import test from "node:test";
import assert from "node:assert/strict";
import {StudentSession,PROFILE_KEY} from "../dist/faithful-session.js";
import {InvadersGame} from "../dist/invaders.js";
const memory=()=>{const data=new Map();return {getItem:k=>data.get(k)??null,setItem:(k,v)=>data.set(k,v)};};
function game(s,{mode="practice",players=["Student"],score=100}={}){
 const g=new InvadersGame(s.beginAdaptivePractice(),{mode,players});g.scores[0]=score;g.input("Escape",0);return g.record();
}
test("global game tables and audit records save together while typing statistics remain separate",()=>{
 const storage=memory(),s=new StudentSession(storage),r=game(s);s.recordGame(r);
 assert.equal(storage.getItem(PROFILE_KEY),null);assert.equal(s.workingScores[0][0].score,100);assert.deepEqual(s.savedScores,[[],[]]);
 assert.equal(s.working.practiceRecords,undefined);assert.ok(s.working.curriculum.current.every(c=>c.time===0));
 assert.equal(s.commit(),"");const raw=storage.getItem(PROFILE_KEY),restored=new StudentSession(storage);
 assert.equal(restored.readable,true);assert.deepEqual(restored.working.gameRecords,[r]);assert.deepEqual(restored.workingScores,s.workingScores);
 assert.equal(s.commit(),"");assert.equal(storage.getItem(PROFILE_KEY),raw);
});
test("game score failure, discard and stale-tab conflict retain complete saved/working boundaries",()=>{
 const storage=memory(),s=new StudentSession(storage);s.recordGame(game(s));assert.equal(s.commit(),"");
 const before=storage.getItem(PROFILE_KEY),saved=structuredClone(s.savedScores);
 s.recordGame(game(s,{mode:"full",score:200}));const working=structuredClone(s.workingScores),write=storage.setItem;
 storage.setItem=()=>{throw Error("full");};assert.ok(s.commit());assert.equal(s.dirty,true);assert.deepEqual(s.workingScores,working);assert.deepEqual(s.savedScores,saved);
 storage.setItem=write;s.discard();assert.deepEqual(s.workingScores,saved);assert.equal(storage.getItem(PROFILE_KEY),before);
 const other=new StudentSession(storage);other.change("wpm",30);assert.equal(other.commit(),"");
 s.recordGame(game(s,{score:300}));assert.match(s.commit(),/another tab/);assert.equal(s.workingScores[0][0].score,300);
});
test("native duplicate submissions retain order and current names without importing prior scores",()=>{
 const s=new StudentSession(memory()),g=new InvadersGame(s.beginAdaptivePractice(),{players:["First","Second"]});
 g.scores=[100,50];g.input("Enter",0);g.input("Escape",0);g.input("Escape",0);s.recordGame(g.record());
 assert.deepEqual(s.workingScores[0].map(e=>e.name),["First","First","Second"]);assert.deepEqual(s.working.gameRecords[0].submissions.map(e=>e.player),[0,0,1]);
 assert.equal(s.commit(),"");const raw=JSON.parse(s.storage.getItem(PROFILE_KEY));raw.gameScores[0][0].score=-1;
 const bad=new StudentSession({getItem:()=>JSON.stringify(raw),setItem(){throw Error();}});
 assert.equal(bad.readable,false);assert.ok(bad.commit());
});
test("viewing empty tables stays clean and ordinary saves preserve older database shape",()=>{
 const storage=memory(),s=new StudentSession(storage);assert.deepEqual(s.workingScores,[[],[]]);assert.equal(s.dirty,false);
 s.change("wpm",30);assert.equal(s.commit(),"");assert.equal(JSON.parse(storage.getItem(PROFILE_KEY)).gameScores,undefined);
 const g=new InvadersGame(s.beginAdaptivePractice());assert.throws(()=>s.recordGame(g.record()),/Invalid game record/);
});
