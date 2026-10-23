// Full grammar path of 0x15854, 0x1618a, 0x1639e, 0x164cc, 0x16592/0x1665a.
import DATA from "./curriculum-data.js";
import {numericCallback} from "./numeric-generator.js";
import {mastered,alphabeticWeightTotal} from "./curriculum.js";
export class DosRandom{
  constructor(state){this.state=state;}
  next(n){
    if(!Number.isInteger(n)||n<0||n>32767)throw Error("Invalid random range");
    this.state.seed=(Math.imul(this.state.seed??0,0xe4f5)+0x3619)&0xffff;
    return Math.floor(n*(this.state.seed>>>8)/256);
  }
}
const titleCase=s=>s.replace(/(^| )([a-z])/g,(_,space,c)=>space+c.toUpperCase());
const trimNul=s=>s.split("\0")[0];
export class DrillGenerator{
  constructor(state,{testType=0}={}){
    this.testType=testType;this.state=state;this.random=new DosRandom(state);this.buffer="";this.fresh=true;
    this.stack=[];this.pointer=null;this.join=false;this.pair="";this.quote="";this.upperNext=false;
  }
  known(char){const index=DATA.keyIndex[char]??255;return index>=0&&index<=this.state.introduced;}
  choose(chars){
    const candidates=[...chars].filter(c=>this.known(c));if(!candidates.length)return "";
    const weights=candidates.map(c=>this.state.weights[DATA.keyIndex[c]]);
    let n=this.random.next(weights.reduce((a,b)=>a+b,0)),sum=weights[0],i=0;
    while(sum<n){sum+=weights[++i];}
    return candidates[i];
  }
  optional(chars){const c=this.choose(chars);return c&&this.random.next(127)<=this.state.weights[DATA.keyIndex[c]]?c:"";}
  isMastered(index){return this.testType!==3&&mastered(this.state,index);}
  weighted(start,end){
    const weights=[];
    for(let i=start;i<end&&i<=this.state.introduced;i++)weights.push(this.state.weights[i]*(!this.isMastered(i)&&(start>21||i>28)?7:1));
    let n=this.random.next(weights.reduce((a,b)=>a+b,0)),i=0;
    // Native 57cc subtracts until negative; zero-range still returns its first slot.
    while(n>=0){n-=weights[i++]??0;if(i>weights.length+1)throw Error("Empty key weighting");}
    return start+i-1;
  }
  rule(){
    let index=this.state.introduced>28?21:0;const start=index,totals=[];
    for(const boundary of DATA.boundaries){let total=0;for(;index<boundary&&index<=this.state.introduced;index++)total+=this.state.weights[index]*(!this.isMastered(index)&&index>28?2:1);totals.push(total);}
    const draw=this.random.next(totals.reduce((a,b)=>a+b,0));
    if(draw<=totals[0]){
      const key=this.weighted(start,37);
      if(key===15)return this.random.next(4)+12;
      if(key===29||key===31)return this.random.next(3)+40;
      if(key===30)return this.random.next(2)+48;
      if(key===32)return this.random.next(7)+26;
      if(key===33)return this.random.next(2)+46;
      if(key===34||key===35)return 21;
      if(key===36)return this.random.next(2)+14;
      return this.state.introduced<9?this.random.next(DATA.earlyRanges[this.state.alphabetic])+5:
        this.random.next(DATA.earlyRanges[this.state.alphabetic]-2)+7;
    }
    if(draw-totals[0]<=totals[1])return this.random.next(7)+33;
    const key=this.weighted(47,64)-47;
    if([0,2,3,5,7].includes(key))return 22;
    if(key===1)return this.random.next(2)+44;
    if(key===4)return this.random.next(2)+48;
    if(key===6)return 43;
    if(key===8||key===9)return this.random.next(2)+21;
    if(key===10)return this.random.next(3)+22;
    if(key>=11&&key<=14)return 21;
    if(key===15||key===16)return 50;
    return key;
  }

