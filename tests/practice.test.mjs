import test from "node:test";
import assert from "node:assert/strict";
import {readFileSync} from "node:fs";
import {LineInput,PracticeLesson,accuracy,speed,totals,browserClock,DAY,validPracticeRecord,HOME_DRILLS} from "../dist/practice.js";
import {StudentSession,PROFILE_KEY,DEFAULT_PROFILE} from "../dist/faithful-session.js";
import {drawPractice} from "../dist/practice-screen.js";
import {Grid} from "../dist/grid.js";
import DATA from "../dist/original-data.js";
const run=(target,keys)=>{const l=new LineInput(target);keys.forEach((key,i)=>l.input(key,100+i*100));return l;};
test("assembly scoring kernels use wrapped unsigned products and 16-bit integer returns",()=>{
  assert.equal(accuracy(3,1),75);assert.equal(accuracy(2,1),66);assert.equal(accuracy(0,0),0);
  assert.equal(speed(2,0,200),12);assert.equal(speed(2,0,0),0);
  assert.equal(speed(100,0,1),120000&65535);
  assert.equal(speed(0x40000000,0,1),0);assert.equal(accuracy(0x40000000,0),0);
});
test("first key is untimed; line boundary counts in accuracy but is excluded from speed/time",()=>{
  const l=run("asd",["a","s","d","Enter"]);
  assert.deepEqual(l.result,{correct:4,errors:0,time:200,positions:2,wpm:12,accuracy:100});
  assert.deepEqual(l.attempts,[{key:"s",correct:true,time:100},{key:"d",correct:true,time:100}]);
  assert.deepEqual(l.input("x",800),{ignored:true});
});
test("corrected and uncorrected mistakes have separate final-line and attempt accounting",()=>{
  const wrong=run("asd",["a","x","d"," "]),fixed=run("asd",["a","x","Backspace","s","d","Enter"]);
  assert.equal(wrong.result.accuracy,75);assert.equal(wrong.result.wpm,12);
  assert.equal(fixed.result.accuracy,100);assert.equal(fixed.result.time,400);
  assert.deepEqual(fixed.attempts.map(a=>[a.key,a.correct]),[["s",false],["s",true],["d",true]]);
});
test("Backspace at start starts the timer, repeated correction clears markers, spaces have no individual records",()=>{
  const l=run("a s",["Backspace","Backspace","x","Backspace","Backspace","a"," ","s","Enter"]);
  assert.equal(l.result.accuracy,100);assert.equal(l.errors.some(Boolean),false);
  assert.equal(l.result.time,700);assert.ok(l.attempts.some(a=>a.key==="a"&&!a.correct));
  assert.ok(l.attempts.every(a=>a.key!==" "));
});
test("Enter/Tab within a line are ordinary errors; any final character ends it; only CR/space/plus are accepted",()=>{
  for(const key of ["Enter"," ","+"]){const l=run("as",["a","s",key]);assert.equal(l.result.accuracy,100);}
  const bad=run("as",["a","s","x"]);assert.equal(bad.result.correct,2);assert.equal(bad.result.errors,1);
  assert.equal(bad.result.accuracy,66);
  assert.equal(run("asd",["Enter","s","d","Enter"]).result.accuracy,75);
  assert.equal(run("asd",["a","Tab","d","Enter"]).result.accuracy,75);
  const l=new LineInput("as");assert.deepEqual(l.input("ArrowLeft",50),{ignored:true});assert.equal(l.epoch,null);
});
test("interval smoothing uses previous RAW interval, caps at 500; long pauses remain in total duration",()=>{
  const l=new LineInput("asd");
  l.input("a",100);l.input("s",200);assert.equal(l.interval,100);
  l.input("d",1200);assert.equal(l.interval,500);
  l.input("Enter",1300);assert.equal(l.interval,280);
  assert.equal(l.result.time,920);assert.equal(l.result.wpm,2);
  assert.deepEqual(l.attempts.map(a=>a.time),[100,500]);
});
test("zero tick intervals and midnight rollover; browser clock quantization stays separate",()=>{
  const zero=new LineInput("as");["a","s","Enter"].forEach(k=>zero.input(k,100));
  assert.equal(zero.result.time,0);assert.equal(zero.result.wpm,0);assert.equal(zero.attempts.length,0);
  const l=new LineInput("as");l.input("a",DAY-100);l.input("s",0);l.input("Enter",100);
  assert.equal(l.result.time,100);assert.equal(l.result.wpm,12);
  assert.equal(browserClock(0),0);assert.equal(browserClock(54),0);assert.equal(browserClock(55),5);
});
test("lesson summary sums counters and duration, not rounded per-drill scores; Escape excludes unfinished line",()=>{
  const lesson=new PracticeLesson(5);let now=100;
  for(let i=0;i<5;i++){for(const key of [...lesson.line.target,"Enter"]){lesson.input(key,now%DAY);now+=100;}}
  assert.equal(lesson.finished,true);assert.equal(lesson.record().completed,true);
  assert.ok(validPracticeRecord(lesson.record()));assert.equal(lesson.lines.length,5);
  assert.deepEqual(lesson.record().totals,totals(lesson.lines));
  const partial=new PracticeLesson(5);partial.input("a",100);partial.input("x",200);partial.input("Escape",300);
  const r=partial.record();assert.equal(r.completed,false);assert.equal(r.lines.length,0);assert.equal(r.totals.correct,0);
  assert.equal(r.partialAttempts.length,1);assert.ok(validPracticeRecord(r));
});
test("practice records commit/discard atomically with settings; old v2 settings load unchanged",()=>{
  const map=new Map([[PROFILE_KEY,JSON.stringify({version:2,activeId:DEFAULT_PROFILE.id,profiles:[{...DEFAULT_PROFILE}]})]]);
  const storage={getItem:k=>map.get(k)??null,setItem:(k,v)=>map.set(k,v)},s=new StudentSession(storage);
  const lesson=new PracticeLesson(5);lesson.input("a",100);lesson.input("s",200);lesson.input("Escape",300);
  s.recordPractice(lesson.record());assert.equal(s.dirty,true);assert.equal(s.saved.practiceRecords,undefined);
  s.discard();assert.equal(s.working.practiceRecords,undefined);
  s.recordPractice(lesson.record());assert.equal(s.commit(),"");
  assert.equal(new StudentSession(storage).working.practiceRecords.length,1);
  const r=lesson.record();r.totals.wpm=999;assert.throws(()=>s.recordPractice(r));
  s.storage.setItem=()=>{throw Error();};s.recordPractice(lesson.record());assert.ok(s.commit());
  assert.equal(s.working.practiceRecords.length,2);assert.equal(s.saved.practiceRecords.length,1);
  s.discard();assert.equal(s.working.practiceRecords.length,1);
});
test("practice frame uses recovered coordinates, attributes, arrows and post-drill stats",()=>{
  const lesson=new PracticeLesson(5),g=new Grid();drawPractice(g,lesson,DATA.practice);
  assert.equal(g.cells[5][22].char,"╒");assert.equal(g.cells[10][57].char,"╛");
  assert.equal(g.cells[13][25].char,"╒");assert.equal(g.cells[15][54].char,"╛");
  const left=Math.trunc((80-lesson.line.target.length)/2);
  assert.equal(g.cells[8][left].char,"↑");assert.equal(g.cells[8][left].attr,0x2f);
  lesson.input("x",100);g.clear();drawPractice(g,lesson,DATA.practice);
  assert.equal(g.cells[6][left].char,"↓");assert.equal(g.cells[6][left].attr,0x2c);
  lesson.input("Backspace",200);g.clear();drawPractice(g,lesson,DATA.practice);
  assert.equal(g.cells[6][left].char," ");
  let now=300;for(const key of [...lesson.line.target,"Enter"]){lesson.input(key,now);now+=100;}
  g.clear();drawPractice(g,lesson,DATA.practice);assert.equal(g.cells[17][31].char,"╒");
  assert.ok(g.lines()[18].includes("Speed:"));assert.ok(g.lines()[19].includes("100%"));
  assert.ok(HOME_DRILLS.every(l=>l.length<=26&&/^[asdf ]+$/.test(l)));
});
test("retained assembly anchors support the constants and key boundaries",()=>{
  const asm=name=>readFileSync("analysis/recovered/0x"+name+".asm","utf8").toLowerCase();
  assert.match(asm("152dc"),/mov bx, 0x4b0/);assert.match(asm("1529a"),/mov bx, 0x64/);
  assert.match(asm("14b92"),/0x1f4/);assert.match(asm("14cd6"),/0xd600/);
  for(const value of ["0xd","0x20","0x2b"])assert.ok(asm("14e95").includes(value));
});
