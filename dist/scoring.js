// Original unsigned integer kernels: 0x1529a and 0x152dc.
export function accuracy(correct,errors){
  const total=(correct+errors)>>>0;
  return total?Math.floor((Math.imul(correct,100)>>>0)/total)&0xffff:0;
}
export function speed(a,b,time){
  time>>>=0;
  return time?Math.floor((Math.imul((a+b)>>>0,1200)>>>0)/time)&0xffff:0;
}
