/* ev_75aa6825a0b78af1767ec6c2e9e86078d44059b85dba5964f3b7701cef2554c6 */

uint __cdecl16near FUN_1000_e5a1(uint *param_1)

{
  code *pcVar1;
  int iVar2;
  int in_CX;
  uint uVar3;
  uint extraout_DX;
  uint extraout_DX_00;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  uVar3 = in_CX - 0x76c;
  param_1[5] = uVar3;
  param_1[4] = (uint)(byte)((char)(extraout_DX >> 8) - 1);
  param_1[3] = extraout_DX & 0xff;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  param_1[2] = uVar3 >> 8;
  param_1[1] = uVar3 & 0xff;
  *param_1 = extraout_DX_00 >> 8;
  param_1[9] = extraout_DX_00 & 0xff;
  iVar2 = 0;
  if ((1 < param_1[4]) && ((param_1[5] & 3) == 0)) {
    iVar2 = 1;
  }
  uVar3 = iVar2 + *(int *)(param_1[4] * 2 + -0x1a77) + param_1[3];
  param_1[7] = uVar3;
  uVar3 = uVar3 + param_1[5] + (param_1[5] - 1 >> 2) + 1;
  param_1[6] = uVar3 % 7;
  param_1[8] = 0;
  return uVar3 / 7;
}

