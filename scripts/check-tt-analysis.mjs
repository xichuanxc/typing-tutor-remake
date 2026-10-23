// Verify and render the machine-code-derived frame using project-local Chrome tooling.
import {chromium} from "playwright";
import assert from "node:assert/strict";
import {readFile} from "node:fs/promises";
import {resolve} from "node:path";
import {pathToFileURL} from "node:url";
const coverage=JSON.parse(await readFile("analysis/recovered/coverage.json","utf8"));
assert.equal(coverage.analyzed_procedures,377);
assert.equal(coverage.assembly_exports,coverage.analyzed_procedures);
assert.equal(coverage.pseudocode_exports,coverage.analyzed_procedures);
const menus=JSON.parse(await readFile("analysis/recovered/menus.json","utf8")).menus;
assert.equal(menus.length,8);
assert.deepEqual(menus[0].items.map(i=>i.label),["Lessons","Tests","Reports","Options","Game","Help","Quit"]);
assert.deepEqual(menus[1].items.map(i=>i.label),["Practice","Fingering","Keypad","Help"]);
const rows=(await readFile("analysis/recovered/main-menu-frame.txt","utf8")).replace(/\n$/, "").split("\n");
assert.equal(rows.length,25);
assert.ok(rows.every(row=>[...row].length===80));
const browser=await chromium.launch({channel:"chrome",headless:true});
try {
  const page=await browser.newPage({viewport:{width:1040,height:840}});
  const errors=[];page.on("pageerror",e=>errors.push(String(e)));
  await page.goto(pathToFileURL(resolve("analysis/recovered/main-menu-frame.html")).href);
  assert.equal(await page.locator("pre span").count(),2000);
  assert.equal(await page.locator("pre").innerText(),rows.join("\n"));
  const highlight=page.locator("pre span").nth(3*80);
  assert.equal(await highlight.evaluate(el=>getComputedStyle(el).color),"rgb(255, 255, 85)");
  assert.equal(await highlight.evaluate(el=>getComputedStyle(el).backgroundColor),"rgb(170, 0, 170)");
  await page.screenshot({path:"docs/screenshots/recovered-main-menu-frame.png",fullPage:true});
  assert.deepEqual(errors,[]);
  console.log("PASS: 377 paired exports, eight menus, 80×25 frame, Chrome rendering, original highlight colors; screenshot saved.");
} finally {await browser.close();}
