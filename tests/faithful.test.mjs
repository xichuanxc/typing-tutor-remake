import test from "node:test";
import assert from "node:assert/strict";
import {StudentSession,PROFILE_KEY,LEGACY_KEY,DEFAULT_PROFILE,validName} from "../dist/faithful-session.js";
import {Grid,wrap,glyph,choiceLayout} from "../dist/grid.js";
import DATA from "../dist/original-data.js";
function memory(initial={}){const map=new Map(Object.entries(initial));return {map,getItem:key=>map.get(key)??null,setItem:(key,value)=>map.set(key,value)};}
test("working changes never autosave; explicit commit preserves the legacy store",()=>{
  const store=memory({[LEGACY_KEY]:'{"old":"untouched"}'}),s=new StudentSession(store);
  s.change("wpm",100);s.change("weekly",6);s.change("drills",20);s.change("sound",false);
  assert.equal(store.getItem(PROFILE_KEY),null);assert.equal(s.dirty,true);
  assert.equal(s.commit(),"");assert.equal(s.dirty,false);
  assert.deepEqual(new StudentSession(store).working,s.working);
  assert.equal(store.getItem(LEGACY_KEY),'{"old":"untouched"}');
});
test("discard restores saved settings; a later session reads only the committed profile",()=>{
  const store=memory(),s=new StudentSession(store);s.change("wpm",30);s.commit();
  s.change("wpm",50);s.rename("Changed");s.discard();
  assert.equal(s.working.wpm,30);assert.equal(s.working.name,"Student");assert.equal(s.dirty,false);
  assert.equal(new StudentSession(store).working.wpm,30);
});
test("invalid settings are rejected; unchanged values do not mark a clean session dirty",()=>{
  const s=new StudentSession(memory());s.change("wpm",20);assert.equal(s.dirty,false);
  for(const [key,value] of [["wpm",25],["weekly",7],["drills",1],["sound",1]])assert.throws(()=>s.change(key,value));
  s.change("wpm",30);s.change("wpm",20);assert.equal(s.dirty,true);
});
test("name constraints and case-sensitive duplicates follow the recovered editor",()=>{
  assert.ok(validName("A".repeat(25)));assert.equal(validName("A".repeat(26)),false);
  for(const name of [""," space","-dash","é","user<script>"])assert.equal(validName(name),false);
  for(const name of ["A. Smith","O'Neil","Jean-Luc","User, 2"])assert.ok(validName(name));
  const db={version:2,activeId:"student-1",profiles:[{...DEFAULT_PROFILE},{...DEFAULT_PROFILE,id:"student-2",name:"Alex"}]};
  const s=new StudentSession(memory({[PROFILE_KEY]:JSON.stringify(db)}));
  assert.ok(s.rename("Alex"));assert.ok(s.rename("Student"));assert.equal(s.rename("alex"),"");
});
test("storage failure and conflicting writes preserve working settings and saved values",()=>{
  const store=memory(),s=new StudentSession(store);s.change("drills",15);
  store.setItem=()=>{throw Error("denied");};
  assert.ok(s.commit());assert.equal(s.dirty,true);assert.equal(s.working.drills,15);assert.equal(s.saved.drills,10);
  const other=memory(),a=new StudentSession(other),b=new StudentSession(other);
  a.change("wpm",30);assert.equal(a.commit(),"");b.change("wpm",50);
  assert.match(b.commit(),/another tab/);assert.equal(new StudentSession(other).working.wpm,30);
});
test("corrupt saved data is retained and cannot be overwritten by a normal save",()=>{
  const store=memory({[PROFILE_KEY]:'{"version":999}'}),s=new StudentSession(store);
  assert.ok(s.warning);s.change("wpm",30);assert.ok(s.commit());assert.equal(store.getItem(PROFILE_KEY),'{"version":999}');
});
test("grid dimensions, CP437 arrows and choice geometry match the recovered shell",()=>{
  const grid=new Grid();assert.equal(grid.lines().length,25);assert.ok(grid.lines().every(l=>l.length===80));
  grid.box(1,1,4,6,0x2f);assert.equal(grid.cells[1][1].char,"╒");assert.equal(grid.cells[2][1].char,"│");
  assert.equal(glyph(24),"↑");assert.equal(glyph(25),"↓");assert.equal(glyph(205),"═");assert.equal(glyph(186),"║");
  const layout=choiceLayout(10,9,DATA.prompts.wpm);assert.equal(layout.top,2);assert.equal(layout.listLeft,34);
  assert.ok(layout.listBottom<=23);
  assert.deepEqual(wrap("one two three",7),["one two","three"]);
});
test("resource choices and HLP substitution remain faithful to the audited records",()=>{
  assert.equal(DATA.menus.length,6);assert.equal(DATA.choices.wpm.length,10);
  assert.deepEqual(DATA.choices.drills,[5,10,15,20]);assert.equal(DATA.choices.weekly_time.length,7);
  assert.ok(DATA.help[0].some(t=>t.includes("'ASDF'")&&t.includes("'JKL;'")));
  assert.ok(!DATA.help.flat().some(t=>t.includes("'*'")||t.includes("'#'")));
});
