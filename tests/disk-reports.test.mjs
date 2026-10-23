import test from "node:test";
import assert from "node:assert/strict";
import {DiskTest,validDiskRecord} from "../dist/disk-test.js";
import {TypingTest} from "../dist/typing-test.js";
import {StudentSession,PROFILE_KEY} from "../dist/faithful-session.js";
import {progressModel,aggregate,testSummary} from "../dist/reports-model.js";
import {drawProgress} from "../dist/report-screen.js";
import {Grid} from "../dist/grid.js";
const bytes=s=>new TextEncoder().encode(s);
const store=()=>{const map=new Map();return {getItem:k=>map.get(k)??null,setItem:(k,v)=>map.set(k,v)};};
function line(t,now=100){for(const key of [...t.line.target,"Enter"])t.input(key,now+=100);return now;}
function complete(t){let now=100;while(!t.finished)now=line(t,now);return t.record();}
test("aborted Disk pages keep completed screen totals and timed partials, without a test history row",()=>{
 const s=new StudentSession(store()),c=s.beginAdaptivePractice(),t=new DiskTest(c,bytes("asdf ".repeat(150)),{name:"ABORT.TST"});
 let now=100;while(t.page===0)now=line(t,now);
 t.input(t.line.target[0],now+=100);t.input(t.line.target[1],now+=100);t.input("Escape",now+=100);
 const r=t.record();assert.ok(validDiskRecord(r));assert.equal(r.completed,false);assert.deepEqual(r.pages,[6]);
 assert.ok(r.totals.correct>0);assert.ok(r.partialAttempts.length>0);s.recordPractice(r);
 let model=progressModel(s.working,s.saved);
 assert.equal(model.groups[0].rows.length,0);assert.equal(model.groups[1].rows[0].label,"Session");
 assert.equal(model.groups[1].rows[0].speed,r.totals.wpm);assert.equal(aggregate([r]).total.correct,r.totals.correct);
 assert.equal(c.introduced,3);assert.equal(s.commit(),"");
 const restored=new StudentSession(s.storage);assert.equal(restored.readable,true);assert.deepEqual(restored.working.practiceRecords,[r]);
 model=progressModel(restored.working,restored.saved);assert.equal(model.groups[1].rows[0].label,"History");
});
test("Disk history keeps four separate slots beside four keyboard tests and uses native report height",()=>{
 const s=new StudentSession(store()),c=s.beginAdaptivePractice();
 for(let i=0;i<4;i++)s.recordPractice(complete(new TypingTest(c)));
 for(let i=0;i<5;i++)s.recordPractice(complete(new DiskTest(c,bytes("asdf asdf"),{name:"TEST"+i+".TST"})));
 const model=progressModel(s.working,s.saved),rows=model.groups[0].rows;
 assert.equal(rows.length,8);assert.deepEqual(rows.slice(4).map(r=>r.label),["TEST4.TST","TEST3.TST","TEST2.TST","TEST1.TST"]);
 assert.equal(testSummary(s.working.practiceRecords.at(-1)).groups[0].rows[0].label,"TEST4.TST");
 const grid=new Grid(),row={label:"Session",date:"10-23-26",keysAbove:0,accuracy:100,speed:20};
 const maximum={groups:[model.groups[0],{label:"Lesson - Practice",rows:[row,{...row,label:"History"}]},{label:"Lesson - Keypad",rows:[row,{...row,label:"History"}]}]};
 assert.equal(drawProgress(grid,maximum).bottom,24);
 assert.equal(grid.cells[24][1].char,"╘"); // Original maximum-height border shares the footer row.
});
test("Disk source identities and short EOF records survive save, failed save and discard",()=>{
 const storage=store(),s=new StudentSession(storage),c=s.beginAdaptivePractice();
 for(const text of ["","a"]){
  const r=complete(new DiskTest(c,bytes(text),{name:text?"ONE.TST":"EMPTY.TST",sha256:"a".repeat(64)}));
  assert.ok(validDiskRecord(r));s.recordPractice(r);
 }
 assert.equal(s.working.practiceRecords[0].totals.positions,0xffffffff);
 assert.equal(s.commit(),"");const raw=storage.getItem(PROFILE_KEY),restored=new StudentSession(storage);
 assert.equal(restored.readable,true);assert.equal(restored.working.practiceRecords.length,2);
 assert.equal(restored.working.practiceRecords[0].source.sha256,"a".repeat(64));
 const t=new DiskTest(restored.beginAdaptivePractice(),bytes("asdf asdf"),{name:"NEW.TST"});
 t.input("Escape",100);restored.recordPractice(t.record());
 storage.setItem=()=>{throw Error("full");};assert.ok(restored.commit());assert.equal(restored.dirty,true);
 restored.discard();assert.equal(restored.working.practiceRecords.length,2);assert.equal(storage.getItem(PROFILE_KEY),raw);
});
