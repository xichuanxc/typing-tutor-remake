import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {spawn} from 'node:child_process';
import {once} from 'node:events';
import {readFile,mkdir} from 'node:fs/promises';
const base=process.env.RESET_BASE||'http://127.0.0.1:8776',KEY='type-tutor-remake.faithful.v2',LEGACY='type-tutor-remake.v1';
const fixture={version:2,activeId:'student-1',profiles:[{id:'student-1',name:'Student',wpm:20,weekly:1,drills:5,sound:false},{id:'student-2',name:'Other',wpm:30,weekly:2,drills:10,sound:true}],gameScores:[[],[]]},raw=JSON.stringify(fixture);
const server=process.env.RESET_BASE?null:spawn('python3',['scripts/serve.py','--port','8776'],{stdio:'ignore'});let browser;
try{
 for(let i=0;i<50;i++){if(server&&server.exitCode!==null)throw Error('Reset server exited');try{if((await fetch(base)).ok)break;}catch{}await new Promise(r=>setTimeout(r,100));}
 browser=await chromium.launch({channel:'chrome',headless:true,args:process.env.RESET_HOST_MAP?['--host-resolver-rules='+process.env.RESET_HOST_MAP]:[]});
 const errors=[],dialogs=[];
 async function open(failure){
  const context=await browser.newContext({acceptDownloads:true,viewport:{width:1040,height:780}}),page=await context.newPage();
  page.on('pageerror',e=>errors.push(String(e)));page.on('dialog',d=>{dialogs.push(d.type());d.dismiss();});
  await page.addInitScript(({KEY,LEGACY,raw,failure})=>{
   if(!sessionStorage.getItem('reset-test-seeded')){
    localStorage.setItem(KEY,failure==='corrupt'?'broken':raw);localStorage.setItem(LEGACY,'legacy sentinel');localStorage.setItem('unrelated','keep me');sessionStorage.setItem('reset-test-seeded','yes');
   }
   if(failure==='remove'){const remove=Storage.prototype.removeItem;Storage.prototype.removeItem=function(key){if(key===KEY)throw Error('denied');return remove.call(this,key);};}
   if(failure==='blocked')Object.defineProperty(window,'localStorage',{get(){throw Error('denied');}});
  },{KEY,LEGACY,raw,failure});
  await page.goto(base);await page.locator('.cell').last().waitFor();return {context,page};
 }
 const {context,page}=await open(),mode=()=>page.locator('#terminal').getAttribute('data-mode'),dialog=page.getByRole('dialog',{name:'Reset all Typing Tutor data?',exact:true});
 // Include an unsaved change in the backup; reset must suppress only its own unload prompt.
 await page.keyboard.press('o');await page.keyboard.press('n');await page.locator('#name-entry').fill('Unsaved Name');await page.keyboard.press('Enter');
 assert.equal(await page.locator('#terminal').getAttribute('data-dirty'),'true');
 const cells=await page.locator('#screen-text').textContent();
 await page.getByRole('button',{name:'Reset all Typing Tutor data',exact:true}).click();await dialog.waitFor();
 assert.equal(await page.getByRole('button',{name:'Cancel',exact:true}).evaluate(el=>el===document.activeElement),true);
 await page.keyboard.press('Escape');assert.equal(await dialog.isVisible(),false);assert.equal(await page.locator('#screen-text').textContent(),cells);
 assert.equal(await page.evaluate(key=>localStorage.getItem(key),KEY),raw);assert.equal(await page.locator('#terminal').getAttribute('data-dirty'),'true');
 await page.getByRole('button',{name:'Reset all Typing Tutor data',exact:true}).click();await page.getByRole('button',{name:'Cancel',exact:true}).click();assert.equal(await dialog.isVisible(),false);
 await page.getByRole('button',{name:'Reset all Typing Tutor data',exact:true}).click();
 const pending=page.waitForEvent('download');await page.getByRole('button',{name:'Export first',exact:true}).click();const download=await pending;
 const backup=JSON.parse(await readFile(await download.path(),'utf8'));assert.equal(backup.faithfulSaved,raw);assert.equal(backup.earlierPrototype,'legacy sentinel');assert.equal(backup.workingSettings.name,'Unsaved Name');assert.equal(await dialog.isVisible(),true);
 assert.equal(await page.evaluate(key=>localStorage.getItem(key),KEY),raw);
 await mkdir('docs/screenshots',{recursive:true});await page.screenshot({path:'docs/screenshots/reset-confirmation.png',fullPage:true});
 await page.setViewportSize({width:390,height:740});assert.ok(await page.getByRole('button',{name:'Clear data',exact:true}).isVisible());await page.waitForFunction(()=>document.querySelector('#viewport').getBoundingClientRect().right<=innerWidth);assert.ok(await page.evaluate(()=>document.documentElement.scrollWidth<=innerWidth));
 await Promise.all([page.waitForEvent('domcontentloaded'),page.getByRole('button',{name:'Clear data',exact:true}).click()]);await page.locator('.cell').last().waitFor();
 assert.equal(await mode(),'welcome');assert.equal(await page.locator('#terminal').getAttribute('data-welcome-phase'),'ready');assert.equal(await page.locator('#terminal').getAttribute('data-dirty'),'false');
 assert.deepEqual(await page.evaluate(({KEY,LEGACY})=>[localStorage.getItem(KEY),localStorage.getItem(LEGACY),localStorage.getItem('unrelated')],{KEY,LEGACY}),[null,null,'keep me']);
 assert.deepEqual(dialogs,[],'Confirmed reset must not open a second beforeunload confirmation');await context.close();
 for(const failure of ['remove','blocked','corrupt']){
  const {context,page}=await open(failure);await page.getByRole('button',{name:'Reset all Typing Tutor data',exact:true}).click();
  if(failure==='blocked'){
   await page.getByRole('button',{name:'Export first',exact:true}).click();assert.match(await page.locator('#reset-error').textContent(),/could not be exported/);
  }
  if(failure==='corrupt'){
   await Promise.all([page.waitForEvent('domcontentloaded'),page.getByRole('button',{name:'Clear data',exact:true}).click()]);await page.locator('.cell').last().waitFor();assert.equal(await page.locator('#terminal').getAttribute('data-mode'),'welcome');
  }else{
   await page.getByRole('button',{name:'Clear data',exact:true}).click();assert.match(await page.locator('#reset-error').textContent(),/could not be completed/);assert.ok(await page.getByRole('dialog').isVisible());
   if(failure==='remove')assert.equal(await page.evaluate(key=>localStorage.getItem(key),KEY),raw);
   await page.getByRole('button',{name:'Cancel',exact:true}).click();assert.equal(await page.locator('#terminal').getAttribute('data-mode'),'menu');
  }
  await context.close();
 }
 assert.deepEqual(errors,[]);assert.deepEqual(dialogs,[]);
 console.log('PASS Chrome reset: Cancel/Escape preserve saved and unsaved data; Export first downloads current/legacy/working backup; clear removes both keys, preserves unrelated storage, discards dirty session without unload prompt and reloads welcome; corrupt saves reset; blocked/partial failure stays open; narrow dialog; no page errors.');
}finally{if(browser)await browser.close();if(server&&server.exitCode===null){const ended=once(server,'exit');server.kill();await ended;}}
