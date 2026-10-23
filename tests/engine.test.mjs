import test from "node:test";
import assert from "node:assert/strict";
import {createSession, input, pause, metrics, summary, makeLines, qualifies, aggregate} from "../dist/engine.js";
import {load, save, defaults, STORAGE_KEY} from "../dist/storage.js";

test("timer waits for first printable key; navigation and premature Enter are ignored", () => {
  const s=createSession(["asdf"]);
  input(s,"Enter",100); input(s,"Shift",200); input(s,"Backspace",300);
  assert.equal(s.startedAt,null); assert.equal(s.attempts,0);
  input(s,"a",1000); assert.equal(s.startedAt,1000);
});
test("mistakes advance, corrections retain attempt penalties, extra keys do not count", () => {
  const s=createSession(["as"]);
  input(s,"x",0); input(s,"Backspace",100); input(s,"a",200); input(s,"s",400);
  assert.equal(input(s,"z",500),"ignored"); input(s,"Enter",60000);
  assert.ok(Math.abs(metrics(s,99999).accuracy - 200/3) < 1e-10);
  assert.equal(metrics(s,99999).wpm,0.4);
  assert.equal(s.perKey.a.attempts,2);
  assert.equal(summary(s,60000).attempts,3);
});
test("space within text is input; space or Enter at end advances; completion is final", () => {
  const s=createSession(["a s","df"]);
  for(const [i,k] of [..."a s"].entries()) input(s,k,i*100);
  assert.equal(input(s," ",400),"next");
  input(s,"d",500); input(s,"f",600);
  assert.equal(input(s," ",700),"finished");
  assert.equal(input(s,"Backspace",800),"ignored");
  assert.equal(s.row,1); assert.equal(summary(s,999).lines,2);
});
test("pause excludes inactive time and avoids cross-line latency samples", () => {
  const s=createSession(["as","df"]); input(s,"a",0); pause(s,1000);
  input(s,"s",10000); input(s,"Enter",11000); input(s,"d",12000); input(s,"f",13000); input(s,"Enter",14000);
  assert.equal(metrics(s,15000).elapsedMs,5000);
  assert.equal(s.perKey.s.samples,0); assert.equal(s.perKey.d.samples,0);
  assert.equal(s.perKey.f.latencyMs,1000);
});
test("no incomplete save; generated drills use only selected keys and spaces", () => {
  assert.throws(()=>summary(createSession(["a"]),0));
  for(let stage=0;stage<6;stage++) {
    const lines=makeLines(stage,10,()=>0.5);
    assert.equal(lines.length,10); assert.ok(lines.every(l=>l.length===29 && !l.endsWith(" ")));
  }
  assert.match(makeLines(0,1)[0],/^[asdf ]+$/);
});
test("progression requires a lesson, 95% accuracy, and target speed", () => {
  assert.equal(qualifies({mode:"lesson",accuracy:95,wpm:25},25),true);
  assert.equal(qualifies({mode:"lesson",accuracy:94,wpm:40},25),false);
  assert.equal(qualifies({mode:"test",accuracy:100,wpm:40},25),false);
});
test("reports weight totals rather than averaging percentages or speeds", () => {
  const r=aggregate([{elapsedMs:60000,attempts:100,correct:90,perKey:{}},
    {elapsedMs:180000,attempts:300,correct:150,perKey:{}}]);
  assert.equal(r.wpm,12); assert.equal(r.accuracy,60);
});
test("storage roundtrip, corruption and denied storage are explicit", () => {
  const map=new Map(); const store={getItem:k=>map.get(k)??null,setItem:(k,v)=>map.set(k,v)};
  assert.deepEqual(load(store).data,defaults());
  const data={...defaults(),name:"Tester"}; assert.equal(save(store,data),""); assert.deepEqual(load(store).data,data);
  store.setItem(STORAGE_KEY,'{"version":999}'); assert.ok(load(store).warning); assert.equal(map.get(STORAGE_KEY),'{"version":999}');
  assert.ok(save({setItem(){throw Error();}},data));
  assert.ok(load({getItem(){throw Error();}}).warning);
});
test("zero-time results are finite and empty history is safe", () => {
  const s=createSession(["a"]); input(s,"a",0); input(s,"Enter",0);
  assert.equal(metrics(s,0).wpm,0); assert.equal(aggregate([]).wpm,0);
});
