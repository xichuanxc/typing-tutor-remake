/* ev_2f10fd34ce10b4a80aa70ed7d6f46e9593e6a1f6d383a8cfed8397eb21e50219 */

void __cdecl16near
FUN_1000_4e95(char param_1,undefined2 param_2,int *param_3,int *param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 unaff_DS;
  
  iVar5 = FUN_1000_f139(param_2);
  if (((param_1 != '\r') && (param_1 != ' ')) && (param_1 != '+')) {
    *(undefined1 *)(iVar5 + 0x900) = 1;
    FUN_1000_b1f3(0,2,4);
    FUN_1000_4e79(*(int *)0x9d6c + -2,*(int *)0x9d6e + -1,0x19);
    FUN_1000_b1f3(0,2,7);
  }
  for (iVar7 = 0; iVar7 < iVar5 + 1; iVar7 = iVar7 + 1) {
    if (*(char *)(iVar7 + 0x900) == '\0') {
      *param_3 = *param_3 + 1;
    }
    else {
      *param_4 = *param_4 + 1;
    }
  }
  iVar5 = *(int *)0x9d66;
  uVar3 = *(uint *)0x9d64;
  uVar4 = *(uint *)0x9d5c;
  uVar6 = uVar3 - *(uint *)0x9d5c;
  iVar7 = *(int *)0x9d5e;
  puVar1 = param_5;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar6;
  param_5[1] = param_5[1] + ((iVar5 - iVar7) - (uint)(uVar3 < uVar4)) + (uint)CARRY2(uVar2,uVar6);
  return;
}

