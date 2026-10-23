// Counters and display adjustments translated from 0x14f6c, 0x18857, 0x18383, 0x18f6e.
import {accuracy,speed} from "./scoring.js";
import D from "./curriculum-data.js";
const u32=n=>n>>>0,s16=n=>(n<<16)>>16;
const empty=()=>({correct:0,errors:0,time:0});
const blankTotals=()=>({correct:0,errors:0,time:0,positions:0});
export function supportedRecord(r){return r.kind==="adaptive-alpha-f4"||r.kind==="adaptive-keyboard-f4c"||r.kind==="keyboard-test-f4b"||r.kind==="keypad-f5a"||r.kind==="disk-test-f5b";}
export function categoryFor(key){
  return ((D.charFlags[key.charCodeAt(0)]&3)||D.punctuation.includes(key))?"letter":
    (D.charFlags[key.charCodeAt(0)]&4)?"number":"symbol";
}
export function observations(record){
  return [...record.lines.flatMap(l=>l.observations??[]),...(record.partialObservations??[])];
}
function hasCategoryEvidence(record){
  return record.lines.every(l=>Array.isArray(l.observations))&&Array.isArray(record.partialObservations);
}
const isDisk=r=>r.kind==="disk-test-f5b";
const isKeypad=r=>r.kind==="keypad-f5a";
const isTest=r=>r.kind==="keyboard-test-f4b"||(isKeypad(r)&&r.activity==="test");
const rIndex=(r,key)=>isKeypad(r)?("4567891230.".includes(key)?64+"4567891230.".indexOf(key):-1):D.keyIndex[key];
export function keyCounts(record){
  const out=Array.from({length:75},empty);
  for(const a of [...record.lines.flatMap(l=>l.attempts),...record.partialAttempts]){
    const i=rIndex(record,a.key);if(!Number.isInteger(i)||i<0||i>=75)continue;
    out[i].time=u32(out[i].time+a.time);const key=a.correct?"correct":"errors";out[i][key]=u32(out[i][key]+1);
  }
  return out;
}
export function keysAbove(samples,goal){return samples.slice(0,64).filter(s=>speed(s.correct,s.errors,s.time)>=goal).length;}
export function aggregate(records){
  const total=blankTotals(),categories={letter:empty(),number:empty(),symbol:empty()};
  let precise=true;
  for(const record of records){
    const counted=isDisk(record)||!isTest(record)||record.completed;
    if(counted)for(const key of Object.keys(total))total[key]=u32(total[key]+record.totals[key]);
    if(isKeypad(record))continue; // Native 14f6c suppresses every keypad category aggregate.
    precise&&=hasCategoryEvidence(record);
    for(const a of observations(record)){
      const c=categories[categoryFor(a.key)];c.time=u32(c.time+a.time);
      c[a.correct?"correct":"errors"]=u32(c[a.correct?"correct":"errors"]+1);
    }
  }
  return {total,categories,precise,date:records.at(-1)?.startedAt??null};
}
export function localDate(iso){
  if(!iso)return "";const d=new Date(iso);
  return [d.getMonth()+1,d.getDate(),d.getFullYear()%100].map(n=>String(n).padStart(2,"0")).join("-");
}
// 8857 adjusts only the first present category when all categories lie on one
// side of overall speed. Its second condition specifically requires symbol=0.
export function displaySpeeds(overall,letter,number,symbol){
  if(!overall)return {speed:null,letter:null,number:null,symbol:null};
  const signed=[letter,number,symbol].map(s16),o=s16(overall);
  let adjust=signed.every(n=>n===0||o<n)||
    ((signed[0]===0||signed[0]<o)&&(signed[1]===0||signed[1]<o)&&signed[2]===0&&signed[2]<o);
  const out={speed:o};
  for(const [i,key] of ["letter","number","symbol"].entries()){
    out[key]=signed[i]===0?null:adjust?o:signed[i];if(signed[i]!==0)adjust=false;
  }
  return out;
}
export function reportRow(data,label,samples,goal,{keypad=false,test=false}={}){
  const t=data.total,overall=speed(t.positions,0,t.time);
  let values;
  if(data.precise){
    const categorySpeeds=["letter","number","symbol"].map(k=>{const c=data.categories[k];return speed(c.correct,c.errors,c.time);});
    values=displaySpeeds(overall,...categorySpeeds);
  }else values={speed:overall?s16(overall):null,letter:null,number:null,symbol:null};
  return {label,date:localDate(data.date),keysAbove:(keypad?samples.slice(64):test?samples:samples.slice(0,64)).filter(s=>speed(s.correct,s.errors,s.time)>=goal).length,
    accuracy:t.correct+t.errors?accuracy(t.correct,t.errors):null,...values};
}
export function progressModel(working,saved){
  const all=(working.practiceRecords??[]),savedCount=(saved.practiceRecords??[]).length;
  const history=all.slice(0,savedCount).filter(supportedRecord),session=all.slice(savedCount).filter(supportedRecord);
  const zero=()=>Array.from({length:75},empty),curriculum=working.curriculum;
  const currentSamples=curriculum?.current??zero(),savedSamples=curriculum?.saved??zero();
  const tests=[...all.filter(r=>isTest(r)&&r.completed).slice(-4).reverse(),...all.filter(r=>isDisk(r)&&r.completed).slice(-4).reverse()];
  function groupRows(keypad){
    const current=aggregate(session.filter(r=>isKeypad(r)===keypad)),past=aggregate(history.filter(r=>isKeypad(r)===keypad)),rows=[];
    if(current.total.correct+current.total.errors)rows.push(reportRow(current,"Session",currentSamples,working.wpm,{keypad}));
    if(past.total.correct+past.total.errors)rows.push(reportRow(past,"History",savedSamples,working.wpm,{keypad}));
    return {rows,limited:!current.precise||!past.precise};
  }
  const keyboard=groupRows(false),keypad=groupRows(true);
  return {groups:[
    {label:"Test",rows:tests.map(r=>reportRow(aggregate([r]),isDisk(r)?r.name:isKeypad(r)?"Keypad":r.testType==="all-keys"?"All-keys":"Practice",keyCounts(r),working.wpm,{test:true}))},
    {label:"Lesson - Practice",rows:keyboard.rows},{label:"Lesson - Keypad",rows:keypad.rows}
  ],legacyBreakdownMissing:keyboard.limited};
}
export function testSummary(record,goal=record.goal){
  return {groups:[{label:"",rows:[reportRow(aggregate([record]),
    isDisk(record)?record.name:isKeypad(record)?"Keypad":record.testType==="all-keys"?"All-keys":"Practice",keyCounts(record),goal,{test:true})]}]};
}
export function graphHeight(sample,kind="speed"){
  let value;
  if(kind==="accuracy")value=accuracy(sample.correct,sample.errors)&255;
  else{value=speed(sample.correct,sample.errors,sample.time)&255;if(value>104)value=100;}
  return Math.floor(value/5);
}
export function graphModel(curriculum,kind="speed"){
  const zero=()=>Array.from({length:75},empty);
  return {current:(curriculum?.current??zero()).map(a=>graphHeight(a,kind)),
    saved:(curriculum?.saved??zero()).map(a=>graphHeight(a,kind))};
}
