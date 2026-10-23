// Keypad paths 0x1282a/0x12cc6, 0x1d368, 0x1d6a0, 0x1e08c..0x1e1ef.
import KEYPAD_DATA from "./keypad-data.js";
import {LineInput,totals} from "./practice.js";
import {DosRandom} from "./drill-generator.js";
import {mastered,recordAttempt,recalculateThreshold} from "./curriculum.js";
import {accuracy,speed} from "./scoring.js";
export const KEYPAD_KEYS=KEYPAD_DATA.keys.slice(0,11);
export function keypadIndex(key){if(typeof key!=="string"||key.length!==1)return -1;const i=KEYPAD_KEYS.indexOf(key);return i>=0?64+i:-1;}
export function ensureKeypad(c){
  c.keypadIntroduced??=KEYPAD_DATA.bootstrap.introduced;c.keypadNewKey??=KEYPAD_DATA.bootstrap.pending;
  return c;
}
export function nextKeypadKey(c){
  ensureKeypad(c);
  if(c.keypadIntroduced>=74)return " ";
  let remaining=0;for(let i=64;i<=c.keypadIntroduced;i++)if(!mastered(c,i))remaining++;
  if(remaining>=3)return " ";
  return KEYPAD_KEYS[++c.keypadIntroduced-64];
}
export class KeypadGenerator{
  constructor(c){this.curriculum=ensureKeypad(c);this.random=new DosRandom(c);}
  known(key){const index=keypadIndex(key);return index>=64&&index<=this.curriculum.keypadIntroduced;}
  choose(chars){
    const keys=[...chars].filter(c=>this.known(c));if(!keys.length)return "";
    let n=this.random.next(keys.reduce((n,c)=>n+this.curriculum.weights[keypadIndex(c)],0));
    let i=0,sum=this.curriculum.weights[keypadIndex(keys[0])];
    // Native uses cumulative >= draw, including the first-key zero boundary.
    while(sum<n)sum+=this.curriculum.weights[keypadIndex(keys[++i])];
    return keys[i];
  }
  number(){
    const length=this.random.next(6)+4;
    const chars=Array.from({length},()=>this.choose("0123456789"));
    if(this.known("."))chars[length-3]=".";
    return chars.join("");
  }
  warmup(key,home,first=false){
    let out="";
    for(let n=0;n<2;n++){
      const group=[home,key,home,key];
      if(!first)for(let j=3;j>0;j--){const k=this.random.next(j+1);[group[j],group[k]]=[group[k],group[j]];}
      first=false;out+=group.join("");
    }
    return out;
  }
}
export function keypadRankings(c,text,mode=0){
  const out=[" "," "," "],weights=Array(3).fill(mode===1?255:0);
  for(const key of text){
    const index=keypadIndex(key);if(index<64)continue;
    const weight=c.weights[index];
    for(let j=0;j<3;j++){
      if(out[j]===key)break;
      if(mode===1?weights[j]>=weight:weights[j]<weight){
        for(let k=2;k>j;k--){out[k]=out[k-1];weights[k]=weights[k-1];}
        out[j]=key;weights[j]=weight;break;
      }
    }
  }
  if((c.keypadIntroduced<=67&&mode!==0)||(c.keypadIntroduced===68&&mode===2))out[2]=" ";
  if(c.keypadIntroduced===66&&mode===2)out[1]=" ";
  return out.join("");
}
const copyAttempts=a=>a.map(a=>({...a}));
const copiedLine=l=>({target:l.target,result:{...l.result},attempts:copyAttempts(l.attempts),observations:copyAttempts(l.observations)});
const display=(lines,batches)=>{const t=totals(lines),positions=t.correct+t.errors-2*batches;return {...t,positions,wpm:speed(positions,0,t.time)};};
class KeypadActivity{
  constructor(c,activity,drills,goal,startedAt){
    if(!["lesson","test"].includes(activity)||![5,10,15,20].includes(drills)||!Number.isInteger(goal)||goal<10||goal>100||goal%10)throw Error("Invalid keypad activity");
    this.curriculum=ensureKeypad(c);this.activity=activity;this.drills=activity==="lesson"?drills:1;this.goal=goal;this.startedAt=startedAt;
    this.generator=new KeypadGenerator(c);this.lines=[];this.entries=[];this.activeEntry=0;this.batches=0;
    this.finished=false;this.completed=false;this.recorded=false;this.tutorial=null;
    this.introRequired=activity==="lesson"&&c.keypadNewKey===1;
    this.prepare();
  }
  get pendingGuide(){return this.introRequired?{type:"keypad-intro"}:null;}
  acknowledgeGuide(){this.introRequired=false;}
  get line(){return this.entries[Math.min(this.activeEntry,this.entries.length-1)];}
  prepare(){
    const c=this.curriculum;
    if(this.activity==="lesson")c.keypadNewKey=nextKeypadKey(c).charCodeAt(0);
    if(this.batches===0)recalculateThreshold(c,this.goal,1);
    this.entries=Array.from({length:this.activity==="lesson"?3:24},()=>new LineInput(this.generator.number(),{maxLength:9}));
    this.activeEntry=0;
    const key=String.fromCharCode(c.keypadNewKey);
    if(this.activity==="lesson"&&key!==" "&&this.entries.some(l=>l.target.includes(key))){
      const finger=key==="."?3:(keypadIndex(key)-1)%3+1,home="456"[finger-1];
      this.tutorial={key,home,finger,count:0,entries:[],activeEntry:0,
        get line(){return this.entries[this.activeEntry];}};
      this.prepareTutorial(true);
    }
  }
  prepareTutorial(first=false){
    const t=this.tutorial;
    t.entries=Array.from({length:3},(_,i)=>new LineInput(this.generator.warmup(t.key,t.home,first&&i===0),{maxLength:8}));
    t.activeEntry=0;
  }
  input(key,now){
    if(this.finished||this.introRequired)return {ignored:true};
    if(this.tutorial){
      const t=this.tutorial,event=t.line.input(key,now);
      if(event.aborted){this.curriculum.keypadNewKey=0;this.tutorial=null;this.finished=true;return event;}
      if(event.done){
        if(++t.activeEntry===3){
          if(++t.count===3){this.curriculum.keypadNewKey=0;this.tutorial=null;return {...event,tutorialDone:true};}
          this.prepareTutorial();return {...event,tutorialGroupDone:true};
        }
        return {...event,tutorialEntryDone:true};
      }
      return event;
    }
    const line=this.line,before=line.attempts.length,event=line.input(key,now);
    for(const a of line.attempts.slice(before))recordAttempt(this.curriculum,a,{index:keypadIndex(a.key)});
    if(event.aborted){this.finished=true;return event;}
    if(event.done){
      this.lines.push(line);this.activeEntry++;
      if(this.activeEntry===this.entries.length){
        this.batches++;
        this.lastResult=this.activity==="lesson"?display(this.entries,1):totals(this.entries);
        if(this.activity==="test"||this.batches===this.drills){
          this.finished=true;this.completed=true;return {...event,[this.activity==="test"?"testDone":"lessonDone"]:true};
        }
        this.prepare();return {...event,drillDone:true};
      }
      return {...event,entryDone:true};
    }
    return event;
  }
  scoredLines(){
    return this.activity==="test"?(this.completed?this.lines:[]):this.lines.slice(0,this.batches*3);
  }
  displayTotals(){return this.activity==="lesson"?display(this.scoredLines(),this.batches):totals(this.scoredLines());}
  summary(){
    const c=this.curriculum,text=KEYPAD_KEYS.slice(0,c.keypadIntroduced-63);
    return {best:keypadRankings(c,text,1),worst:keypadRankings(c,text,2),
      above:c.current.slice(64,c.keypadIntroduced+1).filter(s=>speed(s.correct,s.errors,s.time)>=this.goal).length};
  }
  record(){
    const line=this.line,included=this.lines.includes(line);
    return {version:1,kind:"keypad-f5a",activity:this.activity,startedAt:this.startedAt,goal:this.goal,
      drills:this.activity==="lesson"?this.drills:1,batches:this.batches,completed:this.completed,
      lines:this.lines.map(copiedLine),totals:totals(this.scoredLines()),
      partialAttempts:included?[]:copyAttempts(line.attempts),partialObservations:included?[]:copyAttempts(line.observations)};
  }
}
export class KeypadLesson extends KeypadActivity{
  constructor(c,drills=10,goal=20,startedAt=new Date().toISOString()){super(c,"lesson",drills,goal,startedAt);}
}
export class KeypadTest extends KeypadActivity{
  constructor(c,goal=20,startedAt=new Date().toISOString()){super(c,"test",5,goal,startedAt);}
}
export function validKeypadRecord(r){
  const uint=n=>Number.isInteger(n)&&n>=0&&n<=0xffffffff;
  const observation=a=>a&&keypadIndex(a.key??"")>=64&&typeof a.correct==="boolean"&&Number.isInteger(a.time)&&a.time>=1&&a.time<=500;
  const result=s=>s&&["correct","errors","time","positions","wpm","accuracy"].every(k=>uint(s[k]))&&s.wpm<=65535&&s.accuracy<=100;
  const matches=(a,b)=>a.length===b.length&&a.every((x,i)=>x.key===b[i].key&&x.correct===b[i].correct&&x.time===b[i].time);
  if(!r||r.version!==1||r.kind!=="keypad-f5a"||!["lesson","test"].includes(r.activity)||
    typeof r.startedAt!=="string"||!Number.isFinite(Date.parse(r.startedAt))||!Number.isInteger(r.goal)||r.goal<10||r.goal>100||r.goal%10||
    !(r.activity==="lesson"?[5,10,15,20].includes(r.drills):r.drills===1)||!Number.isInteger(r.batches)||r.batches<0||r.batches>r.drills||
    typeof r.completed!=="boolean"||r.completed!==(r.batches===r.drills)||!Array.isArray(r.lines)||!result(r.totals)||
    !Array.isArray(r.partialAttempts)||!r.partialAttempts.every(observation)||!Array.isArray(r.partialObservations)||!r.partialObservations.every(observation)||
    !matches(r.partialAttempts,r.partialObservations)||(r.completed&&(r.partialAttempts.length||r.partialObservations.length)))return false;
  const count=r.activity==="lesson"?3:24;
  if(r.lines.length>r.drills*count||r.batches!==Math.floor(r.lines.length/count))return false;
  if(!r.lines.every(l=>l&&typeof l.target==="string"&&/^[0-9]{4,9}$|^[0-9]{1,6}\.[0-9]{2}$/.test(l.target)&&
    l.target.length>=4&&l.target.length<=9&&result(l.result)&&l.result.correct+l.result.errors===l.target.length+1&&
    l.result.positions===l.target.length-1&&l.result.wpm===speed(l.result.positions,0,l.result.time)&&
    l.result.accuracy===accuracy(l.result.correct,l.result.errors)&&
    Array.isArray(l.attempts)&&l.attempts.every(observation)&&Array.isArray(l.observations)&&l.observations.every(observation)&&matches(l.attempts,l.observations)))return false;
  const expected=totals(r.lines.slice(0,r.batches*count));
  return Object.keys(expected).every(k=>r.totals[k]===expected[k]);
}
