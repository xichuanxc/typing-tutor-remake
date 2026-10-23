import test from "node:test";
import assert from "node:assert/strict";
import D from "../dist/curriculum-data.js";
import {createCurriculum,validCurriculum} from "../dist/curriculum.js";
import {DrillGenerator,DosRandom} from "../dist/drill-generator.js";
import {AdaptiveLesson} from "../dist/adaptive-lesson.js";
import {validPracticeRecord,PracticeLesson} from "../dist/practice.js";
import {StudentSession,PROFILE_KEY,DEFAULT_PROFILE} from "../dist/faithful-session.js";
const index=c=>D.keyIndex[c];
function at(level,seed=0){
  const s=createCurriculum();s.introduced=level;s.seed=seed;
  s.alphabetic=[...D.presentation.slice(4,level+1)].filter(c=>D.charFlags[c.charCodeAt(0)]&3).length;
  s.shiftLearned=level>=8?1:0;return s;
}
function master(s,keys){for(const key of keys)Object.assign(s.saved[index(key)],{correct:31,errors:0,time:1860});}
test("original random generator updates 16-bit seed and uses its high byte",()=>{
  const state={seed:0},r=new DosRandom(state);
  assert.deepEqual(Array.from({length:8},()=>r.next(100)),[21,25,82,42,24,11,71,7]);
  assert.equal(state.seed,4856);assert.equal(r.next(0),0);assert.notEqual(state.seed,4856);
});
test("dictionary extraction preserves independently addressed blocks and original symbols",()=>{
  assert.equal(Object.keys(D.dictionary).length,1058);
  assert.equal(Object.values(D.dictionary).reduce((n,words)=>n+words.length,0),4019);
  assert.equal(D.dictionaryIndex.length,46);assert.ok(D.dictionaryIndex.every(a=>a.length===23));
  assert.equal(D.grammar.length,481);assert.equal(D.grammarOffsets.length,51);
  assert.equal(D.presentation.slice(0,12),"asdfjkl;eit.");
});
test("recovered grammar produces deterministic word drills instead of fixed four-key groups",()=>{
  const g=new DrillGenerator(at(3));
  assert.deepEqual(Array.from({length:3},()=>g.line()),[
    "sad add add ada das add da","fad daa daa af sad a sad","sad ada af dada asa sass"]);
  const shifted=new DrillGenerator(at(8));assert.match(shifted.line(),/^[A-Z]/);
});
test("grammar stays within the introduced alphabet across levels and random seeds",()=>{
  let checked=0;
  for(let level=3;level<=28;level++)for(let seed=0;seed<30;seed++){
    const g=new DrillGenerator(at(level,seed));
    for(let i=0;i<12;i++){
      const line=g.line();assert.ok(line.length>=2&&line.length<=26);
      assert.ok([...line].every(c=>c===" "||index(c)<=level),level+": "+line);checked++;
    }
  }
  assert.equal(checked,9360);
  assert.ok(new DrillGenerator(at(29)).line().length<=26);
});
test("word callbacks preserve singular/plural, possessive and suffix rules",()=>{
  const g=new DrillGenerator(at(28));
  g.word=()=>"glass";assert.equal(g.callback(26),"glasses");const calls=[];g.word=alias=>{calls.push(alias);return "glass";};
  assert.equal(g.callback(33),"glasses");assert.deepEqual(calls,[7]);
  assert.equal(g.known("\\"),false);
  g.word=()=>"make";assert.equal(g.callback(37),"maked");assert.equal(g.callback(38),"making");
  g.callbackOriginal=g.callback;g.word=alias=>alias===8?"a":"apple";
  g.callback=function(id){return id===23?"apple":this.callbackOriginal(id);};
  assert.equal(g.callback(25),"an apple");assert.equal(g.callback(29),"an apple's");
});
test("a new home key is introduced from individual mastery and shown before normal practice",()=>{
  const s=at(3);master(s,"a");
  const lesson=new AdaptiveLesson(s,5);
  assert.equal(s.introduced,4);assert.deepEqual(lesson.pendingGuide,{type:"home",key:"j"});
  assert.equal(s.newKey,0);assert.equal(lesson.tutorial,null);
  assert.deepEqual(lesson.input("x",100),{ignored:true});lesson.acknowledgeGuide();
  assert.ok(lesson.line.target.length<=26);
});
test("new reach keys receive three untallied home-key drills before the scored line",()=>{
  const s=at(7);s.shiftLearned=1;master(s,"asdfjkl;");
  const lesson=new AdaptiveLesson(s,5),original=lesson.line.target;
  assert.equal(s.introduced,8);assert.equal(lesson.pendingGuide,null);
  assert.ok(lesson.tutorial.line.target.startsWith("dede "));lesson.acknowledgeGuide();
  let now=100;
  for(let i=0;i<3;i++){for(const key of [...lesson.tutorial.line.target,"Enter"]){lesson.input(key,now);now+=50;}}
  assert.equal(lesson.tutorial,null);assert.equal(lesson.line.target,original);
  assert.equal(lesson.lines.length,0);assert.ok(s.current.every(a=>a.correct+a.errors===0));
  assert.equal(s.newKey,0);assert.equal(s.weights[index("e")],255);
});
test("Shift is a separate introduction and mastery continues into punctuation",()=>{
  const s=at(7);s.shiftPending=1;
  const lesson=new AdaptiveLesson(s,5);assert.deepEqual(lesson.pendingGuide,{type:"shift"});
  assert.equal(s.shiftLearned,1);assert.match(lesson.line.target,/[A-Z]/);
  const last=at(28);master(last,D.presentation.slice(0,29));
  const bounded=new AdaptiveLesson(last,5);assert.equal(last.introduced,29);
  assert.ok([...bounded.line.target].every(c=>c===" "||index(c)<=29));
});
test("corrected errors still update adaptive samples; an aborted line adds no final score",()=>{
  const s=at(3),lesson=new AdaptiveLesson(s,5);lesson.input(lesson.line.target[0],100);
  const key=lesson.line.target[1];lesson.input("x",200);lesson.input("Backspace",300);lesson.input(key,400);
  assert.equal(s.current[index(key)].errors,1);assert.equal(lesson.line.errors[1],false);
  lesson.input("Escape",500);
  assert.equal(lesson.record().totals.correct,0);assert.ok(validPracticeRecord(lesson.record()));
  assert.ok(validCurriculum(s));assert.equal(lesson.record().kind,"adaptive-alpha-f4");
});
test("explicit saving merges current samples once and reload/discard preserve earlier records",()=>{
  const map=new Map(),storage={getItem:k=>map.get(k)??null,setItem:(k,v)=>map.set(k,v)};
  const s=new StudentSession(storage),old=new PracticeLesson(5);old.input("Escape",1);s.recordPractice(old.record());
  const c=s.beginAdaptivePractice(),lesson=new AdaptiveLesson(c,5);
  lesson.input(lesson.line.target[0],100);lesson.input(lesson.line.target[1],200);lesson.input("Escape",300);
  s.recordPractice(lesson.record());const current=c.current.map(a=>({...a}));
  storage.setItem=()=>{throw Error();};assert.ok(s.commit());assert.deepEqual(c.current,current);
  storage.setItem=(k,v)=>map.set(k,v);assert.equal(s.commit(),"");
  const reloaded=new StudentSession(storage);assert.equal(reloaded.working.practiceRecords.length,2);
  assert.ok(reloaded.working.curriculum.current.every(a=>a.time===0));
  assert.deepEqual(reloaded.working.curriculum.saved,current);
  assert.equal(reloaded.commit(),"");assert.deepEqual(reloaded.working.curriculum.saved,current);
  reloaded.beginAdaptivePractice().introduced=4;reloaded.discard();assert.equal(reloaded.working.curriculum.introduced,3);
  assert.equal(reloaded.working.practiceRecords[0].kind,"home-keys-f3");
});
test("unreadable adaptive state is retained without overwrite; older settings bootstrap separately",()=>{
  const raw=JSON.stringify({version:2,activeId:"student-1",profiles:[{...DEFAULT_PROFILE,curriculum:{version:999}}]});
  const storage={getItem:()=>raw,setItem:()=>{throw Error("must not write");}},s=new StudentSession(storage);
  assert.ok(s.warning);s.beginAdaptivePractice();assert.ok(s.commit());
  const old=new StudentSession({getItem:()=>null,setItem:()=>{}});assert.equal(old.working.curriculum,undefined);
  assert.equal(old.beginAdaptivePractice().introduced,3);
});