  begin(){
    this.pointer=DATA.grammarOffsets[this.rule()];this.stack=[];this.join=false;this.pair="";this.quote="";
  }
  dictionary(classId){
    const total=alphabeticWeightTotal(this.state),order=DATA.alphabetFrequency;
    let n=this.random.next(total),sum=this.state.weights[DATA.keyIndex[order[0]]],letter=0;
    while(sum<n){letter++;sum+=this.state.weights[DATA.keyIndex[order[letter]]];}
    const minimum=Math.max(0,letter-3),span=this.state.alphabetic-minimum+1;
    n=this.random.next(Math.trunc((span+1)*span/2));sum=span;let level=minimum,step=span;
    while(sum<n){step--;level++;sum+=step;}
    if(this.state.introduced<8)classId=DATA.defaultDictionaryClass;
    const listAt=i=>DATA.dictionary[DATA.dictionaryIndex[classId]?.[i]]??[];
    let lower=level;
    while(lower>=minimum&&!listAt(lower).length)lower--;
    let selected=lower;
    if(lower<minimum){
      level++;while(level<=this.state.alphabetic&&!listAt(level).length)level++;
      selected=level;
      if(level>this.state.alphabetic){
        selected=lower;while(selected>=0&&!listAt(selected).length)selected--;
        if(selected<0){selected=level;while(selected<23&&!listAt(selected).length)selected++;}
      }
    }
    const list=listAt(selected);if(!list.length)throw Error("No recovered word list for this key");
    const raw=list[this.random.next(list.length)];
    return trimNul(raw.map(v=>{
      if(v===0)return " ";
      if(v===27)return this.known("-")?"-":" ";
      if(v===30)return this.known(".")?".":"\0";
      return String.fromCharCode(v|0x60);
    }).join(""));
  }
  word(alias){return this.dictionary(DATA.dictionaryClasses[alias]);}
  plural(s){return s+(/(s|sh|ch)$/.test(s)?"es":"s");}
  article(noun){
    // c1d3: one-byte article slot before the remaining word; insert n only when
    // its following token is empty and the noun starts with a vowel.
    const word=this.word(8);
    return word+(word.length===1&&/^[aeiou]/.test(noun)&&this.known("n")?"n":"")+" ";
  }
  callback(id){
    const strings=DATA.selectionStrings;
    if((id>=3&&id<=11)||id===15)return numericCallback(this,id);
    if(id===0)return this.choose(strings["20e0"]);
    if(id===1)return this.choose(strings["20e4"]);
    if(id===2)return "?";
    if(id===12)return "!";
    if(id===13)return this.known(",")?",":"";
    if(id===14)return this.optional(strings["85fe"])?strings["8600"]:strings["8602"];
    const simple={17:0,18:20,19:21,20:0,21:20,22:2,27:10,28:9,31:16,32:7,33:7,34:22,35:18,36:17,37:12,38:12,39:12,40:31,41:31,42:19,43:15};
    let s="";
    if(id===16)s=titleCase(this.word(this.random.next(2)+20));
    else if(id===23)s=this.word(this.random.next(4)===0?this.random.next(2)+9:11);
    else if(id===24)s=this.word(this.random.next(4)+27);
    else if(id===25||id===26||id===29||id===30||[27,28,31,32,34,35,36].includes(id)){
      let noun;
      if(id===25||id===26||id===29)noun=this.callback(23);
      else if(id===30)noun=this.callback(24);
      else noun=this.word(simple[id]);
      s=id===26?this.plural(noun):this.article(noun)+noun;
      if(id===29)s+="'s";
    }else if(Object.hasOwn(simple,id))s=this.word(simple[id]);
    else throw Error("Unimplemented nonalphabetic grammar callback "+id);
    if([17,18,19,20,21,22].includes(id))s=titleCase(s);
    if([20,21].includes(id))s+="'s";
    if([33,39].includes(id))s=this.plural(s);
    if([37,40,42,43].includes(id))s=s.replace(/e$/,"")+"ed";
    if([38,41].includes(id))s=s.replace(/e$/,"")+"ing";
    return s;
  }
  token(){
    for(let budget=0;budget<256;budget++){
      const code=DATA.grammar[this.pointer++];
      if(code===undefined)throw Error("Recovered grammar pointer outside resource");
      if(code===0){
        if(DATA.grammar[this.pointer]===0){
          if(!this.stack.length)return null;
          this.pointer=this.stack.pop();continue;
        }
        let text="";while(DATA.grammar[this.pointer])text+=String.fromCharCode(DATA.grammar[this.pointer++]);this.pointer++;
        return text;
      }
      if(code&128)return this.callback(code&127);
      if(code&64){this.stack.push(this.pointer);this.pointer=DATA.grammarOffsets[code&63];continue;}
      return this.dictionary((code&63)-1);
    }
    throw Error("Recovered grammar iteration limit");
  }
  nextToken(){
    if(this.pointer===null)this.begin();
    let spacing=this.join?0:1;this.join=false;
    for(let budget=0;budget<256;budget++){
      let text=this.token();
      if(text===null){this.begin();this.fresh=true;continue;}
      if(!text)continue;
      if(this.fresh){
        spacing=this.state.shiftLearned?2:1;
        if(text[0]==="'"||text[0]==='"')this.upperNext=true;
        else text=text[0].toUpperCase()+text.slice(1);
        this.fresh=false;
      }else{
        if(this.upperNext){text=text[0].toUpperCase()+text.slice(1);this.upperNext=false;}
        const c=text[0],flags=DATA.charFlags[c.charCodeAt(0)]??0;
        if(!(flags&7)&&!this.join&&!"$-_^&(".includes(c))spacing=0;
      }
      if(!this.state.shiftLearned)text=text.toLowerCase();
      return {text,spacing};
    }
    throw Error("Recovered token iteration limit");
  }
  line(max=26){
    if(this.fresh)this.buffer="";
    let output=this.buffer;
    for(let budget=0;output.length<=max+32&&budget<256;budget++){
      const {text,spacing}=this.nextToken();output+=(output?" ".repeat(spacing):"")+text;
    }
    if(output.length<=max+32)throw Error("Recovered line generation limit");
    let split=max;while(split>=0&&output[split]>" ")split--;
    let end,next;
    if(split<0){end=max;next=max+1;while(output[next]>" ")next++;}
    else{while(split>=0&&output[split]<"!")split--;end=split+1;next=split+2;}
    while(output[next]===" ")next++;
    const line=output.slice(0,end);this.buffer=output.slice(next);
    if(line.length<2||line.length>max)throw Error("Invalid recovered drill line");
    return line;
  }
  homeDrill(newKey,first=false){
    const index=DATA.keyIndex[newKey],other=DATA.counterpart[index];let out="";
    for(let i=0;i<26-3;i+=5){
      const group=[other,newKey,other,newKey];
      if(!first)for(let j=3;j>0;j--){const k=this.random.next(j+1);[group[j],group[k]]=[group[k],group[j]];}
      first=false;out+=group.join("")+" ";
    }
    return out.trimEnd();
  }
}
