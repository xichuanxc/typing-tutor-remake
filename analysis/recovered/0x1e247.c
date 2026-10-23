/* ev_7e9021bc355a53ec0bbf2ef21526d7d52876bb1a09b6c1f948daa8a966397d16 */

undefined2 __cdecl16near FUN_1000_e247(int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  int extraout_DX;
  undefined2 unaff_DS;
  bool bVar4;
  
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xf7;
  if ((*(byte *)(param_1 + 3) & 4) == 0) {
    if ((param_4 == 1) && (*param_1 != 0)) {
      uVar2 = param_1[1] - *param_1;
      bVar4 = param_2 < uVar2;
      param_2 = param_2 - uVar2;
      param_3 = (param_3 - ((int)uVar2 >> 0xf)) - (uint)bVar4;
    }
  }
  else {
    iVar1 = FUN_1000_e983(param_1,0xffff);
    if (iVar1 != 0) {
      return 0xffff;
    }
  }
  param_1[1] = 0;
  *param_1 = 0;
  FUN_1000_f42e((int)*(char *)((int)param_1 + 7),param_2,param_3,param_4);
  if ((extraout_DX < 1) && (extraout_DX != 0)) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

