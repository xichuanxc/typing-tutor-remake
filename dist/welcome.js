import DATA from "./welcome-data.js";
import {LEGACY_KEY} from "./faithful-session.js";
import {BIOS_TICK_MS} from "./invaders.js";
import {recordNotes} from "./game-audio.js";
import {drawKeyboard} from "./keyboard-screen.js";
import {wrap} from "./grid.js";

export function shouldShowWelcome(storage,session){
 if(!session.readable||session.baseRaw!==null)return false;
 try{return storage.getItem(LEGACY_KEY)===null;}catch{return false;}
}
export function welcomeNotes(){return recordNotes(DATA.music);}
export const WELCOME_MUSIC_MS=welcomeNotes().reduce((sum,note)=>sum+note.duration*1000,0);
export class WelcomeSequence{
 constructor(){
  this.phase="ready";this.line=0;this.index=0;this.lastCentis=0;this.logoStart=0;this.logoFrame=0;this.events=[];
  this.lines=DATA.lines.map(line=>({...line,typed:[],errors:[]}));
 }
 start(){if(this.phase==="ready"){this.phase="typing";this.lastCentis=0;}}
 advance(elapsedMs){
  if(!Number.isFinite(elapsedMs)||elapsedMs<0)throw Error("Invalid welcome clock");
  if(this.phase==="typing"){
   const centis=Math.floor(Math.floor(elapsedMs/BIOS_TICK_MS)*549/100),line=this.lines[this.line];
   if(centis-this.lastCentis>line.delayCentis){
    const char=line.replay[this.index++];
    if(char==="\b"){line.typed.pop();line.errors.pop();}
    else{
     const expected=line.expected[line.typed.length];line.typed.push(char);line.errors.push(char!==expected);
     if(char!==expected)this.events.push({type:"wrong"});
    }
    this.lastCentis=centis;
    if(this.index===line.replay.length){
     this.line++;this.index=0;
     if(this.line===this.lines.length){this.phase="logo";this.logoStart=elapsedMs;this.events.push({type:"music"});}
    }
   }
  }else if(this.phase==="logo"){
   this.logoFrame=Math.floor((elapsedMs-this.logoStart)/BIOS_TICK_MS)%10;
   if(elapsedMs-this.logoStart>=WELCOME_MUSIC_MS){this.phase="done";this.events.push({type:"done"});}
  }
  return this.phase;
 }
 drainEvents(){const events=this.events;this.events=[];return events;}
}
export function drawWelcome(grid,welcome){
 grid.clear(0x1f);
 grid.box(2,26,10,53);
 for(const [index,line] of welcome.lines.entries()){
  if(welcome.phase!=="ready"&&index>welcome.line)continue;
  grid.put(line.row-1,line.col,line.expected,0x2f);
  grid.put(line.row,line.col,line.typed.join(""),0x2f);
  line.errors.forEach((error,col)=>{if(error)grid.put(line.row-2,line.col+col,"↓",0x2c);});
  if(welcome.phase==="typing"&&index===welcome.line)grid.put(line.row,line.col+line.typed.length,"↑",0x2f);
 }
 if(welcome.phase==="logo"||welcome.phase==="done"){
  grid.box(13,3,22,76,0x1f,true);
  grid.box(13,29,22,50,0x1f,true);
  for(const col of [29,50]){grid.put(13,col,"╦");grid.put(22,col,"╩");}
  for(const [index,paragraph] of DATA.copyright.entries()){
   wrap(paragraph,index===0?24:22).slice(0,8).forEach((line,row)=>grid.put(14+row,index===0?5:52,line));
  }
  const logo=DATA.logo,phase=welcome.logoFrame%10;
  let color=logo.colors[(phase+3)%5],point=0;
  for(let row=0;row<5;row++)for(let col=0;col<10;col++,point++){
   if(col===phase)color=logo.colors[(phase+row)%5];
   grid.put(logo.top+logo.rows[point],logo.left+logo.cols[point],logo.chars[point],0x18|color);
  }
  grid.put(21,46,DATA.registered);
 }else{
  const line=welcome.lines[welcome.line],highlight=welcome.phase==="typing"?line?.replay[welcome.index]??"":"";
  drawKeyboard(grid,DATA.keyboard.top,DATA.keyboard.left,highlight);
 }
 grid.fill(24,0x5e);grid.put(24,Math.trunc((80-DATA.prompt.length)/2),DATA.prompt,0x5e);
}
