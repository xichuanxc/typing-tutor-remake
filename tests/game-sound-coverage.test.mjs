import test from "node:test";
import assert from "node:assert/strict";
import {readFileSync} from "node:fs";
import {GameAudio,GAME_SOUND_TYPES,soundNotes} from "../dist/game-audio.js";
import {InvadersGame,invaderIndex,BIOS_TICK_MS} from "../dist/invaders.js";
import {createCurriculum} from "../dist/curriculum.js";
function harness(){
 const voices=[];let accesses=0;
 const context={currentTime:0,destination:{},createGain(){return {gain:{setValueAtTime(){},linearRampToValueAtTime(){},cancelScheduledValues(){}},connect(){},disconnect(){}};},
 createOscillator(){const voice={frequency:{setValueAtTime(frequency){voice.pitches.push(frequency);}},pitches:[],stops:[],connect(){},disconnect(){},start(){},stop(time){this.stops.push(time);}};voices.push(voice);return voice;}};
 const audio=new GameAudio(()=>{accesses++;return context;});
 return {audio,voices,get accesses(){return accesses;}};
}
function scene(text="a"){
 const game=new InvadersGame(createCurriculum());game.input("Enter",0);
 game._slots.forEach(slot=>slot.type=0);game.payloads=Array.from({length:40},()=>({text:"",typed:0}));
 game.payloads[0]={text,typed:0};const slot=game._slots[invaderIndex(text[0])];
 Object.assign(slot,{type:1,row:2,col:10,phase:0,payloadIndex:0,missile:0});
 game.active=1;game.nextPayload=0;game.cooldown=10000;
 return {game,slot};
}
function wire(game,audio,enabled=true){
 const events=game.drainEvents();
 audio.update(events,{enabled,playing:game.phase==="playing",specialType:game.targets.find(target=>target.type>1)?.type??0});
 return events.map(event=>event.type);
}
test("every emitted gameplay sound has an explicit recovered effect",()=>{
 const engine=readFileSync("dist/invaders.js","utf8");
 const emitted=[...new Set([...engine.matchAll(/this\.emit\("([^"]+)"\)/g)].map(match=>match[1]))].sort();
 assert.deepEqual(emitted,[...GAME_SOUND_TYPES].sort());
 assert.ok(GAME_SOUND_TYPES.every(kind=>soundNotes(kind).length>0));
 assert.deepEqual(soundNotes("unknown"),[]);
});
test("wrong key, hit and ground impact have distinct recovered pitches and durations",()=>{
 const wrong=soundNotes("wrong"),hit=soundNotes("hit"),impact=soundNotes("impact");
 assert.equal(wrong.length,1);assert.equal(wrong[0].frequency,1193180/1140);
 assert.equal(wrong[0].duration,BIOS_TICK_MS/1000);
 assert.equal(hit.length,3);assert.ok(hit.every(note=>note.frequency>500&&note.frequency<700));
 assert.ok(hit.every((note,i)=>note.duration===BIOS_TICK_MS/1000&&(!i||note.frequency<hit[i-1].frequency)));
 assert.equal(impact.length,3);assert.ok(impact.every(note=>note.frequency>60&&note.frequency<90));
 assert.ok(impact.every((note,i)=>note.duration===BIOS_TICK_MS/1000&&(!i||note.frequency>impact[i-1].frequency)));
});
test("real engine wrong/hit/impact events route to the matching voice; ordinary shots stay silent",()=>{
 for(const kind of ["wrong","hit","impact"]){
  const {game,slot}=scene(),h=harness();
  if(kind==="wrong")game.input("~",1);
  else if(kind==="hit"){game.input("a",1);assert.deepEqual(wire(game,h.audio),[]);assert.equal(h.accesses,0);game.resolve(slot,true);}
  else game.resolve(slot,false);
  assert.deepEqual(wire(game,h.audio),[kind]);assert.equal(h.audio.kind,kind);
  assert.equal(h.voices[0].pitches.length,kind==="wrong"?1:3);
  wire(game,h.audio);assert.equal(h.voices[0].stops.length,1,"Empty physics frames must not cut short a cue");
 }
});
test("special spawns, destruction and offscreen escape cover both warnings without test-only app hooks",()=>{
 for(const [kind,type,text,round] of [["boomlet",2,"a",2],["ship",3,"abc",3]]){
  const {game,slot}=scene(text),h=harness();slot.type=0;game.active=0;game.cooldown=0;game.round=round;
  game.random.next=()=>0;game.step(1);
  assert.equal(game.targets[0].type,type);assert.deepEqual(wire(game,h.audio),[kind]);
  assert.equal(h.voices[0].pitches.length,type===2?72:85);
  game.resolve(slot,true);assert.deepEqual(wire(game,h.audio),["hit"]);
  assert.equal(h.voices[0].stops.length,2);assert.equal(h.audio.kind,"hit");
 }
 const {game,slot}=scene("abc"),h=harness();slot.type=3;game.special=1;
 h.audio.update([{type:"ship"}],{specialType:3});
 slot.col=-4;game.frame=1;game.step(1);assert.deepEqual(wire(game,h.audio),[]);
 assert.equal(h.audio.playing,false);assert.equal(h.voices[0].stops.length,2);assert.equal(game.health[0],80);
});
test("short effects wait for a free speaker and cannot interrupt special warnings",()=>{
 const h=harness();h.audio.update([{type:"hit"},{type:"wrong"},{type:"impact"}]);
 assert.equal(h.voices.length,1);assert.equal(h.audio.kind,"hit");
 h.voices[0].onended();h.audio.update([{type:"wrong"}]);assert.equal(h.audio.kind,"wrong");
 h.audio.update([{type:"ship"}],{specialType:3});assert.equal(h.audio.kind,"ship");
 const count=h.voices.length;h.audio.update([{type:"wrong"},{type:"hit"},{type:"impact"}],{specialType:3});
 assert.equal(h.voices.length,count);assert.equal(h.audio.kind,"ship");
 h.audio.update([],{specialType:0});assert.equal(h.audio.playing,false);
});
test("mute and leaving play silence every effect, including uncommon outcomes",()=>{
 for(const kind of GAME_SOUND_TYPES){
  const h=harness(),specialType=kind==="boomlet"?2:kind==="ship"?3:0;
  h.audio.update([{type:kind}],{enabled:false,specialType});assert.equal(h.accesses,0);
  h.audio.update([{type:kind}],{specialType});assert.equal(h.audio.playing,true);
  h.audio.update([],{playing:false,specialType});assert.equal(h.audio.playing,false);
  assert.equal(h.voices[0].stops.length,2);
 }
});
