import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn} from "node:child_process";
import {once} from "node:events";
import {mkdir} from "node:fs/promises";
const PORT=8767,base="http://127.0.0.1:"+PORT,KEY="type-tutor-remake.faithful.v2";
const server=spawn("python3",["scripts/serve.py","--port",String(PORT)],{stdio:"ignore"});
let browser;
try{
  let ready=false;
  for(let i=0;i<50;i++){if(server.exitCode!==null)throw Error("Test server exited");try{if((await fetch(base)).ok){ready=true;break;}}catch{}await new Promise(r=>setTimeout(r,100));}
  assert.ok(ready);
  browser=await chromium.launch({channel:"chrome",headless:true});
  const page=await browser.newPage({viewport:{width:1040,height:780}}),errors=[];
  page.on("pageerror",e=>errors.push(String(e)));
  await page.addInitScript(({KEY})=>{
    if(!localStorage.getItem(KEY))localStorage.setItem(KEY,JSON.stringify({version:2,activeId:"student-1",profiles:[{id:"student-1",name:"Student",wpm:20,weekly:1,drills:5,sound:false}]}));
  },{KEY});
  await page.goto(base);
  const mode=()=>page.locator("#terminal").getAttribute("data-mode");
  const row=n=>page.locator('.row[data-row="'+n+'"]').textContent();
  const target=async()=>(await row(7)).replace(/[│]/g,"").trim();
  const guides=async()=>{
    for(let i=0;i<8;i++){
      if(await mode()==="guide"){await page.keyboard.press("Enter");continue;}
      if(await mode()==="home-practice"){
        const text=(await row(5)).replace(/[│]/g,"").trim();await page.keyboard.type(text,{delay:15});await page.keyboard.press("Enter");continue;
      }
      return;
    }
    throw Error("Tutorial did not finish");
  };
  const start=async()=>{await page.keyboard.press("l");await page.keyboard.press("p");await guides();assert.equal(await mode(),"practice");};
  const choose=async name=>page.getByRole("option",{name,exact:true}).click();
  await start();const first=await target();assert.match(first,/^[asdf ]+$/);
  await mkdir("docs/screenshots",{recursive:true});
  await page.screenshot({path:"docs/screenshots/faithful-practice.png",fullPage:true});
  await page.keyboard.press("x");assert.ok((await row(6)).includes("↓"));
  const red=page.locator('.row[data-row="6"] .cell').filter({hasText:"↓"});
  assert.equal(await red.getAttribute("data-attr"),"2c");
  await page.screenshot({path:"docs/screenshots/faithful-practice-error.png",fullPage:true});
  await page.keyboard.press("Backspace");assert.ok(!(await row(6)).includes("↓"));
  await page.keyboard.type(first,{delay:30});
  assert.equal(await mode(),"practice");await page.keyboard.press("Enter");await guides();
  assert.ok((await row(19)).includes("100%"));
  await page.screenshot({path:"docs/screenshots/faithful-practice-results.png",fullPage:true});
  // Uncorrected error; early Enter advances like a DOS CR, rather than submitting.
  let text=await target();await page.keyboard.press("Enter");assert.ok((await row(6)).includes("↓"));
  await page.keyboard.type(text.slice(1),{delay:30});await page.keyboard.press("Space");await guides();
  assert.ok(!(await row(19)).includes("100%"));
  for(let i=2;i<5;i++){
    text=await target();await page.keyboard.type(text,{delay:30});
    await page.keyboard.press(i===2?"x":i===3?"+":"Enter");await guides();
  }
  assert.equal(await mode(),"lesson-end");
  await page.keyboard.press("Enter");assert.equal(await mode(),"summary");
  assert.ok((await row(0)).includes("Keyboard Lesson Summary"));
  assert.ok((await row(6)).includes("Keys Above 20 WPM: "));
  assert.equal(await page.getByRole("option").count(),3);
  await page.screenshot({path:"docs/screenshots/faithful-practice-summary.png",fullPage:true});
  await choose("Continue lessons");await guides();assert.equal(await mode(),"practice");
  await page.keyboard.type("ax",{delay:65});await page.keyboard.press("Escape");
  assert.equal(await mode(),"menu");assert.equal(await page.locator("#terminal").getAttribute("data-menu"),"0");
  // No autosave: original settings fixture remains unchanged until explicit Quit/save.
  assert.equal(await page.evaluate(k=>JSON.parse(localStorage.getItem(k)).profiles[0].practiceRecords,KEY),undefined);
  const download=page.waitForEvent("download");await page.getByRole("button",{name:"Export browser data"}).click();
  const stream=await (await download).createReadStream(),chunks=[];for await(const chunk of stream)chunks.push(chunk);
  const exported=JSON.parse(Buffer.concat(chunks).toString()),records=exported.workingSettings.practiceRecords;
  assert.equal(records.length,2);assert.equal(records[0].completed,true);assert.equal(records[1].completed,false);
  assert.equal(records[0].lines[0].result.accuracy,100);assert.equal(records[0].lines[1].result.errors,1);
  assert.equal(records[0].lines[2].result.errors,1);
  assert.equal(records[0].totals.errors,2);assert.ok(records[0].totals.time>0);
  assert.ok(records[1].partialAttempts.some(a=>!a.correct));assert.equal(records[1].totals.correct,0);
  await page.locator("#terminal").focus();await page.keyboard.press("q");await choose("Yes, save session to history");
  assert.equal(await mode(),"exited");
  assert.deepEqual(await page.evaluate(k=>JSON.parse(localStorage.getItem(k)).profiles[0].practiceRecords,KEY),records);
  assert.equal(records[0].kind,"adaptive-alpha-f4");
  await page.reload();await start();await page.keyboard.type("as",{delay:65});await page.keyboard.press("Escape");
  await page.keyboard.press("q");await choose("No, do not save to history");
  await page.keyboard.press("Enter");await page.reload();
  assert.equal(await page.evaluate(k=>JSON.parse(localStorage.getItem(k)).profiles[0].practiceRecords.length,KEY),2);
  await start();await page.setViewportSize({width:390,height:844});
  await page.waitForFunction(()=>document.documentElement.scrollWidth<=innerWidth);
  await page.screenshot({path:"docs/screenshots/faithful-practice-mobile.png",fullPage:true});
  await page.keyboard.press("Escape");await page.keyboard.press("q");await choose("No, do not save to history");
  assert.deepEqual(errors,[]);
  console.log("PASS (Chrome): original practice layout/arrows/correction, early CR and boundary errors, five-drill summary, continue, abort, export, explicit save/reload/discard, narrow viewport; no JS errors.");
}finally{
  if(browser)await browser.close();
  if(server.exitCode===null){const exited=once(server,"exit");server.kill();await exited;}
}
