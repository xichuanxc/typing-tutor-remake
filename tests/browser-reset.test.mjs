import test from 'node:test';
import assert from 'node:assert/strict';
import {clearBrowserData,PROFILE_KEY,LEGACY_KEY} from '../dist/faithful-session.js';
function store(values){return {values:new Map(Object.entries(values)),getItem(key){return this.values.get(key)??null;},removeItem(key){this.values.delete(key);}};}
test('explicit reset removes whole current and legacy saves and preserves unrelated origin data',()=>{
 const storage=store({[PROFILE_KEY]:JSON.stringify({profiles:[{name:'A',history:[1,2]},{name:'B'}],scores:[100]}),[LEGACY_KEY]:'prototype data',unrelated:'keep','type-tutor-remake.other':'keep too'});
 clearBrowserData(storage);assert.deepEqual(Object.fromEntries(storage.values),{unrelated:'keep','type-tutor-remake.other':'keep too'});
 clearBrowserData(storage);assert.deepEqual(Object.fromEntries(storage.values),{unrelated:'keep','type-tutor-remake.other':'keep too'});
});
test('reset can remove corrupted saves without parsing or importing them',()=>{
 const storage=store({[PROFILE_KEY]:'broken json',[LEGACY_KEY]:'also broken'});clearBrowserData(storage);assert.equal(storage.values.size,0);
});
test('reset reports blocked or ineffective removal rather than claiming success',()=>{
 const storage=store({[PROFILE_KEY]:'saved',[LEGACY_KEY]:'old'});storage.removeItem=()=>{throw Error('denied');};assert.throws(()=>clearBrowserData(storage));assert.equal(storage.getItem(PROFILE_KEY),'saved');
 storage.removeItem=()=>{};assert.throws(()=>clearBrowserData(storage),/not removed/);
 const partial=store({[PROFILE_KEY]:'saved',[LEGACY_KEY]:'old'}),remove=partial.removeItem.bind(partial);partial.removeItem=key=>{if(key===PROFILE_KEY)throw Error('denied');remove(key);};assert.throws(()=>clearBrowserData(partial));assert.equal(partial.getItem(PROFILE_KEY),'saved');
});
