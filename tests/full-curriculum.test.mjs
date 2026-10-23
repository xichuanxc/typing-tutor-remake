import test from "node:test";
import assert from "node:assert/strict";
import D from "../dist/curriculum-data.js";
import {createCurriculum,validCurriculum} from "../dist/curriculum.js";
import {AdaptiveLesson} from "../dist/adaptive-lesson.js";
import {validPracticeRecord} from "../dist/practice.js";
import {StudentSession,PROFILE_KEY} from "../dist/faithful-session.js";
import {progressModel} from "../dist/reports-model.js";
import {drawTutorial} from "../dist/keyboard-screen.js";
import {DrillGenerator} from "../dist/drill-generator.js";
import {Grid} from "../dist/grid.js";
export function pending(level,seed=0){
 const c=createCurriculum();Object.assign(c,{introduced:level,alphabetic:22,shiftLearned:1,newKey:D.presentation.charCodeAt(level),seed,introShown:true});return c;
}
function reachLesson(level){
 for(let seed=0;seed<100;seed++){
  const c=pending(level,seed),l=new AdaptiveLesson(c,20);let now=100;
  for(let n=0;!l.tutorial&&n<19;n++){
   for(const ch of [...l.line.target,"Enter"])l.input(ch,now+=100);
  }
  if(l.tutorial)return {c,l,seed};
 }
 throw Error("Reach tutorial never appeared for "+level);
}
test("all 35 later keys use original counterpart drills and unscored guide completion",()=>{
 for(let level=29;level<=63;level++){
  const {c,l}=reachLesson(level),key=D.presentation[level],home=D.counterpart[level],original=l.line.target;
  const before=structuredClone(c.current),completed=l.lines.length;
  assert.equal(l.pendingGuide,null);assert.ok(l.tutorial.line.target.startsWith(home+key+home+key+" "));
  const grid=new Grid();drawTutorial(grid,l);
  assert.equal(c.newKey,key.charCodeAt(0));l.acknowledgeGuide();
  let now=100;
  for(let n=0;n<3;n++){
   assert.ok([...l.tutorial.line.target].every(c=>c===" "||c===key||c===home));
   for(const ch of [...l.tutorial.line.target,"Enter"])l.input(ch,now+=100);
  }
  assert.equal(l.line.target,original);assert.equal(l.tutorial,null);assert.equal(c.newKey,0);
  assert.equal(l.lines.length,completed);assert.deepEqual(c.current,before);
  l.input("Escape",now+100);assert.ok(validPracticeRecord(l.record()));
  assert.equal(l.record().kind,"adaptive-keyboard-f4c");
 }
});
test("pending punctuation waits until its scored line contains the key",()=>{
 let found=false;
 for(let seed=0;seed<100;seed++){
  const c=pending(29,seed),l=new AdaptiveLesson(c,5);
  if(l.tutorial)continue;
  found=true;assert.equal(c.newKey,39);assert.equal(l.pendingGuide,null);
  assert.ok(!l.line.target.includes("'"));break;
 }
 assert.ok(found);
});
test("leaving reach practice clears pending key without timing samples or final results",()=>{
 for(const level of [8,29,37,49,63]){
  let l;
  if(level===8){const c=createCurriculum();Object.assign(c,{introduced:8,alphabetic:4,newKey:101,shiftLearned:1});l=new AdaptiveLesson(c,5);}
  else l=reachLesson(level).l;
  const c=l.curriculum,before=structuredClone(c.current);assert.ok(l.tutorial);l.acknowledgeGuide();
  l.input(l.tutorial.line.target[0],100);l.input(l.tutorial.line.target[1],200);
  assert.equal(l.input("Escape",300).aborted,true);
  assert.equal(c.newKey,0);assert.equal(l.record().totals.correct,l.lines.reduce((n,l)=>n+l.result.correct,0));
  assert.deepEqual(c.current,before);assert.equal(l.record().partialAttempts.length,0);
  if(level===8)assert.equal(c.weights[8],255);
 }
});
test("full-key lessons validate, save/reload, discard and contribute to faithful reports",()=>{
 const map=new Map(),storage={getItem:k=>map.get(k)??null,setItem:(k,v)=>map.set(k,v)};
 const s=new StudentSession(storage);s.working.curriculum=pending(63);s.working.curriculum.newKey=0;
 const l=new AdaptiveLesson(s.beginAdaptivePractice(),5);let now=100;
 while(!l.finished){assert.equal(l.pendingGuide,null);for(const ch of [...l.line.target,"Enter"])l.input(ch,now+=100);}
 const r=l.record();assert.ok(validPracticeRecord(r));assert.equal(r.totals.accuracy,100);
 assert.ok(r.lines.every(l=>[...l.target].every(c=>c===" "||D.keyIndex[c]>=0)));s.recordPractice(r);
 assert.ok(progressModel(s.working,s.saved).groups[1].rows.length);
 assert.equal(s.commit(),"");const reloaded=new StudentSession(storage);
 assert.equal(reloaded.readable,true);assert.equal(reloaded.working.curriculum.introduced,63);
 assert.deepEqual(reloaded.working.practiceRecords,[r]);assert.ok(validCurriculum(reloaded.working.curriculum));
 reloaded.working.curriculum.seed=123;reloaded.discard();assert.notEqual(reloaded.working.curriculum.seed,123);
 assert.equal(JSON.parse(map.get(PROFILE_KEY)).profiles[0].curriculum.introduced,63);
 const bad=structuredClone(r);bad.lines[0].target="\\";
 assert.equal(validPracticeRecord(bad),false);
 const mislabeled=structuredClone(r);mislabeled.kind="adaptive-alpha-f4";assert.equal(validPracticeRecord(mislabeled),false);
});
test("the full keyboard remains at its last key after mastery",()=>{
 const c=pending(63);c.newKey=0;
 c.saved.forEach(s=>Object.assign(s,{correct:31,errors:0,time:1860}));
 const l=new AdaptiveLesson(c,5);assert.equal(c.introduced,63);assert.equal(l.pendingGuide,null);assert.equal(c.newKey,0);
});

test("pending introductions preserve the original generated phrase across scored lines",()=>{
 const c=pending(29),g=new DrillGenerator(structuredClone(c)),l=new AdaptiveLesson(c,5);
 assert.equal(l.tutorial,null);assert.equal(l.line.target,g.line());
 l.prepare();assert.equal(l.line.target,g.line());assert.equal(c.newKey,39);
});
