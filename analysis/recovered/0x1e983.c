/* ev_10678eea9da8a6dc35df292dba60d52c53ce5dcbb4bfc3358ba87988bb14f41e */

uint __cdecl16near FUN_1000_e983(int *param_1,uint param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x8f0e = 0xe8f5;
  if ((*(byte *)(param_1 + 3) & 0x10) != 0) {
    return 0xffff;
  }
  if (((*(byte *)(param_1 + 3) & 4) == 0) ||
     (iVar4 = *param_1, iVar1 = param_1[2],
     iVar3 = FUN_1000_f3e7((int)*(char *)((int)param_1 + 7),param_1[2],iVar4 - iVar1),
     iVar3 == iVar4 - iVar1)) {
    if (param_2 == 0xffff) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfb;
      *param_1 = 0;
      param_1[1] = 0;
      return 0;
    }
    if (param_1[2] == 0) {
      FUN_1000_ea5e(param_1);
    }
    if (*(int *)((int)param_1 + 9) != 1) {
      iVar4 = param_1[2];
      *param_1 = iVar4;
      param_1[1] = iVar4 + *(int *)((int)param_1 + 9);
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 4;
      puVar2 = (undefined1 *)*param_1;
      *param_1 = *param_1 + 1;
      *puVar2 = (char)param_2;
      return param_2 & 0xff;
    }
    iVar4 = FUN_1000_f3e7((int)*(char *)((int)param_1 + 7),&param_2,1);
    if (iVar4 == 1) {
      return param_2;
    }
  }
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x10;
  *param_1 = 0;
  param_1[1] = 0;
  return 0xffff;
}

