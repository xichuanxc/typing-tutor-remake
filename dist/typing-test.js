// Native tests: 0x12952, 0x12a2c, 0x13a6d; six lines, width72, no teaching promotion.
import {LineInput,totals,accuracy,speed} from "./practice.js";
import {recordAttempt,recalculateThreshold} from "./curriculum.js";
import {DrillGenerator} from "./drill-generator.js";
import D from "./curriculum-data.js";
export class TypingTest{
  constructor(curriculum,testType="practice",goal=20,startedAt=new Date().toISOString()){
    if(!["practice","all-keys"].includes(testType))throw Error("Unknown test type");
    this.curriculum=curriculum;this.testType=testType;this.goal=goal;this.startedAt=startedAt;
    this.activeLine=0;this.finished=false;this.completed=false;this.recorded=false;
    const generation=structuredClone(curriculum);
    if(testType==="all-keys"){generation.introduced=63;generation.alphabetic=22;generation.shiftLearned=1;}
    else if(generation.newKey){
      generation.introduced--;
      if(D.charFlags[generation.newKey]&3)generation.alphabetic--;
    }
    recalculateThreshold(generation,goal,0);recalculateThreshold(generation,goal,1);
    curriculum.thresholds=[...generation.thresholds];
    const generator=new DrillGenerator(generation,{testType:testType==="all-keys"?3:2});
    this.lines=Array.from({length:6},()=>new LineInput(generator.line(72),{maxLength:72}));
    curriculum.seed=generation.seed;
  }
  get line(){return this.lines[Math.min(this.activeLine,5)];}
  input(key,now){
    if(this.finished)return {ignored:true};
    const before=this.line.attempts.length,event=this.line.input(key,now);
    for(const attempt of this.line.attempts.slice(before))recordAttempt(this.curriculum,attempt);
    if(event.aborted){this.finished=true;return event;}
    if(event.done){
      this.activeLine++;
      if(this.activeLine===6){this.finished=true;this.completed=true;return {...event,testDone:true};}
    }
    return event;
  }
  record(){
    const lines=this.lines.filter(l=>l.done).map(l=>({target:l.target,result:{...l.result},
      attempts:l.attempts.map(a=>({...a})),observations:l.observations.map(a=>({...a}))}));
    return {version:1,kind:"keyboard-test-f4b",testType:this.testType,startedAt:this.startedAt,goal:this.goal,
      completed:this.completed,targets:this.lines.map(l=>l.target),lines,totals:totals(lines),
      partialAttempts:this.completed?[]:this.line.attempts.map(a=>({...a})),
      partialObservations:this.completed?[]:this.line.observations.map(a=>({...a}))};
  }
}
export {validObservation} from "./timed-observation.js";
import {validObservation,sameKeyAttempts} from "./timed-observation.js";
export function validTestRecord(r){
  const uint=n=>Number.isInteger(n)&&n>=0&&n<=0xffffffff;
  const result=s=>s&&["correct","errors","time","positions","wpm","accuracy"].every(k=>uint(s[k]))&&s.accuracy<=100&&s.wpm<=65535;
  const target=s=>typeof s==="string"&&s.length>=2&&s.length<=72&&/^[ -~]+$/.test(s);
  if(!r||r.version!==1||r.kind!=="keyboard-test-f4b"||!["practice","all-keys"].includes(r.testType)||
    typeof r.startedAt!=="string"||!Number.isFinite(Date.parse(r.startedAt))||!Number.isInteger(r.goal)||r.goal<10||r.goal>100||r.goal%10||
    typeof r.completed!=="boolean"||!Array.isArray(r.targets)||r.targets.length!==6||!r.targets.every(target)||
    !Array.isArray(r.lines)||r.lines.length>6||r.completed!==(r.lines.length===6)||!result(r.totals)||
    !Array.isArray(r.partialAttempts)||!r.partialAttempts.every(a=>validObservation(a))||
    !Array.isArray(r.partialObservations)||!r.partialObservations.every(a=>validObservation(a,true))||
    !sameKeyAttempts(r.partialAttempts,r.partialObservations)||(r.completed&&(r.partialAttempts.length||r.partialObservations.length)))return false;
  if(!r.lines.every((l,i)=>l&&l.target===r.targets[i]&&result(l.result)&&
    l.result.correct+l.result.errors===l.target.length+1&&l.result.positions===l.target.length-1&&
    l.result.wpm===speed(l.result.positions,0,l.result.time)&&l.result.accuracy===accuracy(l.result.correct,l.result.errors)&&
    Array.isArray(l.attempts)&&l.attempts.every(a=>validObservation(a))&&
    Array.isArray(l.observations)&&l.observations.every(a=>validObservation(a,true))&&sameKeyAttempts(l.attempts,l.observations)))return false;
  const expected=totals(r.lines);return Object.keys(expected).every(k=>r.totals[k]===expected[k]);
}
