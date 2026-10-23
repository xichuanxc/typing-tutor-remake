import {CP437} from "./cp437.js";
// Logical character positions and DOS attributes stay independent of browser pixels.
export const COLS=80, ROWS=25;
export const PALETTE=["#000000","#0000aa","#00aa00","#00aaaa","#aa0000","#aa00aa","#aa5500","#aaaaaa",
  "#555555","#5555ff","#55ff55","#55ffff","#ff5555","#ff55ff","#ffff55","#ffffff"];
export function glyph(value) {return typeof value==="number"?(CP437[value]??"?"):value;}
const borders={single:["╒","╕","╘","╛","═","│"],double:["╔","╗","╚","╝","═","║"]};
export class Grid {
  constructor(){this.clear();}
  clear(attr=0x1f){this.cells=Array.from({length:ROWS},()=>Array.from({length:COLS},()=>({char:" ",attr})));return this;}
  put(row,col,text,attr=0x1f) {
    for(const char of String(glyph(text))){if(row>=0&&row<ROWS&&col>=0&&col<COLS)this.cells[row][col]={char,attr};col++;}
    return this;
  }
  fill(row,attr=0x1f,start=0,end=COLS-1){for(let col=start;col<=end;col++)this.put(row,col," ",attr);return this;}
  box(top,left,bottom,right,attr=0x1f,double=false,fill=true) {
    const [tl,tr,bl,br,h,v]=borders[double?"double":"single"];
    if(fill)for(let row=top;row<=bottom;row++)this.fill(row,attr,left,right);
    this.put(top,left,tl+h.repeat(Math.max(0,right-left-1))+tr,attr);
    this.put(bottom,left,bl+h.repeat(Math.max(0,right-left-1))+br,attr);
    for(let row=top+1;row<bottom;row++){this.put(row,left,v,attr);this.put(row,right,v,attr);}
    return this;
  }
  lines(){return this.cells.map(row=>row.map(c=>c.char).join(""));}
}
export function wrap(text,width) {
  const result=[];
  for(const paragraph of text.split("\n")) {
    let line="";
    for(const word of paragraph.trim().split(/\s+/).filter(Boolean)) {
      if(line&&line.length+1+word.length>width){result.push(line);line="";}
      if(word.length>width){if(line){result.push(line);line="";}for(let i=0;i<word.length;i+=width)result.push(word.slice(i,i+width));}
      else line+=(line?" ":"")+word;
    }
    if(line)result.push(line);
    if(!paragraph.trim())result.push("");
  }
  return result;
}
// Directly follows the geometry recovered at 0x1b21d (integer division truncates).
export function choiceLayout(count,width,prompt) {
  const promptRows=Math.trunc(prompt.length/69);
  let height=promptRows+count+10, compact=0;
  while(compact<2&&22<height){height-=2;compact++;}
  const top=Math.trunc((22-height)/2)+2;
  const x=Math.trunc((77-width)/2), left=Math.trunc(x/3);
  return {top,left,right:80-left,bottom:top+height-1,promptTop:top+(compact===0?1:0),
    instructionRow:top+height-(compact?3:4),listTop:top+promptRows+4-compact,
    listLeft:x,listRight:x+width+2,listBottom:top+promptRows+4-compact+count+1,width};
}
