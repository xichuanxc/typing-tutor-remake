/* ev_d1309eb658fe9ef2388aaaacdf0ecef658d792759c2ca7fdd44935381fea8d16 */

void __cdecl16near FUN_1000_4f2b(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  if (*(int *)0x9d2c < 8) {
    iVar4 = *(int *)0x9d5e;
    uVar3 = *(uint *)0x9d5c;
    puVar1 = param_1;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    param_1[1] = param_1[1] + iVar4 + (uint)CARRY2(uVar2,uVar3);
    puVar1 = param_2;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + 1;
    param_2[1] = param_2[1] + (uint)(0xfffe < uVar2);
  }
  iVar4 = *(int *)0x9d5e;
  uVar3 = *(uint *)0x9d5c;
  puVar1 = param_3;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar3;
  param_3[1] = param_3[1] + iVar4 + (uint)CARRY2(uVar2,uVar3);
  puVar1 = param_4;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  param_4[1] = param_4[1] + (uint)(0xfffe < uVar2);
  return;
}

