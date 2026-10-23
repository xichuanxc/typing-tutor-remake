import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn} from "node:child_process";
import {once} from "node:events";
import {mkdir} from "node:fs/promises";
const PORT=8769,base="http://127.0.0.1:"+PORT,KEY="type-tutor-remake.faithful.v2",OLD="type-tutor-remake.v1";
const server=spawn("python3",["scripts/serve.py","--port",String(PORT)],{stdio:"ignore"});
const errors=[];let browser;
const sum=samples=>samples.reduce((sum,s)=>sum+s.correct+s.errors,0);
try{
  let ready=false;
  for(let i=0;i<50;i++){
    if(server.exitCode!==null)throw Error("Tests/reports server exited");
    try{if((await fetch(base)).ok){ready=true;break;}}catch{}
    await new Promise(resolve=>setTimeout(resolve,100));
  }
  assert.ok(ready,"Tests/reports server ready");
  browser=await chromium.launch({channel:"chrome",headless:true});
  await mkdir("docs/screenshots",{recursive:true});
  const context=await browser.newContext({viewport:{width:1040,height:780}});
  const page=await context.newPage();
  page.on("pageerror",error=>errors.push(String(error)));
  const fixture={version:2,activeId:"student-1",profiles:[{
    id:"student-1",name:"Student",wpm:20,weekly:1,drills:5,sound:false
  }]};
  await page.addInitScript(({KEY,OLD,fixture})=>{
    if(localStorage.getItem(KEY)===null)localStorage.setItem(KEY,JSON.stringify(fixture));
    if(localStorage.getItem(OLD)===null)localStorage.setItem(OLD,"preserved-old-prototype");
  },{KEY,OLD,fixture});
  await page.goto(base);await page.locator(".cell").last().waitFor();
  const mode=()=>page.locator("#terminal").getAttribute("data-mode");
  const attr=name=>page.locator("#terminal").getAttribute(name);
  const row=n=>page.locator('.row[data-row="'+n+'"]').textContent();
  const screen=async()=>(await page.locator(".row").allTextContents()).join("\n");
  const saved=()=>page.evaluate(key=>JSON.parse(localStorage.getItem(key)),KEY);
  const choose=name=>page.getByRole("option",{name,exact:true}).click();
  const target=async n=>(await row(4+3*n)).slice(3,75).trimEnd();
  const exportState=async()=>{
    const pending=page.waitForEvent("download");
    await page.getByRole("button",{name:"Export browser data"}).click();
    const stream=await(await pending).createReadStream(),chunks=[];
    for await(const chunk of stream)chunks.push(chunk);
    await page.locator("#terminal").focus();
    return JSON.parse(Buffer.concat(chunks).toString());
  };
  const report=async(kind,key)=>{
    assert.equal(await mode(),"menu");
    await page.keyboard.press("r");await page.keyboard.press(key);
    assert.equal(await mode(),"report");assert.equal(await attr("data-report-kind"),kind);
  };
  const exitReport=async()=>{await page.keyboard.press("Escape");assert.equal(await mode(),"menu");};
  const startTest=async type=>{
    await page.keyboard.press("t");await page.keyboard.press(type==="practice"?"p":"a");
    assert.equal(await mode(),"test");assert.equal(await attr("data-test-type"),type);
    assert.equal(await attr("data-line"),"0");
  };
  const finishLines=async({correctFirst=false}={})=>{
    const targets=[];
    for(let i=0;i<6;i++){
      assert.equal(await attr("data-line"),String(i));
      const text=await target(i);targets.push(text);
      assert.ok(text.length>=2&&text.length<=72,"Test target width");
      assert.match(text,/^[ -~]+$/);
      let offset=0;
      if(i===0&&correctFirst){
        await page.keyboard.type(text[0]);await page.waitForTimeout(70);offset=1;
        const wrong=text[1]==="x"?"z":"x";
        await page.keyboard.type(wrong);
        assert.equal((await row(3)).slice(4,5),"↓");
        assert.equal(await page.locator('.row[data-row="3"] .cell').nth(4).getAttribute("data-attr"),"2c");
        await page.keyboard.press("Backspace");
        assert.ok(!(await row(3)).includes("↓"),"Backspace clears corrected error arrow");
      }
      await page.keyboard.type(text.slice(offset),{delay:5});
      assert.equal(await mode(),"test","Target requires boundary confirmation");
      await page.keyboard.press(["Enter","Space","+"][i%3]);
    }
    assert.equal(await mode(),"test-summary");
    return targets;
  };
  // Browsing reports on a new profile must never create adaptive state or dirty the session.
  await report("progress","p");
  assert.ok(!(await screen()).includes("NaN"));
  await page.keyboard.press("x");assert.equal(await attr("data-report-kind"),"speed");
  await page.keyboard.press("x");assert.equal(await attr("data-report-kind"),"accuracy");
  await page.keyboard.press("x");assert.equal(await attr("data-report-kind"),"progress");
  await exitReport();
  assert.deepEqual(await saved(),fixture);
  assert.equal((await exportState()).workingSettings.curriculum,undefined);
  await page.keyboard.press("q");assert.equal(await mode(),"exited","Read-only reports leave session clean");
  await page.keyboard.press("Enter");assert.equal(await mode(),"menu");
  await startTest("practice");
  const firstTargets=await Promise.all(Array.from({length:6},(_,i)=>target(i)));
  assert.ok(firstTargets.every(text=>/^[asdf ]+$/.test(text)),"Practice test uses introduced home keys");
  await page.screenshot({path:"docs/screenshots/faithful-test-practice.png",fullPage:true});
  const practiceTargets=await finishLines({correctFirst:true});
  assert.deepEqual(practiceTargets,firstTargets);
  assert.match(await screen(),/100%/);
  assert.equal(await page.getByRole("option").count(),3);
  for(const label of ["Take another test","Practice Lesson","Return to Main Menu"])
    assert.equal(await page.getByRole("option",{name:label,exact:true}).count(),1);
  await page.screenshot({path:"docs/screenshots/faithful-test-result.png",fullPage:true});
  await choose("Return to Main Menu");assert.equal(await mode(),"menu");
  let working=(await exportState()).workingSettings;
  assert.equal(working.practiceRecords.length,1);
  assert.equal(working.practiceRecords[0].kind,"keyboard-test-f4b");
  assert.equal(working.practiceRecords[0].testType,"practice");
  assert.equal(working.practiceRecords[0].completed,true);
  assert.equal(working.practiceRecords[0].lines.length,6);
  assert.equal(working.practiceRecords[0].totals.errors,0,"Corrected error excluded from line score");
  assert.ok(sum(working.curriculum.current)>0);
  assert.ok(working.curriculum.current.some(sample=>sample.errors>0),"Corrected attempt retained in learning samples");
  assert.equal(working.curriculum.introduced,3,"Tests do not teach new keys");
  assert.deepEqual(await saved(),fixture,"Test does not autosave");
  // An aborted test retains timed key observations while remaining distinct from a completed result.
  await startTest("practice");
  let text=await target(0);await page.keyboard.type(text,{delay:5});await page.keyboard.press("Enter");
  const partial=(await target(1)).slice(0,3);
  for(const key of partial){await page.keyboard.type(key);await page.waitForTimeout(80);}
  await page.keyboard.press("Escape");assert.equal(await mode(),"menu");
  working=(await exportState()).workingSettings;
  assert.equal(working.practiceRecords.length,2);
  assert.equal(working.practiceRecords[1].completed,false);
  assert.equal(working.practiceRecords[1].lines.length,1);
  assert.ok(working.practiceRecords[1].partialAttempts.length>0);
  assert.ok(working.practiceRecords[1].partialObservations.length>0);
  await startTest("all-keys");
  const allTargets=await Promise.all(Array.from({length:6},(_,i)=>target(i)));
  assert.ok(allTargets.some(text=>/\d/.test(text)),"All-keys includes digits");
  assert.ok(allTargets.some(text=>/[^\w\s]/.test(text)),"All-keys includes punctuation");
  await page.screenshot({path:"docs/screenshots/faithful-test-all-keys.png",fullPage:true});
  assert.deepEqual(await finishLines(),allTargets);
  await choose("Return to Main Menu");
  working=(await exportState()).workingSettings;
  assert.equal(working.practiceRecords.length,3);
  assert.equal(working.practiceRecords[2].testType,"all-keys");
  assert.equal(working.practiceRecords[2].completed,true);
  assert.equal(working.curriculum.introduced,3);
  const beforeReports=structuredClone(working);
  await report("progress","p");
  const progressRows=await page.locator(".row").allTextContents();
  assert.equal(progressRows.filter(row=>row.slice(5,19).trim()==="Practice").length,1,"Only completed Practice test gets a report row");
  assert.equal(progressRows.filter(row=>row.slice(5,19).trim()==="All-keys").length,1);
  assert.ok(progressRows.some(row=>row.slice(5,19).trim()==="Session"));
  assert.ok(!progressRows.some(row=>row.slice(5,19).trim()==="History"));
  assert.ok(!(await screen()).includes("NaN"));
  await page.screenshot({path:"docs/screenshots/faithful-progress.png",fullPage:true});
  await page.keyboard.press("x");assert.equal(await attr("data-report-kind"),"speed");
  await page.screenshot({path:"docs/screenshots/faithful-speed-graph.png",fullPage:true});
  await page.keyboard.press("x");assert.equal(await attr("data-report-kind"),"accuracy");
  await page.screenshot({path:"docs/screenshots/faithful-accuracy-graph.png",fullPage:true});
  await page.setViewportSize({width:390,height:844});
  await page.waitForFunction(()=>document.documentElement.scrollWidth<=innerWidth);
  await page.screenshot({path:"docs/screenshots/faithful-report-mobile.png",fullPage:true});
  await exitReport();await page.setViewportSize({width:1040,height:780});
  assert.deepEqual((await exportState()).workingSettings,beforeReports,"Reports do not mutate working samples/results");
  await page.keyboard.press("q");await choose("Yes, save session to history");assert.equal(await mode(),"exited");
  const committed=await saved();
  assert.equal(committed.profiles[0].practiceRecords.length,3);
  assert.equal(sum(committed.profiles[0].curriculum.current),0);
  assert.ok(sum(committed.profiles[0].curriculum.saved)>0);
  await page.reload();assert.equal(await mode(),"menu");
  assert.equal((await exportState()).workingSettings.practiceRecords.length,3);
  await report("speed","s");await exitReport();
  await report("accuracy","a");await exitReport();
  await report("progress","p");
  const historicalRows=await page.locator(".row").allTextContents();
  assert.ok(historicalRows.some(row=>row.slice(5,19).trim()==="History"));
  assert.ok(!historicalRows.some(row=>row.slice(5,19).trim()==="Session"));
  await exitReport();
  await startTest("practice");await page.keyboard.type((await target(0)).slice(0,3),{delay:20});
  await page.keyboard.press("Escape");await page.keyboard.press("q");
  await choose("No, do not save to history");assert.equal(await mode(),"exited");
  assert.deepEqual(await saved(),committed,"Discard preserves saved tests and historical counters");
  assert.equal(await page.evaluate(key=>localStorage.getItem(key),OLD),"preserved-old-prototype");
  assert.deepEqual(errors,[],"No browser JavaScript errors");
  await context.close();
  console.log("PASS (Chrome): six-line Practice/All-keys tests, corrected errors, boundary keys, abort observations, summaries, read-only report cycling, current/history, save/reload/discard, narrow graphs and legacy namespace.");
}finally{
  if(browser)await browser.close();
  if(server.exitCode===null){const exited=once(server,"exit");server.kill();await exited;}
}
