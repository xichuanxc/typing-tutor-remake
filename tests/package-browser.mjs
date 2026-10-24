import {chromium} from "playwright";
import assert from "node:assert/strict";
import {spawn,execFileSync} from "node:child_process";
import {once} from "node:events";
import {rm} from "node:fs/promises";
const archive="artifacts/typing-tutor-remake-v0.2.0-web.zip";
const root=execFileSync("python3",["-c","from pathlib import Path; import tempfile,zipfile; Path('.runtime').mkdir(exist_ok=True); root=Path(tempfile.mkdtemp(prefix='deployment-check-',dir='.runtime')); z=zipfile.ZipFile('"+archive+"'); assert not any(n.startswith('prototype/') for n in z.namelist()); z.extractall(root); z.extractall(root/'typing-tutor-remake'); print(root)"]).toString().trim();
const base="http://127.0.0.1:8773",server=spawn("python3",["-m","http.server","8773","--bind","127.0.0.1","--directory",root],{stdio:"ignore"});
let browser;
try{
 for(let i=0;i<50;i++){
  if(server.exitCode!==null)throw Error("Static test server exited");
  try{if((await fetch(base)).ok)break;}catch{}
  await new Promise(r=>setTimeout(r,100));
 }
 browser=await chromium.launch({channel:"chrome",headless:true});
 const page=await browser.newPage(),errors=[];page.on("pageerror",e=>errors.push(String(e)));
 for(const path of ["/","/typing-tutor-remake/"]){
  await page.goto(base+path);await page.locator(".cell").last().waitFor();
  assert.equal(await page.locator("#terminal").getAttribute("data-mode"),"welcome");
  await page.keyboard.press("Escape");
  assert.equal(await page.locator("#terminal").getAttribute("data-mode"),"menu");
  assert.equal((await fetch(base+path+"TT/TT.EXE")).status,404);
  assert.equal((await fetch(base+path+"analysis/evidence-index.json")).status,404);
  assert.equal((await (await fetch(base+path+"CNAME")).text()).trim(),"tt.xcstudio.dev");
  assert.ok((await (await fetch(base+path+"LICENSE")).text()).startsWith("MIT License"));
  await page.keyboard.press("o");await page.keyboard.press("i");
  const text=(await page.locator(".row").allTextContents()).join("\n");
  assert.match(text,/Page 1 \/ 7/);assert.ok(text.includes("matches your goals"));assert.ok(!text.includes("TiANWEi"));
  await page.keyboard.press("Escape");await page.keyboard.press("t");await page.keyboard.press("d");
  await page.locator("#disk-files").setInputFiles({name:"CHECK.TXT",mimeType:"text/plain",buffer:Buffer.from("A simple typing test.")});
  await page.getByRole("option",{name:"CHECK.TST",exact:true}).click();
  await page.waitForFunction(()=>document.querySelector("#terminal").dataset.mode==="disk-test");
  assert.match(await page.locator("#terminal").getAttribute("data-disk-target"),/A simple typing test/);
  await page.keyboard.press("Escape");
  await page.keyboard.press("q");await page.getByRole("option",{name:"No, do not save to history",exact:true}).click();
  assert.equal(await page.getByRole("link",{name:"Earlier typing prototype"}).count(),0);
  assert.equal((await fetch(base+path+"prototype/")).status,404);
 }
 assert.deepEqual(errors,[]);
 console.log("PASS extracted ZIP in installed Chrome: root and project-path modules, original Intro, local Disk test/hash, prototype exclusion, license/domain files and excluded private paths; no page errors.");
}finally{
 if(browser)await browser.close();
 if(server.exitCode===null){const ended=once(server,"exit");server.kill();await ended;}
 await rm(root,{recursive:true,force:true});
}
