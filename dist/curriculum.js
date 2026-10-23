// Assembly-backed adaptive state: 0x14f6c, 0x1531a–0x15584, 0x14427.
// Saved and current samples stay separate until the explicit Quit/save boundary.
import D from "./curriculum-data.js";
import {accuracy,speed} from "./scoring.js";
const u32=n=>n>>>0;
const s16=n=>(n<<16)>>16;
const empty=()=>({correct:0,errors:0,time:0});
const samples=()=>Array.from({length:75},empty);
const lower=c=>c>="A"&&c<="Z"?String.fromCharCode(c.charCodeAt(0)+32):c;
const keyNumber=key=>D.keyIndex[key];
const flags=key=>D.charFlags[key.charCodeAt(0)]||0;
export function createCurriculum(goal=20){
  const b=D.bootstrap;
  const state={version:1,introduced:b.introduced,alphabetic:b.alphabetic,newKey:b.newKey,
    shiftPending:b.shiftPending,shiftLearned:b.shiftLearned,
    thresholds:[...b.thresholds],weights:[...b.weights],saved:samples(),current:samples()};
  recalculateThreshold(state,goal,0);recalculateThreshold(state,goal,1);
  return state;
}
export function validCurriculum(s){
  const integer=(n,max)=>Number.isInteger(n)&&n>=0&&n<=max;
  const sample=a=>a&&["correct","errors","time"].every(k=>integer(a[k],0xffffffff));
  return !!s&&s.version===1&&(!("seed" in s)||integer(s.seed,65535))&&
    (!("introShown" in s)||typeof s.introShown==="boolean")&&integer(s.introduced,63)&&integer(s.alphabetic,D.alphabetic.length-1)&&
    (!("keypadIntroduced" in s)||(integer(s.keypadIntroduced,74)&&s.keypadIntroduced>=66))&&
    (!("keypadNewKey" in s)||[0,1,32,46,48,49,50,51,52,53,54,55,56,57].includes(s.keypadNewKey))&&
    integer(s.newKey,126)&&(s.newKey===0||s.newKey>=33)&&integer(s.shiftPending,1)&&integer(s.shiftLearned,1)&&
    Array.isArray(s.thresholds)&&s.thresholds.length===2&&s.thresholds.every(n=>integer(n,255))&&
    Array.isArray(s.weights)&&s.weights.length===75&&s.weights.every(n=>integer(n,255))&&
    ["saved","current"].every(k=>Array.isArray(s[k])&&s[k].length===75&&s[k].every(sample));
}
export function recordAttempt(s,{key,correct,time},{index=keyNumber(key)}={}){
  if(key===" "||time===0)return false;
  const i=index;
  if(!Number.isInteger(i)||i<0||i>=75||typeof correct!=="boolean"||!Number.isInteger(time)||time<1||time>500)
    throw Error("Invalid adaptive key sample");
  const a=s.current[i];
  a.time=u32(a.time+time);a[correct?"correct":"errors"]=u32(a[correct?"correct":"errors"]+1);
  const old=s.weights[i];
  // The intermediate ADD/SHL are 16-bit; shifts are unsigned, division signed.
  const w=correct?((old+3*Math.trunc(2040/(s16(speed(a.correct,a.errors,a.time))||1)))&0xffff)>>>2:
    old+(old>>>5)+1;
  s.weights[i]=Math.min(255,w);
  return true;
}
export function needsPractice(s,i){
  const a=s.current[i];
  if(u32(a.correct+a.errors)===0)return false;
  return speed(a.correct,a.errors,a.time)<s.thresholds[i>28?1:0]||accuracy(a.correct,a.errors)<D.accuracyGoal;
}
export function needsHistoryPractice(s,i){
  const a=s.saved[i];
  return speed(a.correct,a.errors,a.time)<s.thresholds[i>28?1:0]||
    accuracy(a.correct,a.errors)<D.accuracyGoal||u32(a.correct+s.current[i].correct)<D.minSamples;
}
export function mastered(s,i,{testType=0}={}){
  if(testType===3||(i>s.introduced&&i<64)||(i===s.introduced&&s.newKey!==0)||needsPractice(s,i))return false;
  return !needsHistoryPractice(s,i)||s.current[i].correct>D.minSamples;
}
// Native 0x1544e returns one for mastery (not for needing extra practice).
export const eligible=mastered;
export function recalculateThreshold(s,goal,group=0){
  if(!Number.isInteger(goal)||goal<10||goal>100||goal%10||![0,1].includes(group))throw Error("Invalid adaptive goal");
  if(group===1&&s.introduced<29)return s.thresholds[1];
  let sum=0;
  const first=group===1?29:0;
  for(let i=first;i<=s.introduced;i++){
    const a=s.saved[i],b=s.current[i];
    sum=s16(sum+speed(u32(a.correct+b.correct),u32(a.errors+b.errors),u32(a.time+b.time)));
  }
  let threshold=Math.trunc(s16(2*Math.trunc(sum/(s.introduced-first+1)))/(s.introduced>28?5:4));
  // Original compares the goal with an unsigned 16-bit threshold before the floor.
  if((threshold&0xffff)>goal)threshold=goal;
  else threshold=Math.max(group===1?5:10,threshold);
  s.thresholds[group]=threshold;
  return threshold;
}
export function nextKey(s){
  if(s.newKey)return {key:String.fromCharCode(s.newKey),guide:false,shiftLesson:false};
  if(s.shiftPending){
    s.shiftPending=0;s.shiftLearned=1;
    return {key:null,guide:true,shiftLesson:true};
  }
  if(s.introduced>=63)return {key:null,guide:false,shiftLesson:false};
  let remaining=0;
  for(let i=0;i<=s.introduced;i++)if(!mastered(s,i))remaining++;
  if(remaining>=4)return {key:null,guide:false,shiftLesson:false};
  const key=D.presentation[++s.introduced];
  s.newKey=key.charCodeAt(0);
  if(s.introduced===7)s.shiftPending=1;
  else if(flags(key)&3)s.alphabetic++;
  return {key,guide:s.introduced<8,shiftLesson:false};
}
export function beginLesson(s,goal){
  recalculateThreshold(s,goal,0);recalculateThreshold(s,goal,1);
  return nextKey(s);
}
export function completeNewKey(s){
  if(s.newKey){
    const key=String.fromCharCode(s.newKey),i=keyNumber(key);
    if((flags(key)&3)&&i<=s.introduced)s.weights[i]=255;
  }
  s.newKey=0;
}
export function commitCurriculum(s){
  for(let i=0;i<75;i++){
    for(const k of ["correct","errors","time"])s.saved[i][k]=u32(s.saved[i][k]+s.current[i][k]);
    s.current[i]=empty();
  }
  return s;
}
export function alphabeticWeightTotal(s){
  // DS:0x7aee starts "asd", followed by the alphabetic presentation beginning f.
  return [...("asd"+D.alphabetic.slice(0,s.alphabetic+1))].reduce((sum,key)=>sum+s.weights[keyNumber(key)],0)&0xffff;
}
export function rankings(s,text,mode=0){
  if(![0,1,2].includes(mode))throw Error("Invalid ranking mode");
  const best=mode===1,out=[" "," "," "],weights=Array(3).fill(best?255:0);
  for(const original of text){
    if(original===" ")continue;
    const key=lower(original),i=keyNumber(original);
    if(!Number.isInteger(i)||i<0||i>=75)continue;
    const weight=s.weights[i];
    for(let j=0;j<3;j++){
      if(out[j]===key)break;
      if(best?weights[j]>=weight:weights[j]<weight){
        for(let k=2;k>j;k--){out[k]=out[k-1];weights[k]=weights[k-1];}
        out[j]=key;weights[j]=weight;break;
      }
    }
  }
  if((s.introduced===3&&mode===0)||(s.introduced===4&&mode===2))out[2]=" ";
  return out.join("");
}
export function summaryRankings(s){
  const text=D.presentation.slice(0,s.introduced+(s.newKey?0:1));
  return {best:rankings(s,text,1),worst:rankings(s,text,2)};
}
