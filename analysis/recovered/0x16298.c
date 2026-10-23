/* ev_bd8e2867aa9185c11c14223de7b809840567d1dde0342717d1d5711a1fe1b86b */

void __cdecl16near FUN_1000_6298(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -2) = 0;
  while (*(int *)(unaff_BP + -2) < *(int *)(unaff_BP + 6) + -3) {
    if (*(char *)0x9d4f == '\0') {
      uVar1 = FUN_1000_bdcb(*(undefined1 *)0x90b2);
    }
    else {
      uVar1 = *(undefined1 *)(*(byte *)0x9d4f + 0x7b13);
    }
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 2) = uVar1;
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2)) = uVar1;
    if (*(char *)0x9d4f == '\0') {
      uVar1 = *(undefined1 *)0x90b2;
    }
    else {
      uVar1 = *(undefined1 *)0x90b1;
    }
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 3) = uVar1;
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 1) = uVar1;
    if (*(char *)0x9d4e == '\0') {
      for (iVar3 = 3; 0 < iVar3; iVar3 = iVar3 + -1) {
        iVar2 = FUN_1000_bd74(iVar3 + 1);
        *(undefined1 *)(unaff_BP + -3) =
             *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar3 + *(int *)(unaff_BP + -2));
        *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar3 + *(int *)(unaff_BP + -2)) =
             *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar2 + *(int *)(unaff_BP + -2));
        *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar2 + *(int *)(unaff_BP + -2)) =
             *(undefined1 *)(unaff_BP + -3);
      }
      if (*(char *)0x9d4f == '\0') {
        *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 4) = 0x20;
      }
      else {
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
      }
    }
    else {
      *(undefined1 *)0x9d4e = 0;
      if (*(char *)0x9d4f == '\0') {
        *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 4) = 0x20;
      }
      else {
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
      }
    }
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 5;
  }
  iVar3 = *(int *)(unaff_BP + -2);
  if (*(char *)0x9d4f == '\0') {
    iVar3 = iVar3 + -1;
  }
  *(undefined1 *)(iVar3 + *(int *)(unaff_BP + 4)) = 0;
  return;
}

