import test from "node:test";
import assert from "node:assert/strict";
import {Grid} from "../dist/grid.js";
import DATA from "../dist/report-data.js";
import {drawProgress,drawGraph,drawTest} from "../dist/report-screen.js";

test("static report strings and 75 graph columns match recovered tables",()=>{
 assert.equal(DATA.labels,"ASDFJKL;EIT.NRO,HCPUMYGWVBXQZ':\"?!()-4738291056=$+%&*#@<>/[]{}^_4567891230.");
 assert.deepEqual(DATA.groups,["Test","Lesson - Practice","Lesson - Keypad"]);
 assert.deepEqual(DATA.titles,["Progress Report","Speed Graph","Accuracy Graph"]);
});

test("progress table uses original overall/breakdown columns and data-dependent border",()=>{
 const grid=new Grid();
 const result=drawProgress(grid,{groups:[{label:"Test",rows:[{label:"Practice",date:"10-23-26",keysAbove:12,accuracy:95,speed:27,letter:27,number:null,symbol:null}]},
 {label:"Lesson - Practice",rows:[]},{label:"Lesson - Keypad",rows:[]}]},{wpmGoal:30});
 assert.equal(grid.lines()[4].slice(44,75),"Overall    │    Speed Breakdown");
 assert.equal(grid.lines()[5].slice(27,37),"Keys Above");
 assert.equal(grid.lines()[6].slice(8,12),"Type");
 assert.equal(grid.lines()[9].slice(5,19),"Practice      ");
 assert.equal(grid.lines()[9].slice(19,27),"10-23-26");
 assert.equal(grid.lines()[9].slice(27,33),"    12");
 assert.equal(grid.lines()[9].slice(39,46),"    95%");
 assert.equal(grid.lines()[9].slice(46,52),"    27");
 assert.equal(grid.lines()[9].slice(56,61),"   27");
 assert.equal(grid.lines()[11].slice(6,17),"* No data *");
 assert.equal(result.bottom,15);
 assert.equal(grid.cells[7][1].char,"├");
 assert.equal(grid.cells[7][38].char,"┼");
 assert.equal(grid.cells[15][55].char,"╧");
});

test("single result shares table geometry and blank zero-speed fields",()=>{
 const grid=new Grid();drawProgress(grid,{groups:[{label:"",rows:[{label:"All Keys",date:"01-02-26",keysAbove:0,accuracy:0,speed:null,letter:null}]}]});
 assert.equal(grid.lines()[8].slice(39,46),"     0%");
 assert.equal(grid.lines()[8].slice(46,55)," ".repeat(9));
 assert.equal(grid.cells[10][1].char,"╘");
 assert.equal(grid.lines()[8].slice(5,19),"All Keys      ");
});

test("speed/accuracy graph stacks BOTH, SESSION and HISTORY in bright DOS colors",()=>{
 const current=Array(75).fill(0),saved=Array(75).fill(0);current[0]=10;saved[0]=15;current[1]=20;saved[1]=5;
 const grid=new Grid();drawGraph(grid,{current,saved});
 assert.equal(grid.lines()[2].slice(0,4),"100┬");
 assert.equal(grid.lines()[21].slice(0,4),"  5┼");
 assert.equal(grid.cells[22][3].char,"└");
 assert.equal(grid.lines()[23].slice(4,79),DATA.labels);
 assert.deepEqual(grid.cells[21][4],{char:"█",attr:0x1f});
 assert.deepEqual(grid.cells[7][4],{char:"█",attr:0x1c});
 assert.deepEqual(grid.cells[2][5],{char:"█",attr:0x1a});
 assert.equal(grid.cells[6][4].char," ");
});

test("legend finds an original 22-column high/low clearance run",()=>{
 const grid=new Grid(),zero=Array(75).fill(0);
 assert.deepEqual(drawGraph(grid,{current:zero,saved:zero}).legend,{row:4,column:58});
 assert.equal(grid.cells[4][60].char,"╔");
 assert.equal(grid.lines()[5].slice(61,76)," █ THIS SESSION");
 assert.deepEqual(drawGraph(new Grid(),{current:Array(75).fill(15),saved:Array(75).fill(15)}).legend,{row:15,column:58});
 // Mid-height bars leave neither original clearance band.
 assert.equal(drawGraph(new Grid(),{current:Array(75).fill(8),saved:Array(75).fill(15)}).legend,null);
});

test("monochrome graph uses recovered three distinct fill glyphs",()=>{
 const grid=new Grid(),current=Array(75).fill(0),saved=Array(75).fill(0);
 current[0]=5;saved[0]=10;current[1]=10;saved[1]=5;
 drawGraph(grid,{current,saved},{color:false});
 assert.deepEqual(grid.cells[12][4],{char:"▒",attr:7});
 assert.deepEqual(grid.cells[12][5],{char:"░",attr:7});
 assert.deepEqual(grid.cells[21][4],{char:"█",attr:7});
});

test("six-line original test places targets, corrections and active pointer inside open green frame",()=>{
 const grid=new Grid(),lines=Array.from({length:6},(_,i)=>({target:"Line "+i,typed:i===2?["x","i"]:[],errors:i===2?[true,false]:[]}));
 drawTest(grid,{lines,activeLine:2,finished:false});
 for(let i=0;i<6;i++)assert.equal(grid.lines()[4+3*i].slice(3,9),"Line "+i);
 assert.deepEqual(grid.cells[2][1],{char:"╒",attr:0x2f});
 assert.deepEqual(grid.cells[9][3],{char:"↓",attr:0x2c});
 assert.deepEqual(grid.cells[11][5],{char:"↑",attr:0x2f});
 assert.equal(grid.cells[5][3].char," ");
 assert.equal(grid.cells[22][78].char,"╛");
 assert.equal(grid.cells[3][2].attr,0x1f);
 drawTest(new Grid(),{lines,activeLine:5,finished:true});
});
