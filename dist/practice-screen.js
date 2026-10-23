// Character coordinates from 0x14232, 0x14344, 0x14802, 0x13a6d.
export function drawPractice(grid,lesson,data){
  const line=lesson.line,left=Math.trunc((80-line.target.length)/2);
  grid.box(5,22,10,57,0x2f);
  grid.box(13,25,15,54,0x2f);
  grid.put(14,27,data.focus,0x2f);grid.put(14,47,lesson.focus?[...lesson.focus].join(" "):"--",0x2f);
  if(!lesson.finished){
    grid.put(7,left,line.target,0x2f);
    line.typed.forEach((char,i)=>grid.put(8,left+i,char>" "?char:" ",0x2f));
    line.errors.forEach((error,i)=>{if(error)grid.put(6,left+i,"↓",0x2c);});
    grid.put(8,left+line.typed.length,"↑",0x2f);
  }else grid.put(7,33,data.end,0x2f);
  if(!lesson.lines.length){
    grid.box(17,4,20,75,0x2f);
    // The original paragraph formatter adds a one-cell inner margin.
    const words=data.instruction.split(/\s+/);let row=18,text="";
    for(const word of words){if(text.length+word.length+1>68){grid.put(row++,6,text,0x2f);text="";}text+=(text?" ":"")+word;}
    if(text)grid.put(row,6,text,0x2f);
  }else{
    const last=lesson.lines.at(-1).result;
    grid.box(17,31,20,48,0x2f);
    grid.put(18,33,data.speed,0x2f);grid.put(19,33,data.accuracy,0x2f);
    grid.put(18,40,last.wpm+" WPM",0x2f);grid.put(19,43,last.accuracy+"%",0x2f);
  }
  return left;
}
