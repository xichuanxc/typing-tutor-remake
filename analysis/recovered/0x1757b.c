/* ev_3f29a50c2146aebe948cf3954560e86a3c9670564f6c47b52c36d8fe85bd2113 */

undefined2 __cdecl16near FUN_1000_757b(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  int *piVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_72ff(0x2141);
  if (iVar1 != 0) {
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      puVar3 = (undefined2 *)(iVar1 * 4 + *(int *)(unaff_BP + 4));
      iVar2 = FUN_1000_bd33(*puVar3,puVar3[1]);
      piVar4 = (int *)(iVar1 * 4 + *(int *)(unaff_BP + 4));
      piVar4[1] = iVar2 >> 0xf;
      *piVar4 = iVar2;
    }
    return 1;
  }
  return 0;
}

