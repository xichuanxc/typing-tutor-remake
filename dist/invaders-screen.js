import DATA from "./invaders-data.js";
import {choiceLayout} from "./grid.js";
import {DosRandom} from "./drill-generator.js";
// Native af51/b0a9 paragraph output retains internal spaces and uses a strict right boundary.
function paragraph(grid,text,top,left,bottom,right,attr=0x1f){
 let index=0,row=top+1,column=left+2;
 while(row<bottom&&index<text.length){
  const startColumn=column;let line="";
  for(;;){
   let next=index+1;while(next<text.length&&text.charCodeAt(next)>32)next++;
   if(column+next-index>=right)break;
   line+=text.slice(index,next);column+=next-index;index=next;
   if(index>=text.length){grid.put(row,startColumn,line,attr);return row;}
  }
  grid.put(row,startColumn,line,attr);
  while(text[index]===" ")index++;
  row++;column=left+2;
 }
 return row;
}
const format=(text,...values)=>{let index=0;return text.replace(/%%|%(?:ld|[dsc])/g,token=>token==="%%"?"%":String(values[index++]));};
const name=(game,player=game.player??0)=>game.players?.[player]??"Student";
const score=(game,player=game.player??0)=>game.scores?.[player]??game.score??0;
function localDate(value){
 if(!value)return "";
 if(/^\d{2}-\d{2}-\d{2}$/.test(value))return value;
 const date=new Date(value);if(!Number.isFinite(date.getTime()))return "";
 return [date.getMonth()+1,date.getDate(),date.getFullYear()%100].map(n=>String(n).padStart(2,"0")).join("-");
}
export function drawGameSetup(grid,kind="mode",selected=0){
 const modes=kind==="mode",labels=modes?DATA.modeChoices:DATA.playerChoices,prompt=modes?DATA.modePrompt:DATA.playersPrompt;
 if(!Number.isInteger(selected)||selected<0||selected>=labels.length)throw Error("Invalid game choice");
 const width=modes?14:4,g=choiceLayout(labels.length,width,prompt);
 grid.box(g.top,g.left,g.bottom,g.right);
 paragraph(grid,prompt,g.promptTop,g.left+2,g.listTop-1,g.right-3);
 grid.put(g.instructionRow,g.right-1-DATA.choiceInstruction.length,DATA.choiceInstruction);
 grid.box(g.listTop,g.listLeft,g.listBottom,g.listRight,0x2f,true);
 labels.forEach((label,i)=>grid.put(g.listTop+i+1,g.listLeft+1,(" "+label).padEnd(width+1),i===selected?0x1a:0x29));
 return {...g,labels,prompt};
}
export function drawSecondName(grid,value=""){
 const g={top:9,left:14,bottom:17,right:65,row:13,col:27,width:26,maxLength:25};
 grid.box(g.top,g.left,g.bottom,g.right);
 paragraph(grid,DATA.secondNamePrompt+DATA.nameDots,10,g.left,12,g.right);
 grid.put(g.row,g.col,value.slice(0,25).padEnd(25,"_"));
 grid.put(15,g.right-1-DATA.nameEnter.length,DATA.nameEnter);
 return g;
}
export function drawGameIntroduction(grid){
 grid.box(3,10,11,70);
 paragraph(grid,DATA.introParagraphs[0],3,10,7,70);
 paragraph(grid,DATA.introParagraphs[1],7,10,11,70);
}
// Native19296 uses a restored copy of the game-start random seed and never alters play RNG.
export function terrainCells(seed=0){
 const random=new DosRandom({seed}),cells=[];let col=0,height=random.next(3);
 const put=(row,column,char)=>cells.push({row,col:column,char});
 while(col<80){
  const turn=random.next(3);
  if(turn===2){put(22+height,col++,"═");continue;}
  if(height===0){
   put(22,col,"╗");
   if(turn){put(23,col,"║");put(24,col++,"╚");height=2;}
   else{put(23,col++,"╚");height=1;}
  }else if(height===1){
   if(turn){put(23,col,"╗");put(24,col++,"╚");height=2;}
   else{put(23,col,"╝");put(22,col++,"╔");height=0;}
  }else{
   put(24,col,"╝");
   if(turn){put(23,col,"║");put(22,col++,"╔");height=0;}
   else{put(23,col++,"╔");height=1;}
  }
 }
 return cells;
}
function playPut(grid,row,col,char,attr=0x1f){if(row>=2&&row<22&&col>=0&&col<80)grid.put(row,col,char,attr);}
export function drawGame(grid,game){
 for(let row=2;row<25;row++)grid.fill(row,0x1f);
 grid.put(0,0," "+DATA.roundTitle+" ");grid.put(0,7,String(game.round??1));
 grid.put(0,31,format(DATA.score,(score(game)|0)),0x5e);
 const ground=game.ground?.[game.player??0]??Array(80).fill(true);
 for(const cell of terrainCells(game.seedAtStart??0))if(ground[cell.col])grid.put(cell.row,cell.col,cell.char,0x1b);
 for(const target of game.targets??[]){
  if(!target.type)continue;
  const typed=target.typed??0;
  for(const [i,char] of [...target.text].entries())playPut(grid,target.row,target.col+i,char,i<typed?0x1a:target.type>1?0x1e:0x1f);
  if(target.missile>0)playPut(grid,target.missile,target.missileCol??target.col+Math.trunc(target.text.length/2),"↑",0x1c);
 }
 for(const explosion of game.explosions??[]){
  const {row,col}=explosion,width=explosion.width??explosion.length??0;
  playPut(grid,row-1,col-1,"\\",0x4e);playPut(grid,row,col-2,"─",0x4e);playPut(grid,row,col-1,"─",0x4e);playPut(grid,row+1,col-1,"/",0x4e);
  for(let i=0;i<width;i++){playPut(grid,row-1,col+i,"│",0x4e);playPut(grid,row,col+i,explosion.hit?"┼":" ",0x4e);playPut(grid,row+1,col+i,"│",0x4e);}
  playPut(grid,row-1,col+width,"/",0x4e);playPut(grid,row,col+width,"─",0x4e);playPut(grid,row,col+width+1,"─",0x4e);playPut(grid,row+1,col+width,"\\",0x4e);
 }
 return {field:{top:2,bottom:21,left:0,right:79},terrain:{top:22,bottom:24}};
}
function summaryBox(grid,game,summary=game.summary??{}){
 const accuracy=summary.accuracy??0,bonus=summary.bonus??0,two=(game.players?.length??1)>1;
 grid.box(two?2:3,21,accuracy>90?8:7,59);
 const player=summary.player??game.player??0;
 if(two)grid.put(3,23,format(DATA.summaryPlayer,player+1,name(game,player)));
 grid.put(4,23,format(DATA.hits,summary.hits??0));
 grid.put(5,23,format(DATA.misses,summary.misses??0));
 grid.put(6,23,format(DATA.accuracy,accuracy));
 if(accuracy>90)grid.put(7,23,format(DATA.bonus,bonus),0x1e);
}
export function drawRoundReady(grid,game){
 drawGame(grid,game);
 if((game.round??1)===1)drawGameIntroduction(grid);
 else if(game.lastSummary)summaryBox(grid,game,game.lastSummary);
 const round=game.round??1,two=(game.players?.length??1)>1;
 let top=(round===2?15:round<=3?14:17)-(two?2:0),textTop=top;
 grid.box(top,10,21,70);
 if(two){
  let label=format(DATA.player,(game.player??0)+1,name(game));
  if(round>1)label+=format(DATA.playerScore,(score(game)|0));
  grid.put(top+1,12,label);textTop+=2;
 }
 paragraph(grid,DATA.roundParagraphs[Math.min(round,4)-1],textTop,10,21,70);
 grid.put(20,37,format(DATA.ready,round));
 return {top,left:10,bottom:21,right:70};
}
export function drawRoundSummary(grid,game){drawGame(grid,game);summaryBox(grid,game);}
export function drawScoreTable(grid,tables,mode,top=13){
 if(![0,1].includes(mode))throw Error("Invalid score-table mode");
 grid.box(top,1,top+9,78,0x1f,false,false);
 grid.put(top+1,3,format(DATA.scoreTitle,DATA.modeChoices[mode]));
 grid.put(top+2,6,DATA.scoreHeading+(mode===0?DATA.keysHeading:""));
 grid.put(top+3,6,"─".repeat(mode===0?67:59));
 (tables?.[mode]??[]).slice(0,5).forEach((entry,i)=>{
  if(!entry?.name)return;
  let text=String(i+1)+"     "+entry.name.slice(0,26).padEnd(26)+String(entry.score|0).padStart(13)+localDate(entry.date).padStart(13);
  if(mode===0)text+=String(entry.keys??0).padStart(7);
  grid.put(top+4+i,7,text);
 });
 return {top,left:1,bottom:top+9,right:78};
}
export function drawScores(grid,tables){drawScoreTable(grid,tables,1,1);drawScoreTable(grid,tables,0,13);}
export function drawGameOver(grid,game,tables){
 drawRoundSummary(grid,game);
 const player=game.player??0,two=(game.players?.length??1)>1;
 grid.put(9,21,(two?format(DATA.gameOverPlayer,player+1):"")+format(DATA.gameOver,name(game)));
 if(two){
  grid.put(10,21,DATA.playerOneFinal.replace("%s",name(game,0)).replace("%ld",String(score(game,0)|0)));
  grid.put(11,21,DATA.playerTwoFinal.replace("%s",name(game,1)).replace("%ld",String(score(game,1)|0)));
 }
 return drawScoreTable(grid,tables,game.mode??0,13);
}
