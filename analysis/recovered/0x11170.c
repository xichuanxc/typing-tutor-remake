/* ev_d6eff93aff834b5ca15c2cb7f82fc8a77cb7969aa363c8f5246972cbee4bb4e1 */

undefined2 __cdecl16near FUN_1000_1170(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0xc6d,0x843);
  iVar1 = FUN_1000_b21d(3,0x12,0x8d2,0,0,0x900);
  if (iVar1 == -1) {
    return 0xffff;
  }
  *(char *)0x90b5 = (char)iVar1;
  if ((char)iVar1 == '\x02') {
    FUN_1000_2692(0x9ae,0x843);
    FUN_1000_ae2b(3,1,0x17,0x4e,0,0xcd,0xba,0xc9,0xbb,200,0xbc);
    iVar1 = FUN_1000_af51(0xa4c,0xffff,4,1,0x17,0x4e,0,0);
    iVar1 = FUN_1000_af51(0xae5,0xffff,iVar1 + 1,1,0x17,0x4e,0,0);
    iVar1 = FUN_1000_af51(0xcbc,0xffff,iVar1 + 1,1,0x17,0x4e,0,0);
    FUN_1000_af51(0xc81,1,iVar1 + 1,1,0x17,0x4e,0,0);
    iVar1 = FUN_1000_f831();
    if (iVar1 == 0x1b) {
      return 0xffff;
    }
    uVar2 = FUN_1000_e74e(0x9d3e,0xf89,0xf95);
    iVar1 = FUN_1000_e7cd(uVar2);
    *(int *)0x9070 = iVar1;
    if (iVar1 == 0) {
      FUN_1000_f7da(0,0);
      FUN_1000_f77c();
      FUN_1000_b194(0xc9e,0x24,3);
      FUN_1000_f7da(0xe,0);
      return 0xffff;
    }
    FUN_1000_2723(0x843);
    *(undefined2 *)0x9d2c = 0;
    FUN_1000_48d7();
    *(undefined2 *)0x9d4c = 4;
    *(undefined2 *)0x9d4e = 1;
    while (iVar1 = FUN_1000_3a6d(0,6,0x48,1), iVar1 == 0) {
      FUN_1000_2723(0x843);
    }
    if (*(char *)0x9d38 == '\0') {
      return 0xffff;
    }
    *(undefined1 *)0x9d38 = 0;
    FUN_1000_e913(*(undefined2 *)0x9070);
    FUN_1000_51c5();
    uVar3 = (uint)((ulong)*(uint *)0x94a7 * 2);
    uVar4 = *(uint *)0x949f + *(uint *)0x94a3;
    iVar1 = FUN_1000_52dc(uVar4 - uVar3,
                          ((*(int *)0x94a1 + *(int *)0x94a5 +
                           (uint)CARRY2(*(uint *)0x949f,*(uint *)0x94a3)) -
                          ((int)((ulong)*(uint *)0x94a7 * 2 >> 0x10) + *(int *)0x94a9 * 2)) -
                          (uint)(uVar4 < uVar3),0,0,*(undefined2 *)0x949b,*(undefined2 *)0x949d);
    *(char *)0x90b8 = (char)(iVar1 / 10) * '\n' + '\x14';
    FUN_1000_f7da(0,0);
    FUN_1000_f77c();
    uVar2 = FUN_1000_e74e(0xcbc,0x10a3,0xf97,0xfa4);
    uVar2 = FUN_1000_e717(uVar2);
    FUN_1000_2692(uVar2);
    FUN_1000_2612(0x183,0);
    FUN_1000_bd1f();
    FUN_1000_8c42(0,0xfa5);
    iVar1 = FUN_1000_52dc(*(undefined2 *)0x94af,*(undefined2 *)0x94b1,*(undefined2 *)0x94b3,
                          *(undefined2 *)0x94b5,*(undefined2 *)0x94ab,*(undefined2 *)0x94ad);
    if ((iVar1 < 0x19) ||
       (uVar3 = FUN_1000_529a(*(undefined2 *)0x949f,*(undefined2 *)0x94a1,*(undefined2 *)0x94a3,
                              *(undefined2 *)0x94a5), uVar3 < *(byte *)0x1c90)) {
      *(undefined1 *)0x90b5 = 1;
      *(undefined2 *)(unaff_BP + -2) = 0;
      while (*(int *)(unaff_BP + -2) < 0x40) {
        *(undefined1 *)(*(int *)(unaff_BP + -2) + -0x6f45) = 0xff;
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
      }
      *(undefined2 *)0x9d36 = 0x3fc;
      return 0;
    }
    *(undefined1 *)0x90af = 0x24;
    iVar1 = FUN_1000_52dc(*(undefined2 *)0x94bb,*(undefined2 *)0x94bd,*(undefined2 *)0x94bf,
                          *(undefined2 *)0x94c1,*(undefined2 *)0x94b7,*(undefined2 *)0x94b9);
    if (0x14 < iVar1) {
      *(undefined1 *)0x90af = 0x2e;
      iVar1 = FUN_1000_52dc(*(undefined2 *)0x94c7,*(undefined2 *)0x94c9,*(undefined2 *)0x94cb,
                            *(undefined2 *)0x94cd,*(undefined2 *)0x94c3,*(undefined2 *)0x94c5);
      if (0xf < iVar1) {
        *(undefined1 *)0x90af = 0x3f;
      }
    }
    *(undefined1 *)0x90ae = 0x16;
    *(undefined1 *)0x90ba = 1;
    FUN_1000_54c1(0);
    FUN_1000_54c1(1);
    *(undefined2 *)(unaff_BP + -2) = 0;
    *(undefined2 *)0x9d36 = 0;
    while (*(uint *)(unaff_BP + -2) < *(byte *)0x90ae + 4) {
      iVar1 = FUN_1000_722b((int)*(char *)(*(int *)(unaff_BP + -2) + 0x7aee));
      *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    }
  }
  return 0;
}

