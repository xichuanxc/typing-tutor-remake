import test from "node:test";
import assert from "node:assert/strict";
import {readFile} from "node:fs/promises";
import {createHash} from "node:crypto";
import DATA from "../dist/disk-data.js";
import {Grid,choiceLayout} from "../dist/grid.js";
import {drawDiskPicker,drawDiskEmpty,prepareDiskFiles} from "../dist/disk-screen.js";
const cell=(g,r,c)=>g.cells[r][c],row=(g,r)=>g.lines()[r];
test("Disk resources retain original mask, prompt, choices and reproducible identities",async()=>{
 assert.equal(DATA.mask,"*.tst");assert.equal(DATA.maxFiles,8);assert.equal(DATA.pickerWidth,13);
 assert.equal(DATA.title,"Disk Test");assert.equal(DATA.suffix," Disk Test");
 assert.deepEqual(DATA.choices,["Take another test","Practice Lesson","Return to Main Menu"]);
 const m=JSON.parse(await readFile(new URL("../analysis/disk/resources.json",import.meta.url)));
 const hash=async p=>createHash("sha256").update(await readFile(new URL(p,import.meta.url))).digest("hex");
 assert.equal(m.output_sha256,await hash("../dist/disk-data.js"));
 assert.equal(m.extractor_sha256,await hash("../scripts/extract-disk-data.py"));
 assert.equal(m.native_selection.encrypted_filter,false);assert.equal(m.native_selection.history_choice,false);
});
test("local browser files retain chosen order with eight DOS aliases and no paths",()=>{
 const inputs=["long filename.txt","LONG_FILENAMES.TST","notes.pdf","abc.tst","ABC.TXT","/private/path/Cat.txt","😀.txt","eight.txt","nine.txt","ten.txt"].map(name=>({name}));
 const selected=prepareDiskFiles(inputs);
 assert.equal(selected.length,8);
 assert.deepEqual(selected.map(f=>f.name),["LONG_FIL.TST","LONG_F~1.TST","ABC.TST","ABC~1.TST","CAT.TST","__.TST","EIGHT.TST","NINE.TST"]);
 assert.equal(selected[0].originalName,"long filename.txt");assert.equal(selected[4].originalName,"Cat.txt");
 assert.equal(selected[0].file,inputs[0]);assert.ok(selected.every(f=>f.name.length<=12));
 assert.equal(prepareDiskFiles([{name:".tst"}])[0].name,"TEST.TST");
});
test("original picker uses recovered width, centered list, prompt and DOS attributes",()=>{
 const files=prepareDiskFiles([{name:"one.tst"},{name:"two.txt"}]),g=new Grid();
 const geometry=drawDiskPicker(g,{files,selected:1}),expected=choiceLayout(2,13,DATA.pickerPrompt);
 assert.deepEqual(geometry,expected);
 assert.match(row(g,geometry.listTop+1),/ ONE.TST/);assert.match(row(g,geometry.listTop+2),/ TWO.TST/);
 assert.equal(cell(g,geometry.listTop+1,geometry.listLeft+1).attr,0x29);
 assert.equal(cell(g,geometry.listTop+2,geometry.listLeft+1).attr,0x1a);
 assert.ok(row(g,geometry.instructionRow).includes(DATA.pickerInstruction));
 const full=new Grid(),many=prepareDiskFiles(Array.from({length:8},(_,i)=>({name:i+".tst"})));
 const bounds=drawDiskPicker(full,{files:many});assert.ok(bounds.bottom<=23);assert.ok(bounds.listBottom<=23);
 assert.throws(()=>drawDiskPicker(g,{files,selected:2}));assert.throws(()=>drawDiskPicker(g,{files:[{name:"long-name-without-alias.txt"}]}));
});
test("empty native file selection uses centered double box and original message",()=>{
 const g=new Grid(),geometry=drawDiskEmpty(g);
 assert.deepEqual(geometry,{top:10,left:22,bottom:13,right:56});
 assert.equal(cell(g,10,22).char,"╔");assert.equal(cell(g,13,56).char,"╝");
 assert.ok(row(g,11).includes("There are no test files."));
 const empty=new Grid();assert.deepEqual(drawDiskPicker(empty),geometry);
});
