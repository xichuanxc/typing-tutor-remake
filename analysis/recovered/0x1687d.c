/* ev_1bd1baff88dd12fb2cb4c9cde8b997e8ac824c80bdcf6daf74e3b21f7103bb8c */

void __cdecl16near FUN_1000_687d(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar2 = FUN_1000_7251(0x20e0);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

