import D from "./curriculum-data.js";
export function validObservation(a,spaces=false){
  return a&&typeof a.key==="string"&&a.key.length===1&&a.key.charCodeAt(0)>=(spaces?32:33)&&a.key.charCodeAt(0)<=126&&
    Number.isInteger(D.keyIndex[a.key])&&(spaces&&a.key===" "||D.keyIndex[a.key]>=0&&D.keyIndex[a.key]<64)&&
    typeof a.correct==="boolean"&&Number.isInteger(a.time)&&a.time>0&&a.time<=500;
}
export function sameKeyAttempts(attempts,observations){
  const keys=observations.filter(a=>a.key!==" ");
  return attempts.length===keys.length&&attempts.every((a,i)=>a.key===keys[i].key&&a.correct===keys[i].correct&&a.time===keys[i].time);
}
