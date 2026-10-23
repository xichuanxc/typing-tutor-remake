/* ev_c6801433e5e8ac2fba03a6ff213ff29a292e4b8a0b0aab5f734497dcb5657aa4 */

uint __cdecl16near FUN_1000_e8c5(byte param_1,uint *param_2)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  if (*param_2 < param_2[1]) {
    pbVar1 = (byte *)*param_2;
    *param_2 = *param_2 + 1;
    *pbVar1 = param_1;
    uVar2 = (uint)param_1;
  }
  else {
    uVar2 = FUN_1000_e983(param_2,param_1);
  }
  return uVar2;
}

