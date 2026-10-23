// Project-local Playwright controls installed Chrome using a fresh test profile.
import { chromium } from "playwright";
import assert from "node:assert/strict";
import { spawn } from "node:child_process";
import { mkdir } from "node:fs/promises";
import { once } from "node:events";

const port = 8766, base = `http://127.0.0.1:${port}/prototype/`;
const server = spawn("python3", ["scripts/serve.py", "--port", String(port)], {stdio:["ignore","pipe","pipe"]});
let browser;
try {
  let ready = false;
  for(let i=0;i<50;i++) {
    if(server.exitCode !== null) throw new Error("Test server exited");
    try { if((await fetch(base)).ok){ready=true;break;} } catch {}
    await new Promise(resolve=>setTimeout(resolve,100));
  }
  assert.ok(ready,"Server ready");
  assert.equal((await fetch(base+"/TT/TT.EXE")).status,404);
  browser=await chromium.launch({channel:"chrome",headless:true});
  const page=await browser.newPage({viewport:{width:1280,height:960}});
  const errors=[];
  page.on("pageerror",error=>errors.push(String(error)));
  await page.goto(base);
  await page.getByRole("heading",{name:"Make the keyboard second nature."}).waitFor();
  await page.keyboard.press("o");
  await page.getByLabel("Your name").fill("Practice Tester");
  await page.getByLabel("Drills per lesson").fill("1");
  await page.getByRole("button",{name:"Save options"}).click();
  assert.equal(await page.locator("#student").innerText(),"Practice Tester");
  await page.keyboard.press("l");
  let line=await page.locator(".line").getAttribute("aria-label");
  await page.keyboard.type("x");
  assert.equal(await page.locator(".char.miss").count(),1);
  await page.keyboard.press("Backspace");
  assert.equal(await page.locator(".char.miss").count(),0);
  await page.keyboard.type(line,{delay:5});
  await page.keyboard.press("Enter");
  await page.getByText("NEXT LESSON UNLOCKED",{exact:true}).waitFor();
  let data=await page.evaluate(()=>JSON.parse(localStorage.getItem("type-tutor-remake.v1")));
  assert.equal(data.history.length,1);assert.equal(data.history[0].attempts,30);
  assert.equal(data.history[0].correct,29);assert.equal(data.stage,1);
  await page.keyboard.press("Escape");
  await page.keyboard.press("l");
  await page.keyboard.type("a");
  await page.keyboard.press("Escape");
  await page.getByRole("heading",{name:"Practice paused."}).waitFor();
  await page.getByRole("button",{name:"Resume [Enter]",exact:true}).click();
  await page.evaluate(()=>window.dispatchEvent(new Event("blur")));
  await page.getByRole("heading",{name:"Practice paused."}).waitFor();
  await page.getByRole("button",{name:"Discard exercise"}).click();
  await page.keyboard.press("r");
  assert.equal(await page.locator("tbody").first().locator("tr").count(),1);
  const downloadPromise=page.waitForEvent("download");
  await page.getByRole("button",{name:"Export progress"}).click();
  assert.equal((await downloadPromise).suggestedFilename(),"type-tutor-progress.json");
  await page.reload();
  assert.equal(await page.locator("#student").innerText(),"Practice Tester");
  await page.keyboard.press("t");
  for(let i=0;i<3;i++) {
    line=await page.locator(".line").getAttribute("aria-label");
    await page.keyboard.type(line,{delay:1});
    await page.keyboard.press(i===0?"Space":"Enter");
  }
  await page.getByText("EXERCISE COMPLETE",{exact:true}).waitFor();
  data=await page.evaluate(()=>JSON.parse(localStorage.getItem("type-tutor-remake.v1")));
  assert.equal(data.history.length,2);assert.equal(data.history[1].mode,"test");assert.equal(data.stage,1);
  await page.keyboard.press("Escape");
  await page.keyboard.press("ArrowUp");
  await page.keyboard.press("Enter");
  await page.locator("#typing-area").waitFor();
  await page.keyboard.press("Escape");
  await page.keyboard.press("Escape");
  await mkdir("docs/screenshots",{recursive:true});
  await page.screenshot({path:"docs/screenshots/prototype-main-menu.png",fullPage:true});
  await page.keyboard.press("l");
  await page.keyboard.type("asdf",{delay:120});
  await page.waitForTimeout(1000);
  await page.screenshot({path:"docs/screenshots/prototype-practice-lesson.png",fullPage:true});
  await page.setViewportSize({width:390,height:844});
  assert.ok(await page.evaluate(()=>document.documentElement.scrollWidth<=innerWidth));
  await page.screenshot({path:"docs/screenshots/prototype-mobile-lesson.png",fullPage:true});
  assert.deepEqual(errors,[]);
  console.log("PASS (Google Chrome): lessons, corrections, results, progression, tests, pause/discard, reload, reports/export, keyboard navigation, mobile layout, reference isolation; no JavaScript errors.");
} finally {
  if(browser) await browser.close();
  const exited=once(server,"exit");server.kill();await exited;
}
