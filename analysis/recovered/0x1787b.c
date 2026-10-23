/* ev_400d978dd05923c30e46dcfe75f5cad8f79e7f77919e41263f26301ba83710db */

void __cdecl16near FUN_1000_787b(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(0x16,0);
  FUN_1000_f74a();
  FUN_1000_f7da(0x17,0);
  FUN_1000_f74a();
  FUN_1000_ae2b(*(undefined2 *)(unaff_BP + 6),1,*(int *)(unaff_BP + 6) + 9,0x4e,0,0xcd,0xb3,0xd5,
                0xb8,0xd4,0xbe);
  FUN_1000_f7da(*(int *)(unaff_BP + 6) + 1,3);
  FUN_1000_f6a4(0x7b20,*(undefined2 *)(*(int *)(unaff_BP + 4) * 2 + 0x7fc4));
  FUN_1000_f7da(*(int *)(unaff_BP + 6) + 2,6);
  FUN_1000_f6a4(0x7b30);
  if (*(int *)(unaff_BP + 4) == 0) {
    FUN_1000_f6a4(0x7b6a);
  }
  FUN_1000_f7da(*(int *)(unaff_BP + 6) + 3,6);
  *(undefined1 *)(unaff_BP + -1) = 0;
  while( true ) {
    bVar1 = 0x43;
    if (*(int *)(unaff_BP + 4) != 0) {
      bVar1 = 0x3b;
    }
    if (bVar1 <= *(byte *)(unaff_BP + -1)) break;
    FUN_1000_f873(0xc4);
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
  }
  *(undefined1 *)(unaff_BP + -1) = 0;
  while (*(byte *)(unaff_BP + -1) < 5) {
    if (*(char *)((uint)*(byte *)(unaff_BP + -1) * 0x23 + *(int *)(unaff_BP + 4) * 0xaf + -0x67bd)
        != '\0') {
      FUN_1000_f7da((uint)*(byte *)(unaff_BP + -1) + *(int *)(unaff_BP + 6) + 4,7);
      iVar2 = (uint)*(byte *)(unaff_BP + -1) * 0x23 + *(int *)(unaff_BP + 4) * 0xaf;
      uVar4 = FUN_1000_c0c6(*(undefined2 *)(iVar2 + -0x679e),*(undefined2 *)(iVar2 + -0x679c),
                            unaff_BP + -10);
      iVar2 = *(int *)(unaff_BP + 4) * 0xaf;
      iVar3 = (uint)*(byte *)(unaff_BP + -1) * 0x23 + iVar2;
      FUN_1000_f6a4(0x7b75,*(byte *)(unaff_BP + -1) + 1,
                    (uint)*(byte *)(unaff_BP + -1) * 0x23 + iVar2 + -0x67bd,
                    *(undefined2 *)(iVar3 + -0x67a3),*(undefined2 *)(iVar3 + -0x67a1),uVar4);
      if (*(int *)(unaff_BP + 4) == 0) {
        FUN_1000_f6a4(0x7b8b,*(undefined1 *)
                              ((uint)*(byte *)(unaff_BP + -1) * 0x23 + *(int *)(unaff_BP + 4) * 0xaf
                              + -0x679f));
      }
    }
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
  }
  return;
}

