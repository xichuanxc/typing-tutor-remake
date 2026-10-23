/* ev_30cd9945ace17d60b009a5e25d751ff7a4ebeb4edb64f89035a0aa524c87b771 */

undefined2 __cdecl16near FUN_1000_cd9b(void)

{
  undefined1 uVar1;
  bool bVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = *(undefined1 *)0x90b2;
  bVar2 = false;
LAB_1000_cdaa:
  do {
    if (bVar2) {
      FUN_1000_e74e(0x17a0,0x1004);
      *(undefined1 *)0x90b2 = uVar1;
      return 0;
    }
    FUN_1000_b1f3(0,1,7);
    FUN_1000_2723(0x101e);
    FUN_1000_c78e(3,0xd);
    *(undefined2 *)(unaff_BP + -2) = 0;
    while (*(int *)(unaff_BP + -2) < 8) {
      FUN_1000_c98e(3,0xd,(int)*(char *)(*(int *)(unaff_BP + -2) + 0x7a53),1);
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    }
    FUN_1000_ae2b(0xe,3,0x17,0x4d,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
    *(undefined2 *)(unaff_BP + -2) = 0xf;
    *(undefined2 *)(unaff_BP + -4) = 5;
    uVar4 = FUN_1000_af51(0x8a63,0xffff,0xe,3,0x17,0x4d,unaff_BP + -2,unaff_BP + -4);
    *(undefined2 *)(unaff_BP + -2) = uVar4;
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 2;
    *(undefined2 *)(unaff_BP + -4) = 5;
    uVar4 = FUN_1000_af51(0x8b01,0xffff,0xe,3,0x17,0x4d,unaff_BP + -2,unaff_BP + -4);
    *(undefined2 *)(unaff_BP + -2) = uVar4;
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 2;
    *(undefined2 *)(unaff_BP + -4) = 5;
    uVar4 = FUN_1000_af51(0x8b78,0xffff,0xe,3,0x17,0x4d,unaff_BP + -2,unaff_BP + -4);
    *(undefined2 *)(unaff_BP + -2) = uVar4;
    while( true ) {
      cVar3 = FUN_1000_f831();
      *(char *)0x90b2 = cVar3;
      if (cVar3 == '\x1b') break;
      iVar5 = FUN_1000_e677(0x7a5b,cVar3);
      if (iVar5 != 0) {
        iVar5 = FUN_1000_4557(0x8bb0,0x1a,0,0);
        if (iVar5 == -1) {
          bVar2 = true;
        }
        goto LAB_1000_cdaa;
      }
      FUN_1000_7e47(5);
    }
    bVar2 = true;
  } while( true );
}

