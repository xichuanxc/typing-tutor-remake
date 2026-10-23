import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn} from "node:child_process";
import {once} from "node:events";
import {mkdir} from "node:fs/promises";
import {createCurriculum} from "../dist/curriculum.js";
import DATA from "../dist/curriculum-data.js";
import {PracticeLesson,validPracticeRecord} from "../dist/practice.js";
// Deterministic fixtures model earlier saved per-key learning, not an imported DOS history.
const PORT=8768,base="http://127.0.0.1:"+PORT,KEY="type-tutor-remake.faithful.v2";
const server=spawn("python3",["scripts/serve.py","--port",String(PORT)],{stdio:"ignore"});
const errors=[];let browser;
const sample={correct:31,errors:0,time:1860};
const fixture=()=>({...createCurriculum(20),seed:0,introShown:true});
const oldLesson=new PracticeLesson(5,20,"2026-10-23T00:00:00.000Z");
let oldTime=0;
for(const key of oldLesson.line.target)oldLesson.input(key,oldTime+=10);
oldLesson.input("Enter",oldTime+=10);oldLesson.input("Escape",oldTime+=10);
const originalRecord=oldLesson.record();assert.ok(validPracticeRecord(originalRecord));
try{
  let ready=false;
  for(let i=0;i<50;i++){
    if(server.exitCode!==null)throw Error("Adaptive test server exited");
    try{if((await fetch(base)).ok){ready=true;break;}}catch{}
    await new Promise(r=>setTimeout(r,100));
  }
  assert.ok(ready,"Adaptive server ready");
  browser=await chromium.launch({channel:"chrome",headless:true});
  await mkdir("docs/screenshots",{recursive:true});
  async function open(curriculum,practiceRecords=[]){
    const context=await browser.newContext({viewport:{width:1040,height:780}});
    const page=await context.newPage();
    page.on("pageerror",e=>errors.push(String(e)));
    const db={version:2,activeId:"student-1",profiles:[{
      id:"student-1",name:"Student",wpm:20,weekly:1,drills:5,sound:false,curriculum,practiceRecords
    }]};
    await page.addInitScript(({KEY,db})=>{
      if(localStorage.getItem(KEY)===null)localStorage.setItem(KEY,JSON.stringify(db));
    },{KEY,db});
    await page.goto(base);await page.locator(".cell").last().waitFor();
    return {page,context,db};
  }
  const mode=page=>page.locator("#terminal").getAttribute("data-mode");
  const row=(page,n)=>page.locator('.row[data-row="'+n+'"]').textContent();
  const screen=async page=>(await page.locator(".row").allTextContents()).join("\n");
  const target=async(page,n=7)=>(await row(page,n)).replace(/[│]/g,"").trim();
  const start=async page=>{await page.keyboard.press("l");await page.keyboard.press("p");};
  const choose=(page,name)=>page.getByRole("option",{name,exact:true}).click();
  const saved=page=>page.evaluate(k=>JSON.parse(localStorage.getItem(k)),KEY);
  async function exported(page){
    const download=page.waitForEvent("download");
    await page.getByRole("button",{name:"Export browser data"}).click();
    const stream=await(await download).createReadStream(),chunks=[];
    for await(const chunk of stream)chunks.push(chunk);
    await page.locator("#terminal").focus();
    return JSON.parse(Buffer.concat(chunks).toString());
  }
  async function discard(page){
    await page.keyboard.press("Escape");assert.equal(await mode(page),"menu");
    await page.keyboard.press("q");await choose(page,"No, do not save to history");
    assert.equal(await mode(page),"exited");
  }
  {
    const state=fixture();state.saved[DATA.keyIndex.a]={...sample};
    const {page,context}=await open(state,[originalRecord]);
    await start(page);assert.equal(await mode(page),"guide");
    assert.match(await screen(page),/home key.*J/i);
    await page.screenshot({path:"docs/screenshots/adaptive-home-key.png",fullPage:true});
    await page.keyboard.press("Enter");assert.equal(await mode(page),"practice");
    assert.ok(!(await row(page,14)).includes("--"));
    const text=await target(page),expected=DATA.keyIndex[text[1]];
    await page.keyboard.type(text[0]);await page.waitForTimeout(70);
    await page.keyboard.press("!");assert.match(await row(page,6),/↓/);
    await page.keyboard.press("Backspace");assert.ok(!(await row(page,6)).includes("↓"));
    await page.keyboard.type(text.slice(1),{delay:25});await page.keyboard.press("Enter");
    assert.equal(await mode(page),"practice");assert.match(await row(page,19),/100%/);
    await page.keyboard.press("Escape");
    const out=await exported(page);
    assert.equal(out.workingSettings.curriculum.introduced,4);
    assert.ok(out.workingSettings.curriculum.current[expected].errors>=1);
    assert.deepEqual(out.workingSettings.practiceRecords[0],originalRecord);
    assert.equal(out.workingSettings.practiceRecords[1].lines[0].result.errors,0);
    await page.keyboard.press("q");await choose(page,"Yes, save session to history");
    assert.equal(await mode(page),"exited");
    await page.reload();
    const profile=(await saved(page)).profiles[0];
    assert.equal(profile.curriculum.introduced,4);
    assert.ok(profile.curriculum.current.every(a=>a.correct===0&&a.errors===0&&a.time===0));
    assert.ok(profile.curriculum.saved[expected].errors>=1);
    assert.deepEqual(profile.practiceRecords[0],originalRecord);
    assert.equal(profile.practiceRecords[1].kind,"adaptive-alpha-f4");
    await context.close();
  }
  {
    const state=fixture();state.introduced=7;state.alphabetic=3;state.shiftPending=1;
    const {page,context,db}=await open(state);
    await start(page);assert.equal(await mode(page),"guide");
    assert.match(await screen(page),/Shift/);
    await page.screenshot({path:"docs/screenshots/adaptive-shift.png",fullPage:true});
    await page.keyboard.press("Enter");assert.equal(await mode(page),"practice");
    assert.match(await target(page),/[A-Z]/);
    const out=await exported(page);
    assert.equal(out.workingSettings.curriculum.shiftLearned,1);
    assert.equal(out.workingSettings.curriculum.shiftPending,0);
    await discard(page);assert.deepEqual(await saved(page),db);
    await context.close();
  }
  {
    const state=fixture();state.introduced=7;state.alphabetic=3;state.shiftLearned=1;
    for(let i=0;i<8;i++)state.saved[i]={...sample};
    const {page,context,db}=await open(state);
    await start(page);assert.equal(await mode(page),"home-practice");
    const guide=await screen(page);assert.match(guide,/Home Key Lesson/);
    assert.match(guide,/D/);assert.match(guide,/E/);
    const highlightedKeys=async()=>{
      for(const key of "de"){
        const [r,c]=DATA.keyboardPositions[DATA.keyIndex[key]];
        const cell=page.locator('.row[data-row="'+(12+r*2+2)+'"] .cell').nth(13+Math.trunc(c/3)+r*2+c+3);
        assert.equal(await cell.textContent(),key.toUpperCase());
        assert.equal(await cell.getAttribute("data-attr"),"1f");
      }
    };
    await highlightedKeys();
    assert.equal(await mode(page),"home-practice");
    assert.match(await row(page,10),/finger/);await highlightedKeys();
    await page.evaluate(async()=>{
      await document.fonts.ready;
      await new Promise(resolve=>requestAnimationFrame(()=>requestAnimationFrame(resolve)));
    });
    await page.waitForTimeout(100);
    const whiteCells=await page.evaluate(()=>{
      const positions=[[0,1],[3,22],[5,28],[12,13],[18,29],[16,27]];
      return positions.map(([r,c])=>{
        const cell=document.querySelector('.row[data-row="'+r+'"]').children[c],style=getComputedStyle(cell);
        return {r,c,text:cell.textContent,color:style.color,visibility:style.visibility,opacity:style.opacity};
      });
    });
    assert.ok(whiteCells.every(c=>c.color==="rgb(255, 255, 255)"&&c.visibility==="visible"&&c.opacity==="1"));
    assert.ok(whiteCells.every(c=>c.text.trim().length>0));
    console.log("Reach capture white cells:",JSON.stringify(whiteCells));
    await page.screenshot({path:"docs/screenshots/adaptive-reach.png",fullPage:true});
    const before=(await exported(page)).workingSettings.curriculum;
    for(let i=0;i<3;i++){
      const text=await target(page,5);assert.match(text,/^[de ]+$/);
      await page.keyboard.type(text,{delay:15});await page.keyboard.press("Enter");
      assert.equal(await mode(page),i===2?"practice":"home-practice");
      if(i<2){assert.match(await row(page,10),/finger/);await highlightedKeys();}
    }
    const after=await exported(page);
    assert.equal(after.workingSettings.curriculum.newKey,0);
    assert.equal(after.workingSettings.curriculum.introduced,8);
    assert.deepEqual(after.workingSettings.curriculum.current,before.current);
    assert.equal(after.inProgressPractice.lines.length,0);
    assert.equal(after.inProgressPractice.totals.correct,0);
    assert.equal(after.inProgressPractice.partialAttempts.length,0);
    await discard(page);assert.deepEqual(await saved(page),db);
    await context.close();
  }
  {
    const state=fixture();state.introduced=28;state.alphabetic=22;state.shiftLearned=1;
    const {page,context}=await open(state);
    await start(page);assert.equal(await mode(page),"practice");
    let foundWord=false;
    for(let i=0;i<5;i++){
      const text=await target(page);
      assert.ok([...text].every(c=>c===" "||DATA.keyIndex[c]<=28));
      foundWord||=/[a-z]{3,}/i.test(text);
      assert.ok(!(await row(page,14)).includes("--"));
      if(i===0)await page.screenshot({path:"docs/screenshots/adaptive-words.png",fullPage:true});
      await page.keyboard.type(text,{delay:20});await page.keyboard.press("Enter");
      assert.equal(await mode(page),i===4?"lesson-end":"practice");
    }
    assert.ok(foundWord,"Recovered alphabetic corpus yields words");
    await page.keyboard.press("Enter");assert.equal(await mode(page),"summary");
    const summary=await screen(page);
    await page.screenshot({path:"docs/screenshots/adaptive-summary.png",fullPage:true});
    assert.match(summary,/Best Keys:/);assert.match(summary,/Keys to Work on:/);
    assert.ok(!summary.includes("--"));assert.ok(!summary.includes("NaN"));assert.ok(!summary.includes("Infinity"));
    const out=await exported(page),record=out.workingSettings.practiceRecords[0];
    assert.equal(record.completed,true);assert.equal(record.lines.length,5);
    assert.equal(record.introducedAtEnd,28);assert.equal(record.totals.accuracy,100);
    await choose(page,"Return to Main Menu");await page.keyboard.press("q");
    await choose(page,"No, do not save to history");
    await context.close();
  }

  // Full-key saved fixtures represent previous learning; no DOS history is imported.
  for(const [level,seed,label] of [[29,1,"punctuation"],[37,31,"number"],[49,12,"symbol"],[63,61,"last-key"]]){
    const state=fixture();Object.assign(state,{introduced:level,alphabetic:22,shiftLearned:1,newKey:DATA.presentation.charCodeAt(level),seed});
    const {page,context,db}=await open(state),key=DATA.presentation[level],home=DATA.counterpart[level];
    await start(page);assert.equal(await mode(page),"home-practice");
    assert.match(await row(page,10),/finger/);
    for(const highlight of [key,home]){
      const [r,c]=DATA.keyboardPositions[DATA.keyIndex[highlight]];
      const cell=page.locator('.row[data-row="'+(12+r*2+2)+'"] .cell').nth(13+Math.trunc(c/3)+r*2+c+3);
      assert.equal(await cell.textContent(),highlight.toUpperCase());assert.equal(await cell.getAttribute("data-attr"),"1f");
    }
    await page.evaluate(()=>document.fonts.ready);
    await page.screenshot({path:"docs/screenshots/full-key-"+label+"-guide.png",fullPage:true});
    const first=await target(page,5);assert.ok(first.startsWith(home+key+home+key));
    // The first key types directly; no acknowledgement consumes it.
    await page.keyboard.type(first[0]);assert.equal((await row(page,6)).slice(28,29),first[0]);
    await page.waitForTimeout(80);await page.keyboard.type(first[1]==="x"?"y":"x");
    assert.match(await row(page,4),/↓/);await page.keyboard.press("Backspace");
    assert.ok(!(await row(page,4)).includes("↓"));
    await page.keyboard.type(first.slice(1),{delay:10});await page.keyboard.press("Enter");
    for(let n=0;n<2;n++){await page.keyboard.type(await target(page,5),{delay:10});await page.keyboard.press("Enter");}
    assert.equal(await mode(page),"practice");
    let out=await exported(page);assert.equal(out.workingSettings.curriculum.newKey,0);
    assert.ok(out.workingSettings.curriculum.current.every(a=>a.time===0),"Warmups and corrections excluded from adaptive samples");
    assert.deepEqual(await saved(page),db,"Tutorial does not autosave");
    const text=await target(page);await page.keyboard.type(text[0]);await page.waitForTimeout(80);
    await page.keyboard.type(text[1]==="x"?"y":"x");await page.keyboard.press("Backspace");
    await page.keyboard.type(text.slice(1),{delay:40});await page.keyboard.press("Enter");
    assert.equal(await mode(page),"practice");
    await page.screenshot({path:"docs/screenshots/full-key-"+label+"-practice.png",fullPage:true});
    await page.keyboard.press("Escape");out=await exported(page);
    const record=out.workingSettings.practiceRecords[0];
    assert.equal(record.kind,"adaptive-keyboard-f4c");assert.equal(record.lines.length,1);
    assert.equal(record.lines[0].result.accuracy,100);assert.ok(record.lines[0].attempts.some(a=>!a.correct));
    assert.ok(validPracticeRecord(record));assert.equal(out.workingSettings.curriculum.introduced,level);
    await page.keyboard.press("q");await choose(page,"Yes, save session to history");
    assert.equal(await mode(page),"exited");await page.reload();
    const profile=(await saved(page)).profiles[0];assert.equal(profile.curriculum.introduced,level);
    assert.equal(profile.curriculum.newKey,0);assert.deepEqual(profile.practiceRecords,[record]);
    await page.keyboard.press("r");await page.keyboard.press("p");assert.equal(await mode(page),"report");
    assert.match(await screen(page),/History/);await page.keyboard.press("Escape");
    await start(page);assert.ok(["practice","home-practice"].includes(await mode(page)));
    await page.keyboard.press("Escape");await page.keyboard.press("q");await choose(page,"No, do not save to history");
    assert.deepEqual((await saved(page)).profiles[0],profile);await context.close();
  }

  assert.deepEqual(errors,[]);
  console.log("PASS (Chrome): recovered home/Shift/reach guides, untimed tutorial isolation, generated words/focus, five-drill rankings, correction penalties, explicit save/reload/discard, prior F3 record preservation, full-key punctuation/digit/symbol/last-key guides and persistence; no JS errors.");
}finally{
  if(browser)await browser.close();
  if(server.exitCode===null){const exited=once(server,"exit");server.kill();await exited;}
}
