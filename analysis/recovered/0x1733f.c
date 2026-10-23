/* ev_73117c6b40f913d97c60d0dfea14b0007bbd8b4cc2e51919db8b24c6eca0fa83 */

void __cdecl16near FUN_1000_733f(void)

{
  undefined1 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e793((int)*(char *)*(undefined2 *)(unaff_BP + 4));
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = uVar1;
  while( true ) {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    if (*(char *)*(undefined2 *)(unaff_BP + 4) < ' ') break;
    if (*(char *)*(undefined2 *)(unaff_BP + 4) == ' ') {
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      uVar1 = FUN_1000_e793((int)*(char *)*(undefined2 *)(unaff_BP + 4));
      *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = uVar1;
    }
  }
  return;
}

