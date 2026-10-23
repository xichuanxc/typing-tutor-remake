/* ev_2fcf63af004b8f35e71ecf05d54940edd5e739ea1f49ea86f43322d4205f8092 */

void __cdecl16near FUN_1000_4427(void)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int unaff_BP;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
    *(undefined1 *)(*(int *)(unaff_BP + 10) + iVar4) = 0x20;
    uVar2 = 0;
    if (*(int *)(unaff_BP + 4) == 1) {
      uVar2 = 0xff;
    }
    *(undefined1 *)(unaff_BP + iVar4 + -3) = uVar2;
  }
  iVar4 = 0;
  do {
    if (*(int *)(unaff_BP + 6) <= iVar4) {
      if (((*(char *)0x90af == '\x03') && (*(int *)(unaff_BP + 4) != 0)) ||
         ((*(char *)0x90af == '\x04' && (*(int *)(unaff_BP + 4) == 2)))) {
        *(undefined1 *)(*(int *)(unaff_BP + 10) + 2) = 0x20;
      }
      return;
    }
    iVar3 = FUN_1000_722b((int)*(char *)*(undefined2 *)(unaff_BP + 8));
    bVar1 = *(byte *)(iVar3 + -0x6f45);
    *(undefined2 *)(unaff_BP + -5) = 0;
    while( true ) {
      if (((2 < *(int *)(unaff_BP + -5)) ||
          (iVar3 = FUN_1000_e7a7((int)*(char *)*(undefined2 *)(unaff_BP + 8)),
          iVar3 == *(char *)(*(int *)(unaff_BP + 10) + *(int *)(unaff_BP + -5)))) ||
         (*(char *)*(undefined2 *)(unaff_BP + 8) == ' ')) goto LAB_1000_4529;
      if (((*(int *)(unaff_BP + 4) == 1) &&
          (bVar1 <= *(byte *)(*(int *)(unaff_BP + -5) + unaff_BP + -3))) ||
         ((*(int *)(unaff_BP + 4) != 1 &&
          (*(byte *)(*(int *)(unaff_BP + -5) + unaff_BP + -3) < bVar1)))) break;
      *(int *)(unaff_BP + -5) = *(int *)(unaff_BP + -5) + 1;
    }
    if (*(int *)(unaff_BP + -5) < 2) {
      *(undefined1 *)(*(int *)(unaff_BP + 10) + 2) = *(undefined1 *)(*(int *)(unaff_BP + 10) + 1);
      *(undefined1 *)(unaff_BP + -1) = *(undefined1 *)(unaff_BP + -2);
    }
    if (*(int *)(unaff_BP + -5) == 0) {
      ((undefined1 *)*(undefined2 *)(unaff_BP + 10))[1] =
           *(undefined1 *)*(undefined2 *)(unaff_BP + 10);
      *(undefined1 *)(unaff_BP + -2) = *(undefined1 *)(unaff_BP + -3);
    }
    uVar2 = FUN_1000_e7a7((int)*(char *)*(undefined2 *)(unaff_BP + 8));
    *(undefined1 *)(*(int *)(unaff_BP + 10) + *(int *)(unaff_BP + -5)) = uVar2;
    *(byte *)(*(int *)(unaff_BP + -5) + unaff_BP + -3) = bVar1;
LAB_1000_4529:
    *(int *)(unaff_BP + 8) = *(int *)(unaff_BP + 8) + 1;
    iVar4 = iVar4 + 1;
  } while( true );
}

