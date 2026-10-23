/* ev_bcde1ae33f864d801226c0f1120bb137890594dd005ea378d8a10ca3b5da68f3 */

void __cdecl16near FUN_1000_69a0(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_73cc(unaff_BP + 4);
  iVar3 = FUN_1000_bd74(2);
  iVar4 = FUN_1000_bd74(4);
  for (iVar3 = iVar3 + iVar4; iVar3 < 4; iVar3 = iVar3 + 1) {
    FUN_1000_73ad(unaff_BP + 4);
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  FUN_1000_737b(unaff_BP + 4,0);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  FUN_1000_737b(unaff_BP + 4,1);
  iVar3 = FUN_1000_bd74(5);
  if (iVar3 != 0) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x2c;
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    FUN_1000_737b(unaff_BP + 4,2);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x2c;
    *(undefined2 *)(unaff_BP + -2) = *(undefined2 *)(unaff_BP + 4);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    iVar3 = FUN_1000_bd74(0xb);
    if (iVar3 == 0) {
      FUN_1000_737b(unaff_BP + 4,3);
    }
    else {
      FUN_1000_737b(unaff_BP + 4,4);
    }
    if (*(int *)(unaff_BP + 4) - *(int *)(unaff_BP + -2) == 3) {
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
      uVar2 = FUN_1000_e793((int)*(char *)*(undefined2 *)(unaff_BP + 4));
      *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = uVar2;
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    }
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    if (iVar3 == 0) {
      FUN_1000_748b(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_748b(unaff_BP + 4);
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x20;
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_748b(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
    }
    else {
      for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {
        FUN_1000_73ad(unaff_BP + 4);
      }
      iVar3 = FUN_1000_72ff(0x20f0);
      if (iVar3 != 0) {
        puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
        *puVar1 = 0x2d;
        FUN_1000_73ad(unaff_BP + 4);
        FUN_1000_73ad(unaff_BP + 4);
        FUN_1000_73ad(unaff_BP + 4);
        FUN_1000_73ad(unaff_BP + 4);
      }
    }
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

