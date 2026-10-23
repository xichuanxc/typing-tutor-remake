import test from "node:test";
import assert from "node:assert/strict";
import {LineInput} from "../dist/practice.js";
import {createCurriculum} from "../dist/curriculum.js";
import {TypingTest,validTestRecord} from "../dist/typing-test.js";
import {AdaptiveLesson} from "../dist/adaptive-lesson.js";
import {StudentSession,PROFILE_KEY} from "../dist/faithful-session.js";
import {aggregate,categoryFor,displaySpeeds,graphHeight,graphModel,progressModel,testSummary,keysAbove} from "../dist/reports-model.js";
import D from "../dist/curriculum-data.js";
function complete(t){
  let now=100;
  for(const line of t.lines)for(const key of [...line.target,"Enter"]){t.input(key,now);now+=10;}
  return t.record();
}
const memory=()=>{const map=new Map();return {map,getItem:k=>map.get(k)??null,setItem:(k,v)=>map.set(k,v)};};
test("line width parameter retains old practice boundary and accepts native72-character tests",()=>{
  assert.throws(()=>new LineInput("a".repeat(27)));
  assert.equal(new LineInput("a".repeat(72),{maxLength:72}).target.length,72);
  assert.throws(()=>new LineInput("a".repeat(73),{maxLength:72}));
  assert.throws(()=>new LineInput("as",{maxLength:81}));
});
test("six test lines are generated upfront; practice excludes a pending new key without promoting it",()=>{
  const c=createCurriculum();c.introduced=4;c.alphabetic=1;c.newKey=106;
  c.current.slice(0,4).forEach(s=>Object.assign(s,{correct:1,errors:0,time:10}));
  const t=new TypingTest(c,"practice",100);
  assert.equal(c.thresholds[0],60);
  assert.equal(t.lines.length,6);assert.ok(t.lines.every(l=>l.target.length<=72&&/^[asdf ]+$/.test(l.target)));
  assert.equal(c.introduced,4);assert.equal(c.alphabetic,1);assert.equal(c.newKey,106);
  assert.equal(c.current[4].correct,0);assert.equal(typeof c.seed,"number");
});
test("All-keys temporarily enables full grammar without changing the teaching position or flags",()=>{
  const c=createCurriculum(),snapshot={introduced:c.introduced,alphabetic:c.alphabetic,shiftLearned:c.shiftLearned,newKey:c.newKey};
  c.current.slice(0,4).forEach(s=>Object.assign(s,{correct:1,errors:0,time:10}));
  const t=new TypingTest(c,"all-keys",100);
  assert.deepEqual(c.thresholds,[10,5]);
  assert.match(t.lines.map(l=>l.target).join(" "),/[0-9]/);
  assert.match(t.lines.map(l=>l.target).join(" "),/[$@%?!()[\]{}]/);
  assert.deepEqual({introduced:c.introduced,alphabetic:c.alphabetic,shiftLearned:c.shiftLearned,newKey:c.newKey},snapshot);
  const record=complete(t);assert.equal(record.completed,true);assert.equal(record.lines.length,6);
  assert.ok(validTestRecord(record));assert.equal(record.totals.accuracy,100);
  assert.equal(record.totals.positions,record.lines.reduce((n,l)=>n+l.target.length-1,0));
  assert.equal(c.introduced,3);
});
test("corrected errors retain timed observations while final six-line accuracy recovers",()=>{
  const c=createCurriculum(),t=new TypingTest(c,"practice");
  let now=100;const first=t.line.target;
  t.input(first[0],now);t.input("x",now+=100);t.input("Backspace",now+=100);
  for(const key of [...first.slice(1),"Enter"]){t.input(key,now+=100);}
  for(const line of t.lines.slice(1))for(const key of [...line.target,"Enter"]){t.input(key,now+=100);}
  const record=t.record();assert.equal(record.totals.errors,0);assert.equal(record.totals.accuracy,100);
  assert.ok(record.lines[0].attempts.some(a=>!a.correct));assert.ok(validTestRecord(record));
  assert.equal(t.input("x",now+100).ignored,true);
});
test("aborted tests retain key samples but do not enter completed-test rows or session line totals",()=>{
  const store=memory(),s=new StudentSession(store),c=s.beginAdaptivePractice(),t=new TypingTest(c,"practice");
  let now=100;for(const key of [...t.line.target,"Enter"]){t.input(key,now);now+=100;}
  t.input(t.line.target[0],now+=100);t.input("x",now+=100);t.input("Escape",now+=100);
  const record=t.record();assert.equal(record.completed,false);assert.equal(record.lines.length,1);assert.ok(validTestRecord(record));
  s.recordPractice(record);const report=progressModel(s.working,s.saved);
  assert.equal(report.groups[0].rows.length,0);assert.equal(report.groups[1].rows.length,0);
  assert.equal(aggregate([record]).total.correct,0);assert.ok(c.current.some(a=>a.time>0));
  assert.ok(Object.values(aggregate([record]).categories).some(a=>a.time>0));
});
test("timed spaces belong to letter breakdowns but not to individual key arrays",()=>{
  const l=new LineInput("a s");
  ["a"," ","s","Enter"].forEach((k,i)=>l.input(k,100+i*100));
  assert.deepEqual(l.observations,[{key:" ",correct:true,time:100},{key:"s",correct:true,time:100}]);
  assert.deepEqual(l.attempts,[{key:"s",correct:true,time:100}]);
  assert.equal(categoryFor(" "),"letter");assert.equal(categoryFor(";"),"letter");
  assert.equal(categoryFor("7"),"number");assert.equal(categoryFor("$"),"symbol");
});
test("report accuracy and overall speed use final counters; category fields retain native display adjustment",()=>{
  assert.deepEqual(displaySpeeds(20,30,40,0),{speed:20,letter:20,number:40,symbol:null});
  assert.deepEqual(displaySpeeds(50,20,30,0),{speed:50,letter:50,number:30,symbol:null});
  assert.deepEqual(displaySpeeds(50,20,30,20),{speed:50,letter:20,number:30,symbol:20});
  assert.deepEqual(displaySpeeds(0,100,0,0),{speed:null,letter:null,number:null,symbol:null});
  const r=complete(new TypingTest(createCurriculum(),"practice"));
  const row=testSummary(r).groups[0].rows[0];
  assert.equal(row.accuracy,100);assert.equal(row.speed,r.totals.wpm);
  assert.ok(Number.isInteger(row.letter));assert.equal(row.number,null);
});
test("graph heights preserve original byte conversion before the speed cap",()=>{
  assert.equal(graphHeight({correct:1,errors:0,time:10}),20); // 120 => cap100
  assert.equal(graphHeight({correct:1,errors:0,time:4}),8); // 300 => lowbyte44
  assert.equal(graphHeight({correct:99,errors:1,time:1},"accuracy"),19);
  assert.equal(graphHeight({correct:0,errors:0,time:0}),0);
  const c=createCurriculum();Object.assign(c.current[0],{correct:1,errors:0,time:4});
  assert.equal(graphModel(c).current[0],8);assert.equal(graphModel(c).saved[0],0);
});
test("reports are read-only and split current/history at explicit save, counting tests in session practice",()=>{
  const store=memory(),s=new StudentSession(store),clean=JSON.stringify(s.working);
  assert.equal(progressModel(s.working,s.saved).groups.length,3);
  assert.equal(JSON.stringify(s.working),clean);assert.equal(s.dirty,false);assert.equal(store.getItem(PROFILE_KEY),null);
  const c=s.beginAdaptivePractice(),r=complete(new TypingTest(c,"practice"));
  s.recordPractice(r);let model=progressModel(s.working,s.saved);
  assert.equal(model.groups[0].rows.length,1);assert.equal(model.groups[1].rows[0].label,"Session");
  assert.equal(model.groups[1].rows[0].speed,r.totals.wpm);
  assert.equal(s.commit(),"");model=progressModel(s.working,s.saved);
  assert.deepEqual(model.groups[1].rows.map(r=>r.label),["History"]);
  assert.ok(s.working.curriculum.current.every(a=>a.time===0));
  assert.ok(s.working.curriculum.saved.some(a=>a.time>0));
});
test("older adaptive records remain visible with unknown category speeds blank; fixtures are not relabeled",()=>{
  const c=createCurriculum(),l=new AdaptiveLesson(c,5);
  let now=100;for(const key of [...l.line.target,"Enter"]){l.input(key,now);now+=100;}
  l.input("Escape",now);const old=l.record();
  for(const line of old.lines)delete line.observations;delete old.partialObservations;
  const working={wpm:20,curriculum:c,practiceRecords:[old]},saved={practiceRecords:[]};
  const model=progressModel(working,saved);assert.equal(model.legacyBreakdownMissing,true);
  assert.equal(model.groups[1].rows[0].letter,null);assert.equal(model.groups[1].rows[0].accuracy,100);
  const legacy={...old,kind:"home-keys-f3"};
  assert.equal(progressModel({...working,practiceRecords:[legacy]},saved).groups[1].rows.length,0);
});
test("new test records validate observations/totals and save or discard atomically",()=>{
  const store=memory(),s=new StudentSession(store),r=complete(new TypingTest(s.beginAdaptivePractice(),"all-keys"));
  s.recordPractice(r);assert.equal(s.commit(),"");
  const restored=new StudentSession(store);assert.equal(restored.working.practiceRecords[0].testType,"all-keys");
  const bad=structuredClone(r);bad.totals.correct++;assert.equal(validTestRecord(bad),false);
  const altered=structuredClone(r);altered.lines[0].observations=[];assert.equal(validTestRecord(altered),false);
  const before=store.getItem(PROFILE_KEY);
  const t=new TypingTest(restored.beginAdaptivePractice(),"practice");t.input("Escape",100);restored.recordPractice(t.record());
  store.setItem=()=>{throw Error();};assert.ok(restored.commit());assert.equal(restored.dirty,true);
  restored.discard();assert.equal(restored.working.practiceRecords.length,1);assert.equal(store.getItem(PROFILE_KEY),before);
});
