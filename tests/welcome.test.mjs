import test from 'node:test';
import assert from 'node:assert/strict';
import {readFileSync} from 'node:fs';
import {createHash} from 'node:crypto';
import DATA from '../dist/welcome-data.js';
import {WelcomeSequence,drawWelcome,shouldShowWelcome,welcomeNotes,WELCOME_MUSIC_MS} from '../dist/welcome.js';
import {StudentSession,PROFILE_KEY,LEGACY_KEY} from '../dist/faithful-session.js';
import {Grid} from '../dist/grid.js';
import {BIOS_TICK_MS} from '../dist/invaders.js';
function storage(entries={}){return {entries,writes:0,getItem(key){return this.entries[key]??null;},setItem(key,value){this.entries[key]=value;this.writes++;}};}
function completeTyping(){const welcome=new WelcomeSequence();welcome.start();let elapsed=0;while(welcome.phase==='typing'){elapsed+=BIOS_TICK_MS;welcome.advance(elapsed);}return {welcome,elapsed};}
test('welcome gate reads existing faithful/legacy profiles without writing or overriding warnings',()=>{
 const fresh=storage(),session=new StudentSession(fresh);assert.equal(shouldShowWelcome(fresh,session),true);
 assert.equal(fresh.writes,0);assert.equal(session.dirty,false);
 assert.equal(session.commit(),'');assert.equal(shouldShowWelcome(fresh,new StudentSession(fresh)),false);
 const legacy=storage({[LEGACY_KEY]:'legacy data'});assert.equal(shouldShowWelcome(legacy,new StudentSession(legacy)),false);assert.equal(legacy.writes,0);
 const corrupt=storage({[PROFILE_KEY]:'broken'}),broken=new StudentSession(corrupt);assert.equal(shouldShowWelcome(corrupt,broken),false);assert.ok(broken.warning);assert.equal(corrupt.entries[PROFILE_KEY],'broken');
 const denied={getItem(){throw Error('denied');}};assert.equal(shouldShowWelcome(denied,new StudentSession(denied)),false);
 assert.equal(shouldShowWelcome(denied,new StudentSession(storage())),false);
});
test('native startup title replay corrects III to IV and retains intentional uppercase W error',()=>{
 const {welcome}=completeTyping();assert.equal(welcome.phase,'logo');
 assert.equal(welcome.lines[0].typed.join(''),DATA.lines[0].expected);assert.ok(welcome.lines[0].errors.every(error=>!error));
 assert.equal(welcome.lines[1].typed.join(''),'With Letter Invaders (R)');assert.deepEqual(welcome.lines[1].errors,[true,...Array(23).fill(false)]);
 const events=welcome.drainEvents();assert.equal(events.filter(e=>e.type==='music').length,1);assert.ok(events.some(e=>e.type==='wrong'));
 assert.equal(welcome.drainEvents().length,0);
});
test('welcome respects native strictly greater centisecond wait and music completion boundary',()=>{
 const welcome=new WelcomeSequence();welcome.advance(500);assert.equal(welcome.phase,'ready');welcome.start();
 welcome.advance(BIOS_TICK_MS);assert.equal(welcome.index,0);welcome.advance(BIOS_TICK_MS*2);assert.equal(welcome.index,1);
 assert.throws(()=>welcome.advance(-1));assert.throws(()=>welcome.advance(NaN));
 const finished=completeTyping();finished.welcome.drainEvents();
 finished.welcome.advance(finished.elapsed+WELCOME_MUSIC_MS-1);assert.equal(finished.welcome.phase,'logo');
 finished.welcome.advance(finished.elapsed+WELCOME_MUSIC_MS);assert.equal(finished.welcome.phase,'done');assert.deepEqual(finished.welcome.drainEvents(),[{type:'done'}]);
 finished.welcome.advance(finished.elapsed+WELCOME_MUSIC_MS+100);assert.deepEqual(finished.welcome.drainEvents(),[]);
});
test('startup music is 64 native PIT tones with 303 ticks including rests',()=>{
 const notes=welcomeNotes();assert.equal(notes.filter(n=>n.frequency).length,64);assert.ok(notes.some(n=>!n.frequency));
 assert.ok(Math.abs(WELCOME_MUSIC_MS-303*BIOS_TICK_MS)<1e-8);
 assert.equal(DATA.titleKeyTone[1],7);assert.equal(Math.floor((7*182+5000)/10000),0);
 assert.equal(DATA.historyFile,'TT.HIS');assert.equal(DATA.profileBytes,1996);assert.equal(DATA.enumeratedSlots,8);
});
test('welcome uses original title, keyboard, logo, copyright and footer coordinates',()=>{
 const grid=new Grid(),welcome=new WelcomeSequence();drawWelcome(grid,welcome);
 assert.equal(grid.cells[2][26].char,'╒');assert.equal(grid.cells[12][13].char,'╒');
 assert.equal(grid.lines()[4].slice(30,49),DATA.lines[0].expected);
 const finished=completeTyping();drawWelcome(grid,finished.welcome);
 assert.equal(grid.lines()[5].slice(30,49),DATA.lines[0].expected);
 assert.equal(grid.cells[6][28].char,'↓');assert.equal(grid.cells[13][3].char,'╔');assert.equal(grid.cells[13][29].char,'╦');assert.equal(grid.cells[22][50].char,'╩');
 assert.equal(grid.lines()[21].slice(46,49),'(R)');assert.ok(grid.lines()[24].includes(DATA.prompt));
 DATA.logo.rows.forEach((row,i)=>assert.equal(grid.cells[14+row][33+DATA.logo.cols[i]].char,DATA.logo.chars[i]));
 assert.equal(grid.lines().length,25);assert.ok(grid.lines().every(line=>line.length===80));
});
test('welcome extraction is linked to retained assembly and reproducible resources',()=>{
 const receipt=JSON.parse(readFileSync('analysis/welcome/resources.json'));
 const sha=path=>createHash('sha256').update(readFileSync(path)).digest('hex');
 assert.equal(sha('dist/welcome-data.js'),receipt.output_sha256);assert.equal(sha('scripts/extract-welcome-data.py'),receipt.extractor_sha256);
 for(const row of receipt.functions)assert.equal(sha('analysis/recovered/'+row.address+'.asm'),row.sha256);
 assert.equal(receipt.music.notes,64);assert.equal(receipt.music.duration_ticks,303);
});
