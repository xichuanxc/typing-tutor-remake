import test from "node:test";
import assert from "node:assert/strict";
import {boomletNotes,wordShipNotes,GameAudio} from "../dist/game-audio.js";
import {BIOS_TICK_MS} from "../dist/invaders.js";
test("Boomlet warning retains native pitch vectors, six octaves and quantized note duration",()=>{
 const notes=boomletNotes();
 assert.equal(notes.length,72);
 assert.equal(notes[0].frequency,1193180/603);
 assert.equal(notes[11].frequency,1193180/1140);
 assert.equal(notes[12].frequency,1193180/1207);
 assert.equal(notes.at(-1).frequency,1193180/36488);
 assert.ok(notes.every((note,i)=>note.duration===BIOS_TICK_MS*2/1000&&(!i||note.frequency<notes[i-1].frequency)));
 assert.ok(notes.reduce((sum,note)=>sum+note.duration,0)>7.9);
});
test("warning voice stops immediately, cleans up old nodes and does not cancel a replacement",()=>{
 const voices=[],gains=[],context={currentTime:3,destination:{}};
 context.createOscillator=()=>{const voice={frequency:{setValueAtTime(frequency){voice.frequencies.push(frequency);}},frequencies:[],connect(){},disconnect(){this.disconnected=true;},start(){},stop(time){this.stops.push(time);},stops:[]};voices.push(voice);return voice;};
 context.createGain=()=>{const node={gain:{setValueAtTime(){},linearRampToValueAtTime(){},cancelScheduledValues(){node.cancelled=true;}},connect(){},disconnect(){this.disconnected=true;}};gains.push(node);return node;};
 let unlocks=0;const sound=new GameAudio(()=>{unlocks++;return context;});
 sound.unlock();assert.equal(unlocks,1);sound.start();assert.equal(sound.playing,true);
 assert.equal(voices[0].stops.length,1);
 sound.start("ship");assert.equal(voices[1].frequencies.length,85);assert.equal(voices[0].stops.length,2);assert.equal(gains[0].cancelled,true);
 voices[0].onended();assert.equal(voices[0].disconnected,true);assert.equal(sound.playing,true);
 sound.stop();assert.equal(sound.playing,false);assert.equal(voices[1].stops.length,2);
 sound.stop();assert.equal(voices[1].stops.length,2);
 voices[1].onended();assert.equal(gains[1].disconnected,true);
 const unsupported=new GameAudio(()=>{throw Error("No audio");});
 assert.doesNotThrow(()=>{unsupported.unlock();unsupported.start();unsupported.stop();});
});

test("Word Ship melody expands native phrase order and preserves quantized rests",()=>{
 const notes=wordShipNotes(),tones=notes.filter(note=>note.frequency),rests=notes.filter(note=>!note.frequency);
 assert.equal(tones.length,85);
 assert.ok(tones[0].frequency>246&&tones[0].frequency<248);
 assert.equal(tones[0].frequency,tones[7].frequency);
 assert.ok(tones[8].frequency>329&&tones[8].frequency<331);
 assert.ok(tones[9].frequency>369&&tones[9].frequency<372);
 assert.ok(tones.at(-1).frequency>1328&&tones.at(-1).frequency<1331);
 assert.equal(tones[0].duration,BIOS_TICK_MS/1000);
 assert.equal(tones[2].duration,2*BIOS_TICK_MS/1000);
 assert.equal(rests.length,35);assert.ok(rests.every(note=>note.duration===BIOS_TICK_MS/1000));
 assert.ok(Math.abs(notes.reduce((sum,note)=>sum+note.duration,0)-163*BIOS_TICK_MS/1000)<1e-10);
});
