import test from "node:test";
import assert from "node:assert/strict";
import {readFileSync} from "node:fs";
import {createHash} from "node:crypto";
import {Grid} from "../dist/grid.js";
import G from "../dist/invaders-data.js";
import {drawGameSetup,drawSecondName,drawRoundReady,drawGame,drawScores,drawGameOver} from "../dist/invaders-screen.js";
const view=()=>({mode:0,round:1,player:0,players:["Student"],scores:[123],ground:[Array(80).fill(true)],seedAtStart:0,targets:[],summary:{hits:3,misses:0,accuracy:100,bonus:30}});
test("game extraction retains original choices, character order and verified source identities",()=>{
 const m=JSON.parse(readFileSync("analysis/invaders/resources.json"));
 const hash=p=>createHash("sha256").update(readFileSync(p)).digest("hex");
 assert.equal(hash("dist/invaders-data.js"),m.output_sha256);assert.equal(hash("scripts/extract-invaders-data.py"),m.extractor_sha256);
 assert.deepEqual(G.modeChoices,["Practice Keys","Full Keyboard"]);assert.deepEqual(G.playerChoices,["One","Two"]);
 assert.equal(G.gameOrder.length,90);assert.equal(G.scoreTables.entryBytes,35);
});
test("mode and player selectors use original centered geometry and color attributes",()=>{
 const grid=new Grid(),g=drawGameSetup(grid,"mode",1);
 assert.deepEqual([g.top,g.left,g.bottom,g.right,g.listTop,g.listLeft],[7,10,18,70,11,31]);
 assert.equal(grid.cells[12][32].attr,0x29);assert.equal(grid.cells[13][32].attr,0x1a);
 assert.match(grid.lines()[13],/Full Keyboard/);
 const p=drawGameSetup(new Grid(),"players",0);assert.deepEqual([p.top,p.left,p.right,p.listLeft],[7,12,68,36]);
});
test("second-player editor uses the original name field and twenty-five character buffer",()=>{
 const grid=new Grid(),g=drawSecondName(grid,"Second");
 assert.deepEqual([g.top,g.left,g.bottom,g.right,g.row,g.col,g.maxLength],[9,14,17,65,13,27,25]);
 assert.equal(grid.lines()[13].slice(27,52),"Second"+"_" .repeat(19));
 assert.match(grid.lines().join("\n"),/Player #2: Please type your name/);
});
test("live game preserves header, native target colors, projectiles, explosions and ground clipping",()=>{
 const grid=new Grid(),g=view();grid.put(0,70,"Student");
 g.targets=[{type:1,row:2,col:5,text:"Ab",typed:1,missile:20},{type:2,row:3,col:9,text:"x",typed:0},{type:1,row:1,col:0,text:"BAD",typed:0}];
 g.explosions=[{row:10,col:20,length:3,hit:true}];drawGame(grid,g);
 assert.match(grid.lines()[0],/Score: 123/);assert.ok(!grid.lines().join("\n").includes("%ld"));
 assert.equal(grid.cells[2][5].attr,0x1a);assert.equal(grid.cells[2][6].attr,0x1f);assert.equal(grid.cells[3][9].attr,0x1e);
 assert.equal(grid.cells[20][6].char,"↑");assert.equal(grid.cells[20][6].attr,0x1c);assert.equal(grid.cells[10][20].char,"┼");assert.equal(grid.cells[10][20].attr,0x4e);
 assert.ok(!grid.lines()[1].includes("BAD"));assert.ok(grid.cells.slice(22).flat().some(c=>c.attr===0x1b));
 const clear=new Grid();g.ground[0].fill(false);g.targets=[];g.explosions=[];drawGame(clear,g);
 assert.ok(clear.cells.slice(22).flat().every(c=>c.char===" "));
});
test("ready screens retain introductory text and later-round summary with formatted numbers",()=>{
 const first=new Grid();drawRoundReady(first,view());assert.match(first.lines().join("\n"),/Nihilistic letters/);
 assert.match(first.lines()[20],/begin Round 1/);
 const next=view();Object.assign(next,{round:2,lastSummary:{hits:5,misses:0,accuracy:100,bonus:50,player:0}});
 const grid=new Grid();drawRoundReady(grid,next);assert.match(grid.lines()[4],/Hits: 5/);assert.match(grid.lines()[7],/Accuracy Bonus: 50/);
 assert.match(grid.lines()[20],/begin Round 2/);assert.ok(!grid.lines().join("\n").includes("%ld"));
});
test("both global five-entry score tables and game-over rows retain native layout",()=>{
 const tables=[[{name:"Practice",score:40,keys:8,date:"10-23-26"}],[{name:"Full",score:90,keys:64,date:"10-23-26"}]];
 const grid=new Grid();drawScores(grid,tables);assert.match(grid.lines()[2],/Full Keyboard - Top Scores/);assert.match(grid.lines()[14],/Practice Keys - Top Scores/);
 assert.match(grid.lines()[5],/Full.*90.*10-23-26/);assert.match(grid.lines()[17],/Practice.*40.*10-23-26.*8/);
 const over=new Grid();drawGameOver(over,view(),tables);assert.match(over.lines()[9],/Student, the game is over/);assert.match(over.lines()[14],/Practice Keys - Top Scores/);
});
