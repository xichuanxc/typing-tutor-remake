/* ev_afe1af63319418133a606a12c195211512bae8ac75f8794056b1c0506afcd406 */

uint __cdecl16near FUN_1000_f156(int param_1)

{
  code *pcVar1;
  byte bVar3;
  uint uVar2;
  undefined2 unaff_DS;
  bool bVar4;
  
  if ((char)((uint)param_1 >> 8) == '\0') {
    param_1 = param_1 << 8;
  }
  bVar3 = (byte)((uint)param_1 >> 8);
  if (9 < bVar3) {
    bVar4 = bVar3 < 0x47;
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    if (bVar4) {
      *(uint *)0x8f00 = uVar2;
      uVar2 = 0xffff;
    }
    return uVar2;
  }
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  return uVar2 & 0xff;
}

