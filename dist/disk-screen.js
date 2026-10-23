import DATA from "./disk-data.js";
import {choiceLayout,wrap} from "./grid.js";
// Browser adapter: the native DOS enumeration receives at most eight 8.3 names.
// User-selected .txt files and longer names are given stable display aliases.
export function prepareDiskFiles(files){
  const accepted=[],used=new Set();
  for(const file of files){
    if(accepted.length===DATA.maxFiles)break;
    const originalName=String(file?.name??"").split(/[\\/]/).pop();
    if(!/\.(tst|txt)$/i.test(originalName))continue;
    const basename=originalName.slice(0,originalName.lastIndexOf("."));
    const clean=basename.toUpperCase().replace(/[^A-Z0-9!#$%&'()@^_{}~-]/g,"_")||"TEST";
    let stem=clean.slice(0,8),name=stem+".TST",collision=0;
    while(used.has(name)){
      const tail="~"+(++collision);
      stem=clean.slice(0,8-tail.length)+tail;name=stem+".TST";
    }
    used.add(name);accepted.push({file,name,originalName});
  }
  return accepted;
}
export function drawDiskEmpty(grid){
  const g=DATA.emptyGeometry;
  grid.box(g.top,g.left,g.bottom,g.right,0x1f,true);
  wrap(DATA.noFiles,g.right-g.left-3).forEach((text,i)=>grid.put(g.top+1+i,g.left+2,text));
  return g;
}
export function drawDiskPicker(grid,{files=[],selected=0}={}){
  if(!files.length)return drawDiskEmpty(grid);
  if(files.length>DATA.maxFiles||!Number.isInteger(selected)||selected<0||selected>=files.length)throw Error("Invalid disk picker state");
  if(files.some(f=>typeof f.name!=="string"||f.name.length>12||!f.name.length))throw Error("Disk picker needs DOS display aliases");
  const g=choiceLayout(files.length,DATA.pickerWidth,DATA.pickerPrompt);
  grid.box(g.top,g.left,g.bottom,g.right);
  const prompt=wrap(DATA.pickerPrompt,g.right-g.left-7);
  prompt.forEach((text,i)=>grid.put(g.promptTop+1+i,g.left+4,text));
  grid.put(g.instructionRow,g.right-1-DATA.pickerInstruction.length,DATA.pickerInstruction);
  grid.box(g.listTop,g.listLeft,g.listBottom,g.listRight,0x2f,true);
  files.forEach((file,i)=>grid.put(g.listTop+i+1,g.listLeft+1,(" "+file.name).padEnd(DATA.pickerWidth+1),i===selected?0x1a:0x29));
  return g;
}
