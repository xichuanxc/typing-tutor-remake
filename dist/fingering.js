import D from "./curriculum-data.js";
import K from "./keypad-data.js";
import {DrillGenerator} from "./drill-generator.js";
import {LineInput} from "./practice.js";
import {drawKeyboard,drawTutorial} from "./keyboard-screen.js";
import {wrap} from "./grid.js";
// Native1291c/cd9b saves/restores pending90b2, accepts presentation keys8..63,
// and calls14557 with checkPending=0. Timed tutorial observations are suppressed.
export class FingeringReview{
 constructor(curriculum){this.curriculum=curriculum;this.generator=new DrillGenerator(curriculum);this.tutorial=null;this.finished=false;}
 input(key,now){
  if(this.finished)return {ignored:true};
  if(!this.tutorial){
   if(key==="Escape"){this.finished=true;return {aborted:true};}
   if(key.length!==1)return {ignored:true};
   if(!D.presentation.slice(8).includes(key))return {invalid:true};
   this.tutorial={key,count:0,line:new LineInput(this.generator.homeDrill(key,true))};
   return {tutorialStarted:true};
  }
  const event=this.tutorial.line.input(key,now);
  if(event.aborted||event.done&&this.tutorial.count===2){
   const selected=this.tutorial.key,i=D.keyIndex[selected];
   if((D.charFlags[selected.charCodeAt(0)]&3)&&i<=this.curriculum.introduced)this.curriculum.weights[i]=255;
   this.tutorial=null;
   if(event.aborted){this.finished=true;return event;}
   return {...event,reviewDone:true};
  }
  if(event.done){this.tutorial.count++;this.tutorial.line=new LineInput(this.generator.homeDrill(this.tutorial.key));}
  return event;
 }
}
export function drawFingering(grid,review){
 if(review.tutorial){drawTutorial(grid,review);return {tutorial:true};}
 drawKeyboard(grid,3,13,D.presentation.slice(0,8));
 grid.box(14,3,23,77);
 let row=15;
 for(const paragraph of K.fingeringParagraphs){
  const lines=wrap(paragraph,70);
  for(const line of lines)grid.put(row++,5,line);
  row++;
 }
 return {tutorial:false};
}
