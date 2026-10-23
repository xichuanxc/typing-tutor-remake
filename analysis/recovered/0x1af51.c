/* ev_6356c07c375ebdd63a33e76b4c8fe54bd3dbe8b9620f3224eacfebb8ca47c189 */

/* WARNING: Removing unreachable block (ram,0x0001afa8) */

undefined1 __cdecl16near FUN_1000_af51(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  char cVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -2) = 0;
  if (*(int *)(unaff_BP + 0x10) == 0) {
    cVar5 = (char)*(undefined2 *)(unaff_BP + 8) + '\x01';
  }
  else {
    cVar5 = (char)*(undefined2 *)*(undefined2 *)(unaff_BP + 0x10);
  }
  *(char *)(unaff_BP + -3) = cVar5;
  if (*(int *)(unaff_BP + 0x12) == 0) {
    cVar5 = (char)*(undefined2 *)(unaff_BP + 10) + '\x02';
  }
  else {
    cVar5 = (char)*(undefined2 *)*(undefined2 *)(unaff_BP + 0x12);
  }
  *(char *)(unaff_BP + -4) = cVar5;
  do {
    if (*(uint *)(unaff_BP + 0xc) <= (uint)*(byte *)(unaff_BP + -3)) {
      if (*(uint *)*(undefined2 *)(unaff_BP + 0x12) != 0) {
        *(uint *)*(undefined2 *)(unaff_BP + 0x12) = (uint)*(byte *)(unaff_BP + -4);
      }
      return *(undefined1 *)(unaff_BP + -3);
    }
    bVar1 = *(byte *)(unaff_BP + -4);
    *(int *)(unaff_BP + -0x57) = unaff_BP + -0x55;
    while( true ) {
      *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -2) + '\x01';
      while (' ' < *(char *)((uint)*(byte *)(unaff_BP + -1) + *(int *)(unaff_BP + 4))) {
        *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
      }
      if (*(uint *)(unaff_BP + 0xe) <=
          ((uint)*(byte *)(unaff_BP + -1) - (uint)*(byte *)(unaff_BP + -2)) +
          (uint)*(byte *)(unaff_BP + -4)) break;
      while (bVar2 = *(byte *)(unaff_BP + -2), bVar2 < *(byte *)(unaff_BP + -1)) {
        *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
        uVar3 = *(undefined1 *)((uint)bVar2 + *(int *)(unaff_BP + 4));
        puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + -0x57);
        *(int *)(unaff_BP + -0x57) = *(int *)(unaff_BP + -0x57) + 1;
        *puVar4 = uVar3;
        *(char *)(unaff_BP + -4) = *(char *)(unaff_BP + -4) + '\x01';
      }
      if (*(char *)((uint)*(byte *)(unaff_BP + -2) + *(int *)(unaff_BP + 4)) == '\0') {
        *(undefined1 *)*(undefined2 *)(unaff_BP + -0x57) = 0;
        FUN_1000_b0a9(*(undefined2 *)(unaff_BP + 6),unaff_BP + -0x55,*(undefined1 *)(unaff_BP + -3),
                      bVar1 - 2,*(undefined2 *)(unaff_BP + 0xe));
        if (*(uint *)*(undefined2 *)(unaff_BP + 0x12) != 0) {
          *(uint *)*(undefined2 *)(unaff_BP + 0x12) = (uint)*(byte *)(unaff_BP + -4);
        }
        return *(undefined1 *)(unaff_BP + -3);
      }
    }
    *(undefined1 *)*(undefined2 *)(unaff_BP + -0x57) = 0;
    FUN_1000_b0a9(*(undefined2 *)(unaff_BP + 6),unaff_BP + -0x55,*(undefined1 *)(unaff_BP + -3),
                  bVar1 - 2,*(undefined2 *)(unaff_BP + 0xe));
    while (*(char *)((uint)*(byte *)(unaff_BP + -2) + *(int *)(unaff_BP + 4)) == ' ') {
      *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
    }
    *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + '\x01';
    *(char *)(unaff_BP + -4) = (char)*(undefined2 *)(unaff_BP + 10) + '\x02';
  } while( true );
}

