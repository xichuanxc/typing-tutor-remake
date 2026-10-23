import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn} from "node:child_process";
import {once} from "node:events";
import {mkdir} from "node:fs/promises";
import {createCurriculum} from "../dist/curriculum.js";
const PORT=8772,base="http://127.0.0.1:"+PORT,KEY="type-tutor-remake.faithful.v2",OLD="type-tutor-remake.v1";
const server=spawn("python3",["scripts/serve.py","--port",String(PORT)],{stdio:"ignore"});
let browser;const errors=[];
const date="2026-10-23T00:00:00.000Z";
const curriculum=()=>({...createCurriculum(),seed:0,introShown:true});
const priorScores=()=>[Array.from({length:5},(_,i)=>({name:"Prior "+(i+1),score:1,keys:8,date})),[{name:"Full Prior",score:1,keys:64,date}]];
const teaching=c=>{const copy=structuredClone(c);delete copy.seed;return copy;};
try{
 let ready=false;
 for(let n=0;n<50;n++){
  if(server.exitCode!==null)throw Error("Invaders test server exited");
  try{if((await fetch(base)).ok){ready=true;break;}}catch{}
  await new Promise(r=>setTimeout(r,100));
 }
 assert.ok(ready,"Invaders server ready");
 browser=await chromium.launch({channel:"chrome",headless:true});
 await mkdir("docs/screenshots",{recursive:true});
 async function open(gameScores=priorScores()){
  const context=await browser.newContext({viewport:{width:1040,height:780}}),page=await context.newPage();
  page.on("pageerror",e=>errors.push(String(e)));
  const fixture={version:2,activeId:"student-1",profiles:[{id:"student-1",name:"Student",wpm:20,weekly:1,drills:5,sound:false,curriculum:curriculum(),practiceRecords:[]}],gameScores};
  await page.addInitScript(({KEY,OLD,fixture})=>{
   if(localStorage.getItem(KEY)===null)localStorage.setItem(KEY,JSON.stringify(fixture));
   if(localStorage.getItem(OLD)===null)localStorage.setItem(OLD,"preserved-invaders-prototype");
  },{KEY,OLD,fixture});
  await page.clock.install({time:new Date(date)});
  await page.goto(base);await page.locator(".cell").last().waitFor();
  await page.clock.pauseAt(await page.evaluate(()=>Date.now())+1000);
  const terminal=page.locator("#terminal"),mode=()=>terminal.getAttribute("data-mode"),attr=k=>terminal.getAttribute(k);
  const snapshot=async()=>JSON.parse(await attr("data-game-state"));
  const screen=async()=>(await page.locator(".row").allTextContents()).join("\n");
  const choose=name=>page.getByRole("option",{name,exact:true}).click();
  const saved=()=>page.evaluate(k=>JSON.parse(localStorage.getItem(k)),KEY);
  async function exported(){
   const pending=page.waitForEvent("download");await page.getByRole("button",{name:"Export browser data"}).click();
   const stream=await(await pending).createReadStream(),chunks=[];for await(const c of stream)chunks.push(c);
   await terminal.focus();return JSON.parse(Buffer.concat(chunks).toString());
  }
  async function main(){
   assert.equal(await mode(),"menu");
   if(await attr("data-menu")!=="0")await page.keyboard.press("Escape");
   assert.equal(await attr("data-menu"),"0");
  }
  async function play(kind="Practice Keys",players="One"){
   await main();await page.keyboard.press("g");await page.keyboard.press("p");assert.equal(await mode(),"game-setup");
   await choose(kind);assert.equal(await mode(),"game-players");await choose(players);
   assert.equal(await mode(),players==="Two"?"game-name":"game-ready");
  }
  async function scores(){
   await main();await page.keyboard.press("g");await page.keyboard.press("s");assert.equal(await mode(),"game-scores");
  }
  async function advance(ms=55){await page.clock.runFor(ms);return snapshot();}
  const live=s=>(s.targets??[]).filter(t=>t&&t.type>0&&t.text&&!(t.missile??0)&&!(t.typed??0));
  async function target(predicate=()=>true){
   for(let n=0;n<300;n++){
    const s=await snapshot(),t=live(s).find(predicate);if(t)return t;
    assert.equal(await mode(),"game-playing");await advance();
   }
   throw Error("No matching active invader in deterministic fixture");
  }
  async function scoreAfterShot(previous){
   for(let n=0;n<80;n++){
    const s=await advance();if(s.scores[s.player]>previous)return s;
    assert.equal(await mode(),"game-playing");
   }
   throw Error("A correct shot did not reach its target");
  }
  async function finish(){
   await page.keyboard.press("Escape");assert.equal(await mode(),"game-over");
   await page.screenshot({path:"docs/screenshots/invaders-game-over.png",fullPage:true});
   await page.keyboard.press("Enter");assert.equal(await mode(),"game-end");
   await choose("Return to Main Menu");assert.equal(await mode(),"menu");
  }
  return {page,context,fixture,terminal,mode,attr,snapshot,screen,choose,saved,exported,main,play,scores,advance,target,scoreAfterShot,finish};
 }
 // Read-only score viewing and setup cancellation leave saved/working learning intact.
 {
  const h=await open(),{page,context}=h;
  await h.scores();assert.match(await h.screen(),/Practice Keys/);assert.match(await h.screen(),/Full Keyboard/);
  assert.match(await h.screen(),/Prior 1/);assert.match(await h.screen(),/Full Prior/);
  assert.equal(await h.attr("data-dirty"),"false");assert.deepEqual(await h.saved(),h.fixture);
  await page.screenshot({path:"docs/screenshots/invaders-scores.png",fullPage:true});
  await page.setViewportSize({width:390,height:844});await page.clock.runFor(32);
  for(let n=0;n<40&&!(await page.evaluate(()=>document.documentElement.scrollWidth<=innerWidth));n++){
   await new Promise(r=>setTimeout(r,50));await page.clock.runFor(16);
  }
  assert.ok(await page.evaluate(()=>document.documentElement.scrollWidth<=innerWidth),"Scaled game score table settles after the browser resize event");
  await page.screenshot({path:"docs/screenshots/invaders-mobile.png",fullPage:true});
  await page.setViewportSize({width:1040,height:780});await page.keyboard.press("Escape");
  await h.main();await page.keyboard.press("g");await page.keyboard.press("p");
  assert.equal(await h.mode(),"game-setup");
  await page.screenshot({path:"docs/screenshots/invaders-mode.png",fullPage:true});
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"menu");
  assert.equal(await h.attr("data-dirty"),"false");assert.deepEqual(await h.saved(),h.fixture);
  await context.close();
 }
 // Correct words launch missiles; a miss resets a word and costs ten points.
 {
  const h=await open(),{page,context}=h;
  await h.play();assert.match(await h.screen(),/Round 1/);
  await page.screenshot({path:"docs/screenshots/invaders-ready.png",fullPage:true});
  await page.keyboard.press("Enter");assert.equal(await h.mode(),"game-playing");
  const word=await h.target(t=>t.text.length>1);
  await page.keyboard.type(word.text[0]);
  let state=await h.snapshot();assert.ok(state.targets.some(t=>t&&t.text===word.text&&t.typed===1),"Word locks after the first matching character");
  await page.keyboard.press("~");state=await h.snapshot();
  assert.ok(state.targets.some(t=>t&&t.text===word.text&&t.typed===0),"Incorrect next character resets the word");
  const previous=state.scores[state.player];
  await page.keyboard.type(word.text);state=await h.scoreAfterShot(previous);
  assert.ok(state.scores[state.player]>0);
  const beforeMiss=state.scores[state.player];await page.keyboard.press("~");state=await h.snapshot();
  assert.equal(state.scores[state.player],Math.max(0,beforeMiss-10));
  await page.screenshot({path:"docs/screenshots/invaders-playing.png",fullPage:true});
  await h.finish();
  let out=await h.exported(),record=out.workingSettings.gameRecords.at(-1);
  assert.equal(record.kind,"letter-invaders-f5c");assert.equal(record.mode,"practice");
  assert.deepEqual(record.players,["Student"]);assert.ok(record.scores[0]>0);
  assert.deepEqual(out.workingSettings.practiceRecords,[]);
  assert.deepEqual(teaching(out.workingSettings.curriculum),teaching(h.fixture.profiles[0].curriculum));
  assert.notEqual(out.workingSettings.curriculum.seed,0);
  assert.equal(out.workingGameScores[0][0].name,"Student");assert.equal(out.workingGameScores[0].length,5);
  assert.deepEqual(out.workingGameScores[0].slice(1).map(s=>s.name),["Prior 1","Prior 2","Prior 3","Prior 4"],"Equal old ranks retain their original order");
  assert.deepEqual(out.workingGameScores[1],h.fixture.gameScores[1]);
  assert.deepEqual(await h.saved(),h.fixture,"Game does not autosave");
  await page.keyboard.press("q");await h.choose("Yes, save session to history");assert.equal(await h.mode(),"exited");
  const committed=await h.saved();assert.equal(committed.gameScores[0][0].name,"Student");
  assert.equal(committed.profiles[0].gameRecords.length,1);
  await page.reload();await page.clock.pauseAt(await page.evaluate(()=>Date.now())+1000);
  await h.scores();assert.match(await h.screen(),/Student/);assert.ok(!(await h.screen()).includes("Prior 5"));await page.keyboard.press("Escape");
  const beforeFull=await h.exported();await h.play("Full Keyboard");
  await page.keyboard.press("Enter");assert.equal(await h.mode(),"game-playing");
  const invader=await h.target();state=await h.snapshot();await page.keyboard.type(invader.text);
  await h.scoreAfterShot(state.scores[state.player]);await h.finish();
  out=await h.exported();record=out.workingSettings.gameRecords.at(-1);
  assert.equal(record.mode,"full");assert.equal(record.keys,64);assert.equal(out.workingGameScores[1][0].name,"Student");
  assert.deepEqual(teaching(out.workingSettings.curriculum),teaching(beforeFull.workingSettings.curriculum));
  await page.keyboard.press("q");await h.choose("No, do not save to history");assert.deepEqual(await h.saved(),committed);
  assert.equal(await page.evaluate(k=>localStorage.getItem(k),OLD),"preserved-invaders-prototype");
  await context.close();
 }
 // The second player is local and alternates at round boundaries; exiting ready submits both players.
 {
  const h=await open([[],[]]),{page,context}=h;
  await h.play("Practice Keys","Two");
  const input=page.locator("#game-second-name");await input.fill("");await page.keyboard.press("Enter");
  assert.equal(await h.mode(),"game-name","Empty second-player name is not accepted");
  await input.fill("Second Player");await page.keyboard.press("Enter");assert.equal(await h.mode(),"game-ready");
  await page.screenshot({path:"docs/screenshots/invaders-two-player.png",fullPage:true});
  await page.keyboard.press("Enter");assert.equal(await h.mode(),"game-playing");assert.equal(Number(await h.attr("data-game-player")),0);
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"game-round");assert.equal(Number(await h.attr("data-game-player")),1);
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"menu");
  const out=await h.exported(),record=out.workingSettings.gameRecords.at(-1);
  assert.deepEqual(record.players,["Student","Second Player"]);
  assert.deepEqual(record.submissions.map(s=>s.player),[0,0,1],"Native death and ready-cancel submission order is retained");
  assert.deepEqual(out.workingGameScores,[[],[]]);assert.deepEqual(out.workingSettings.practiceRecords,[]);
  await page.keyboard.press("q");await h.choose("No, do not save to history");assert.deepEqual(await h.saved(),h.fixture);
  await context.close();
 }
 assert.deepEqual(errors,[],"No Chrome page errors");
 console.log("PASS (Chrome): original game setup/scores, ready controls, word targeting and reset, missile hits, miss penalties, two-player turns, separate global score tables, save/reload/discard, unchanged teaching counters, narrow layout and prototype preservation.");
}finally{
 if(browser)await browser.close();
 if(server.exitCode===null){const exited=once(server,"exit");server.kill();await exited;}
}
