/* ev_edfb16c22c18ac0ff1164b663a7d8c56c724d4ae4e723fda84126b61778a7992 */

void __cdecl16near FUN_1000_708a(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_72ff(0x2108);
  if (iVar3 == 0) goto LAB_1000_7105;
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x28;
  FUN_1000_73cc(unaff_BP + 4);
  iVar3 = FUN_1000_72dd(0x30);
  if (iVar3 == 0) {
    iVar3 = FUN_1000_72dd(0x31);
    if (iVar3 != 0) goto LAB_1000_70c5;
    FUN_1000_73eb(unaff_BP + 4);
  }
  else {
LAB_1000_70c5:
    uVar2 = FUN_1000_7251(0x210b);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = uVar2;
  }
  FUN_1000_73cc(unaff_BP + 4);
  iVar3 = FUN_1000_72dd(0x29);
  if (iVar3 != 0) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x29;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
LAB_1000_7105:
  FUN_1000_73eb(unaff_BP + 4);
  FUN_1000_73eb(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x2d;
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

