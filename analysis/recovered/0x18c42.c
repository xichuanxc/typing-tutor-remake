/* ev_9ed5e77c76bc962905c0d17f75fa4f0f6c09088ad2f129b536157737381eb677 */

void __cdecl16near FUN_1000_8c42(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int unaff_BP;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)0x9d2c = 10;
  FUN_1000_8f6e(0x9ad4,0x9c00,0x99a8);
  *(undefined2 *)0x9d2c = 8;
  FUN_1000_8f6e(0x9ad4,0x9c00,0x99a8);
  FUN_1000_f7da(4,0x2c);
  FUN_1000_f6a4(0x7e93);
  if (*(int *)(unaff_BP + 4) != 10) {
    FUN_1000_f7da(5,0x1b);
    FUN_1000_f6a4(0x7eb3);
  }
  FUN_1000_f7da(6,8);
  if (*(int *)(unaff_BP + 4) == 10) {
    FUN_1000_f6a4(0x7ed7);
  }
  else {
    FUN_1000_f6a4(0x7ebe,*(undefined1 *)0x90b8);
  }
  FUN_1000_f6a4(0x7ef3);
  if (*(int *)(unaff_BP + 4) == 8) {
    uVar1 = FUN_1000_8ad2(0x7f1e,0,8,8);
    uVar1 = FUN_1000_8ad2(0x7f23,8,10,uVar1);
    iVar2 = FUN_1000_8ad2(0x7f35,10,0xc,uVar1);
  }
  else if (*(int *)(unaff_BP + 4) == 10) {
    FUN_1000_0128();
    iVar2 = 8;
    for (iVar5 = 0; iVar5 < 8; iVar5 = iVar5 + 1) {
      FUN_1000_e247(*(undefined2 *)0x9070,iVar5 * 0x7cc,0,0);
      FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
      iVar3 = FUN_1000_f105(*(undefined2 *)(unaff_BP + 6),0x7f45);
      if ((iVar3 == 0) && (*(char *)0x9072 != '\0')) {
        iVar3 = 1;
      }
      else {
        iVar3 = 0;
      }
      *(int *)(unaff_BP + -6) = iVar3;
      if (iVar3 == 0) {
        *(undefined2 *)(unaff_BP + -2) = 0;
        while (*(int *)(unaff_BP + -2) < 8) {
          FUN_1000_e74e(unaff_BP + -0x1c,0x7f4d);
          *(undefined2 *)(unaff_BP + -4) = 0;
          while ((pcVar4 = (char *)(*(int *)(unaff_BP + 6) + *(int *)(unaff_BP + -4)),
                 *pcVar4 != '.' && (*pcVar4 != '\0'))) {
            *(char *)(*(int *)(unaff_BP + -4) + unaff_BP + -0x17) = *pcVar4;
            *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
          }
          *(undefined1 *)(*(int *)(unaff_BP + -4) + unaff_BP + -0x17) = 0;
          iVar3 = FUN_1000_f105(*(int *)(unaff_BP + -2) * 0x4f + -0x6b76,unaff_BP + -0x1c);
          *(uint *)(unaff_BP + -6) = (uint)(iVar3 == 0);
          if ((iVar3 == 0) != 0) break;
          *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
        }
      }
      else {
        *(undefined2 *)(unaff_BP + -2) = 9;
      }
      FUN_1000_f7da(iVar2,2);
      if (*(int *)(unaff_BP + -6) == 0) {
        if (*(char *)0x9072 == '\0') break;
        FUN_1000_f6a4(0x7f5e,0x9072);
      }
      else {
        iVar3 = *(int *)(unaff_BP + -2) * 0x4f;
        uVar1 = FUN_1000_c0c6(*(undefined2 *)(iVar3 + -0x6b69),*(undefined2 *)(iVar3 + -0x6b67),
                              unaff_BP + -0xf);
        FUN_1000_f6a4(0x7f53,0x9072,uVar1);
        FUN_1000_8857(*(undefined2 *)(unaff_BP + -2));
      }
      iVar2 = iVar2 + 1;
    }
    FUN_1000_e74e(0x9072,0x1314);
    FUN_1000_e913(*(undefined2 *)0x9070);
  }
  else {
    iVar2 = FUN_1000_8ad2(0x7f7a,*(undefined2 *)(unaff_BP + 4),*(int *)(unaff_BP + 4) + 1,8);
  }
  FUN_1000_ae2b(3,1,iVar2 + 1,0x4e,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_ae2b(3,0x26,iVar2 + 1,0x37,0,0xcd,0xb3,0xd1,0xd1,0xcf,0xcf);
  FUN_1000_f7da(7,1);
  FUN_1000_f873(0xc3);
  for (iVar2 = 2; iVar2 < 0x4e; iVar2 = iVar2 + 1) {
    FUN_1000_f873(0xc4);
  }
  FUN_1000_f873(0xb4);
  FUN_1000_f7da(7,0x37);
  FUN_1000_f873(0xc5);
  FUN_1000_f7da(7,0x26);
  FUN_1000_f873(0xc5);
  if (*(char *)0x9d38 == '\0') {
    FUN_1000_f831();
    return;
  }
  return;
}

