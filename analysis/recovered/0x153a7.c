/* ev_3ef0d861f507eba77a5fa76ef051f3ecb45c32955cbd659564f928337f376ed7 */

undefined2 __cdecl16near FUN_1000_53a7(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(int *)(unaff_BP + 4) < 0x1d) {
    bVar2 = *(byte *)0x90b3;
  }
  else {
    bVar2 = *(byte *)0x90b4;
  }
  uVar4 = (uint)bVar2;
  iVar5 = *(int *)(unaff_BP + 4) * 4;
  uVar3 = FUN_1000_52dc(*(undefined2 *)(iVar5 + -0x6dce),*(undefined2 *)(iVar5 + -0x6dcc),
                        *(undefined2 *)(iVar5 + -0x6ca2),*(undefined2 *)(iVar5 + -0x6ca0),
                        *(undefined2 *)(iVar5 + -0x6efa),*(undefined2 *)(iVar5 + -0x6ef8));
  if (uVar4 <= uVar3) {
    iVar5 = *(int *)(unaff_BP + 4) * 4;
    uVar4 = FUN_1000_529a(*(undefined2 *)(iVar5 + -0x6dce),*(undefined2 *)(iVar5 + -0x6dcc),
                          *(undefined2 *)(iVar5 + -0x6ca2),*(undefined2 *)(iVar5 + -0x6ca0));
    if (*(byte *)0x1c90 <= uVar4) {
      iVar5 = *(int *)(unaff_BP + 4) * 4;
      uVar4 = *(uint *)(iVar5 + -0x6dce);
      iVar6 = *(int *)(unaff_BP + 4) * 4;
      puVar1 = (uint *)(iVar6 + -0x652c);
      if ((*(int *)(iVar5 + -0x6dcc) + *(int *)(iVar6 + -0x652a) + (uint)CARRY2(uVar4,*puVar1) != 0)
         || ((uint)*(byte *)0x1c91 <= uVar4 + *puVar1)) {
        return 0;
      }
    }
  }
  return 1;
}

