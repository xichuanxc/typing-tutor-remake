// Native global score insertion: 0x1768e. Tables are outside the student profile.
const uint=n=>Number.isInteger(n)&&n>=0&&n<=0xffffffff;
export const validGamePlayerName=name=>typeof name==="string"&&name.length>0&&name.length<=25&&/^[A-Za-z0-9.,'][A-Za-z0-9 .,'-]*$/.test(name);
const candidate=e=>e&&validGamePlayerName(e.name)&&uint(e.score)&&Number.isInteger(e.keys)&&e.keys>=8&&e.keys<=64&&typeof e.date==="string"&&Number.isFinite(Date.parse(e.date));
export function validGameScores(tables){
 return Array.isArray(tables)&&tables.length===2&&tables.every((rows,mode)=>Array.isArray(rows)&&rows.length<=5&&rows.every((e,i)=>candidate(e)&&(e.score|0)>0&&(mode===0||e.keys===64)&&(i===0||(rows[i-1].score|0)>=(e.score|0))));
}
export function insertGameScore(tables,mode,entry){
 if(!validGameScores(tables)||![0,1].includes(mode)||!candidate(entry)||(mode===1&&entry.keys!==64))throw Error("Invalid game score");
 const out=structuredClone(tables),score=entry.score|0;
 // Blank native slots contain zero: a zero or negative signed score cannot qualify.
 if(score<=0)return {tables:out,index:-1};
 const rows=out[mode];let index=rows.findIndex(e=>(e.score|0)<score);
 if(index<0)index=rows.length;
 if(index>=5)return {tables:out,index:-1};
 rows.splice(index,0,{...entry});rows.length=Math.min(rows.length,5);
 return {tables:out,index};
}
