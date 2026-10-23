// Letter Invaders: retained 0x19538,0x1980e,0x19f66,0x1a22a,0x1a541,0x1ab36.
// Pure BIOS-tick simulation. Only the original RNG seed is published to teaching state.
import {validGamePlayerName} from "./game-scores.js";
import D from "./curriculum-data.js";
import G from "./invaders-data.js";
import {DrillGenerator,DosRandom} from "./drill-generator.js";
import {accuracy} from "./scoring.js";
const u32=n=>n>>>0,s16=n=>(n<<16)>>16;
export const BIOS_TICK_MS=65536/1193182*1000;
export function invadersTick(ms){return Math.floor(ms/BIOS_TICK_MS)%0x1800b0;}
export function invaderIndex(key){
 if(typeof key!=="string"||key.length!==1)return -1;
 const i=D.keyIndex[key];if(!Number.isInteger(i)||i<0||i>=64)return -1;
 let j=i>28?26:i>15?i-3:i>11?i-2:i>7?i-1:i;
 if(i<=28&&(D.charFlags[key.charCodeAt(0)]&1))j++;
 return i+j;
}
export class InvadersGame{
 constructor(curriculum,{mode="practice",players=["Student"],startedAt=new Date().toISOString()}={}){
  if(!["practice","full"].includes(mode)||!Array.isArray(players)||players.length<1||players.length>2||
   !players.every(validGamePlayerName))throw Error("Invalid Letter Invaders setup.");
  this.curriculum=curriculum;this.mode=mode;this.players=[...players];this.startedAt=startedAt;
  this.generation=structuredClone(curriculum);this.seedAtStart=curriculum.seed??0;
  const c=this.generation;c.shiftLearned=1;let dictionaryCount=c.alphabetic+4;
  if(mode==="full"){c.introduced=63;c.alphabetic=22;c.weights.fill(100,0,64);dictionaryCount=26;}
  else if(c.introduced<7){c.introduced=7;c.alphabetic=4;dictionaryCount=7;}
  else if(c.newKey){
   c.introduced--;
   if(D.charFlags[c.newKey]&3){c.alphabetic--;dictionaryCount=c.alphabetic+3;}
  }
  this.keys=Math.max(8,c.introduced+1);
  this.lastCharacter=invaderIndex(D.presentation[c.newKey&&c.introduced<63?c.introduced-1:c.introduced].toUpperCase());
  this.generator=new DrillGenerator(c);this.random=new DosRandom(c);
  // Native global9d36 can exclude one extra dictionary letter during temporary game setup.
  const dictionary=this.generator.dictionary.bind(this.generator);
  this.generator.dictionary=id=>{
   const removed=[...D.alphabetFrequency.slice(dictionaryCount,c.alphabetic+4)].map(key=>[D.keyIndex[key],c.weights[D.keyIndex[key]]]);
   for(const [i] of removed)c.weights[i]=0;
   try{return dictionary(id);}finally{for(const [i,value] of removed)c.weights[i]=value;}
  };
  this.round=1;this.player=0;this.scores=players.map(()=>0);this.health=players.map(()=>80);
  this.ground=players.map(()=>Array(80).fill(true));this.spawnInterval=20;this.fallInterval=12;
  this.phase="ready";this.completed=false;this.aborted=false;this.finished=false;this.recorded=false;
  this.ticks=0;this.lastTick=null;this.submissions=[];this.rounds=[];this.events=[];this.lastSummary=null;
  this.prepareRound();
 }
 publishSeed(){this.curriculum.seed=this.generation.seed??0;}
 pool(){
  const out=[];
  for(let i=0;i<=this.lastCharacter;i++){
   if("',-".includes(G.gameOrder[i]))i++;
   if(i>this.lastCharacter||G.gameOrder[i]==="_")break;
   out.push(G.gameOrder[i]);
  }
  return out;
 }
 wordLine(){
  let line;
  do{line=this.generator.line(40);}while(this.generation.introduced===7&&line.includes("e"));
  return line;
 }
 prepareRound(){
  if(this.spawnInterval>2)this.spawnInterval--;
  if(this.round>3&&this.fallInterval>6)this.fallInterval--;
  this.generator.fresh=true;this.generator.pointer=null;
  this.frame=0;this.cooldown=0;this.active=0;this.nextPayload=0;this.special=0;this.lock=null;
  this.hits=0;this.misses=0;this.explosions=[];this._slots=Array.from({length:90},(_,index)=>({index,type:0,row:0,col:0,phase:0,missile:0,payloadIndex:0}));
  this.columns=this.ground[this.player].flatMap((alive,i)=>alive?[i]:[]);
  let pool=this.pool(),text=this.wordLine(),position=0;
  this.payloads=[];
  for(let i=0;i<40;i++){
   if(!pool.length)pool=this.pool();
   let word;
   if(this.random.next(this.round+1)===0){
    const selected=this.random.next(pool.length);word=pool[selected];pool.splice(selected,1);
   }else{
    for(;;){
     while(text[position]===" "||(text[position]==="-"&&!(text[position+1]>" ")))position++;
     if(position<text.length)break;
     text=this.wordLine();position=0;
    }
    word="";
    while(text[position]>" "&&word.length<15)word+=text[position++];
    if(this.random.next(2))word=word[0].toUpperCase()+word.slice(1);
   }
   this.payloads.push({text:word,typed:0});
  }
  this.publishSeed();this.lastTick=null;
 }
 get targets(){return this._slots.filter(s=>s.type).map(s=>({...s,text:this.payloads[s.payloadIndex].text,typed:this.payloads[s.payloadIndex].typed,missileCol:s.type===3?this.special:s.col+Math.trunc(this.payloads[s.payloadIndex].text.length/2)}));}
 get score(){return this.scores[this.player];}
 get terrain(){return this.ground[this.player];}
 get summary(){return this.lastSummary??{hits:this.hits,misses:this.misses,accuracy:accuracy(this.hits,this.misses),bonus:0};}
 get snapshot(){return {phase:this.phase,round:this.round,player:this.player,players:[...this.players],scores:[...this.scores],
  ground:this.ground.map(g=>[...g]),health:[...this.health],targets:this.targets,seedAtStart:this.seedAtStart,
  hits:this.hits,misses:this.misses,frame:this.frame,nextPayload:this.nextPayload,active:this.active,
  summary:{...this.summary},explosions:this.explosions.map(e=>({...e})),keys:this.keys};}
 drainEvents(){const out=this.events;this.events=[];return out;}
 emit(type){this.events.push({type});}
 submit(player){this.submissions.push({player,score:this.scores[player],keys:this.keys,round:this.round});}
 endReady(){
  this.aborted=true;for(let p=0;p<this.players.length;p++)this.submit(p);
  this.phase="game-over";this.finished=true;this.completed=true;
 }
 input(key,tick=0){
  if(this.finished)return {ignored:true};
  if(this.phase==="ready"||this.phase==="level-end"){
   if(key==="Escape"){this.endReady();return {aborted:true,gameOver:true};}
   this.phase="playing";this.lastTick=tick;return {started:true};
  }
  if(key==="Escape"){
   this.aborted=true;this.health[this.player]=0;this.finishRound();return {aborted:true,gameOver:this.finished};
  }
  const char=key==="Enter"?"\r":key==="Tab"?"\t":key==="Backspace"?"\b":key;
  if(typeof char!=="string"||char.length!==1)return {ignored:true};
  if(!this.lock&&(char===" "||char==="\r"))return {ignored:true};
  if(this.lock){
   const payload=this.payloads[this.lock.payloadIndex],slot=this._slots[this.lock.slotIndex];
   if(char!==payload.text[this.lock.nextIndex]){
    payload.typed=0;this.lock=null;this.penalty();return {error:true};
   }
   payload.typed++;this.lock.nextIndex++;this.hits=(this.hits+1)&0xffff;
   if(this.lock.nextIndex===payload.text.length){
    slot.missile=21;
    if(slot.type===3)this.special=slot.col-Math.floor((23-slot.row)/2)+Math.trunc(payload.text.length/2);
    this.lock=null;
   }
   return {hit:true};
  }
  if(G.ignoredKeys.includes(char)||char.charCodeAt(0)<=32||char.charCodeAt(0)>125){this.penalty();return {error:true};}
  const index=invaderIndex(char),slot=this._slots[index];
  if(!slot||!slot.type||slot.missile){this.penalty();return {error:true};}
  const payload=this.payloads[slot.payloadIndex];payload.typed=1;this.hits=(this.hits+1)&0xffff;
  if(payload.text.length>1)this.lock={payloadIndex:slot.payloadIndex,slotIndex:index,nextIndex:1};
  else slot.missile=21;
  return {hit:true};
 }
 penalty(){
  this.misses=(this.misses+1)&0xffff;
  const value=u32(this.scores[this.player]-10);this.scores[this.player]=(value|0)<0?0:value;
  this.emit("wrong");
 }
 resolve(slot,hit){
  const payload=this.payloads[slot.payloadIndex],length=payload.text.length,type=slot.type;
  this.explosions.push({row:slot.row,col:slot.col,length,hit});
  if(hit){
   const points=length>1?5*length*(length+1)*(type===1?1:2):type===1?10:50;
   this.scores[this.player]=u32(this.scores[this.player]+points);this.emit("hit");
  }else{
   const value=u32(this.scores[this.player]-10);this.scores[this.player]=(value|0)<0?0:value;
   if(this.lock?.payloadIndex===slot.payloadIndex)this.lock=null;
   for(let col=slot.col;col<slot.col+length;col++)if(col>=0&&col<80&&this.ground[this.player][col]){
    this.ground[this.player][col]=false;this.health[this.player]--;
   }
   this.emit("impact");
  }
  if(type>1)this.special=0;
  slot.type=0;slot.missile=0;payload.text="";payload.typed=0;this.active--;
 }
 step(tick){
  if(!Number.isInteger(tick)||tick<0)throw Error("Game clock must be a nonnegative BIOS tick.");
  if(this.phase!=="playing"||tick===this.lastTick)return {ignored:true};
  this.lastTick=tick;this.ticks++;this.explosions=[];
  for(const slot of this._slots){
   const move=slot.type===2?slot.phase===s16(this.frame)%3:slot.type===3?!!(this.frame%2):slot.type===1?slot.phase===s16(this.frame)%this.fallInterval:false;
   if(move){
    if(slot.type===3)slot.col--;else slot.row++;
    if(slot.missile&&slot.row>=slot.missile)this.resolve(slot,true);
    if(slot.type===3&&!slot.missile&&slot.col+this.payloads[slot.payloadIndex].text.length<0){
     const p=this.payloads[slot.payloadIndex];p.text="";p.typed=0;
     if(this.lock?.payloadIndex===slot.payloadIndex)this.lock=null;
     slot.type=0;slot.missile=0;this.active--;this.special=0;
    }
   }
   if(slot.missile){slot.missile--;if(slot.row>=slot.missile)this.resolve(slot,true);}
   if(slot.type&&slot.row>=22)this.resolve(slot,false);
  }
  const roll=this.random.next(this.spawnInterval);
  let spawn=roll===0;
  if(!spawn&&this.active<5)spawn=this.random.next(2)!==0;
  if(spawn&&this.nextPayload<40&&!this.cooldown&&this.health[this.player]){
   let payload=this.payloads[this.nextPayload],index=invaderIndex(payload.text[0]);
   if(this._slots[index]?.type){
    for(let n=0;n<10;n++){
     const char=G.gameOrder[this.random.next(this.lastCharacter+1)],replacement=invaderIndex(char);
     if(this._slots[replacement]&&!this._slots[replacement].type&&!G.replacementExcluded.includes(char)){
      payload.text=char;payload.typed=0;index=replacement;break;
     }
    }
   }
   const slot=this._slots[index];
   if(slot&&!slot.type){
    Object.assign(slot,{payloadIndex:this.nextPayload,type:1,row:2,col:0,missile:0});
    if(payload.text.length===1){
     if(this.random.next(5)===0&&!this.special&&this.round>1){slot.type=2;this.special=1;this.emit("boomlet");}
    }else if(!this.special&&this.round>2&&this.random.next(5)===0){
     slot.type=3;this.special=1;slot.row=this.random.next(18)+3;slot.col=78;this.emit("ship");
    }
    if(slot.type!==3){
     const width=80-payload.text.length;
     if(this.random.next(2))slot.col=this.random.next(width);
     else slot.col=Math.min(width,this.columns[this.random.next(this.columns.length)]);
    }
    slot.phase=slot.type===2?s16(this.frame)%3:s16(this.frame)%this.fallInterval;
    this.cooldown=this.fallInterval+1;this.active++;this.nextPayload++;
   }
  }
  if(this.cooldown)this.cooldown--;
  this.frame=(this.frame+1)&0xffff;this.publishSeed();
  if(!this.health[this.player]||(!this.active&&this.nextPayload>=40)){
   this.finishRound();return {roundDone:true,gameOver:this.finished};
  }
  return {advanced:true};
 }
 finishRound(){
  const percent=accuracy(s16(this.hits),s16(this.misses));
  const bonus=percent>90?s16((percent-90)*this.hits):0;
  this.scores[this.player]=u32(this.scores[this.player]+bonus);
  const summary={hits:this.hits,misses:this.misses,accuracy:percent,bonus,player:this.player,round:this.round,score:this.score};
  this.lastSummary=summary;this.rounds.push({...summary});
  if(!this.health[this.player])this.submit(this.player);
  const other=this.player?0:1;
  if(this.players.length===2&&this.health[other]){
   if(this.player===1)this.round++;
   this.player=other;
  }else if(this.health[this.player])this.round++;
  else{this.phase="game-over";this.finished=true;this.completed=true;this.publishSeed();return;}
  this.phase="level-end";this.prepareRound();
 }
 record(){
  return {version:1,kind:"letter-invaders-f5c",startedAt:this.startedAt,mode:this.mode,players:[...this.players],
   scores:[...this.scores],keys:this.keys,round:this.round,ticks:this.ticks,frames:this.ticks,
   completed:this.completed,aborted:this.aborted,submissions:this.submissions.map(s=>({...s})),rounds:this.rounds.map(s=>({...s}))};
 }
}
export function validInvadersRecord(r){
 const uint=n=>Number.isInteger(n)&&n>=0&&n<=0xffffffff;
 if(!r||r.version!==1||r.kind!=="letter-invaders-f5c"||!["practice","full"].includes(r.mode)||
  typeof r.startedAt!=="string"||!Number.isFinite(Date.parse(r.startedAt))||
  !Array.isArray(r.players)||r.players.length<1||r.players.length>2||!r.players.every(validGamePlayerName)||
  !Array.isArray(r.scores)||r.scores.length!==r.players.length||!r.scores.every(uint)||
  !Number.isInteger(r.keys)||r.keys<8||r.keys>64||(r.mode==="full"&&r.keys!==64)||!Number.isInteger(r.round)||r.round<1||r.round>65535||
  !uint(r.ticks)||r.frames!==r.ticks||typeof r.completed!=="boolean"||typeof r.aborted!=="boolean"||
  !Array.isArray(r.submissions)||!r.submissions.every(s=>s&&Number.isInteger(s.player)&&s.player>=0&&s.player<r.players.length&&uint(s.score)&&s.score===r.scores[s.player]&&s.keys===r.keys&&Number.isInteger(s.round)&&s.round>=1&&s.round<=r.round)||
  !Array.isArray(r.rounds)||!r.rounds.every(s=>s&&Number.isInteger(s.player)&&s.player>=0&&s.player<r.players.length&&Number.isInteger(s.round)&&s.round>=1&&s.round<=r.round&&uint(s.hits)&&s.hits<=65535&&uint(s.misses)&&s.misses<=65535&&uint(s.accuracy)&&s.accuracy<=100&&Number.isInteger(s.bonus)&&s.bonus>=-32768&&s.bonus<=32767&&uint(s.score)))return false;
 return true;
}
