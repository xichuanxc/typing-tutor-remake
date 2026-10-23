/* ev_45a5b1be33c37d5974c7021c4d7f80a7dce4dde934faaa798037cf938efceb79 */

void __cdecl16near FUN_1000_0000(void)

{
  char *pcVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar3;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  *(undefined2 *)(unaff_BP + -3) = 0;
  if (1 < *(int *)(unaff_BP + 4)) {
    pcVar1 = (char *)*(undefined2 *)(*(int *)(unaff_BP + 6) + 2);
    if (*pcVar1 == '-') {
      *(char *)(unaff_BP + -1) = pcVar1[1];
      if (2 < *(int *)(unaff_BP + 4)) {
        *(undefined2 *)(unaff_BP + -3) = *(undefined2 *)(*(int *)(unaff_BP + 6) + 4);
      }
    }
    else {
      *(undefined2 *)(unaff_BP + -3) = *(undefined2 *)(*(int *)(unaff_BP + 6) + 2);
    }
  }
  FUN_1000_014b((int)*(char *)(unaff_BP + -1),*(undefined2 *)(unaff_BP + -3));
  iVar2 = FUN_1000_0860();
  if (iVar2 == 0) {
    uVar3 = FUN_1000_4cb5();
    *(undefined2 *)0x9068 = (int)((ulong)uVar3 >> 0x10);
    *(undefined2 *)0x9066 = (int)uVar3;
    *(undefined1 *)0x99a1 = 1;
    FUN_1000_32ed(0,0xffff);
  }
  FUN_1000_0335();
  return;
}

