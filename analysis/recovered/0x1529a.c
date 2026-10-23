/* ev_b5ef276a5592952c2b672a132729ceef384f60c3a1ae2c710cb787e14ae3498e */

undefined2 __cdecl16near FUN_1000_529a(void)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = *(uint *)(unaff_BP + 4) + *(uint *)(unaff_BP + 8);
  iVar3 = *(int *)(unaff_BP + 6) + *(int *)(unaff_BP + 10) +
          (uint)CARRY2(*(uint *)(unaff_BP + 4),*(uint *)(unaff_BP + 8));
  *(int *)(unaff_BP + -2) = iVar3;
  *(int *)(unaff_BP + -4) = iVar1;
  if (iVar3 == 0 && iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_1000_f0a7();
  }
  return uVar2;
}

