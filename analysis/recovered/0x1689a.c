/* ev_c74e27c7b593713c0669efd551f81d3b7b5b5600e90e486031efae4590550f91 */

void __cdecl16near FUN_1000_689a(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar2 = FUN_1000_7251(0x20e4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

