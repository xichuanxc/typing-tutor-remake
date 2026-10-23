/* ev_eccf411c59634d57677acdcefc51af001e61528de240c87c2b249bd8ef8b29c9 */

void __cdecl16near FUN_1000_c2da(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar2 = FUN_1000_72dd(0x2c);
  if (iVar2 != 0) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x2c;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

