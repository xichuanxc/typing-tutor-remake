/* ev_1a8a644451b73b2b68cb5742f3faff57be00b3f1fbfac7b602657232fa7884e5 */

void __cdecl16near FUN_1000_02e0(void)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar6;
  
  FUN_1000_e7bd();
  if (*(char *)0x99a2 == '\0') {
    uVar2 = *(uint *)*(int *)(unaff_BP + 4);
    puVar1 = (uint *)*(int *)(unaff_BP + 6);
    iVar4 = uVar2 + *puVar1;
    iVar5 = ((uint *)*(int *)(unaff_BP + 4))[1] + ((uint *)*(int *)(unaff_BP + 6))[1] +
            (uint)CARRY2(uVar2,*puVar1);
  }
  else {
    uVar6 = FUN_1000_f0a7();
    puVar1 = (uint *)*(int *)(unaff_BP + 6);
    iVar4 = (uint)uVar6 + *puVar1;
    iVar5 = (int)((ulong)uVar6 >> 0x10) + ((uint *)*(int *)(unaff_BP + 6))[1] +
            (uint)CARRY2((uint)uVar6,*puVar1);
  }
  piVar3 = (int *)*(int *)(unaff_BP + 4);
  piVar3[1] = iVar5;
  *piVar3 = iVar4;
  return;
}

