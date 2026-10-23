/* ev_8e7ac5f30e81303e7f2184196d6ff61a058177814850166c648ae4a6b92c3105 */

void __cdecl16near FUN_1000_c1d3(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8889,*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  iVar3 = FUN_1000_75c1((int)*(char *)0x8b5);
  if ((iVar3 != 0) && (iVar2 == 0)) {
    iVar3 = FUN_1000_72dd(0x6e);
    if (iVar3 != 0) {
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x6e;
      goto LAB_1000_c21d;
    }
  }
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar2;
LAB_1000_c21d:
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}

