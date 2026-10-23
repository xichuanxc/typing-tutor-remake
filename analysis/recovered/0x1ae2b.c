/* ev_aa248dc9caa0da2a681ff11c5034bcf8c23942cf67a697d2ad211d996ca9b6a9 */

void __cdecl16near FUN_1000_ae2b(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
  uVar1 = *(undefined1 *)(unaff_BP + 0x14);
  cVar2 = (*(char *)(unaff_BP + 10) - *(char *)(unaff_BP + 6)) + -1;
  *(char *)(unaff_BP + -2) = cVar2;
  uVar3 = FUN_1000_bbea(*(undefined1 *)(unaff_BP + 0xe),cVar2,unaff_BP + -0x53,uVar1);
  FUN_1000_f6a4(0x84f4,*(undefined1 *)(unaff_BP + 0x12),uVar3);
  *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + 4) + '\x01';
  while (*(byte *)(unaff_BP + -1) < *(byte *)(unaff_BP + 8)) {
    FUN_1000_f7da(*(undefined1 *)(unaff_BP + -1),*(undefined1 *)(unaff_BP + 6));
    if (*(char *)(unaff_BP + 0xc) == '\0') {
      FUN_1000_f6a4(0x8502,*(undefined1 *)(unaff_BP + 0x10));
      FUN_1000_f7da(*(undefined1 *)(unaff_BP + -1),*(undefined1 *)(unaff_BP + 10));
      FUN_1000_f6a4(0x8505,*(undefined1 *)(unaff_BP + 0x10));
    }
    else {
      uVar3 = FUN_1000_bbea(0x20,*(undefined1 *)(unaff_BP + -2),unaff_BP + -0x53,
                            *(undefined1 *)(unaff_BP + 0x10));
      FUN_1000_f6a4(0x84fb,*(undefined1 *)(unaff_BP + 0x10),uVar3);
    }
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
  }
  FUN_1000_f7da(*(undefined1 *)(unaff_BP + -1),*(undefined1 *)(unaff_BP + 6));
  uVar3 = FUN_1000_bbea(*(undefined1 *)(unaff_BP + 0xe),*(undefined1 *)(unaff_BP + -2),
                        unaff_BP + -0x53,*(undefined1 *)(unaff_BP + 0x18));
  FUN_1000_f6a4(0x8508,*(undefined1 *)(unaff_BP + 0x16),uVar3);
  return;
}

