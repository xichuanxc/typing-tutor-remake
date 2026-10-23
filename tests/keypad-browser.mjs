import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn} from "node:child_process";
import {once} from "node:events";
import {mkdir} from "node:fs/promises";
import {createCurriculum} from "../dist/curriculum.js";
const PORT=8770,base="http://127.0.0.1:"+PORT,KEY="type-tutor-remake.faithful.v2",OLD="type-tutor-remake.v1";
const server=spawn("python3",["scripts/serve.py","--port",String(PORT)],{stdio:"ignore"});
const errors=[];let browser;
const total=samples=>samples.reduce((n,s)=>n+s.correct+s.errors,0);
try{
 let ready=false;
 for(let i=0;i<50;i++){
  if(server.exitCode!==null)throw Error("Keypad browser server exited");
  try{if((await fetch(base)).ok){ready=true;break;}}catch{}
  await new Promise(r=>setTimeout(r,100));
 }
 assert.ok(ready,"Keypad browser server ready");
 browser=await chromium.launch({channel:"chrome",headless:true});
 await mkdir("docs/screenshots",{recursive:true});
 async function open(curriculum){
  const context=await browser.newContext({viewport:{width:1040,height:780}}),page=await context.newPage();
  page.on("pageerror",e=>errors.push(String(e)));
  const fixture={version:2,activeId:"student-1",profiles:[{
   id:"student-1",name:"Student",wpm:20,weekly:1,drills:5,sound:false,curriculum,practiceRecords:[]
  }]};
  await page.addInitScript(({KEY,OLD,fixture})=>{
   if(localStorage.getItem(KEY)===null)localStorage.setItem(KEY,JSON.stringify(fixture));
   if(localStorage.getItem(OLD)===null)localStorage.setItem(OLD,"preserved-keypad-prototype");
  },{KEY,OLD,fixture});
  await page.goto(base);await page.locator(".cell").last().waitFor();
  const mode=()=>page.locator("#terminal").getAttribute("data-mode");
  const attr=name=>page.locator("#terminal").getAttribute(name);
  const row=n=>page.locator('.row[data-row="'+n+'"]').textContent();
  const screen=async()=>(await page.locator(".row").allTextContents()).join("\n");
  const saved=()=>page.evaluate(k=>JSON.parse(localStorage.getItem(k)),KEY);
  const choose=name=>page.getByRole("option",{name,exact:true}).click();
  async function exported(){
   const pending=page.waitForEvent("download");
   await page.getByRole("button",{name:"Export browser data"}).click();
   const stream=await(await pending).createReadStream(),chunks=[];
   for await(const chunk of stream)chunks.push(chunk);
   await page.locator("#terminal").focus();return JSON.parse(Buffer.concat(chunks).toString());
  }
  const keypadTarget=()=>attr("data-keypad-target");
  const fingerTarget=async()=>(await row(5)).slice(28,54).trimEnd();
  async function typeTarget(text,{correct=false,delay=30,physicalFirst=false,addBoundary=false}={}){
   assert.ok(text&&text.length>=2,"An active target exists");
   let offset=0;
   if(correct||physicalFirst){
    if(physicalFirst){
     await page.evaluate(char=>{
      const keys={0:"Insert",1:"End",2:"ArrowDown",3:"PageDown",4:"ArrowLeft",5:"Clear",6:"ArrowRight",7:"Home",8:"ArrowUp",9:"PageUp"};
      document.querySelector("#terminal").dispatchEvent(new KeyboardEvent("keydown",{key:keys[char],code:"Numpad"+char,location:3,bubbles:true,cancelable:true}));
      document.querySelector("#terminal").dispatchEvent(new KeyboardEvent("keyup",{key:keys[char],code:"Numpad"+char,location:3,bubbles:true}));
     },text[0]);
    }else await page.keyboard.type(text[0]);
    await page.waitForTimeout(80);offset=1;
   }
   if(correct){
    await page.keyboard.type(text[1]==="4"?"5":"4");
    assert.match(await screen(),/↓/,"Incorrect character gets an original marker");
    await page.keyboard.press("Backspace");assert.ok(!(await screen()).includes("↓"),"Backspace clears marker");
   }
   await page.keyboard.type(text.slice(offset),{delay});
   if(addBoundary){
    await page.evaluate(()=>{
     const terminal=document.querySelector("#terminal");
     terminal.dispatchEvent(new KeyboardEvent("keydown",{key:"+",code:"NumpadAdd",location:3,bubbles:true,cancelable:true}));
     terminal.dispatchEvent(new KeyboardEvent("keyup",{key:"+",code:"NumpadAdd",location:3,bubbles:true}));
    });
   }else await page.keyboard.press("Enter");
  }
  async function clearKeypadGuides(){
   for(let n=0;n<30;n++){
    const m=await mode();
    if(m==="keypad-intro"||m==="keypad-guide"){await page.keyboard.press("Enter");continue;}
    if(m==="keypad-tutorial"){await typeTarget(await keypadTarget(),{delay:10});continue;}
    return;
   }
   throw Error("Keypad guide did not finish");
  }
  return {page,context,fixture,mode,attr,row,screen,saved,choose,exported,keypadTarget,fingerTarget,typeTarget,clearKeypadGuides};
 }
 // Fingering review preserves the learner's pending introduction and never records scored drills.
 {
  const curriculum=createCurriculum();Object.assign(curriculum,{introduced:28,alphabetic:22,newKey:122,shiftLearned:1,seed:0,introShown:true});
  const h=await open(curriculum),{page,context}=h;
  await page.keyboard.press("l");await page.keyboard.press("f");assert.equal(await h.mode(),"fingering");
  assert.match(await h.screen(),/Finger Positioning Lesson/);
  await page.screenshot({path:"docs/screenshots/fingering-overview.png",fullPage:true});
  await page.keyboard.press("e");assert.equal(await h.attr("data-fingering-tutorial"),"true");
  assert.ok((await h.fingerTarget()).startsWith("dede"));
  await page.screenshot({path:"docs/screenshots/fingering-reach.png",fullPage:true});
  await h.typeTarget(await h.fingerTarget(),{correct:true,delay:10});
  for(let n=0;n<2;n++)await h.typeTarget(await h.fingerTarget(),{delay:10});
  assert.equal(await h.mode(),"fingering");assert.equal(await h.attr("data-fingering-tutorial"),"false");
  let working=(await h.exported()).workingSettings;
  assert.equal(working.curriculum.newKey,122);assert.equal(total(working.curriculum.current),0);
  assert.deepEqual(working.practiceRecords,[]);assert.equal(working.curriculum.weights[8],255);
  assert.notEqual(working.curriculum.seed,0,"Review consumes the original random sequence");
  await page.keyboard.press("t");assert.equal(await h.attr("data-fingering-tutorial"),"true");
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"menu");
  working=(await h.exported()).workingSettings;assert.equal(working.curriculum.newKey,122);
  assert.equal(total(working.curriculum.current),0);assert.deepEqual(await h.saved(),h.fixture);
  await page.keyboard.press("q");await h.choose("No, do not save to history");
  assert.deepEqual(await h.saved(),h.fixture);await context.close();
 }
 // Saved mastery introduces 7 and its nine unscored keypad reach entries.
 {
  const curriculum=createCurriculum();Object.assign(curriculum,{keypadIntroduced:66,keypadNewKey:0,seed:0});
  for(let i=64;i<=66;i++)Object.assign(curriculum.saved[i],{correct:31,errors:0,time:1860});
  const h=await open(curriculum),{page,context}=h;
  await page.keyboard.press("l");await page.keyboard.press("k");
  assert.equal(await h.mode(),"keypad-tutorial");
  const before=(await h.exported()).workingSettings.curriculum.current;
  await page.screenshot({path:"docs/screenshots/keypad-reach.png",fullPage:true});
  for(let n=0;n<9;n++){
   const text=await h.keypadTarget();assert.equal(text.length,8);assert.match(text,/^[47]+$/);
   await h.typeTarget(text,{correct:n===0,delay:10});
  }
  assert.equal(await h.mode(),"keypad");
  const working=(await h.exported()).workingSettings;
  assert.equal(working.curriculum.keypadIntroduced,67);
  assert.equal(working.curriculum.keypadNewKey,0);assert.deepEqual(working.curriculum.current,before);
  assert.deepEqual(await h.saved(),h.fixture);
  await page.keyboard.press("Escape");await page.keyboard.press("q");await h.choose("No, do not save to history");
  assert.deepEqual(await h.saved(),h.fixture);await context.close();
 }
 {
  const curriculum=createCurriculum();Object.assign(curriculum,{keypadIntroduced:66,keypadNewKey:1,seed:0});
  const h=await open(curriculum),{page,context}=h;
  await page.keyboard.press("l");await page.keyboard.press("k");assert.equal(await h.mode(),"keypad-intro");
  await page.screenshot({path:"docs/screenshots/keypad-intro.png",fullPage:true});
  await h.clearKeypadGuides();assert.equal(await h.mode(),"keypad");
  const first=await h.keypadTarget();assert.match(first,/^[456]{4,9}$/);
  assert.equal((await h.row(5)).slice(46-first.length,46),first,"Lesson numbers right-align at original column45");
  await page.screenshot({path:"docs/screenshots/keypad-lesson.png",fullPage:true});
  for(let n=0;n<15;n++){
   await h.clearKeypadGuides();assert.equal(await h.mode(),"keypad");
   assert.match(await h.keypadTarget(),/^[0-9.]{4,9}$/);
   await h.typeTarget(await h.keypadTarget(),{correct:n===0,delay:30,physicalFirst:n===0,addBoundary:n===0});
  }
  if((await h.mode()).includes("end"))await page.keyboard.press("Enter");
  assert.equal(await h.mode(),"keypad-summary");assert.match(await h.screen(),/100%/);
  await page.screenshot({path:"docs/screenshots/keypad-summary.png",fullPage:true});
  await h.choose("Return to Main Menu");assert.equal(await h.mode(),"menu");
  let working=(await h.exported()).workingSettings,lesson=working.practiceRecords.at(-1);
  assert.equal(lesson.kind,"keypad-f5a");assert.equal(lesson.activity,"lesson");assert.equal(lesson.completed,true);
  assert.equal(lesson.lines.length,15);assert.equal(lesson.totals.errors,0);
  assert.ok(lesson.lines.some(l=>l.attempts.some(a=>!a.correct)),"Corrected timed attempt is retained");
  assert.equal(total(working.curriculum.current.slice(0,64)),0,"Keypad samples do not enter keyboard slots");
  assert.ok(total(working.curriculum.current.slice(64))>0);
  assert.deepEqual(await h.saved(),h.fixture,"Keypad lesson does not autosave");
  const introduced=working.curriculum.keypadIntroduced;
  await page.keyboard.press("t");await page.keyboard.press("k");
  assert.equal(await h.mode(),"keypad");assert.equal(await h.attr("data-keypad-activity"),"test");
  await page.screenshot({path:"docs/screenshots/keypad-test.png",fullPage:true});
  for(let n=0;n<24;n++){
   assert.equal(await h.mode(),"keypad");await h.typeTarget(await h.keypadTarget(),{correct:n===0,delay:10});
  }
  assert.equal(await h.mode(),"keypad-test-result");assert.match(await h.screen(),/100%/);
  await page.screenshot({path:"docs/screenshots/keypad-test-result.png",fullPage:true});
  await h.choose("Return to Main Menu");
  working=(await h.exported()).workingSettings;
  const test=working.practiceRecords.at(-1);assert.equal(test.activity,"test");assert.equal(test.completed,true);assert.equal(test.lines.length,24);
  assert.equal(working.curriculum.keypadIntroduced,introduced,"Tests do not introduce keypad keys");
  assert.equal(working.curriculum.introduced,3,"Keypad does not advance keyboard lessons");
  await page.keyboard.press("r");await page.keyboard.press("p");assert.equal(await h.mode(),"report");
  const text=await h.screen();assert.match(text,/Lesson - Keypad/);assert.match(text,/Keypad/);assert.match(text,/Session/);
  assert.ok(!text.includes("NaN"));await page.screenshot({path:"docs/screenshots/keypad-progress.png",fullPage:true});
  await page.keyboard.press("x");assert.equal(await h.attr("data-report-kind"),"speed");
  await page.screenshot({path:"docs/screenshots/keypad-speed.png",fullPage:true});
  await page.setViewportSize({width:390,height:844});await page.waitForFunction(()=>document.documentElement.scrollWidth<=innerWidth);
  await page.screenshot({path:"docs/screenshots/keypad-mobile.png",fullPage:true});
  await page.keyboard.press("Escape");await page.setViewportSize({width:1040,height:780});
  await page.keyboard.press("q");await h.choose("Yes, save session to history");assert.equal(await h.mode(),"exited");
  const committed=await h.saved();assert.equal(committed.profiles[0].practiceRecords.length,2);
  assert.equal(total(committed.profiles[0].curriculum.current),0);assert.ok(total(committed.profiles[0].curriculum.saved.slice(64))>0);
  await page.reload();assert.equal(await h.mode(),"menu");assert.equal((await h.exported()).workingSettings.curriculum.keypadIntroduced,introduced);
  await page.keyboard.press("r");await page.keyboard.press("p");assert.match(await h.screen(),/History/);await page.keyboard.press("Escape");
  await page.keyboard.press("t");await page.keyboard.press("k");assert.equal(await h.mode(),"keypad");
  const partial=await h.keypadTarget();
  for(const char of partial.slice(0,3)){await page.keyboard.type(char);await page.waitForTimeout(80);}
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"menu");
  working=(await h.exported()).workingSettings;
  const aborted=working.practiceRecords.at(-1);assert.equal(aborted.completed,false);assert.ok(aborted.partialAttempts.length>0);
  await page.keyboard.press("q");await h.choose("No, do not save to history");assert.deepEqual(await h.saved(),committed);
  assert.equal(await page.evaluate(k=>localStorage.getItem(k),OLD),"preserved-keypad-prototype");
  await context.close();
 }
 assert.deepEqual(errors,[],"No browser JavaScript page errors");
 console.log("PASS (Chrome): fingering review, pending-key restoration, keypad introduction/nine warmups, lesson/test geometry, corrections and separate key slots, summary/reports, save/reload/discard, narrow layout and legacy preservation.");
}finally{
 if(browser)await browser.close();
 if(server.exitCode===null){const exited=once(server,"exit");server.kill();await exited;}
}
