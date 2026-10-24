import test from 'node:test';
import assert from 'node:assert/strict';
import {StudentSession,PROFILE_KEY} from '../dist/faithful-session.js';
import DATA from '../dist/welcome-data.js';
function storage(){return {raw:null,writes:0,getItem(key){return key===PROFILE_KEY?this.raw:null;},setItem(key,value){assert.equal(key,PROFILE_KEY);this.raw=value;this.writes++;}};}
test('fresh registration accepts Student as a real name without treating the placeholder as a duplicate',()=>{
 const store=storage(),session=new StudentSession(store);
 assert.equal(DATA.registration.title,'Registration');assert.equal(DATA.registration.prompt,'Please type your name');
 assert.equal(session.register('Student'),'');assert.equal(session.working.name,'Student');assert.equal(session.dirty,true);assert.equal(store.writes,0);
 assert.match(session.rename('Student'),/duplicates/,'Existing rename duplicate rule remains unchanged');
});
test('registered name stays pending until explicit save; discard returns to unnamed fresh-session state',()=>{
 const store=storage(),session=new StudentSession(store);
 assert.equal(session.register('New Student'),'');assert.equal(store.raw,null);session.discard();assert.equal(session.working.name,'Student');assert.equal(session.dirty,false);
 assert.equal(session.register('New Student'),'');assert.equal(session.commit(),'');assert.equal(store.writes,1);
 const loaded=new StudentSession(store);assert.equal(loaded.working.name,'New Student');assert.equal(loaded.dirty,false);
 assert.match(loaded.register('Replacement'),/new session/);assert.equal(loaded.working.name,'New Student');assert.equal(store.writes,1);
});
test('invalid or unreadable registration cannot change a profile or write storage',()=>{
 const store=storage(),session=new StudentSession(store);
 for(const name of ['', ' leading','Bad@Name','A'.repeat(26)])assert.match(session.register(name),/valid name/);
 assert.equal(session.dirty,false);assert.equal(session.working.name,'Student');assert.equal(store.writes,0);
 store.raw='broken';const corrupt=new StudentSession(store);assert.match(corrupt.register('Replacement'),/new session/);assert.equal(store.raw,'broken');assert.equal(corrupt.dirty,false);
});
