import DATA from "./report-data.js";

const A=0x1f;
const pad=(value,width)=>String(value??"").padStart(width," ");
const field=(value,width)=>String(value??"").padEnd(width," ");
const clean=value=>String(value??"").slice(0,79);

// Parent owns the original screen header/footer. Rows follow 0x18c42/0x18ad2/0x18857.
export function drawProgress(grid,model,{wpmGoal=20}={}){
  const s=DATA.strings;
  grid.put(4,44,s["7e93"],A);
  grid.put(5,27,s["7eb3"],A);
  grid.put(6,8,"Type         Date"+pad(wpmGoal,6)+" WPM"+s["7ef3"],A);
  let row=8;
  for(const group of model.groups??[]){
    if(group.label)grid.put(row++,3,clean(group.label),A);
    if(!group.rows?.length){grid.put(row++,6,s["7e87"],A);continue;}
    for(const item of group.rows){
      // DOS printf widths are minimum widths; labels are validated by the report model.
      const accuracy=item.accuracy==null?" ".repeat(7):pad(item.accuracy,6)+"%";
      let text=field(item.label,14)+field(item.date,8)+pad(item.keysAbove,6)+" ".repeat(6)+accuracy;
      const speed=item.speed??0;
      if(speed){
        text+=pad(speed,6)+pad(item.letter||null,9)+pad(item.number||null,7);
        if(item.symbol)text+=pad(item.symbol,7);
      }
      grid.put(row++,5,text,A);
    }
  }
  // Native frame height is data dependent and is drawn after the row output.
  const bottom=row+1;
  grid.box(3,1,bottom,78,A,false,false);
  for(let r=4;r<bottom;r++){grid.put(r,38,"│",A);grid.put(r,55,"│",A);}
  grid.put(3,38,"╤",A);grid.put(3,55,"╤",A);
  grid.put(bottom,38,"╧",A);grid.put(bottom,55,"╧",A);
  grid.put(7,1,"├"+"─".repeat(76)+"┤",A);
  grid.put(7,38,"┼",A);grid.put(7,55,"┼",A);
  return {bottom,nextRow:row};
}

function heights(model,key){
  return Array.from({length:75},(_,i)=>Math.max(0,Math.min(20,Math.trunc(model[key]?.[i]??0))));
}
// Exact clear-space scan used by 0x184d1 while columns are drawn right-to-left.
function legendPlacement(current,saved){
  let high=79,highLast=80,highFound=0,low=79,lowLast=80,lowFound=0;
  for(let i=74;i>=0;i--){
    if(highFound)continue;
    high--;if(Math.max(current[i],saved[i])>11)highLast=high;
    if(highLast-high===22)highFound=high;
    if(!lowFound){low--;if(Math.min(current[i],saved[i])<9)lowLast=low;if(lowLast-low===22)lowFound=low;}
  }
  return highFound?{row:4,column:highFound}:lowFound?{row:15,column:lowFound}:null;
}
export function drawGraph(grid,model,{labels=DATA.labels,color=true}={}){
  const current=heights(model,"current"),saved=heights(model,"saved");
  const sharedAttr=color?0x1f:0x07,currentAttr=color?0x1a:0x07,savedAttr=color?0x1c:0x07;
  const shared="█",currentChar=color?"█":"░",savedChar=color?"█":"▒";
  for(let row=2;row<22;row++)grid.put(row,0,pad(110-row*5,3)+(row===2?"┬":"┼"),sharedAttr);
  grid.put(22,3,"└"+"┼".repeat(74)+"┤",sharedAttr);
  grid.put(23,4,labels,sharedAttr);
  for(let i=74;i>=0;i--){
    const common=Math.min(current[i],saved[i]),top=Math.max(current[i],saved[i]);
    for(let n=1;n<=common;n++)grid.put(22-n,4+i,shared,sharedAttr);
    for(let n=common+1;n<=top;n++)grid.put(22-n,4+i,current[i]>saved[i]?currentChar:savedChar,current[i]>saved[i]?currentAttr:savedAttr);
  }
  const legend=legendPlacement(current,saved);
  if(legend){
    const {row,column}=legend;
    grid.box(row,column+2,row+4,column+19,sharedAttr,true,true);
    grid.put(row+1,column+3," "+currentChar+" "+DATA.legend[0],currentAttr);
    grid.put(row+2,column+3," "+savedChar+" "+DATA.legend[1],savedAttr);
    grid.put(row+3,column+3," "+shared+" "+DATA.legend[2],sharedAttr);
  }
  return {legend};
}

// Standard six-line test: 0x13a6d(0,6,72,...), frame 0x14802.
// Accept either line-input objects or raw targets with a separate active line-input object.
export function drawTest(grid,test){
  grid.box(2,1,22,78,0x2f,false,false);
  const active=test.activeLine??0;
  (test.lines??[]).slice(0,6).forEach((item,i)=>{
    const line=typeof item==="string"?{target:item}:item;
    const input=(i===active?test.line:null)??line;
    const row=4+i*3,left=3;
    grid.put(row,left,line.target??"",0x2f);
    (input.typed??[]).forEach((char,j)=>grid.put(row+1,left+j,char>" "?char:" ",0x2f));
    (input.errors??[]).forEach((error,j)=>{if(error)grid.put(row-1,left+j,"↓",0x2c);});
    if(i===active&&!test.finished)grid.put(row+1,left+(input.typed?.length??0),"↑",0x2f);
  });
  return {targetRows:[4,7,10,13,16,19],left:3};
}
