import test from "node:test";
import assert from "node:assert/strict";
import D from "../dist/curriculum-data.js";
import {createCurriculum,validCurriculum,recordAttempt,needsPractice,needsHistoryPractice,mastered,
  recalculateThreshold,nextKey,beginLesson,completeNewKey,commitCurriculum,alphabeticWeightTotal,
  rankings,summaryRankings} from "../dist/curriculum.js";
const index=key=>D.keyIndex[key];
const set=(s,kind,key,correct,errors,time)=>Object.assign(s[kind][index(key)],{correct,errors,time});
test("unnamed-record bootstrap is independent and preserves original introduction state",()=>{
  const a=createCurriculum(),b=createCurriculum();
  assert.equal(a.introduced,3);assert.equal(a.alphabetic,0);assert.equal(a.newKey,0);
  assert.deepEqual(a.thresholds,[10,5]);assert.equal(alphabeticWeightTotal(a),1020);
  assert.equal(a.weights.length,75);assert.ok(a.weights.every(n=>n===255));
  assert.ok(validCurriculum(a));a.current[0].correct=9;a.weights[0]=4;
  assert.equal(b.current[0].correct,0);assert.equal(b.weights[0],255);
  assert.equal(validCurriculum({...b,introduced:64}),false);
  assert.ok(validCurriculum({...b,seed:65535,introShown:true}));
  assert.equal(validCurriculum({...b,seed:65536}),false);
  assert.equal(validCurriculum({...b,introShown:1}),false);
  assert.equal(validCurriculum({...b,current:Array(75).fill({correct:-1,errors:0,time:0})}),false);
});
test("timed samples update expected key and adaptive penalty; spaces and zero time do not",()=>{
  const s=createCurriculum(),i=index("a");
  assert.equal(recordAttempt(s,{key:"a",correct:true,time:0}),false);
  assert.equal(recordAttempt(s,{key:" ",correct:false,time:100}),false);
  recordAttempt(s,{key:"a",correct:true,time:60});
  assert.deepEqual(s.current[i],{correct:1,errors:0,time:60});
  assert.equal(s.weights[i],140); // (255 + 3 * floor(2040 / 20)) / 4
  recordAttempt(s,{key:"a",correct:false,time:60});
  assert.equal(s.weights[i],145); // old + floor(old / 32) + 1
  assert.equal(s.current[i].errors,1);
  assert.throws(()=>recordAttempt(s,{key:"a",correct:true,time:501}));
});
test("penalty cap, zero-speed fallback and unsigned sample overflow match arithmetic",()=>{
  const s=createCurriculum(),i=index("a");
  recordAttempt(s,{key:"a",correct:false,time:1});assert.equal(s.weights[i],255);
  s.weights[i]=0;recordAttempt(s,{key:"a",correct:false,time:500});assert.equal(s.weights[i],1);
  set(s,"current","a",0xffffffff,0,0xffffffff);
  recordAttempt(s,{key:"a",correct:true,time:1});
  assert.deepEqual(s.current[i],{correct:0,errors:0,time:0});assert.equal(s.weights[i],255);
});
test("correct-key penalty uses a signed sixteen-bit WPM divisor",()=>{
  const s=createCurriculum(),i=index("a");
  set(s,"current","a",4368,0,79);
  recordAttempt(s,{key:"a",correct:true,time:1}); // returned WPM65535 is IDIV divisor -1
  assert.equal(s.weights[i],255);
});
test("current improvement and saved mastery use distinct evidence",()=>{
  const s=createCurriculum(),i=index("a");
  assert.equal(needsPractice(s,i),false);assert.equal(needsHistoryPractice(s,i),true);
  assert.equal(mastered(s,i),false);
  set(s,"current","a",30,0,1800);
  assert.equal(needsPractice(s,i),false);assert.equal(mastered(s,i),false);
  set(s,"current","a",31,0,1860);
  assert.equal(mastered(s,i),true);
  set(s,"current","a",31,8,2340);
  assert.equal(needsPractice(s,i),true);assert.equal(mastered(s,i),false); // floor(3100/39)=79
});
test("history minimum is inclusive but session-only fallback is strictly above thirty",()=>{
  const s=createCurriculum(),i=index("a");
  set(s,"saved","a",29,0,1740);
  assert.equal(needsHistoryPractice(s,i),true);
  set(s,"current","a",1,0,60);
  assert.equal(needsHistoryPractice(s,i),false);assert.equal(mastered(s,i),true);
  set(s,"saved","a",24,6,1800);set(s,"current","a",6,0,360);
  assert.equal(needsHistoryPractice(s,i),false); // exact 80% is accepted
  s.saved[i].errors=7;assert.equal(needsHistoryPractice(s,i),true);
});
test("mastery excludes unintroduced and currently taught keys, plus test type three",()=>{
  const s=createCurriculum(),i=index("f");
  set(s,"current","f",31,0,1860);
  assert.equal(mastered(s,i),true);s.newKey="f".charCodeAt(0);
  assert.equal(mastered(s,i),false);s.newKey=0;
  assert.equal(mastered(s,i,{testType:3}),false);
  set(s,"current","j",100,0,6000);assert.equal(mastered(s,index("j")),false);
});
test("dynamic thresholds average speeds with original floors and goal cap",()=>{
  const s=createCurriculum(100);
  for(const key of "asdf")set(s,"current",key,1,0,10); // each 120WPM -> 60 threshold
  assert.equal(recalculateThreshold(s,100,0),60);
  assert.equal(recalculateThreshold(s,20,0),20);
  assert.equal(recalculateThreshold(s,100,1),5); // no non-alpha group yet
  s.introduced=29;
  for(let i=0;i<=29;i++)Object.assign(s.current[i],{correct:1,errors:0,time:10});
  assert.equal(recalculateThreshold(s,100,0),48);
  assert.equal(recalculateThreshold(s,100,1),48);
  assert.equal(recalculateThreshold(s,10,1),10);
  assert.throws(()=>recalculateThreshold(s,25,0));
});
test("threshold sum is signed sixteen-bit before integer division",()=>{
  const s=createCurriculum(100);s.introduced=63;
  for(let i=0;i<64;i++)Object.assign(s.current[i],{correct:1,errors:0,time:1}); // 76800 wraps 11264
  assert.equal(recalculateThreshold(s,100,0),70); // trunc(2*176/5)
});
test("next key waits for fewer than four unmastered keys and introduces j",()=>{
  const s=createCurriculum();
  assert.deepEqual(nextKey(s),{key:null,guide:false,shiftLesson:false});
  set(s,"current","a",31,0,1860);
  const next=beginLesson(s,20);
  assert.deepEqual(next,{key:"j",guide:true,shiftLesson:false});
  assert.equal(s.introduced,4);assert.equal(s.alphabetic,1);assert.equal(s.newKey,106);
  assert.equal(alphabeticWeightTotal(s),1275);
  assert.deepEqual(nextKey(s),{key:"j",guide:false,shiftLesson:false}); // pending introduction is retained
  s.weights[index("j")]=12;completeNewKey(s);
  assert.equal(s.newKey,0);assert.equal(s.weights[index("j")],255);
});
test("home keys hand off to Shift before the next alphabetic introduction",()=>{
  const s=createCurriculum();s.introduced=6;s.alphabetic=3;
  for(let i=0;i<=6;i++)Object.assign(s.current[i],{correct:31,errors:0,time:1860});
  assert.equal(nextKey(s).key,";");assert.equal(s.shiftPending,1);
  completeNewKey(s);
  assert.deepEqual(nextKey(s),{key:null,guide:true,shiftLesson:true});
  assert.equal(s.shiftPending,0);assert.equal(s.shiftLearned,1);
  const next=nextKey(s);assert.equal(next.key,"e");assert.equal(next.guide,false);assert.equal(s.alphabetic,4);
  s.introduced=63;s.newKey=0;assert.equal(nextKey(s).key,null);
});
test("explicit commit merges modulo32 once, clears current and preserves weights",()=>{
  const s=createCurriculum(),i=index("a");
  set(s,"saved","a",0xffffffff,2,0xffffffff);set(s,"current","a",2,1,4);s.weights[i]=44;
  assert.equal(commitCurriculum(s),s);
  assert.deepEqual(s.saved[i],{correct:1,errors:3,time:3});assert.deepEqual(s.current[i],{correct:0,errors:0,time:0});
  commitCurriculum(s);assert.equal(s.saved[i].correct,1);assert.equal(s.weights[i],44);
});
test("rankings retain original ties, case folding, duplicates and introductory omissions",()=>{
  const s=createCurriculum();
  assert.equal(rankings(s,"asdf",0),"as ");assert.equal(rankings(s,"asdf",1),"fds");
  assert.equal(rankings(s,"asASdf",2),"asd");
  s.introduced=4;assert.equal(rankings(s,"asdfj",2),"as ");
  s.weights[index("a")]=5;s.weights[index("s")]=2;s.weights[index("d")]=8;
  assert.equal(rankings(s,"a s d f j",1),"sad");assert.equal(rankings(s,"a s d f j",0),"fjd");
  s.newKey=106;
  assert.deepEqual(summaryRankings(s),{best:"sad",worst:"fd "}); // pending j excluded
  assert.throws(()=>rankings(s,"asdf",3));
});
