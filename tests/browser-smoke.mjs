import {chromium} from "playwright";
import assert from "node:assert/strict";
import DATA from "../dist/original-data.js";
import {spawn} from "node:child_process";
import {mkdir,readFile} from "node:fs/promises";
import {once} from "node:events";
const PORT=8765,base="http://127.0.0.1:"+PORT,KEY="type-tutor-remake.faithful.v2",LEGACY="type-tutor-remake.v1";
const server=spawn("python3",["scripts/serve.py","--port",String(PORT)],{stdio:"ignore"});
let browser;
const wait=ms=>new Promise(r=>setTimeout(r,ms));
try{
  let ready=false;
  for(let i=0;i<50;i++){if(server.exitCode!==null)throw Error("Test server exited");try{if((await fetch(base)).ok){ready=true;break;}}catch{}await wait(100);}
  assert.ok(ready);assert.equal((await fetch(base+"/TT/TT.EXE")).status,404);
  browser=await chromium.launch({channel:"chrome",headless:true});
  const page=await browser.newPage({viewport:{width:1040,height:780}});
  const errors=[];page.on("pageerror",e=>errors.push(String(e)));
  // Legacy records must survive faithful-session changes without migration/relabeling.
  await page.addInitScript(({LEGACY})=>{if(!localStorage.getItem(LEGACY))localStorage.setItem(LEGACY,'{"sentinel":"v0.1 remains"}');},{LEGACY});
  await page.goto(base);await page.locator(".cell").last().waitFor();
  const mode=()=>page.locator("#terminal").getAttribute("data-mode");
  const menu=()=>page.locator("#terminal").getAttribute("data-menu");
  const choose=async label=>{await page.getByRole("option",{name:label,exact:true}).click();};
  const option=async label=>{if(await mode()!=="menu")await page.keyboard.press("Escape");if(await menu()!=="4"){if(await menu()!=="0")await page.keyboard.press("Escape");await page.keyboard.press("o");}await page.keyboard.press(label[0].toLowerCase());};
  const rows=await page.locator(".row").allTextContents();
  const expected=(await readFile("analysis/recovered/main-menu-frame.txt","utf8")).replace(/\n$/,"").split("\n");
  assert.deepEqual(rows,expected);
  const attrs=await page.locator('.row[data-row="3"] .cell').evaluateAll(cells=>cells.map(c=>c.dataset.attr));
  assert.deepEqual(attrs.slice(0,7),Array(7).fill("5e"));assert.equal(attrs[9],"5f");
  await mkdir("docs/screenshots",{recursive:true});
  await page.screenshot({path:"docs/screenshots/faithful-main-menu.png",fullPage:true});
  await page.keyboard.press("ArrowLeft");assert.equal(await page.locator("#terminal").getAttribute("data-selected"),"6");
  await page.keyboard.press("Space");assert.equal(await page.locator("#terminal").getAttribute("data-selected"),"0");
  await page.getByRole("button",{name:"Options",exact:true}).click();assert.equal(await menu(),"4");
  await page.getByRole("button",{name:"WPM",exact:true}).click();assert.equal(await mode(),"choice");
  await page.keyboard.press("Escape");
  // All submenu layouts and first-letter shortcuts.
  for(const [letter,index] of [["l",1],["t",2],["r",3],["o",4],["g",5]]){
    await page.keyboard.press(letter);assert.equal(await menu(),String(index));await page.keyboard.press("Escape");
  }
  await page.keyboard.press("o");
  await page.screenshot({path:"docs/screenshots/faithful-options-menu.png",fullPage:true});
  await page.keyboard.press("w");assert.equal(await mode(),"choice");
  assert.equal(await page.getByRole("option").count(),10);
  assert.equal(await page.getByRole("option", {selected:true}).getAttribute("aria-label")," 20 - 29");
  await page.keyboard.press("ArrowUp");await page.keyboard.press("ArrowUp");
  assert.equal(await page.getByRole("option",{selected:true}).getAttribute("aria-label"),"100+");
  await page.screenshot({path:"docs/screenshots/faithful-wpm-dialog.png",fullPage:true});
  await page.keyboard.press("Enter");assert.equal(await menu(),"4");
  assert.equal(await page.evaluate(key=>localStorage.getItem(key),KEY),null);
  await option("Time");assert.equal(await page.getByRole("option").count(),7);
  await page.keyboard.press("ArrowUp");await page.keyboard.press("Enter");
  await option("Drills");assert.equal(await page.getByRole("option").count(),4);
  await page.keyboard.press("ArrowDown");await page.keyboard.press("Enter");
  await option("Sound");await page.keyboard.press("ArrowDown");await page.keyboard.press("Enter");
  await option("Name");const input=page.getByLabel("Student name");
  await input.fill("Student");await page.keyboard.press("Enter");
  assert.ok((await page.locator(".row").allTextContents()).join("\n").includes("duplicates"));
  await input.fill("A".repeat(25));await page.keyboard.press("Enter");
  assert.ok((await page.locator('.row[data-row="0"]').textContent()).includes("A".repeat(25)));
  // Cancel a changed choice returns to Main Menu and never commits it.
  await option("Drills");await page.keyboard.press("ArrowDown");await page.keyboard.press("Escape");
  assert.equal(await menu(),"0");
  await page.keyboard.press("q");assert.equal(await mode(),"choice");
  await choose("Return to Main Menu");assert.equal(await mode(),"menu");
  assert.equal(await page.locator("#terminal").getAttribute("data-dirty"),"true");
  await page.keyboard.press("q");
  await page.screenshot({path:"docs/screenshots/faithful-quit-dialog.png",fullPage:true});
  await choose("Yes, save session to history");assert.equal(await mode(),"exited");
  let db=await page.evaluate(key=>JSON.parse(localStorage.getItem(key)),KEY),p=db.profiles[0];
  assert.equal(p.wpm,100);assert.equal(p.weekly,0);assert.equal(p.drills,15);assert.equal(p.sound,false);
  assert.equal(p.name,"A".repeat(25));
  assert.equal(await page.evaluate(key=>localStorage.getItem(key),LEGACY),'{"sentinel":"v0.1 remains"}');
  await page.keyboard.press("Enter");await option("WPM");assert.equal(await page.getByRole("option",{selected:true}).getAttribute("aria-label"),"100+");
  await page.keyboard.press("ArrowDown");await page.keyboard.press("Enter");
  await page.keyboard.press("Escape");await page.keyboard.press("q");
  await choose("No, do not save to history");await page.keyboard.press("Enter");
  await option("WPM");assert.equal(await page.getByRole("option",{selected:true}).getAttribute("aria-label"),"100+");
  await page.keyboard.press("Escape");await page.reload();
  await page.keyboard.press("o");await page.keyboard.press("t");
  assert.equal(await page.getByRole("option",{selected:true}).getAttribute("aria-label")," 1 -  2");
  await page.keyboard.press("Escape");
  await page.keyboard.press("o");await page.keyboard.press("i");assert.equal(await mode(),"reader");
  const firstIntro=(await page.locator(".row").allTextContents()).join("\n");
  assert.ok(firstIntro.includes("Welcome to"));assert.ok(firstIntro.includes("matches your goals"));
  assert.ok(!/TiANWEi|2000 Bug|winice/.test(firstIntro));
  await page.screenshot({path:"docs/screenshots/faithful-intro-first.png",fullPage:true});
  await page.keyboard.press("PageDown");await page.keyboard.press("PageUp");
  assert.equal((await page.locator(".row").allTextContents()).join("\n"),firstIntro);
  let introText="",introPages=0;
  while(await mode()==="reader"){
    const lines=await page.locator(".row").allTextContents();
    introText+=lines.slice(5,20).map(line=>line.slice(5,75)).join(" ");
    introPages++;assert.ok(introPages<=20,"Intro reader must finish");
    if(lines.join(" ").includes("Good luck!")){
      await page.screenshot({path:"docs/screenshots/faithful-intro-last.png",fullPage:true});
    }
    await page.keyboard.press("Enter");
  }
  assert.equal(introText.replace(/\s/g,""),DATA.help[0].join("").replace(/\s/g,""));
  console.log("Verified Intro: 17 source parts, "+introPages+" fitted reader screens, complete text and backward/forward navigation.");
  assert.equal(await menu(),"4");assert.equal(await page.locator("#terminal").getAttribute("data-dirty"),"false");
  await page.keyboard.press("Escape");await page.keyboard.press("o");await page.keyboard.press("i");
  await page.keyboard.press("Escape");assert.equal(await menu(),"0");
  await page.keyboard.press("o");await page.keyboard.press("h");assert.equal(await mode(),"reader");
  const help=(await page.locator(".row").allTextContents()).join("\n");assert.ok(help.includes("WPM"));assert.ok(help.includes("Time"));
  await page.keyboard.press("Escape");
  await page.keyboard.press("l");await page.keyboard.press("p");if(await mode()==="guide")await page.keyboard.press("Enter");assert.equal(await mode(),"practice");
  assert.ok((await page.locator(".row").allTextContents()).join("\n").includes("Current Focus Keys"));
  await page.keyboard.press("Escape");
  await page.keyboard.press("q");await choose("No, do not save to history");await page.keyboard.press("Enter");
  await page.waitForTimeout(5200);
  assert.ok((await page.locator(".row").allTextContents()).join("\n").includes("There are six menus"));
  await page.screenshot({path:"docs/screenshots/faithful-idle-help.png",fullPage:true});
  await page.setViewportSize({width:390,height:844});
  await page.waitForFunction(()=>document.documentElement.scrollWidth<=innerWidth);
  assert.ok(await page.evaluate(()=>document.documentElement.scrollWidth<=innerWidth));
  await page.screenshot({path:"docs/screenshots/faithful-mobile.png",fullPage:true});
  const download=page.waitForEvent("download");await page.getByRole("button",{name:"Export browser data"}).click();
  assert.equal((await download).suggestedFilename(),"typing-tutor-browser-data.json");
  await page.locator("#terminal").focus();
  // Save failures keep the session working. No false exit.
  await page.keyboard.press("o");await page.keyboard.press("d");await page.keyboard.press("ArrowDown");await page.keyboard.press("Enter");
  await page.keyboard.press("Escape");await page.keyboard.press("q");
  await page.evaluate(()=>{Storage.prototype.setItem=function(){throw Error("test denied");};});
  await choose("Yes, save session to history");assert.equal(await mode(),"choice");
  assert.ok((await page.locator(".row").allTextContents()).join("\n").includes("could not be saved"));
  await choose("Return to Main Menu");
  await page.keyboard.press("q");await choose("No, do not save to history");
  assert.deepEqual(errors,[]);
  console.log("PASS (Chrome): recovered frame, all student menus, horizontal/list navigation, exact Options, cancel/save/discard/reload, names, complete verified Intro/pagination, HLP, idle panel, failure retention, legacy preservation, export, narrow viewport; no JS errors.");
}finally{
  if(browser)await browser.close();
  if(server.exitCode===null){const exited=once(server,"exit");server.kill();await exited;}
}
