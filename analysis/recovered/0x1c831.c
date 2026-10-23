/* ev_4b499938e0e0e133234621ddff95ebe08479d6b033c47d269e31f436418306a4 */

void __cdecl16near FUN_1000_c831(void)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int unaff_BP;
  int iVar5;
  int iVar6;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar5 = 0;
  while (iVar5 < 5) {
    FUN_1000_f7da(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
    uVar2 = 0xda;
    if (iVar5 != 0) {
      uVar2 = 0xc0;
    }
    FUN_1000_f873(uVar2);
    FUN_1000_f873(0xc4);
    switch(iVar5) {
    case 0:
      *(undefined1 *)(unaff_BP + -8) = 0xc4;
      *(undefined1 *)(unaff_BP + -10) = 0xc4;
      *(undefined1 *)(unaff_BP + -0xb) = 0xc4;
      *(undefined1 *)(unaff_BP + -9) = 0xc2;
      *(undefined1 *)(unaff_BP + -0xc) = 0;
      *(undefined1 *)(unaff_BP + -7) = 0;
      *(undefined2 *)(unaff_BP + -2) = 0xb;
      *(undefined1 *)(unaff_BP + -0xe) = 0xc4;
      *(undefined1 *)(unaff_BP + -0xf) = 0xc4;
      *(undefined1 *)(unaff_BP + -0xd) = 0xbf;
      break;
    case 1:
      *(undefined1 *)(unaff_BP + -0xb) = 0xc2;
      *(undefined1 *)(unaff_BP + -9) = 0xc1;
      *(undefined1 *)(unaff_BP + -0xf) = 0xc1;
      break;
    case 2:
      *(undefined1 *)(unaff_BP + -0xf) = 0xc2;
      *(undefined1 *)(unaff_BP + -0xd) = 0xd9;
      break;
    case 3:
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
      break;
    case 4:
      *(undefined1 *)(unaff_BP + -0xb) = 0xc4;
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
      *(undefined1 *)(unaff_BP + -0xf) = 0xc4;
    }
    for (iVar6 = 0; iVar6 < *(int *)(unaff_BP + -2); iVar6 = iVar6 + 1) {
      FUN_1000_f6a4(0x893a,unaff_BP + -0xb);
    }
    if (iVar5 == 1) {
      FUN_1000_f873(0xc2);
      FUN_1000_f873(0xc4);
    }
    FUN_1000_f6a4(0x893d,unaff_BP + -0xf);
    if (iVar5 < 4) {
      if (iVar5 == 0) {
        uVar3 = (uint)*(byte *)(unaff_BP + 6);
      }
      else {
        uVar3 = *(byte *)(unaff_BP + 6) + 2;
      }
      *(uint *)(unaff_BP + -4) = uVar3;
      iVar6 = 0;
      *(int *)(unaff_BP + -6) = *(byte *)(unaff_BP + 4) + 1;
      while( true ) {
        iVar4 = 1;
        if (iVar5 < 2) {
          iVar4 = 2;
        }
        if (iVar4 + *(int *)(unaff_BP + -2) <= iVar6) break;
        FUN_1000_f7da(*(undefined2 *)(unaff_BP + -6),*(undefined2 *)(unaff_BP + -4));
        FUN_1000_f873(0xb3);
        iVar6 = iVar6 + 1;
        *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 4;
      }
    }
    iVar5 = iVar5 + 1;
    *(char *)(unaff_BP + 4) = *(char *)(unaff_BP + 4) + '\x01';
    *(char *)(unaff_BP + 4) = *(char *)(unaff_BP + 4) + '\x01';
    if (iVar5 < 2) {
      cVar1 = *(char *)(unaff_BP + 6);
    }
    else {
      cVar1 = *(char *)(unaff_BP + 6) + '\x02';
    }
    *(char *)(unaff_BP + 6) = cVar1;
  }
  return;
}

