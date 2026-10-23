/* ev_b2c17634a910cf249c193dffba7009d9baab4135b719d2fb5e351f5187671d31 */

void __cdecl16near FUN_1000_c32b(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_bd74(2);
  if (iVar3 == 0) {
    uVar4 = 0x860d;
  }
  else {
    uVar4 = 0x8606;
  }
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),uVar4);
  iVar3 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar3;
  uVar2 = FUN_1000_7251(0x8617);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  iVar3 = FUN_1000_bd74(2);
  iVar5 = FUN_1000_72dd(0x5f);
  if (iVar5 == 0) {
    iVar3 = 0;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  iVar5 = FUN_1000_bd74(2);
  if (iVar5 != 0) {
    uVar4 = *(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    FUN_1000_71ce(uVar4);
  }
  uVar2 = 0x5e;
  if (iVar3 != 0) {
    uVar2 = 0x5f;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  if (iVar5 != 0) {
    uVar4 = *(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    FUN_1000_71ce(uVar4);
  }
  iVar5 = FUN_1000_bd74(2);
  if (iVar5 == 0) {
    *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    uVar4 = 0x8627;
    if (iVar3 != 0) {
      uVar4 = 0x861a;
    }
    FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),uVar4);
  }
  return;
}

