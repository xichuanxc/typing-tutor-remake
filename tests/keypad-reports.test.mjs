import test from "node:test";
import assert from "node:assert/strict";
import {createCurriculum,validCurriculum} from "../dist/curriculum.js";
import {KeypadLesson,KeypadTest,validKeypadRecord} from "../dist/keypad.js";
import {StudentSession,PROFILE_KEY} from "../dist/faithful-session.js";
import {progressModel,testSummary,keyCounts,aggregate} from "../dist/reports-model.js";
function inputEntry(activity,now=100){for(const key of [...activity.line.target,"Enter"]){activity.input(key,now);now+=100;}return now;}
const memory=()=>{const data=new Map();return {getItem:k=>data.get(k)??null,setItem:(k,v)=>data.set(k,v)};};
test("keypad lesson batches enter only keypad reports and preserve the displayed speed quirk",()=>{
 const s=new StudentSession(memory()),l=new KeypadLesson(s.beginAdaptivePractice(),5);l.acknowledgeGuide();
 let now=100;for(let n=0;n<3;n++)now=inputEntry(l,now);
 assert.equal(l.batches,1);assert.equal(l.displayTotals().positions,l.record().totals.positions+4);
 l.input(l.line.target[0],now);l.input(l.line.target[1],now+100);l.input("Escape",now+200);
 const record=l.record();assert.ok(validKeypadRecord(record));s.recordPractice(record);
 let model=progressModel(s.working,s.saved);
 assert.equal(model.groups[0].rows.length,0);assert.equal(model.groups[1].rows.length,0);
 assert.equal(model.groups[2].rows[0].label,"Session");assert.equal(model.groups[2].rows[0].speed,record.totals.wpm);
 for(const key of ["letter","number","symbol"])assert.equal(model.groups[2].rows[0][key],null);
 assert.ok(aggregate([record]).categories.number.time===0);assert.ok(keyCounts(record).slice(64).some(a=>a.time>0));
 assert.ok(keyCounts(record).slice(0,64).every(a=>a.time===0));
 assert.equal(s.commit(),"");model=progressModel(s.working,s.saved);
 assert.equal(model.groups[2].rows[0].label,"History");assert.equal(s.working.curriculum.keypadIntroduced,66);
 assert.ok(validCurriculum(s.working.curriculum));
});
test("keypad tests share the latest-four test rows and never enter keyboard lesson totals",()=>{
 const s=new StudentSession(memory());
 for(let n=0;n<5;n++){
  const t=new KeypadTest(s.beginAdaptivePractice());let now=100;
  for(let i=0;i<24;i++)now=inputEntry(t,now);s.recordPractice(t.record());
 }
 const model=progressModel(s.working,s.saved);
 assert.equal(model.groups[0].rows.length,4);assert.ok(model.groups[0].rows.every(r=>r.label==="Keypad"&&r.letter===null&&r.number===null&&r.symbol===null));
 assert.equal(model.groups[1].rows.length,0);assert.equal(model.groups[2].rows.length,1);
 const r=s.working.practiceRecords[0];assert.equal(testSummary(r).groups[0].rows[0].label,"Keypad");
 const t=new KeypadTest(s.working.curriculum);inputEntry(t);t.input("Escape",1000);s.recordPractice(t.record());
 assert.equal(progressModel(s.working,s.saved).groups[0].rows.length,4);
});
test("full keypad profiles round-trip and failed saves retain pending observations",()=>{
 const storage=memory(),s=new StudentSession(storage),c=s.beginAdaptivePractice();
 Object.assign(c,{keypadIntroduced:74,keypadNewKey:32});
 const t=new KeypadTest(c);let now=100;for(let i=0;i<24;i++)now=inputEntry(t,now);s.recordPractice(t.record());
 assert.equal(s.commit(),"");const raw=storage.getItem(PROFILE_KEY),restored=new StudentSession(storage);
 assert.equal(restored.readable,true);assert.equal(restored.working.curriculum.keypadIntroduced,74);
 assert.equal(restored.working.practiceRecords[0].lines.length,24);
 const extra=new KeypadTest(restored.beginAdaptivePractice());extra.input(extra.line.target[0],100);extra.input(extra.line.target[1],200);extra.input("Escape",300);restored.recordPractice(extra.record());
 storage.setItem=()=>{throw Error("denied");};assert.ok(restored.commit());assert.equal(restored.dirty,true);
 restored.discard();assert.equal(restored.working.practiceRecords.length,1);assert.equal(storage.getItem(PROFILE_KEY),raw);
 const bad=JSON.parse(raw);bad.profiles[0].curriculum.keypadIntroduced=75;
 const broken=new StudentSession({getItem:()=>JSON.stringify(bad),setItem(){throw Error();}});
 assert.equal(broken.readable,false);assert.ok(broken.commit());
});
