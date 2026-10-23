import test from "node:test";
import assert from "node:assert/strict";
import {insertGameScore,validGameScores} from "../dist/game-scores.js";
const date="2026-10-23T00:00:00.000Z",entry=(name,score,keys=8)=>({name,score,keys,date});
test("native high scores keep two global five-entry tables, stable ties and no zero-score placeholders",()=>{
 let tables=[[],[]];const original=structuredClone(tables);
 assert.equal(insertGameScore(tables,0,entry("Zero",0)).index,-1);assert.deepEqual(tables,original);
 for(const [name,score] of [["A",30],["B",10],["C",30],["D",50],["E",5],["F",20]])tables=insertGameScore(tables,0,entry(name,score)).tables;
 assert.deepEqual(tables[0].map(e=>e.name),["D","A","C","F","B"]);assert.equal(tables[1].length,0);
 tables=insertGameScore(tables,1,entry("Full",99,64)).tables;assert.equal(tables[1][0].name,"Full");
 assert.equal(insertGameScore(tables,0,entry("Negative",0xffffffff)).index,-1);assert.ok(validGameScores(tables));
});
test("score tables reject corrupt names, dates, ranges and ordering without accepting historical data",()=>{
 const good=[[entry("Student",20)],[]];assert.ok(validGameScores(good));
 for(const mutate of [t=>t[0][0].score=0,t=>t[0][0].score=0xffffffff,t=>t[0][0].name=" leading",t=>t[0][0].keys=65,t=>t[0][0].date="bad",t=>t[0].push(entry("Higher",30)),t=>t[1].push(entry("Full",20,8))]){
  const bad=structuredClone(good);mutate(bad);assert.equal(validGameScores(bad),false);
 }
 assert.equal(validGameScores(null),false);assert.throws(()=>insertGameScore(good,2,entry("X",1)));
});
