import test from "node:test";
import assert from "node:assert/strict";
import {readFileSync} from "node:fs";
import {createHash} from "node:crypto";
import {createCurriculum} from "../dist/curriculum.js";
import D from "../dist/curriculum-data.js";
import K from "../dist/keypad-data.js";
import {FingeringReview,drawFingering} from "../dist/fingering.js";
import {Grid} from "../dist/grid.js";
import {LineInput} from "../dist/practice.js";
import {drawKeypad,drawKeypadIntro,drawKeypadTutorial,drawKeypadActivity,drawKeypadSummary} from "../dist/keypad-screen.js";
const char=(g,r,c)=>g.cells[r][c].char;
const attr=(g,r,c)=>g.cells[r][c].attr;
test("extracted keypad/fingering resources match original identity, positions and choices",()=>{
 assert.equal(K.keys,"4567891230.+");assert.deepEqual(K.bootstrap,{introduced:66,pending:1});
 assert.equal(K.positions.length,12);assert.deepEqual(K.positions[0],[4,4]);assert.deepEqual(K.positions[11],[7,16]);
 assert.deepEqual(K.lessonChoices,["Continue lessons","Take a keypad test","Return to Main Menu"]);
 assert.deepEqual(K.testChoices,["Take another test","Keypad Lesson","Return to Main Menu"]);
 const receipt=JSON.parse(readFileSync("analysis/keypad/resources.json"));
 const sha=p=>createHash("sha256").update(readFileSync(p)).digest("hex");
 assert.equal(sha("dist/keypad-data.js"),receipt.output_sha256);
 assert.equal(sha("scripts/extract-keypad-data.py"),receipt.extractor_sha256);
});
test("fingering overview preserves original home highlights and paragraph box",()=>{
 const c=createCurriculum(),review=new FingeringReview(c),g=new Grid();drawFingering(g,review);
 assert.equal(char(g,14,3),"╒");assert.equal(char(g,23,77),"╛");
 assert.match(g.lines()[15],/highlighted keys are the home keys/);
 assert.match(g.lines()[22],/Press any other key/);
 for(const key of "asdfjkl;"){
  const [r,col]=D.keyboardPositions[D.keyIndex[key]],x=13+Math.trunc(col/3)+r*2+col+3;
  assert.equal(char(g,3+r*2+2,x),key.toUpperCase());assert.equal(attr(g,3+r*2+2,x),0x1f);
 }
 assert.equal(review.input("a",0).invalid,true);assert.equal(review.input("E",0).invalid,true);
 assert.equal(review.input("ArrowLeft",0).ignored,true);assert.equal(review.tutorial,null);
});
test("fingering review accepts original reach keys and consumes first typed key immediately",()=>{
 const c=createCurriculum();c.introduced=8;c.alphabetic=4;c.newKey=106;
 const before=structuredClone(c.current),review=new FingeringReview(c),seed=c.seed;
 assert.equal(review.input("e",0).tutorialStarted,true);assert.ok(review.tutorial.line.target.startsWith("dede "));
 assert.equal(c.newKey,106);const first=review.tutorial.line.target[0];
 review.input(first,100);assert.deepEqual(review.tutorial.line.typed,[first]);
 let now=200;
 for(const key of [...review.tutorial.line.target.slice(1),"Enter"])review.input(key,now+=100);
 for(let n=0;n<2;n++)for(const key of [...review.tutorial.line.target,"Enter"])review.input(key,now+=100);
 assert.equal(review.tutorial,null);assert.equal(review.finished,false);assert.equal(c.newKey,106);
 assert.deepEqual(c.current,before);assert.equal(c.weights[8],255);assert.notEqual(c.seed,seed);
 review.input("Escape",now);assert.equal(review.finished,true);assert.equal(c.newKey,106);
 assert.equal(review.input("e",now).ignored,true);
});
test("fingering tutorial abort restores overview state without recording samples or changing pending introduction",()=>{
 const c=createCurriculum(),review=new FingeringReview(c),weight=c.weights[D.keyIndex.z];c.newKey=106;
 review.input("z",0);review.input("a",100);review.input("Escape",200);
 assert.equal(review.finished,true);assert.equal(review.tutorial,null);assert.equal(c.newKey,106);
 assert.equal(c.weights[D.keyIndex.z],weight);assert.ok(c.current.every(s=>s.time===0));
});
test("original keypad outline positions, intro highlights and instruction survive extraction",()=>{
 const g=new Grid();drawKeypadIntro(g);
 assert.equal(char(g,3,30),"╒");assert.equal(char(g,13,50),"╛");
 for(let i=0;i<12;i++){const [r,c]=K.positions[i];assert.equal(char(g,3+r,30+c),K.keys[i]);assert.equal(attr(g,3+r,30+c),i<3?0x1f:0x12);}
 assert.equal(char(g,15,13),"╒");assert.match(g.lines().join("\n"),/right hand/);
});
test("lesson and four-column keypad test entries use original right-aligned coordinates",()=>{
 const lesson={entries:["44","456","4.56"].map(s=>new LineInput(s)),activeEntry:1};
 const g=new Grid();drawKeypadActivity(g,lesson);
 assert.equal(char(g,3,33),"╒");assert.equal(char(g,14,47),"╛");
 assert.equal(g.lines()[5].slice(44,46),"44");assert.equal(g.lines()[8].slice(43,46),"456");
 assert.equal(char(g,9,43),"↑");assert.match(g.lines()[18],/Type the lines/);
 const entries=Array.from({length:24},()=>new LineInput("12345"));entries[6].input("1",100);entries[6].input("x",200);
 const tg=new Grid();drawKeypadActivity(tg,{entries,activeEntry:6},{test:true});
 assert.equal(tg.lines()[5].slice(15,20),"12345");assert.equal(tg.lines()[20].slice(66,71),"12345");
 assert.equal(char(tg,4,33),"↓");assert.equal(char(tg,6,34),"↑");assert.equal(char(tg,22,72),"╛");
});
test("keypad reach tutorial shows three short entries, active marker and right finger instruction",()=>{
 const entries=Array.from({length:3},()=>new LineInput("47474747")),g=new Grid();
 drawKeypadTutorial(g,{entries,activeEntry:0,key:"7",home:"4",finger:1,count:0});
 assert.equal(g.lines()[5].slice(13,21),"47474747");assert.equal(char(g,6,13),"↑");
 assert.equal(char(g,3,10),"╒");assert.equal(char(g,14,24),"╛");
 assert.match(g.lines()[17],/right index finger.*'4' and '7'/);
 assert.equal(char(g,7,54),"4");assert.equal(attr(g,7,54),0x1f);assert.equal(attr(g,5,54),0x1f);
});
test("keypad lesson summary follows recovered white table and integer fields",()=>{
 const g=new Grid();drawKeypadSummary(g,{totals:{wpm:24,accuracy:99},goal:20},{best:"456",worst:"7.0",above:3});
 assert.equal(char(g,3,27),"╒");assert.equal(attr(g,3,27),0x1f);
 assert.match(g.lines()[4],/Speed: 24 WPM/);assert.match(g.lines()[5],/Accuracy: 99%/);
 assert.match(g.lines()[6],/Keys Above 20 WPM: 3/);assert.match(g.lines()[7],/Best Keys: 4 5 6/);
 assert.match(g.lines()[8],/Keys to Work on: 7 . 0/);
});
