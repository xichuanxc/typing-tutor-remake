import G from "./invaders-data.js";
import {BIOS_TICK_MS} from "./invaders.js";

// Native17e47 case0: six descending octaves, 12 pitches each;17a75/17ce8 quantize time.
export function boomletNotes(){
 const {pitches,durationMs,pitHundredths}=G.boomletSound;
 const duration=Math.floor((durationMs*182+5000)/10000)*BIOS_TICK_MS/1000,notes=[];
 for(let scale=1;scale<64;scale*=2)for(const pitch of pitches){
  const divisor=Math.trunc(pitHundredths/Math.trunc(pitch/scale))&0xffff;
  notes.push({frequency:pitHundredths/100/(divisor||65536),duration});
 }
 return notes;
}
// Native 8-byte pitch/duration/rest records, with PIT and BIOS-tick quantization.
function recordNotes(records){
 const notes=[],ticks=ms=>Math.floor((ms*182+5000)/10000)*BIOS_TICK_MS/1000;
 for(const [pitch,durationMs,silenceMs] of records){
  const divisor=pitch?Math.trunc(G.boomletSound.pitHundredths/pitch)&0xffff:0;
  notes.push({frequency:pitch?G.boomletSound.pitHundredths/100/(divisor||65536):0,duration:ticks(durationMs)});
  const rest=ticks(silenceMs);if(rest)notes.push({frequency:0,duration:rest});
 }
 return notes;
}
export const GAME_SOUND_TYPES=Object.freeze(["boomlet","ship","wrong","hit","impact"]);
export function wordShipNotes(){return recordNotes(G.wordShipSound.notes);}
export function soundNotes(kind){
 if(kind==="boomlet")return boomletNotes();
 if(kind==="ship")return wordShipNotes();
 return G.gameSounds[kind]?recordNotes(G.gameSounds[kind]):[];
}
export class GameAudio{
 constructor(contextFactory){this.contextFactory=contextFactory;this.voice=null;}
 // Called from the user's start/key gesture, before asynchronous spawns can need sound.
 unlock(){try{this.contextFactory();}catch{/* Optional browser audio. */}}
 get playing(){return this.voice!==null;}
 get kind(){return this.voice?.kind??null;}
 play(kind){
  if(!GAME_SOUND_TYPES.includes(kind))return false;
  // Original short cues are dropped while another effect occupies the speaker queue.
  if(kind!=="boomlet"&&kind!=="ship"&&this.playing)return false;
  this.start(kind);return this.playing;
 }
 update(events,{enabled=true,playing=true,specialType=0}={}){
  if(!enabled||!playing){this.stop();return;}
  if((this.kind==="boomlet"&&specialType!==2)||(this.kind==="ship"&&specialType!==3))this.stop();
  for(const event of events)this.play(event.type);
 }
 start(kind="boomlet"){
  const notes=soundNotes(kind);if(!notes.length)return;
  this.stop();
  try{
   const context=this.contextFactory();if(!context)return;
   const oscillator=context.createOscillator(),gain=context.createGain();
   oscillator.type="square";oscillator.connect(gain);gain.connect(context.destination);
   const start=context.currentTime;let end=start;
   for(const note of notes){
    if(note.frequency)oscillator.frequency.setValueAtTime(note.frequency,end);
    gain.gain.setValueAtTime(note.frequency > 0 ? .06 : 0,end);end+=note.duration;
   }
   gain.gain.setValueAtTime(notes.at(-1)?.frequency > 0 ? .06 : 0,Math.max(start,end-.004));
   gain.gain.linearRampToValueAtTime(0,end);
   const voice={oscillator,gain,context,kind};this.voice=voice;
   oscillator.onended=()=>{oscillator.disconnect();gain.disconnect();if(this.voice===voice)this.voice=null;};
   oscillator.start(start);oscillator.stop(end);
  }catch{this.stop();}
 }
 stop(){
  const voice=this.voice;if(!voice)return;this.voice=null;
  try{
   voice.gain.gain.cancelScheduledValues(voice.context.currentTime);
   voice.gain.gain.setValueAtTime(0,voice.context.currentTime);
   voice.oscillator.stop();
  }catch{/* It may already have ended. */}
 }
}

// Preserve the earlier module name for already-cached app modules during deployment.
export {GameAudio as BoomletAudio};
