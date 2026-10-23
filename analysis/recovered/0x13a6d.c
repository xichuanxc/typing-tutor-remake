/* ev_f1ff498e7bf71235d47ba485f45fe1d9f9bd0773b9da0f721a7af1946bc93afd */

uint __cdecl16near FUN_1000_3a6d(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  int unaff_BP;
  int iVar9;
  int iVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -0x294) = 1;
  if (*(char *)(unaff_BP + 4) == '\0') {
    *(char *)(unaff_BP + 4) = (char)((uint)*(byte *)(unaff_BP + 6) * -3 + 0x19 >> 1) + '\x01';
  }
  *(char *)(unaff_BP + -0x289) = (char)(0x50 - *(byte *)(unaff_BP + 8) >> 1) + -1;
  *(undefined1 *)(unaff_BP + -0x28b) = 0;
  *(undefined2 *)(unaff_BP + -0x29a) = 0;
  *(undefined2 *)(unaff_BP + -0x29c) = 0;
  iVar10 = 0;
  iVar9 = 0;
  FUN_1000_54c1(0);
  FUN_1000_54c1(1);
  do {
    if (*(int *)0x9d2c == 8) {
      uVar5 = FUN_1000_5584();
      *(undefined1 *)0x90b2 = uVar5;
    }
    if (*(char *)(unaff_BP + 10) == '\x01') {
      FUN_1000_4802(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -0x289),
                    *(undefined1 *)(unaff_BP + 6));
      *(undefined1 *)(unaff_BP + -0x28a) = 0;
      while ((*(char *)(unaff_BP + -0x28b) == '\0' &&
             (*(byte *)(unaff_BP + -0x28a) < *(byte *)(unaff_BP + 6)))) {
        iVar7 = FUN_1000_639e((uint)*(byte *)(unaff_BP + -0x28a) * 0x51 + unaff_BP + -0x288,
                              *(undefined1 *)(unaff_BP + 8),0x5ff7);
        if (iVar7 != 0) {
          *(undefined1 *)(unaff_BP + -0x28b) = 0xff;
        }
        uVar5 = *(undefined1 *)(unaff_BP + -0x289);
        *(undefined1 *)(unaff_BP + -0x28c) = uVar5;
        FUN_1000_f7da((uint)*(byte *)(unaff_BP + -0x28a) * 3 + (uint)*(byte *)(unaff_BP + 4),uVar5);
        FUN_1000_f6a4(0x1af1,(uint)*(byte *)(unaff_BP + -0x28a) * 0x51 + unaff_BP + -0x288);
        *(char *)(unaff_BP + -0x28a) = *(char *)(unaff_BP + -0x28a) + '\x01';
      }
      if (*(char *)0x9d50 != '\0') {
        FUN_1000_f7da(0x18,0x20);
        FUN_1000_2612(0x1af4,0);
      }
    }
    else {
      if (*(int *)0x9d2c != 8) {
        FUN_1000_4802(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -0x289),
                      *(undefined1 *)(unaff_BP + 6));
      }
      *(undefined1 *)(unaff_BP + -0x28a) = 0;
      while (*(byte *)(unaff_BP + -0x28a) < *(byte *)(unaff_BP + 6)) {
        FUN_1000_639e((uint)*(byte *)(unaff_BP + -0x28a) * 0x51 + unaff_BP + -0x288,
                      *(undefined1 *)(unaff_BP + 8),0x618a);
        if (*(int *)0x9d2c == 8) {
          iVar7 = FUN_1000_f139((uint)*(byte *)(unaff_BP + -0x28a) * 0x51 + unaff_BP + -0x288);
          *(undefined1 *)(unaff_BP + -0x28c) = (char)((0x50 - iVar7) / 2);
          iVar7 = FUN_1000_4557((uint)*(byte *)(unaff_BP + -0x28a) * 0x51 + unaff_BP + -0x288,
                                *(undefined1 *)(unaff_BP + 8),1,*(undefined2 *)(unaff_BP + -0x294));
          if (iVar7 == -1) {
            uVar8 = FUN_1000_e74e(0x17a0,0x1004);
            return uVar8;
          }
        }
        else {
          *(undefined1 *)(unaff_BP + -0x28c) = *(undefined1 *)(unaff_BP + -0x289);
        }
        FUN_1000_f7da((uint)*(byte *)(unaff_BP + -0x28a) * 3 + (uint)*(byte *)(unaff_BP + 4),
                      *(undefined1 *)(unaff_BP + -0x28c));
        FUN_1000_f6a4(0x1af5,(uint)*(byte *)(unaff_BP + -0x28a) * 0x51 + unaff_BP + -0x288);
        *(char *)(unaff_BP + -0x28a) = *(char *)(unaff_BP + -0x28a) + '\x01';
      }
    }
    if (*(int *)0x9d2c == 8) {
      uVar6 = FUN_1000_f139(unaff_BP + -0x288,unaff_BP + -0x288,unaff_BP + -0x2a3);
      FUN_1000_4427(0,uVar6);
      FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 7,*(byte *)(unaff_BP + -0x289) + 0x15);
      FUN_1000_f6a4(0x1af8,*(undefined1 *)(unaff_BP + -0x2a3),*(undefined1 *)(unaff_BP + -0x2a2),
                    *(undefined1 *)(unaff_BP + -0x2a1));
    }
    FUN_1000_bd1f();
    *(undefined2 *)(unaff_BP + -0x29e) = 0;
    *(undefined2 *)(unaff_BP + -0x2a0) = 0;
    *(undefined2 *)(unaff_BP + -0x298) = 0;
    *(undefined2 *)(unaff_BP + -0x296) = 0;
    *(undefined2 *)(unaff_BP + -0x28e) = 0;
    while (*(uint *)(unaff_BP + -0x28e) < (uint)*(byte *)(unaff_BP + -0x28a)) {
      iVar7 = FUN_1000_4a70((uint)*(byte *)(unaff_BP + 4) + *(int *)(unaff_BP + -0x28e) * 3 + 1,
                            *(undefined1 *)(unaff_BP + -0x28c),
                            *(int *)(unaff_BP + -0x28e) * 0x51 + unaff_BP + -0x288,unaff_BP + -0x296
                            ,unaff_BP + -0x298,unaff_BP + -0x2a0);
      if (iVar7 == -1) {
        FUN_1000_e74e(0x17a0,0x1004);
        return 0xffff;
      }
      *(int *)(unaff_BP + -0x28e) = *(int *)(unaff_BP + -0x28e) + 1;
    }
    if (*(int *)0x9d2c < 8) {
      uVar3 = *(uint *)(unaff_BP + -0x296);
      iVar7 = *(int *)0x9d3a;
      puVar1 = (uint *)(iVar7 + 0x15);
      uVar8 = *puVar1;
      *puVar1 = *puVar1 + uVar3;
      *(int *)(iVar7 + 0x17) =
           *(int *)(iVar7 + 0x17) + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar8,uVar3);
      uVar3 = *(uint *)(unaff_BP + -0x298);
      puVar1 = (uint *)(iVar7 + 0x19);
      uVar8 = *puVar1;
      *puVar1 = *puVar1 + uVar3;
      *(int *)(iVar7 + 0x1b) =
           *(int *)(iVar7 + 0x1b) + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar8,uVar3);
      iVar4 = *(int *)(unaff_BP + -0x29e);
      uVar3 = *(uint *)(unaff_BP + -0x2a0);
      puVar1 = (uint *)(iVar7 + 0x11);
      uVar8 = *puVar1;
      *puVar1 = *puVar1 + uVar3;
      *(int *)(iVar7 + 0x13) = *(int *)(iVar7 + 0x13) + iVar4 + (uint)CARRY2(uVar8,uVar3);
      bVar2 = *(byte *)(unaff_BP + -0x28a);
      puVar1 = (uint *)(iVar7 + 0x1d);
      uVar8 = *puVar1;
      *puVar1 = *puVar1 + (uint)bVar2;
      *(int *)(iVar7 + 0x1f) = *(int *)(iVar7 + 0x1f) + (uint)CARRY2(uVar8,(uint)bVar2);
    }
    uVar3 = *(uint *)(unaff_BP + -0x296);
    puVar1 = (uint *)0x9717;
    uVar8 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    *(int *)0x9719 = *(int *)0x9719 + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar8,uVar3);
    uVar3 = *(uint *)(unaff_BP + -0x298);
    puVar1 = (uint *)0x971b;
    uVar8 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    *(int *)0x971d = *(int *)0x971d + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar8,uVar3);
    iVar7 = *(int *)(unaff_BP + -0x29e);
    uVar3 = *(uint *)(unaff_BP + -0x2a0);
    puVar1 = (uint *)0x9713;
    uVar8 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    *(int *)0x9715 = *(int *)0x9715 + iVar7 + (uint)CARRY2(uVar8,uVar3);
    bVar2 = *(byte *)(unaff_BP + -0x28a);
    puVar1 = (uint *)0x971f;
    uVar8 = *puVar1;
    *puVar1 = *puVar1 + (uint)bVar2;
    *(int *)0x9721 = *(int *)0x9721 + (uint)CARRY2(uVar8,(uint)bVar2);
    iVar9 = iVar9 + *(int *)(unaff_BP + -0x296);
    iVar10 = iVar10 + *(int *)(unaff_BP + -0x298);
    iVar7 = *(int *)(unaff_BP + -0x29e);
    uVar3 = *(uint *)(unaff_BP + -0x2a0);
    puVar1 = (uint *)(unaff_BP + -0x29c);
    uVar8 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    *(int *)(unaff_BP + -0x29a) = *(int *)(unaff_BP + -0x29a) + iVar7 + (uint)CARRY2(uVar8,uVar3);
    if (*(int *)0x9d2c == 8) {
      *(undefined2 *)(unaff_BP + -0x290) = 0;
      while (*(int *)(unaff_BP + -0x290) < 3) {
        FUN_1000_f7da((uint)*(byte *)(unaff_BP + 4) + *(int *)(unaff_BP + -0x290) + -1,
                      *(undefined1 *)(unaff_BP + -0x289));
        *(undefined2 *)(unaff_BP + -0x28e) = 0;
        while (*(int *)(unaff_BP + -0x28e) < 0x1c) {
          FUN_1000_f873(0x20);
          *(int *)(unaff_BP + -0x28e) = *(int *)(unaff_BP + -0x28e) + 1;
        }
        *(int *)(unaff_BP + -0x290) = *(int *)(unaff_BP + -0x290) + 1;
      }
      if (*(char *)0x9d52 == '\0') {
        FUN_1000_4344(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -0x289));
        *(undefined1 *)0x9d52 = 1;
      }
      FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 0xb,0x48 - (uint)*(byte *)(unaff_BP + -0x289));
      FUN_1000_f873(0x20);
      FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 0xc,0x48 - (uint)*(byte *)(unaff_BP + -0x289));
      FUN_1000_f873(0x20);
      FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 0xb,*(byte *)(unaff_BP + -0x289) + 0xe);
      iVar7 = *(int *)(unaff_BP + -0x296) + *(int *)(unaff_BP + -0x298) + -2;
      uVar6 = FUN_1000_52dc(iVar7,iVar7 >> 0xf,0,0,*(undefined2 *)(unaff_BP + -0x2a0),
                            *(undefined2 *)(unaff_BP + -0x29e));
      *(undefined2 *)0x9d56 = uVar6;
      FUN_1000_f6a4(0x1b01,uVar6);
      FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 0xc,*(byte *)(unaff_BP + -0x289) + 0x11);
      uVar6 = FUN_1000_529a(*(int *)(unaff_BP + -0x296),*(int *)(unaff_BP + -0x296) >> 0xf,
                            *(int *)(unaff_BP + -0x298),*(int *)(unaff_BP + -0x298) >> 0xf);
      *(undefined2 *)0x9d54 = uVar6;
      FUN_1000_f6a4(0x1b09,uVar6);
      if (*(uint *)(unaff_BP + -0x294) < (uint)*(byte *)0x90b6) {
        *(int *)(unaff_BP + -0x294) = *(int *)(unaff_BP + -0x294) + 1;
      }
      else {
        FUN_1000_b1f3(1,1,7);
        FUN_1000_f7da(*(undefined1 *)(unaff_BP + 4),0x21);
        FUN_1000_f6a4(0x1b0f,0x1ae3);
        FUN_1000_2612(0x183,0);
        FUN_1000_4d14(0xfa,0,1);
        FUN_1000_b1f3(0,2,7);
        FUN_1000_bd1f();
        FUN_1000_2692(0x1b14,0x843);
        FUN_1000_ae2b(3,0x1b,9,0x35,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
        FUN_1000_f7da(4,0x1d);
        iVar7 = iVar9 + iVar10 + *(int *)(unaff_BP + -0x294) * -2;
        uVar6 = FUN_1000_52dc(iVar7,iVar7 >> 0xf,0,0,*(undefined2 *)(unaff_BP + -0x29c),
                              *(undefined2 *)(unaff_BP + -0x29a));
        FUN_1000_f6a4(0x1b2c,uVar6);
        FUN_1000_f7da(5,0x1d);
        *(undefined2 *)(unaff_BP + -0x294) = 1;
        uVar6 = FUN_1000_529a(iVar9,iVar9 >> 0xf,iVar10,iVar10 >> 0xf);
        FUN_1000_f6a4(0x1b3a,uVar6);
        FUN_1000_f7da(6,0x1d);
        FUN_1000_8f6e(0x9ad4,0x9c00,0x99a8);
        FUN_1000_f6a4(0x1b49,*(undefined1 *)0x90b8,
                      *(undefined1 *)((*(byte *)0x90b8 - 10) / 10 + 0x9747));
        if (*(char *)0x90b2 == '\0') {
          uVar8 = *(byte *)0x90af + 1;
        }
        else {
          uVar8 = (uint)*(byte *)0x90af;
        }
        FUN_1000_4427(1,uVar8,0x7a53,unaff_BP + -0x2a3);
        FUN_1000_f7da(7,0x1d);
        FUN_1000_f6a4(0x1b5f,*(undefined1 *)(unaff_BP + -0x2a3),*(undefined1 *)(unaff_BP + -0x2a2),
                      *(undefined1 *)(unaff_BP + -0x2a1));
        if (*(char *)0x90b2 == '\0') {
          uVar8 = *(byte *)0x90af + 1;
        }
        else {
          uVar8 = (uint)*(byte *)0x90af;
        }
        FUN_1000_4427(2,uVar8,0x7a53,unaff_BP + -0x2a3);
        FUN_1000_f7da(8,0x1d);
        FUN_1000_f6a4(0x1b73,*(undefined1 *)(unaff_BP + -0x2a3),*(undefined1 *)(unaff_BP + -0x2a2),
                      *(undefined1 *)(unaff_BP + -0x2a1));
        FUN_1000_54c1(0);
        FUN_1000_54c1(1);
        iVar9 = FUN_1000_b21d(3,0x15,0x1ac8,10,0,0x102e);
        if (iVar9 == -1) {
          uVar8 = FUN_1000_e74e(0x17a0,0x1006);
          return uVar8;
        }
        if (iVar9 == 1) {
          uVar8 = FUN_1000_e74e(0x17a0,0x1b8d);
          return uVar8;
        }
        if (iVar9 == 2) {
          uVar8 = FUN_1000_e74e(0x17a0,0x1004);
          return uVar8;
        }
        *(undefined2 *)(unaff_BP + -0x29a) = 0;
        *(undefined2 *)(unaff_BP + -0x29c) = 0;
        iVar10 = 0;
        iVar9 = 0;
      }
    }
    else {
      *(undefined1 *)0x9d38 = 1;
    }
    if (*(int *)0x9d2c != 8) {
      return (uint)*(byte *)(unaff_BP + -0x28b);
    }
  } while( true );
}

