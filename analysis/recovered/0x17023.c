/* ev_65eca36ed2b8874fd92ef91d121153439f0b8e6f5f35b7deb6affd9b5329d67d */

void __cdecl16near FUN_1000_7023(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_745c(unaff_BP + 4);
  for (iVar3 = FUN_1000_bd74(2); -1 < iVar3; iVar3 = iVar3 + -1) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x3a;
    FUN_1000_740a(unaff_BP + 4);
    FUN_1000_73ad(unaff_BP + 4);
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  uVar4 = FUN_1000_7251(0x2105);
  uVar2 = FUN_1000_e793(uVar4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x4d;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

