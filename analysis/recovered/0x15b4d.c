/* ev_7ceadbc03ce52e1b9cef71ced6400880c81857c53d1c12de0b1208d82e773c8f */

undefined2 __cdecl16near FUN_1000_5b4d(void)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_BP;
  char cVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  do {
    FUN_1000_2692(0x1ff1,0x843);
    iVar2 = FUN_1000_b751(0x1ffa,unaff_BP + -0xc,6,0);
    if (iVar2 == -1) {
      return 0xffff;
    }
    cVar3 = '\x02';
    for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
      *(char *)(unaff_BP + iVar2 + -6) = *(char *)(*(int *)(unaff_BP + 4) + iVar2) - cVar3;
      uVar1 = FUN_1000_e793((int)*(char *)(unaff_BP + iVar2 + -0xc));
      *(undefined1 *)(unaff_BP + iVar2 + -0xc) = uVar1;
      cVar3 = cVar3 * '\x02';
    }
    *(undefined1 *)(unaff_BP + -1) = 0;
    iVar2 = FUN_1000_f105(unaff_BP + -0xc,unaff_BP + -6);
  } while (iVar2 != 0);
  return 0;
}

