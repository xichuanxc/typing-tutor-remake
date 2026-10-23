/* ev_84ee8bf4042e49e18f9aa487ef8d8404ccce892f0c7814360c4ea40213c37684 */

void __cdecl16near FUN_1000_665a(undefined2 param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined2 unaff_DS;
  uint local_6;
  
  iVar2 = FUN_1000_6592();
  if (*(byte *)0x90af < 8) {
    param_1 = *(undefined2 *)0x8893;
  }
  FUN_1000_6629(param_1,iVar2);
  iVar6 = iVar2;
  while ((*(int *)0x9d98 <= iVar6 && (iVar3 = FUN_1000_6802(), iVar3 == 0))) {
    iVar6 = iVar6 + -1;
    FUN_1000_6629(param_1,iVar6);
  }
  if (iVar6 < *(int *)0x9d98) {
    local_6 = iVar2 + 1;
    FUN_1000_6629(param_1,local_6);
    while ((local_6 <= *(byte *)0x90ae && (iVar2 = FUN_1000_6802(), iVar2 == 0))) {
      local_6 = local_6 + 1;
      FUN_1000_6629(param_1,local_6);
    }
    if (*(byte *)0x90ae < local_6) {
      FUN_1000_6629(param_1,iVar6);
      while ((-1 < iVar6 && (iVar2 = FUN_1000_6802(), iVar2 == 0))) {
        iVar6 = iVar6 + -1;
        FUN_1000_6629(param_1,iVar6);
      }
      if (iVar6 < 0) {
        FUN_1000_6629(param_1,local_6);
        while (iVar2 = FUN_1000_6802(), iVar2 == 0) {
          local_6 = local_6 + 1;
          FUN_1000_6629(param_1,local_6);
        }
      }
    }
  }
  *(undefined2 *)0x9d96 = 7;
  uVar4 = FUN_1000_6802();
  iVar2 = FUN_1000_bd74(uVar4);
  for (iVar6 = 0; iVar6 < iVar2; iVar6 = iVar6 + 1) {
    iVar3 = FUN_1000_6802();
    *(int *)0x9d94 = *(int *)0x9d94 + (iVar3 * 5 >> 3);
    uVar5 = iVar3 * 5 & 7;
    if (*(uint *)0x9d96 < uVar5) {
      *(int *)0x9d94 = *(int *)0x9d94 + 1;
      *(int *)0x9d96 = (*(int *)0x9d96 + 8) - uVar5;
    }
    else {
      *(int *)0x9d96 = *(int *)0x9d96 - uVar5;
    }
  }
  iVar2 = FUN_1000_6802();
  param_2 = (byte *)((int)param_2 + -1);
  for (iVar6 = 0; iVar6 < iVar2; iVar6 = iVar6 + 1) {
    bVar1 = FUN_1000_6802();
    param_2 = param_2 + 1;
    *param_2 = bVar1 | 0x60;
    if ((bVar1 | 0x60) == 0x60) {
      *param_2 = 0x20;
    }
    else if (*param_2 == 0x7b) {
      iVar3 = FUN_1000_72dd(0x2d);
      if (iVar3 == 0) {
        bVar1 = 0x20;
      }
      else {
        bVar1 = 0x2d;
      }
      *param_2 = bVar1;
    }
    else if (*param_2 == 0x7e) {
      iVar3 = FUN_1000_72dd(0x2e);
      if (iVar3 == 0) {
        bVar1 = 0;
      }
      else {
        bVar1 = 0x2e;
      }
      *param_2 = bVar1;
    }
  }
  param_2[1] = 0;
  return;
}

