import DATA from "./curriculum-data.js";
// Native c78e / c831 / c98e: keyboard border, staggered key outlines, table positions.
export function drawKeyboard(grid,top=3,left=13,highlights=""){
  grid.box(top,left,top+10,left+54);
  let row=top+1,col=left+2,count=11,a=["─","─","┬","─"],tail=["─","─","┐"];
  for(let i=0;i<5;i++){
    if(i===1){a[0]="┬";a[2]="┴";tail[0]="┴";}
    if(i===2){tail[0]="┬";tail[2]="┘";}
    if(i===3)count--;
    if(i===4){a[0]="─";count--;tail[0]="─";}
    grid.put(row,col,(i?"└":"┌")+"─"+a.join("").repeat(count)+(i===1?"┬─":"")+tail.join(""),0x12);
    if(i<4){
      const first=i===0?col:col+2,keys=count+(i<2?2:1);
      for(let j=0;j<keys;j++)grid.put(row+1,first+j*4,"│",0x12);
    }
    row+=2;if(i>=1)col+=2;
  }
  for(let i=0;i<64;i++){
    const char=DATA.presentation[i],[r,c]=DATA.keyboardPositions[i];
    grid.put(top+r*2+2,left+Math.trunc(c/3)+r*2+c+3,char.toUpperCase(),
      highlights.toLowerCase().includes(char.toLowerCase())?0x1f:0x12);
  }
}
export function drawTutorial(grid,lesson){
  const tutorial=lesson.tutorial,line=tutorial.line,left=28;
  grid.box(3,22,8,57,0x2f);
  grid.put(5,left,line.target,0x2f);
  line.typed.forEach((c,i)=>grid.put(6,left+i,c>" "?c:" ",0x2f));
  line.errors.forEach((e,i)=>{if(e)grid.put(4,left+i,"↓",0x2c);});
  grid.put(6,left+line.typed.length,"↑",0x2f);
  const home=DATA.counterpart[DATA.keyIndex[tutorial.key]],index=DATA.keyIndex[home],finger=index>3?7-index:index;
  drawKeyboard(grid,12,13,tutorial.key+home);
  const instruction=DATA.guideStrings["1a50"].replace("%s",index>3?"right":"left")
    .replace("%s",DATA.fingers[finger]).replace("%c",home.toUpperCase()).replace("%c",tutorial.key.toUpperCase());
  grid.put(10,8,instruction);
}
