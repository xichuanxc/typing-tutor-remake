import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn} from "node:child_process";
import {once} from "node:events";
import {mkdir} from "node:fs/promises";
import {createCurriculum} from "../dist/curriculum.js";
import {TypingTest} from "../dist/typing-test.js";
const PORT=8771,base="http://127.0.0.1:"+PORT,KEY="type-tutor-remake.faithful.v2",OLD="type-tutor-remake.v1";
const server=spawn("python3",["scripts/serve.py","--port",String(PORT)],{stdio:"ignore"});
const errors=[];let browser;
const payload=(name,text)=>({name,mimeType:"text/plain",buffer:Buffer.isBuffer(text)?text:Buffer.from(text,"ascii")});
function priorTests(){
 const records=[];
 for(let n=0;n<4;n++){
  const t=new TypingTest(createCurriculum(),"practice",20,"2026-10-23T00:00:00.000Z");let now=100;
  for(const line of t.lines)for(const key of [...line.target,"Enter"]){t.input(key,now);now+=100;}
  records.push(t.record());
 }
 return records;
}
try{
 let ready=false;
 for(let i=0;i<50;i++){
  if(server.exitCode!==null)throw Error("Disk test server exited");
  try{if((await fetch(base)).ok){ready=true;break;}}catch{}
  await new Promise(r=>setTimeout(r,100));
 }
 assert.ok(ready,"Disk test server ready");
 browser=await chromium.launch({channel:"chrome",headless:true});
 await mkdir("docs/screenshots",{recursive:true});
 async function open(practiceRecords=[]){
  const context=await browser.newContext({viewport:{width:1040,height:780}}),page=await context.newPage();
  page.on("pageerror",e=>errors.push(String(e)));
  const fixture={version:2,activeId:"student-1",profiles:[{
   id:"student-1",name:"Student",wpm:20,weekly:1,drills:5,sound:false,practiceRecords
  }]};
  await page.addInitScript(({KEY,OLD,fixture})=>{
   if(localStorage.getItem(KEY)===null)localStorage.setItem(KEY,JSON.stringify(fixture));
   if(localStorage.getItem(OLD)===null)localStorage.setItem(OLD,"preserved-disk-prototype");
  },{KEY,OLD,fixture});
  await page.goto(base);await page.locator(".cell").last().waitFor();
  const terminal=page.locator("#terminal"),mode=()=>terminal.getAttribute("data-mode");
  const attr=name=>terminal.getAttribute(name),row=n=>page.locator('.row[data-row="'+n+'"]').textContent();
  const screen=async()=>(await page.locator(".row").allTextContents()).join("\n");
  const saved=()=>page.evaluate(k=>JSON.parse(localStorage.getItem(k)),KEY);
  const choose=name=>page.getByRole("option",{name,exact:true}).click();
  async function exported(){
   const pending=page.waitForEvent("download");await page.getByRole("button",{name:"Export browser data"}).click();
   const stream=await(await pending).createReadStream(),chunks=[];
   for await(const chunk of stream)chunks.push(chunk);
   await terminal.focus();return JSON.parse(Buffer.concat(chunks).toString());
  }
  async function startPicker(){
   assert.equal(await mode(),"menu");await page.keyboard.press("t");await page.keyboard.press("d");
   await page.waitForFunction(()=>document.querySelector("#terminal").dataset.mode==="disk-picker");
  }
  async function upload(files){await page.locator("#disk-files").setInputFiles(files);await page.waitForFunction(()=>document.querySelector("#terminal").dataset.mode==="disk-picker");await terminal.focus();}
  async function selectFirst(expected="disk-test"){
   await page.keyboard.press("Enter");
   await page.waitForFunction(expected=>document.querySelector("#terminal").dataset.mode===expected,expected);
  }
  async function typeLine({correct=false,boundary="Enter"}={}){
   assert.equal(await mode(),"disk-test");
   const text=await attr("data-disk-target"),line=Number(await attr("data-disk-line"));
   assert.equal(typeof text,"string");assert.ok(text.length<=72);
   assert.equal((await row(4+3*line)).slice(3,3+text.length),text,"Recovered test coordinates");
   let offset=0;
   if(correct&&text.length>=2){
    await page.keyboard.type(text[0]);await page.waitForTimeout(80);offset=1;
    await page.keyboard.type(text[1]==="x"?"z":"x");
    assert.equal((await row(3+3*line)).slice(4,5),"↓");
    await page.keyboard.press("Backspace");assert.ok(!(await row(3+3*line)).includes("↓"));
   }
   if(text.slice(offset))await page.keyboard.type(text.slice(offset),{delay:2});
   await page.keyboard.press(boundary);return text;
  }
  async function finish({correctFirst=false}={}){
   let count=0,maxPage=0;
   while(await mode()==="disk-test"){
    assert.ok(count<100,"Disk test finishes within its fixture");
    maxPage=Math.max(maxPage,Number(await attr("data-disk-page")));
    await typeLine({correct:correctFirst&&count===0,boundary:["Enter","Space","+"][count%3]});count++;
   }
   assert.equal(await mode(),"disk-test-result");return {count,maxPage};
  }
  return {page,context,fixture,terminal,mode,attr,row,screen,saved,choose,exported,startPicker,upload,selectFirst,typeLine,finish};
 }
 // Browsing or canceling the file list does not create student activity.
 {
  const h=await open(),{page,context}=h;
  await h.startPicker();assert.match(await h.screen(),/There are no test files/);
  assert.equal(await page.getByRole("button",{name:"Choose local test files",exact:true}).isVisible(),true);
  await page.screenshot({path:"docs/screenshots/disk-empty-picker.png",fullPage:true});
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"menu");
  assert.deepEqual(await h.saved(),h.fixture);assert.equal((await h.exported()).workingSettings.curriculum,undefined);
  await h.startPicker();
  await h.upload(Array.from({length:9},(_,i)=>payload("file"+i+".tst","alpha beta.")));
  assert.equal(await page.getByRole("option").count(),8,"Native file-list cap");
  await page.keyboard.press("ArrowUp");
  assert.equal(await page.getByRole("option").last().getAttribute("aria-selected"),"true","Picker wraps upward");
  await page.keyboard.press("Space");
  assert.equal(await page.getByRole("option").first().getAttribute("aria-selected"),"true","Space wraps forward");
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"menu");
  await page.keyboard.press("q");assert.equal(await h.mode(),"exited","Picker leaves a clean session");
  await context.close();
 }
 // Earlier keyboard fixtures establish a distinct four-row history group.
 {
  const earlier=priorTests(),h=await open(earlier),{page,context}=h;
  const text=("alpha beta gamma delta epsilon zeta eta theta iota kappa lambda mu. ".repeat(16))+"final word.";
  await h.startPicker();await h.upload([payload("a long selection lesson.txt",text),payload("SHORT.TST","A short test.")]);
  assert.equal(await page.getByRole("option").count(),2);
  await page.screenshot({path:"docs/screenshots/disk-picker.png",fullPage:true});
  await h.selectFirst();
  const name=await h.attr("data-disk-filename");assert.match(name,/^[A-Z0-9_~!-]{1,8}\.TST$/);
  await page.screenshot({path:"docs/screenshots/disk-test.png",fullPage:true});
  const result=await h.finish({correctFirst:true});assert.ok(result.maxPage>=1,"Text crosses a six-line page");
  assert.ok(result.count>=7);assert.match(await h.screen(),/100%/);
  await page.screenshot({path:"docs/screenshots/disk-result.png",fullPage:true});
  await h.choose("Return to Main Menu");
  let working=(await h.exported()).workingSettings,record=working.practiceRecords.at(-1);
  assert.equal(record.kind,"disk-test-f5b");assert.equal(record.name,name);assert.equal(record.completed,true);
  assert.equal(record.lines.length,result.count);assert.equal(record.totals.errors,0);
  assert.ok(record.lines.some(l=>l.attempts.some(a=>!a.correct)),"Corrected timed error is retained");
  assert.ok(record.pages.length>=2);assert.match(record.source.sha256,/^[0-9a-f]{64}$/);
  assert.equal(record.source.originalName,"a long selection lesson.txt");assert.equal(typeof record.source.bytes,"number");
  assert.equal(working.curriculum.introduced,3,"Disk test does not teach keys");
  assert.deepEqual(working.practiceRecords.slice(0,4),earlier);assert.deepEqual(await h.saved(),h.fixture);
  await page.keyboard.press("r");await page.keyboard.press("p");assert.equal(await h.mode(),"report");
  let rows=await page.locator(".row").allTextContents();
  assert.equal(rows.filter(r=>r.slice(5,19).trim()==="Practice").length,4,"Disk history does not evict keyboard test history");
  assert.equal(rows.filter(r=>r.slice(5,19).trim()===name).length,1);
  await page.screenshot({path:"docs/screenshots/disk-progress.png",fullPage:true});
  await page.keyboard.press("Escape");await page.keyboard.press("q");await h.choose("Yes, save session to history");
  const committed=await h.saved();assert.equal(committed.profiles[0].practiceRecords.length,5);
  assert.ok(committed.profiles[0].curriculum.current.every(s=>s.time===0));
  await page.reload();assert.equal(await h.mode(),"menu");
  await h.startPicker();assert.match(await h.screen(),/There are no test files/,"Source file selection is memory only");
  await h.upload([payload("AGAIN.TST",text)]);await h.selectFirst();
  for(let n=0;n<6;n++)await h.typeLine();
  assert.equal(await h.attr("data-disk-page"),"1");assert.equal(await h.attr("data-disk-line"),"0","Next page starts immediately");
  const partial=await h.attr("data-disk-target");
  for(const char of partial.slice(0,3)){await page.keyboard.type(char);await page.waitForTimeout(80);}
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"menu");
  working=(await h.exported()).workingSettings;record=working.practiceRecords.at(-1);
  assert.equal(record.completed,false);assert.equal(record.lines.length,6);assert.equal(record.pages.length,1);
  assert.ok(record.totals.correct>0,"A completed earlier page retains its final session counters");
  assert.ok(record.partialAttempts.length>0);
  await page.keyboard.press("r");await page.keyboard.press("p");rows=await page.locator(".row").allTextContents();
  assert.ok(!rows.some(r=>r.slice(5,19).trim()==="AGAIN.TST"),"Aborted Disk test gets no completed-test row");
  assert.ok(rows.some(r=>r.slice(5,19).trim()==="Session"));assert.ok(rows.some(r=>r.slice(5,19).trim()==="History"));
  await page.setViewportSize({width:390,height:844});await page.waitForFunction(()=>document.documentElement.scrollWidth<=innerWidth);
  await page.screenshot({path:"docs/screenshots/disk-mobile.png",fullPage:true});
  await page.keyboard.press("Escape");await page.keyboard.press("q");await h.choose("No, do not save to history");
  assert.deepEqual(await h.saved(),committed);
  assert.equal(await page.evaluate(k=>localStorage.getItem(k),OLD),"preserved-disk-prototype");
  await context.close();
 }
 // Native empty EOF entry and explicit rejection of unsupported or damaged input.
 {
  const h=await open(),{page,context}=h;
  await h.startPicker();await h.upload([payload("BAD.TST",Buffer.from([1,2]))]);await h.selectFirst("disk-error");
  await page.screenshot({path:"docs/screenshots/disk-error.png",fullPage:true});
  assert.equal((await h.exported()).workingSettings.curriculum,undefined,"Invalid file leaves the profile clean");
  await page.keyboard.press("Escape");assert.equal(await h.mode(),"disk-picker");
  await h.upload([payload("UNKNOWN.TST","alpha\\beta")]);await h.selectFirst("disk-error");
  assert.equal((await h.exported()).workingSettings.curriculum,undefined);
  await page.keyboard.press("Enter");assert.equal(await h.mode(),"disk-picker");
  await h.upload([payload("EMPTY.TST","")]);await h.selectFirst();
  assert.equal(await h.attr("data-disk-target"),"");await page.keyboard.press("Enter");
  assert.equal(await h.mode(),"disk-test-result");assert.ok(!(await h.screen()).includes("NaN"));
  await h.choose("Take another test");assert.equal(await h.mode(),"disk-picker");
  const record=(await h.exported()).workingSettings.practiceRecords.at(-1);
  assert.equal(record.completed,true);assert.equal(record.lines.length,1);assert.equal(record.lines[0].target,"");
  await page.keyboard.press("Escape");await page.keyboard.press("q");await h.choose("No, do not save to history");
  assert.deepEqual(await h.saved(),h.fixture);await context.close();
 }
 // Rotated DOS text uses its native non-aborting Escape behavior.
 {
  const h=await open(),{page,context}=h;
  await h.startPicker();
  await h.upload([payload("PACKED.TST",Buffer.from([1,6,0,0xc2,0xcd,0x23,0x66,0x04,0]))]);
  await h.selectFirst();assert.equal(await h.attr("data-disk-target"),"asdf");
  await page.keyboard.type("a");await page.waitForTimeout(80);await page.keyboard.press("Escape");
  assert.equal(await h.mode(),"disk-test","Packed Escape is input, not an abort");
  assert.equal((await h.row(3)).slice(4,5),"↓");
  await page.screenshot({path:"docs/screenshots/disk-rotated-error.png",fullPage:true});
  await page.keyboard.press("Backspace");assert.ok(!(await h.row(3)).includes("↓"));
  await page.keyboard.type("sdf",{delay:30});await page.keyboard.press("Enter");
  assert.equal(await h.mode(),"disk-test-result");assert.match(await h.screen(),/100%/);
  const record=(await h.exported()).workingSettings.practiceRecords.at(-1);
  assert.equal(record.source.format,"rotated");assert.equal(record.completed,true);
  assert.equal(record.lines.length,1);assert.equal(record.totals.errors,0);
  assert.ok(record.lines[0].attempts.some(a=>!a.correct),"Corrected Escape remains in timed observations");
  await h.choose("Return to Main Menu");await page.keyboard.press("q");await h.choose("No, do not save to history");
  assert.deepEqual(await h.saved(),h.fixture);await context.close();
 }
 assert.deepEqual(errors,[],"No browser JavaScript page errors");
 console.log("PASS (Chrome): native Disk picker, local-file aliases, multi-page tests/EOF, corrections and boundary keys, separate test history, completed-page abort accounting, errors/empty files, rotated Escape semantics, save/reload/discard, narrow layout and legacy preservation.");
}finally{
 if(browser)await browser.close();
 if(server.exitCode===null){const exited=once(server,"exit");server.kill();await exited;}
}
