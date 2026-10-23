// Disk reader 0x15ff7/0x15fad/0x1639e and page accounting 0x12b58/0x13a6d.
// This translates byte input and retained assembly; it does not execute DOS.
import {LineInput,totals,accuracy,speed} from "./practice.js";
import {recordAttempt,recalculateThreshold} from "./curriculum.js";
import {validObservation,sameKeyAttempts} from "./timed-observation.js";
import D from "./curriculum-data.js";
const u32=n=>n>>>0;
const copy=a=>a.map(a=>({...a}));
const lineRecord=l=>({target:l.target,result:{...l.result},attempts:copy(l.attempts),observations:copy(l.observations)});
const known=char=>char===" "||(Number.isInteger(D.keyIndex[char])&&D.keyIndex[char]>=0&&D.keyIndex[char]<64);
function byteArray(input){
 if(input instanceof Uint8Array)return new Uint8Array(input);
 if(input instanceof ArrayBuffer)return new Uint8Array(input.slice(0));
 throw Error("Disk test input must be bytes.");
}
export function readDiskText(input){
 const bytes=byteArray(input),rotated=bytes[0]===1,chars=[];
 if(rotated){
  if(bytes.length<3)throw Error("The rotated DOS text header is incomplete.");
  const declared=bytes[1]|bytes[2]<<8,limit=(declared<<16)>>16;
  // 15ff7 tests the incremented counter strictly below its signed length.
  // The declared final byte is a lookahead/terminator and is not appended.
  const length=Math.max(0,limit-1);
  if(bytes.length-3<length)throw Error("The rotated DOS text is shorter than its declared length.");
  for(let i=0;i<length;i++){
   const shift=i%7+1,b=bytes[i+3];
   chars.push(String.fromCharCode(((b>>>shift)|(b<<(8-shift)))&255));
  }
 }else{
  for(const raw of bytes){
   const b=raw&127; // 1e38e is DOS seven-bit text input.
   if(b===26)break;
   if(b===0||b===13)continue;
   chars.push(String.fromCharCode(b));
  }
 }
 const text=chars.join(""),tokens=[];let position=0;
 while(position<text.length){
  let spaces=0;while(position<text.length&&text.charCodeAt(position)<=32){position++;spaces++;}
  if(position===text.length)break;
  let word="";
  while(position<text.length&&text.charCodeAt(position)>32)word+=text[position++];
  if([...word].some(c=>c.charCodeAt(0)>126||!known(c)))
   throw Error("This text contains a character outside the recovered typing keyboard.");
  tokens.push({word,spaces});
 }
 const targets=[];let index=0,carry="";
 for(;;){
  let local=carry;carry="";
  while(index<tokens.length){
   const {word,spaces}=tokens[index++];
   local+=(local?" ".repeat(spaces):"")+word;
   if(local.length<=72)continue;
   let split=72;while(split>=0&&local.charCodeAt(split)>32)split--;
   let end,next;
   if(split<0){
    end=72;next=73;while(next<local.length&&local.charCodeAt(next)>32)next++;
   }else{
    while(split>=0&&local.charCodeAt(split)<=32)split--;
    end=split+1;next=split+2;
   }
   while(local[next]===" ")next++;
   targets.push(local.slice(0,end));carry=local.slice(next);local=null;break;
  }
  if(local!==null){targets.push(local);break;}
 }
 // The EOF-returning line counts even when empty; 13b41 does not skip 13b8a.
 return {targets,format:rotated?"rotated":"plain",byteLength:bytes.length};
}
export class DiskTest{
 constructor(curriculum,bytes,{name="TEXT.TST",originalName,sha256,goal=20,startedAt=new Date().toISOString()}={}){
  if(!Number.isInteger(goal)||goal<10||goal>100||goal%10)throw Error("Invalid disk test goal.");
  if(typeof name!=="string"||!name.length||name.length>12||!/^[ -~]+$/.test(name)||/[\\/]/.test(name))throw Error("Invalid disk test name.");
  const parsed=readDiskText(bytes);
  this.curriculum=curriculum;this.name=name;this.goal=goal;this.startedAt=startedAt;
  this.source={name,bytes:parsed.byteLength,format:parsed.format};
  if(originalName!==undefined)this.source.originalName=originalName;
  if(sha256!==undefined)this.source.sha256=sha256;
  this.targets=parsed.targets;this.page=0;this.activeLine=0;this.pages=[];this.completedLines=[];
  this.finished=false;this.completed=false;this.recorded=false;
  this.loadPage();
 }
 loadPage(){
  recalculateThreshold(this.curriculum,this.goal,0);recalculateThreshold(this.curriculum,this.goal,1);
  this.lines=this.targets.slice(this.page*6,this.page*6+6).map(t=>new LineInput(t,{maxLength:72,minLength:0,abortOnEscape:this.source.format!=="rotated"}));
  this.activeLine=0;
 }
 get line(){return this.lines[Math.min(this.activeLine,this.lines.length-1)];}
 input(key,now){
  if(this.finished)return {ignored:true};
  const before=this.line.attempts.length,event=this.line.input(key,now);
  for(const attempt of this.line.attempts.slice(before))recordAttempt(this.curriculum,attempt);
  if(event.aborted){this.finished=true;return event;}
  if(event.done){
   this.completedLines.push(this.line);this.activeLine++;
   if(this.activeLine===this.lines.length){
    this.pages.push(this.lines.length);
    if((this.page+1)*6>=this.targets.length){
     this.finished=true;this.completed=true;return {...event,testDone:true};
    }
    this.page++;this.loadPage();return {...event,pageDone:true};
   }
  }
  return event;
 }
 record(){
  const committed=this.pages.reduce((n,count)=>n+count,0),line=this.line;
  return {version:1,kind:"disk-test-f5b",name:this.name,source:{...this.source},startedAt:this.startedAt,goal:this.goal,
   completed:this.completed,pages:[...this.pages],lines:this.completedLines.map(lineRecord),
   totals:totals(this.completedLines.slice(0,committed)),
   partialAttempts:this.completed||line.done?[]:copy(line.attempts),
   partialObservations:this.completed||line.done?[]:copy(line.observations)};
 }
}
export function validDiskRecord(r){
 const uint=n=>Number.isInteger(n)&&n>=0&&n<=0xffffffff;
 const name=n=>typeof n==="string"&&n.length>0&&n.length<=12&&/^[ -~]+$/.test(n)&&!/[\\/]/.test(n);
 const result=s=>s&&["correct","errors","time","positions","wpm","accuracy"].every(k=>uint(s[k]))&&s.wpm<=65535&&s.accuracy<=100;
 if(!r||r.version!==1||r.kind!=="disk-test-f5b"||!name(r.name)||!r.source||r.source.name!==r.name||
  !uint(r.source.bytes)||!["plain","rotated"].includes(r.source.format)||
  (r.source.originalName!==undefined&&(typeof r.source.originalName!=="string"||r.source.originalName.length>255))||
  (r.source.sha256!==undefined&&(typeof r.source.sha256!=="string"||!/^[a-f0-9]{64}$/i.test(r.source.sha256)))||
  typeof r.startedAt!=="string"||!Number.isFinite(Date.parse(r.startedAt))||
  !Number.isInteger(r.goal)||r.goal<10||r.goal>100||r.goal%10||typeof r.completed!=="boolean"||
  !Array.isArray(r.pages)||!r.pages.every((n,i)=>Number.isInteger(n)&&n>=1&&n<=6&&(i===r.pages.length-1&&r.completed||n===6))||
  !Array.isArray(r.lines)||!result(r.totals)||
  !Array.isArray(r.partialAttempts)||!r.partialAttempts.every(a=>validObservation(a))||
  !Array.isArray(r.partialObservations)||!r.partialObservations.every(a=>validObservation(a,true))||
  !sameKeyAttempts(r.partialAttempts,r.partialObservations)||(r.completed&&(r.partialAttempts.length||r.partialObservations.length)))return false;
 const committed=r.pages.reduce((n,count)=>n+count,0);
 if(committed>r.lines.length||r.lines.length-committed>5||(r.completed&&(committed!==r.lines.length||!committed)))return false;
 if(!r.lines.every(l=>l&&typeof l.target==="string"&&l.target.length<=72&&/^[ -~]*$/.test(l.target)&&[...l.target].every(known)&&
  result(l.result)&&l.result.correct+l.result.errors===l.target.length+1&&l.result.positions===u32(l.target.length-1)&&
  l.result.wpm===speed(u32(l.target.length-1),0,l.result.time)&&l.result.accuracy===accuracy(l.result.correct,l.result.errors)&&
  Array.isArray(l.attempts)&&l.attempts.every(a=>validObservation(a))&&Array.isArray(l.observations)&&l.observations.every(a=>validObservation(a,true))&&sameKeyAttempts(l.attempts,l.observations)))return false;
 const expected=totals(r.lines.slice(0,committed));
 return Object.keys(expected).every(k=>r.totals[k]===expected[k]);
}
