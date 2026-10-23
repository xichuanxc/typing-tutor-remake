import DATA from "./curriculum-data.js";
import {validObservation,sameKeyAttempts} from "./timed-observation.js";
// Static translations: 0x14a70–0x14f2b, 0x1529a, 0x152dc; see docs/practice-scoring.md.
const u32=n=>n>>>0;
export const DAY=0x83d600;
export {accuracy,speed} from "./scoring.js";
import {accuracy,speed} from "./scoring.js";
// Browser adapter: quantized BIOS-like ticks, converted by the original 549/100.
export function browserClock(ms){
  return Math.floor(Math.floor(ms/(65536/1193182*1000))*549/100)%DAY;
}
export class LineInput{
  constructor(target,{maxLength=26,minLength=2,abortOnEscape=true}={}){
    if(typeof abortOnEscape!=="boolean"||!Number.isInteger(maxLength)||maxLength<2||maxLength>80||!Number.isInteger(minLength)||minLength<0||minLength>maxLength||typeof target!=="string"||target.length<minLength||target.length>maxLength||!/^[ -~]*$/.test(target))throw Error("Invalid practice line");
    this.abortOnEscape=abortOnEscape;this.target=target;this.typed=[];this.errors=Array(target.length+1).fill(false);
    this.attempts=[];this.observations=[];this.epoch=null;this.elapsed=0;this.previousElapsed=0;
    this.previousRaw=0;this.interval=0;this.done=false;this.aborted=false;
  }
  tick(now){
    if(!Number.isInteger(now)||now<0||now>=DAY)throw Error("Clock must be a day-relative integer");
    if(this.epoch===null){this.epoch=now;return;}
    this.elapsed=now-this.epoch;if(this.elapsed<0)this.elapsed+=DAY;
    const raw=(this.elapsed-this.previousElapsed)|0;
    this.interval=Math.min(500,this.previousRaw>0?Math.trunc(((2*this.previousRaw+8*raw)|0)/10):raw);
    this.previousRaw=raw;this.previousElapsed=this.elapsed;
  }
  input(key,now){
    if(this.done||this.aborted)return {ignored:true};
    if(!["Escape","Backspace","Enter","Tab"].includes(key)&&(key.length!==1||key.charCodeAt(0)<32||key.charCodeAt(0)>126))return {ignored:true};
    this.tick(now);
    if(key==="Escape"&&this.abortOnEscape){this.aborted=true;return {aborted:true};}
    if(key==="Backspace"){
      if(!this.typed.length)return {beep:true};
      this.typed.pop();this.errors[this.typed.length]=false;return {corrected:true};
    }
    const actual=key==="Enter"?"\r":key==="Tab"?"\t":key==="Escape"?"\x1b":key;
    const index=this.typed.length;
    this.typed.push(actual);
    if(index===this.target.length){
      this.errors[index]=!["\r"," ","+"].includes(actual);this.done=true;
      const errors=this.errors.filter(Boolean).length,correct=this.errors.length-errors;
      const time=u32(this.elapsed-this.interval);
      this.result={correct,errors,time,positions:u32(this.target.length-1),
        wpm:speed(this.target.length-1,0,time),accuracy:accuracy(correct,errors)};
      return {done:true,error:this.errors[index],result:this.result};
    }
    const expected=this.target[index],correct=actual===expected;
    this.errors[index]=!correct;
    // First/zero-interval keys have no per-key record; spaces are not individual keys.
    if(this.interval!==0){
      const observation={key:expected,correct,time:this.interval};this.observations.push(observation);
      if(expected!==" ")this.attempts.push({...observation});
    }
    return {error:!correct};
  }
}
export function totals(lines){
  const sum=lines.reduce((s,line)=>({correct:s.correct+line.result.correct,errors:s.errors+line.result.errors,
    time:u32(s.time+line.result.time),positions:u32(s.positions+line.result.positions)}),{correct:0,errors:0,time:0,positions:0});
  return {...sum,wpm:speed(sum.positions,0,sum.time),accuracy:accuracy(sum.correct,sum.errors)};
}
// Explicit F3 corpus, NOT the original adaptive generator (F4).
export const HOME_DRILLS=Object.freeze([
  "asdf fdsa asdf fdsa asdf","asdf asdf fdsa fdsa asdf",
  "asas dfdf sasa fdfd asdf","afaf sdsd fafa dsds fdsa",
  "adsf fsda dasf sfad asdf","aass ddff ssaa ffdd asdf",
  "fsda asdf sfad dasf fdsa","sada fada dasa fasa asdf",
  "asdf fdsa aass ddff fdsa","fads sadf dafs asdf fdsa"
]);
export class PracticeLesson{
  constructor(drills=10,goal=20,startedAt=new Date().toISOString()){
    if(![5,10,15,20].includes(drills))throw Error("Invalid drill count");
    this.drills=drills;this.goal=goal;this.startedAt=startedAt;this.lines=[];this.line=new LineInput(HOME_DRILLS[0]);
    this.finished=false;this.recorded=false;
  }
  input(key,now){
    if(this.finished)return {ignored:true};
    const event=this.line.input(key,now);
    if(event.done){
      this.lines.push(this.line);
      if(this.lines.length===this.drills){this.finished=true;return {...event,lessonDone:true};}
      this.line=new LineInput(HOME_DRILLS[this.lines.length%HOME_DRILLS.length]);
    }
    if(event.aborted)this.finished=true;
    return event;
  }
  record(){
    return {version:1,kind:"home-keys-f3",startedAt:this.startedAt,goal:this.goal,drills:this.drills,
      completed:this.lines.length===this.drills,totals:totals(this.lines),
      lines:this.lines.map(line=>({target:line.target,result:{...line.result},attempts:line.attempts.map(a=>({...a}))})),
      partialAttempts:this.lines.includes(this.line)?[]:this.line.attempts.map(a=>({...a}))};
  }
}
export function validPracticeRecord(r){
  const uint=n=>Number.isInteger(n)&&n>=0&&n<=0xffffffff;
  const attempt=a=>a&&typeof a.key==="string"&&a.key.length===1&&a.key!==" "&&/^[!-~]$/.test(a.key)&&typeof a.correct==="boolean"&&Number.isInteger(a.time)&&a.time>0&&a.time<=500;
  const result=s=>s&&["correct","errors","time","positions","wpm","accuracy"].every(k=>uint(s[k]))&&s.accuracy<=100&&s.wpm<=65535;
  if(!r||r.version!==1||!["home-keys-f3","adaptive-alpha-f4","adaptive-keyboard-f4c"].includes(r.kind)||typeof r.startedAt!=="string"||!Number.isFinite(Date.parse(r.startedAt))||
    ![5,10,15,20].includes(r.drills)||!Number.isInteger(r.goal)||r.goal<10||r.goal>100||r.goal%10||
    typeof r.completed!=="boolean"||!result(r.totals)||!Array.isArray(r.lines)||r.lines.length>r.drills||
    r.completed!==(r.lines.length===r.drills)||!Array.isArray(r.partialAttempts)||!r.partialAttempts.every(attempt))return false;
  if(!r.lines.every(l=>l&&(r.kind==="home-keys-f3"?HOME_DRILLS.includes(l.target):typeof l.target==="string"&&l.target.length>=2&&l.target.length<=26&&(r.kind==="adaptive-alpha-f4"?/^[A-Za-z ;.,]+$/.test(l.target):[...l.target].every(c=>c===" "||(Number.isInteger(DATA.keyIndex[c])&&DATA.keyIndex[c]>=0&&DATA.keyIndex[c]<=r.introducedAtEnd))))&&result(l.result)&&Array.isArray(l.attempts)&&l.attempts.every(attempt)&&
    l.result.correct+l.result.errors===l.target.length+1&&l.result.positions===l.target.length-1&&
    l.result.accuracy===accuracy(l.result.correct,l.result.errors)&&l.result.wpm===speed(l.result.positions,0,l.result.time)))return false;
  if(["adaptive-alpha-f4","adaptive-keyboard-f4c"].includes(r.kind)&&(!Number.isInteger(r.introducedAtStart)||!Number.isInteger(r.introducedAtEnd)||
    r.introducedAtStart<3||r.introducedAtEnd<r.introducedAtStart||r.introducedAtEnd>(r.kind==="adaptive-alpha-f4"?28:63)))return false;
  if(r.lines.some(l=>l.observations!==undefined&&(!Array.isArray(l.observations)||!l.observations.every(a=>validObservation(a,true))||!sameKeyAttempts(l.attempts,l.observations))))return false;
  if(r.partialObservations!==undefined&&(!Array.isArray(r.partialObservations)||!r.partialObservations.every(a=>validObservation(a,true))||!sameKeyAttempts(r.partialAttempts,r.partialObservations)))return false;
  const sum=totals(r.lines);
  return Object.keys(sum).every(k=>sum[k]===r.totals[k]);
}
