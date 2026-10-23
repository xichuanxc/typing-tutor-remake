/* ev_e5789414ea1c365096db6083d0efd0a51f82e1abf0923f49ee56af0e036a22c6 */

undefined2 __cdecl16near FUN_1000_639e(void)

{
  bool bVar1;
  int iVar2;
  int unaff_BP;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d4e != '\0') {
    *(undefined1 *)0x9bb = 0;
  }
  FUN_1000_e74e(unaff_BP + -0xd6,0x9bb);
  do {
    iVar2 = (*(code *)*(undefined2 *)(unaff_BP + 8))(unaff_BP + -2);
    if (iVar2 != 0) {
      FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),unaff_BP + -0xd6);
      *(undefined1 *)0x9bb = 0;
      return 1;
    }
    if (*(char *)(unaff_BP + -0xd6) != '\0') {
      for (iVar2 = 0; iVar2 < *(int *)(unaff_BP + -2); iVar2 = iVar2 + 1) {
        FUN_1000_e717(unaff_BP + -0xd6,0x2084);
      }
    }
    FUN_1000_e717(unaff_BP + -0xd6,0x9bb);
    if (*(int *)(unaff_BP + 8) == 0x618a) {
      iVar2 = FUN_1000_f139(unaff_BP + -0xd6);
      bVar1 = *(int *)(unaff_BP + 6) + 0x20 < iVar2;
    }
    else {
      iVar2 = FUN_1000_f139(unaff_BP + -0xd6);
      if (*(int *)(unaff_BP + 6) < iVar2) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
  } while (!bVar1);
  iVar2 = *(int *)(unaff_BP + 6);
  while ((-1 < iVar2 && (' ' < *(char *)(unaff_BP + iVar2 + -0xd6)))) {
    iVar2 = iVar2 + -1;
  }
  if (iVar2 < 0) {
    *(undefined1 *)(unaff_BP + *(int *)(unaff_BP + 6) + -0xd6) = 0;
    iVar3 = *(int *)(unaff_BP + 6);
    do {
      iVar3 = iVar3 + 1;
    } while (' ' < *(char *)(unaff_BP + iVar3 + -0xd6));
  }
  else {
    while ((-1 < iVar2 && (*(char *)(unaff_BP + iVar2 + -0xd6) < '!'))) {
      iVar2 = iVar2 + -1;
    }
    iVar3 = iVar2 + 2;
    *(undefined1 *)(unaff_BP + iVar2 + -0xd5) = 0;
  }
  while (*(char *)(unaff_BP + iVar3 + -0xd6) == ' ') {
    iVar3 = iVar3 + 1;
  }
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),unaff_BP + -0xd6);
  FUN_1000_e74e(0x9bb,iVar3 + unaff_BP + -0xd6);
  return 0;
}

