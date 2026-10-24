import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn} from "node:child_process";
import {once} from "node:events";
import {createCurriculum} from "../dist/curriculum.js";
const base="http://127.0.0.1:8774",KEY="type-tutor-remake.faithful.v2";
const server=spawn("python3",["scripts/serve.py","--port","8774"],{stdio:"ignore"});
let browser;
try{
 for(let i=0;i<50;i++){if(server.exitCode!==null)throw Error("Audio server exited");try{if((await fetch(base)).ok)break;}catch{}await new Promise(r=>setTimeout(r,100));}
 browser=await chromium.launch({channel:"chrome",headless:true,args:["--autoplay-policy=document-user-activation-required"]});
 for(const enabled of [true,false]){
  const context=await browser.newContext(),page=await context.newPage(),errors=[];
  page.on("pageerror",error=>errors.push(String(error)));
  const fixture={version:2,activeId:"student-1",profiles:[{id:"student-1",name:"Student",wpm:20,weekly:1,drills:5,sound:enabled,curriculum:{...createCurriculum(),seed:0,introShown:true},practiceRecords:[]}]};
  await page.addInitScript(({KEY,fixture})=>{
   localStorage.setItem(KEY,JSON.stringify(fixture));
   window.__contexts=[];window.__tones=[];
   const Base=window.AudioContext,create=Base.prototype.createOscillator;
   Base.prototype.createOscillator=function(){
    const voice=create.call(this),info={frequencies:[],stops:[]},set=voice.frequency.setValueAtTime.bind(voice.frequency),stop=voice.stop.bind(voice);
    voice.frequency.setValueAtTime=(frequency,time)=>{info.frequencies.push(frequency);return set(frequency,time);};
    voice.stop=time=>{info.stops.push(time??null);return stop(time);};
    window.__tones.push(info);return voice;
   };
   window.AudioContext=new Proxy(Base,{construct(target,args){const result=Reflect.construct(target,args);window.__contexts.push(result);return result;}});
  },{KEY,fixture});
  await page.clock.install({time:new Date("2026-10-24T00:00:00Z")});
  await page.goto(base);await page.locator(".cell").last().waitFor();
  await page.clock.pauseAt(await page.evaluate(()=>Date.now())+1000);
  await page.keyboard.press("g");await page.keyboard.press("p");
  await page.getByRole("option",{name:"Practice Keys",exact:true}).click();
  await page.getByRole("option",{name:"One",exact:true}).click();
  await page.keyboard.press("Enter");
  const state=async()=>JSON.parse(await page.locator("#terminal").getAttribute("data-game-state"));
  let snapshot;
  await page.keyboard.press("~");
  if(enabled){
   const wrong=await page.evaluate(()=>window.__tones.at(-1).frequencies);
   assert.equal(wrong.length,1);assert.ok(wrong[0]>1046&&wrong[0]<1048);
  }
  // Let the first real target hit the ground before playing the remaining wave.
  for(let step=0;step<400;step++){
   snapshot=await state();if(snapshot.health[0]<80)break;
   await page.clock.runFor(120);
  }
  assert.ok((await state()).health[0]<80,"A real ground impact is exercised");
  if(enabled)assert.ok(await page.evaluate(()=>window.__tones.some(tone=>tone.frequencies.length===3&&tone.frequencies[0]<100)),"Ground impact has its low rising three-note cue");
  // Play a complete real first round; no production test hook or injected game state.
  for(let step=0;step<1800;step++){
   snapshot=await state();if(snapshot.phase!=="playing")break;
   for(const target of snapshot.targets.filter(target=>!target.missile))await page.keyboard.type(target.text);
   await page.clock.runFor(120);
  }
  snapshot=await state();assert.equal(snapshot.phase,"level-end");assert.equal(snapshot.round,2);
  if(enabled)assert.ok(await page.evaluate(()=>window.__tones.some(tone=>tone.frequencies.length===3&&tone.frequencies[0]>600)),"Successful hits have their distinct high falling cue");
  const summary=(await page.locator(".row").allTextContents()).join("\n");
  assert.match(summary,/Accuracy: \d+%(?!%)/);assert.ok(!summary.includes("%%"));

  await page.keyboard.press("Enter");
  let boomlet;
  for(let step=0;step<1500;step++){
   snapshot=await state();assert.equal(snapshot.phase,"playing");
   boomlet=snapshot.targets.find(target=>target.type===2);if(boomlet)break;
   for(const target of snapshot.targets.filter(target=>!target.missile))await page.keyboard.type(target.text);
   await page.clock.runFor(120);
  }
  assert.ok(boomlet,"Deterministic second round reaches a fast-falling Boomlet");
  if(enabled){
   await page.waitForFunction(()=>window.__contexts[0]?.state==="running");
   const tones=await page.evaluate(()=>window.__tones.filter(tone=>tone.frequencies.length===72));
   assert.equal(tones.length,1);assert.ok(tones[0].frequencies[0]>1900);
   assert.ok(tones[0].frequencies.at(-1)<40);
   await page.keyboard.type(boomlet.text);
   for(let i=0;i<30&&(await state()).targets.some(target=>target.type===2);i++)await page.clock.runFor(60);
   assert.ok(!(await state()).targets.some(target=>target.type===2));
   assert.equal(await page.evaluate(()=>window.__tones.find(tone=>tone.frequencies.length===72).stops.length),2,"Collision cancels the warning immediately");
   const rms=await page.evaluate(async()=>{
    const {GameAudio}=await import("./game-audio.js");
    const offline=new OfflineAudioContext(1,22050,22050),sound=new GameAudio(()=>offline);
    sound.start();const rendered=await offline.startRendering(),samples=rendered.getChannelData(0);
    return Math.sqrt(samples.reduce((sum,value)=>sum+value*value,0)/samples.length);
   });
   assert.ok(rms>.02&&rms<.1,"Real browser audio rendering is audible/nonzero at the intended gain");
   console.log("PASS Chrome audio on: user-gesture activation, real round-two Boomlet,72 descending notes, collision stop and rendered RMS="+rms.toFixed(4));
  }else{
   assert.equal(await page.evaluate(()=>window.__contexts.length),0,"Sound Off never opens or plays an audio context, including Boomlets");
   console.log("PASS Chrome audio off: same fast-falling target produces no audio context.");
  }
  // Finish round two and reach an actual horizontal Word Ship in round three.
  for(let step=0;step<1800;step++){
   snapshot=await state();if(snapshot.phase!=="playing")break;
   for(const target of snapshot.targets.filter(target=>!target.missile))await page.keyboard.type(target.text);
   await page.clock.runFor(120);
  }
  snapshot=await state();assert.equal(snapshot.phase,"level-end");assert.equal(snapshot.round,3);
  await page.keyboard.press("Enter");
  let ship;
  for(let step=0;step<1500;step++){
   snapshot=await state();assert.equal(snapshot.phase,"playing");
   ship=snapshot.targets.find(target=>target.type===3);if(ship)break;
   for(const target of snapshot.targets.filter(target=>!target.missile))await page.keyboard.type(target.text);
   await page.clock.runFor(120);
  }
  assert.ok(ship,"Deterministic third round reaches a horizontal Word Ship");
  if(enabled){
   const shipCount=await page.evaluate(()=>window.__tones.filter(tone=>tone.frequencies.length===85).length);
   assert.ok(shipCount>=1,"Word Ship schedules its own85-note melody");
   await page.keyboard.type(ship.text);
   for(let i=0;i<45&&(await state()).targets.some(target=>target.type===3);i++)await page.clock.runFor(60);
   assert.ok(!(await state()).targets.some(target=>target.type===3));
   assert.equal(await page.evaluate(()=>window.__tones.filter(tone=>tone.frequencies.length===85).at(-1).stops.length),2,"Destroyed Word Ship stops its melody");
   const rms=await page.evaluate(async()=>{
    const {GameAudio}=await import("./game-audio.js");
    const offline=new OfflineAudioContext(1,22050,22050),sound=new GameAudio(()=>offline);
    sound.start("ship");const rendered=await offline.startRendering(),samples=rendered.getChannelData(0);
    return Math.sqrt(samples.reduce((sum,value)=>sum+value*value,0)/samples.length);
   });
   assert.ok(rms>.01&&rms<.1);
   console.log("PASS Chrome Word Ship: real round-three spawn,85-note melody, collision stop, rendered RMS="+rms.toFixed(4)+"; summary has one percent sign.");
  }else{
   assert.equal(await page.evaluate(()=>window.__contexts.length),0);
   console.log("PASS Chrome Word Ship muted: no audio context; summary percent formatting correct.");
  }
  const shortRms=await page.evaluate(async()=>{
   const {GameAudio}=await import("./game-audio.js"),out={};
   for(const kind of ["wrong","hit","impact"]){
    const offline=new OfflineAudioContext(1,22050,22050),sound=new GameAudio(()=>offline);
    sound.start(kind);const buffer=await offline.startRendering(),samples=buffer.getChannelData(0);
    out[kind]=Math.sqrt(samples.reduce((sum,value)=>sum+value*value,0)/samples.length);
   }
   return out;
  });
  for(const value of Object.values(shortRms))assert.ok(value>.005&&value<.1);
  console.log("PASS all five gameplay effects: actual wrong/hit/impact plus Boomlet/Word Ship; short waveform RMS="+JSON.stringify(shortRms));
  assert.deepEqual(errors,[]);
  await context.close();
 }
}finally{
 if(browser)await browser.close();
 if(server.exitCode===null){const ended=once(server,"exit");server.kill();await ended;}
}
