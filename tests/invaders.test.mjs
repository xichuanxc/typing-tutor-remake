import test from "node:test";
import assert from "node:assert/strict";
import {createCurriculum} from "../dist/curriculum.js";
import D from "../dist/curriculum-data.js";
import G from "../dist/invaders-data.js";
import {InvadersGame,invaderIndex,invadersTick,BIOS_TICK_MS,validInvadersRecord} from "../dist/invaders.js";
function game(options){return new InvadersGame(createCurriculum(),options);}
function active(text="a",type=1,row=2,col=10){
 const g=game();g.input("Enter",0);g.payloads=Array.from({length:40},()=>({text:"",typed:0}));g.payloads[0]={text,typed:0};
 g._slots.forEach(s=>s.type=0);const slot=g._slots[invaderIndex(text[0])];
 Object.assign(slot,{type,row,col,phase:0,payloadIndex:0,missile:0});
 g.active=1;g.nextPayload=0;g.cooldown=10000;return {g,slot};
}
test("all90 original game characters have distinct case-sensitive slots",()=>{
 assert.equal(G.gameOrder.length,90);
 assert.deepEqual([...G.gameOrder].map(invaderIndex),Array.from({length:90},(_,i)=>i));
 assert.equal(invaderIndex("a"),0);assert.equal(invaderIndex("A"),1);assert.equal(invaderIndex("_"),89);
 for(const key of ["",null,{},0,"ab","\\","|","`"])assert.equal(invaderIndex(key),-1);
 assert.equal(invadersTick(BIOS_TICK_MS*100+.001),100);
});
test("temporary game ranges and weights preserve teaching state while publishing only RNG seed",()=>{
 const c=createCurriculum(),before=structuredClone(c),g=new InvadersGame(c);
 assert.equal(g.keys,8);assert.equal(g.generation.introduced,7);assert.equal(g.generation.alphabetic,4);assert.equal(g.generation.shiftLearned,1);
 assert.deepEqual(g.payloads.slice(0,10).map(p=>p.text),["J","a","D","Dj","F","L","d","k","Add","Jaffas;"]);
 assert.equal(c.seed,61996);assert.ok(g.payloads.every(p=>p.text.length>=1&&p.text.length<=15));
 const after={...c};delete after.seed;assert.deepEqual(after,before);
 const full=new InvadersGame(c,{mode:"full"});assert.equal(full.keys,64);assert.equal(full.generation.introduced,63);
 assert.ok(full.generation.weights.slice(0,64).every(n=>n===100));assert.deepEqual(c.weights,before.weights);
 const p=createCurriculum();Object.assign(p,{introduced:8,alphabetic:4,newKey:101});const pending=new InvadersGame(p);
 assert.equal(pending.generation.introduced,7);assert.equal(pending.generation.alphabetic,3);assert.equal(p.newKey,101);
});
test("the native clock advances once per changed BIOS tick without catch-up or a pause key",()=>{
 const g=game();assert.equal(g.step(100).ignored,true);g.input("Enter",100);
 assert.equal(g.step(100).ignored,true);g.step(1000);assert.equal(g.ticks,1);
 const first=g.targets[0];assert.equal(first.text,"J");assert.equal(first.row,2);assert.equal(first.col,51);
 g.step(1000);assert.equal(g.ticks,1);g.step(0);assert.equal(g.ticks,2);
 assert.equal(g.input(" ",0).ignored,true);assert.equal(g.phase,"playing");
 assert.throws(()=>g.step(-1));assert.throws(()=>g.step(.5));
});
test("a correct single character launches a missile; points wait for collision",()=>{
 const {g,slot}=active();assert.equal(g.input("a",0).hit,true);assert.equal(g.score,0);assert.equal(slot.missile,21);
 for(let tick=1;tick<=30&&slot.type;tick++)g.step(tick);
 assert.equal(slot.type,0);assert.equal(g.score,10);assert.equal(g.hits,1);assert.equal(g.misses,0);
 assert.equal(g.ground[0].filter(Boolean).length,80);
});
test("wrong keys reset the word lock, retain correct keystrokes and clamp miss penalties",()=>{
 const {g}=active("ab");g.scores[0]=25;
 g.input("a",0);assert.equal(g.lock.nextIndex,1);assert.equal(g.payloads[0].typed,1);
 g.input("x",0);assert.equal(g.score,15);assert.equal(g.lock,null);assert.equal(g.payloads[0].typed,0);
 assert.equal(g.hits,1);assert.equal(g.misses,1);
 for(const key of ["Backspace","Tab","\\","|","`","~"])assert.equal(g.input(key,0).error,true);
 assert.equal(g.score,0);assert.equal(g.misses,7);
 const before=g.misses;g.input("Enter",0);g.input(" ",0);assert.equal(g.misses,before);
 g.input("a",0);g.input(" ",0);assert.equal(g.lock,null);assert.equal(g.misses,before+1);
});
test("destruction points use native triangular word points and special multipliers",()=>{
 for(const [text,type,points] of [["a",1,10],["a",2,50],["abc",1,60],["abc",2,120],["abc",3,120]]){
  const {g,slot}=active(text,type);g.resolve(slot,true);assert.equal(g.score,points);assert.equal(g.active,0);
  assert.equal(g.payloads[0].text,"");assert.equal(slot.missile,0);
 }
});
test("ground impacts remove only intact columns and repeated overlap still costs ten points",()=>{
 const {g,slot}=active("abc",1,22,1);g.scores[0]=100;g.resolve(slot,false);
 assert.equal(g.health[0],77);assert.equal(g.score,90);
 Object.assign(slot,{type:1,row:22,col:2,missile:0});g.payloads[0]={text:"abc",typed:0};g.active=1;g.resolve(slot,false);
 assert.equal(g.health[0],76);assert.equal(g.score,80);assert.equal(g.ground[0][0],true);assert.equal(g.ground[0][4],false);
});
test("Word Ships move on odd frames, aim their projectile column and leave without ground damage",()=>{
 const {g,slot}=active("abc",3,5,50);g.input("a",0);g.input("b",0);g.input("c",0);
 assert.equal(g.special,42);assert.equal(g.targets[0].missileCol,42);assert.equal(slot.missile,21);g.step(1);assert.equal(slot.col,50);g.step(2);assert.equal(slot.col,49);
 const escape=active("abc",3,5,-3);escape.g.step(1);escape.g.step(2);
 assert.equal(escape.slot.type,0);assert.equal(escape.g.active,0);assert.equal(escape.g.score,0);assert.equal(escape.g.health[0],80);
});
test("round bonuses preserve signed16 multiplication and native round interval floors",()=>{
 const {g}=active();g.scores[0]=10000;g.hits=4000;g.misses=0;g.finishRound();
 assert.equal(g.lastSummary.accuracy,100);assert.equal(g.lastSummary.bonus,-25536);assert.equal(g.scores[0],(-15536)>>>0);
 assert.equal(g.round,2);assert.equal(g.phase,"level-end");g.input("Enter",0);assert.equal(g.phase,"playing");
 const plain=game();for(let i=0;i<25;i++)plain.finishRound();
 assert.equal(plain.spawnInterval,2);assert.equal(plain.fallInterval,6);
});
test("two-player turns preserve submission order including duplicate ready-Escape submissions",()=>{
 const g=game({players:["First","Second"]});g.scores=[100,50];g.input("Enter",0);g.input("Escape",0);
 assert.equal(g.player,1);assert.equal(g.round,1);assert.equal(g.phase,"level-end");
 assert.deepEqual(g.submissions.map(s=>s.player),[0]);g.input("Escape",0);
 assert.equal(g.phase,"game-over");assert.equal(g.aborted,true);
 assert.deepEqual(g.submissions.map(s=>s.player),[0,0,1]);assert.ok(validInvadersRecord(g.record()));
 const second=game({players:["First","Second"]});second.input("Enter",0);second.input("Escape",0);second.input("Enter",0);second.input("Escape",0);
 assert.deepEqual(second.submissions.map(s=>s.player),[0,1]);assert.equal(second.completed,true);
});
test("game records validate final metadata and reject invalid player names and score tampering",()=>{
 for(const players of [[],[""],[" Leading"],["bad\nname"],["a","b","c"]])assert.throws(()=>game({players}));
 const g=game({mode:"full"});g.input("Escape",0);const r=g.record();assert.ok(validInvadersRecord(r));
 for(const change of [r=>r.keys=63,r=>r.players[0]=" bad",r=>r.scores[0]=-1,r=>r.submissions[0].player=2,r=>r.submissions[0].score=1]){
  const bad=structuredClone(r);change(bad);assert.equal(validInvadersRecord(bad),false);
 }
 assert.equal(validInvadersRecord(null),false);assert.equal(g.input("a",1).ignored,true);
});
