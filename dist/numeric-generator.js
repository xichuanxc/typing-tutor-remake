// Recovered callbacks 0x168e3..0x171ce and numeric helpers 0x173ad..0x175e2.
// Static assembly translation; integer formatting deliberately retains native quirks.
import DATA from './curriculum-data.js';
const titleCase=s=>s.replace(/(^| )([a-z])/g,(_,space,c)=>space+c.toUpperCase());
export function formatNumber(raw,money=false){
  const s=String(raw),width=money?5:3,negative=s[0]==='-';let i=0,out='';
  if(s.length>width+Number(negative)){while(i<s.length-width)out+=s[i++];out+=',';}
  while(i<s.length-width+3)out+=s[i++];
  if(money){out+='.';out+=s.length>1?s[i++]:'0';out+=s[i];}
  return out;
}
export function numericCallback(g,id){
  const strings=DATA.selectionStrings,r=n=>g.random.next(n),pick=address=>g.choose(strings[address]),opt=address=>g.optional(strings[address]);
  const digit=()=>pick('2116'),nonzero=()=>pick('2121'),twoUp=()=>pick('212b'),zeroFive=()=>pick('2134');
  const hour=()=>opt('213f')?'1'+pick('213b'):nonzero();
  const word=i=>titleCase(g.word(i));
  const digits=n=>Array.from({length:n},digit).join('');
  if(id===3||id===11){
    const field=id===3?'pair':'quote';
    if(g[field]){const closing=g[field];g[field]='';return closing;}
    const opening=pick(id===3?'20eb':'2113');
    if(opening){g.join=true;const closing=({'(':')','[':']','{':'}','<':'>'})[opening]??opening;g[field]=g.known(closing)?closing:'';}
    return opening;
  }
  if(id===4){
    let s=nonzero();const count=r(2)+r(4);s+=digits(Math.max(0,4-count));s+=' '+word(0)+' '+word(1);
    if(r(5)!==0){s+=', '+word(2)+', ';const country=r(11);let region=word(country===0?3:4);if(region.length===2)region=region[0]+region[1].toUpperCase();s+=region+' ';
      s+=country===0?pick('7aee').toUpperCase()+digit()+pick('7aee').toUpperCase()+' '+digit()+pick('7aee').toUpperCase()+digit():digits(5)+(opt('20f0')?'-'+digits(4):'');
    }
    return s;
  }
  if(id===5)return '$'+formatNumber(nonzero()+digits(r(8)),true);
  if(id===7){
    const separator=opt('20ff');let s='';
    if(!separator){if(r(3)!==0)s+=word(5)+', ';s+=word(6)+' ';}else s+=hour()+separator;
    const tens=opt('2102');s+=tens?tens+digit():nonzero();
    if(!separator){if(r(3)!==0)s+=', 1'+digits(3);}else s+=separator+digits(2);
    return s;
  }
  if(id===8){let s=hour();for(let i=r(2);i>=0;i--)s+=':'+zeroFive()+digit();return s+' '+pick('2105').toUpperCase()+'M';}
  if(id===9){let s='';if(opt('2108')){s+='('+nonzero();s+=g.known('0')||g.known('1')?pick('210b'):twoUp();s+=nonzero();if(g.known(')'))s+=')';s+=' ';}return s+twoUp()+twoUp()+digit()+'-'+digits(4);}
  if(id===10)return strings['210e']+'#'+digits(3)+'-'+digits(2)+'-'+digits(4);
  if(id===15){
    let s=strings[r(2)?'8606':'860d']+pick('8617');let underscore=r(2);if(!g.known('_'))underscore=0;s+=' ';
    const quote=r(2);if(quote)s+=numericCallback(g,11);s+=underscore?'_':'^';if(quote)s+=numericCallback(g,11);
    if(r(2))s+=' '+strings[underscore?'861a':'8627'];return s;
  }
  if(id!==6)throw Error('Unknown numeric callback '+id);
  const operator=pick('20f2');let a,b,result,ma=false,mb=false,mr=false;
  const operand=()=>{const sign=opt('20f9')?'-':'0';return Number(sign+digits(3));};
  a=operand();b=operand();
  if(operator==='@'||operator==='%'){a=Math.abs(a);b=Math.abs(b);}
  const currency=()=>{const yes=!!opt('2141');if(yes){a=Math.abs(a);b=Math.abs(b);}return yes;};
  if(operator==='+'){ma=mb=mr=currency();result=(a+b)|0;}
  else if(operator==='-'){ma=mb=mr=currency();const first=a;a=(b+first)|0;b=first;result=(a-b)|0;}
  else if(operator==='*'){ma=mr=currency();result=Math.imul(a,b);}
  else if(operator==='/'){ma=mr=currency();result=b;b=a;a=Math.imul(a,result);}
  else if(operator==='@'){mb=mr=true;result=Math.imul(a,b);}
  else if(operator==='%'){mb=mr=true;a=Math.trunc(a/10)||100;result=b;b=Math.trunc(b*100/a);}
  else throw Error('Recovered arithmetic operator unavailable');
  let s=(ma?'$':'')+formatNumber(a,ma)+' ';
  if(operator==='@')s+=g.callback(33)+' ';
  s+=operator+' '+(operator==='%'?strings['20fb']:'')+(mb?'$':'')+formatNumber(b,mb)+' ';
  let comparison='=';
  if(result!==0){comparison=pick('2149');if(comparison!=='='){const factor=r(100)+r(100)+1;result=(comparison==='>'&&result>=0)||(comparison==='<'&&result<0)?Math.trunc(result/factor):Math.imul(result,factor);}}
  return s+comparison+' '+(mr?'$':'')+formatNumber(result,mr);
}
