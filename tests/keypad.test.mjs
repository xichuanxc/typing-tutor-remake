import test from "node:test";
import assert from "node:assert/strict";
import {createCurriculum} from "../dist/curriculum.js";
import D from "../dist/curriculum-data.js";
import {KeypadGenerator,KeypadLesson,KeypadTest,KEYPAD_KEYS,keypadIndex,nextKeypadKey,validKeypadRecord} from "../dist/keypad.js";
const at=(index=66,seed=0)=>Object.assign(createCurriculum(),{keypadIntroduced:index,keypadNewKey:0,seed});
function finishEntry(a,now=100){
  for(const key of [...a.line.target,"Enter"])a.input(key,now+=100);
  return now;
}
test("keypad keys map separately from main-row digits and reject malformed keys",()=>{
  assert.equal(KEYPAD_KEYS,"4567891230.");
  assert.deepEqual([...KEYPAD_KEYS].map(keypadIndex),Array.from({length:11},(_,i)=>64+i));
  for(const x of [undefined,null,0,{},[],true,"","44","+","x"])assert.equal(keypadIndex(x),-1);
  assert.notEqual(keypadIndex("4"),D.keyIndex["4"]);
});
test("native keypad generator uses 4..9 weighted learned digits and fixed cents position",()=>{
  const g=new KeypadGenerator(at());
  assert.deepEqual(Array.from({length:3},()=>g.number()),["46544","44554544","4546"]);
  assert.equal(new KeypadGenerator(at(74)).number(),"28.21");
  let checked=0;
  for(let level=66;level<=74;level++)for(let seed=0;seed<20;seed++){
    const g=new KeypadGenerator(at(level,seed));
    for(let n=0;n<20;n++){
      const s=g.number();assert.ok(s.length>=4&&s.length<=9);
      assert.ok([...s].every(c=>g.known(c)));
      if(level===74)assert.equal(s[s.length-3],".");
      else assert.ok(!s.includes("."));
      checked++;
    }
  }
  assert.equal(checked,3600);
});
test("keypad introduction uses fewer than three unmastered keys and stops at decimal",()=>{
  const c=at();assert.equal(nextKeypadKey(c)," ");assert.equal(c.keypadIntroduced,66);
  Object.assign(c.saved[64],{correct:31,errors:0,time:1860});
  assert.equal(nextKeypadKey(c),"7");assert.equal(c.keypadIntroduced,67);
  assert.equal(nextKeypadKey(c)," "); // three unmastered:5,6,7
  for(let i=64;i<=74;i++)Object.assign(c.saved[i],{correct:31,errors:0,time:1860});
  assert.deepEqual(Array.from({length:7},()=>nextKeypadKey(c)),[..."891230."]);
  assert.equal(nextKeypadKey(c)," ");assert.equal(c.keypadIntroduced,74);
});
test("initial explanation gates typing; timed samples and errors affect only keypad slots",()=>{
  const c=createCurriculum(),l=new KeypadLesson(c,5);
  assert.deepEqual(l.pendingGuide,{type:"keypad-intro"});assert.equal(c.keypadIntroduced,66);
  assert.equal(l.input("4",100).ignored,true);l.acknowledgeGuide();
  const text=l.line.target,key=text[1],index=keypadIndex(key);
  l.input(text[0],100);l.input("x",200);l.input("Backspace",300);
  l.input(key,400);for(const ch of [...text.slice(2),"Enter"])l.input(ch,500);
  assert.equal(c.current[index].errors,1);assert.equal(c.current[D.keyIndex[key]].errors,0);
  assert.equal(l.lines[0].result.accuracy,100);assert.ok(l.lines[0].attempts.some(a=>!a.correct));
  assert.equal(l.record().totals.correct,0,"A partial three-number drill has no committed total");
  assert.ok(validKeypadRecord(l.record()));
});
test("new keypad digits receive nine untallied counterpart warmups, including abort cleanup",()=>{
  const c=at();Object.assign(c.saved[64],{correct:31,errors:0,time:1860});
  const l=new KeypadLesson(c,5);assert.equal(c.keypadIntroduced,67);
  assert.ok(l.tutorial);assert.equal(l.tutorial.key,"7");assert.equal(l.tutorial.home,"4");assert.equal(l.tutorial.finger,1);
  assert.ok(l.tutorial.line.target.startsWith("4747"));
  const original=l.entries.map(l=>l.target),before=structuredClone(c.current);let now=100;
  for(let n=0;n<9;n++){
    const text=l.tutorial.line.target;assert.equal(text.length,8);assert.match(text,/^[47]+$/);
    for(const key of [...text,"Enter"])l.input(key,now+=100);
  }
  assert.equal(l.tutorial,null);assert.equal(c.keypadNewKey,0);assert.deepEqual(c.current,before);
  assert.deepEqual(l.entries.map(l=>l.target),original);assert.equal(l.record().totals.correct,0);
  const abortedState=at();Object.assign(abortedState.saved[64],{correct:31,errors:0,time:1860});
  const aborted=new KeypadLesson(abortedState,5);aborted.input("4",100);aborted.input("Escape",200);
  assert.equal(aborted.finished,true);assert.equal(abortedState.keypadNewKey,0);
  assert.ok(abortedState.current.every(s=>s.time===0));assert.ok(validKeypadRecord(aborted.record()));
});
test("three-number drills commit atomically and preserve native displayed-speed discrepancy",()=>{
  const l=new KeypadLesson(at(),5);let now=100;
  for(let n=0;n<3;n++)now=finishEntry(l,now);
  const r=l.record();assert.equal(r.batches,1);assert.equal(r.lines.length,3);
  assert.ok(validKeypadRecord(r));assert.equal(l.displayTotals().positions,r.totals.positions+4);
  for(let n=0;n<2;n++)now=finishEntry(l,now);
  l.input(l.line.target[0],now+=100);l.input("Escape",now+=100);
  const aborted=l.record();assert.equal(aborted.lines.length,5);assert.equal(aborted.batches,1);
  assert.deepEqual(aborted.totals,r.totals);assert.ok(validKeypadRecord(aborted));
});
test("keypad tests generate24 learned-range entries and commit only when all complete",()=>{
  const c=at(),before={introduced:c.introduced,keypadIntroduced:c.keypadIntroduced},t=new KeypadTest(c);
  assert.equal(t.entries.length,24);assert.ok(t.entries.every(l=>/^[456]+$/.test(l.target)));
  let now=100;for(let n=0;n<23;n++)now=finishEntry(t,now);
  assert.equal(t.record().totals.correct,0);assert.equal(t.record().completed,false);
  assert.ok(validKeypadRecord(t.record()));
  now=finishEntry(t,now);const r=t.record();
  assert.equal(r.completed,true);assert.equal(r.batches,1);assert.equal(r.lines.length,24);
  assert.equal(r.totals.accuracy,100);assert.equal(r.totals.positions,r.lines.reduce((n,l)=>n+l.target.length-1,0));
  assert.ok(validKeypadRecord(r));assert.deepEqual({introduced:c.introduced,keypadIntroduced:c.keypadIntroduced},before);
  assert.equal(t.input("4",now+1).ignored,true);
});
test("keypad validation rejects tampered totals, observation keys and completed partials without throwing",()=>{
  const t=new KeypadTest(at());let now=100;
  for(let n=0;n<24;n++)now=finishEntry(t,now);
  const r=t.record();assert.ok(validKeypadRecord(r));
  for(const mutate of [
    r=>r.totals.correct++,r=>r.batches=0,r=>r.lines[0].target="abcd",
    r=>r.lines[0].attempts[0].key=null,r=>r.lines[0].observations=[],
    r=>r.partialAttempts.push({key:"4",correct:true,time:10}),
  ]){
    const bad=structuredClone(r);mutate(bad);assert.equal(validKeypadRecord(bad),false);
  }
  assert.equal(validKeypadRecord(null),false);
});
