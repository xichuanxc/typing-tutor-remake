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
export class BoomletAudio{
 constructor(contextFactory){this.contextFactory=contextFactory;this.voice=null;}
 // Called from the user's start/key gesture, before asynchronous spawns can need sound.
 unlock(){try{this.contextFactory();}catch{/* Optional browser audio. */}}
 get playing(){return this.voice!==null;}
 start(){
  this.stop();
  try{
   const context=this.contextFactory();if(!context)return;
   const oscillator=context.createOscillator(),gain=context.createGain();
   oscillator.type="square";oscillator.connect(gain);gain.connect(context.destination);
   const start=context.currentTime,notes=boomletNotes();let end=start;
   for(const note of notes){oscillator.frequency.setValueAtTime(note.frequency,end);end+=note.duration;}
   gain.gain.setValueAtTime(.06,start);
   gain.gain.setValueAtTime(.06,Math.max(start,end-.004));
   gain.gain.linearRampToValueAtTime(0,end);
   const voice={oscillator,gain,context};this.voice=voice;
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
