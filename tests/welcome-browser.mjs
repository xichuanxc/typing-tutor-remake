import {chromium} from 'playwright';
import assert from 'node:assert/strict';
import {spawn} from 'node:child_process';
import {once} from 'node:events';
import {mkdir} from 'node:fs/promises';
const base=process.env.WELCOME_BASE||'http://127.0.0.1:8775',KEY='type-tutor-remake.faithful.v2',LEGACY='type-tutor-remake.v1';
const server=process.env.WELCOME_BASE?null:spawn('python3',['scripts/serve.py','--port','8775'],{stdio:'ignore'});
let browser;
try{
 for(let i=0;i<50;i++){if(server&&server.exitCode!==null)throw Error('Welcome server exited');try{if((await fetch(base)).ok)break;}catch{}await new Promise(r=>setTimeout(r,100));}
 browser=await chromium.launch({channel:'chrome',headless:true,args:['--autoplay-policy=document-user-activation-required',...(process.env.WELCOME_HOST_MAP?['--host-resolver-rules='+process.env.WELCOME_HOST_MAP]:[])]});
 const errors=[];
 async function open(fixture){
  const context=await browser.newContext({viewport:{width:1040,height:780}}),page=await context.newPage();page.on('pageerror',e=>errors.push(String(e)));
  await page.addInitScript(({KEY,LEGACY,fixture})=>{
   if(fixture==='legacy')localStorage.setItem(LEGACY,'{"sentinel":"keep"}');
   if(fixture==='corrupt')localStorage.setItem(KEY,'broken');
   if(fixture==='denied')Object.defineProperty(window,'localStorage',{get(){throw Error('denied');}});
   window.__contexts=[];window.__tones=[];
   const Base=window.AudioContext,create=Base.prototype.createOscillator;
   Base.prototype.createOscillator=function(){const voice=create.call(this),info={frequencies:[],stops:[]},set=voice.frequency.setValueAtTime.bind(voice.frequency),stop=voice.stop.bind(voice);
    voice.frequency.setValueAtTime=(f,t)=>{info.frequencies.push(f);return set(f,t);};voice.stop=t=>{info.stops.push(t??null);return stop(t);};window.__tones.push(info);return voice;};
   window.AudioContext=new Proxy(Base,{construct(target,args){const result=Reflect.construct(target,args);window.__contexts.push(result);return result;}});
  },{KEY,LEGACY,fixture});
  await page.clock.install({time:new Date('2026-10-24T00:00:00Z')});await page.goto(base);await page.locator('.cell').last().waitFor();
  await page.clock.pauseAt(await page.evaluate(()=>Date.now())+1000);return {context,page};
 }
 const {context,page}=await open(),mode=()=>page.locator('#terminal').getAttribute('data-mode'),phase=()=>page.locator('#terminal').getAttribute('data-welcome-phase');
 assert.equal(await mode(),'welcome');assert.equal(await phase(),'ready');assert.equal(await page.evaluate(()=>window.__contexts.length),0);
 assert.equal(await page.evaluate(key=>localStorage.getItem(key),KEY),null);assert.equal(await page.locator('#terminal').getAttribute('data-dirty'),'false');
 await page.keyboard.press('Enter');await page.clock.runFor(1000);assert.equal(await phase(),'typing');
 await mkdir('docs/screenshots',{recursive:true});await page.screenshot({path:'docs/screenshots/welcome-typing.png',fullPage:true});
 await page.clock.runFor(7000);assert.equal(await phase(),'logo');
 await page.waitForFunction(()=>window.__contexts[0]?.state==='running');
 assert.equal(await page.evaluate(()=>window.__tones.filter(t=>t.frequencies.length===64).length),1);
 const rows=await page.locator('.row').allTextContents();assert.equal(rows[5].slice(30,49),'Typing Tutor (R) IV');assert.equal(rows[8].slice(28,52),'With Letter Invaders (R)');assert.equal(rows[6][28],'↓');
 await page.screenshot({path:'docs/screenshots/welcome-logo.png',fullPage:true});
 await page.setViewportSize({width:390,height:740});assert.ok(await page.locator('#terminal').isVisible());await page.setViewportSize({width:1040,height:780});
 const rms=await page.evaluate(async()=>{
  const {GameAudio}=await import('./game-audio.js'),{welcomeNotes}=await import('./welcome.js');
  const offline=new OfflineAudioContext(1,22050,22050),sound=new GameAudio(()=>offline);sound.startNotes(welcomeNotes(),'welcome');
  const samples=(await offline.startRendering()).getChannelData(0);return Math.sqrt(samples.reduce((s,v)=>s+v*v,0)/samples.length);
 });assert.ok(rms>.01&&rms<.1);
 await page.clock.runFor(20000);assert.equal(await mode(),'registration');assert.equal(await page.evaluate(key=>localStorage.getItem(key),KEY),null);
 assert.equal(await page.locator('#terminal').getAttribute('data-dirty'),'false');
 assert.equal(await page.evaluate(()=>window.__tones.find(t=>t.frequencies.length===64).stops.length),2);
 await page.keyboard.press('Enter');assert.equal(await mode(),'registration');assert.match(await page.locator('#screen-text').textContent(),/Please enter/);
 await page.locator('#name-entry').fill('Welcome Student');await page.keyboard.press('Enter');assert.equal(await mode(),'menu');
 assert.equal(await page.locator('#terminal').getAttribute('data-dirty'),'true');
 await page.keyboard.press('q');await page.getByRole('option',{name:'Yes, save session to history',exact:true}).click();
 const saved=await page.evaluate(key=>localStorage.getItem(key),KEY);assert.ok(saved);
 await page.reload();await page.locator('.cell').last().waitFor();assert.equal(await mode(),'menu');assert.equal(await page.evaluate(()=>window.__contexts.length),0);assert.equal(await page.evaluate(key=>localStorage.getItem(key),KEY),saved);
 await context.close();
 for(const fixture of ['legacy','corrupt','denied']){
  const current=await open(fixture);assert.equal(await current.page.locator('#terminal').getAttribute('data-mode'),'menu');assert.equal(await current.page.evaluate(()=>window.__contexts.length),0);
  if(fixture==='corrupt'){assert.match(await current.page.locator('#session-note').textContent(),/could not be read/);assert.equal(await current.page.evaluate(key=>localStorage.getItem(key),KEY),'broken');}
  if(fixture==='legacy')assert.equal(await current.page.evaluate(key=>localStorage.getItem(key),LEGACY),'{"sentinel":"keep"}');
  await current.context.close();
 }
 const skipped=await open();await skipped.page.keyboard.press('Escape');assert.equal(await skipped.page.locator('#terminal').getAttribute('data-mode'),'registration');assert.equal(await skipped.page.evaluate(()=>window.__contexts.length),0);
 await skipped.page.locator('#name-entry').fill('Student');await skipped.page.keyboard.press('Enter');assert.equal(await skipped.page.locator('#terminal').getAttribute('data-mode'),'menu');
 await skipped.page.keyboard.press('q');await skipped.page.getByRole('option',{name:'No, do not save to history',exact:true}).click();await skipped.page.keyboard.press('Enter');assert.equal(await skipped.page.locator('#terminal').getAttribute('data-mode'),'registration');
 await skipped.context.close();
 const clicked=await open();await clicked.page.getByRole('button',{name:'Play welcome',exact:true}).click();await clicked.page.clock.runFor(8000);assert.equal(await clicked.page.locator('#terminal').getAttribute('data-welcome-phase'),'logo');
 await clicked.page.getByRole('button',{name:'Continue to registration',exact:true}).click();assert.equal(await clicked.page.locator('#terminal').getAttribute('data-mode'),'registration');
 assert.equal(await clicked.page.evaluate(()=>window.__tones.find(t=>t.frequencies.length===64).stops.length),2);
 await clicked.page.clock.runFor(30000);assert.equal(await clicked.page.locator('#terminal').getAttribute('data-mode'),'registration');
 await clicked.page.keyboard.press('Escape');assert.equal(await clicked.page.locator('#terminal').getAttribute('data-mode'),'exited');await clicked.page.keyboard.press('Enter');assert.equal(await clicked.page.locator('#terminal').getAttribute('data-mode'),'registration');
 await clicked.page.screenshot({path:'docs/screenshots/startup-registration.png',fullPage:true});await clicked.context.close();
 assert.deepEqual(errors,[]);console.log('PASS Chrome fresh-user welcome: gesture activation, native title correction/logo,64-note music, waveform RMS='+rms.toFixed(4)+', auto-completion to Registration, empty-name validation, Student placeholder registration, Escape/Begin again, keyboard/click skip, saved/legacy/corrupt/unavailable storage gates, no welcome writes or page errors.');
}finally{if(browser)await browser.close();if(server&&server.exitCode===null){const ended=once(server,'exit');server.kill();await ended;}}
