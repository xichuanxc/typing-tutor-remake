import test from "node:test";
import assert from "node:assert/strict";
import {readDiskText,DiskTest,validDiskRecord} from "../dist/disk-test.js";
import {createCurriculum} from "../dist/curriculum.js";
import {totals} from "../dist/practice.js";
const bytes=text=>new TextEncoder().encode(text);
function packed(text,declared=text.length+1){
 const source=[...text].map(c=>c.charCodeAt(0)),out=new Uint8Array(source.length+3);
 out.set([1,declared&255,declared>>>8],0);
 source.forEach((b,i)=>{const shift=i%7+1;out[i+3]=((b<<shift)|(b>>>(8-shift)))&255;});
 return out;
}
function finishLine(t,now=100){
 for(const key of [...t.line.target,"Enter"]){t.input(key,now);now+=100;}return now;
}
test("plain Disk reader uses DOS seven-bit text, skips NUL/CR and stops at Ctrl-Z",()=>{
 const input=new Uint8Array([32,32,0xc1,13,10,9,32,66,0,67,32,26,88]);
 assert.deepEqual(readDiskText(input),{targets:["A   BC"],format:"plain",byteLength:input.length});
 assert.deepEqual(readDiskText(bytes("a\r\nb\tc\n\nd")).targets,["a b c  d"]);
});
test("Disk wrapping preserves 72 columns and carries text at native whitespace boundaries",()=>{
 const text="a".repeat(70)+" b c";
 assert.deepEqual(readDiskText(bytes(text)).targets,["a".repeat(70)+" b","c"]);
 assert.equal(readDiskText(bytes("a".repeat(72))).targets.length,1);
 assert.equal(readDiskText(bytes("a".repeat(72))).targets[0].length,72);
 assert.deepEqual(readDiskText(bytes("word"+" ".repeat(100)+"next")).targets,["word","next"]);
});
test("native overlong-word splitting drops its remainder and counts the EOF-returning empty line",()=>{
 assert.deepEqual(readDiskText(bytes("a".repeat(90))).targets,["a".repeat(72),""]);
 assert.deepEqual(readDiskText(bytes("a".repeat(90)+" end")).targets,["a".repeat(72),"end"]);
 assert.deepEqual(readDiskText(bytes("")).targets,[""]);
 assert.deepEqual(readDiskText(bytes("x")).targets,["x"]);
});
test("rotated DOS envelope uses seven-shift byte decoding and its signed length cutoff",()=>{
 const vector=Uint8Array.from([1,4,0,0x90,0x95,0x63]); // ROL1 H, ROL2 e, ROL3 l
 assert.deepEqual(readDiskText(vector),{targets:["Hel"],format:"rotated",byteLength:6});
 assert.deepEqual(readDiskText(packed("Hello   world!")).targets,["Hello   world!"]);
 assert.deepEqual(readDiskText(packed("abcd",3)).targets,["ab"]);
 assert.deepEqual(readDiskText(Uint8Array.from([1,0,128])).targets,[""]);
 // Packed control characters are whitespace, not the plain reader's CR/NUL skips.
 assert.deepEqual(readDiskText(packed("a\r\0b")).targets,["a  b"]);
});
test("malformed or untypeable source data is rejected rather than inventing key counters",()=>{
 assert.throws(()=>readDiskText(Uint8Array.from([1,2])),/header/);
 assert.throws(()=>readDiskText(Uint8Array.from([1,9,0,0])),/declared length/);
 for(const text of ["back\\slash","pipe|key","backtick\u0060","DEL"+String.fromCharCode(127)])
  assert.throws(()=>readDiskText(bytes(text)),/recovered typing keyboard/);
 assert.throws(()=>readDiskText("text"),/bytes/);
});
test("one-character and empty EOF lines use native integer boundaries without changing teaching state",()=>{
 for(const target of ["","x"]){
  const c=createCurriculum(),before={introduced:c.introduced,alphabetic:c.alphabetic,newKey:c.newKey,seed:c.seed};
  const t=new DiskTest(c,bytes(target),{name:"SHORT.TST"});finishLine(t);
  assert.equal(t.completed,true);assert.equal(t.record().lines.length,1);
  assert.equal(t.record().lines[0].result.positions,(target.length-1)>>>0);
  assert.equal(t.record().totals.accuracy,100);assert.ok(validDiskRecord(t.record()));
  assert.deepEqual({introduced:c.introduced,alphabetic:c.alphabetic,newKey:c.newKey,seed:c.seed},before);
 }
});
test("six-line screens continue immediately and only complete screens enter final totals",()=>{
 const text=bytes("alpha ".repeat(100)),t=new DiskTest(createCurriculum(),text),targets=readDiskText(text).targets;
 assert.ok(targets.length>6);let now=100,event;
 for(let n=0;n<6;n++)for(const key of [...t.line.target,"Enter"]){event=t.input(key,now);now+=100;}
 assert.equal(event.pageDone,true);assert.equal(t.page,1);assert.equal(t.activeLine,0);assert.equal(t.lines[0].target,targets[6]);
 const committed=t.record().totals;now=finishLine(t,now);
 t.input(t.line.target[0],now+=100);t.input(t.line.target[1],now+=100);t.input("Escape",now+=100);
 const aborted=t.record();assert.equal(aborted.completed,false);assert.deepEqual(aborted.pages,[6]);
 assert.equal(aborted.lines.length,7);assert.deepEqual(aborted.totals,committed);
 assert.ok(aborted.partialAttempts.length>0);assert.ok(validDiskRecord(aborted));
 const complete=new DiskTest(createCurriculum(),text);now=100;
 while(!complete.finished)now=finishLine(complete,now);
 const record=complete.record();assert.equal(record.completed,true);assert.deepEqual(record.pages,[6,targets.length-6]);
 assert.deepEqual(record.totals,totals(record.lines));assert.ok(validDiskRecord(record));
 assert.equal(complete.input("x",now).ignored,true);
});
test("corrected Disk errors disappear from final accuracy and remain in timed expected-key samples",()=>{
 const c=createCurriculum(),t=new DiskTest(c,bytes("alpha beta"));
 t.input("a",100);t.input("?",200);t.input("Backspace",300);
 let now=400;for(const key of [...t.line.target.slice(1),"Enter"]){t.input(key,now);now+=100;}
 const r=t.record();assert.equal(r.totals.errors,0);assert.equal(r.totals.accuracy,100);
 assert.ok(r.lines[0].attempts.some(a=>!a.correct));assert.ok(c.current.some(s=>s.errors>0));
 assert.ok(validDiskRecord(r));
});
test("packed Escape is a typed error in the body and at the boundary, not native cancellation",()=>{
 const t=new DiskTest(createCurriculum(),packed("ab"));
 let event=t.input("Escape",100);assert.equal(event.error,true);assert.equal(event.aborted,undefined);
 assert.equal(t.finished,false);assert.equal(t.line.typed[0],"\x1b");
 t.input("Backspace",200);t.input("a",300);t.input("b",400);
 event=t.input("Escape",500);assert.equal(event.testDone,true);assert.equal(event.error,true);
 assert.equal(t.record().totals.errors,1);assert.ok(validDiskRecord(t.record()));
 const plain=new DiskTest(createCurriculum(),bytes("ab"));assert.equal(plain.input("Escape",100).aborted,true);
 assert.equal(plain.record().totals.correct,0);assert.ok(validDiskRecord(plain.record()));
});
test("Disk records validate page accounting, source identity and observations without accepting tampering",()=>{
 const t=new DiskTest(createCurriculum(),bytes("alpha beta"),{name:"SOURCE.TST",originalName:"A local source.txt",sha256:"a".repeat(64)});
 finishLine(t);const r=t.record();assert.ok(validDiskRecord(r));
 for(const mutate of [
  r=>r.pages[0]=7,r=>r.pages=[],r=>r.totals.correct++,r=>r.lines[0].target="\\",
  r=>r.lines[0].observations=[],r=>r.lines[0].attempts[0].key=null,
  r=>r.source.name="OTHER.TST",r=>r.source.sha256="bad",r=>r.source.format="utf8",
  r=>r.partialAttempts.push({key:"a",correct:true,time:10})
 ]){
  const bad=structuredClone(r);mutate(bad);assert.equal(validDiskRecord(bad),false);
 }
 assert.equal(validDiskRecord(null),false);assert.equal(validDiskRecord({}),false);
});
