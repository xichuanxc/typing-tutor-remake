import K from "./keypad-data.js";
import D from "./curriculum-data.js";
import {wrap} from "./grid.js";
function nativeBox(grid,top,left,bottom,right,corners){
 const [tl,tr,bl,br]=corners;
 grid.put(top,left,tl+"─".repeat(right-left-1)+tr,0x12);
 grid.put(bottom,left,bl+"─".repeat(right-left-1)+br,0x12);
 for(let r=top+1;r<bottom;r++){grid.put(r,left,"│",0x12);grid.put(r,right,"│",0x12);}
}
// Original cf2e/d14c table geometry, including the long zero and Enter keys.
export function drawKeypad(grid,top=3,left=30,highlights=""){
 grid.box(top,left,top+10,left+20);
 for(const [t,l,b,r,c] of [[1,2,5,14,"┌┐├┼"],[3,2,7,14,"├┤├┤"],[1,6,7,10,"┬┬┴┼"],[5,2,9,18,"├┐└┘"],[7,10,9,14,"┼┤┴┴"],[3,6,5,10,"┼┼┼┼"]])nativeBox(grid,top+t,left+l,top+b,left+r,[...c]);
 grid.put(top+7,left+2,"├",0x12);grid.put(top+5,left+14,"┼",0x12);
 [...K.keys].forEach((key,i)=>{const [r,c]=K.positions[i];grid.put(top+r,left+c,key,highlights.includes(key)?0x1f:0x12);});
}
function paragraph(grid,text,top,left,width,maxRow){
 for(const line of wrap(text,width)){if(top>maxRow)break;grid.put(top++,left,line);}
}
export function drawKeypadIntro(grid){
 drawKeypad(grid,3,30,"456");grid.box(15,13,20,67);
 paragraph(grid,K.intro,16,15,50,19);
}
function input(grid,line,row,left,active){
 grid.put(row,left,line.target,0x2f);
 (line.typed??[]).forEach((char,i)=>grid.put(row+1,left+i,char,0x2f));
 (line.errors??[]).forEach((error,i)=>{if(error)grid.put(row-1,left+i,"↓",0x2c);});
 if(active)grid.put(row+1,left+(line.typed?.length??0),"↑",0x2f);
}
export function drawKeypadTutorial(grid,tutorial){
 grid.box(3,10,14,24,0x2f);
 tutorial.entries.forEach((line,i)=>input(grid,line,5+3*i,13,i===tutorial.activeEntry));
 drawKeypad(grid,3,50,tutorial.home+tutorial.key);
 const finger=D.fingers[4-tutorial.finger];
 const instruction=D.guideStrings["1a50"].replace("%s","right").replace("%s",finger).replace("%c",tutorial.home).replace("%c",tutorial.key);
 grid.put(17,8,instruction);
}
export function drawKeypadActivity(grid,activity,{test=false,stats=null}={}){
 if(activity.tutorial){drawKeypadTutorial(grid,activity.tutorial);return {tutorial:true};}
 const columns=test?4:1,rows=test?6:3;
 for(let col=0;col<columns;col++){
  const left=test?7+17*col:33,right=test?21+17*col:47;
  grid.box(3,left,test?22:14,right,0x2f);
  for(let r=0;r<rows;r++){
   const i=col*rows+r,line=activity.entries[i];if(!line)continue;
   const end=test?20+17*col:46;
   input(grid,line,5+r*3,end-line.target.length,i===activity.activeEntry&&!activity.finished);
  }
 }
 if(!test){
  if(stats){grid.box(17,31,20,48,0x2f);grid.put(18,33,K.speedLabel,0x2f);grid.put(19,33,K.accuracyLabel,0x2f);
   grid.put(18,40,stats.wpm+" WPM",0x2f);grid.put(19,43,stats.accuracy+"%",0x2f);}
  else{grid.box(17,4,20,75,0x2f);for(const [i,line] of wrap(K.instruction,68).entries())if(i<2)grid.put(18+i,6,line,0x2f);}
 }
 return {tutorial:false,columns,rows};
}
export function drawKeypadSummary(grid,record,summary={best:"   ",worst:"   ",above:0}){
 const result=record.totals;grid.box(3,27,9,53);
 grid.put(4,29,K.speed.replace("%d",result.wpm));grid.put(5,29,K.accuracy.replace("%d",result.accuracy));
 grid.put(6,29,K.above.replace("%d",record.goal).replace("%d",summary.above));
 for(const [row,key,value] of [[7,"best",summary.best],[8,"worst",summary.worst]]){
  let text=K[key];for(const char of value)text=text.replace("%c",char);grid.put(row,29,text);
 }
}
