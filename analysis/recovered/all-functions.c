/* Ghidra pseudocode from REA. Not original source; not expected to compile. */

/* Shared-prologue and register conventions can produce incomplete/misleading pseudocode. Consult assembly. */

/* 0x10000 ev_45a5b1be33c37d5974c7021c4d7f80a7dce4dde934faaa798037cf938efceb79 */

void __cdecl16near FUN_1000_0000(void)

{
  char *pcVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar3;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  *(undefined2 *)(unaff_BP + -3) = 0;
  if (1 < *(int *)(unaff_BP + 4)) {
    pcVar1 = (char *)*(undefined2 *)(*(int *)(unaff_BP + 6) + 2);
    if (*pcVar1 == '-') {
      *(char *)(unaff_BP + -1) = pcVar1[1];
      if (2 < *(int *)(unaff_BP + 4)) {
        *(undefined2 *)(unaff_BP + -3) = *(undefined2 *)(*(int *)(unaff_BP + 6) + 4);
      }
    }
    else {
      *(undefined2 *)(unaff_BP + -3) = *(undefined2 *)(*(int *)(unaff_BP + 6) + 2);
    }
  }
  FUN_1000_014b((int)*(char *)(unaff_BP + -1),*(undefined2 *)(unaff_BP + -3));
  iVar2 = FUN_1000_0860();
  if (iVar2 == 0) {
    uVar3 = FUN_1000_4cb5();
    *(undefined2 *)0x9068 = (int)((ulong)uVar3 >> 0x10);
    *(undefined2 *)0x9066 = (int)uVar3;
    *(undefined1 *)0x99a1 = 1;
    FUN_1000_32ed(0,0xffff);
  }
  FUN_1000_0335();
  return;
}



/* 0x10079 ev_aacd8c3af0e77f7bfe62ae187c1aeec83b5fff78b5e5a72481b9cadedb5041fa */

void __cdecl16near FUN_1000_0079(void)

{
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(0,0);
  FUN_1000_f77c();
  FUN_1000_f8c2(0x100,0,0xb0c,0);
  FUN_1000_7c0a();
  FUN_1000_f8c2(*(undefined2 *)0x906c,0,0,0);
  return;
}



/* 0x100b3 ev_b47de38d52999c1d2a8bcc602cdaee751071d3f7f716f69c519e192d0a5db5ee */

void __cdecl16near FUN_1000_00b3(void)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_0079();
  if (*(byte *)(unaff_BP + 4) < 2) {
    uVar1 = 0xa1;
    if (*(char *)(unaff_BP + 4) != '\0') {
      uVar1 = 0xa8;
    }
    FUN_1000_e74e(8,uVar1);
    uVar1 = 0xa1;
    if (*(char *)(unaff_BP + 4) != '\0') {
      uVar1 = 0xa8;
    }
    iVar2 = FUN_1000_f139(uVar1);
    *(undefined1 *)(iVar2 + 8) = 0x20;
    FUN_1000_b194(3,0x32,6);
  }
  else {
    FUN_1000_b194(0xed,0x2a,3);
  }
  FUN_1000_f7da(0xe,0);
  FUN_1000_f3ba();
  return;
}



/* 0x10128 ev_9727cbb6daab5662f0c550d770f84baf0a6332c4d424e91bc54725235032469d */

void __cdecl16near FUN_1000_0128(void)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_e7cd(0xa1,0x113);
  *(int *)0x9070 = iVar1;
  if (iVar1 == 0) {
    FUN_1000_00b3(0);
  }
  return;
}



/* 0x1014b ev_04b76eb83d7781e2457aa689f06ba1ce95e0edb2b36e7c8200c5860e14767fcc */

void __cdecl16near FUN_1000_014b(void)

{
  uint uVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_7b92();
  uVar1 = FUN_1000_f8c2(0xf00,0,0,0);
  uVar1 = uVar1 & 0xff;
  *(uint *)0x906c = uVar1;
  if ((uVar1 == 7) || (uVar1 == 0xf)) {
    *(undefined1 *)0x906a = 0;
    if (uVar1 == 0xf) {
      FUN_1000_f8c2(7,0,0,0);
    }
    FUN_1000_f7c2(0);
  }
  else {
    iVar2 = FUN_1000_e793(*(undefined2 *)(unaff_BP + 4));
    if (iVar2 == 0x42) {
      *(undefined1 *)0x906a = 0;
      FUN_1000_f8c2(2,0,0,0);
    }
    else {
      *(undefined1 *)0x906a = 1;
      FUN_1000_f8c2(3,0,0,0);
      FUN_1000_f8c2(0xb00,0,0,0);
      FUN_1000_f6bf(1,7,1,0);
      FUN_1000_f7da(0,0);
      FUN_1000_f77c();
    }
  }
  FUN_1000_f73b(0);
  FUN_1000_f8c2(0x100,0,0x2b0c,0);
  FUN_1000_07c9(0x40,0);
  FUN_1000_07c9(0x20,0);
  FUN_1000_f7da(0,0);
  FUN_1000_f77c();
  iVar2 = FUN_1000_e7cd(0xa8,0x116);
  *(int *)0x9070 = iVar2;
  if (iVar2 == 0) {
    FUN_1000_00b3(1);
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  iVar2 = FUN_1000_e7cd(0xa1,0x118);
  *(int *)0x9070 = iVar2;
  if (iVar2 == 0) {
    FUN_1000_00b3(0);
  }
  FUN_1000_e247(*(undefined2 *)0x9070,0x462c,0,0);
  FUN_1000_e1f4(0x983e,1,0x163,*(undefined2 *)0x9070);
  FUN_1000_e913(*(undefined2 *)0x9070);
  if (*(int *)(unaff_BP + 6) != 0) {
    FUN_1000_e74e(0x9072,0x1314);
    FUN_1000_5bca(*(undefined2 *)(unaff_BP + 6));
  }
  FUN_1000_e74e(0x9072,0x11a);
  return;
}



/* 0x102e0 ev_1a8a644451b73b2b68cb5742f3faff57be00b3f1fbfac7b602657232fa7884e5 */

void __cdecl16near FUN_1000_02e0(void)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar6;
  
  FUN_1000_e7bd();
  if (*(char *)0x99a2 == '\0') {
    uVar2 = *(uint *)*(int *)(unaff_BP + 4);
    puVar1 = (uint *)*(int *)(unaff_BP + 6);
    iVar4 = uVar2 + *puVar1;
    iVar5 = ((uint *)*(int *)(unaff_BP + 4))[1] + ((uint *)*(int *)(unaff_BP + 6))[1] +
            (uint)CARRY2(uVar2,*puVar1);
  }
  else {
    uVar6 = FUN_1000_f0a7();
    puVar1 = (uint *)*(int *)(unaff_BP + 6);
    iVar4 = (uint)uVar6 + *puVar1;
    iVar5 = (int)((ulong)uVar6 >> 0x10) + ((uint *)*(int *)(unaff_BP + 6))[1] +
            (uint)CARRY2((uint)uVar6,*puVar1);
  }
  piVar3 = (int *)*(int *)(unaff_BP + 4);
  piVar3[1] = iVar5;
  *piVar3 = iVar4;
  return;
}



/* 0x10335 ev_10c424ac7b1d69a1a322db505dd8d466f6897cf409b8bad85d674c1e76841687 */

void __cdecl16near FUN_1000_0335(void)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  int iVar7;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar8;
  undefined4 uVar9;
  
  FUN_1000_e7bd();
  if (*(char *)0x99a1 == '\0') goto LAB_1000_0775;
  bVar8 = false;
  if (*(int *)0x9719 == 0) {
    bVar8 = *(int *)0x9717 == 0;
  }
  if (bVar8) {
    bVar8 = false;
    if (*(int *)0x97b7 == 0) {
      bVar8 = *(int *)0x97b5 == 0;
    }
    if (!bVar8) goto LAB_1000_037d;
    bVar8 = false;
    if (*(int *)0x97bb == 0) {
      bVar8 = *(int *)0x97b9 == 0;
    }
    if (!bVar8) goto LAB_1000_037d;
    bVar8 = false;
    if (*(int *)0x971d == 0) {
      bVar8 = *(int *)0x971b == 0;
    }
    if (!bVar8) goto LAB_1000_037d;
    if (*(char *)0x906e == '\0') goto LAB_1000_0775;
  }
  else {
LAB_1000_037d:
    FUN_1000_2692(0x113f,0x11b);
    FUN_1000_2612(0x183,0);
    FUN_1000_8c42(8,0x11c);
    if ((*(int *)0x9719 + *(int *)0x97b7 + (uint)CARRY2(*(uint *)0x9717,*(uint *)0x97b5) == 0) &&
       (*(uint *)0x9717 + *(uint *)0x97b5 < 0x3e9)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    *(undefined1 *)0x99a2 = uVar6;
  }
  FUN_1000_2692(0x11d,0x122);
  FUN_1000_f7da(0x18,0);
  FUN_1000_f74a();
  while (iVar7 = FUN_1000_b21d(3,0x1d,0xaf,0,0,0x123), iVar7 == -1) {
    FUN_1000_7e47(5);
  }
  if (iVar7 != 1) {
    if (iVar7 == 2) {
      return;
    }
    uVar9 = FUN_1000_4cb5();
    *(undefined2 *)(unaff_BP + -6) = (int)((ulong)uVar9 >> 0x10);
    *(undefined2 *)(unaff_BP + -8) = (int)uVar9;
    uVar3 = *(undefined2 *)0x99a4;
    *(undefined2 *)(unaff_BP + -2) = *(undefined2 *)0x99a6;
    *(undefined2 *)(unaff_BP + -4) = uVar3;
    if ((*(int *)(unaff_BP + -6) <= *(int *)0x9068) &&
       ((*(int *)(unaff_BP + -6) != *(int *)0x9068 || (*(uint *)(unaff_BP + -8) < *(uint *)0x9066)))
       ) {
      puVar1 = (uint *)(unaff_BP + -8);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 0xd600;
      *(int *)(unaff_BP + -6) = *(int *)(unaff_BP + -6) + 0x83 + (uint)(0x29ff < uVar2);
      for (iVar7 = 0; iVar7 < 6; iVar7 = iVar7 + 1) {
        *(undefined2 *)(iVar7 * 2 + -0x6f68) = *(undefined2 *)((iVar7 + 1) * 2 + -0x6f68);
      }
      *(undefined2 *)0x90a4 = 0;
      puVar1 = (uint *)(unaff_BP + -4);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 1;
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + (uint)(0xfffe < uVar2);
    }
    uVar9 = FUN_1000_f04d();
    *(undefined2 *)(unaff_BP + -0xe) = (int)((ulong)uVar9 >> 0x10);
    *(undefined2 *)(unaff_BP + -0x10) = (int)uVar9;
    bVar8 = false;
    if (*(int *)(unaff_BP + -0xe) == 0) {
      bVar8 = *(int *)(unaff_BP + -0x10) == 0;
    }
    if (bVar8) {
      *(undefined2 *)(unaff_BP + -0xe) = 0;
      *(undefined2 *)(unaff_BP + -0x10) = 1;
    }
    iVar7 = *(int *)(unaff_BP + -0xe);
    uVar4 = *(uint *)(unaff_BP + -0x10);
    puVar1 = (uint *)0x9094;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar4;
    *(int *)0x9096 = *(int *)0x9096 + iVar7 + (uint)CARRY2(uVar2,uVar4);
    uVar3 = *(undefined2 *)(unaff_BP + -4);
    *(undefined2 *)0x9092 = *(undefined2 *)(unaff_BP + -2);
    *(undefined2 *)0x9090 = uVar3;
    *(int *)0x90a4 = *(int *)0x90a4 + *(int *)(unaff_BP + -0x10);
    FUN_1000_0128();
    for (iVar7 = 0; iVar7 < 0x4b; iVar7 = iVar7 + 1) {
      FUN_1000_02e0(iVar7 * 4 + -0x6efa,iVar7 * 4 + -0x6658);
      FUN_1000_02e0(iVar7 * 4 + -0x6dce,iVar7 * 4 + -0x652c);
      FUN_1000_02e0(iVar7 * 4 + -0x6ca2,iVar7 * 4 + -0x6400);
    }
    *(undefined2 *)0x9d2c = 9;
    FUN_1000_8f6e(0x9232,0x935e,0x9106);
    *(undefined2 *)0x9d2c = 0xb;
    FUN_1000_8f6e(0x9232,0x935e,0x9106);
    FUN_1000_02e0(0x9762,0x9713);
    FUN_1000_02e0(0x9766,0x9717);
    FUN_1000_02e0(0x976a,0x971b);
    FUN_1000_02e0(0x976e,0x971f);
    FUN_1000_02e0(0x9800,0x97b1);
    FUN_1000_02e0(0x9804,0x97b5);
    FUN_1000_02e0(0x9808,0x97b9);
    FUN_1000_02e0(0x980c,0x97bd);
    FUN_1000_02e0(0x9772,0x9723);
    FUN_1000_02e0(0x9776,0x9727);
    FUN_1000_02e0(0x977a,0x972b);
    FUN_1000_02e0(0x977e,0x972f);
    FUN_1000_02e0(0x9782,0x9733);
    FUN_1000_02e0(0x9786,0x9737);
    FUN_1000_02e0(0x978a,0x973b);
    FUN_1000_02e0(0x978e,0x973f);
    FUN_1000_02e0(0x9792,0x9743);
    *(undefined2 *)0x9721 = 0;
    *(undefined2 *)0x971f = 0;
    *(undefined2 *)0x971d = 0;
    *(undefined2 *)0x971b = 0;
    *(undefined2 *)0x9719 = 0;
    *(undefined2 *)0x9717 = 0;
    *(undefined2 *)0x9715 = 0;
    *(undefined2 *)0x9713 = 0;
    *(undefined2 *)0x97bf = 0;
    *(undefined2 *)0x97bd = 0;
    *(undefined2 *)0x97bb = 0;
    *(undefined2 *)0x97b9 = 0;
    *(undefined2 *)0x97b7 = 0;
    *(undefined2 *)0x97b5 = 0;
    *(undefined2 *)0x97b3 = 0;
    *(undefined2 *)0x97b1 = 0;
    *(undefined2 *)0x9745 = 0;
    *(undefined2 *)0x9743 = 0;
    *(undefined2 *)0x9741 = 0;
    *(undefined2 *)0x973f = 0;
    *(undefined2 *)0x973d = 0;
    *(undefined2 *)0x973b = 0;
    *(undefined2 *)0x9739 = 0;
    *(undefined2 *)0x9737 = 0;
    *(undefined2 *)0x9735 = 0;
    *(undefined2 *)0x9733 = 0;
    *(undefined2 *)0x9731 = 0;
    *(undefined2 *)0x972f = 0;
    *(undefined2 *)0x972d = 0;
    *(undefined2 *)0x972b = 0;
    *(undefined2 *)0x9729 = 0;
    *(undefined2 *)0x9727 = 0;
    *(undefined2 *)0x9725 = 0;
    *(undefined2 *)0x9723 = 0;
    for (iVar7 = 0; iVar7 < 10; iVar7 = iVar7 + 1) {
      *(undefined1 *)(iVar7 + -0x681b) = 0;
      *(undefined1 *)(iVar7 + -0x68b9) = 0;
    }
    uVar5 = *(undefined2 *)0x9092;
    uVar3 = *(undefined2 *)0x9090;
    *(undefined2 *)0x97fe = uVar5;
    *(undefined2 *)0x97fc = uVar3;
    *(undefined2 *)0x9760 = uVar5;
    *(undefined2 *)0x975e = uVar3;
    FUN_1000_e247(*(undefined2 *)0x9070,*(int *)0x9d2e * 0x7cc,0,0);
    FUN_1000_e852(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    FUN_1000_e247(*(undefined2 *)0x9070,0x462c,0,0);
    FUN_1000_e852(0x983e,1,0x163,*(undefined2 *)0x9070);
    FUN_1000_e913(*(undefined2 *)0x9070);
  }
LAB_1000_0775:
  FUN_1000_0128();
  if ((-1 < *(int *)0x9d2e) && (*(int *)0x9d2e < 7)) {
    FUN_1000_e247(*(undefined2 *)0x9070,*(int *)0x9d2e * 0x7cc + 0x34,0,0);
    FUN_1000_e852(0x90a6,1,2,*(undefined2 *)0x9070);
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_0079();
  FUN_1000_f3ba();
  return;
}



/* 0x107c9 ev_2d844dabb9fc3c2f31b0c5edc575fe5d6e557dd5273d57e69dc5e1398bd3123c */

void __cdecl16near FUN_1000_07c9(void)

{
  byte bVar1;
  uint uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  bVar1 = FUN_1000_e6a2(0x17,0x40);
  *(byte *)(unaff_BP + -1) = bVar1 & *(byte *)(unaff_BP + 4);
  if (((*(char *)(unaff_BP + -1) != '\0') && (*(char *)(unaff_BP + 6) == '\0')) ||
     ((*(char *)(unaff_BP + -1) == '\0' && (*(char *)(unaff_BP + 6) != '\0')))) {
    if (*(char *)(unaff_BP + 6) == '\0') {
      bVar1 = FUN_1000_e6a2(0x17,0x40);
      FUN_1000_e6c0(0x17,0x40,bVar1 & ~*(byte *)(unaff_BP + 4));
    }
    else {
      uVar2 = FUN_1000_e6a2(0x17,0x40);
      FUN_1000_e6c0(0x17,0x40,uVar2 | *(byte *)(unaff_BP + 4));
    }
  }
  return;
}



/* 0x10860 ev_f8544d81f41437974f201cd38ce050aa4dfc2f4c82e96d66542b3f394d3f282d */

undefined2 __cdecl16near FUN_1000_0860(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_f84a();
  if (iVar3 < 1) {
    FUN_1000_095c(0);
  }
  FUN_1000_b1f3(0,1,7);
  FUN_1000_bd1f();
  iVar3 = FUN_1000_0e3f();
  *(int *)0x9d2e = iVar3;
  if (iVar3 == -1) {
    FUN_1000_e913(*(undefined2 *)0x9070);
    return 0xffff;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_bd1f();
  iVar3 = FUN_1000_0f9a();
  if (iVar3 == -1) {
    return 0xffff;
  }
  uVar2 = *(undefined2 *)0x99a6;
  uVar1 = *(undefined2 *)0x99a4;
  *(undefined2 *)0x9711 = uVar2;
  *(undefined2 *)0x970f = uVar1;
  *(undefined2 *)0x97af = uVar2;
  *(undefined2 *)0x97ad = uVar1;
  *(undefined1 *)0x9d38 = 0;
  FUN_1000_bd1f();
  *(undefined2 *)0x9d3a = 0x962;
  *(undefined2 *)0x9d3c = 0xa4c;
  if (*(int *)0x9d34 == 0) {
    FUN_1000_1699();
    FUN_1000_bd1f();
  }
  else {
    uVar1 = *(undefined2 *)0x99a4;
    *(undefined2 *)0x908e = *(undefined2 *)0x99a6;
    *(undefined2 *)0x908c = uVar1;
    iVar3 = FUN_1000_9018(0,0xe5d,0x8b5);
    if (iVar3 == -1) {
      return 0xffff;
    }
    FUN_1000_bd1f();
    iVar3 = FUN_1000_1170();
    if (iVar3 == -1) {
      return 0xffff;
    }
    FUN_1000_bd1f();
    iVar3 = FUN_1000_14f2();
    if (iVar3 == -1) {
      return 0xffff;
    }
    FUN_1000_2692(0xe6a,0x843);
    FUN_1000_1605(0);
    FUN_1000_bd1f();
  }
  if (*(char *)0x90b5 == '\x02') {
    *(undefined1 *)0x1c91 = 0xf;
  }
  return 0;
}



/* 0x1095c ev_53d82aa7e45ad2cae0d9af72b198e2243e1fd1c3ac55aef3eecc984afa901dc3 */

void __cdecl16near FUN_1000_095c(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(0,0);
  FUN_1000_f77c();
  FUN_1000_c78e(*(undefined1 *)0x168,*(undefined1 *)0x169);
  FUN_1000_2612(0x16b,0);
  if (*(char *)0x906a == '\0') {
    FUN_1000_ae2b(2,0x1a,10,0x35,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  }
  else {
    FUN_1000_f6bf(2,7,1,0);
    FUN_1000_ae2b(2,0x1a,10,0x35,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  }
  if (*(int *)(unaff_BP + 4) != 0) {
    FUN_1000_f7da(0xc,0x21);
    FUN_1000_b1f3(1,7,1);
    FUN_1000_f6a4(0x19e);
  }
  FUN_1000_b1f3(0,2,7);
  iVar1 = FUN_1000_0c43(0xe70,0xe84,5,0x1e,6);
  if (iVar1 == -1) {
    return;
  }
  iVar1 = FUN_1000_0c43(0xe9c,0xeb5,8,0x1c,5);
  if (iVar1 == -1) {
    return;
  }
  FUN_1000_b1f3(0,1,7);
  FUN_1000_f7da(0xc,0);
  FUN_1000_f77c();
  if (*(int *)(unaff_BP + 4) != 0) {
    FUN_1000_f7da(0xc,0x20);
    FUN_1000_b1f3(1,7,1);
    FUN_1000_f6a4(0x19e);
    FUN_1000_b1f3(0,1,7);
  }
  FUN_1000_ae2b(0xd,3,0x16,0x4c,0,0xcd,0xba,0xc9,0xbb,200,0xbc);
  FUN_1000_ae2b(0xd,0x1d,0x16,0x32,0,0xcd,0xba,0xcb,0xcb,0xca,0xca);
  FUN_1000_b1f3(0,1,7);
  FUN_1000_af51(0xbcd,0xffff,0xd,3,0x16,0x1d,0,0);
  FUN_1000_af51(0x9bb,0xffff,0xd,0x32,0x16,0x4c,0,0);
  FUN_1000_2612(0x16b,0);
  FUN_1000_ca33(0xe,0x21);
  return;
}



/* 0x10bbb ev_8cea7698fbb3f5123bb27bb74c13076044fdb773ddd5bc71654c99377a57c374 */

undefined1 __cdecl16near FUN_1000_0bbb(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_f84a();
  if (0 < iVar1) {
    return 0x1b;
  }
  FUN_1000_c98e(*(undefined1 *)0x168,*(undefined1 *)0x169,
                (int)*(char *)*(undefined2 *)(unaff_BP + 4),1);
  FUN_1000_7e47(4);
  iVar1 = FUN_1000_4d14(*(undefined1 *)(unaff_BP + 6),0,1);
  if (iVar1 == 1) {
    return 0x1b;
  }
  FUN_1000_c98e(*(undefined1 *)0x168,*(undefined1 *)0x169,
                (int)*(char *)*(undefined2 *)(unaff_BP + 4),0);
  FUN_1000_b1f3(0,2,7);
  return *(undefined1 *)*(undefined2 *)(unaff_BP + 4);
}



/* 0x10c43 ev_2df98ba8beabcc5fe86f394c2084d1cc6352cda31c57c9d0fd8eb0ee7b055c89 */

/* WARNING: Removing unreachable block (ram,0x00010c6b) */

undefined2 __cdecl16near FUN_1000_0c43(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(*(int *)(unaff_BP + 8) + -1,*(undefined2 *)(unaff_BP + 10));
  FUN_1000_f6a4(0xece,*(undefined2 *)(unaff_BP + 4));
  while( true ) {
    while( true ) {
      uVar1 = *(undefined2 *)(unaff_BP + 0xc);
      uVar2 = *(undefined2 *)(unaff_BP + 6);
      *(int *)(unaff_BP + 6) = *(int *)(unaff_BP + 6) + 1;
      cVar3 = FUN_1000_0bbb(uVar2,uVar1);
      *(char *)(unaff_BP + -1) = cVar3;
      if (cVar3 == '\x1b') {
        FUN_1000_b1f3(0,1,7);
        return 0xffff;
      }
      if (*(char *)(unaff_BP + -1) != '\b') break;
      uVar1 = *(undefined2 *)(unaff_BP + 10);
      *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + -1;
      FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),uVar1,0x20);
      FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10),0x18);
      FUN_1000_4e79(*(int *)(unaff_BP + 8) + -2,*(undefined2 *)(unaff_BP + 10),0x20);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
    }
    iVar4 = 0x20;
    if (' ' < *(char *)(unaff_BP + -1)) {
      iVar4 = (int)*(char *)(unaff_BP + -1);
    }
    uVar1 = *(undefined2 *)(unaff_BP + 10);
    *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
    FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),uVar1,iVar4);
    if (*(char *)(unaff_BP + -1) == '\0') break;
    if (*(char *)(unaff_BP + -1) != *(char *)*(undefined2 *)(unaff_BP + 4)) {
      FUN_1000_b1f3(0,2,4);
      FUN_1000_4e79(*(int *)(unaff_BP + 8) + -2,*(int *)(unaff_BP + 10) + -1,0x19);
      FUN_1000_b1f3(0,2,7);
      FUN_1000_7e47(5);
    }
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    FUN_1000_4e79(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10),0x18);
  }
  return 0;
}



/* 0x10d63 ev_bd8b13de624820193b89c71370a7d3288821c478e29fe662b51018e4f91a521a */

undefined2 __cdecl16near FUN_1000_0d63(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  do {
    bVar1 = false;
    iVar2 = FUN_1000_b751(0x1ae,*(undefined2 *)0x6d5,0x1a,0);
    if (iVar2 == -1) {
      return 0xffff;
    }
    for (iVar2 = 1; iVar2 <= *(int *)(unaff_BP + 4); iVar2 = iVar2 + 1) {
      iVar3 = FUN_1000_f105(*(undefined2 *)0x6d5,*(undefined2 *)(iVar2 * 2 + 0x6d5));
      if (iVar3 == 0) {
        bVar1 = true;
        FUN_1000_b12a(0xed1,0x13,0x10,0x16,0x40);
        break;
      }
    }
    if (!bVar1) {
      FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
      return 0;
    }
  } while( true );
}



/* 0x10ddc ev_0759850f0b2306647142fd5d8aed7cc88b52fea77a84901f270cd54dc99c015f */

undefined2 __cdecl16near FUN_1000_0ddc(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)0x9d34 = 1;
  FUN_1000_2723(0x843);
  iVar1 = FUN_1000_0d63(*(undefined2 *)(unaff_BP + 4));
  if (iVar1 == -1) {
    return 0xffff;
  }
  FUN_1000_e247(*(undefined2 *)0x9070,(long)*(int *)(unaff_BP + 4) * 0x7cc,0);
  FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
  FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  return *(undefined2 *)(unaff_BP + 4);
}



/* 0x10e3f ev_aef19ddf1b68e693f7ce20b01337f90c137220bcde16fe40296248fd77259b9b */

int __cdecl16near FUN_1000_0e3f(void)

{
  int iVar1;
  int unaff_BP;
  uint uVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x1c9,0x843);
  FUN_1000_0128();
  iVar1 = FUN_1000_0f47();
  *(int *)(unaff_BP + -2) = iVar1;
  if (7 < iVar1) {
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_BP + -2)) {
    iVar3 = FUN_1000_b21d(*(int *)(unaff_BP + -2) + 1,0x1a,(uint)(7 < iVar1) * 2 + 0x6d5,0,0,0x962);
  }
  if (iVar3 == -1) {
    return -1;
  }
  if (7 < iVar1 != 0) {
    iVar3 = iVar3 + 1;
  }
  if (iVar3 == 0) {
    iVar3 = FUN_1000_0ddc(*(undefined2 *)(unaff_BP + -2));
    if (iVar3 == -1) {
      return -1;
    }
  }
  else {
    iVar3 = iVar3 + -1;
    FUN_1000_e247(*(undefined2 *)0x9070,iVar3 * 0x7cc,0,0);
    FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    *(undefined2 *)0x9d34 = 0;
    if ((*(char *)0x90a8 != '\0') && (iVar1 = FUN_1000_5b4d(0x90a8), iVar1 == -1)) {
      return -1;
    }
  }
  if (*(char *)0x90ad == '\0') {
    FUN_1000_7c0a();
  }
  *(undefined2 *)0x9d36 = 0;
  for (uVar2 = 0; uVar2 < *(byte *)0x90ae + 4; uVar2 = uVar2 + 1) {
    iVar1 = FUN_1000_722b((int)*(char *)(uVar2 + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
  }
  return iVar3;
}



/* 0x10f47 ev_9e46aa06fb7e523de86d65a871655def6b741c956407f7d28d9bd89aeaab7059 */

int __cdecl16near FUN_1000_0f47(void)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  for (iVar1 = 1; iVar1 < 9; iVar1 = iVar1 + 1) {
    FUN_1000_e247(*(undefined2 *)0x9070,(long)(iVar1 + -1) * 0x7cc,0);
    FUN_1000_e1f4(*(undefined2 *)(iVar1 * 2 + 0x6d5),1,0x1a,*(undefined2 *)0x9070);
    if (*(char *)*(undefined2 *)(iVar1 * 2 + 0x6d5) == '\0') break;
  }
  return iVar1 + -1;
}



/* 0x10f9a ev_7a4deb5ba35fdba20e57fb2e1bde40ed28d20fbf5eebe6dc4ef07a2b5df516dc */

/* WARNING: Removing unreachable block (ram,0x00011082) */

uint __cdecl16near FUN_1000_0f9a(void)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  FUN_1000_e7bd();
  uVar4 = FUN_1000_114b();
  uVar3 = (undefined2)((ulong)uVar4 >> 0x10);
  *(undefined2 *)0x99a6 = uVar3;
  *(undefined2 *)0x99a4 = (int)uVar4;
  *(undefined2 *)0x9d32 = uVar3;
  *(undefined2 *)0x9d30 = (int)uVar4;
  if ((*(int *)0x99a6 <= *(int *)0x9092) &&
     ((*(int *)0x99a6 != *(int *)0x9092 || (*(uint *)0x99a4 < *(uint *)0x9090)))) {
    uVar3 = *(undefined2 *)0x9090;
    *(undefined2 *)0x99a6 = *(undefined2 *)0x9092;
    *(undefined2 *)0x99a4 = uVar3;
  }
  FUN_1000_c0c6(*(undefined2 *)0x99a4,*(undefined2 *)0x99a6,0x868);
  *(undefined1 *)0x870 = 0x3f;
  do {
    if (*(int *)0x9d34 == 0) {
      FUN_1000_2692(0x1c4);
    }
    else {
      FUN_1000_2692(0x1c4);
    }
    iVar1 = FUN_1000_b21d(2,4,0x8c7,0,0);
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        return 0;
      }
      FUN_1000_2723();
      while( true ) {
        iVar1 = FUN_1000_b751(0xf2e,unaff_BP + -9,9);
        if (iVar1 == -1) {
          return 0xffff;
        }
        uVar4 = FUN_1000_c131();
        iVar1 = (int)((ulong)uVar4 >> 0x10);
        uVar2 = (uint)uVar4;
        *(int *)0x99a6 = iVar1;
        *(uint *)0x99a4 = uVar2;
        if ((*(int *)0x9092 < iVar1) || ((iVar1 == *(int *)0x9092 && (*(uint *)0x9090 <= uVar2))))
        break;
        FUN_1000_ae2b(0x12,10,0x14,0x40,0,0xcd,0xb3,0xd5,0xb8,0xd4);
        FUN_1000_af51(0xf56,0xffff,0x12,10,0x14,0x40,0);
        iVar1 = FUN_1000_f831();
        if (iVar1 == 0x1b) {
          return 0xffff;
        }
        FUN_1000_ae2b(0x12,10,0x14,0x40,1,0x20,0x20,0x20,0x20,0x20);
      }
      return uVar2;
    }
    if (*(int *)0x9d34 == 0) {
      return 0xffff;
    }
    FUN_1000_2692(0x1c9);
    iVar1 = FUN_1000_0d63();
  } while (iVar1 != -1);
  return 0xffff;
}



/* 0x1114b ev_ffe54cef1ad8dd84e93815bb37d4d6ff31a51cd69a70b209a736b2dc5226eff3 */

void __cdecl16near FUN_1000_114b(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_e5a1(unaff_BP + -0x14);
  *(int *)(unaff_BP + -0xc) = *(int *)(unaff_BP + -0xc) + 1;
  FUN_1000_bfc7(*(undefined2 *)(unaff_BP + -0xe),*(undefined2 *)(unaff_BP + -0xc),
                *(int *)(unaff_BP + -10) + 0x76c);
  return;
}



/* 0x11170 ev_d6eff93aff834b5ca15c2cb7f82fc8a77cb7969aa363c8f5246972cbee4bb4e1 */

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



/* 0x114f2 ev_2da2492718ac30ee9436b1c5f348ad34abb423132dfb18a50fa667ce77f6e7f5 */

undefined2 __cdecl16near FUN_1000_14f2(void)

{
  int unaff_BP;
  int iVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0xfa6,0x843);
  iVar2 = (uint)*(byte *)0x90b5 * 10 + 10;
  *(int *)(unaff_BP + -2) = iVar2;
  for (iVar1 = 0; iVar1 < 8; iVar1 = iVar1 + 1) {
    FUN_1000_e61c(*(undefined2 *)(iVar1 * 2 + 0x6d5),0xfb1,iVar2,iVar2 + 9);
    iVar2 = iVar2 + 10;
  }
  FUN_1000_e74e(*(int *)((iVar1 + -1) * 2 + 0x6d5) + 3,0xfbb);
  if (*(char *)0x90b5 == '\0') {
    *(undefined1 *)0x90b8 = 0x14;
  }
  else if (*(char *)0x90b5 == '\x01') {
    *(undefined1 *)0x90b8 = 0x1e;
  }
  iVar1 = 7;
  if (*(byte *)0x90b8 < 100) {
    iVar1 = (*(byte *)0x90b8 / 10 - 1) - (uint)*(byte *)0x90b5;
  }
  iVar1 = FUN_1000_b21d(8,9,0x6d5,0,iVar1,0xd38);
  if (iVar1 == -1) {
    return 0xffff;
  }
  *(char *)0x90b8 = (char)iVar1 * '\n' + (char)*(undefined2 *)(unaff_BP + -2);
  FUN_1000_2692(0xfbd,0x843);
  iVar1 = FUN_1000_b21d(7,8,0x7fb,0,1,0xdd1);
  if (iVar1 == -1) {
    return 0xffff;
  }
  *(undefined1 *)0x90b7 = (char)iVar1;
  return 0;
}



/* 0x11605 ev_846db92ccfcc7573652d85b7c74628a8385ba7ccbf2ce566722b43ca3959ee87 */

void __cdecl16near FUN_1000_1605(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_b21d(3,0x11,0x83d,*(undefined2 *)(unaff_BP + 4),0,0xfcb);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
  }
  else if (iVar1 == 0) {
    FUN_1000_e74e(0x17a0,0xfe9);
    *(undefined1 *)0x17a5 = 0;
  }
  else if (iVar1 == 1) {
    FUN_1000_e74e(0x17a0,0xfec);
    *(undefined1 *)0x17a5 = 0;
  }
  else if (iVar1 == 2) {
    *(undefined1 *)0x17a0 = 0;
  }
  return;
}



/* 0x1167f ev_33076ceee3dd7c0de4407b9a21c3a219cc73e24f1d340ff5c8746aa1d65b9cdb */

undefined2 __cdecl16near FUN_1000_167f(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  bool bVar1;
  
  FUN_1000_e7bd();
  bVar1 = false;
  if (*(int *)(unaff_BP + 6) == 0) {
    bVar1 = *(int *)(unaff_BP + 4) == 10;
  }
  if (bVar1) {
    return 0x528;
  }
  return 0x52e;
}



/* 0x11699 ev_beff1764ca9cea4306931acfa7a0fcce703f6b2cdd8237ba5bf91bfdb401da2a */

/* WARNING: Removing unreachable block (ram,0x0001218b) */

void __cdecl16near FUN_1000_1699(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  long lVar9;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -4) = 3;
  *(undefined2 *)(unaff_BP + -6) = 3;
  FUN_1000_2692(0xfef,0x843);
  *(int *)(unaff_BP + -0xc) = (uint)*(byte *)((uint)*(byte *)0x90b7 * 2 + 0x7ed) * 10;
  *(int *)(unaff_BP + -0xe) = (uint)*(byte *)((uint)*(byte *)0x90b7 * 2 + 0x7ee) * 10;
  uVar2 = (uint)((ulong)*(uint *)0x976e * 2);
  uVar5 = *(uint *)0x9766 + *(uint *)0x976a;
  uVar2 = FUN_1000_52dc(uVar5 - uVar2,
                        ((*(int *)0x9768 + *(int *)0x976c +
                         (uint)CARRY2(*(uint *)0x9766,*(uint *)0x976a)) -
                        ((int)((ulong)*(uint *)0x976e * 2 >> 0x10) + *(int *)0x9770 * 2)) -
                        (uint)(uVar5 < uVar2),0,0,*(undefined2 *)0x9762,*(undefined2 *)0x9764);
  *(int *)(unaff_BP + -2) = *(int *)0x99a4 - *(int *)0x908c;
  iVar3 = *(int *)0x99a4 - *(int *)0x9090;
  *(int *)(unaff_BP + -10) = iVar3;
  if (iVar3 != 0) {
    if (iVar3 < 7) {
      for (iVar3 = *(int *)(unaff_BP + -10); iVar3 < 7; iVar3 = iVar3 + 1) {
        *(undefined2 *)((iVar3 - *(int *)(unaff_BP + -10)) * 2 + -0x6f68) =
             *(undefined2 *)(iVar3 * 2 + -0x6f68);
      }
      for (iVar3 = 7 - *(int *)(unaff_BP + -10); iVar3 < 7; iVar3 = iVar3 + 1) {
        *(undefined2 *)(iVar3 * 2 + -0x6f68) = 0;
      }
    }
    else {
      for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
        *(undefined2 *)(iVar3 * 2 + -0x6f68) = 0;
      }
    }
  }
  *(undefined2 *)(unaff_BP + -8) = 0;
  for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
    *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + *(int *)(iVar3 * 2 + -0x6f68);
  }
  uVar4 = FUN_1000_af51(0x1d6,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  if (*(int *)(unaff_BP + -10) < 0xf) {
    if (*(int *)(unaff_BP + -10) < 8) {
      if (*(int *)(unaff_BP + -0xe) < *(int *)(unaff_BP + -8)) {
        uVar4 = FUN_1000_af51(0x2b7,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      if (0 < *(int *)(unaff_BP + -8)) {
        uVar4 = FUN_1000_af51(0x343,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_24e8(*(int *)(unaff_BP + -8),*(int *)(unaff_BP + -8) >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_167f(*(int *)(unaff_BP + -8),*(int *)(unaff_BP + -8) >> 0xf,0xffff,2,1,0x17
                              ,0x4e,unaff_BP + -4,unaff_BP + -6);
        uVar4 = FUN_1000_af51(uVar4);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x359,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      if (*(int *)(unaff_BP + -8) < *(int *)(unaff_BP + -0xc)) {
        uVar4 = FUN_1000_af51(0x36c,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        iVar3 = *(int *)(unaff_BP + -0xc) - *(int *)(unaff_BP + -8);
        FUN_1000_24e8(iVar3,iVar3 >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        iVar3 = *(int *)(unaff_BP + -0xc) - *(int *)(unaff_BP + -8);
        uVar4 = FUN_1000_167f(iVar3,iVar3 >> 0xf,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        uVar4 = FUN_1000_af51(uVar4);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x3a3,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      else if (*(int *)(unaff_BP + -0xe) < *(int *)(unaff_BP + -8)) {
        uVar4 = FUN_1000_af51(0x2be,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x662,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
      else {
        uVar4 = FUN_1000_af51(0x3c6,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_24e8(*(int *)(unaff_BP + -0xc),*(int *)(unaff_BP + -0xc) >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x65a,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_24e8(*(int *)(unaff_BP + -0xe),*(int *)(unaff_BP + -0xe) >> 0xf,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_167f(*(int *)(unaff_BP + -0xe),*(int *)(unaff_BP + -0xe) >> 0xf,0xffff,2,1,
                              0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        uVar4 = FUN_1000_af51(uVar4);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x3f2,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
    }
    else {
      uVar4 = FUN_1000_af51(0x26b,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
  }
  else {
    uVar4 = FUN_1000_af51(0x1f7,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
  }
  bVar7 = false;
  if (*(int *)0x9768 == 0) {
    bVar7 = *(int *)0x9766 == 0;
  }
  if (bVar7) {
    bVar7 = false;
    if (*(int *)0x976c == 0) {
      bVar7 = *(int *)0x976a == 0;
    }
    if (bVar7) goto LAB_1000_200c;
  }
  FUN_1000_253e(unaff_BP + -4,unaff_BP + -6);
  if (*(int *)(unaff_BP + -2) < 0xf) {
    uVar4 = FUN_1000_af51(0x4a3,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    if (1 < *(int *)(unaff_BP + -2)) {
      FUN_1000_bc82(*(int *)(unaff_BP + -2),*(int *)(unaff_BP + -2) >> 0xf,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x4c8,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
    uVar4 = FUN_1000_af51(0x4d4,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    FUN_1000_24e8(*(undefined2 *)0x9094,*(undefined2 *)0x9096,unaff_BP + -0x21);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_167f(*(undefined2 *)0x9094,*(undefined2 *)0x9096,0xffff,2,1,0x17,0x4e,
                          unaff_BP + -4,unaff_BP + -6);
    uVar4 = FUN_1000_af51(uVar4);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x4f3,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
  }
  else {
    uVar4 = FUN_1000_af51(0x438,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar8 = FUN_1000_f04d(unaff_BP + -0x21);
    FUN_1000_bc82(uVar8);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x46b,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    FUN_1000_24e8(*(undefined2 *)0x9094,*(undefined2 *)0x9096,unaff_BP + -0x21);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_167f(*(undefined2 *)0x9094,*(undefined2 *)0x9096,0xffff,2,1,0x17,0x4e,
                          unaff_BP + -4,unaff_BP + -6);
    uVar4 = FUN_1000_af51(uVar4);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x487,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar8 = FUN_1000_f0a7(unaff_BP + -0x21);
    FUN_1000_24e8(uVar8);
    uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar8 = FUN_1000_f0a7(0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    uVar4 = FUN_1000_167f(uVar8);
    uVar4 = FUN_1000_af51(uVar4);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
    uVar4 = FUN_1000_af51(0x498,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
    *(undefined2 *)(unaff_BP + -4) = uVar4;
  }
  uVar4 = FUN_1000_af51(0x4f5,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  FUN_1000_bc82(uVar2,(int)uVar2 >> 0xf,unaff_BP + -0x21);
  uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  uVar4 = FUN_1000_af51(0x50e,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  iVar3 = FUN_1000_529a(*(undefined2 *)0x9766,*(undefined2 *)0x9768,*(undefined2 *)0x976a,
                        *(undefined2 *)0x976c,unaff_BP + -0x21);
  FUN_1000_bc82(iVar3,iVar3 >> 0xf);
  uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
  uVar4 = FUN_1000_af51(0x65f,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
  *(undefined2 *)(unaff_BP + -4) = uVar4;
LAB_1000_200c:
  if (((*(int *)0x9096 != 0) || (0x28 < *(uint *)0x9094)) && (1 < *(int *)(unaff_BP + -2))) {
    FUN_1000_253e(unaff_BP + -4,unaff_BP + -6);
    if ((uVar2 < *(byte *)0x90b8) || (*(byte *)0x90af < 0x3f)) {
      lVar9 = (ulong)*(uint *)(unaff_BP + -2) * (ulong)(uint)*(byte *)0x90b8;
      *(int *)(unaff_BP + -0x14) =
           (int)((ulong)lVar9 >> 0x10) +
           ((int)*(uint *)(unaff_BP + -2) >> 0xf) * (uint)*(byte *)0x90b8;
      *(undefined2 *)(unaff_BP + -0x16) = (int)lVar9;
      if (*(char *)0x90b5 == '\x02') {
        uVar5 = (uint)((ulong)*(uint *)0x94a7 * 2);
        uVar6 = *(uint *)0x949f + *(uint *)0x94a3;
        iVar3 = FUN_1000_52dc(uVar6 - uVar5,
                              ((*(int *)0x94a1 + *(int *)0x94a5 +
                               (uint)CARRY2(*(uint *)0x949f,*(uint *)0x94a3)) -
                              ((int)((ulong)*(uint *)0x94a7 * 2 >> 0x10) + *(int *)0x94a9 * 2)) -
                              (uint)(uVar6 < uVar5),0,0,*(undefined2 *)0x949b,*(undefined2 *)0x949d)
        ;
        if (iVar3 < (int)uVar2) {
          uVar8 = FUN_1000_f04d();
        }
        else {
          uVar8 = 999999;
        }
        *(undefined2 *)(unaff_BP + -0x10) = (int)((ulong)uVar8 >> 0x10);
        *(undefined2 *)(unaff_BP + -0x12) = (int)uVar8;
      }
      else {
        if (uVar2 == 0) {
          uVar8 = 999999;
        }
        else {
          uVar8 = FUN_1000_f04d();
        }
        *(undefined2 *)(unaff_BP + -0x10) = (int)((ulong)uVar8 >> 0x10);
        *(undefined2 *)(unaff_BP + -0x12) = (int)uVar8;
      }
      uVar5 = *(uint *)(unaff_BP + -2);
      puVar1 = (uint *)(unaff_BP + -0x12);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 - uVar5;
      *(int *)(unaff_BP + -0x10) =
           (*(int *)(unaff_BP + -0x10) - ((int)uVar5 >> 0xf)) - (uint)(uVar2 < uVar5);
      if ((*(int *)(unaff_BP + -0x10) < 1) &&
         ((*(int *)(unaff_BP + -0x10) != 0 || (*(int *)(unaff_BP + -0x12) == 0)))) {
        *(undefined2 *)(unaff_BP + -0x10) = 0;
        *(undefined2 *)(unaff_BP + -0x12) = 1;
      }
      lVar9 = FUN_1000_f0a7();
      lVar9 = (lVar9 - *(int *)(unaff_BP + -2)) *
              CONCAT22(*(undefined2 *)(unaff_BP + -0x10),*(undefined2 *)(unaff_BP + -0x12));
      *(undefined2 *)(unaff_BP + -0x10) = (int)((ulong)lVar9 >> 0x10);
      *(undefined2 *)(unaff_BP + -0x12) = (int)lVar9;
      if (lVar9 < 0xb4) {
        uVar4 = FUN_1000_af51(0x535,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_bc82(*(undefined1 *)0x90b8,0,unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x57b,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        FUN_1000_c0c6(*(uint *)0x99a4 + *(uint *)(unaff_BP + -0x12),
                      *(int *)0x99a6 + *(int *)(unaff_BP + -0x10) +
                      (uint)CARRY2(*(uint *)0x99a4,*(uint *)(unaff_BP + -0x12)),unaff_BP + -0x21);
        uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
        uVar4 = FUN_1000_af51(0x599,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
        *(undefined2 *)(unaff_BP + -4) = uVar4;
      }
    }
    else if (((uVar2 < *(byte *)0x90b8) || (*(byte *)0x90b8 + 9 < uVar2)) ||
            (*(char *)0x90b8 == 'd')) {
      uVar4 = FUN_1000_af51(0x61e,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      FUN_1000_bc82(*(byte *)0x90b8 + 9,0xfff6 < *(byte *)0x90b8,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x64c,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x662,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
    else {
      uVar4 = FUN_1000_af51(0x5c9,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      FUN_1000_bc82(*(undefined1 *)0x90b8,0,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x65a,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      FUN_1000_bc82(*(byte *)0x90b8 + 9,0xfff6 < *(byte *)0x90b8,unaff_BP + -0x21);
      uVar4 = FUN_1000_af51(unaff_BP + -0x21,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x5ee,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
      uVar4 = FUN_1000_af51(0x662,0xffff,2,1,0x17,0x4e,unaff_BP + -4,unaff_BP + -6);
      *(undefined2 *)(unaff_BP + -4) = uVar4;
    }
  }
  iVar3 = *(int *)(unaff_BP + -4);
  if (*(int *)(unaff_BP + -6) != 3) {
    iVar3 = iVar3 + 1;
  }
  FUN_1000_ae2b(2,1,iVar3,0x4e,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  if (*(int *)(unaff_BP + -6) == 3) {
    iVar3 = *(int *)(unaff_BP + -4) + 1;
  }
  else {
    iVar3 = *(int *)(unaff_BP + -4) + 2;
  }
  FUN_1000_1605(iVar3);
  return;
}



/* 0x124e8 ev_46fadd6e8b5508a268211fad795280d0f3831995494bffb1c90eea7902fcd2d4 */

void __cdecl16near FUN_1000_24e8(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined4 uVar1;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_f04d(*(undefined2 *)(unaff_BP + 8));
  FUN_1000_bc82(uVar1);
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 8),0xffc);
  uVar1 = FUN_1000_f07b(unaff_BP + -2);
  FUN_1000_bc82(uVar1);
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 8),unaff_BP + -2);
  return;
}



/* 0x1253e ev_cf8340d431f0e7f53779ffb379e88f49082f64f13325e0ce865b864c1c4eafda */

void __cdecl16near FUN_1000_253e(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(int *)*(undefined2 *)(unaff_BP + 6) == 3) {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 2;
  }
  else {
    *(undefined2 *)*(undefined2 *)(unaff_BP + 6) = 3;
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 2;
  }
  return;
}



/* 0x12565 ev_8f9965c3b0812f6b1bf77c45949a5162694e4d207f3ffb9451ec12175af5f00a */

void __cdecl16near FUN_1000_2565(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)0x9d38 = 0;
  FUN_1000_07c9(0x20,0);
  uVar1 = 0x153c;
  if (*(char *)0x9d4f != '\0') {
    uVar1 = 0x1542;
  }
  iVar2 = FUN_1000_b21d(3,0x14,uVar1,0xb,0,0x102e);
  if (iVar2 == -1) {
    FUN_1000_e74e(0x17a0,0x1006);
  }
  else if (iVar2 == 0) {
    FUN_1000_e74e(0x17a0,0x1548);
  }
  else if (iVar2 == 1) {
    if (*(char *)0x9d4f == '\0') {
      FUN_1000_e74e(0x17a0,0x154e);
    }
    else {
      FUN_1000_e74e(0x17a0,0x154a);
    }
  }
  else if (iVar2 == 2) {
    FUN_1000_e74e(0x17a0,0x1004);
  }
  return;
}



/* 0x12612 ev_bc0323671345bbb068d738d0ef86bbaf4e6189c6ca1b7d39429122bcd9b5dc30 */

void __cdecl16near FUN_1000_2612(void)

{
  int iVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(0,5,6);
  FUN_1000_f7da(0x18,0);
  FUN_1000_f77c();
  iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  iVar2 = 0;
  if (*(int *)(unaff_BP + 6) != 0) {
    iVar2 = 7;
  }
  FUN_1000_f7da(0x18,((0x50 - iVar1) - iVar2) / 2);
  if (*(int *)(unaff_BP + 6) != 0) {
    FUN_1000_f6a4(0x1552);
  }
  FUN_1000_f6a4(0x155a,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x12692 ev_2d8fae50de30a56981229591458be78105de851f186df7b847387ed73bd91221 */

void __cdecl16near FUN_1000_2692(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(0,1,7);
  FUN_1000_f7da(0,0);
  FUN_1000_f77c();
  FUN_1000_f6a4(0x155d,*(undefined2 *)(unaff_BP + 4));
  iVar1 = FUN_1000_f139(0x9072);
  FUN_1000_f7da(0,0x4f - iVar1);
  FUN_1000_f6a4(0x1561,0x9072);
  FUN_1000_f7da(1,0);
  uVar2 = FUN_1000_bbea(0xcd,0x50,unaff_BP + -0x51);
  FUN_1000_f6a4(0x1564,uVar2);
  FUN_1000_2612(*(undefined2 *)(unaff_BP + 6),1);
  return;
}



/* 0x12723 ev_2b1cf029e4544986aff098b595e7c3698e649ceabaeadcce75a790a1d937013c */

void __cdecl16near FUN_1000_2723(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(2,0);
  FUN_1000_f77c();
  FUN_1000_2612(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x12741 ev_6d2a7f05cb9e09f3f13391c91d55e2c1b10bde7f77e5b32a317ec0af8ac3b4b3 */

void __cdecl16near FUN_1000_2741(void)

{
  int iVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  FUN_1000_e7bd();
  *(undefined2 *)0x9d2c = 8;
  *(undefined2 *)0x9d4c = 0;
  *(undefined1 *)0x9d4e = 1;
  bVar2 = false;
  if (*(int *)0x9715 + *(int *)0x9764 + (uint)CARRY2(*(uint *)0x9713,*(uint *)0x9762) ==
      *(int *)0x949d) {
    bVar2 = *(uint *)0x9713 + *(uint *)0x9762 == *(int *)0x949b;
  }
  if ((bVar2) && (*(byte *)0x90b5 < 2)) {
    FUN_1000_2692(0x1043,0x183);
    FUN_1000_c78e(3,0xd);
    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
      FUN_1000_c98e(3,0xd,(int)*(char *)(iVar1 + 0x7a53),1);
    }
    FUN_1000_ae2b(0xf,0xd,0x15,0x43,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
    FUN_1000_af51(0x1567,0xffff,0xf,0xd,0x16,0x43,0,0);
    FUN_1000_f831();
  }
  FUN_1000_3a6d(7,1,0x1a,0);
  return;
}



/* 0x1282a ev_31c23baba81b917ccd54374580b2919d27b8b45e8d586cf607faf01304613635 */

void __cdecl16near FUN_1000_282a(void)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x1053,0x101e);
  *(undefined2 *)0x9d2c = 10;
  *(undefined2 *)0x9d4c = 0;
  *(undefined1 *)0x9d4e = 1;
  *(undefined1 *)0x9d4f = 1;
  if (*(char *)0x90b1 == '\x01') {
    FUN_1000_2612(0x183,0);
    FUN_1000_cf2e(3,0x1e);
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      FUN_1000_d14c(3,0x1e,iVar1,1);
    }
    FUN_1000_ae2b(0xf,0xd,0x14,0x43,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
    FUN_1000_af51(0x165d,0xffff,0xf,0xd,0x14,0x43,0,0);
    FUN_1000_f831();
  }
  FUN_1000_07c9(0x20,1);
  FUN_1000_d6a0(1);
  FUN_1000_07c9(0x20,0);
  *(undefined1 *)0x9d4f = 0;
  return;
}



/* 0x1291c ev_3fadd25ebb8ce0e85865b8c1509cda64620d7c78d0874c3cc66921a46b4b0aad */

void __cdecl16near FUN_1000_291c(void)

{
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x106a,0x101e);
  *(undefined2 *)0x9d4c = 0;
  FUN_1000_cd9b();
  return;
}



/* 0x1293a ev_270d5b85241cfd118e74b127541a91b2b7395915b5d08ccd7997412d91d32b75 */

void __cdecl16near FUN_1000_293a(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(1,0x1084,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x12952 ev_ce97b7020ac4e95e27044da24460b86a51cd970f1db8db9187022b193e6cc8e2 */

void __cdecl16near FUN_1000_2952(void)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(uint *)0x9d2c = (uint)(*(char *)0x90b5 == '\x02');
  *(undefined2 *)0x9d4c = 2;
  FUN_1000_2692(0x10af,0x101e);
  *(undefined1 *)0x9d4e = 1;
  uVar1 = (uint)*(byte *)0x90b2;
  if ((uVar1 != 0) && (*(char *)0x90af = *(char *)0x90af + -1, (*(byte *)(uVar1 + 0x8e7d) & 3) != 0)
     ) {
    iVar2 = FUN_1000_722b(uVar1);
    *(int *)0x9d36 = *(int *)0x9d36 - (uint)*(byte *)(iVar2 + -0x6f45);
    *(char *)0x90ae = *(char *)0x90ae + -1;
  }
  FUN_1000_3a6d(0,6,0x48,0);
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar3 = FUN_1000_e74e(0xcbc,0x10a3,0x10af,0x843);
    uVar3 = FUN_1000_e717(uVar3);
    FUN_1000_2692(uVar3);
    FUN_1000_8c42(*(char *)0x90b5 == '\x02',0x1720);
    FUN_1000_2565();
  }
  if ((uVar1 != 0) &&
     (*(char *)0x90af = *(char *)0x90af + '\x01', (*(byte *)(uVar1 + 0x8e7d) & 3) != 0)) {
    iVar2 = FUN_1000_722b(uVar1);
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar2 + -0x6f45);
    *(char *)0x90ae = *(char *)0x90ae + '\x01';
  }
  return;
}



/* 0x12a2c ev_5c2ca4b624e32b279be83d75d80670f34e6a0733f542bc309088acc7ea225841 */

void __cdecl16near FUN_1000_2a2c(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)0x9d36 = 0;
  while (*(int *)(unaff_BP + -2) < 0x1a) {
    iVar3 = FUN_1000_722b((int)*(char *)(*(int *)(unaff_BP + -2) + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar3 + -0x6f45);
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
  }
  uVar1 = *(undefined1 *)0x90ae;
  uVar2 = *(undefined1 *)0x90af;
  *(uint *)(unaff_BP + -2) = (uint)*(byte *)0x90ba;
  *(undefined1 *)0x90ae = 0x16;
  *(undefined1 *)0x90af = 0x3f;
  *(undefined1 *)0x90ba = 1;
  *(uint *)0x9d2c = (uint)(*(char *)0x90b5 == '\x02');
  *(undefined2 *)0x9d4c = 3;
  FUN_1000_2692(0x10bd,0x101e);
  *(undefined1 *)0x9d4e = 1;
  FUN_1000_3a6d(0,6,0x48,0);
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar4 = FUN_1000_e74e(0xcbc,0x10a3,0x10bd,0x843);
    uVar4 = FUN_1000_e717(uVar4);
    FUN_1000_2692(uVar4);
    FUN_1000_8c42(*(char *)0x90b5 == '\x02',0x1721);
    FUN_1000_2565();
  }
  *(undefined1 *)0x90ae = uVar1;
  *(undefined1 *)0x90af = uVar2;
  *(undefined1 *)0x90ba = (char)*(undefined2 *)(unaff_BP + -2);
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)0x9d36 = 0;
  while (*(uint *)(unaff_BP + -2) < *(byte *)0x90ae + 4) {
    iVar3 = FUN_1000_722b((int)*(char *)(*(int *)(unaff_BP + -2) + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar3 + -0x6f45);
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
  }
  *(undefined2 *)0x9d4c = 2;
  return;
}



/* 0x12b58 ev_b1f41467c365024648cb8cedc50e532d5ef9c66ec499ff4727c3d1da1d50d0f3 */

void __cdecl16near FUN_1000_2b58(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  uint uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x10cb,0x101e);
  *(undefined2 *)0x9d2c = 4;
  *(undefined2 *)0x9d4c = 1;
  iVar1 = FUN_1000_b5b2(0xffe,0,0,unaff_BP + -2);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    return;
  }
  if (*(int *)(unaff_BP + -2) == 0) {
    FUN_1000_b194(0x12fb,0x23,4);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return;
  }
  uVar2 = FUN_1000_e74e(0x9d3e,*(undefined2 *)(unaff_BP + -2),0x1722);
  uVar2 = FUN_1000_e7cd(uVar2);
  *(undefined2 *)0x9070 = uVar2;
  uVar2 = FUN_1000_e74e(0xcbc,0x9d3e,0x1328,0x101e);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(uVar2);
  *(undefined1 *)0x9d4e = 1;
  while( true ) {
    iVar1 = FUN_1000_3a6d(0,6,0x48,1);
    if (iVar1 != 0) break;
    *(undefined1 *)0x9d38 = 0;
    FUN_1000_b1f3(0,1,7);
    FUN_1000_2723(*(undefined2 *)(unaff_BP + 4));
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  *(undefined1 *)0x9d50 = 0;
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar2 = FUN_1000_e74e(0xcbc,0x10a3,0x9d3e,0x1328,0x843);
    uVar2 = FUN_1000_e717(uVar2);
    uVar2 = FUN_1000_e717(uVar2);
    FUN_1000_2692(uVar2);
    FUN_1000_8c42(4,0x1724);
    FUN_1000_2565();
  }
  *(undefined2 *)0x9d36 = 0;
  for (uVar3 = 0; uVar3 < *(byte *)0x90ae + 4; uVar3 = uVar3 + 1) {
    iVar1 = FUN_1000_722b((int)*(char *)(uVar3 + 0x7aee));
    *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
  }
  return;
}



/* 0x12cc6 ev_a4da69448f9c0d00a27b641cc7e155616a8903229bef967eb2c02ced265a9321 */

void __cdecl16near FUN_1000_2cc6(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_07c9(0x20,1);
  FUN_1000_2692(0x10d5,0x101e);
  *(uint *)0x9d2c = (uint)(*(char *)0x90b5 == '\x02');
  *(undefined2 *)0x9d4c = 5;
  *(undefined1 *)0x9d4f = 1;
  *(undefined1 *)0x9d4e = 1;
  FUN_1000_d6a0(4);
  if (*(char *)0x9d38 != '\0') {
    FUN_1000_51c5();
    uVar1 = FUN_1000_e74e(0xcbc,0x10a3,0x10d5,0x843);
    uVar1 = FUN_1000_e717(uVar1);
    FUN_1000_2692(uVar1);
    FUN_1000_8c42(*(char *)0x90b5 == '\x02',0x1725);
    FUN_1000_2565();
  }
  FUN_1000_07c9(0x20,0);
  *(undefined1 *)0x9d4f = 0;
  return;
}



/* 0x12d6a ev_3c6ee1ad04a3555b9da7935c26fa48375e8174fba076db707b60e4de92186be3 */

void __cdecl16near FUN_1000_2d6a(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(2,0x10e1,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x12d82 ev_7c318a0bd20ad6186767c3d034f36f83e96f3172e549df98ef38c75c2586b300 */

void __cdecl16near FUN_1000_2d82(void)

{
  undefined2 uVar1;
  int iVar2;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e74e(0xcbc,0x101e,0x1009,0x114f,1);
  uVar1 = FUN_1000_e717(uVar1);
  uVar1 = FUN_1000_e717(uVar1);
  FUN_1000_2692(0x113f,uVar1);
  iVar2 = FUN_1000_8c42(8,0x1726);
  if (iVar2 == 0x1b) {
    uVar1 = 0x1004;
  }
  else {
    uVar1 = 0x1727;
  }
  FUN_1000_e74e(0x17a0,uVar1);
  return;
}



/* 0x12de2 ev_fab4e3132827c77270bbb58eb4d0c1cdb287f0efdbe2bd1fb1521e8623be0b13 */

void __cdecl16near FUN_1000_2de2(void)

{
  undefined2 uVar1;
  int iVar2;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e74e(0xcbc,0x101e,0x1009,0x115b,1);
  uVar1 = FUN_1000_e717(uVar1);
  uVar1 = FUN_1000_e717(uVar1);
  FUN_1000_2692(0x114f,uVar1);
  iVar2 = FUN_1000_853c(0);
  if (iVar2 == 0x1b) {
    uVar1 = 0x1004;
  }
  else {
    uVar1 = 0x1729;
  }
  FUN_1000_e74e(0x17a0,uVar1);
  return;
}



/* 0x12e3b ev_d351edfa009d2000173536d112594081896dafd9adfefd03268596edbfc68bf0 */

void __cdecl16near FUN_1000_2e3b(void)

{
  undefined2 uVar1;
  int iVar2;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e74e(0xcbc,0x101e,0x1009,0x113f,1);
  uVar1 = FUN_1000_e717(uVar1);
  uVar1 = FUN_1000_e717(uVar1);
  FUN_1000_2692(0x115b,uVar1);
  iVar2 = FUN_1000_853c(1);
  if (iVar2 == 0x1b) {
    uVar1 = 0x1004;
  }
  else {
    uVar1 = 0x172b;
  }
  FUN_1000_e74e(0x17a0,uVar1);
  return;
}



/* 0x12e95 ev_f253de0790e070da9e89080a4c7d148e9a8555b654115664c677397f8c347853 */

void __cdecl16near FUN_1000_2e95(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(3,0x116a,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x12ead ev_a4f54aafefdac5c3b03c845c9f6c15ebb7cc271c62ed3e1529aa085700a9525e */

void __cdecl16near FUN_1000_2ead(void)

{
  FUN_1000_e7bd();
  FUN_1000_2692(0x1193,0x101e);
  FUN_1000_cbd7();
  return;
}



/* 0x12ec5 ev_1d5cf36ec7dc914a40abbd48f3b71eaadbfd8f5934f818829e1b8072107e16e3 */

void __cdecl16near FUN_1000_2ec5(void)

{
  FUN_1000_e7bd();
  FUN_1000_2692(0x11a5,0x101e);
  FUN_1000_cc89();
  return;
}



/* 0x12edd ev_b89b04194153b74823d8da471fdaf118536da98b3dd65139138c23f5d8a7a168 */

void __cdecl16near FUN_1000_2edd(void)

{
  FUN_1000_e7bd();
  FUN_1000_2692(0x11ba,0x101e);
  FUN_1000_ccdd();
  return;
}



/* 0x12ef5 ev_b2a31633367a69a5004b122f3337dcf85839ca700409696f13a0bc50fa8be858 */

void __cdecl16near FUN_1000_2ef5(void)

{
  FUN_1000_e7bd();
  FUN_1000_2692(0x11d5,0x101e);
  FUN_1000_cb56();
  return;
}



/* 0x12f0d ev_f9195ef7a9e42e94ee04f64d51779238e7475dec2d390611858ba85b034be1a6 */

void __cdecl16near FUN_1000_2f0d(void)

{
  FUN_1000_e7bd();
  FUN_1000_2692(0x11eb,0x101e);
  FUN_1000_cd3c();
  return;
}



/* 0x12f25 ev_eabeb05faabbc5aa3cc3653f2eaef985f6ee428eb5cc4260f904efebf8d9bd4d */

void __cdecl16near FUN_1000_2f25(void)

{
  int iVar1;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_9018(0,0x11fc,0x101e);
  if (iVar1 == 2) {
    FUN_1000_e74e(0x17a0,0x1004);
  }
  return;
}



/* 0x12f50 ev_c5a3fd9dc69ad32550fc753fa359b33ee555e39789f1d9d5c45d95df9f41a38a */

void __cdecl16near FUN_1000_2f50(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(4,0x1220,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x12f68 ev_51f9151685a75cdad41334fa891af639cad187a23884d24b2da74488ebb105ee */

void __cdecl16near FUN_1000_2f68(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x172d,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_ab36();
  return;
}



/* 0x12f7f ev_5ea93d17618cbbf9c80ec136f3b9218f9ea06ef495d0550d64da329a8779fbbf */

void __cdecl16near FUN_1000_2f7f(void)

{
  FUN_1000_e7bd();
  FUN_1000_2692(0x123f,0x101e);
  FUN_1000_7a3a();
  return;
}



/* 0x12f97 ev_20f76397416b291765a615db8d4cf0a375b8b3fac99d5b0100fc43607ec03b41 */

void __cdecl16near FUN_1000_2f97(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(7,0x124b,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x12faf ev_19517ac123a249c3b31396c96bcff45513ff1a45666090e9e9c1a9fc5cf02116 */

void __cdecl16near FUN_1000_2faf(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x1267,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_bd1f();
  FUN_1000_5c49();
  return;
}



/* 0x12fc9 ev_756a515a7e03a3939f34ee534663c451a69e47be5d947ab4d45d36c05d5a5a88 */

void __cdecl16near FUN_1000_2fc9(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x1283,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_5cbb();
  return;
}



/* 0x12fe0 ev_e3a63bda74efcdd00df9697e2623726d1c5ef00ef89d48eb707f883e57fd8eb3 */

void __cdecl16near FUN_1000_2fe0(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x12d5,0x101e);
  iVar1 = FUN_1000_b5b2(0xffe,0,1,unaff_BP + -2);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    return;
  }
  if (*(int *)(unaff_BP + -2) == 0) {
    FUN_1000_b194(0x12fb,0x23,4);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return;
  }
  FUN_1000_e74e(0x9d3e,*(undefined2 *)(unaff_BP + -2));
  uVar2 = FUN_1000_e74e(0xcbc,0x1733,0x9d3e,0x173f,0x1751);
  uVar2 = FUN_1000_e717(uVar2);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(uVar2);
  FUN_1000_2612(0x183,0);
  FUN_1000_8c42(10,0x9d3e);
  FUN_1000_e74e(0x17a0,0x1004);
  return;
}



/* 0x130ac ev_1288f46e0840533d31948e021a1b67d6fcbf0e117d969432c0c62be9ae2e5446 */

void __cdecl16near FUN_1000_30ac(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_bd1f();
  if (*(char *)0x9d4e == '\0') {
    FUN_1000_2692(0x113f,*(undefined2 *)(unaff_BP + 4));
    iVar1 = FUN_1000_5ec5();
    if (iVar1 == -1) {
      return;
    }
  }
  *(undefined1 *)0x9d4e = 0;
  FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  uVar2 = FUN_1000_e74e(0xcbc,0x111a,0x1009,0x114f);
  uVar2 = FUN_1000_e717(uVar2);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(0x113f,uVar2);
  iVar1 = FUN_1000_8c42(8,0x1752);
  if (iVar1 != 0x1b) {
    *(undefined1 *)0x9d4e = 1;
    FUN_1000_e74e(0x17a0,0x1753);
  }
  FUN_1000_e74e(0x9072,0x1314);
  return;
}



/* 0x13149 ev_a3e93358ce2657ac1a9304680e50ef8e05e7936ab9edbcc068731af8bbb268f7 */

void __cdecl16near FUN_1000_3149(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_bd1f();
  if (*(char *)0x9d4e != '\x01') {
    FUN_1000_2692(0x114f,*(undefined2 *)(unaff_BP + 4));
    iVar1 = FUN_1000_5ec5();
    if (iVar1 == -1) {
      return;
    }
  }
  *(undefined1 *)0x9d4e = 0;
  FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  uVar2 = FUN_1000_e74e(0xcbc,0x111a,0x1009,0x115b);
  uVar2 = FUN_1000_e717(uVar2);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(0x114f,uVar2);
  iVar1 = FUN_1000_853c(0);
  if (iVar1 != 0x1b) {
    *(undefined1 *)0x9d4e = 1;
    FUN_1000_e74e(0x17a0,0x1755);
  }
  FUN_1000_e74e(0x9072,0x1314);
  return;
}



/* 0x131df ev_ec8fe1d9a6f6def94e9251c47895659929c78937784ca14e89648ddbd5107dda */

void __cdecl16near FUN_1000_31df(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_bd1f();
  if (*(char *)0x9d4e != '\x01') {
    FUN_1000_2692(0x115b,*(undefined2 *)(unaff_BP + 4));
    iVar1 = FUN_1000_5ec5();
    if (iVar1 == -1) {
      return;
    }
  }
  *(undefined1 *)0x9d4e = 0;
  FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  uVar2 = FUN_1000_e74e(0xcbc,0x111a,0x1009,0x113f);
  uVar2 = FUN_1000_e717(uVar2);
  uVar2 = FUN_1000_e717(uVar2);
  FUN_1000_2692(0x115b,uVar2);
  iVar1 = FUN_1000_853c(1);
  if (iVar1 != 0x1b) {
    *(undefined1 *)0x9d4e = 1;
    FUN_1000_e74e(0x17a0,0x1757);
  }
  FUN_1000_e74e(0x9072,0x1314);
  return;
}



/* 0x13276 ev_94afe281e29b82fca65d9a2de1fb87f5fa6edcacafc4b00af6896c455aac17ad */

void __cdecl16near FUN_1000_3276(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x129b,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_bd1f();
  iVar1 = FUN_1000_5ec5();
  if (iVar1 != -1) {
    FUN_1000_2723(*(undefined2 *)(unaff_BP + 4));
    FUN_1000_5e0d(iVar1);
  }
  return;
}



/* 0x132a5 ev_e114afc1935e5c51c3db9c06aac6b6e1abe54f4d6f9653aa61b44e65c32e0f1e */

void __cdecl16near FUN_1000_32a5(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(5,0x12b9,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x132bd ev_31178a5a8f998404e03f4c48cc55e8088bdbbea865b8006c60bd65b701480de9 */

void __cdecl16near FUN_1000_32bd(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(6,0x12b9,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x132d5 ev_9df449c16d7435628c21c63e1a191063946dca9ec7122954ff7990575d3d2324 */

void __cdecl16near FUN_1000_32d5(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_9018(8,0x116a,*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x132ed ev_3626d12191b440f311ab96ddd71ddde56b703eefdc86bd9ba584beabca2da55f */

/* WARNING: Removing unreachable block (ram,0x000133ae) */

void __cdecl16near FUN_1000_32ed(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar5;
  long lVar6;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -3) = 0;
  *(undefined1 *)(unaff_BP + -2) = 0;
  *(undefined1 *)(unaff_BP + -1) = 0;
  uVar2 = 0x843;
  if (-1 < *(int *)(unaff_BP + 6)) {
    uVar2 = *(undefined2 *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134c);
  }
  FUN_1000_366e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),uVar2);
LAB_1000_3327:
  do {
    if (*(char *)(unaff_BP + -3) != '\0') {
      FUN_1000_b1f3(0,1,7);
      return;
    }
    *(bool *)0x17a5 = *(char *)0x17a0 == '\0';
    FUN_1000_37f2(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
    uVar2 = FUN_1000_3a2e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
    FUN_1000_f7da(3,uVar2);
    if ((*(char *)0x16a == '\0') || (*(char *)0x17a5 == '\0')) {
      if (*(char *)0x17a0 == '\0') {
        uVar5 = FUN_1000_4cb5();
        *(undefined2 *)(unaff_BP + -7) = (int)((ulong)uVar5 >> 0x10);
        *(undefined2 *)(unaff_BP + -9) = (int)uVar5;
        do {
          iVar3 = FUN_1000_f84a();
          if (((0 < iVar3) ||
              (lVar6 = FUN_1000_4cb5(),
              CONCAT22(*(int *)(unaff_BP + -7) + (uint)(0xfe0b < *(uint *)(unaff_BP + -9)),
                       *(uint *)(unaff_BP + -9) + 500) <= lVar6)) ||
             (0x83 < *(int *)(unaff_BP + -7))) break;
        } while ((*(int *)(unaff_BP + -7) != 0x83) || (*(uint *)(unaff_BP + -9) < 0xc278));
        iVar3 = FUN_1000_f84a();
        if (iVar3 < 1) {
          FUN_1000_370e();
        }
      }
    }
    else {
      *(undefined1 *)0x16a = 0;
      FUN_1000_370e();
    }
    iVar3 = FUN_1000_35c3();
    *(undefined1 *)(unaff_BP + -2) = *(undefined1 *)(unaff_BP + -1);
    if ((iVar3 == 0x1b) && (iVar4 = FUN_1000_38f1(*(undefined2 *)(unaff_BP + 4),0x71), iVar4 != -1))
    {
      iVar3 = 0x71;
    }
    if (((iVar3 < 0x80) && ((*(byte *)(iVar3 + -0x7183) & 3) != 0)) &&
       (iVar4 = FUN_1000_38f1(*(undefined2 *)(unaff_BP + 4),iVar3), iVar4 != -1)) {
      *(undefined1 *)(unaff_BP + -1) = (char)iVar4;
      *(undefined1 *)(unaff_BP + -2) = (char)iVar4;
      iVar3 = 10;
      *(uint *)(unaff_BP + -5) = (uint)*(byte *)0x17a5;
      *(undefined1 *)0x17a5 = 0;
      FUN_1000_394a(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
      *(undefined1 *)0x17a5 = (char)*(undefined2 *)(unaff_BP + -5);
    }
    if ((iVar3 != 10) && (iVar3 != 0xd)) {
      if (iVar3 == 0x1b) {
        *(undefined1 *)(unaff_BP + -3) = 1;
        goto LAB_1000_3327;
      }
      if (iVar3 != 0x20) {
        if (iVar3 == 0xcb) {
          uVar1 = FUN_1000_35f5(0xcb,*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
          *(undefined1 *)(unaff_BP + -1) = uVar1;
          goto LAB_1000_3327;
        }
        if (iVar3 != 0xcd) {
          FUN_1000_7e47(5);
          goto LAB_1000_3327;
        }
      }
      uVar1 = FUN_1000_35f5(0xcd,*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
      *(undefined1 *)(unaff_BP + -1) = uVar1;
      goto LAB_1000_3327;
    }
    if (*(int *)((uint)*(byte *)(unaff_BP + -1) * 2 + *(int *)(unaff_BP + 4) * 0x1f + 0x135d) < 0) {
      FUN_1000_c19a();
      iVar3 = *(int *)(unaff_BP + 4) * 0x1f;
      (*(code *)*(undefined2 *)
                 (*(int *)((uint)*(byte *)(unaff_BP + -1) * 2 + iVar3 + 0x135d) * -2 + 0x1759))
                (*(undefined2 *)(iVar3 + 0x134c));
      *(bool *)0x17a5 = *(char *)0x17a0 == '\0';
      *(undefined1 *)(unaff_BP + -1) = *(undefined1 *)(unaff_BP + -2);
      uVar2 = 0x843;
      if (-1 < *(int *)(unaff_BP + 6)) {
        uVar2 = *(undefined2 *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134c);
      }
      FUN_1000_366e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),uVar2);
      FUN_1000_c1af();
    }
    else {
      FUN_1000_32ed(*(undefined2 *)
                     ((uint)*(byte *)(unaff_BP + -1) * 2 + *(int *)(unaff_BP + 4) * 0x1f + 0x135d),
                    *(undefined2 *)(unaff_BP + 4));
      *(bool *)0x17a5 = *(char *)0x17a0 == '\0';
      uVar2 = 0x843;
      if (-1 < *(int *)(unaff_BP + 6)) {
        uVar2 = *(undefined2 *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134c);
      }
      FUN_1000_366e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),uVar2);
      FUN_1000_37f2(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
    }
  } while( true );
}



/* 0x135c3 ev_99e51f51af172380670b414410b3f14c40dd56d32fc20431aa21ef03c64256f8 */

uint __cdecl16near FUN_1000_35c3(void)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x17a0 == '\0') {
    uVar1 = FUN_1000_f831();
  }
  else {
    uVar1 = (uint)*(byte *)0x17a0;
    for (iVar2 = 0; *(char *)(iVar2 + 0x17a0) != '\0'; iVar2 = iVar2 + 1) {
      *(undefined1 *)(iVar2 + 0x17a0) = *(undefined1 *)(iVar2 + 0x17a1);
    }
  }
  return uVar1;
}



/* 0x135f5 ev_5e8b1e6d86790f276508b45892b910a70bfa67fbc04fb333cd803e48c6246282 */

undefined2 __cdecl16near FUN_1000_35f5(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(int *)(unaff_BP + 4) == 0xcd) {
    uVar1 = *(undefined2 *)(unaff_BP + 8);
    *(int *)(unaff_BP + 8) = *(int *)(unaff_BP + 8) + 1;
    FUN_1000_39c4(*(undefined2 *)(unaff_BP + 6),uVar1);
    if (*(byte *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134e) - 1 < *(uint *)(unaff_BP + 8)) {
      *(undefined2 *)(unaff_BP + 8) = 0;
    }
  }
  else {
    uVar1 = *(undefined2 *)(unaff_BP + 8);
    *(int *)(unaff_BP + 8) = *(int *)(unaff_BP + 8) + -1;
    FUN_1000_39c4(*(undefined2 *)(unaff_BP + 6),uVar1);
    if (*(int *)(unaff_BP + 8) < 0) {
      *(int *)(unaff_BP + 8) = *(byte *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134e) - 1;
    }
  }
  FUN_1000_394a(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8));
  return *(undefined2 *)(unaff_BP + 8);
}



/* 0x1366e ev_a545e9e0b8b411f8891b88f927bbecac71d83fb858ce2203b5196d830ec64423 */

void __cdecl16near FUN_1000_366e(void)

{
  byte bVar1;
  byte bVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_2692(*(undefined2 *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134c),
                  *(undefined2 *)(unaff_BP + 8));
    FUN_1000_b1f3(0,5,7);
    FUN_1000_f7da(3,0);
    FUN_1000_f74a();
    while (*(byte *)(unaff_BP + -1) < *(byte *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134e)) {
      bVar1 = *(byte *)(unaff_BP + 4);
      bVar2 = *(byte *)(unaff_BP + -1);
      *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
      FUN_1000_f6a4(*(undefined2 *)((uint)bVar1 * 0x1f + (uint)bVar2 * 2 + 0x134f));
      FUN_1000_f6a4(0x1a45);
    }
    FUN_1000_394a(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
  }
  return;
}



/* 0x1370e ev_b5879cfab668642701a6bf4d69d300e9df849407ec08e02cbe90f09ee4a9ed1c */

void __cdecl16near FUN_1000_370e(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -2) = 5;
  FUN_1000_b1f3(0,1,7);
  FUN_1000_ae2b(7,3,0x15,0x4c,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  iVar1 = FUN_1000_af51(0x17a6,0xffff,7,3,0x15,0x4c,0,unaff_BP + -2);
  iVar1 = FUN_1000_af51(0x185e,0xffff,iVar1 + -1,3,0x15,0x4c,0,unaff_BP + -2);
  iVar1 = FUN_1000_af51(0x18a6,0xffff,iVar1 + 1,3,0x15,0x4c,0,0);
  FUN_1000_af51(0x1997,0xffff,iVar1 + 1,3,0x15,0x4c,0,0);
  return;
}



/* 0x137f2 ev_8c036371284441f908edfdb28adc14b761cc20728728626bef153dc6aada93e7 */

void __cdecl16near FUN_1000_37f2(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_b1f3(0,5,6);
    FUN_1000_f7da(4,0);
    FUN_1000_f74a();
  }
  if ((*(int *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2 + 0x135d) <
       0) && (*(char *)0x17a5 != '\0')) {
    FUN_1000_f6a4(*(undefined2 *)
                   (*(int *)((uint)*(byte *)(unaff_BP + 4) * 0x1f +
                             (uint)*(byte *)(unaff_BP + 6) * 2 + 0x135d) * -2 + 0x14f5));
  }
  else {
    FUN_1000_f7da(4,0);
    *(undefined1 *)(unaff_BP + 4) =
         (char)*(undefined2 *)
                ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2 + 0x135d);
    while (*(byte *)(unaff_BP + -1) < *(byte *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134e)) {
      if (*(char *)0x17a5 != '\0') {
        FUN_1000_f6a4(0x1a48,*(undefined2 *)
                              ((uint)*(byte *)(unaff_BP + 4) * 0x1f +
                               (uint)*(byte *)(unaff_BP + -1) * 2 + 0x134f));
      }
      *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
    }
  }
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x138f1 ev_4ae3bae754b74a2e38d20f5ac82a64ac747cccbb3ceaf78b35d6eda6bbcf2f17 */

ulong __cdecl16near FUN_1000_38f1(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e793(*(undefined2 *)(unaff_BP + 6));
  *(undefined2 *)(unaff_BP + 6) = uVar1;
  *(undefined1 *)(unaff_BP + -1) = 0;
  while( true ) {
    if (*(byte *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134e) <= *(byte *)(unaff_BP + -1)) {
      return 0xffff;
    }
    if ((int)*(char *)*(undefined2 *)
                       ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + -1) * 2 +
                       0x134f) == *(int *)(unaff_BP + 6)) break;
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
  }
  return (ulong)*(byte *)(unaff_BP + -1);
}



/* 0x1394a ev_84fe9a6617e49d70ce692aeb53fcd568469aa215c85a0f26385a398e5c4043b2 */

void __cdecl16near FUN_1000_394a(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(1,5,6);
  uVar1 = FUN_1000_3a2e(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
  FUN_1000_f7da(3,uVar1);
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_f6a4(*(undefined2 *)
                   ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2 +
                   0x134f));
  }
  FUN_1000_b1f3(0,5,7);
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_f6a4(0x1a4d);
  }
  return;
}



/* 0x139c4 ev_ecd5b312c5ccdf1bb9d9bb75e2a8f44bf13baa8719e9d0fd8ba91996300cd139 */

void __cdecl16near FUN_1000_39c4(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(0,5,7);
  if (*(char *)0x17a5 != '\0') {
    uVar1 = FUN_1000_3a2e(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
    FUN_1000_f7da(3,uVar1);
    FUN_1000_f6a4(*(undefined2 *)
                   ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2 +
                   0x134f));
  }
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x13a2e ev_c9fc2ce3fe49f925a28f0513c6d1064b538924774dd3d80e720c4342df01e1a8 */

undefined1 __cdecl16near FUN_1000_3a2e(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  while (cVar1 = *(char *)(unaff_BP + 6), *(char *)(unaff_BP + 6) = *(char *)(unaff_BP + 6) + -1,
        cVar1 != '\0') {
    cVar1 = FUN_1000_f139(*(undefined2 *)
                           ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2
                           + 0x134f));
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + cVar1 + '\x02';
  }
  return *(undefined1 *)(unaff_BP + -1);
}



/* 0x13a6d ev_f1ff498e7bf71235d47ba485f45fe1d9f9bd0773b9da0f721a7af1946bc93afd */

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



/* 0x14232 ev_e4e2119d12d0fbda88c0feee88f8cb76ac4a2839cc2048589ca98e30bee9cc28 */

void __cdecl16near FUN_1000_4232(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_2692(0x1043,0x101e);
  FUN_1000_4802(*(undefined1 *)(unaff_BP + 4),0x18,1);
  FUN_1000_ae2b(*(byte *)(unaff_BP + 4) + 6,*(byte *)(unaff_BP + 6) - 1,*(byte *)(unaff_BP + 4) + 8,
                0x50 - (uint)*(byte *)(unaff_BP + 6),1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 7,*(byte *)(unaff_BP + 6) + 1);
  FUN_1000_f6a4(0x1b91);
  if (*(char *)0x9d52 == '\0') {
    FUN_1000_ae2b(*(byte *)(unaff_BP + 4) + 10,4,*(byte *)(unaff_BP + 4) + 0xd,0x4b,1,0xcd,0xb3,0xd5
                  ,0xb8,0xd4,0xbe);
    FUN_1000_af51(0x1bab,0xffff,*(byte *)(unaff_BP + 4) + 10,4,*(byte *)(unaff_BP + 4) + 0xd,0x4b,0,
                  0);
  }
  else {
    FUN_1000_4344(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6));
  }
  return;
}



/* 0x14344 ev_f90c1b1fc427cce0fcaadd207caa8e1e0585df2a343b36d3c2db1e6658e1f542 */

void __cdecl16near FUN_1000_4344(void)

{
  int unaff_BP;
  uint uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d52 == '\0') {
    FUN_1000_b1f3(0,1,7);
    for (uVar1 = *(byte *)(unaff_BP + 4) + 10; uVar1 < *(byte *)(unaff_BP + 4) + 0xe;
        uVar1 = uVar1 + 1) {
      FUN_1000_f7da(uVar1,0);
      FUN_1000_f74a();
    }
    FUN_1000_b1f3(0,2,7);
  }
  FUN_1000_ae2b(*(byte *)(unaff_BP + 4) + 10,*(byte *)(unaff_BP + 6) + 5,
                *(byte *)(unaff_BP + 4) + 0xd,0x4a - (uint)*(byte *)(unaff_BP + 6),1,0xcd,0xb3,0xd5,
                0xb8,0xd4,0xbe);
  FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 0xb,*(byte *)(unaff_BP + 6) + 7);
  FUN_1000_f6a4(0x1c31);
  FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 0xc,*(byte *)(unaff_BP + 6) + 7);
  FUN_1000_f6a4(0x1c40);
  return;
}



/* 0x14427 ev_2fcf63af004b8f35e71ecf05d54940edd5e739ea1f49ea86f43322d4205f8092 */

void __cdecl16near FUN_1000_4427(void)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int unaff_BP;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {
    *(undefined1 *)(*(int *)(unaff_BP + 10) + iVar4) = 0x20;
    uVar2 = 0;
    if (*(int *)(unaff_BP + 4) == 1) {
      uVar2 = 0xff;
    }
    *(undefined1 *)(unaff_BP + iVar4 + -3) = uVar2;
  }
  iVar4 = 0;
  do {
    if (*(int *)(unaff_BP + 6) <= iVar4) {
      if (((*(char *)0x90af == '\x03') && (*(int *)(unaff_BP + 4) != 0)) ||
         ((*(char *)0x90af == '\x04' && (*(int *)(unaff_BP + 4) == 2)))) {
        *(undefined1 *)(*(int *)(unaff_BP + 10) + 2) = 0x20;
      }
      return;
    }
    iVar3 = FUN_1000_722b((int)*(char *)*(undefined2 *)(unaff_BP + 8));
    bVar1 = *(byte *)(iVar3 + -0x6f45);
    *(undefined2 *)(unaff_BP + -5) = 0;
    while( true ) {
      if (((2 < *(int *)(unaff_BP + -5)) ||
          (iVar3 = FUN_1000_e7a7((int)*(char *)*(undefined2 *)(unaff_BP + 8)),
          iVar3 == *(char *)(*(int *)(unaff_BP + 10) + *(int *)(unaff_BP + -5)))) ||
         (*(char *)*(undefined2 *)(unaff_BP + 8) == ' ')) goto LAB_1000_4529;
      if (((*(int *)(unaff_BP + 4) == 1) &&
          (bVar1 <= *(byte *)(*(int *)(unaff_BP + -5) + unaff_BP + -3))) ||
         ((*(int *)(unaff_BP + 4) != 1 &&
          (*(byte *)(*(int *)(unaff_BP + -5) + unaff_BP + -3) < bVar1)))) break;
      *(int *)(unaff_BP + -5) = *(int *)(unaff_BP + -5) + 1;
    }
    if (*(int *)(unaff_BP + -5) < 2) {
      *(undefined1 *)(*(int *)(unaff_BP + 10) + 2) = *(undefined1 *)(*(int *)(unaff_BP + 10) + 1);
      *(undefined1 *)(unaff_BP + -1) = *(undefined1 *)(unaff_BP + -2);
    }
    if (*(int *)(unaff_BP + -5) == 0) {
      ((undefined1 *)*(undefined2 *)(unaff_BP + 10))[1] =
           *(undefined1 *)*(undefined2 *)(unaff_BP + 10);
      *(undefined1 *)(unaff_BP + -2) = *(undefined1 *)(unaff_BP + -3);
    }
    uVar2 = FUN_1000_e7a7((int)*(char *)*(undefined2 *)(unaff_BP + 8));
    *(undefined1 *)(*(int *)(unaff_BP + 10) + *(int *)(unaff_BP + -5)) = uVar2;
    *(byte *)(*(int *)(unaff_BP + -5) + unaff_BP + -3) = bVar1;
LAB_1000_4529:
    *(int *)(unaff_BP + 8) = *(int *)(unaff_BP + 8) + 1;
    iVar4 = iVar4 + 1;
  } while( true );
}



/* 0x14557 ev_652969abb3576886c42d0d6ddaf9d5770cbb472e977941fa32ab574741264a1a */

int __cdecl16near FUN_1000_4557(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int unaff_BP;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = 0;
  *(undefined2 *)(unaff_BP + -2) = 0;
  *(undefined2 *)(unaff_BP + -4) = 0;
  *(undefined2 *)(unaff_BP + -8) = 0;
  *(undefined2 *)(unaff_BP + -10) = 0;
  if ((*(char *)(unaff_BP + 8) != '\0') && ((*(byte *)0x90af < 8 || (*(char *)0x90b2 == '\0')))) {
    if ((*(int *)(unaff_BP + 10) == 1) && (*(char *)0x9d50 == '\0')) {
      FUN_1000_4232(7,0x1a);
    }
    *(undefined1 *)0x90b2 = 0;
    *(undefined1 *)0x9d50 = 0;
    return 0;
  }
  if (*(char *)(unaff_BP + 8) != '\0') {
    uVar1 = FUN_1000_e7a7(*(undefined1 *)0x90b2);
    iVar2 = FUN_1000_e677(*(undefined2 *)(unaff_BP + 4),uVar1);
    if (iVar2 == 0) {
      uVar1 = FUN_1000_e793(*(undefined1 *)0x90b2);
      iVar2 = FUN_1000_e677(*(undefined2 *)(unaff_BP + 4),uVar1);
      if (iVar2 == 0) goto LAB_1000_4710;
    }
  }
  *(undefined1 *)0x9d4e = 1;
  *(undefined1 *)0x9d51 = 1;
  FUN_1000_2692(0x1c4f,0x101e);
  FUN_1000_c78e(0xc,0xd);
  FUN_1000_4757();
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    FUN_1000_6298(unaff_BP + -0x5b,*(undefined1 *)(unaff_BP + 6));
    FUN_1000_4802(5,0x18,1);
    FUN_1000_f7da(5,0x1c);
    FUN_1000_f6a4(0x1c5f,unaff_BP + -0x5b);
    FUN_1000_bd1f();
    iVar4 = FUN_1000_4a70(6,0x1c,unaff_BP + -0x5b,unaff_BP + -2,unaff_BP + -4,unaff_BP + -10);
    if (iVar4 == -1) break;
  }
  uVar3 = (uint)*(byte *)0x90b2;
  *(uint *)(unaff_BP + -6) = uVar3;
  if (((*(byte *)(uVar3 + 0x8e7d) & 3) != 0) &&
     (uVar3 = FUN_1000_722b(uVar3), uVar3 <= *(byte *)0x90af)) {
    iVar2 = FUN_1000_722b(*(undefined2 *)(unaff_BP + -6));
    *(int *)0x9d36 = *(int *)0x9d36 - (uint)*(byte *)(iVar2 + -0x6f45);
    uVar3 = 0xff;
    iVar2 = FUN_1000_722b(*(undefined2 *)(unaff_BP + -6));
    *(undefined1 *)(iVar2 + -0x6f45) = 0xff;
    *(int *)0x9d36 = *(int *)0x9d36 + (uVar3 & 0xff);
  }
  *(undefined1 *)0x90b2 = 0;
  *(undefined1 *)0x9d51 = 0;
  if (((*(char *)(unaff_BP + 8) != '\0') && (*(int *)(unaff_BP + 10) != 1)) && (iVar4 != -1)) {
    FUN_1000_4232(7,0x1a);
    FUN_1000_f7da(0x12,0x28);
    FUN_1000_f6a4(0x1c62,*(undefined2 *)0x9d56);
    FUN_1000_f7da(0x13,0x2b);
    FUN_1000_f6a4(0x1c6a,*(undefined2 *)0x9d54);
  }
LAB_1000_4710:
  if ((*(int *)(unaff_BP + 10) == 1) && (iVar4 != -1)) {
    FUN_1000_4232(7,0x1a);
  }
  return iVar4;
}



/* 0x14757 ev_739d7379547824108513649af69e86c099e05db550de91b7ef2fd348fd48bdc8 */

void __cdecl16near FUN_1000_4757(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_bdcb(*(undefined1 *)0x90b2);
  *(char *)(unaff_BP + -1) = cVar1;
  iVar2 = FUN_1000_722b((int)cVar1);
  FUN_1000_c98e(0xc,0xd,(int)*(char *)(unaff_BP + -1),1);
  FUN_1000_c98e(0xc,0xd,*(undefined1 *)0x90b2,1);
  FUN_1000_f7c2(1);
  FUN_1000_f7da(10,8);
  iVar3 = iVar2;
  if (3 < iVar2) {
    iVar3 = 7 - iVar2;
  }
  FUN_1000_f6a4(0x1a50,(uint)(3 < iVar2) * 6 + 0x1a8f,iVar3 * 7 + 0x1a9b,
                (int)*(char *)(unaff_BP + -1),*(undefined1 *)0x90b2);
  FUN_1000_f7c2(0);
  return;
}



/* 0x14802 ev_a796fc8693ab39d2342e6fbb6d80277b4a5d4435c21aa45e4521a76e964ee112 */

void __cdecl16near FUN_1000_4802(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(0,2,7);
  if (*(char *)0x906a == '\0') {
    FUN_1000_ae2b(*(byte *)(unaff_BP + 4) - 2,*(byte *)(unaff_BP + 6) - 2,
                  (uint)*(byte *)(unaff_BP + 8) * 3 + (uint)*(byte *)(unaff_BP + 4),
                  0x51 - (uint)*(byte *)(unaff_BP + 6),*(char *)(unaff_BP + 6) != '\x03',0xcd,0xb3,
                  0xd5,0xb8,0xd4,0xbe);
  }
  else {
    FUN_1000_ae2b(*(byte *)(unaff_BP + 4) - 2,*(byte *)(unaff_BP + 6) - 2,
                  (uint)*(byte *)(unaff_BP + 8) * 3 + (uint)*(byte *)(unaff_BP + 4),
                  0x51 - (uint)*(byte *)(unaff_BP + 6),1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  }
  return;
}



/* 0x148d7 ev_2e6ce45f85d6f6f1a04a1ba843fc0045822811c38b78c580a05c3670874d7bde */

void __cdecl16near FUN_1000_48d7(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  switch(*(undefined2 *)0x9d4c) {
  case 1:
    FUN_1000_e74e(*(undefined2 *)0x9d3a,0x1c70);
    iVar3 = FUN_1000_e677(0x9d3e,0x2e);
    FUN_1000_e76b(*(int *)0x9d3a + 5,0x9d3e,iVar3 + 0x62c2);
    *(undefined1 *)(*(int *)0x9d3a + iVar3 + 0x62c2 + 5) = 0;
    break;
  case 2:
    FUN_1000_e74e(*(undefined2 *)0x9d3a,0x131f);
    break;
  case 3:
    FUN_1000_e74e(*(undefined2 *)0x9d3a,0x1061);
    break;
  case 4:
    FUN_1000_e74e(*(undefined2 *)0x9d3a,0x1c76);
    break;
  case 5:
    FUN_1000_e74e(*(undefined2 *)0x9d3a,0x1333);
  }
  *(undefined2 *)0x9d4c = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x1b) = 0;
  *(undefined2 *)(iVar3 + 0x19) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x1f) = 0;
  *(undefined2 *)(iVar3 + 0x1d) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x17) = 0;
  *(undefined2 *)(iVar3 + 0x15) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x13) = 0;
  *(undefined2 *)(iVar3 + 0x11) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x43) = 0;
  *(undefined2 *)(iVar3 + 0x41) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x3f) = 0;
  *(undefined2 *)(iVar3 + 0x3d) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x3b) = 0;
  *(undefined2 *)(iVar3 + 0x39) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x37) = 0;
  *(undefined2 *)(iVar3 + 0x35) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x33) = 0;
  *(undefined2 *)(iVar3 + 0x31) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x2f) = 0;
  *(undefined2 *)(iVar3 + 0x2d) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x2b) = 0;
  *(undefined2 *)(iVar3 + 0x29) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x27) = 0;
  *(undefined2 *)(iVar3 + 0x25) = 0;
  iVar3 = *(int *)0x9d3a;
  *(undefined2 *)(iVar3 + 0x23) = 0;
  *(undefined2 *)(iVar3 + 0x21) = 0;
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    *(undefined1 *)(*(int *)0x9d3a + iVar3 + 0x45) = 0;
  }
  iVar3 = *(int *)0x9d3a;
  uVar1 = *(undefined2 *)0x99a4;
  *(undefined2 *)(iVar3 + 0xf) = *(undefined2 *)0x99a6;
  *(undefined2 *)(iVar3 + 0xd) = uVar1;
  for (iVar3 = 0; iVar3 < 0x4b; iVar3 = iVar3 + 1) {
    puVar2 = (undefined2 *)(iVar3 * 4 + *(int *)0x9d3c);
    puVar2[1] = 0;
    *puVar2 = 0;
    *(undefined2 *)(iVar3 * 2 + *(int *)0x9d3c + 0x1c2) = 0;
    *(undefined2 *)(iVar3 * 2 + *(int *)0x9d3c + 300) = 0;
  }
  return;
}



/* 0x14a70 ev_05209849878248a03378af42c758425c16e5fd3575b98c5764cb4b488dc8f90f */

/* WARNING: Removing unreachable block (ram,0x00014ace) */

undefined2 __cdecl16near
FUN_1000_4a70(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5,undefined2 param_6)

{
  undefined2 uVar1;
  char cVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x9d66 = 0xffff;
  *(undefined2 *)0x9d64 = 0xffff;
  *(undefined2 *)0x9d70 = param_3;
  *(undefined2 *)0x9d6c = param_1;
  *(undefined2 *)0x9d6e = param_2;
  FUN_1000_b1f3(0,2,7);
  FUN_1000_4e79(*(undefined2 *)0x9d6c,*(undefined2 *)0x9d6e,0x18);
  for (iVar5 = 0; iVar5 < 0x51; iVar5 = iVar5 + 1) {
    *(undefined1 *)(iVar5 + 0x900) = 0;
  }
  while( true ) {
    while( true ) {
      cVar4 = FUN_1000_4d07();
      FUN_1000_4b92();
      if ((cVar4 == '\x1b') && (*(char *)0x9d50 == '\0')) {
        FUN_1000_b1f3(0,1,7);
        return 0xffff;
      }
      if (cVar4 != '\b') break;
      FUN_1000_4d5f(param_3);
    }
    if (*(int *)0x9d4c != 0) {
      FUN_1000_48d7();
    }
    pcVar3 = (char *)*(undefined2 *)0x9d70;
    *(int *)0x9d70 = *(int *)0x9d70 + 1;
    cVar2 = *pcVar3;
    iVar5 = 0x20;
    if (' ' < cVar4) {
      iVar5 = (int)cVar4;
    }
    uVar1 = *(undefined2 *)0x9d6e;
    *(int *)0x9d6e = *(int *)0x9d6e + 1;
    FUN_1000_4e79(*(undefined2 *)0x9d6c,uVar1,iVar5);
    if (cVar2 == '\0') break;
    FUN_1000_4e79(*(undefined2 *)0x9d6c,*(undefined2 *)0x9d6e,0x18);
    FUN_1000_4dcd((int)cVar4,(int)cVar2,param_3);
  }
  FUN_1000_4e95((int)cVar4,param_3,param_4,param_5,param_6);
  return 0;
}



/* 0x14b92 ev_07f875d0d5ed312581cceb5b788ecabeb027ede9c27d0b5e1946fdda3a5711a4 */

void __cdecl16near FUN_1000_4b92(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined4 uVar5;
  long lVar6;
  
  if ((*(int *)0x9d66 < 1) && (*(int *)0x9d66 != 0)) {
    *(undefined2 *)0x9d6a = 0;
    *(undefined2 *)0x9d68 = 0;
    *(undefined2 *)0x9d5e = 0;
    *(undefined2 *)0x9d5c = 0;
    *(undefined2 *)0x9d62 = 0;
    *(undefined2 *)0x9d60 = 0;
    *(undefined2 *)0x9d66 = 0;
    *(undefined2 *)0x9d64 = 0;
    uVar5 = FUN_1000_4cb5();
    *(undefined2 *)0x9d5a = (int)((ulong)uVar5 >> 0x10);
    *(undefined2 *)0x9d58 = (int)uVar5;
  }
  else {
    uVar5 = FUN_1000_4cb5(*(undefined2 *)0x9d58,*(undefined2 *)0x9d5a);
    lVar6 = FUN_1000_4cd6(uVar5);
    *(undefined2 *)0x9d66 = (int)((ulong)lVar6 >> 0x10);
    *(undefined2 *)0x9d64 = (int)lVar6;
    lVar6 = lVar6 - CONCAT22(*(undefined2 *)0x9d62,*(undefined2 *)0x9d60);
    uVar1 = (undefined2)lVar6;
    uVar3 = (undefined2)((ulong)lVar6 >> 0x10);
    *(undefined2 *)0x9d5e = uVar3;
    *(undefined2 *)0x9d5c = uVar1;
    if ((-1 < *(int *)0x9d6a) && ((*(int *)0x9d6a != 0 || (*(int *)0x9d68 != 0)))) {
      uVar5 = FUN_1000_f04d();
      *(undefined2 *)0x9d5e = (int)((ulong)uVar5 >> 0x10);
      *(undefined2 *)0x9d5c = (int)uVar5;
    }
    if ((*(int *)0x9d5e < 0) || ((*(int *)0x9d5e == 0 && (*(uint *)0x9d5c < 0x1f5)))) {
      uVar4 = *(undefined2 *)0x9d5e;
      uVar2 = *(undefined2 *)0x9d5c;
    }
    else {
      uVar4 = 0;
      uVar2 = 500;
    }
    *(undefined2 *)0x9d5e = uVar4;
    *(undefined2 *)0x9d5c = uVar2;
    *(undefined2 *)0x9d6a = uVar3;
    *(undefined2 *)0x9d68 = uVar1;
    uVar1 = *(undefined2 *)0x9d64;
    *(undefined2 *)0x9d62 = *(undefined2 *)0x9d66;
    *(undefined2 *)0x9d60 = uVar1;
  }
  return;
}



/* 0x14cb5 ev_f1daf4dd1d06220079e483b91c6b0fdfead3a3630f1c1ebf92e96c7e73553664 */

void __cdecl16near FUN_1000_4cb5(void)

{
  FUN_1000_c1c4();
  FUN_1000_f04d();
  return;
}



/* 0x14cd6 ev_bf077c4b5236543943cf8787a895536bf36e9c95035f4d547881bde30b1cfb5f */

undefined4 __cdecl16near FUN_1000_4cd6(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  if ((param_2 <= param_4) && ((param_2 != param_4 || (param_1 < param_3)))) {
    bVar1 = 0x29ff < param_1;
    param_1 = param_1 + 0xd600;
    param_2 = param_2 + 0x83 + (uint)bVar1;
  }
  return CONCAT22((param_2 - param_4) - (uint)(param_1 < param_3),param_1 - param_3);
}



/* 0x14d07 ev_cdd12efe7a163efba463c69247cc11653db4783f39202be411a6f5c926cb4e57 */

int __cdecl16near FUN_1000_4d07(void)

{
  char cVar1;
  
  cVar1 = FUN_1000_f831();
  return (int)cVar1;
}



/* 0x14d14 ev_53b3ec035cbb30aa49f9c5c7bbc57d502d4192dc7c7158014579c4ea03b83175 */

/* WARNING: Removing unreachable block (ram,0x00014d3b) */

undefined2 __cdecl16near FUN_1000_4d14(undefined2 param_1,undefined2 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  
  uVar2 = FUN_1000_4cb5();
  do {
    uVar3 = FUN_1000_4cb5(uVar2);
    lVar4 = FUN_1000_4cd6(uVar3);
    if (CONCAT22(param_2,param_1) < lVar4) {
      return 0;
    }
    iVar1 = FUN_1000_f84a();
  } while ((iVar1 < 1) || (param_3 == '\0'));
  return 1;
}



/* 0x14d5f ev_7172839c349b438eb0d6db782d2e7cdbe2d06ebcf5eba63d3982de6600c6e544 */

void __cdecl16near FUN_1000_4d5f(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  if (*(int *)0x9d70 == param_1) {
    FUN_1000_7e47(5);
  }
  else {
    uVar1 = *(undefined2 *)0x9d6e;
    *(int *)0x9d6e = *(int *)0x9d6e + -1;
    FUN_1000_4e79(*(undefined2 *)0x9d6c,uVar1,0x20);
    FUN_1000_4e79(*(undefined2 *)0x9d6c,*(undefined2 *)0x9d6e,0x18);
    *(int *)0x9d70 = *(int *)0x9d70 + -1;
    iVar2 = *(int *)0x9d70;
    if (*(char *)((iVar2 - param_1) + 0x900) != '\0') {
      FUN_1000_4e79(*(int *)0x9d6c + -2,*(undefined2 *)0x9d6e,0x20);
      *(undefined1 *)((iVar2 - param_1) + 0x900) = 0;
    }
  }
  return;
}



/* 0x14dcd ev_0340147478a186543e443cb3be69f86b6b8a9d9bd83e37c9c182da741ae2628f */

void __cdecl16near FUN_1000_4dcd(char param_1,char param_2,int param_3)

{
  undefined2 unaff_DS;
  
  if (param_1 == param_2) {
    if (*(char *)0x9d51 == '\0') {
      FUN_1000_4f6c((int)param_2,1);
    }
  }
  else {
    *(undefined1 *)((*(int *)0x9d70 - param_3) + 0x8ff) = 1;
    FUN_1000_b1f3(0,2,4);
    FUN_1000_4e79(*(int *)0x9d6c + -2,*(int *)0x9d6e + -1,0x19);
    FUN_1000_b1f3(0,2,7);
    FUN_1000_7e47(5);
    if (*(char *)0x9d4f == '\0') {
      FUN_1000_07c9(0x40,0);
    }
    else {
      FUN_1000_07c9(0x20,1);
    }
    if (*(char *)0x9d51 == '\0') {
      FUN_1000_4f6c((int)param_2,0);
    }
  }
  return;
}



/* 0x14e79 ev_02b46bd08eea44bab8937a20ab78eebebf6b36270592a40313b63e8045ec0bac */

void __cdecl16near FUN_1000_4e79(undefined2 param_1,undefined2 param_2,char param_3)

{
  FUN_1000_f7da(param_1,param_2);
  FUN_1000_f873((int)param_3);
  return;
}



/* 0x14e95 ev_2f10fd34ce10b4a80aa70ed7d6f46e9593e6a1f6d383a8cfed8397eb21e50219 */

void __cdecl16near
FUN_1000_4e95(char param_1,undefined2 param_2,int *param_3,int *param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 unaff_DS;
  
  iVar5 = FUN_1000_f139(param_2);
  if (((param_1 != '\r') && (param_1 != ' ')) && (param_1 != '+')) {
    *(undefined1 *)(iVar5 + 0x900) = 1;
    FUN_1000_b1f3(0,2,4);
    FUN_1000_4e79(*(int *)0x9d6c + -2,*(int *)0x9d6e + -1,0x19);
    FUN_1000_b1f3(0,2,7);
  }
  for (iVar7 = 0; iVar7 < iVar5 + 1; iVar7 = iVar7 + 1) {
    if (*(char *)(iVar7 + 0x900) == '\0') {
      *param_3 = *param_3 + 1;
    }
    else {
      *param_4 = *param_4 + 1;
    }
  }
  iVar5 = *(int *)0x9d66;
  uVar3 = *(uint *)0x9d64;
  uVar4 = *(uint *)0x9d5c;
  uVar6 = uVar3 - *(uint *)0x9d5c;
  iVar7 = *(int *)0x9d5e;
  puVar1 = param_5;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar6;
  param_5[1] = param_5[1] + ((iVar5 - iVar7) - (uint)(uVar3 < uVar4)) + (uint)CARRY2(uVar2,uVar6);
  return;
}



/* 0x14f2b ev_d1309eb658fe9ef2388aaaacdf0ecef658d792759c2ca7fdd44935381fea8d16 */

void __cdecl16near FUN_1000_4f2b(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  if (*(int *)0x9d2c < 8) {
    iVar4 = *(int *)0x9d5e;
    uVar3 = *(uint *)0x9d5c;
    puVar1 = param_1;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    param_1[1] = param_1[1] + iVar4 + (uint)CARRY2(uVar2,uVar3);
    puVar1 = param_2;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + 1;
    param_2[1] = param_2[1] + (uint)(0xfffe < uVar2);
  }
  iVar4 = *(int *)0x9d5e;
  uVar3 = *(uint *)0x9d5c;
  puVar1 = param_3;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar3;
  param_3[1] = param_3[1] + iVar4 + (uint)CARRY2(uVar2,uVar3);
  puVar1 = param_4;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + 1;
  param_4[1] = param_4[1] + (uint)(0xfffe < uVar2);
  return;
}



/* 0x14f6c ev_932dd8714fd05f65b08138f4ec8f3cca013d9fc54ec576e7f22264ed654bec7d */

void __cdecl16near FUN_1000_4f6c(char param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  bool bVar4;
  int local_c [3];
  int local_6;
  uint local_4;
  
  local_c[1] = 0;
  local_c[0] = 0;
  bVar4 = false;
  if (*(int *)0x9d5e == 0) {
    bVar4 = *(int *)0x9d5c == 0;
  }
  if (!bVar4) {
    if (param_1 != ' ') {
      if (*(char *)0x9d4f == '\0') {
        local_6 = FUN_1000_722b((int)param_1);
      }
      else {
        local_6 = FUN_1000_e08c((int)param_1);
      }
      if (param_2 == 0) {
        iVar2 = local_6 * 4 + -0x6400;
      }
      else {
        iVar2 = local_6 * 4 + -0x652c;
      }
      FUN_1000_4f2b(local_6 * 4 + *(int *)0x9d3c,local_c,local_6 * 4 + -0x6658,iVar2);
      if (*(int *)0x9d2c < 8) {
        if (param_2 == 0) {
          piVar1 = (int *)(local_6 * 2 + *(int *)0x9d3c + 0x1c2);
          *piVar1 = *piVar1 + local_c[0];
        }
        else {
          piVar1 = (int *)(local_6 * 2 + *(int *)0x9d3c + 300);
          *piVar1 = *piVar1 + local_c[0];
        }
      }
      if (param_2 == 0) {
        local_4 = (uint)(*(byte *)(local_6 + -0x6f45) >> 5) + (uint)*(byte *)(local_6 + -0x6f45) + 1
        ;
      }
      else {
        iVar2 = local_6 * 4;
        iVar2 = FUN_1000_52dc(*(undefined2 *)(iVar2 + -0x652c),*(undefined2 *)(iVar2 + -0x652a),
                              *(undefined2 *)(iVar2 + -0x6400),*(undefined2 *)(iVar2 + -0x63fe),
                              *(undefined2 *)(iVar2 + -0x6658),*(undefined2 *)(iVar2 + -0x6656));
        if (iVar2 == 0) {
          iVar2 = 1;
        }
        local_4 = (int)(0x7f8 / (long)iVar2) * 3 + (uint)*(byte *)(local_6 + -0x6f45) >> 2;
      }
    }
    if (((*(byte *)(param_1 + -0x7183) & 3) == 0) &&
       ((iVar2 = FUN_1000_e677(0x1c83,(int)param_1), iVar2 == 0 || (*(char *)0x9d4f != '\0')))) {
      if (((*(byte *)(param_1 + -0x7183) & 4) == 0) || (*(char *)0x9d4f != '\0')) {
        if (*(char *)0x9d4f == '\0') {
          uVar3 = 0x9743;
          if (param_2 == 0) {
            iVar2 = *(int *)0x9d3a + 0x41;
          }
          else {
            uVar3 = 0x973f;
            iVar2 = *(int *)0x9d3a + 0x3d;
          }
          FUN_1000_4f2b(*(int *)0x9d3a + 0x39,iVar2,0x973b,uVar3);
        }
      }
      else {
        uVar3 = 0x9737;
        if (param_2 == 0) {
          iVar2 = *(int *)0x9d3a + 0x35;
        }
        else {
          uVar3 = 0x9733;
          iVar2 = *(int *)0x9d3a + 0x31;
        }
        FUN_1000_4f2b(*(int *)0x9d3a + 0x2d,iVar2,0x972f,uVar3);
      }
    }
    else {
      uVar3 = 0x972b;
      if (param_2 == 0) {
        iVar2 = *(int *)0x9d3a + 0x29;
      }
      else {
        uVar3 = 0x9727;
        iVar2 = *(int *)0x9d3a + 0x25;
      }
      FUN_1000_4f2b(*(int *)0x9d3a + 0x21,iVar2,0x9723,uVar3);
    }
    if (param_1 != ' ') {
      if (0xff < local_4) {
        local_4 = 0xff;
      }
      if ((*(byte *)(param_1 + -0x7183) & 3) != 0) {
        *(int *)0x9d36 = *(int *)0x9d36 + (local_4 - *(byte *)(local_6 + -0x6f45));
      }
      *(undefined1 *)(local_6 + -0x6f45) = (char)local_4;
    }
  }
  return;
}



/* 0x151c5 ev_8405b34b17c687a89714d52763ac039d6dc447a74f5bb446c2d07e0bc28b73ab */

void __cdecl16near FUN_1000_51c5(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 local_25a [150];
  undefined2 local_12e [150];
  
  iVar6 = 2;
  if (*(int *)0x9d2c == 4) {
    iVar6 = 6;
  }
  for (; *(int *)0x9d2c <= iVar6; iVar6 = iVar6 + -1) {
    puVar4 = (undefined2 *)((iVar6 + 1) * 0x4f + -0x6b76);
    puVar7 = (undefined2 *)(iVar6 * 0x4f + -0x6b76);
    for (iVar5 = 0x27; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar2 = puVar4;
      puVar4 = puVar4 + 1;
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar2 = *puVar1;
    }
    *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
  }
  puVar4 = (undefined2 *)(*(int *)0x9d2c * 0x4f + -0x6b76);
  puVar7 = (undefined2 *)*(undefined2 *)0x9d3a;
  for (iVar6 = 0x27; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar7;
    puVar7 = puVar7 + 1;
    *puVar2 = *puVar1;
  }
  *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
  for (iVar6 = 0; iVar6 < 0x4b; iVar6 = iVar6 + 1) {
    uVar3 = *(undefined2 *)(iVar6 * 2 + *(int *)0x9d3c + 300);
    local_12e[iVar6 * 2 + 1] = 0;
    local_12e[iVar6 * 2] = uVar3;
    uVar3 = *(undefined2 *)(iVar6 * 2 + *(int *)0x9d3c + 0x1c2);
    local_25a[iVar6 * 2 + 1] = 0;
    local_25a[iVar6 * 2] = uVar3;
  }
  FUN_1000_8f6e(local_12e,local_25a,*(undefined2 *)0x9d3c);
  return;
}



/* 0x1529a ev_b5ef276a5592952c2b672a132729ceef384f60c3a1ae2c710cb787e14ae3498e */

undefined2 __cdecl16near FUN_1000_529a(void)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = *(uint *)(unaff_BP + 4) + *(uint *)(unaff_BP + 8);
  iVar3 = *(int *)(unaff_BP + 6) + *(int *)(unaff_BP + 10) +
          (uint)CARRY2(*(uint *)(unaff_BP + 4),*(uint *)(unaff_BP + 8));
  *(int *)(unaff_BP + -2) = iVar3;
  *(int *)(unaff_BP + -4) = iVar1;
  if (iVar3 == 0 && iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_1000_f0a7();
  }
  return uVar2;
}



/* 0x152dc ev_55a99fa34c48f1cd8082759b2a361ba7ddd7a3708b5da28d89eb073ba33bfdfd */

undefined2 __cdecl16near FUN_1000_52dc(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  bool bVar2;
  
  FUN_1000_e7bd();
  bVar2 = false;
  if (*(int *)(unaff_BP + 0xe) == 0) {
    bVar2 = *(int *)(unaff_BP + 0xc) == 0;
  }
  if (bVar2) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_1000_f0a7();
  }
  return uVar1;
}



/* 0x1531a ev_2f3d1f7ca741033283b129ff9d3a18866b22154c3c884b35b433b58db8566304 */

undefined2 __cdecl16near FUN_1000_531a(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = *(int *)(unaff_BP + 4) * 4;
  if (*(int *)(iVar4 + -0x652a) + *(int *)(iVar4 + -0x63fe) +
      (uint)CARRY2(*(uint *)(iVar4 + -0x652c),*(uint *)(iVar4 + -0x6400)) == 0 &&
      *(uint *)(iVar4 + -0x652c) + *(uint *)(iVar4 + -0x6400) == 0) {
    return 0;
  }
  if (*(int *)(unaff_BP + 4) < 0x1d) {
    bVar1 = *(byte *)0x90b3;
  }
  else {
    bVar1 = *(byte *)0x90b4;
  }
  uVar3 = (uint)bVar1;
  uVar2 = FUN_1000_52dc(*(undefined2 *)(iVar4 + -0x652c),*(undefined2 *)(iVar4 + -0x652a),
                        *(undefined2 *)(iVar4 + -0x6400),*(undefined2 *)(iVar4 + -0x63fe),
                        *(undefined2 *)(iVar4 + -0x6658),*(undefined2 *)(iVar4 + -0x6656));
  if (uVar3 <= uVar2) {
    iVar4 = *(int *)(unaff_BP + 4) * 4;
    uVar3 = FUN_1000_529a(*(undefined2 *)(iVar4 + -0x652c),*(undefined2 *)(iVar4 + -0x652a),
                          *(undefined2 *)(iVar4 + -0x6400),*(undefined2 *)(iVar4 + -0x63fe));
    if (*(byte *)0x1c90 <= uVar3) {
      return 0;
    }
  }
  return 1;
}



/* 0x153a7 ev_3ef0d861f507eba77a5fa76ef051f3ecb45c32955cbd659564f928337f376ed7 */

undefined2 __cdecl16near FUN_1000_53a7(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(int *)(unaff_BP + 4) < 0x1d) {
    bVar2 = *(byte *)0x90b3;
  }
  else {
    bVar2 = *(byte *)0x90b4;
  }
  uVar4 = (uint)bVar2;
  iVar5 = *(int *)(unaff_BP + 4) * 4;
  uVar3 = FUN_1000_52dc(*(undefined2 *)(iVar5 + -0x6dce),*(undefined2 *)(iVar5 + -0x6dcc),
                        *(undefined2 *)(iVar5 + -0x6ca2),*(undefined2 *)(iVar5 + -0x6ca0),
                        *(undefined2 *)(iVar5 + -0x6efa),*(undefined2 *)(iVar5 + -0x6ef8));
  if (uVar4 <= uVar3) {
    iVar5 = *(int *)(unaff_BP + 4) * 4;
    uVar4 = FUN_1000_529a(*(undefined2 *)(iVar5 + -0x6dce),*(undefined2 *)(iVar5 + -0x6dcc),
                          *(undefined2 *)(iVar5 + -0x6ca2),*(undefined2 *)(iVar5 + -0x6ca0));
    if (*(byte *)0x1c90 <= uVar4) {
      iVar5 = *(int *)(unaff_BP + 4) * 4;
      uVar4 = *(uint *)(iVar5 + -0x6dce);
      iVar6 = *(int *)(unaff_BP + 4) * 4;
      puVar1 = (uint *)(iVar6 + -0x652c);
      if ((*(int *)(iVar5 + -0x6dcc) + *(int *)(iVar6 + -0x652a) + (uint)CARRY2(uVar4,*puVar1) != 0)
         || ((uint)*(byte *)0x1c91 <= uVar4 + *puVar1)) {
        return 0;
      }
    }
  }
  return 1;
}



/* 0x1544e ev_38311902649e778daa22d9cd7a2898178039706e112a5d1dc22d0abd4fb7aef6 */

undefined2 __cdecl16near FUN_1000_544e(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if ((((*(char *)0x9d4c != '\x03') &&
       ((*(uint *)(unaff_BP + 4) <= (uint)*(byte *)0x90af || (0x3f < *(int *)(unaff_BP + 4))))) &&
      (((uint)*(byte *)0x90af != *(uint *)(unaff_BP + 4) || (*(char *)0x90b2 == '\0')))) &&
     (iVar1 = FUN_1000_531a(*(undefined2 *)(unaff_BP + 4)), iVar1 == 0)) {
    iVar1 = FUN_1000_53a7(*(undefined2 *)(unaff_BP + 4));
    if (iVar1 != 0) {
      iVar1 = *(int *)(unaff_BP + 4) * 4;
      if ((*(int *)(iVar1 + -0x652a) == 0) && (*(uint *)(iVar1 + -0x652c) <= (uint)*(byte *)0x1c91))
      {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}



/* 0x154c1 ev_9bfb03a85045b7a4e6d20a38226702a687c9053c4ac39dff6bd0a137853964f0 */

void __cdecl16near FUN_1000_54c1(void)

{
  int iVar1;
  int unaff_BP;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = 0;
  if ((*(int *)(unaff_BP + 4) != 0) && (*(byte *)0x90af < 0x1d)) {
    return;
  }
  uVar2 = 0;
  if (*(int *)(unaff_BP + 4) != 0) {
    uVar2 = 0x1d;
  }
  for (; uVar2 <= *(byte *)0x90af; uVar2 = uVar2 + 1) {
    iVar1 = uVar2 * 4;
    iVar1 = FUN_1000_52dc(*(uint *)(iVar1 + -0x6dce) + *(uint *)(iVar1 + -0x652c),
                          *(int *)(iVar1 + -0x6dcc) + *(int *)(iVar1 + -0x652a) +
                          (uint)CARRY2(*(uint *)(iVar1 + -0x6dce),*(uint *)(iVar1 + -0x652c)),
                          *(uint *)(iVar1 + -0x6ca2) + *(uint *)(iVar1 + -0x6400),
                          *(int *)(iVar1 + -0x6ca0) + *(int *)(iVar1 + -0x63fe) +
                          (uint)CARRY2(*(uint *)(iVar1 + -0x6ca2),*(uint *)(iVar1 + -0x6400)),
                          *(uint *)(iVar1 + -0x6efa) + *(uint *)(iVar1 + -0x6658),
                          *(int *)(iVar1 + -0x6ef8) + *(int *)(iVar1 + -0x6656) +
                          (uint)CARRY2(*(uint *)(iVar1 + -0x6efa),*(uint *)(iVar1 + -0x6658)));
    iVar4 = iVar4 + iVar1;
  }
  if (*(int *)(unaff_BP + 4) != 0) {
    uVar2 = uVar2 - 0x1d;
  }
  iVar1 = 4;
  if (0x1c < *(byte *)0x90af) {
    iVar1 = 5;
  }
  uVar2 = (iVar4 / (int)uVar2 << 1) / iVar1;
  if (*(byte *)0x90b8 < uVar2) {
    uVar2 = (uint)*(byte *)0x90b8;
  }
  else {
    uVar3 = 10;
    if (*(int *)(unaff_BP + 4) != 0) {
      uVar3 = 5;
    }
    if ((int)uVar2 < (int)uVar3) {
      uVar2 = uVar3;
    }
  }
  *(undefined1 *)(*(int *)(unaff_BP + 4) + -0x6f4d) = (char)uVar2;
  return;
}



/* 0x15584 ev_91e10e5646bb5a847f96c8bfd06103d3a5351b8498cfbb6a284d76e936c04ce1 */

uint __cdecl16near FUN_1000_5584(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  uint uVar3;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x90b2 != '\0') {
    return (uint)*(byte *)0x90b2;
  }
  if (*(char *)0x90b9 == '\0') {
    if (*(byte *)0x90af < 0x3f) {
      iVar4 = 0;
      for (uVar3 = 0; uVar3 <= *(byte *)0x90af; uVar3 = uVar3 + 1) {
        iVar1 = FUN_1000_544e(uVar3);
        if (iVar1 == 0) {
          iVar4 = iVar4 + 1;
        }
      }
      if (iVar4 < 4) {
        *(char *)0x90af = *(char *)0x90af + '\x01';
        *(int *)(unaff_BP + -4) = (int)*(char *)(*(byte *)0x90af + 0x7a53);
        if (*(byte *)0x90af < 8) {
          FUN_1000_b1f3(0,1,7);
          *(undefined1 *)0x9d4e = 1;
          *(undefined1 *)0x9d50 = 1;
          FUN_1000_2723(0x1eef);
          FUN_1000_2612(0x183,0);
          FUN_1000_c78e(3,0xd);
          FUN_1000_c98e(3,0xd,*(undefined2 *)(unaff_BP + -4),1);
          FUN_1000_ae2b(0xf,0xd,0x15,0x43,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
          FUN_1000_f7da(0x10,0xf);
          uVar2 = FUN_1000_e793(*(undefined2 *)(unaff_BP + -4));
          FUN_1000_f6a4(0x1ef0,uVar2);
          FUN_1000_f7da(0x11,0xf);
          FUN_1000_f6a4(0x1f21,(7 - (uint)*(byte *)0x90af) * 7 + 0x1a9b,0x1a95);
          FUN_1000_f7da(0x12,0xf);
          uVar2 = FUN_1000_e793(*(undefined2 *)(unaff_BP + -4));
          FUN_1000_f6a4(0x1f4c,uVar2);
          FUN_1000_f7da(0x13,0xf);
          FUN_1000_f6a4(0x1f7d);
          FUN_1000_f7da(0x14,0xf);
          FUN_1000_f6a4(0x1fb2);
          FUN_1000_f831();
          FUN_1000_4232(7,0x1a);
          if (*(char *)0x9d52 != '\0') {
            FUN_1000_f7da(0x12,0x28);
            FUN_1000_f6a4(0x1fc9,*(undefined2 *)0x9d56);
            FUN_1000_f7da(0x13,0x2b);
            FUN_1000_f6a4(0x1fd1,*(undefined2 *)0x9d54);
          }
        }
        if (*(char *)0x90af == '\a') {
          *(undefined1 *)0x90b9 = 1;
        }
        else {
          if (*(char *)0x90af == '\b') {
            *(undefined1 *)0x9d4e = 1;
          }
          if ((*(byte *)(*(int *)(unaff_BP + -4) + -0x7183) & 3) != 0) {
            *(char *)0x90ae = *(char *)0x90ae + '\x01';
            iVar4 = FUN_1000_722b((int)*(char *)(*(byte *)0x90ae + 0x7af1));
            *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar4 + -0x6f45);
          }
        }
        return *(uint *)(unaff_BP + -4) & 0xff;
      }
    }
  }
  else {
    FUN_1000_5a80();
    FUN_1000_4232(7,0x1a);
    *(undefined1 *)0x90b9 = 0;
    *(undefined1 *)0x9d4e = 1;
    *(undefined1 *)0x90ba = 1;
    *(undefined1 *)0x9d50 = 1;
  }
  return 0;
}



/* 0x157cc ev_5dc4c189a7266f7988afca4cdd6d2bd1c96454af2cf3aed188db7eb6b83c58f2 */

int __cdecl16near FUN_1000_57cc(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_BP;
  uint uVar4;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar5 = 0;
  for (uVar4 = *(uint *)(unaff_BP + 4);
      ((int)uVar4 < *(int *)(unaff_BP + 6) && (uVar4 <= *(byte *)0x90af)); uVar4 = uVar4 + 1) {
    iVar1 = FUN_1000_544e(uVar4);
    if ((iVar1 == 0) && ((0x15 < *(int *)(unaff_BP + 4) || (0x1c < (int)uVar4)))) {
      uVar2 = (uint)*(byte *)(uVar4 + 0x90bb) * 7;
    }
    else {
      uVar2 = (uint)*(byte *)(uVar4 + 0x90bb);
    }
    iVar5 = iVar5 + uVar2;
  }
  iVar1 = FUN_1000_bd74(iVar5);
  iVar5 = *(int *)(unaff_BP + 4);
  for (; -1 < iVar1; iVar1 = iVar1 - uVar4) {
    iVar3 = FUN_1000_544e(iVar5);
    if ((iVar3 == 0) && ((0x15 < *(int *)(unaff_BP + 4) || (0x1c < iVar5)))) {
      uVar4 = (uint)*(byte *)(iVar5 + -0x6f45) * 7;
    }
    else {
      uVar4 = (uint)*(byte *)(iVar5 + -0x6f45);
    }
    iVar5 = iVar5 + 1;
  }
  return iVar5 + -1;
}



/* 0x15854 ev_1e0affa47a9209793f57145fb1bdcc7514672f69b198ed1eea51939aa7babf6f */

int __cdecl16near FUN_1000_5854(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  int unaff_BP;
  uint uVar5;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar5 = 0;
  if (0x1c < *(byte *)0x90af) {
    uVar5 = 0x15;
  }
  *(uint *)(unaff_BP + -2) = uVar5;
  *(undefined2 *)(unaff_BP + -6) = 0;
  for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {
    *(undefined2 *)(iVar6 * 2 + unaff_BP + -0xc) = 0;
    for (; ((int)uVar5 < *(int *)(iVar6 * 2 + 0x1ed2) && (uVar5 <= *(byte *)0x90af));
        uVar5 = uVar5 + 1) {
      iVar2 = FUN_1000_544e(uVar5);
      if ((iVar2 == 0) && (0x1c < (int)uVar5)) {
        uVar3 = (uint)*(byte *)(uVar5 + 0x90bb) << 1;
      }
      else {
        uVar3 = (uint)*(byte *)(uVar5 + 0x90bb);
      }
      piVar1 = (int *)(iVar6 * 2 + unaff_BP + -0xc);
      *piVar1 = *piVar1 + uVar3;
    }
    *(int *)(unaff_BP + -6) = *(int *)(unaff_BP + -6) + *(int *)(iVar6 * 2 + unaff_BP + -0xc);
  }
  iVar6 = FUN_1000_bd74(*(undefined2 *)(unaff_BP + -6));
  iVar6 = iVar6 - *(int *)(unaff_BP + -0xc);
  *(int *)(unaff_BP + -4) = iVar6;
  if (iVar6 < 1) {
    uVar4 = FUN_1000_57cc(*(undefined2 *)(unaff_BP + -2),0x25);
    switch(uVar4) {
    case 0xf:
      iVar6 = FUN_1000_bd74(4);
      return iVar6 + 0xc;
    case 0x1d:
    case 0x1f:
      iVar6 = FUN_1000_bd74(3);
      return iVar6 + 0x28;
    case 0x1e:
      iVar6 = FUN_1000_bd74(2);
      return iVar6 + 0x30;
    case 0x20:
      iVar6 = FUN_1000_bd74(7);
      return iVar6 + 0x1a;
    case 0x21:
      iVar6 = FUN_1000_bd74(2);
      return iVar6 + 0x2e;
    case 0x22:
    case 0x23:
      return 0x15;
    case 0x24:
      iVar6 = FUN_1000_bd74(2);
      return iVar6 + 0xe;
    }
    if (*(byte *)0x90af < 9) {
      iVar6 = FUN_1000_bd74(*(undefined1 *)(*(byte *)0x90ae + 0x1ed8));
      return iVar6 + 5;
    }
    iVar6 = FUN_1000_bd74(*(byte *)(*(byte *)0x90ae + 0x1ed8) - 2);
    return iVar6 + 7;
  }
  if (*(int *)(unaff_BP + -4) - *(int *)(unaff_BP + -10) < 1) {
    iVar6 = FUN_1000_bd74(7);
    return iVar6 + 0x21;
  }
  iVar6 = FUN_1000_57cc(0x2f,0x40);
  switch(iVar6 + -0x2f) {
  case 0:
  case 2:
  case 3:
  case 5:
  case 7:
    return 0x16;
  case 1:
    iVar6 = FUN_1000_bd74(2);
    return iVar6 + 0x2c;
  case 4:
    iVar6 = FUN_1000_bd74(2);
    return iVar6 + 0x30;
  case 6:
    return 0x2b;
  case 8:
  case 9:
    iVar6 = FUN_1000_bd74(2);
    return iVar6 + 0x15;
  case 10:
    iVar6 = FUN_1000_bd74(3);
    return iVar6 + 0x16;
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
    return 0x15;
  case 0xf:
  case 0x10:
    return 0x32;
  default:
    return iVar6 + -0x2f;
  }
}



/* 0x15a53 ev_39c202bba7c7f4d82d60ab5f2b8907767bac1c916a5e3163d8761b6993f58887 */

void __cdecl16near FUN_1000_5a53(void)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_5854();
  *(int *)0x9d72 = *(int *)(iVar1 * 2 + -0x79ce) + -0x7968;
  *(undefined2 *)0x2086 = 0x9d74;
  *(undefined1 *)0x9d88 = 0;
  *(undefined1 *)0x9d89 = 0;
  *(undefined1 *)0x9d8a = 0;
  return;
}



/* 0x15a80 ev_9b3e80d0f82e02a44e85ebeff8e1681006623dda1f00fa8f1da2020385abe73a */

void __cdecl16near FUN_1000_5a80(void)

{
  int iVar1;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(0,1,7);
  FUN_1000_2723(0x1fd7);
  FUN_1000_2612(0x183,0);
  FUN_1000_ae2b(6,3,0x13,0x4c,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  iVar1 = FUN_1000_af51(0x1c92,0xffff,6,3,0x14,0x4c,0,0);
  iVar1 = FUN_1000_af51(0x1d5c,0xffff,iVar1 + 1,3,0x14,0x4c,0,0);
  FUN_1000_af51(0x1e04,0xffff,iVar1 + 1,3,0x14,0x4c,0,0);
  FUN_1000_f831();
  return;
}



/* 0x15b4d ev_7ceadbc03ce52e1b9cef71ced6400880c81857c53d1c12de0b1208d82e773c8f */

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



/* 0x15bca ev_8ea99500464372656d279491fda3884b1bc28e8bba84bb5a1c0fd2765b1fa344 */

void __cdecl16near FUN_1000_5bca(void)

{
  undefined1 uVar1;
  int unaff_BP;
  char cVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar2 = '\x02';
  for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {
    *(char *)(unaff_BP + iVar3 + -6) = *(char *)(iVar3 + -0x67c2) - cVar2;
    uVar1 = FUN_1000_e793((int)*(char *)(*(int *)(unaff_BP + 4) + iVar3));
    *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar3) = uVar1;
    cVar2 = cVar2 * '\x02';
  }
  *(undefined1 *)(unaff_BP + -1) = 0;
  iVar3 = FUN_1000_f105(*(undefined2 *)(unaff_BP + 4),unaff_BP + -6);
  if (iVar3 == 0) {
    iVar3 = FUN_1000_f84a();
    if (iVar3 < 1) {
      FUN_1000_095c(1);
    }
    FUN_1000_bd1f();
    FUN_1000_32ed(6,0xffff);
  }
  else {
    FUN_1000_00b3(2);
  }
  FUN_1000_0335();
  return;
}



/* 0x15c49 ev_d960fb6e84726f8a3b687d1c18c7de9f3233162c1a862725357363abde9a73e2 */

void __cdecl16near FUN_1000_5c49(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_b5b2(0xffe,1,0,unaff_BP + -0x1c);
  if (iVar1 == -1) {
    return;
  }
  if (*(int *)(unaff_BP + -0x1c) == 0) {
    FUN_1000_b194(0x12fb,0x23,4);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return;
  }
  FUN_1000_e74e(unaff_BP + -0x1a,*(undefined2 *)(unaff_BP + -0x1c));
  FUN_1000_b194(0x2015,0x23,4);
  FUN_1000_8247(unaff_BP + -0x1a);
  return;
}



/* 0x15cbb ev_47059c26d2c5e62f684758c8503355cafca7056fb3cbe3a98568afe29753a234 */

undefined2 __cdecl16near FUN_1000_5cbb(void)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  int unaff_BP;
  char cVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)0x9d4e = 1;
  iVar2 = FUN_1000_5ec5();
  *(int *)(unaff_BP + -2) = iVar2;
  if (iVar2 == -1) {
    *(undefined2 *)0x9d4e = 0;
    return 0xffff;
  }
  *(undefined2 *)0x9d4e = 0;
  FUN_1000_2723(0x101e);
  FUN_1000_0128();
  if (*(int *)(unaff_BP + -2) == 0) {
    iVar2 = 0x462c;
  }
  else {
    iVar2 = (*(int *)(unaff_BP + -2) + -1) * 0x7cc + 0x36;
  }
  *(undefined2 *)(unaff_BP + -4) = 0;
  *(int *)(unaff_BP + -6) = iVar2;
  FUN_1000_e247(*(undefined2 *)0x9070,iVar2,0,0);
  FUN_1000_e1f4(unaff_BP + -0x11,1,5,*(undefined2 *)0x9070);
  if (*(char *)(unaff_BP + -0x11) == '\0') {
    *(undefined1 *)(unaff_BP + -0x17) = 0;
  }
  else {
    cVar4 = '\x02';
    for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
      *(char *)(unaff_BP + iVar2 + -0x17) = *(char *)(unaff_BP + iVar2 + -0x11) - cVar4;
      cVar4 = cVar4 * '\x02';
    }
    *(undefined1 *)(unaff_BP + -0x12) = 0;
  }
  FUN_1000_e74e(0x1feb,unaff_BP + -0x17);
  FUN_1000_b12a(0x1fd8,4,0x1a,6,0x35);
  iVar2 = FUN_1000_b751(0x2028,unaff_BP + -0xc,6,0);
  if (iVar2 == 0) {
    FUN_1000_2612(0x183,0);
    cVar4 = '\x02';
    for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
      cVar1 = FUN_1000_e793((int)*(char *)(unaff_BP + iVar2 + -0xc));
      *(char *)(unaff_BP + iVar2 + -0x11) = cVar1 + cVar4;
      cVar4 = cVar4 * '\x02';
    }
    FUN_1000_e247(*(undefined2 *)0x9070,*(undefined2 *)(unaff_BP + -6),
                  *(undefined2 *)(unaff_BP + -4),0);
    FUN_1000_e852(unaff_BP + -0x11,1,5,*(undefined2 *)0x9070);
    FUN_1000_f831();
  }
  uVar3 = FUN_1000_e913(*(undefined2 *)0x9070);
  return uVar3;
}



/* 0x15e0d ev_45d0a092db978d20fb7e190bd3ef9eca089a3a64df621ab9b993bbdd27f73591 */

void __cdecl16near FUN_1000_5e0d(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b12a(0x9072,8,0x1a,0xb,0x36);
  FUN_1000_f7da(10,0x1c);
  FUN_1000_f6a4(0x2046);
  FUN_1000_0128();
  while (*(int *)(unaff_BP + 4) < 8) {
    FUN_1000_e247(*(undefined2 *)0x9070,(long)(*(int *)(unaff_BP + 4) + 1) * 0x7cc,0);
    FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    FUN_1000_e247(*(undefined2 *)0x9070,(long)*(int *)(unaff_BP + 4) * 0x7cc,0);
    FUN_1000_e852(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_e74e(0x9072,0x1314);
  return;
}



/* 0x15ec5 ev_10aff5f97979e7ef1ee8c102d57d43aeb719f075f8973366d1662dfbee378c68 */

int __cdecl16near FUN_1000_5ec5(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_0128();
  iVar1 = FUN_1000_0f47();
  if ((iVar1 == 0) && (*(int *)0x9d4e == 0)) {
    FUN_1000_b194(0x205a,0x27,4);
    FUN_1000_e913(*(undefined2 *)0x9070);
    FUN_1000_2612(0x183,0);
    FUN_1000_f831();
    return -1;
  }
  if (*(int *)0x9d4e == 0) {
    *(undefined2 *)(unaff_BP + -2) = 1;
  }
  else {
    FUN_1000_e74e(*(undefined2 *)0x6d5,0x1314);
    *(undefined2 *)(unaff_BP + -2) = 0;
    iVar1 = iVar1 + 1;
  }
  iVar1 = FUN_1000_b21d(iVar1,0x1a,*(int *)(unaff_BP + -2) * 2 + 0x6d5,0,0,0x962);
  if (iVar1 == -1) {
    FUN_1000_e913(*(undefined2 *)0x9070);
    return -1;
  }
  if (*(int *)0x9d4e == 0) {
    FUN_1000_e247(*(undefined2 *)0x9070,iVar1 * 0x7cc,0,0);
    FUN_1000_e1f4(0x9072,1,0x7cc,*(undefined2 *)0x9070);
    FUN_1000_e74e(*(undefined2 *)0x6d5,0x9072);
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  return iVar1;
}



/* 0x15fad ev_b0c7cb144fa64bd18464cf695f16bbb6769e499a88aaa08f3a0680d7485c14a7 */

uint __cdecl16near FUN_1000_5fad(void)

{
  int iVar1;
  byte bVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d50 == '\x02') {
    *(undefined1 *)0x9d50 = 1;
    return 0x20;
  }
  iVar1 = *(int *)0x9d8e;
  *(int *)0x9d8e = *(int *)0x9d8e + 1;
  *(int *)(unaff_BP + -2) = iVar1 % 7 + 1;
  iVar1 = FUN_1000_e3ce(*(undefined2 *)0x9070);
  bVar2 = (byte)*(undefined2 *)(unaff_BP + -2);
  return (iVar1 << (8 - bVar2 & 0x1f) | iVar1 >> (bVar2 & 0x1f)) & 0xff;
}



/* 0x15ff7 ev_5d1befa20f20aef81a3316f32009f21f015a9c772dc56e5fd67d61840562972f */

uint __cdecl16near FUN_1000_5ff7(void)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 0;
  if (*(char *)0x9d4e != '\0') {
    *(undefined2 *)0x9d8e = 0;
    cVar1 = FUN_1000_e3ce(*(undefined2 *)0x9070);
    *(char *)(unaff_BP + -1) = cVar1;
    *(bool *)0x9d50 = cVar1 == '\x01';
    if (*(char *)0x9d50 == '\0') {
      *(undefined2 *)0x9d8c = 1;
      FUN_1000_e43d(*(undefined1 *)(unaff_BP + -1),*(undefined2 *)0x9070);
    }
    else {
      uVar2 = FUN_1000_e31a(*(undefined2 *)0x9070);
      *(undefined2 *)0x9d8c = uVar2;
    }
    *(undefined1 *)0x9d4e = 0;
  }
  *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 0;
  while( true ) {
    if (*(char *)0x9d50 == '\0') {
      uVar3 = FUN_1000_e38e(*(undefined2 *)0x9070);
    }
    else {
      uVar3 = FUN_1000_5fad();
      uVar3 = uVar3 & 0xff;
    }
    if ((uVar3 == 0xffff) || (0x20 < (int)uVar3)) break;
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  if ((*(char *)0x9d90 == '\0') || (uVar3 != 0x40)) {
    if ((*(char *)0x9d90 == '\0') || (uVar3 != 0x5e)) {
      if ((uVar3 != 0xffff) && (*(int *)0x9d8e < *(int *)0x9d8c)) {
        *(undefined1 *)(unaff_BP + -2) = 0;
        while ((0x20 < (int)uVar3 && (*(int *)0x9d8e < *(int *)0x9d8c))) {
          if ((*(char *)0x9d90 == '\0') || (uVar3 != 0x2a)) {
            if ((*(char *)0x9d90 == '\0') || (uVar3 != 0x23)) {
              *(undefined1 *)(*(byte *)(unaff_BP + -2) + 0x9bb) = (char)uVar3;
            }
            else {
              FUN_1000_e74e(*(byte *)(unaff_BP + -2) + 0x9bb,0x207f);
              *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x03';
            }
          }
          else {
            FUN_1000_e74e(*(byte *)(unaff_BP + -2) + 0x9bb,0x207a);
            *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x03';
          }
          if (*(char *)0x9d50 == '\0') {
            uVar3 = FUN_1000_e38e(*(undefined2 *)0x9070);
          }
          else {
            uVar3 = FUN_1000_5fad();
            uVar3 = uVar3 & 0xff;
          }
          *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
        }
        if (*(char *)0x9d50 == '\0') {
          FUN_1000_e43d(0x20,*(undefined2 *)0x9070);
        }
        else {
          *(undefined1 *)0x9d50 = 2;
        }
        *(undefined1 *)(*(byte *)(unaff_BP + -2) + 0x9bb) = 0;
        return 0;
      }
      return 1;
    }
    *(undefined1 *)0x9d92 = 1;
  }
  else {
    *(undefined1 *)0x9d91 = 1;
  }
  return uVar3;
}



/* 0x1618a ev_847e9a5bd89cbb247ad64aa35afd0b28b283bf3578d03c4afb742935561aefbd */

undefined2 __cdecl16near FUN_1000_618a(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int unaff_BP;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d4e != '\0') {
    FUN_1000_5a53();
  }
  if (*(char *)0x9d88 == '\0') {
    *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 1;
  }
  else {
    *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 0;
    *(undefined1 *)0x9d88 = 0;
  }
LAB_1000_61b6:
  do {
    cVar1 = FUN_1000_64cc();
    *(char *)(unaff_BP + -1) = cVar1;
    if (cVar1 != '\0') {
      if (*(char *)0x9bb == '\0') goto LAB_1000_61b6;
    }
    if (*(char *)(unaff_BP + -1) == '\0') {
      FUN_1000_5a53();
      *(undefined1 *)0x9bb = 0;
      *(undefined1 *)0x9d4e = 1;
    }
    if (*(char *)(unaff_BP + -1) != '\0') {
      if (*(char *)0x9d4e == '\0') {
        if (*(char *)0x9d8b != '\0') {
          uVar2 = FUN_1000_e793((int)*(char *)0x9bb);
          *(undefined1 *)0x9bb = uVar2;
          *(undefined1 *)0x9d8b = 0;
        }
        iVar4 = (int)*(char *)0x9bb;
        if ((((((*(byte *)(iVar4 + -0x7183) & 7) == 0) && (*(char *)0x9d88 == '\0')) &&
             (iVar4 != 0x24)) && ((iVar4 != 0x2d && (iVar4 != 0x5f)))) &&
           ((iVar4 != 0x5e && ((iVar4 != 0x26 && (iVar4 != 0x28)))))) {
          *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = 0;
        }
      }
      else {
        uVar3 = 1;
        if (*(char *)0x90ba != '\0') {
          uVar3 = 2;
        }
        *(undefined2 *)*(undefined2 *)(unaff_BP + 4) = uVar3;
        if ((*(char *)0x9bb == '\'') || (*(char *)0x9bb == '\"')) {
          *(undefined1 *)0x9d8b = 1;
        }
        else {
          uVar2 = FUN_1000_e793((int)*(char *)0x9bb);
          *(undefined1 *)0x9bb = uVar2;
        }
        *(undefined1 *)0x9d4e = 0;
      }
      if (*(char *)0x90ba == '\0') {
        for (iVar4 = 0; *(char *)(iVar4 + 0x9bb) != '\0'; iVar4 = iVar4 + 1) {
          uVar2 = FUN_1000_e7a7((int)*(char *)(iVar4 + 0x9bb));
          *(undefined1 *)(iVar4 + 0x9bb) = uVar2;
        }
      }
      return 0;
    }
  } while( true );
}



/* 0x16298 ev_bd8e2867aa9185c11c14223de7b809840567d1dde0342717d1d5711a1fe1b86b */

void __cdecl16near FUN_1000_6298(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -2) = 0;
  while (*(int *)(unaff_BP + -2) < *(int *)(unaff_BP + 6) + -3) {
    if (*(char *)0x9d4f == '\0') {
      uVar1 = FUN_1000_bdcb(*(undefined1 *)0x90b2);
    }
    else {
      uVar1 = *(undefined1 *)(*(byte *)0x9d4f + 0x7b13);
    }
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 2) = uVar1;
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2)) = uVar1;
    if (*(char *)0x9d4f == '\0') {
      uVar1 = *(undefined1 *)0x90b2;
    }
    else {
      uVar1 = *(undefined1 *)0x90b1;
    }
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 3) = uVar1;
    *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 1) = uVar1;
    if (*(char *)0x9d4e == '\0') {
      for (iVar3 = 3; 0 < iVar3; iVar3 = iVar3 + -1) {
        iVar2 = FUN_1000_bd74(iVar3 + 1);
        *(undefined1 *)(unaff_BP + -3) =
             *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar3 + *(int *)(unaff_BP + -2));
        *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar3 + *(int *)(unaff_BP + -2)) =
             *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar2 + *(int *)(unaff_BP + -2));
        *(undefined1 *)(*(int *)(unaff_BP + 4) + iVar2 + *(int *)(unaff_BP + -2)) =
             *(undefined1 *)(unaff_BP + -3);
      }
      if (*(char *)0x9d4f == '\0') {
        *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 4) = 0x20;
      }
      else {
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
      }
    }
    else {
      *(undefined1 *)0x9d4e = 0;
      if (*(char *)0x9d4f == '\0') {
        *(undefined1 *)(*(int *)(unaff_BP + 4) + *(int *)(unaff_BP + -2) + 4) = 0x20;
      }
      else {
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
      }
    }
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 5;
  }
  iVar3 = *(int *)(unaff_BP + -2);
  if (*(char *)0x9d4f == '\0') {
    iVar3 = iVar3 + -1;
  }
  *(undefined1 *)(iVar3 + *(int *)(unaff_BP + 4)) = 0;
  return;
}



/* 0x1639e ev_e5789414ea1c365096db6083d0efd0a51f82e1abf0923f49ee56af0e036a22c6 */

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



/* 0x164cc ev_45448bc5826e5a68b5463f5c4aa636ba38ec9088caa3c86ae434137b82c6fdf5 */

undefined2 __cdecl16near FUN_1000_64cc(void)

{
  byte bVar1;
  byte *pbVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)*(undefined2 *)0x9d72;
  *(int *)0x9d72 = *(int *)0x9d72 + 1;
  bVar1 = *pbVar2;
  if (bVar1 == 0) {
    if (*(char *)*(undefined2 *)0x9d72 == '\0') {
      if (*(int *)0x2086 == -0x628c) {
        return 0;
      }
      *(int *)0x2086 = *(int *)0x2086 + -2;
      *(undefined2 *)0x9d72 = *(undefined2 *)*(undefined2 *)0x2086;
      uVar5 = FUN_1000_64cc();
      return uVar5;
    }
    FUN_1000_e74e(0x9bb,(char *)*(undefined2 *)0x9d72);
    iVar4 = FUN_1000_f139(*(undefined2 *)0x9d72);
    *(int *)0x9d72 = *(int *)0x9d72 + iVar4 + 1;
  }
  else if (((int)(char)bVar1 & 0x80U) == 0) {
    if ((bVar1 & 0x40) != 0) {
      puVar3 = (undefined2 *)*(undefined2 *)0x2086;
      *(int *)0x2086 = *(int *)0x2086 + 2;
      *puVar3 = *(undefined2 *)0x9d72;
      *(int *)0x9d72 = *(int *)(((int)(char)bVar1 & 0x3fU) * 2 + -0x79ce) + -0x7968;
      uVar5 = FUN_1000_64cc();
      return uVar5;
    }
    FUN_1000_665a(((int)(char)bVar1 & 0x3fU) - 1,0x9bb);
  }
  else {
    (*(code *)*(undefined2 *)(((int)(char)bVar1 & 0x7fU) * 2 + 0x2088))(0x9bb);
  }
  return 1;
}



/* 0x16592 ev_a15dc46b72b8877bd0225e7de048b1435bc8d261ba74fb5b2d1dc75767e6b5f3 */

int __cdecl16near FUN_1000_6592(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  undefined2 local_4;
  
  iVar1 = FUN_1000_bd74(*(undefined2 *)0x9d36);
  iVar2 = FUN_1000_722b((int)*(char *)0x7aee);
  local_4 = (uint)*(byte *)(iVar2 + -0x6f45);
  iVar2 = 0;
  for (; (int)local_4 < iVar1; local_4 = local_4 + *(byte *)(iVar3 + -0x6f45)) {
    iVar3 = FUN_1000_722b((int)*(char *)(iVar2 + 0x7aef));
    iVar2 = iVar2 + 1;
  }
  iVar1 = 0;
  if (3 < iVar2) {
    iVar1 = iVar2 + -3;
  }
  *(int *)0x9d98 = iVar1;
  iVar3 = ((uint)*(byte *)0x90ae - *(int *)0x9d98) + 1;
  iVar1 = FUN_1000_bd74((int)((((uint)*(byte *)0x90ae - *(int *)0x9d98) + 2) * iVar3) / 2);
  iVar2 = *(int *)0x9d98;
  for (local_4 = iVar3; (int)local_4 < iVar1; local_4 = local_4 + iVar3) {
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



/* 0x16629 ev_82d3a691ac07d091532d872964c0ecedf74d6f15bf4454838697afc21f05d24b */

void __cdecl16near FUN_1000_6629(int param_1,int param_2)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x9d96 = 7;
  *(int *)0x9d94 = *(int *)(param_1 * 0x2e + param_2 * 2 + 0x214e) + 0x2992;
  return;
}



/* 0x1665a ev_84ee8bf4042e49e18f9aa487ef8d8404ccce892f0c7814360c4ea40213c37684 */

void __cdecl16near FUN_1000_665a(undefined2 param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined2 unaff_DS;
  uint local_6;
  
  iVar2 = FUN_1000_6592();
  if (*(byte *)0x90af < 8) {
    param_1 = *(undefined2 *)0x8893;
  }
  FUN_1000_6629(param_1,iVar2);
  iVar6 = iVar2;
  while ((*(int *)0x9d98 <= iVar6 && (iVar3 = FUN_1000_6802(), iVar3 == 0))) {
    iVar6 = iVar6 + -1;
    FUN_1000_6629(param_1,iVar6);
  }
  if (iVar6 < *(int *)0x9d98) {
    local_6 = iVar2 + 1;
    FUN_1000_6629(param_1,local_6);
    while ((local_6 <= *(byte *)0x90ae && (iVar2 = FUN_1000_6802(), iVar2 == 0))) {
      local_6 = local_6 + 1;
      FUN_1000_6629(param_1,local_6);
    }
    if (*(byte *)0x90ae < local_6) {
      FUN_1000_6629(param_1,iVar6);
      while ((-1 < iVar6 && (iVar2 = FUN_1000_6802(), iVar2 == 0))) {
        iVar6 = iVar6 + -1;
        FUN_1000_6629(param_1,iVar6);
      }
      if (iVar6 < 0) {
        FUN_1000_6629(param_1,local_6);
        while (iVar2 = FUN_1000_6802(), iVar2 == 0) {
          local_6 = local_6 + 1;
          FUN_1000_6629(param_1,local_6);
        }
      }
    }
  }
  *(undefined2 *)0x9d96 = 7;
  uVar4 = FUN_1000_6802();
  iVar2 = FUN_1000_bd74(uVar4);
  for (iVar6 = 0; iVar6 < iVar2; iVar6 = iVar6 + 1) {
    iVar3 = FUN_1000_6802();
    *(int *)0x9d94 = *(int *)0x9d94 + (iVar3 * 5 >> 3);
    uVar5 = iVar3 * 5 & 7;
    if (*(uint *)0x9d96 < uVar5) {
      *(int *)0x9d94 = *(int *)0x9d94 + 1;
      *(int *)0x9d96 = (*(int *)0x9d96 + 8) - uVar5;
    }
    else {
      *(int *)0x9d96 = *(int *)0x9d96 - uVar5;
    }
  }
  iVar2 = FUN_1000_6802();
  param_2 = (byte *)((int)param_2 + -1);
  for (iVar6 = 0; iVar6 < iVar2; iVar6 = iVar6 + 1) {
    bVar1 = FUN_1000_6802();
    param_2 = param_2 + 1;
    *param_2 = bVar1 | 0x60;
    if ((bVar1 | 0x60) == 0x60) {
      *param_2 = 0x20;
    }
    else if (*param_2 == 0x7b) {
      iVar3 = FUN_1000_72dd(0x2d);
      if (iVar3 == 0) {
        bVar1 = 0x20;
      }
      else {
        bVar1 = 0x2d;
      }
      *param_2 = bVar1;
    }
    else if (*param_2 == 0x7e) {
      iVar3 = FUN_1000_72dd(0x2e);
      if (iVar3 == 0) {
        bVar1 = 0;
      }
      else {
        bVar1 = 0x2e;
      }
      *param_2 = bVar1;
    }
  }
  param_2[1] = 0;
  return;
}



/* 0x16802 ev_3588cc6d19a2510c9a84b993f8337141a4dfd47f330480d7f8aab71b5e45b50c */

byte __cdecl16near FUN_1000_6802(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = *(byte *)*(undefined2 *)0x9d94;
  if (*(uint *)0x9d96 < 5) {
    *(int *)0x9d94 = *(int *)0x9d94 + 1;
    if (*(uint *)0x9d96 < 4) {
      local_3 = local_3 << (4U - (char)*(undefined2 *)0x9d96 & 0x1f) |
                *(byte *)*(undefined2 *)0x9d94 >> ((char)*(undefined2 *)0x9d96 + 4U & 0x1f);
    }
    *(int *)0x9d96 = *(int *)0x9d96 + 3;
  }
  else {
    *(int *)0x9d96 = *(int *)0x9d96 + -4;
    uVar1 = *(undefined2 *)0x9d96;
    *(int *)0x9d96 = *(int *)0x9d96 + -1;
    local_3 = (byte)((uint)(int)(char)local_3 >> ((byte)uVar1 & 0x1f));
  }
  return local_3 & 0x1f;
}



/* 0x1687d ev_1bd1baff88dd12fb2cb4c9cde8b997e8ac824c80bdcf6daf74e3b21f7103bb8c */

void __cdecl16near FUN_1000_687d(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar2 = FUN_1000_7251(0x20e0);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1689a ev_c74e27c7b593713c0669efd551f81d3b7b5b5600e90e486031efae4590550f91 */

void __cdecl16near FUN_1000_689a(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar2 = FUN_1000_7251(0x20e4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x168b7 ev_f88613e5614f0f0c39a22df7221b60e97d24afa2d3ab4562260ef05d2d39b71d */

void __cdecl16near FUN_1000_68b7(void)

{
  undefined1 *puVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x3f;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x168cd ev_71787c8882df6bc1fc2dec502478386ca0ae4e7a325b89f40c5ca304ff4ee033 */

void __cdecl16near FUN_1000_68cd(void)

{
  undefined1 *puVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x21;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x168e3 ev_5ebf7f971f604be6a4a07799e0cc9125e42cc02cde47f2e2a10d99cfd48d1ab4 */

void __cdecl16near FUN_1000_68e3(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d89 == '\0') {
    cVar3 = FUN_1000_7251(0x20eb);
    *(char *)0x9d89 = cVar3;
    if (cVar3 != '\0') {
      pcVar2 = (char *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *pcVar2 = cVar3;
      *(undefined1 *)0x9d88 = 1;
      if (cVar3 == '(') {
        iVar5 = FUN_1000_72dd(0x29);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x29;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
      else if (cVar3 == '<') {
        iVar5 = FUN_1000_72dd(0x3e);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x3e;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
      else if (cVar3 == '[') {
        iVar5 = FUN_1000_72dd(0x5d);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x5d;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
      else if (cVar3 == '{') {
        iVar5 = FUN_1000_72dd(0x7d);
        if (iVar5 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x7d;
        }
        *(undefined1 *)0x9d89 = uVar4;
      }
    }
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)0x9d89;
    *(undefined1 *)0x9d89 = 0;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x169a0 ev_bcde1ae33f864d801226c0f1120bb137890594dd005ea378d8a10ca3b5da68f3 */

void __cdecl16near FUN_1000_69a0(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_73cc(unaff_BP + 4);
  iVar3 = FUN_1000_bd74(2);
  iVar4 = FUN_1000_bd74(4);
  for (iVar3 = iVar3 + iVar4; iVar3 < 4; iVar3 = iVar3 + 1) {
    FUN_1000_73ad(unaff_BP + 4);
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  FUN_1000_737b(unaff_BP + 4,0);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  FUN_1000_737b(unaff_BP + 4,1);
  iVar3 = FUN_1000_bd74(5);
  if (iVar3 != 0) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x2c;
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    FUN_1000_737b(unaff_BP + 4,2);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x2c;
    *(undefined2 *)(unaff_BP + -2) = *(undefined2 *)(unaff_BP + 4);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    iVar3 = FUN_1000_bd74(0xb);
    if (iVar3 == 0) {
      FUN_1000_737b(unaff_BP + 4,3);
    }
    else {
      FUN_1000_737b(unaff_BP + 4,4);
    }
    if (*(int *)(unaff_BP + 4) - *(int *)(unaff_BP + -2) == 3) {
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
      uVar2 = FUN_1000_e793((int)*(char *)*(undefined2 *)(unaff_BP + 4));
      *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = uVar2;
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    }
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    if (iVar3 == 0) {
      FUN_1000_748b(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_748b(unaff_BP + 4);
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x20;
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_748b(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
    }
    else {
      for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {
        FUN_1000_73ad(unaff_BP + 4);
      }
      iVar3 = FUN_1000_72ff(0x20f0);
      if (iVar3 != 0) {
        puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
        *puVar1 = 0x2d;
        FUN_1000_73ad(unaff_BP + 4);
        FUN_1000_73ad(unaff_BP + 4);
        FUN_1000_73ad(unaff_BP + 4);
        FUN_1000_73ad(unaff_BP + 4);
      }
    }
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x16b2b ev_cf1ae2bd2c42352dc4c36fee6c97df4e3e7f6551b60efaedb4040629d5c970ed */

void __cdecl16near FUN_1000_6b2b(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x24;
  *(undefined2 *)(unaff_BP + -2) = *(undefined2 *)(unaff_BP + 4);
  FUN_1000_73cc(unaff_BP + 4);
  for (iVar2 = FUN_1000_bd74(8); 0 < iVar2; iVar2 = iVar2 + -1) {
    FUN_1000_73ad(unaff_BP + 4);
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + -2),1);
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar2;
  return;
}



/* 0x16b80 ev_69cd99cf87954ac66f77d436784e3114a3bfaf3426a859347e761fbb01086c02 */

void __cdecl16near FUN_1000_6b80(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  long lVar5;
  undefined1 uVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 *puVar9;
  int *piVar10;
  int unaff_BP;
  int iVar11;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar12;
  undefined4 uVar13;
  
  FUN_1000_e7bd();
  uVar6 = FUN_1000_7251(0x20f2);
  *(undefined1 *)(unaff_BP + -0x2b) = uVar6;
  for (iVar11 = 0; iVar11 < 2; iVar11 = iVar11 + 1) {
    iVar7 = FUN_1000_72ff(0x20f9);
    if (iVar7 == 0) {
      uVar6 = 0x30;
    }
    else {
      uVar6 = 0x2d;
    }
    *(undefined1 *)(iVar11 * 8 + unaff_BP + -0x18) = uVar6;
    for (iVar7 = 1; iVar7 < 4; iVar7 = iVar7 + 1) {
      FUN_1000_7448(iVar11 * 8 + iVar7 + unaff_BP + -0x18);
      *(undefined2 *)((iVar7 + -1) * 2 + unaff_BP + -0x2a) = 0;
    }
    *(undefined1 *)(iVar11 * 8 + iVar7 + unaff_BP + -0x18) = 0;
    uVar13 = FUN_1000_e4d3(iVar11 * 8 + unaff_BP + -0x18);
    puVar9 = (undefined2 *)(iVar11 * 4 + unaff_BP + -0x24);
    puVar9[1] = (int)((ulong)uVar13 >> 0x10);
    *puVar9 = (int)uVar13;
    if ((*(char *)(unaff_BP + -0x2b) == '@') || (*(char *)(unaff_BP + -0x2b) == '%')) {
      iVar7 = FUN_1000_bd33(uVar13);
      piVar10 = (int *)(iVar11 * 4 + unaff_BP + -0x24);
      piVar10[1] = iVar7 >> 0xf;
      *piVar10 = iVar7;
    }
  }
  cVar1 = *(char *)(unaff_BP + -0x2b);
  if (cVar1 == '%') {
    *(undefined2 *)(unaff_BP + -0x26) = 1;
    *(undefined2 *)(unaff_BP + -0x28) = 1;
    uVar13 = FUN_1000_f04d();
    *(undefined2 *)(unaff_BP + -0x22) = (int)((ulong)uVar13 >> 0x10);
    *(undefined2 *)(unaff_BP + -0x24) = (int)uVar13;
    uVar8 = *(undefined2 *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1a) = *(undefined2 *)(unaff_BP + -0x1e);
    *(undefined2 *)(unaff_BP + -0x1c) = uVar8;
    bVar12 = false;
    if (*(int *)(unaff_BP + -0x22) == 0) {
      bVar12 = *(int *)(unaff_BP + -0x24) == 0;
    }
    if (bVar12) {
      *(undefined2 *)(unaff_BP + -0x22) = 0;
      *(undefined2 *)(unaff_BP + -0x24) = 100;
    }
    uVar13 = FUN_1000_f04d();
    *(undefined2 *)(unaff_BP + -0x1e) = (int)((ulong)uVar13 >> 0x10);
    *(undefined2 *)(unaff_BP + -0x20) = (int)uVar13;
  }
  else if (cVar1 == '*') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    lVar5 = (ulong)*(uint *)(unaff_BP + -0x24) * (ulong)*(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x1a) =
         (int)((ulong)lVar5 >> 0x10) +
         *(uint *)(unaff_BP + -0x24) * *(int *)(unaff_BP + -0x1e) +
         *(int *)(unaff_BP + -0x22) * *(int *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1c) = (int)lVar5;
  }
  else if (cVar1 == '+') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x28) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    uVar2 = *(uint *)(unaff_BP + -0x24);
    uVar3 = *(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x1a) =
         *(int *)(unaff_BP + -0x22) + *(int *)(unaff_BP + -0x1e) +
         (uint)CARRY2(uVar2,*(uint *)(unaff_BP + -0x20));
    *(int *)(unaff_BP + -0x1c) = uVar2 + uVar3;
  }
  else if (cVar1 == '-') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x28) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    uVar8 = *(undefined2 *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1a) = *(undefined2 *)(unaff_BP + -0x1e);
    *(undefined2 *)(unaff_BP + -0x1c) = uVar8;
    uVar8 = *(undefined2 *)(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x1e) = *(undefined2 *)(unaff_BP + -0x22);
    *(undefined2 *)(unaff_BP + -0x20) = uVar8;
    if (*(int *)(unaff_BP + -0x26) != 0) {
      iVar11 = FUN_1000_bd33(*(undefined2 *)(unaff_BP + -0x1c),*(undefined2 *)(unaff_BP + -0x1a));
      *(int *)(unaff_BP + -0x1a) = iVar11 >> 0xf;
      *(int *)(unaff_BP + -0x1c) = iVar11;
      iVar11 = FUN_1000_bd33(*(undefined2 *)(unaff_BP + -0x20),*(undefined2 *)(unaff_BP + -0x1e));
      *(int *)(unaff_BP + -0x1e) = iVar11 >> 0xf;
      *(int *)(unaff_BP + -0x20) = iVar11;
    }
    uVar2 = *(uint *)(unaff_BP + -0x1c);
    uVar3 = *(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x22) =
         *(int *)(unaff_BP + -0x1a) + *(int *)(unaff_BP + -0x1e) +
         (uint)CARRY2(uVar2,*(uint *)(unaff_BP + -0x20));
    *(int *)(unaff_BP + -0x24) = uVar2 + uVar3;
  }
  else if (cVar1 == '/') {
    uVar8 = FUN_1000_757b(unaff_BP + -0x24);
    *(undefined2 *)(unaff_BP + -0x26) = uVar8;
    *(undefined2 *)(unaff_BP + -0x2a) = uVar8;
    uVar8 = *(undefined2 *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1a) = *(undefined2 *)(unaff_BP + -0x1e);
    *(undefined2 *)(unaff_BP + -0x1c) = uVar8;
    iVar11 = *(int *)(unaff_BP + -0x22);
    uVar2 = *(uint *)(unaff_BP + -0x24);
    *(int *)(unaff_BP + -0x1e) = iVar11;
    *(uint *)(unaff_BP + -0x20) = uVar2;
    lVar5 = (ulong)uVar2 * (ulong)*(uint *)(unaff_BP + -0x1c);
    *(int *)(unaff_BP + -0x22) =
         (int)((ulong)lVar5 >> 0x10) +
         uVar2 * *(int *)(unaff_BP + -0x1a) + iVar11 * *(int *)(unaff_BP + -0x1c);
    *(undefined2 *)(unaff_BP + -0x24) = (int)lVar5;
  }
  else if (cVar1 == '@') {
    *(undefined2 *)(unaff_BP + -0x26) = 1;
    *(undefined2 *)(unaff_BP + -0x28) = 1;
    lVar5 = (ulong)*(uint *)(unaff_BP + -0x24) * (ulong)*(uint *)(unaff_BP + -0x20);
    *(int *)(unaff_BP + -0x1a) =
         (int)((ulong)lVar5 >> 0x10) +
         *(uint *)(unaff_BP + -0x24) * *(int *)(unaff_BP + -0x1e) +
         *(int *)(unaff_BP + -0x22) * *(int *)(unaff_BP + -0x20);
    *(undefined2 *)(unaff_BP + -0x1c) = (int)lVar5;
  }
  if (*(int *)(unaff_BP + -0x2a) != 0) {
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x24;
  }
  FUN_1000_bc82(*(undefined2 *)(unaff_BP + -0x24),*(undefined2 *)(unaff_BP + -0x22),
                *(undefined2 *)(unaff_BP + 4));
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + 4),*(undefined2 *)(unaff_BP + -0x2a));
  iVar11 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar11;
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  if (*(char *)(unaff_BP + -0x2b) == '@') {
    FUN_1000_c63b(*(undefined2 *)(unaff_BP + 4));
    iVar11 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar11;
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x20;
  }
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = *(undefined1 *)(unaff_BP + -0x2b);
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  if (*(char *)(unaff_BP + -0x2b) == '%') {
    FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x20fb);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 3;
  }
  if (*(int *)(unaff_BP + -0x28) != 0) {
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x24;
  }
  FUN_1000_bc82(*(undefined2 *)(unaff_BP + -0x20),*(undefined2 *)(unaff_BP + -0x1e),
                *(undefined2 *)(unaff_BP + 4));
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + 4),*(undefined2 *)(unaff_BP + -0x28));
  iVar11 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar11;
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  uVar6 = FUN_1000_75e2(unaff_BP + -0x1c);
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = uVar6;
  puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar4 = 0x20;
  if (*(int *)(unaff_BP + -0x26) != 0) {
    puVar4 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar4 = 0x24;
  }
  FUN_1000_bc82(*(undefined2 *)(unaff_BP + -0x1c),*(undefined2 *)(unaff_BP + -0x1a),
                *(undefined2 *)(unaff_BP + 4));
  FUN_1000_74ab(*(undefined2 *)(unaff_BP + 4),*(undefined2 *)(unaff_BP + -0x26));
  return;
}



/* 0x16f1b ev_9b27ef0ea1068e9561e8c1b9ec286a8b2cce6dc889bb4ef9f6a44e5b0f335a91 */

void __cdecl16near FUN_1000_6f1b(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar3 = FUN_1000_72ff(0x20ff);
  *(char *)(unaff_BP + -1) = cVar3;
  if (cVar3 == '\0') {
    iVar4 = FUN_1000_bd74(3);
    if (iVar4 != 0) {
      FUN_1000_737b(unaff_BP + 4,5);
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x2c;
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x20;
    }
  }
  if (*(char *)(unaff_BP + -1) == '\0') {
    FUN_1000_737b(unaff_BP + 4,6);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
  }
  else {
    FUN_1000_745c(unaff_BP + 4);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)(unaff_BP + -1);
  }
  cVar3 = FUN_1000_72ff(0x2102);
  *(char *)(unaff_BP + -2) = cVar3;
  if (cVar3 == '\0') {
    FUN_1000_73cc(unaff_BP + 4);
  }
  else {
    pcVar2 = (char *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *pcVar2 = cVar3;
    FUN_1000_73ad(unaff_BP + 4);
  }
  if (*(char *)(unaff_BP + -1) == '\0') {
    iVar4 = FUN_1000_bd74(3);
    if (iVar4 != 0) {
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x2c;
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x20;
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x31;
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
      FUN_1000_73ad(unaff_BP + 4);
    }
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)(unaff_BP + -1);
    FUN_1000_73ad(unaff_BP + 4);
    FUN_1000_73ad(unaff_BP + 4);
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0;
  return;
}



/* 0x17023 ev_65eca36ed2b8874fd92ef91d121153439f0b8e6f5f35b7deb6affd9b5329d67d */

void __cdecl16near FUN_1000_7023(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_745c(unaff_BP + 4);
  for (iVar3 = FUN_1000_bd74(2); -1 < iVar3; iVar3 = iVar3 + -1) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x3a;
    FUN_1000_740a(unaff_BP + 4);
    FUN_1000_73ad(unaff_BP + 4);
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  uVar4 = FUN_1000_7251(0x2105);
  uVar2 = FUN_1000_e793(uVar4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x4d;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1708a ev_edfb16c22c18ac0ff1164b663a7d8c56c724d4ae4e723fda84126b61778a7992 */

void __cdecl16near FUN_1000_708a(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_72ff(0x2108);
  if (iVar3 == 0) goto LAB_1000_7105;
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x28;
  FUN_1000_73cc(unaff_BP + 4);
  iVar3 = FUN_1000_72dd(0x30);
  if (iVar3 == 0) {
    iVar3 = FUN_1000_72dd(0x31);
    if (iVar3 != 0) goto LAB_1000_70c5;
    FUN_1000_73eb(unaff_BP + 4);
  }
  else {
LAB_1000_70c5:
    uVar2 = FUN_1000_7251(0x210b);
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = uVar2;
  }
  FUN_1000_73cc(unaff_BP + 4);
  iVar3 = FUN_1000_72dd(0x29);
  if (iVar3 != 0) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x29;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
LAB_1000_7105:
  FUN_1000_73eb(unaff_BP + 4);
  FUN_1000_73eb(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x2d;
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1714d ev_74da02100b1b8f910dd6b1a1936708752aaf0d5715c4d0e04166c66cf603f208 */

void __cdecl16near FUN_1000_714d(void)

{
  undefined1 *puVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x210e);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 4;
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x23;
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x2d;
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x2d;
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  FUN_1000_73ad(unaff_BP + 4);
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x171ce ev_be2c321daca8f71e491e03d87fe2b5773ec7ce86da51de4adca24034f923d952 */

void __cdecl16near FUN_1000_71ce(void)

{
  undefined1 *puVar1;
  char *pcVar2;
  char cVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x9d8a == '\0') {
    cVar3 = FUN_1000_7251(0x2113);
    *(char *)0x9d8a = cVar3;
    if (cVar3 != '\0') {
      pcVar2 = (char *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *pcVar2 = cVar3;
      *(undefined1 *)0x9d88 = 1;
      if (cVar3 == '\"') {
        *(undefined1 *)0x9d8a = 0x22;
      }
      else if (cVar3 == '\'') {
        *(undefined1 *)0x9d8a = 0x27;
      }
    }
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = *(undefined1 *)0x9d8a;
    *(undefined1 *)0x9d8a = 0;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1722b ev_88eae95199bc741e49a622810827497f100b2af2090b044ec1544298a604cf4a */

int __cdecl16near FUN_1000_722b(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_e793((int)*(char *)(unaff_BP + 4));
  *(char *)(unaff_BP + 4) = cVar1;
  if ('z' < cVar1) {
    *(char *)(unaff_BP + 4) = *(char *)(unaff_BP + 4) + -0x1a;
  }
  return (int)*(char *)(*(char *)(unaff_BP + 4) + 0x79ef);
}



/* 0x17251 ev_7d354cbcaa1c54fa2c99527dfca2da22062f83d89a17a7e5e67d9117d97acaaa */

int __cdecl16near FUN_1000_7251(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -0x38) = 0;
  iVar6 = 0;
  iVar5 = 0;
  while( true ) {
    iVar3 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
    if (iVar3 <= iVar6) break;
    iVar4 = FUN_1000_72dd((int)*(char *)(*(int *)(unaff_BP + 4) + iVar6));
    iVar3 = iVar5;
    if (iVar4 != 0) {
      cVar1 = *(char *)(*(int *)(unaff_BP + 4) + iVar6);
      *(char *)(unaff_BP + iVar5 + -0x1b) = cVar1;
      iVar3 = FUN_1000_722b((int)cVar1);
      bVar2 = *(byte *)(iVar3 + -0x6f45);
      iVar3 = iVar5 + 1;
      *(byte *)(iVar5 + unaff_BP + -0x36) = bVar2;
      *(int *)(unaff_BP + -0x38) = *(int *)(unaff_BP + -0x38) + (uint)bVar2;
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar3;
  }
  if (iVar5 != 0) {
    iVar5 = FUN_1000_bd74(*(undefined2 *)(unaff_BP + -0x38));
    *(uint *)(unaff_BP + -0x38) = (uint)*(byte *)(unaff_BP + -0x36);
    iVar6 = 0;
    while (*(int *)(unaff_BP + -0x38) < iVar5) {
      iVar6 = iVar6 + 1;
      *(int *)(unaff_BP + -0x38) =
           *(int *)(unaff_BP + -0x38) + (uint)*(byte *)(iVar6 + unaff_BP + -0x36);
    }
    return (int)*(char *)(unaff_BP + iVar6 + -0x1b);
  }
  return 0;
}



/* 0x172dd ev_04e05d87bced0baeaad53257ac81cd81f1f5bbfa92feb45a66bb41b07c0f6e6f */

bool __cdecl16near FUN_1000_72dd(void)

{
  uint uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_722b((int)*(char *)(unaff_BP + 4));
  return uVar1 <= *(byte *)0x90af;
}



/* 0x172ff ev_787efed673adbf1441fb9734ef0ae26de977a125562bf6465a2d385044c8f11f */

int __cdecl16near FUN_1000_72ff(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_7251(*(undefined2 *)(unaff_BP + 4));
  *(undefined1 *)(unaff_BP + -1) = uVar1;
  if (*(char *)(unaff_BP + -1) != '\0') {
    uVar2 = FUN_1000_bd74(0x7f);
    iVar3 = FUN_1000_722b((int)*(char *)(unaff_BP + -1));
    if (uVar2 <= *(byte *)(iVar3 + -0x6f45)) {
      return (int)*(char *)(unaff_BP + -1);
    }
  }
  return 0;
}



/* 0x1733f ev_73117c6b40f913d97c60d0dfea14b0007bbd8b4cc2e51919db8b24c6eca0fa83 */

void __cdecl16near FUN_1000_733f(void)

{
  undefined1 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e793((int)*(char *)*(undefined2 *)(unaff_BP + 4));
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = uVar1;
  while( true ) {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    if (*(char *)*(undefined2 *)(unaff_BP + 4) < ' ') break;
    if (*(char *)*(undefined2 *)(unaff_BP + 4) == ' ') {
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      uVar1 = FUN_1000_e793((int)*(char *)*(undefined2 *)(unaff_BP + 4));
      *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = uVar1;
    }
  }
  return;
}



/* 0x1737b ev_bfed24595fdf0f7629f1599e127350a8f2183ae736247cf7cbb9679cc3d59b8c */

void __cdecl16near FUN_1000_737b(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)(*(int *)(unaff_BP + 6) * 2 + -0x7787),
                *(undefined2 *)*(undefined2 *)(unaff_BP + 4));
  FUN_1000_733f(*(undefined2 *)*(undefined2 *)(unaff_BP + 4));
  iVar1 = FUN_1000_f139(*(undefined2 *)*(undefined2 *)(unaff_BP + 4));
  *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + iVar1;
  return;
}



/* 0x173ad ev_ff3eefe1c81d99efd69717f19a22bb0609f7559a70c1ffe17069bbb7941a4fd1 */

void __cdecl16near FUN_1000_73ad(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_7251(0x2116);
  *(char *)*(undefined2 *)*(undefined2 *)(unaff_BP + 4) = cVar1;
  if (cVar1 != '\0') {
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  return;
}



/* 0x173cc ev_08b5ac1c389d01fffaccecca17f3b7b1c38f3ea2ff0c0b26824ad9e543b1b05a */

void __cdecl16near FUN_1000_73cc(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_7251(0x2121);
  *(char *)*(undefined2 *)*(undefined2 *)(unaff_BP + 4) = cVar1;
  if (cVar1 != '\0') {
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  return;
}



/* 0x173eb ev_e4a2e4d5e06dd3ee173f49eebb1ca9e0b09f50a04dac196ab010e591db2eb275 */

void __cdecl16near FUN_1000_73eb(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_7251(0x212b);
  *(char *)*(undefined2 *)*(undefined2 *)(unaff_BP + 4) = cVar1;
  if (cVar1 != '\0') {
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  return;
}



/* 0x1740a ev_260c4659744f3a43461741a4d0d664cf6fcd3ef1545c938038b245aacad600a0 */

void __cdecl16near FUN_1000_740a(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_7251(0x2134);
  *(char *)*(undefined2 *)*(undefined2 *)(unaff_BP + 4) = cVar1;
  if (cVar1 != '\0') {
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  return;
}



/* 0x17429 ev_78588c431d771563516dd9d4b00ccf18810bd38f5894c51a357dd72e2ad88842 */

void __cdecl16near FUN_1000_7429(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar1 = FUN_1000_7251(0x213b);
  *(char *)*(undefined2 *)*(undefined2 *)(unaff_BP + 4) = cVar1;
  if (cVar1 != '\0') {
    *(int *)*(undefined2 *)(unaff_BP + 4) = *(int *)*(undefined2 *)(unaff_BP + 4) + 1;
  }
  return;
}



/* 0x17448 ev_a09530173bde5d64b8f105eb8cc27cc37e92a0499380fee0be51ba2479fc8652 */

void __cdecl16near FUN_1000_7448(void)

{
  undefined1 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_7251(0x2116);
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = uVar1;
  return;
}



/* 0x1745c ev_8d75657e22a556edfe1de6d153ebb0eebd08a890affd218a40d5b37b9de58173 */

void __cdecl16near FUN_1000_745c(void)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_72ff(0x213f);
  if (iVar3 == 0) {
    FUN_1000_73cc(*(undefined2 *)(unaff_BP + 4));
  }
  else {
    puVar2 = (undefined1 *)*(int *)*(undefined2 *)(unaff_BP + 4);
    piVar1 = (int *)*(undefined2 *)(unaff_BP + 4);
    *piVar1 = *piVar1 + 1;
    *puVar2 = 0x31;
    FUN_1000_7429(*(undefined2 *)(unaff_BP + 4));
  }
  return;
}



/* 0x1748b ev_9fa1d6d0f5367b7ad83c9b61e1c4b2d7559205f8d0a3fc5f546b8f70ee932161 */

void __cdecl16near FUN_1000_748b(void)

{
  int *piVar1;
  undefined1 *puVar2;
  char cVar3;
  undefined1 uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  cVar3 = FUN_1000_7251(0x7aee);
  uVar4 = FUN_1000_e793((int)cVar3);
  puVar2 = (undefined1 *)*(int *)*(undefined2 *)(unaff_BP + 4);
  piVar1 = (int *)*(undefined2 *)(unaff_BP + 4);
  *piVar1 = *piVar1 + 1;
  *puVar2 = uVar4;
  return;
}



/* 0x174ab ev_77b50ddbfe574679d254eea9da29d6f1393cf6da5edcc1b20c8c2b3b2fd6fe6c */

void __cdecl16near FUN_1000_74ab(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  int iVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  pcVar1 = (char *)*(undefined2 *)(unaff_BP + 4);
  *(uint *)(unaff_BP + -0xf) = (uint)(*pcVar1 == '-');
  uVar4 = 3;
  if (*(char *)(unaff_BP + 6) != '\0') {
    uVar4 = 5;
  }
  *(undefined2 *)(unaff_BP + -0xd) = uVar4;
  FUN_1000_e74e(unaff_BP + -0xb,pcVar1);
  iVar6 = 0;
  iVar5 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  if (*(int *)(unaff_BP + -0xd) + *(int *)(unaff_BP + -0xf) < iVar5) {
    for (; iVar6 < iVar5 - *(int *)(unaff_BP + -0xd); iVar6 = iVar6 + 1) {
      uVar3 = *(undefined1 *)(iVar6 + unaff_BP + -0xb);
      puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar2 = uVar3;
    }
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = 0x2c;
  }
  for (; iVar6 < (iVar5 - *(int *)(unaff_BP + -0xd)) + 3; iVar6 = iVar6 + 1) {
    uVar3 = *(undefined1 *)(iVar6 + unaff_BP + -0xb);
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = uVar3;
  }
  if (*(char *)(unaff_BP + 6) != '\0') {
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = 0x2e;
    uVar3 = 0x30;
    iVar7 = iVar6;
    if (1 < iVar5) {
      iVar7 = iVar6 + 1;
      uVar3 = *(undefined1 *)(iVar6 + unaff_BP + -0xb);
    }
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = uVar3;
    uVar3 = *(undefined1 *)(unaff_BP + iVar7 + -0xb);
    puVar2 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar2 = uVar3;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1757b ev_3f29a50c2146aebe948cf3954560e86a3c9670564f6c47b52c36d8fe85bd2113 */

undefined2 __cdecl16near FUN_1000_757b(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  int *piVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_72ff(0x2141);
  if (iVar1 != 0) {
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      puVar3 = (undefined2 *)(iVar1 * 4 + *(int *)(unaff_BP + 4));
      iVar2 = FUN_1000_bd33(*puVar3,puVar3[1]);
      piVar4 = (int *)(iVar1 * 4 + *(int *)(unaff_BP + 4));
      piVar4[1] = iVar2 >> 0xf;
      *piVar4 = iVar2;
    }
    return 1;
  }
  return 0;
}



/* 0x175c1 ev_7d9783924a5ed585b1c1040a8f803000028a507f6d35a5b868a27a59e0a1e581 */

bool __cdecl16near FUN_1000_75c1(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_e677(0x2143,(int)*(char *)(unaff_BP + 4));
  return iVar1 != 0;
}



/* 0x175e2 ev_35e91c820944d4c7149c5a30c96d0cd01394ea278a56456e4f01499ceec1880d */

int __cdecl16near FUN_1000_75e2(void)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  uint uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  undefined4 uVar8;
  undefined2 *puVar9;
  
  FUN_1000_e7bd();
  bVar7 = false;
  if (((int *)*(int *)(unaff_BP + 4))[1] == 0) {
    bVar7 = *(int *)*(int *)(unaff_BP + 4) == 0;
  }
  if (!bVar7) {
    cVar3 = FUN_1000_7251(0x2149);
    *(char *)(unaff_BP + -1) = cVar3;
    if (cVar3 != '=') {
      iVar4 = FUN_1000_bd74(100);
      iVar5 = FUN_1000_bd74(100);
      uVar6 = iVar4 + iVar5 + 1;
      if (((*(char *)(unaff_BP + -1) == '>') &&
          ((iVar4 = *(int *)(*(int *)(unaff_BP + 4) + 2), 0 < iVar4 || (iVar4 == 0)))) ||
         ((*(char *)(unaff_BP + -1) == '<' &&
          ((iVar4 = *(int *)(*(int *)(unaff_BP + 4) + 2), iVar4 < 1 && (iVar4 != 0)))))) {
        puVar9 = (undefined2 *)*(undefined2 *)(unaff_BP + 4);
        uVar8 = FUN_1000_f04d();
        puVar9[1] = (int)((ulong)uVar8 >> 0x10);
        *puVar9 = (int)uVar8;
      }
      else {
        puVar1 = (uint *)*(int *)(unaff_BP + 4);
        uVar2 = *puVar1;
        puVar9 = (undefined2 *)*(int *)(unaff_BP + 4);
        puVar9[1] = (int)((ulong)uVar6 * (ulong)uVar2 >> 0x10) +
                    uVar6 * puVar1[1] + ((int)uVar6 >> 0xf) * *puVar1;
        *puVar9 = (int)((ulong)uVar6 * (ulong)uVar2);
      }
    }
    return (int)*(char *)(unaff_BP + -1);
  }
  return 0x3d;
}



/* 0x1768e ev_40be234a7e197e04dc49fb8374e1cc07b812a688b58a1ddae5b4321c952df132 */

void __cdecl16near FUN_1000_768e(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  int iVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  for (iVar6 = 0; iVar6 < 5; iVar6 = iVar6 + 1) {
    iVar3 = *(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23;
    iVar4 = *(int *)(unaff_BP + 6) * 4;
    iVar7 = *(int *)(iVar4 + -0x6264);
    iVar5 = *(int *)(iVar3 + -0x67a1);
    if ((iVar5 < iVar7) ||
       ((iVar7 == iVar5 && (*(uint *)(iVar3 + -0x67a3) < *(uint *)(iVar4 + -0x6266))))) break;
  }
  if (iVar6 != 5) {
    for (iVar7 = 3; iVar6 <= iVar7; iVar7 = iVar7 + -1) {
      FUN_1000_e74e(*(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23 + -0x67bd,
                    *(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23 + -0x67bd);
      iVar5 = *(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23;
      uVar1 = *(undefined2 *)(iVar5 + -0x67a3);
      iVar3 = *(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23;
      *(undefined2 *)(iVar3 + -0x67a1) = *(undefined2 *)(iVar5 + -0x67a1);
      *(undefined2 *)(iVar3 + -0x67a3) = uVar1;
      *(undefined1 *)(*(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23 + -0x679f) =
           *(undefined1 *)(*(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23 + -0x679f);
      iVar5 = *(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23;
      uVar1 = *(undefined2 *)(iVar5 + -0x679e);
      iVar3 = *(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23;
      *(undefined2 *)(iVar3 + -0x679c) = *(undefined2 *)(iVar5 + -0x679c);
      *(undefined2 *)(iVar3 + -0x679e) = uVar1;
    }
    if (*(int *)(unaff_BP + 6) == 0) {
      FUN_1000_e74e(*(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23 + -0x67bd,0x9072);
    }
    else {
      FUN_1000_e74e(*(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23 + -0x67bd,*(undefined2 *)0x6d5);
    }
    iVar7 = *(int *)(unaff_BP + 6) * 4;
    uVar1 = *(undefined2 *)(iVar7 + -0x6266);
    iVar6 = *(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23;
    *(undefined2 *)(iVar6 + -0x67a1) = *(undefined2 *)(iVar7 + -0x6264);
    *(undefined2 *)(iVar6 + -0x67a3) = uVar1;
    cVar2 = '\b';
    if (7 < *(byte *)0x90af) {
      cVar2 = *(char *)0x90af + '\x01';
    }
    *(char *)(iVar6 + -0x679f) = cVar2;
    uVar1 = *(undefined2 *)0x99a4;
    *(undefined2 *)(iVar6 + -0x679c) = *(undefined2 *)0x99a6;
    *(undefined2 *)(iVar6 + -0x679e) = uVar1;
    *(undefined1 *)0x906e = 1;
    return;
  }
  return;
}



/* 0x1787b ev_400d978dd05923c30e46dcfe75f5cad8f79e7f77919e41263f26301ba83710db */

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



/* 0x17a3a ev_f90824ffc6cfadeeb61694ac5404bb8a5ea95bc04b536cd101a26224ae7360da */

void __cdecl16near FUN_1000_7a3a(void)

{
  int iVar1;
  
  FUN_1000_e7bd();
  FUN_1000_787b(1,2);
  FUN_1000_787b(0,0xd);
  FUN_1000_bd1f();
  iVar1 = FUN_1000_f831();
  if (iVar1 == 0x1b) {
    FUN_1000_e74e(0x17a0,0x1004);
  }
  return;
}



/* 0x17a75 ev_c5aac710168207ae0ef4418acd1603efb59130ea0e4f7ad49b953703179020c2 */

/* WARNING: Removing unreachable block (ram,0x00017b14) */

undefined2 __cdecl16near FUN_1000_7a75(int param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = (*(int *)0xa04a + 1U) % 0xaa;
  if (uVar2 == *(uint *)0xa04c) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = 0;
    if (param_2 != 0 || param_1 != 0) {
      uVar1 = FUN_1000_f04d();
    }
    *(undefined2 *)(uVar2 * 4 + -0x625e) = uVar1;
    uVar1 = FUN_1000_f04d();
    *(undefined2 *)(uVar2 * 4 + -0x625c) = uVar1;
    *(uint *)0xa04a = uVar2;
    uVar2 = (uVar2 + 1) % 0xaa;
    if (uVar2 == *(uint *)0xa04c) {
      uVar1 = 0xffff;
    }
    else {
      *(undefined2 *)(uVar2 * 4 + -0x625e) = 0;
      uVar1 = FUN_1000_f04d();
      *(undefined2 *)(uVar2 * 4 + -0x625c) = uVar1;
      *(uint *)0xa04a = uVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 0x17b5b ev_7d9d848042ed619bb8cc60972cbcac9aefb3d1f55a2bc05b835fdfa55ccc2f56 */

undefined2 __cdecl16near FUN_1000_7b5b(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    iVar1 = FUN_1000_7a75(*param_2,param_2[1],param_2[2],param_2[3]);
    if (iVar1 == -1) break;
    param_2 = param_2 + 4;
    param_1 = param_1 + -1;
  }
  return 0xffff;
}



/* 0x17b92 ev_09aa656890de3cff10b612b472cd80134fabe531b99f68da8b25ce2a73232d09 */

undefined2 __cdecl16near FUN_1000_7b92(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  long lVar2;
  undefined4 uVar3;
  
  FUN_1000_7c0a();
  lVar2 = FUN_1000_81e3(0x60);
  if (lVar2 == 0) {
    lVar2 = FUN_1000_81e3(0x61);
    if (lVar2 == 0) {
      *(undefined2 *)0x8f4e = 0;
      *(undefined2 *)0x8f4c = 0;
      uVar3 = FUN_1000_81e3(0x1c);
      *(undefined2 *)0x8f46 = (int)((ulong)uVar3 >> 0x10);
      *(undefined2 *)0x8f44 = (int)uVar3;
      FUN_1000_81ff(0x61,uVar3);
      FUN_1000_7c98(0x1c,0x81c3);
      *(undefined2 *)0x8f4a = 0;
      *(undefined2 *)0x8f48 = 0;
      *(undefined2 *)0x8f50 = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffff;
    }
  }
  else {
    uVar1 = 0xffff;
  }
  return uVar1;
}



/* 0x17c0a ev_d4d3dbd713e670a681a9c2587e6228d216468d90cf32912b2766c31dfff785d9 */

undefined2 __cdecl16near FUN_1000_7c0a(void)

{
  undefined2 unaff_DS;
  bool bVar1;
  
  FUN_1000_7d49();
  bVar1 = false;
  if (*(int *)0x8f46 == 0) {
    bVar1 = *(int *)0x8f44 == 0;
  }
  if (!bVar1) {
    FUN_1000_81ff(0x1c,*(undefined2 *)0x8f44,*(undefined2 *)0x8f46);
    *(undefined2 *)0x8f46 = 0;
    *(undefined2 *)0x8f44 = 0;
  }
  bVar1 = false;
  if (*(int *)0x8f4a == 0) {
    bVar1 = *(int *)0x8f48 == 0;
  }
  if (!bVar1) {
    FUN_1000_81ff(8,*(undefined2 *)0x8f48,*(undefined2 *)0x8f4a);
    *(undefined2 *)0x8f4a = 0;
    *(undefined2 *)0x8f48 = 0;
  }
  FUN_1000_81ff(0x60,0,0);
  FUN_1000_81ff(0x61,0,0);
  *(undefined2 *)0x8f50 = 0;
  return 0;
}



/* 0x17c98 ev_9f59b0d802e7ebdcf362d4478cc088ccf4194f94f9566fbd142c294f43ee4c05 */

undefined4 __cdecl16near FUN_1000_7c98(undefined2 param_1,undefined2 param_2)

{
  undefined2 local_12 [4];
  undefined2 local_a;
  undefined2 local_8;
  undefined4 local_6;
  
  local_6 = FUN_1000_81e3(param_1);
  FUN_1000_e6fc(local_12);
  local_8 = local_12[0];
  local_a = param_2;
  FUN_1000_81ff(param_1,param_2,local_12[0]);
  return local_6;
}



/* 0x17ce8 ev_09c645ae18db5aa74c340e91bf11c8e22becb8aaf3f806acb12e0decc1770dc5 */

void __cdecl16near FUN_1000_7ce8(void)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  while( true ) {
    iVar2 = *(int *)0x8f52;
    *(int *)0x8f52 = *(int *)0x8f52 + -1;
    if (iVar2 != 0) {
      return;
    }
    if (*(int *)0xa04a == *(int *)0xa04c) break;
    uVar1 = (*(int *)0xa04c + 1U) % 0xaa;
    *(uint *)0xa04c = uVar1;
    iVar2 = uVar1 * 4;
    *(undefined2 *)0x8f52 = *(undefined2 *)(iVar2 + -0x625c);
    iVar2 = *(int *)(iVar2 + -0x625e);
    if (iVar2 == 0) {
      FUN_1000_7e2a();
    }
    else {
      FUN_1000_7d9c(iVar2);
      FUN_1000_7e0d();
    }
  }
  *(undefined2 *)0x8f52 = 0;
  FUN_1000_7e2a();
  return;
}



/* 0x17d49 ev_558f9d22c28977aed52bbc9bfbf9500ce5df5bc2688568ff76b7c4ab34d84545 */

void __cdecl16near FUN_1000_7d49(void)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0xa04c = 0;
  *(undefined2 *)0xa04a = 0;
  *(undefined2 *)0x8f52 = 0;
  FUN_1000_7e2a();
  return;
}



/* 0x17d64 ev_211a15a8f3a9a5e667bc47a4c12b42a8bbf159cbd0737571c53df86082953276 */

void __cdecl16near FUN_1000_7d64(int *param_1,int *param_2)

{
  undefined2 unaff_DS;
  
  if (*(uint *)0xa04a < *(uint *)0xa04c) {
    *param_1 = (0xaa - *(int *)0xa04c) + *(int *)0xa04a;
  }
  else {
    *param_1 = *(uint *)0xa04a - *(int *)0xa04c;
  }
  *param_2 = 0xaa - *param_1;
  return;
}



/* 0x17d9c ev_2f39900b1910443513308d30597eb970cf3f07b2ccf50aaea8f486cca135fa30 */

void __cdecl16near FUN_1000_7d9c(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xff;
  param_1 = param_1 >> 8;
  FUN_1000_e6e4(0x43,0xb6,param_1,uVar1);
  FUN_1000_e6e4(0x42,uVar1);
  FUN_1000_e6e4(0x42,param_1);
  return;
}



/* 0x17de4 ev_4e3d8a70973b076c70cd9cfb37ae5e5e96e277f83aa2c5fc084622d1d7d73cae */

void __cdecl16near FUN_1000_7de4(int param_1,int param_2)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0 || param_1 != 0) {
    uVar1 = FUN_1000_f04d();
  }
  FUN_1000_7d9c(uVar1);
  return;
}



/* 0x17e0d ev_437fb8f70453e1ffb70d8d938429ab65dff9464f6cbe4f6dfce5258cf6054ba5 */

void __cdecl16near FUN_1000_7e0d(void)

{
  uint uVar1;
  
  uVar1 = FUN_1000_e6cf(0x61);
  FUN_1000_e6e4(0x61,uVar1 | 3);
  return;
}



/* 0x17e2a ev_511aee0c038691bf43c2f7d5153da6d079673e4fa2fc65802ea7782cb906ef21 */

void __cdecl16near FUN_1000_7e2a(void)

{
  uint uVar1;
  
  uVar1 = FUN_1000_e6cf(0x61);
  FUN_1000_e6e4(0x61,uVar1 & 0xfc);
  return;
}



/* 0x17e47 ev_e361ab9a9109127766c61fe88b2beb16cf30a072628e4c5003b213e85fc7d214 */

void __cdecl16near FUN_1000_7e47(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_6 [2];
  int local_4;
  
  FUN_1000_7d64(&local_4,local_6);
  switch(param_1) {
  case 0:
    for (iVar1 = 1; iVar1 < 0x40; iVar1 = iVar1 * 2) {
      for (iVar2 = 0; iVar2 < 0xc; iVar2 = iVar2 + 1) {
        uVar3 = FUN_1000_f04d(0x53,0);
        FUN_1000_7a75(uVar3);
      }
    }
    break;
  case 1:
    FUN_1000_8134();
    FUN_1000_8104();
    FUN_1000_811c();
    FUN_1000_7b5b(1,0x7cf8);
    FUN_1000_7b5b(1,0x7cf8);
    FUN_1000_7b5b(2,32000);
    FUN_1000_7b5b(1,0x7cd8);
    FUN_1000_8134();
    FUN_1000_7b5b(1,0x7d10);
    FUN_1000_7b5b(1,0x7cf8);
    FUN_1000_7b5b(3,0x7d18);
    FUN_1000_7b5b(1,0x7cf8);
    FUN_1000_7b5b(1,0x7d30);
    FUN_1000_7b5b(1,0x7ce0);
    FUN_1000_7b5b(1,0x7d38);
    FUN_1000_7b5b(1,0x7ce0);
    FUN_1000_81a5();
    FUN_1000_8175();
    FUN_1000_818d();
    FUN_1000_7b5b(1,0x7d68);
    FUN_1000_7b5b(1,0x7d68);
    FUN_1000_7b5b(2,0x7d70);
    FUN_1000_81a5();
    FUN_1000_7b5b(10,0x7d80);
    break;
  case 2:
    if (local_4 == 0) {
      FUN_1000_7b5b(3,0x7bb0);
    }
    break;
  case 3:
    if (local_4 == 0) {
      FUN_1000_7b5b(3,0x7b98);
    }
    break;
  case 4:
    if (local_4 == 0) {
      FUN_1000_7b5b(1,0x7b90);
    }
    break;
  case 5:
    if (local_4 == 0) {
      FUN_1000_7a75(0x98ca,1,0x3e,0);
    }
    break;
  default:
    break;
  case 7:
    FUN_1000_804e();
    FUN_1000_7b5b(7,0x7c60);
    FUN_1000_804e();
    FUN_1000_7b5b(7,0x7c98);
  }
  return;
}



/* 0x1804e ev_ded994f2a9e8f5f0ee3d4e6ed0dd847759fae1aaa626ed70b5d1e6234279afab */

void __cdecl16near FUN_1000_804e(void)

{
  FUN_1000_7b5b(6,0x7bc8);
  FUN_1000_7b5b(1,0x7bf8);
  FUN_1000_7b5b(1,0x7bf8);
  FUN_1000_7b5b(6,0x7c00);
  FUN_1000_7b5b(1,0x7bf8);
  FUN_1000_7b5b(1,0x7bf8);
  FUN_1000_7b5b(2,0x7c30);
  FUN_1000_7b5b(3,0x7c40);
  FUN_1000_7b5b(1,0x7c58);
  FUN_1000_7b5b(3,0x7c40);
  return;
}



/* 0x180e1 ev_329fb83dc8e16e2ee4f8dca30fdc0360b9029f0cffcc8d618e7b5de3a78228ec */

void __cdecl16near FUN_1000_80e1(void)

{
  FUN_1000_7b5b(1,0x7cd0);
  FUN_1000_7b5b(1,0x7cd0);
  return;
}



/* 0x18104 ev_dc6167dd7b8b958d8a8d119e60c37c51f6c3b85159d3c301c7b57d90789ca65b */

void __cdecl16near FUN_1000_8104(void)

{
  FUN_1000_80e1();
  FUN_1000_7b5b(1,0x7cd8);
  return;
}



/* 0x1811c ev_122a03e994ae15f7bd9be938834987b5eb0a8b0bae249ed51cc6bc9e55ed98b4 */

void __cdecl16near FUN_1000_811c(void)

{
  FUN_1000_80e1();
  FUN_1000_7b5b(1,0x7ce0);
  return;
}



/* 0x18134 ev_8801b54dd57e33c0b25bb70cbd52ccdefe79ffe910a974a94688e799782411e5 */

void __cdecl16near FUN_1000_8134(void)

{
  FUN_1000_8104();
  FUN_1000_8104();
  FUN_1000_811c();
  FUN_1000_7b5b(2,0x7ce8);
  return;
}



/* 0x18152 ev_507778f937612366d78fff68c043668dd77848021bf28d787da1e42df2b7bac6 */

void __cdecl16near FUN_1000_8152(void)

{
  FUN_1000_7b5b(1,0x7d40);
  FUN_1000_7b5b(1,0x7d40);
  return;
}



/* 0x18175 ev_51d9559e38eff984939b8414c478f79cf656cf4a25e589281b37fdf3d5c891b0 */

void __cdecl16near FUN_1000_8175(void)

{
  FUN_1000_8152();
  FUN_1000_7b5b(1,0x7d48);
  return;
}



/* 0x1818d ev_5453a726957918acae11c8948076b22100b0772473b05b7d796fc83fe0da8fa6 */

void __cdecl16near FUN_1000_818d(void)

{
  FUN_1000_8152();
  FUN_1000_7b5b(1,0x7d50);
  return;
}



/* 0x181a5 ev_a6a191d99a5a31c12ee825b94c9d76337769d298530b18ac0ffdb36f44262c82 */

void __cdecl16near FUN_1000_81a5(void)

{
  FUN_1000_8175();
  FUN_1000_8175();
  FUN_1000_818d();
  FUN_1000_7b5b(2,0x7d58);
  return;
}



/* 0x181e3 ev_4fbe185707a3e3ac1dafea8338da869b9120857771d0e7b91b590a4bb818a783 */

undefined4 __cdecl16near FUN_1000_81e3(int param_1)

{
  return CONCAT22(((undefined2 *)(param_1 * 4))[1],*(undefined2 *)(param_1 * 4));
}



/* 0x181ff ev_cf524a8be4be965ed5de24679cbae98fc47c5a56d420844aa697b5502eb96d71 */

void __cdecl16near FUN_1000_81ff(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 * 4) = param_2;
  ((undefined2 *)(param_1 * 4))[1] = param_3;
  return;
}



/* 0x18247 ev_e353dd29d44c13386527b28acfb93c4adff68b666911dc221cc3ef44a8399bf8 */

void __cdecl16near FUN_1000_8247(void)

{
  undefined2 uVar1;
  int iVar2;
  int unaff_BP;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_e7cd(*(undefined2 *)(unaff_BP + 4),0x7e02);
  *(undefined2 *)0x9070 = uVar1;
  uVar1 = FUN_1000_e7cd(0x7e04,0x7e0d);
  *(undefined2 *)0xa04e = uVar1;
  iVar3 = 0;
  while( true ) {
    iVar2 = FUN_1000_e38e(*(undefined2 *)0x9070);
    if (iVar2 == -1) break;
    FUN_1000_e892(iVar2,*(undefined2 *)0xa04e);
    iVar3 = iVar3 + 1;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_e913(*(undefined2 *)0xa04e);
  uVar1 = FUN_1000_e7cd(*(undefined2 *)(unaff_BP + 4),0x7e0f);
  *(undefined2 *)0x9070 = uVar1;
  uVar1 = FUN_1000_e7cd(0x7e11,0x7e1a);
  *(undefined2 *)0xa04e = uVar1;
  FUN_1000_e8c5(1,*(undefined2 *)0x9070);
  FUN_1000_e352(iVar3,*(undefined2 *)0x9070);
  iVar3 = 1;
  while( true ) {
    iVar2 = FUN_1000_e38e(*(undefined2 *)0xa04e);
    if (iVar2 == -1) break;
    if (iVar2 < 0x21) {
      iVar2 = 0x20;
    }
    if (iVar3 == 8) {
      iVar3 = 1;
    }
    *(undefined1 *)(unaff_BP + -1) = (char)(iVar2 << ((byte)iVar3 & 0x1f));
    *(byte *)(unaff_BP + -1) = *(byte *)(unaff_BP + -1) | (byte)(iVar2 >> (8 - (byte)iVar3 & 0x1f));
    FUN_1000_e8c5(*(undefined1 *)(unaff_BP + -1),*(undefined2 *)0x9070);
    iVar3 = iVar3 + 1;
  }
  FUN_1000_e913(*(undefined2 *)0x9070);
  FUN_1000_e913(*(undefined2 *)0xa04e);
  FUN_1000_e56c(0x1a,unaff_BP + -0x2c);
  FUN_1000_e56c(0x41,0x7e1c,0);
  return;
}



/* 0x18357 ev_b191159a98cd361ab23bb67a6015862e144afb90c9acc3fe278137daf94f895a */

void __cdecl16near FUN_1000_8357(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(*(undefined1 *)(unaff_BP + 6),0);
  FUN_1000_f6a4(0x7e26,*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 8));
  return;
}



/* 0x18383 ev_60a09eb0bf002a9d97f9f20b747b7ea99ff5fa7b7984fefbf44dd61a54182ec6 */

byte __cdecl16near FUN_1000_8383(void)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)(unaff_BP + 8) == '\0') {
    if (*(char *)(unaff_BP + 6) == '\0') {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar3 = (uint)*(byte *)(unaff_BP + 4) * 4;
      bVar1 = FUN_1000_52dc(*(undefined2 *)(iVar3 + -0x6dce),*(undefined2 *)(iVar3 + -0x6dcc),
                            *(undefined2 *)(iVar5 + -0x6ca2),*(undefined2 *)(iVar5 + -0x6ca0),
                            *(undefined2 *)(iVar4 + -0x6efa),*(undefined2 *)(iVar4 + -0x6ef8));
    }
    else {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar3 = (uint)*(byte *)(unaff_BP + 4) * 4;
      bVar1 = FUN_1000_52dc(*(undefined2 *)(iVar3 + -0x652c),*(undefined2 *)(iVar3 + -0x652a),
                            *(undefined2 *)(iVar5 + -0x6400),*(undefined2 *)(iVar5 + -0x63fe),
                            *(undefined2 *)(iVar4 + -0x6658),*(undefined2 *)(iVar4 + -0x6656));
    }
    *(byte *)(unaff_BP + 4) = bVar1;
    if (0x68 < bVar1) {
      *(undefined1 *)(unaff_BP + 4) = 100;
    }
  }
  else {
    if (*(char *)(unaff_BP + 6) == '\0') {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      uVar2 = FUN_1000_529a(*(undefined2 *)(iVar5 + -0x6dce),*(undefined2 *)(iVar5 + -0x6dcc),
                            *(undefined2 *)(iVar4 + -0x6ca2),*(undefined2 *)(iVar4 + -0x6ca0));
    }
    else {
      iVar4 = (uint)*(byte *)(unaff_BP + 4) * 4;
      iVar5 = (uint)*(byte *)(unaff_BP + 4) * 4;
      uVar2 = FUN_1000_529a(*(undefined2 *)(iVar5 + -0x652c),*(undefined2 *)(iVar5 + -0x652a),
                            *(undefined2 *)(iVar4 + -0x6400),*(undefined2 *)(iVar4 + -0x63fe));
    }
    *(undefined1 *)(unaff_BP + 4) = uVar2;
  }
  return *(byte *)(unaff_BP + 4) / 5;
}



/* 0x18497 ev_85db2897384851ae388473ca5647c318d9e42c197258179b35f14e53ff575944 */

void __cdecl16near FUN_1000_8497(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  *(char *)(unaff_BP + 6) = *(char *)(unaff_BP + 6) + '\x01';
  while (*(byte *)(unaff_BP + 6) <= *(byte *)(unaff_BP + 8)) {
    FUN_1000_f7da(0x16 - (uint)*(byte *)(unaff_BP + 6),*(undefined1 *)(unaff_BP + 4));
    FUN_1000_f873(*(undefined1 *)(unaff_BP + 10));
    *(char *)(unaff_BP + 6) = *(char *)(unaff_BP + 6) + '\x01';
  }
  return;
}



/* 0x184d1 ev_5a346b4461f7adee0cd3f4f25e0be6dccfef68a3dd4d99ce6fd76eef800b44a5 */

void __cdecl16near FUN_1000_84d1(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0xa052 == '\0') {
    *(char *)0xa050 = *(char *)0xa050 + -1;
    if (0xb < *(byte *)(unaff_BP + 6)) {
      *(undefined1 *)0xa051 = *(undefined1 *)0xa050;
    }
    if ((uint)*(byte *)0xa051 - (uint)*(byte *)0xa050 == 0x16) {
      *(undefined1 *)0xa052 = *(undefined1 *)0xa050;
    }
    if (*(char *)0xa055 == '\0') {
      *(char *)0xa053 = *(char *)0xa053 + -1;
      if (*(byte *)(unaff_BP + 4) < 9) {
        *(undefined1 *)0xa054 = *(undefined1 *)0xa053;
      }
      if ((uint)*(byte *)0xa054 - (uint)*(byte *)0xa053 == 0x16) {
        *(undefined1 *)0xa055 = *(undefined1 *)0xa053;
      }
    }
  }
  return;
}



/* 0x1853c ev_26125d5a74230a9ecf31e5d54fdc7137064784c3ad6252834184cf2e89d17dc7 */

void __cdecl16near FUN_1000_853c(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int unaff_BP;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar4 = 0xb0;
  *(undefined2 *)(unaff_BP + -5) = 0xb1;
  *(undefined2 *)(unaff_BP + -7) = 0xdb;
  if (*(char *)0x906a != '\0') {
    uVar4 = *(undefined2 *)(unaff_BP + -7);
    *(undefined2 *)(unaff_BP + -5) = uVar4;
  }
  *(undefined1 *)(unaff_BP + -1) = 100;
  FUN_1000_8357(*(undefined1 *)(unaff_BP + -1),2,0xc2);
  *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + -5;
  for (iVar3 = 3; iVar3 < 0x16; iVar3 = iVar3 + 1) {
    FUN_1000_8357(*(undefined1 *)(unaff_BP + -1),iVar3,0xc5);
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + -5;
  }
  FUN_1000_f7da(iVar3,3);
  FUN_1000_f873(0xc0);
  for (iVar3 = 3; iVar3 < 0x4d; iVar3 = iVar3 + 1) {
    FUN_1000_f873(0xc5);
  }
  FUN_1000_f873(0xb4);
  FUN_1000_f7da(0x17,4);
  for (iVar3 = 0; iVar3 < 0x40; iVar3 = iVar3 + 1) {
    uVar2 = FUN_1000_e793((int)*(char *)(iVar3 + 0x7a53));
    FUN_1000_f873(uVar2);
  }
  for (; iVar3 < 0x4b; iVar3 = iVar3 + 1) {
    FUN_1000_f873((int)*(char *)(iVar3 + 0x7ad4));
  }
  *(undefined1 *)0xa053 = 0x4f;
  *(undefined1 *)0xa050 = 0x4f;
  *(undefined1 *)0xa054 = 0x50;
  *(undefined1 *)0xa051 = 0x50;
  *(undefined1 *)0xa055 = 0;
  *(undefined1 *)0xa052 = 0;
  for (iVar3 = 0x4a; -1 < iVar3; iVar3 = iVar3 + -1) {
    if (*(char *)(unaff_BP + 4) == '\0') {
      uVar1 = FUN_1000_8383(iVar3,0,0);
    }
    else {
      uVar1 = FUN_1000_8383(iVar3,0,1);
    }
    *(undefined1 *)(unaff_BP + -3) = uVar1;
    if (*(char *)(unaff_BP + 4) == '\0') {
      uVar1 = FUN_1000_8383(iVar3,1,0);
    }
    else {
      uVar1 = FUN_1000_8383(iVar3,1,1);
    }
    *(undefined1 *)(unaff_BP + -2) = uVar1;
    FUN_1000_b1f3(0,1,7);
    if (*(byte *)(unaff_BP + -3) < *(byte *)(unaff_BP + -2)) {
      FUN_1000_8497(iVar3 + 4,0,*(undefined1 *)(unaff_BP + -3),*(undefined2 *)(unaff_BP + -7));
      FUN_1000_b1f3(0,1,2);
      FUN_1000_8497(iVar3 + 4,*(undefined1 *)(unaff_BP + -3),*(undefined1 *)(unaff_BP + -2),uVar4);
      FUN_1000_84d1(*(undefined1 *)(unaff_BP + -3),*(undefined1 *)(unaff_BP + -2));
    }
    else {
      FUN_1000_8497(iVar3 + 4,0,*(undefined1 *)(unaff_BP + -2),*(undefined2 *)(unaff_BP + -7));
      FUN_1000_b1f3(0,1,4);
      FUN_1000_8497(iVar3 + 4,*(undefined1 *)(unaff_BP + -2),*(undefined1 *)(unaff_BP + -3),
                    *(undefined2 *)(unaff_BP + -5));
      FUN_1000_84d1(*(undefined1 *)(unaff_BP + -2),*(undefined1 *)(unaff_BP + -3));
    }
  }
  if (*(char *)0xa052 == '\0') {
    *(undefined1 *)0xa052 = *(undefined1 *)0xa055;
    iVar3 = 0xf;
  }
  else {
    iVar3 = 4;
  }
  if (*(char *)0xa052 != '\0') {
    FUN_1000_b1f3(0,1,7);
    FUN_1000_ae2b(iVar3,*(byte *)0xa052 + 2,iVar3 + 4,*(byte *)0xa052 + 0x13,1,0xcd,0xba,0xc9,0xbb,
                  200,0xbc);
    FUN_1000_f7da(iVar3 + 1,*(byte *)0xa052 + 3);
    FUN_1000_b1f3(0,1,2);
    FUN_1000_f6a4(0x7e2c,uVar4);
    FUN_1000_f7da(iVar3 + 2,*(byte *)0xa052 + 3);
    FUN_1000_b1f3(0,1,4);
    FUN_1000_f6a4(0x7e3d,*(undefined2 *)(unaff_BP + -5));
    FUN_1000_f7da(iVar3 + 3,*(byte *)0xa052 + 3);
    FUN_1000_b1f3(0,1,7);
    FUN_1000_f6a4(0x7e49,*(undefined2 *)(unaff_BP + -7));
  }
  FUN_1000_b1f3(0,1,7);
  FUN_1000_f831();
  return;
}



/* 0x18857 ev_5458d4929461f75e4075ead84969ebdb0eb4a38b82ca04ca24cc041850bde5db */

void __cdecl16near FUN_1000_8857(void)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar8;
  
  FUN_1000_e7bd();
  iVar2 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar2 + -0x6b5f) == 0) {
    bVar8 = *(int *)(iVar2 + -0x6b61) == 0;
  }
  if (bVar8) {
    bVar8 = false;
    if (*(int *)(iVar2 + -0x6b5b) == 0) {
      bVar8 = *(int *)(iVar2 + -0x6b5d) == 0;
    }
    if (bVar8) {
      FUN_1000_f6a4(0x7e58,0x20);
      goto LAB_1000_88b4;
    }
  }
  uVar3 = FUN_1000_529a(*(undefined2 *)(iVar2 + -0x6b61),*(undefined2 *)(iVar2 + -0x6b5f),
                        *(undefined2 *)(iVar2 + -0x6b5d),*(undefined2 *)(iVar2 + -0x6b5b));
  FUN_1000_f6a4(0x7e52,uVar3);
LAB_1000_88b4:
  iVar2 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar2 + -0x6b63) == 0) {
    bVar8 = *(int *)(iVar2 + -0x6b65) == 0;
  }
  if (bVar8) {
    iVar2 = 0;
  }
  else {
    uVar4 = *(uint *)(iVar2 + -0x6b61) + *(uint *)(iVar2 + -0x6b5d);
    iVar5 = *(int *)(unaff_BP + 4) * 0x4f;
    lVar1 = (ulong)*(uint *)(iVar5 + -0x6b59) * 2;
    uVar6 = (uint)lVar1;
    iVar2 = FUN_1000_52dc(uVar4 - uVar6,
                          ((*(int *)(iVar2 + -0x6b5f) + *(int *)(iVar2 + -0x6b5b) +
                           (uint)CARRY2(*(uint *)(iVar2 + -0x6b61),*(uint *)(iVar2 + -0x6b5d))) -
                          ((int)((ulong)lVar1 >> 0x10) + *(int *)(iVar5 + -0x6b57) * 2)) -
                          (uint)(uVar4 < uVar6),0,0,*(undefined2 *)(iVar2 + -0x6b65),
                          *(undefined2 *)(iVar2 + -0x6b63));
  }
  iVar5 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar5 + -0x6b53) == 0) {
    bVar8 = *(int *)(iVar5 + -0x6b55) == 0;
  }
  if (bVar8) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_1000_52dc(*(undefined2 *)(iVar5 + -0x6b51),*(undefined2 *)(iVar5 + -0x6b4f),
                          *(undefined2 *)(iVar5 + -0x6b4d),*(undefined2 *)(iVar5 + -0x6b4b),
                          *(undefined2 *)(iVar5 + -0x6b55),*(undefined2 *)(iVar5 + -0x6b53));
  }
  iVar7 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar7 + -0x6b47) == 0) {
    bVar8 = *(int *)(iVar7 + -0x6b49) == 0;
  }
  if (bVar8) {
    *(undefined2 *)(unaff_BP + -2) = 0;
  }
  else {
    uVar3 = FUN_1000_52dc(*(undefined2 *)(iVar7 + -0x6b45),*(undefined2 *)(iVar7 + -0x6b43),
                          *(undefined2 *)(iVar7 + -0x6b41),*(undefined2 *)(iVar7 + -0x6b3f),
                          *(undefined2 *)(iVar7 + -0x6b49),*(undefined2 *)(iVar7 + -0x6b47));
    *(undefined2 *)(unaff_BP + -2) = uVar3;
  }
  iVar7 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar7 + -0x6b3b) == 0) {
    bVar8 = *(int *)(iVar7 + -0x6b3d) == 0;
  }
  if (bVar8) {
    *(undefined2 *)(unaff_BP + -4) = 0;
  }
  else {
    uVar3 = FUN_1000_52dc(*(undefined2 *)(iVar7 + -0x6b39),*(undefined2 *)(iVar7 + -0x6b37),
                          *(undefined2 *)(iVar7 + -0x6b35),*(undefined2 *)(iVar7 + -0x6b33),
                          *(undefined2 *)(iVar7 + -0x6b3d),*(undefined2 *)(iVar7 + -0x6b3b));
    *(undefined2 *)(unaff_BP + -4) = uVar3;
  }
  if (iVar2 != 0) {
    FUN_1000_f6a4(0x7e5c,iVar2);
    if ((((iVar5 == 0) || (iVar2 < iVar5)) &&
        ((*(int *)(unaff_BP + -2) == 0 || (iVar2 < *(int *)(unaff_BP + -2))))) &&
       ((*(int *)(unaff_BP + -4) == 0 || (iVar2 < *(int *)(unaff_BP + -4))))) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    *(undefined2 *)(unaff_BP + -6) = uVar3;
    if (*(int *)(unaff_BP + -6) == 0) {
      if ((((iVar5 == 0) || (iVar5 < iVar2)) &&
          ((*(int *)(unaff_BP + -2) == 0 || (*(int *)(unaff_BP + -2) < iVar2)))) &&
         ((*(int *)(unaff_BP + -4) == 0 && (*(int *)(unaff_BP + -4) < iVar2)))) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      *(undefined2 *)(unaff_BP + -6) = uVar3;
    }
    if (iVar5 == 0) {
      FUN_1000_f6a4(0x7e64,0x20);
    }
    else {
      if (*(int *)(unaff_BP + -6) != 0) {
        iVar5 = iVar2;
      }
      FUN_1000_f6a4(0x7e60,iVar5);
      *(undefined2 *)(unaff_BP + -6) = 0;
    }
    if (*(int *)(unaff_BP + -2) == 0) {
      FUN_1000_f6a4(0x7e6c,0x20);
    }
    else {
      iVar5 = *(int *)(unaff_BP + -2);
      if (*(int *)(unaff_BP + -6) != 0) {
        iVar5 = iVar2;
      }
      FUN_1000_f6a4(0x7e68,iVar5);
      *(undefined2 *)(unaff_BP + -6) = 0;
    }
    if (*(int *)(unaff_BP + -4) != 0) {
      iVar5 = *(int *)(unaff_BP + -4);
      if (*(int *)(unaff_BP + -6) != 0) {
        iVar5 = iVar2;
      }
      FUN_1000_f6a4(0x7e70,iVar5);
    }
  }
  return;
}



/* 0x18ad2 ev_7c78fbf88c39b8311910faff335033b6cb526108c5dc890137b72eb44baccd47 */

undefined2 __cdecl16near FUN_1000_8ad2(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar3;
  
  FUN_1000_e7bd();
  if (*(char *)*(undefined2 *)(unaff_BP + 4) != '\0') {
    uVar2 = *(undefined2 *)(unaff_BP + 10);
    *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
    FUN_1000_f7da(uVar2,3);
    FUN_1000_f6a4(*(undefined2 *)(unaff_BP + 4));
  }
  if (*(int *)(unaff_BP + 6) == 0) {
    iVar1 = (*(int *)(unaff_BP + 6) + 4) * 0x4f;
    bVar3 = false;
    if (*(int *)(iVar1 + -0x6b5f) == 0) {
      bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
    }
    if (bVar3) {
      bVar3 = false;
      if (*(int *)(iVar1 + -0x6b5b) == 0) {
        bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
      }
      if (bVar3) goto LAB_1000_8b27;
    }
    bVar3 = true;
  }
  else {
LAB_1000_8b27:
    bVar3 = false;
  }
  if (!bVar3) {
    iVar1 = *(int *)(unaff_BP + 6) * 0x4f;
    bVar3 = false;
    if (*(int *)(iVar1 + -0x6b5f) == 0) {
      bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
    }
    if (bVar3) {
      bVar3 = false;
      if (*(int *)(iVar1 + -0x6b5b) == 0) {
        bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
      }
      if (bVar3) {
        iVar1 = (*(int *)(unaff_BP + 6) + 1) * 0x4f;
        bVar3 = false;
        if (*(int *)(iVar1 + -0x6b5f) == 0) {
          bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
        }
        if (bVar3) {
          bVar3 = false;
          if (*(int *)(iVar1 + -0x6b5b) == 0) {
            bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
          }
          if (bVar3) {
            uVar2 = *(undefined2 *)(unaff_BP + 10);
            *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
            FUN_1000_f7da(uVar2,6);
            FUN_1000_f6a4(0x7e87);
            goto LAB_1000_8c3e;
          }
        }
      }
    }
  }
  while (*(int *)(unaff_BP + 6) < *(int *)(unaff_BP + 8)) {
    iVar1 = *(int *)(unaff_BP + 6) * 0x4f;
    bVar3 = false;
    if (*(int *)(iVar1 + -0x6b5f) == 0) {
      bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
    }
    if (bVar3) {
      bVar3 = false;
      if (*(int *)(iVar1 + -0x6b5b) == 0) {
        bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
      }
      if (!bVar3) goto LAB_1000_8bb0;
    }
    else {
LAB_1000_8bb0:
      uVar2 = *(undefined2 *)(unaff_BP + 10);
      *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
      FUN_1000_f7da(uVar2,5);
      iVar1 = *(int *)(unaff_BP + 6) * 0x4f;
      uVar2 = FUN_1000_c0c6(*(undefined2 *)(iVar1 + -0x6b69),*(undefined2 *)(iVar1 + -0x6b67),
                            unaff_BP + -9,
                            *(undefined1 *)
                             ((*(byte *)0x90b8 - 10) / 10 + *(int *)(unaff_BP + 6) * 0x4f + -0x6b31)
                           );
      FUN_1000_f6a4(0x7e74,*(int *)(unaff_BP + 6) * 0x4f + -0x6b76,uVar2);
      FUN_1000_8857(*(undefined2 *)(unaff_BP + 6));
    }
    *(int *)(unaff_BP + 6) = *(int *)(unaff_BP + 6) + 1;
  }
LAB_1000_8c3e:
  return *(undefined2 *)(unaff_BP + 10);
}



/* 0x18c42 ev_9ed5e77c76bc962905c0d17f75fa4f0f6c09088ad2f129b536157737381eb677 */

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



/* 0x18f6e ev_8470d0d64f681604777bfc0f7ed4296fa1809e1040be3db9b642812d2d0a68b0 */

void __cdecl16near FUN_1000_8f6e(void)

{
  char *pcVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int unaff_BP;
  int iVar7;
  int iVar8;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if ((*(int *)0x9d2c == 8) || (*(int *)0x9d2c == 9)) {
    uVar2 = 0x40;
  }
  else {
    uVar2 = 0x4b;
  }
  *(undefined2 *)(unaff_BP + -2) = uVar2;
  for (iVar7 = 0; iVar7 < 10; iVar7 = iVar7 + 1) {
    *(undefined1 *)(*(int *)0x9d2c * 0x4f + iVar7 + -0x6b31) = 0;
    if ((*(int *)0x9d2c == 10) || (*(int *)0x9d2c == 0xb)) {
      iVar8 = 0x40;
    }
    else {
      iVar8 = 0;
    }
    for (; iVar8 < *(int *)(unaff_BP + -2); iVar8 = iVar8 + 1) {
      puVar4 = (undefined2 *)(iVar8 * 4 + *(int *)(unaff_BP + 8));
      puVar5 = (undefined2 *)(iVar8 * 4 + *(int *)(unaff_BP + 6));
      puVar6 = (undefined2 *)(iVar8 * 4 + *(int *)(unaff_BP + 4));
      iVar3 = FUN_1000_52dc(*puVar6,puVar6[1],*puVar5,puVar5[1],*puVar4,puVar4[1]);
      if ((iVar7 + 1) * 10 <= iVar3) {
        pcVar1 = (char *)(*(int *)0x9d2c * 0x4f + iVar7 + -0x6b31);
        *pcVar1 = *pcVar1 + '\x01';
      }
    }
  }
  return;
}



/* 0x19018 ev_cdecc1ed7ad8a2bad5375ed0459f1498823ddc2be01e714f3ec0fd3c596683cf */

undefined2 __cdecl16near FUN_1000_9018(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)0x9d92 = 0;
  *(undefined1 *)0x9d91 = 0;
  iVar2 = FUN_1000_e7cd(0xa8,0x7fa4);
  *(int *)0x9070 = iVar2;
  if (iVar2 == 0) {
    FUN_1000_00b3(1);
  }
  FUN_1000_2692(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8));
  FUN_1000_ae2b(3,1,0x16,0x4e,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  iVar2 = (uint)*(byte *)(unaff_BP + 4) * 4;
  iVar2 = FUN_1000_e247(*(undefined2 *)0x9070,*(undefined2 *)(iVar2 + 0x7f7c),
                        *(undefined2 *)(iVar2 + 0x7f7e),0);
  if (iVar2 == 0) {
    *(undefined1 *)0x9d4e = 1;
    *(undefined1 *)0x9d90 = 1;
    *(undefined1 *)(unaff_BP + -0x48) = 0;
    while (*(char *)(unaff_BP + -0x48) == '\0') {
      FUN_1000_b1f3(0,1,7);
      *(undefined1 *)(unaff_BP + -0x47) = 0;
      for (iVar2 = 5; (*(char *)(unaff_BP + -0x48) == '\0' && (iVar2 < 0x14)); iVar2 = iVar2 + 1) {
        FUN_1000_f7da(iVar2,5);
        uVar1 = FUN_1000_639e(unaff_BP + -0x47,0x46,0x5ff7);
        *(undefined1 *)(unaff_BP + -0x48) = uVar1;
        FUN_1000_f6a4(0x7fa6,unaff_BP + -0x47);
        if (*(char *)0x9d91 != '\0') {
          *(undefined1 *)0x9d91 = 0;
          *(undefined1 *)(unaff_BP + -0x48) = 0;
          iVar2 = iVar2 + 1;
        }
      }
      FUN_1000_f7da(0x15,0x30);
      FUN_1000_f6a4(0x7fa9);
      while ((unaff_DI = FUN_1000_f831(), unaff_DI != 0x1b && (unaff_DI != 0xd))) {
        FUN_1000_7e47(5);
      }
      if (unaff_DI == 0x1b) {
        *(undefined1 *)(unaff_BP + -0x48) = 1;
      }
      if (*(char *)(unaff_BP + -0x48) == '\0') {
        FUN_1000_b1f3(0,1,7);
        FUN_1000_2723(*(undefined2 *)(unaff_BP + 8));
        FUN_1000_ae2b(3,1,0x16,0x4e,0,0xcd,0xba,0xc9,0xbb,200,0xbc);
      }
    }
    FUN_1000_e913(*(undefined2 *)0x9070);
    *(undefined1 *)0x9d90 = 0;
    FUN_1000_b1f3(0,1,7);
    uVar3 = 1;
    if (unaff_DI == 0x1b) {
      uVar3 = 2;
    }
    return uVar3;
  }
  return 0xffff;
}



/* 0x191df ev_611280463ca091be61f6b8cec623f1403d28c244b3f89736a572a66e318abae5 */

int __cdecl16near FUN_1000_91df(char param_1)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_722b((int)param_1);
  if (iVar1 < 0x1d) {
    if (iVar1 < 0x10) {
      if (iVar1 < 0xc) {
        iVar2 = iVar1;
        if (7 < iVar1) {
          iVar2 = iVar1 + -1;
        }
      }
      else {
        iVar2 = iVar1 + -2;
      }
    }
    else {
      iVar2 = iVar1 + -3;
    }
    if ((*(byte *)(param_1 + -0x7183) & 1) != 0) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = 0x1a;
  }
  return iVar1 + iVar2;
}



/* 0x1922d ev_d9f031106017ee06c797e39c945afa035646ed91b077c32f22d69082b09fc834 */

void __cdecl16near FUN_1000_922d(int param_1,int param_2,char param_3)

{
  if ((((1 < param_1) && (param_1 < 0x16)) && (-1 < param_2)) && (param_2 < 0x50)) {
    FUN_1000_4e79(param_1,param_2,(int)param_3);
  }
  return;
}



/* 0x1925f ev_4015850d0836fed0d0a316209489836414150ecb7cdca96f547666f0fcc27bc9 */

void __cdecl16near FUN_1000_925f(int param_1,undefined2 param_2,int param_3,undefined1 param_4)

{
  undefined2 unaff_DS;
  
  if (*(char *)(*(int *)0xa07e * 0x50 + param_1 + param_3 + 0x574) != '\0') {
    FUN_1000_4e79(param_2,param_3,param_4);
  }
  return;
}



/* 0x19296 ev_7bb1b917bd6ec1a80286bde053c782fa0739f7568676d1a927277e1d9208b2cc */

void __cdecl16near FUN_1000_9296(undefined2 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined2 local_8;
  undefined2 local_6;
  
  FUN_1000_b1f3(1,1,3);
  uVar1 = *(undefined2 *)0x90a6;
  *(undefined2 *)0x90a6 = *(undefined2 *)0xa088;
  local_6 = 0;
  local_8 = FUN_1000_bd74(3);
  while (local_6 < 0x50) {
    iVar2 = FUN_1000_bd74(3);
    if (iVar2 == 2) {
      FUN_1000_925f(param_1,local_8 + 0x16,local_6,0xcd);
      local_6 = local_6 + 1;
    }
    else if (local_8 == 0) {
      FUN_1000_925f(param_1,0x16,local_6,0xbb);
      if (iVar2 == 0) {
        FUN_1000_925f(param_1,0x17,local_6,200);
        local_8 = 1;
      }
      else {
        FUN_1000_925f(param_1,0x17,local_6,0xba);
        FUN_1000_925f(param_1,0x18,local_6,200);
        local_8 = 2;
      }
      local_6 = local_6 + 1;
    }
    else if (local_8 == 1) {
      if (iVar2 == 0) {
        FUN_1000_925f(param_1,0x17,local_6,0xbc);
        FUN_1000_925f(param_1,0x16,local_6,0xc9);
        local_8 = 0;
      }
      else {
        FUN_1000_925f(param_1,0x17,local_6,0xbb);
        FUN_1000_925f(param_1,0x18,local_6,200);
        local_8 = 2;
      }
      local_6 = local_6 + 1;
    }
    else if (local_8 == 2) {
      FUN_1000_925f(param_1,0x18,local_6,0xbc);
      if (iVar2 == 0) {
        FUN_1000_925f(param_1,0x17,local_6,0xc9);
      }
      else {
        FUN_1000_925f(param_1,0x17,local_6,0xba);
        FUN_1000_925f(param_1,0x16,local_6,0xc9);
      }
      local_6 = local_6 + 1;
      local_8 = (uint)(iVar2 == 0);
    }
  }
  *(undefined2 *)0x90a6 = uVar1;
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x1947e ev_d85860f62870f5376967119849eeb63ca3ac614eaece65f78fdf70ecdb58831e */

void __cdecl16near FUN_1000_947e(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  if (*(int *)0xa07e != 0) {
    FUN_1000_e74e(*(undefined2 *)0x6d9,0x9072);
    FUN_1000_e74e(0x9072,*(undefined2 *)0x6d5);
  }
  FUN_1000_2692(0x8026,0x802c);
  if (*(int *)0xa07e != 0) {
    FUN_1000_e74e(0x9072,*(undefined2 *)0x6d9);
  }
  FUN_1000_f7da(0x18,0);
  FUN_1000_f74a();
  FUN_1000_f7da(0,7);
  FUN_1000_f6a4(0x802d,*(undefined2 *)0xa086);
  FUN_1000_f7da(0,0x1f);
  FUN_1000_b1f3(1,5,6);
  FUN_1000_f6a4(0x8030,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
  FUN_1000_9296(param_1);
  return;
}



/* 0x19538 ev_e22cba081ca86e6459b18940b5b4a3b8d3914bdbf9f41bd72047da0167bcb073 */

undefined2 __cdecl16near FUN_1000_9538(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_b21d(2,0xe,0x7fc4,0,0,0x803d);
  *(int *)0xa07a = iVar1;
  if (iVar1 == -1) {
    uVar2 = 0xffff;
  }
  else {
    FUN_1000_2692(0x8054,0x801c);
    iVar1 = FUN_1000_b21d(2,4,0x7fe4,0,0,0x805c);
    *(int *)0xa07c = iVar1;
    if (iVar1 == -1) {
      uVar2 = 0xffff;
    }
    else {
      if (*(int *)0xa07c != 0) {
        FUN_1000_2692(0x1c9,0x801c);
        iVar1 = FUN_1000_b751(0x8079,*(undefined2 *)0x6d5,0x1a,0);
        if (iVar1 == -1) {
          return 0xffff;
        }
      }
      *(undefined2 *)0xa07e = 0;
      *(undefined2 *)0xa086 = 1;
      *(undefined2 *)0xa05a = 0x14;
      *(undefined2 *)0xa05c = 0xc;
      for (iVar1 = 0; iVar1 <= *(int *)0xa07c; iVar1 = iVar1 + 1) {
        *(undefined2 *)(iVar1 * 4 + -0x6264) = 0;
        *(undefined2 *)(iVar1 * 4 + -0x6266) = 0;
        *(undefined2 *)(iVar1 * 2 + -0x5f98) = 0x50;
        for (iVar4 = 0; iVar4 < 0x50; iVar4 = iVar4 + 1) {
          *(undefined1 *)(iVar1 * 0x50 + param_1 + iVar4 + 0x574) = 1;
        }
      }
      *(undefined2 *)0xa088 = *(undefined2 *)0x90a6;
      FUN_1000_947e(param_1);
      FUN_1000_ae2b(3,10,0xb,0x46,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
      FUN_1000_af51(0x809a,0xffff,3,10,7,0x46,0,0);
      FUN_1000_af51(0x813b,0xffff,7,10,0xb,0x46,0,0);
      *(uint *)0xa080 = (uint)*(byte *)0x90af;
      *(uint *)0xa082 = (uint)*(byte *)0x90ba;
      *(uint *)0xa084 = (uint)*(byte *)0x90ae;
      *(undefined1 *)0x90ba = 1;
      if (*(int *)0xa07a == 0) {
        if (*(byte *)0x90af < 7) {
          *(undefined1 *)0x90ae = 4;
          *(undefined2 *)0x9d36 = 0;
          for (iVar1 = 0; iVar1 < 7; iVar1 = iVar1 + 1) {
            iVar4 = FUN_1000_722b((int)*(char *)(iVar1 + 0x7aee));
            *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar4 + -0x6f45);
          }
          *(undefined1 *)0x90af = 7;
        }
        else if ((*(char *)0x90b2 != '\0') &&
                (*(char *)0x90af = *(char *)0x90af + -1,
                (*(byte *)(*(byte *)0x90b2 + 0x8e7d) & 3) != 0)) {
          *(char *)0x90ae = *(char *)0x90ae + -1;
          *(undefined2 *)0x9d36 = 0;
          for (uVar3 = 0; uVar3 < *(byte *)0x90ae + 3; uVar3 = uVar3 + 1) {
            iVar1 = FUN_1000_722b((int)*(char *)(uVar3 + 0x7aee));
            *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
          }
        }
      }
      else {
        *(undefined1 *)0x90af = 0x3f;
        *(undefined1 *)0x90ae = 0x16;
        *(undefined2 *)0x9d36 = 0xa28;
        for (iVar1 = 0; iVar1 < 0x40; iVar1 = iVar1 + 1) {
          *(undefined1 *)(param_1 + iVar1 + 0x664) = *(undefined1 *)(iVar1 + -0x6f45);
          *(undefined1 *)(iVar1 + -0x6f45) = 100;
        }
      }
      if ((*(char *)0x90b2 == '\0') || (0x3e < *(byte *)0x90af)) {
        uVar3 = (uint)*(byte *)0x90af;
      }
      else {
        uVar3 = *(byte *)0x90af - 1;
      }
      uVar2 = FUN_1000_e793((int)*(char *)(uVar3 + 0x7a53));
      uVar2 = FUN_1000_91df(uVar2);
      *(undefined2 *)0xa062 = uVar2;
    }
  }
  return uVar2;
}



/* 0x197bc ev_ff6fbe55a057b61f3740f03aa2d7d19812e678f2750d97d49757f121cb84c5c5 */

void __cdecl16near FUN_1000_97bc(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = 0;
  *(undefined2 *)0xa060 = 0;
  while( true ) {
    if (*(int *)0xa062 < iVar1) {
      return;
    }
    if (((*(char *)(iVar1 + 0x7a94) == '\'') || (*(char *)(iVar1 + 0x7a94) == ',')) ||
       (*(char *)(iVar1 + 0x7a94) == '-')) {
      iVar1 = iVar1 + 1;
    }
    if (*(char *)(iVar1 + 0x7a94) == '_') break;
    if (*(int *)0xa062 < iVar1) {
      return;
    }
    *(undefined1 *)(param_1 + *(int *)0xa060 + 0x51e) = *(undefined1 *)(iVar1 + 0x7a94);
    iVar1 = iVar1 + 1;
    *(int *)0xa060 = *(int *)0xa060 + 1;
  }
  return;
}



/* 0x1980e ev_6ce47b8a72106bcc08f3f2b258be13d92a90070a9f06557a150eacd082226aa9 */

undefined2 __cdecl16near FUN_1000_980e(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_2d [41];
  int local_4;
  
  if (*(int *)0xa086 == 2) {
    iVar3 = 0xf;
  }
  else {
    iVar3 = 0x11;
    if (*(int *)0xa086 < 4) {
      iVar3 = 0xe;
    }
  }
  if (*(int *)0xa07c != 0) {
    iVar3 = iVar3 + -2;
  }
  FUN_1000_ae2b(iVar3,10,0x15,0x46,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  if (*(int *)0xa07c != 0) {
    iVar4 = iVar3 + 1;
    iVar3 = iVar3 + 2;
    FUN_1000_f7da(iVar4,0xc);
    uVar2 = 0x9072;
    if (*(int *)0xa07e != 0) {
      uVar2 = *(undefined2 *)0x6d5;
    }
    FUN_1000_f6a4(0x81cf,*(int *)0xa07e + 1,uVar2);
    if (1 < *(int *)0xa086) {
      FUN_1000_f6a4(0x81dd,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                    *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
    }
  }
  iVar4 = *(int *)0xa086;
  if (iVar4 == 1) {
    FUN_1000_af51(0x81ef,0xffff,iVar3,10,iVar3 + 5,0x46,0,0);
  }
  else if (iVar4 == 2) {
    FUN_1000_af51(0x82ac,0xffff,iVar3,10,iVar3 + 4,0x46,0,0);
  }
  else if (iVar4 == 3) {
    FUN_1000_af51(0x8356,0xffff,iVar3,10,iVar3 + 5,0x46,0,0);
  }
  else {
    FUN_1000_af51(0x840e,0xffff,iVar3,10,iVar3 + 2,0x46,0,0);
  }
  *(undefined2 *)0xa058 = 0;
  *(undefined2 *)0xa05e = 0;
  *(undefined2 *)0xa074 = 0;
  *(undefined2 *)0xa066 = 0;
  *(undefined2 *)0xa06e = 0;
  *(undefined2 *)0xa078 = 0;
  *(undefined2 *)0xa076 = 0;
  *(undefined2 *)0xa06c = 0;
  for (iVar3 = 0; iVar3 < 0x50; iVar3 = iVar3 + 1) {
    if (*(char *)(*(int *)0xa07e * 0x50 + param_1 + iVar3 + 0x574) != '\0') {
      iVar4 = *(int *)0xa06c;
      *(int *)0xa06c = *(int *)0xa06c + 1;
      *(undefined1 *)(iVar4 + param_1 + 0x614) = (char)iVar3;
    }
  }
  if (2 < *(int *)0xa05a) {
    *(int *)0xa05a = *(int *)0xa05a + -1;
  }
  if ((3 < *(int *)0xa086) && (6 < *(int *)0xa05c)) {
    *(int *)0xa05c = *(int *)0xa05c + -1;
  }
  FUN_1000_97bc(param_1);
  for (iVar3 = 0; iVar3 < 0x5a; iVar3 = iVar3 + 1) {
    *(undefined1 *)(param_1 + iVar3 + 0x168) = 0;
    *(undefined1 *)(param_1 + iVar3 + 0x21c) = 0;
  }
  *(undefined2 *)0x9d4e = 1;
  do {
    FUN_1000_639e(local_2d,0x28,0x618a);
    if (*(char *)0x90af != '\a') break;
    iVar3 = FUN_1000_e677(local_2d,0x65);
  } while (iVar3 != 0);
  local_4 = 0;
  iVar3 = 0;
  do {
    if (0x27 < iVar3) {
      FUN_1000_f7da(0x14,0x25);
      FUN_1000_bd1f();
      FUN_1000_f6a4(0x8426,*(undefined2 *)0xa086);
      FUN_1000_f7da(0x18,0x20);
      FUN_1000_2612(0x101e,1);
      iVar3 = FUN_1000_f831();
      if (iVar3 == 0x1b) {
        uVar2 = 0xffff;
      }
      else {
        uVar2 = FUN_1000_947e(param_1);
      }
      return uVar2;
    }
    *(undefined1 *)(param_1 + iVar3 + 0x4f6) = 0;
    if (*(int *)0xa060 == 0) {
      FUN_1000_97bc(param_1);
    }
    iVar4 = FUN_1000_bd74(*(int *)0xa086 + 1);
    if (iVar4 == 0) {
      uVar2 = *(undefined2 *)0xa060;
      *(int *)0xa060 = *(int *)0xa060 + -1;
      iVar4 = FUN_1000_bd74(uVar2);
      *(undefined1 *)(iVar3 * 0xf + param_1 + 0x276) = *(undefined1 *)(iVar4 + param_1 + 0x51e);
      for (; iVar4 < *(int *)0xa060; iVar4 = iVar4 + 1) {
        *(undefined1 *)(param_1 + iVar4 + 0x51e) = *(undefined1 *)(param_1 + iVar4 + 0x51f);
      }
      *(undefined1 *)(param_1 + iVar3 + 0x4ce) = 1;
    }
    else {
      while ((local_2d[local_4] == ' ' ||
             ((local_2d[local_4] == '-' && (local_2d[local_4 + 1] < '!'))))) {
        local_4 = local_4 + 1;
      }
      if (local_2d[local_4] == '\0') {
        do {
          FUN_1000_639e(local_2d,0x28,0x618a);
          if (*(char *)0x90af != '\a') break;
          iVar4 = FUN_1000_e677(local_2d,0x65);
        } while (iVar4 != 0);
        local_4 = 0;
      }
      iVar4 = 0;
      while( true ) {
        if ((local_2d[local_4] < '!') || (0xe < iVar4)) break;
        *(char *)(iVar3 * 0xf + param_1 + iVar4 + 0x276) = local_2d[local_4];
        local_4 = local_4 + 1;
        iVar4 = iVar4 + 1;
      }
      *(undefined1 *)(param_1 + iVar3 + 0x4ce) = (char)iVar4;
      iVar4 = FUN_1000_bd74(2);
      if (iVar4 != 0) {
        uVar1 = FUN_1000_e793((int)*(char *)(iVar3 * 0xf + param_1 + 0x276));
        *(undefined1 *)(iVar3 * 0xf + param_1 + 0x276) = uVar1;
      }
    }
    iVar3 = iVar3 + 1;
  } while( true );
}



/* 0x19bec ev_7b2300e8538311c7d39ada56a9940ca28e285f532be90ee3252f577a587515a9 */

void __cdecl16near FUN_1000_9bec(undefined2 param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined2 unaff_DS;
  
  if (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) {
    FUN_1000_2723(0x8447);
    FUN_1000_f7da(0x18,0);
    FUN_1000_f74a();
    FUN_1000_9296(param_1);
  }
  iVar4 = FUN_1000_529a(*(int *)0xa076,*(int *)0xa076 >> 0xf,*(int *)0xa078,*(int *)0xa078 >> 0xf,
                        0x3b,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  if (iVar4 < 0x5b) {
    uVar5 = 7;
  }
  else {
    uVar5 = 8;
  }
  uVar6 = 3;
  if (*(int *)0xa07c != 0) {
    uVar6 = 2;
  }
  FUN_1000_ae2b(uVar6,0x15,uVar5);
  if (*(int *)0xa07c != 0) {
    FUN_1000_f7da(3,0x17);
    uVar5 = 0x9072;
    if (*(int *)0xa07e != 0) {
      uVar5 = *(undefined2 *)0x6d5;
    }
    FUN_1000_f6a4(0x8448,*(int *)0xa07e + 1,uVar5);
  }
  FUN_1000_f7da(4,0x17);
  FUN_1000_f6a4(0x8456,*(undefined2 *)0xa076);
  FUN_1000_f7da(5,0x17);
  FUN_1000_f6a4(0x845f,*(undefined2 *)0xa078);
  FUN_1000_f7da(6,0x17);
  FUN_1000_f6a4(0x846a,iVar4);
  if (0x5a < iVar4) {
    uVar7 = (iVar4 + -0x5a) * *(int *)0xa076;
    FUN_1000_f7da(7,0x17);
    FUN_1000_b1f3(1,1,6);
    FUN_1000_f6a4(0x8479,uVar7);
    iVar4 = *(int *)0xa07e;
    puVar1 = (uint *)(iVar4 * 4 + -0x6266);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    piVar2 = (int *)(iVar4 * 4 + -0x6264);
    *piVar2 = *piVar2 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar3,uVar7);
    FUN_1000_f7da(0,0x26);
    FUN_1000_b1f3(1,5,6);
    FUN_1000_f6a4(0x848c,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                  *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
    FUN_1000_b1f3(0,1,7);
  }
  FUN_1000_7d49();
  return;
}



/* 0x19d9a ev_aa7e9e36339c07b7aeead8ce2c8f1248bbb6adad0206edf4abb68bd244b9b2b9 */

void __cdecl16near FUN_1000_9d9a(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  for (iVar4 = 0; iVar4 < *(int *)0xa066; iVar4 = iVar4 + 1) {
    uVar3 = (uint)*(byte *)(param_1 + iVar4 + 0x6af);
    iVar2 = *(int *)(iVar4 * 2 + param_1 + 0x6c1);
    bVar1 = *(byte *)(param_1 + iVar4 + 0x6e5);
    FUN_1000_922d(uVar3 - 1,iVar2 + -1,0x20);
    FUN_1000_922d(uVar3,iVar2 + -1,0x20);
    FUN_1000_922d(uVar3,iVar2 + -2,0x20);
    FUN_1000_922d(uVar3 + 1,iVar2 + -1,0x20);
    for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
      FUN_1000_922d(uVar3 - 1,iVar2 + iVar5,0x20);
      FUN_1000_922d(uVar3,iVar2 + iVar5,0x20);
      FUN_1000_922d(uVar3 + 1,iVar2 + iVar5,0x20);
    }
    FUN_1000_922d(uVar3 - 1,iVar2 + iVar5,0x20);
    FUN_1000_922d(uVar3,iVar2 + iVar5,0x20);
    FUN_1000_922d(uVar3,iVar2 + iVar5 + 1,0x20);
    FUN_1000_922d(uVar3 + 1,iVar2 + iVar5,0x20);
  }
  *(undefined2 *)0xa066 = 0;
  return;
}



/* 0x19ecc ev_058f163dc2279e4a432637f1f4346ff5b1a6bdca1d62de9d2077ff441fa0eec1 */

void __cdecl16near FUN_1000_9ecc(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_7e47(5);
  FUN_1000_07c9(0x40,0);
  *(int *)0xa078 = *(int *)0xa078 + 1;
  iVar3 = *(int *)0xa07e * 4;
  puVar1 = (uint *)(iVar3 + -0x6266);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 - 10;
  *(int *)(iVar3 + -0x6264) = *(int *)(iVar3 + -0x6264) - (uint)(uVar2 < 10);
  if ((*(int *)(iVar3 + -0x6264) < 1) && (*(int *)(iVar3 + -0x6264) != 0)) {
    *(undefined2 *)(iVar3 + -0x6264) = 0;
    *(undefined2 *)(iVar3 + -0x6266) = 0;
  }
  FUN_1000_f7da(0,0x26);
  FUN_1000_b1f3(1,5,6);
  FUN_1000_f6a4(0x8492,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x19f66 ev_92323194178dd45c98488c3fd14981f80dd09f6c37a01ddc5e68884ac93b4959 */

undefined2 __cdecl16near FUN_1000_9f66(int param_1)

{
  char *pcVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  undefined2 unaff_DS;
  
  while( true ) {
    do {
      iVar4 = FUN_1000_f84a();
      if (iVar4 < 1) {
        return 0;
      }
      cVar3 = FUN_1000_f831();
    } while (((cVar3 == '\r') || (cVar3 == ' ')) && (*(int *)0xa06e == 0));
    if ((cVar3 == '\x1b') || (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0)) break;
    if (*(int *)0xa06e == 0) {
      iVar4 = FUN_1000_e677(0x8498,(int)cVar3);
      if (((iVar4 == 0) && (' ' < cVar3)) &&
         ((cVar3 < '~' &&
          ((iVar4 = FUN_1000_91df((int)cVar3), *(char *)(iVar4 + param_1 + 0x21c) != '\0' &&
           (*(char *)(param_1 + iVar4 + 0x168) == '\0')))))) {
        uVar6 = (uint)*(byte *)(param_1 + iVar4 + 0x1c2);
        *(uint *)0xa070 = uVar6;
        *(undefined1 *)(uVar6 + param_1 + 0x4f6) = 1;
        *(int *)0xa076 = *(int *)0xa076 + 1;
        FUN_1000_b1f3(1,1,2);
        FUN_1000_4e79(*(undefined1 *)(param_1 + iVar4),*(undefined2 *)(iVar4 * 2 + param_1 + 0x5a),
                      (int)cVar3);
        if (*(byte *)(param_1 + *(int *)0xa070 + 0x4ce) < 2) {
          FUN_1000_b1f3(0,1,4);
          uVar2 = *(undefined2 *)(iVar4 * 2 + param_1 + 0x5a);
          *(undefined1 *)(param_1 + iVar4 + 0x168) = 0x15;
          FUN_1000_4e79(0x15,uVar2,0x18);
        }
        else {
          *(int *)0xa072 = iVar4;
          *(undefined2 *)0xa06e = 1;
        }
        FUN_1000_b1f3(0,1,7);
      }
      else {
        FUN_1000_9ecc();
      }
    }
    else if (*(char *)(*(int *)0xa070 * 0xf + param_1 + *(int *)0xa06e + 0x276) == cVar3) {
      FUN_1000_b1f3(1,1,2);
      FUN_1000_922d(*(undefined1 *)(param_1 + *(int *)0xa072),
                    *(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) + *(int *)0xa06e,(int)cVar3);
      *(int *)0xa06e = *(int *)0xa06e + 1;
      *(int *)0xa076 = *(int *)0xa076 + 1;
      iVar4 = *(int *)0xa070;
      pcVar1 = (char *)(param_1 + iVar4 + 0x4f6);
      *pcVar1 = *pcVar1 + '\x01';
      if ((uint)*(byte *)(param_1 + iVar4 + 0x4ce) == *(uint *)0xa06e) {
        FUN_1000_b1f3(0,1,4);
        pbVar5 = (byte *)(param_1 + *(int *)0xa072);
        if (pbVar5[0x21c] == 3) {
          iVar4 = (*(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) - (0x17 - *pbVar5 >> 1)) +
                  *(int *)0xa06e / 2;
          *(int *)0xa074 = iVar4;
        }
        else {
          iVar4 = *(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) + *(int *)0xa06e / 2;
        }
        pbVar5[0x168] = 0x15;
        FUN_1000_4e79(0x15,iVar4,0x18);
        *(undefined2 *)0xa06e = 0;
      }
      FUN_1000_b1f3(0,1,7);
    }
    else {
      for (uVar6 = 0; uVar6 < *(byte *)(param_1 + *(int *)0xa070 + 0x4f6); uVar6 = uVar6 + 1) {
        FUN_1000_922d(*(undefined1 *)(param_1 + *(int *)0xa072),
                      *(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) + uVar6,
                      (int)*(char *)(*(int *)0xa070 * 0xf + param_1 + uVar6 + 0x276));
      }
      *(undefined2 *)0xa06e = 0;
      *(undefined1 *)(param_1 + *(int *)0xa070 + 0x4f6) = 0;
      FUN_1000_9ecc();
    }
  }
  return 0xffff;
}



/* 0x1a22a ev_b68a9b46e3702cd449ff49654c8acdd5f681147fb94f9522aaa9c31690ff0018 */

void __cdecl16near FUN_1000_a22a(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 unaff_DS;
  
  FUN_1000_b1f3(0,4,6);
  bVar3 = *(byte *)(param_4 + param_2);
  *(byte *)(param_4 + *(int *)0xa066 + 0x6af) = bVar3;
  uVar4 = (uint)bVar3;
  iVar8 = *(int *)(param_2 * 2 + param_4 + 0x5a);
  *(int *)(*(int *)0xa066 * 2 + param_4 + 0x6c1) = iVar8;
  iVar5 = param_3 + iVar8;
  FUN_1000_922d(uVar4 - 1,iVar8 + -1,0x5c);
  FUN_1000_922d(uVar4,iVar8 + -1,0xc4);
  FUN_1000_922d(uVar4,iVar8 + -2,0xc4);
  FUN_1000_922d(uVar4 + 1,iVar8 + -1,0x2f);
  for (; iVar8 < iVar5; iVar8 = iVar8 + 1) {
    FUN_1000_922d(uVar4 - 1,iVar8,0xb3);
    if (param_1 == 0) {
      FUN_1000_b1f3(0,1,7);
      FUN_1000_4e79(uVar4,iVar8,0x20);
      FUN_1000_4e79(uVar4 + 1,iVar8,0x20);
      FUN_1000_4e79(uVar4 + 2,iVar8,0x20);
      FUN_1000_b1f3(0,4,6);
    }
    else {
      FUN_1000_922d(uVar4,iVar8,0xc5);
      FUN_1000_922d(uVar4 + 1,iVar8,0xb3);
    }
  }
  FUN_1000_922d(uVar4 - 1,iVar8,0x2f);
  FUN_1000_922d(uVar4,iVar8,0xc4);
  FUN_1000_922d(uVar4,iVar8 + 1,0xc4);
  FUN_1000_922d(uVar4 + 1,iVar8,0x5c);
  uVar4 = (uint)*(byte *)(param_4 + param_2 + 0x1c2);
  if (param_1 == 0) {
    iVar8 = *(int *)0xa07e * 4;
    puVar1 = (uint *)(iVar8 + -0x6266);
    uVar7 = *puVar1;
    *puVar1 = *puVar1 - 10;
    *(int *)(iVar8 + -0x6264) = *(int *)(iVar8 + -0x6264) - (uint)(uVar7 < 10);
    if ((*(int *)(iVar8 + -0x6264) < 1) && (*(int *)(iVar8 + -0x6264) != 0)) {
      *(undefined2 *)(iVar8 + -0x6264) = 0;
      *(undefined2 *)(iVar8 + -0x6266) = 0;
    }
    if (uVar4 == *(uint *)0xa070) {
      *(undefined2 *)0xa06e = 0;
    }
  }
  else if (param_3 < 2) {
    if (*(char *)(param_4 + param_2 + 0x21c) == '\x01') {
      uVar7 = 10;
    }
    else {
      uVar7 = 0x32;
    }
    iVar8 = *(int *)0xa07e;
    puVar1 = (uint *)(iVar8 * 4 + -0x6266);
    uVar6 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    piVar2 = (int *)(iVar8 * 4 + -0x6264);
    *piVar2 = *piVar2 + (uint)CARRY2(uVar6,uVar7);
  }
  else {
    iVar8 = (param_3 + 1) * param_3;
    uVar7 = iVar8 * 5;
    if (*(char *)(param_4 + param_2 + 0x21c) == '\x01') {
      iVar8 = *(int *)0xa07e;
      puVar1 = (uint *)(iVar8 * 4 + -0x6266);
      uVar6 = *puVar1;
      *puVar1 = *puVar1 + uVar7;
      piVar2 = (int *)(iVar8 * 4 + -0x6264);
      *piVar2 = *piVar2 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar6,uVar7);
    }
    else {
      uVar6 = iVar8 * 10;
      iVar8 = *(int *)0xa07e;
      puVar1 = (uint *)(iVar8 * 4 + -0x6266);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 + uVar6;
      piVar2 = (int *)(iVar8 * 4 + -0x6264);
      *piVar2 = *piVar2 + ((int)uVar6 >> 0xf) + (uint)CARRY2(uVar7,uVar6);
    }
  }
  if (1 < *(byte *)(param_4 + param_2 + 0x21c)) {
    *(undefined2 *)0xa074 = 0;
    FUN_1000_7d49();
  }
  *(undefined1 *)(param_4 + param_2 + 0x21c) = 0;
  *(undefined1 *)(param_4 + param_2 + 0x168) = 0;
  iVar8 = param_4 + uVar4;
  *(undefined1 *)(iVar8 + 0x4ce) = 0;
  *(undefined1 *)(iVar8 + 0x4f6) = 0;
  iVar8 = *(int *)0xa066;
  *(int *)0xa066 = *(int *)0xa066 + 1;
  *(undefined1 *)(iVar8 + param_4 + 0x6e5) = (char)param_3;
  if (param_1 == 0) {
    FUN_1000_7e47(2);
    iVar10 = 0;
    for (iVar8 = *(int *)(param_2 * 2 + param_4 + 0x5a); iVar8 < iVar5; iVar8 = iVar8 + 1) {
      iVar9 = *(int *)0xa07e * 0x50 + param_4 + iVar8;
      if (*(char *)(iVar9 + 0x574) != '\0') {
        iVar10 = iVar10 + 1;
        *(undefined1 *)(iVar9 + 0x574) = 0;
      }
    }
    piVar2 = (int *)(*(int *)0xa07e * 2 + -0x5f98);
    *piVar2 = *piVar2 - iVar10;
  }
  else {
    FUN_1000_7e47(3);
  }
  FUN_1000_f7da(0,0x26);
  FUN_1000_b1f3(1,5,6);
  FUN_1000_f6a4(0x849c,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
  FUN_1000_b1f3(0,1,7);
  *(int *)0xa05e = *(int *)0xa05e + -1;
  return;
}



/* 0x1a541 ev_d30319a8dc9c3fb924ddf06e1462e3c5dffade92b4f57a1fde7a557e91b6ffeb */

void __cdecl16near FUN_1000_a541(int param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined2 unaff_DS;
  
  for (iVar9 = 0; iVar9 < 0x5a; iVar9 = iVar9 + 1) {
    iVar5 = param_1 + iVar9;
    if ((((*(char *)(iVar5 + 0x21c) == '\x02') &&
         ((uint)*(byte *)(iVar5 + 0x10e) == *(int *)0xa056 % 3)) ||
        ((*(char *)(iVar5 + 0x21c) == '\x03' && (*(int *)0xa056 % 2 != 0)))) ||
       ((*(char *)(iVar5 + 0x21c) == '\x01' &&
        ((uint)*(byte *)(iVar5 + 0x10e) == *(int *)0xa056 % *(int *)0xa05c)))) {
      uVar10 = (uint)*(byte *)(iVar5 + 0x1c2);
      for (uVar11 = 0; uVar11 < *(byte *)(param_1 + uVar10 + 0x4ce); uVar11 = uVar11 + 1) {
        FUN_1000_922d(*(undefined1 *)(param_1 + iVar9),*(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar11
                      ,0x20);
        if (uVar11 < *(byte *)(param_1 + uVar10 + 0x4f6)) {
          FUN_1000_b1f3(1,1,2);
        }
        else if (1 < *(byte *)(param_1 + iVar9 + 0x21c)) {
          FUN_1000_b1f3(0,1,6);
        }
        if (*(char *)(param_1 + iVar9 + 0x21c) == '\x03') {
          FUN_1000_922d(*(undefined1 *)(param_1 + iVar9),
                        *(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar11 + -1,
                        (int)*(char *)(uVar10 * 0xf + param_1 + uVar11 + 0x276));
        }
        else {
          FUN_1000_922d(*(byte *)(param_1 + iVar9) + 1,*(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar11
                        ,(int)*(char *)(uVar10 * 0xf + param_1 + uVar11 + 0x276));
        }
        FUN_1000_b1f3(0,1,7);
      }
      if (((char *)(param_1 + iVar9))[0x21c] == '\x03') {
        piVar2 = (int *)(iVar9 * 2 + param_1 + 0x5a);
        *piVar2 = *piVar2 + -1;
      }
      else {
        pcVar1 = (char *)(param_1 + iVar9);
        *pcVar1 = *pcVar1 + '\x01';
      }
      pbVar8 = (byte *)(param_1 + iVar9);
      if ((pbVar8[0x168] != 0) && (pbVar8[0x168] <= *pbVar8)) {
        FUN_1000_a22a(1,iVar9,*(undefined1 *)(param_1 + uVar10 + 0x4ce),param_1);
      }
      if (((*(char *)(param_1 + iVar9 + 0x21c) == '\x03') &&
          (*(char *)(param_1 + iVar9 + 0x168) == '\0')) &&
         ((int)(*(int *)(iVar9 * 2 + param_1 + 0x5a) + (uint)*(byte *)(param_1 + uVar10 + 0x4ce)) <
          0)) {
        *(undefined1 *)(param_1 + uVar10 + 0x4f6) = 0;
        *(undefined1 *)(param_1 + uVar10 + 0x4ce) = 0;
        *(undefined1 *)(param_1 + iVar9 + 0x168) = 0;
        *(undefined1 *)(param_1 + iVar9 + 0x21c) = 0;
        if (uVar10 == *(uint *)0xa070) {
          *(undefined2 *)0xa06e = 0;
        }
        *(int *)0xa05e = *(int *)0xa05e + -1;
        FUN_1000_7d49();
        *(undefined2 *)0xa074 = 0;
      }
    }
    uVar10 = (uint)*(byte *)((uint)*(byte *)(param_1 + iVar9 + 0x1c2) + param_1 + 0x4ce);
    iVar5 = param_1 + iVar9;
    if (*(char *)(iVar5 + 0x168) != '\0') {
      iVar7 = *(int *)0xa074;
      if (*(char *)(iVar5 + 0x21c) != '\x03') {
        iVar7 = *(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar10 / 2;
      }
      uVar3 = *(undefined1 *)(iVar5 + 0x168);
      *(char *)(iVar5 + 0x168) = *(char *)(iVar5 + 0x168) + -1;
      FUN_1000_4e79(uVar3,iVar7,0x20);
      FUN_1000_b1f3(0,1,4);
      FUN_1000_4e79(*(undefined1 *)(param_1 + iVar9 + 0x168),iVar7,0x18);
      FUN_1000_b1f3(0,1,7);
      if (((byte *)(param_1 + iVar9))[0x168] <= *(byte *)(param_1 + iVar9)) {
        FUN_1000_a22a(1,iVar9,uVar10,param_1);
      }
    }
    if ((((byte *)(param_1 + iVar9))[0x21c] != 0) && (0x15 < *(byte *)(param_1 + iVar9))) {
      FUN_1000_a22a(0,iVar9,uVar10,param_1);
    }
  }
  iVar9 = FUN_1000_bd74(*(undefined2 *)0xa05a);
  if ((((iVar9 == 0) || ((*(int *)0xa05e < 5 && (iVar9 = FUN_1000_bd74(2), iVar9 != 0)))) &&
      (*(int *)0xa064 < 0x28)) &&
     ((*(int *)0xa058 == 0 && (*(int *)(*(int *)0xa07e * 2 + -0x5f98) != 0)))) {
    iVar9 = FUN_1000_91df((int)*(char *)(*(int *)0xa064 * 0xf + param_1 + 0x276));
    if (*(char *)(iVar9 + param_1 + 0x21c) != '\0') {
      for (iVar9 = 0; iVar9 < 10; iVar9 = iVar9 + 1) {
        iVar5 = FUN_1000_bd74(*(int *)0xa062 + 1);
        cVar4 = *(char *)(iVar5 + 0x7a94);
        iVar5 = FUN_1000_91df((int)cVar4);
        if ((*(char *)(iVar5 + param_1 + 0x21c) == '\0') &&
           (iVar5 = FUN_1000_e677(0x84a2,(int)cVar4), iVar5 == 0)) {
          *(char *)(*(int *)0xa064 * 0xf + param_1 + 0x276) = cVar4;
          *(undefined1 *)(param_1 + *(int *)0xa064 + 0x4ce) = 1;
          break;
        }
      }
    }
    iVar9 = FUN_1000_91df((int)*(char *)(*(int *)0xa064 * 0xf + param_1 + 0x276));
    if (*(char *)(iVar9 + param_1 + 0x21c) == '\0') {
      *(undefined1 *)(param_1 + iVar9 + 0x1c2) = (char)*(undefined2 *)0xa064;
      *(undefined1 *)(param_1 + iVar9 + 0x21c) = 1;
      *(undefined1 *)(param_1 + iVar9) = 2;
      if (*(char *)(param_1 + *(int *)0xa064 + 0x4ce) == '\x01') {
        iVar5 = FUN_1000_bd74(5);
        if (((iVar5 == 0) && (*(int *)0xa074 == 0)) && (1 < *(int *)0xa086)) {
          *(undefined1 *)(param_1 + iVar9 + 0x21c) = 2;
          *(undefined2 *)0xa074 = 1;
          FUN_1000_7e47(0);
        }
      }
      else if (((*(int *)0xa074 == 0) && (2 < *(int *)0xa086)) &&
              (iVar5 = FUN_1000_bd74(5), iVar5 == 0)) {
        *(undefined2 *)0xa074 = 1;
        *(undefined1 *)(param_1 + iVar9 + 0x21c) = 3;
        cVar4 = FUN_1000_bd74(0x12);
        *(char *)(param_1 + iVar9) = cVar4 + '\x03';
        *(undefined2 *)(iVar9 * 2 + param_1 + 0x5a) = 0x4e;
        FUN_1000_7e47(1);
      }
      if (*(char *)(param_1 + iVar9 + 0x21c) != '\x03') {
        iVar7 = 0x50 - (uint)*(byte *)(param_1 + *(int *)0xa064 + 0x4ce);
        iVar5 = FUN_1000_bd74(2);
        if (iVar5 == 0) {
          iVar5 = FUN_1000_bd74(*(undefined2 *)0xa06c);
          uVar10 = (uint)*(byte *)(iVar5 + param_1 + 0x614);
          *(uint *)(iVar9 * 2 + param_1 + 0x5a) = uVar10;
          if (iVar7 < (int)uVar10) {
            *(int *)(iVar9 * 2 + param_1 + 0x5a) = iVar7;
          }
        }
        else {
          uVar6 = FUN_1000_bd74(iVar7);
          *(undefined2 *)(iVar9 * 2 + param_1 + 0x5a) = uVar6;
        }
      }
      if (1 < *(byte *)(param_1 + iVar9 + 0x21c)) {
        FUN_1000_b1f3(0,1,6);
      }
      for (uVar10 = 0; uVar10 < *(byte *)(param_1 + *(int *)0xa064 + 0x4ce); uVar10 = uVar10 + 1) {
        FUN_1000_922d(*(undefined1 *)(param_1 + iVar9),*(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar10
                      ,(int)*(char *)(*(int *)0xa064 * 0xf + param_1 + uVar10 + 0x276));
      }
      FUN_1000_b1f3(0,1,7);
      if (*(char *)(param_1 + iVar9 + 0x21c) == '\x02') {
        *(undefined1 *)(param_1 + iVar9 + 0x10e) = (char)(*(int *)0xa056 % 3);
      }
      else {
        *(undefined1 *)(param_1 + iVar9 + 0x10e) = (char)(*(int *)0xa056 % *(int *)0xa05c);
      }
      *(int *)0xa058 = *(int *)0xa05c + 1;
      *(int *)0xa05e = *(int *)0xa05e + 1;
      *(int *)0xa064 = *(int *)0xa064 + 1;
    }
  }
  if (*(int *)0xa058 != 0) {
    *(int *)0xa058 = *(int *)0xa058 + -1;
  }
  *(int *)0xa056 = *(int *)0xa056 + 1;
  return;
}



/* 0x1ab36 ev_97162e6c09b9bc21a3ea6334e0f04cb2f106c876fa805ac59704d3b4059a3ebd */

/* WARNING: Removing unreachable block (ram,0x0001ab5b) */
/* WARNING: Removing unreachable block (ram,0x0001ac00) */
/* WARNING: Removing unreachable block (ram,0x0001ac0c) */

void __cdecl16near FUN_1000_ab36(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  long lVar4;
  undefined1 local_701 [1636];
  undefined1 local_9d [147];
  undefined4 local_a;
  undefined4 local_6;
  
  iVar1 = FUN_1000_9538(local_701);
  if (iVar1 == -1) {
    FUN_1000_7d49();
  }
  else {
    while( true ) {
      iVar1 = FUN_1000_980e(local_701);
      if (iVar1 == -1) break;
      lVar4 = FUN_1000_c1c4();
      *(undefined2 *)0xa064 = 0;
      *(undefined2 *)0xa056 = 0;
      local_6 = lVar4;
      lVar4 = local_a;
      while( true ) {
        local_a = lVar4;
        if ((*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) ||
           ((*(int *)0xa05e == 0 && (0x27 < *(int *)0xa064)))) goto LAB_1000_ac2f;
        iVar1 = FUN_1000_9f66(local_701);
        if (iVar1 == -1) break;
        lVar4 = FUN_1000_c1c4();
        if ((local_6 < lVar4) || (lVar4 < local_6)) {
          local_a = lVar4;
          lVar4 = FUN_1000_c1c4();
          local_6 = lVar4;
          FUN_1000_a541(local_701);
          FUN_1000_9d9a(local_701);
          lVar4 = local_a;
        }
      }
      *(undefined2 *)(*(int *)0xa07e * 2 + -0x5f98) = 0;
LAB_1000_ac2f:
      FUN_1000_9bec(local_701);
      if (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) {
        FUN_1000_f7da(9,0x15);
        if (*(int *)0xa07c != 0) {
          FUN_1000_f6a4(0x84a7,*(int *)0xa07e + 1);
        }
        uVar2 = 0x9072;
        if (*(int *)0xa07e != 0) {
          uVar2 = *(undefined2 *)0x6d5;
        }
        FUN_1000_f6a4(0x84b3,uVar2);
        FUN_1000_768e(*(undefined2 *)0xa07a,*(undefined2 *)0xa07e);
        FUN_1000_bd1f();
      }
      if ((*(int *)0xa07c == 0) || (*(int *)((uint)(*(int *)0xa07e == 0) * 2 + -0x5f98) == 0)) {
        if (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0) {
          if (*(int *)0xa07c != 0) {
            FUN_1000_f7da(10,0x15);
            FUN_1000_f6a4(0x84c9,0x9072,*(undefined2 *)0x9d9a,*(undefined2 *)0x9d9c);
            FUN_1000_f7da(0xb,0x15);
            FUN_1000_f6a4(0x84db,*(undefined2 *)0x6d5,*(undefined2 *)0x9d9e,*(undefined2 *)0x9da0);
          }
          FUN_1000_787b(*(undefined2 *)0xa07a,0xd);
          FUN_1000_2612(0x183,0);
          FUN_1000_f831();
          FUN_1000_2692(0x8008,0x843);
          FUN_1000_bd1f();
          iVar1 = FUN_1000_b21d(3,0x14,0x7ff0,0,0,0x102e);
          if (iVar1 == -1) {
            FUN_1000_e74e(0x17a0,0x1006);
          }
          else if (iVar1 == 0) {
            FUN_1000_e74e(0x17a0,0x84ed);
          }
          else if (iVar1 == 1) {
            FUN_1000_e74e(0x17a0,0x84ef);
          }
          else if (iVar1 == 2) {
            FUN_1000_e74e(0x17a0,0x1004);
          }
          goto LAB_1000_add2;
        }
        *(int *)0xa086 = *(int *)0xa086 + 1;
      }
      else {
        if (*(int *)0xa07e != 0) {
          *(int *)0xa086 = *(int *)0xa086 + 1;
        }
        *(uint *)0xa07e = (uint)(*(int *)0xa07e == 0);
      }
    }
    FUN_1000_768e(*(undefined2 *)0xa07a,0);
    if (*(int *)0xa07c != 0) {
      FUN_1000_768e(*(undefined2 *)0xa07a,1);
    }
    FUN_1000_e74e(0x17a0,0x1004);
LAB_1000_add2:
    *(undefined1 *)0x90af = (char)*(undefined2 *)0xa080;
    *(undefined1 *)0x90ba = (char)*(undefined2 *)0xa082;
    *(undefined1 *)0x90ae = (char)*(undefined2 *)0xa084;
    if (*(int *)0xa07a != 0) {
      for (iVar1 = 0; iVar1 < 0x40; iVar1 = iVar1 + 1) {
        *(undefined1 *)(iVar1 + -0x6f45) = local_9d[iVar1];
      }
    }
    *(undefined2 *)0x9d36 = 0;
    for (uVar3 = 0; uVar3 < *(byte *)0x90ae + 4; uVar3 = uVar3 + 1) {
      iVar1 = FUN_1000_722b((int)*(char *)(uVar3 + 0x7aee));
      *(int *)0x9d36 = *(int *)0x9d36 + (uint)*(byte *)(iVar1 + -0x6f45);
    }
  }
  return;
}



/* 0x1ae2b ev_aa248dc9caa0da2a681ff11c5034bcf8c23942cf67a697d2ad211d996ca9b6a9 */

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



/* 0x1af51 ev_6356c07c375ebdd63a33e76b4c8fe54bd3dbe8b9620f3224eacfebb8ca47c189 */

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



/* 0x1b0a9 ev_ab84f6590602eafe990802da1f190ee867328cf8565a8a81bd713978b696e09d */

void __cdecl16near FUN_1000_b0a9(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = *(int *)(unaff_BP + 4);
  if (iVar1 == -1) {
    FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(int *)(unaff_BP + 10) + 2);
  }
  else if (iVar1 == 0) {
    iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 6));
    FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),
                  (((*(int *)(unaff_BP + 0xc) - *(int *)(unaff_BP + 10)) + -3) - iVar1) / 2 +
                  *(int *)(unaff_BP + 10) + 2);
  }
  else if (iVar1 == 1) {
    iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 6));
    FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),(*(int *)(unaff_BP + 0xc) + -1) - iVar1);
  }
  FUN_1000_f6a4(0x8510,*(undefined2 *)(unaff_BP + 6));
  return;
}



/* 0x1b12a ev_88073c1ce6673bf2fe7bb77d5fe0b84bda32485950c30c73ecc067813333b22f */

void __cdecl16near FUN_1000_b12a(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_ae2b(*(undefined1 *)(unaff_BP + 6),*(undefined1 *)(unaff_BP + 8),
                *(undefined1 *)(unaff_BP + 10),*(undefined1 *)(unaff_BP + 0xc),1,0xcd,0xba,0xc9,0xbb
                ,200,0xbc);
  FUN_1000_af51(*(undefined2 *)(unaff_BP + 4),0xffff,*(undefined1 *)(unaff_BP + 6),
                *(undefined1 *)(unaff_BP + 8),*(undefined1 *)(unaff_BP + 10),
                *(undefined1 *)(unaff_BP + 0xc),0,0);
  return;
}



/* 0x1b194 ev_a41c97bd1342e62b4e05a3093098ff498f607b4eedef58f5e4205647cbed4c1c */

void __cdecl16near FUN_1000_b194(void)

{
  uint uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = (char)(0x19 - *(byte *)(unaff_BP + 8) >> 1);
  uVar1 = 0x50 - *(byte *)(unaff_BP + 6) >> 1;
  *(undefined1 *)(unaff_BP + -2) = (char)uVar1;
  FUN_1000_b12a(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),
                *(undefined1 *)(unaff_BP + -2),
                (uint)*(byte *)(unaff_BP + -1) + (uint)*(byte *)(unaff_BP + 8) + -1,
                (uVar1 & 0xff) + (uint)*(byte *)(unaff_BP + 6) + -1);
  return;
}



/* 0x1b1f3 ev_0f1ef60b9648e8abd6675cec6f76cd3d786cfa17ddf5c8e700ed37dbf03aa67f */

void __cdecl16near FUN_1000_b1f3(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0x906a == '\0') {
    FUN_1000_f7c2(*(undefined2 *)(unaff_BP + 4));
  }
  else {
    FUN_1000_f6bf(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),1,0);
  }
  return;
}



/* 0x1b21d ev_3b447d68835afccb713cf7080ac3626a3a38bad5ebd4ae37314a6726e2d4b971 */

undefined2 __cdecl16near FUN_1000_b21d(void)

{
  int *piVar1;
  int iVar2;
  int unaff_BP;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -10) = 0;
  if (*(int *)(unaff_BP + 10) < 2) {
    *(undefined2 *)(unaff_BP + 10) = 2;
  }
  *(int *)(unaff_BP + -0xc) = 0x18 - *(int *)(unaff_BP + 10);
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 0xe));
  *(int *)(unaff_BP + -2) = iVar2 / 0x45;
  *(int *)(unaff_BP + -8) = iVar2 / 0x45 + *(int *)(unaff_BP + 4) + 10;
  *(undefined2 *)(unaff_BP + -0xe) = 0;
  while ((*(int *)(unaff_BP + -0xe) < 2 && (*(int *)(unaff_BP + -0xc) < *(int *)(unaff_BP + -8)))) {
    *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + -2;
    *(int *)(unaff_BP + -10) = *(int *)(unaff_BP + -10) + 1;
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + 1;
  }
  if (*(int *)(unaff_BP + -0xc) < *(int *)(unaff_BP + -8)) {
    return *(undefined2 *)(unaff_BP + 0xc);
  }
  iVar2 = (*(int *)(unaff_BP + -0xc) - *(int *)(unaff_BP + -8)) / 2 + *(int *)(unaff_BP + 10);
  *(int *)(unaff_BP + -0xe) = iVar2;
  *(int *)(unaff_BP + -0x10) = (uint)(*(int *)(unaff_BP + -10) == 0) + iVar2;
  iVar2 = 4;
  if (*(int *)(unaff_BP + -10) != 0) {
    iVar2 = 3;
  }
  *(int *)(unaff_BP + -0x12) = (*(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -8)) - iVar2;
  *(int *)(unaff_BP + -0x14) =
       (*(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -2) + 4) - *(int *)(unaff_BP + -10);
  iVar2 = (0x4d - *(int *)(unaff_BP + 6)) / 2;
  *(int *)(unaff_BP + -6) = iVar2 / 3;
  FUN_1000_b1f3(0,1,7);
  FUN_1000_ae2b(*(undefined2 *)(unaff_BP + -0xe),*(undefined2 *)(unaff_BP + -6),
                *(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -8) + -1,
                0x50 - *(int *)(unaff_BP + -6),0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_b1f3(0,1,7);
  FUN_1000_af51(*(undefined2 *)(unaff_BP + 0xe),0xffff,*(undefined2 *)(unaff_BP + -0x10),
                *(int *)(unaff_BP + -6) + 2,0x18,0x4e - *(int *)(unaff_BP + -6),0,0);
  FUN_1000_f6a4(0x8513);
  FUN_1000_af51(0x8516,1,*(undefined2 *)(unaff_BP + -0x12),*(int *)(unaff_BP + -6) + 2,0x18,
                0x4e - *(int *)(unaff_BP + -6),0,0);
  FUN_1000_b1f3(0,2,7);
  FUN_1000_ae2b(*(undefined2 *)(unaff_BP + -0x14),iVar2,
                *(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 4) + 1,
                iVar2 + *(int *)(unaff_BP + 6) + 2,0,0xcd,0xba,0xc9,0xbb,200,0xbc);
  FUN_1000_b1f3(0,2,1);
  for (iVar3 = 0; iVar3 < *(int *)(unaff_BP + 4); iVar3 = iVar3 + 1) {
    FUN_1000_b714(*(int *)(unaff_BP + -0x14) + iVar3 + 1,iVar2 + 1,
                  *(undefined2 *)(iVar3 * 2 + *(int *)(unaff_BP + 8)),*(undefined2 *)(unaff_BP + 6))
    ;
  }
  FUN_1000_b1f3(1,1,2);
  FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                *(undefined2 *)(unaff_BP + 6));
  FUN_1000_b1f3(0,1,7);
LAB_1000_b459:
  do {
    while( true ) {
      while( true ) {
        iVar3 = FUN_1000_f831();
        *(int *)(unaff_BP + -4) = iVar3;
        if (iVar3 == 0xd) {
          FUN_1000_b1f3(0,1,7);
          return *(undefined2 *)(unaff_BP + 0xc);
        }
        if (iVar3 != 0x1b) break;
        if (*(char *)0x2 != '\0') {
          FUN_1000_b1f3(0,1,7);
          return 0xffff;
        }
        FUN_1000_7e47(5);
      }
      if (iVar3 != 0x20) break;
LAB_1000_b4fe:
      FUN_1000_b1f3(0,2,1);
      FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                    *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                    *(undefined2 *)(unaff_BP + 6));
      FUN_1000_b1f3(1,1,2);
      *(int *)(unaff_BP + 0xc) = *(int *)(unaff_BP + 0xc) + 1;
      if (*(int *)(unaff_BP + 4) <= *(int *)(unaff_BP + 0xc)) {
        *(undefined2 *)(unaff_BP + 0xc) = 0;
      }
      FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                    *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                    *(undefined2 *)(unaff_BP + 6));
    }
    if (iVar3 != 200) {
      if (iVar3 == 0xd0) goto LAB_1000_b4fe;
      FUN_1000_7e47(5);
      goto LAB_1000_b459;
    }
    FUN_1000_b1f3(0,2,1);
    FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                  *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                  *(undefined2 *)(unaff_BP + 6));
    FUN_1000_b1f3(1,1,2);
    piVar1 = (int *)(unaff_BP + 0xc);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (SBORROW2(iVar3,1) != *piVar1 < 0) {
      *(int *)(unaff_BP + 0xc) = *(int *)(unaff_BP + 4) + -1;
    }
    FUN_1000_b714(*(int *)(unaff_BP + -0x14) + *(int *)(unaff_BP + 0xc) + 1,iVar2 + 1,
                  *(undefined2 *)(*(int *)(unaff_BP + 0xc) * 2 + *(int *)(unaff_BP + 8)),
                  *(undefined2 *)(unaff_BP + 6));
  } while( true );
}



/* 0x1b5b2 ev_803aa67d244b27e0c2520346a4d07261a234e64e17d322453ee3de826d0fee43 */

undefined2 __cdecl16near FUN_1000_b5b2(void)

{
  bool bVar1;
  int iVar2;
  int unaff_BP;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar3 = 0;
  *(undefined2 *)*(undefined2 *)(unaff_BP + 10) = 0;
  FUN_1000_e56c(0x1a,unaff_BP + -0x2b,0);
  iVar2 = FUN_1000_e56c(0x4e,*(undefined2 *)(unaff_BP + 4),0);
  if ((iVar2 != 0x12) && (iVar2 != 2)) {
    iVar2 = FUN_1000_e7cd(unaff_BP + -0xd,0x8540);
    *(int *)0x9070 = iVar2;
    if (iVar2 != 0) {
      bVar1 = true;
      if (*(char *)(unaff_BP + 6) != '\0') {
        iVar2 = FUN_1000_e3ce(*(undefined2 *)0x9070);
        if (iVar2 == 1) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
      }
      if (bVar1) {
        FUN_1000_e74e(*(undefined2 *)0x6d5,unaff_BP + -0xd);
      }
      FUN_1000_e913(*(undefined2 *)0x9070);
      uVar3 = (uint)bVar1;
      while ((iVar2 = FUN_1000_e56c(0x4f,*(undefined2 *)(unaff_BP + 4),0), iVar2 != 0x12 &&
             ((int)uVar3 < 8))) {
        iVar2 = FUN_1000_e7cd(unaff_BP + -0xd,0x8542);
        *(int *)0x9070 = iVar2;
        if (iVar2 != 0) {
          bVar1 = true;
          if (*(char *)(unaff_BP + 6) != '\0') {
            iVar2 = FUN_1000_e3ce(*(undefined2 *)0x9070);
            if (iVar2 == 1) {
              bVar1 = false;
            }
            else {
              bVar1 = true;
            }
          }
          uVar4 = uVar3;
          if (bVar1) {
            uVar4 = uVar3 + 1;
            FUN_1000_e74e(*(undefined2 *)(uVar3 * 2 + 0x6d5),unaff_BP + -0xd);
          }
          FUN_1000_e913(*(undefined2 *)0x9070);
          uVar3 = uVar4;
        }
      }
    }
  }
  FUN_1000_2723(0x101e);
  uVar4 = uVar3;
  if ((*(char *)(unaff_BP + 6) == '\0') && (*(char *)(unaff_BP + 8) != '\0')) {
    uVar4 = uVar3 + 1;
    FUN_1000_e74e(*(undefined2 *)(uVar3 * 2 + 0x6d5),0x8544);
  }
  if (uVar4 != 0) {
    iVar2 = FUN_1000_b21d(uVar4,0xd,0x6d5,0,0,0x854c);
    if (iVar2 == -1) {
      return 0xffff;
    }
    *(undefined2 *)*(undefined2 *)(unaff_BP + 10) = *(undefined2 *)(iVar2 * 2 + 0x6d5);
  }
  return 0;
}



/* 0x1b714 ev_c0e15a4a317d71bb8c938eae4744bb9a00fbaeb6d79727a6a3d6c653e77accba */

void __cdecl16near FUN_1000_b714(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(*(undefined2 *)(unaff_BP + 4),*(undefined2 *)(unaff_BP + 6));
  FUN_1000_f6a4(0x8597,0x20,*(undefined2 *)(unaff_BP + 8));
  for (iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 8)); iVar1 < *(int *)(unaff_BP + 10);
      iVar1 = iVar1 + 1) {
    FUN_1000_f873(0x20);
  }
  return;
}



/* 0x1b751 ev_c52fc2218d27fa1e1ebaccdaad36df4d60f556f1c06180b26553cbb0df20c5b5 */

undefined2 __cdecl16near FUN_1000_b751(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  iVar2 = iVar1 + 2;
  if (iVar1 + 2 < *(int *)(unaff_BP + 8)) {
    iVar2 = *(int *)(unaff_BP + 8);
  }
  *(int *)(unaff_BP + -6) = iVar2;
  if (iVar2 < 0x4c) {
    iVar2 = (0x4a - iVar2) / 2;
    *(int *)(unaff_BP + -2) = iVar2;
    iVar2 = (iVar2 + -2) / 3;
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) - iVar2;
    *(int *)(unaff_BP + -4) = iVar2 * 2 + *(int *)(unaff_BP + -2) + *(int *)(unaff_BP + -6) + 5;
    *(undefined2 *)(unaff_BP + -8) = 1;
  }
  else {
    *(undefined2 *)(unaff_BP + -2) = 2;
    *(undefined2 *)(unaff_BP + -4) = 0x4d;
    *(undefined2 *)(unaff_BP + -8) = 2;
  }
  FUN_1000_b1f3(0,1,7);
  FUN_1000_ae2b(9,*(undefined2 *)(unaff_BP + -2),*(int *)(unaff_BP + -8) + 0x10,
                *(undefined2 *)(unaff_BP + -4),0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_b1f3(0,1,7);
  uVar3 = 0xffff;
  if (1 < *(int *)(unaff_BP + 10)) {
    uVar3 = 0;
  }
  FUN_1000_af51(*(undefined2 *)(unaff_BP + 4),uVar3,10,*(undefined2 *)(unaff_BP + -2),
                *(int *)(unaff_BP + -8) + 0xb,*(undefined2 *)(unaff_BP + -4),0,0);
  FUN_1000_f6a4(0x859c);
  FUN_1000_af51(0x859f,1,*(int *)(unaff_BP + -8) + 0xd,*(undefined2 *)(unaff_BP + -2),
                *(int *)(unaff_BP + -8) + 0xf,*(undefined2 *)(unaff_BP + -4),0,0);
  FUN_1000_b1f3(0,1,7);
  iVar2 = FUN_1000_b8be(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 8),
                        *(int *)(unaff_BP + -8) + 0xc,
                        (((*(int *)(unaff_BP + -4) - *(int *)(unaff_BP + -2)) -
                         *(int *)(unaff_BP + 8)) + -2) / 2 + *(int *)(unaff_BP + -2) + 2,
                        *(undefined2 *)(unaff_BP + 10));
  if (iVar2 == -1) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 0x1b8be ev_05b7ce86c54beece8992e6ad087e37831d24745749bb4333d33e5f6c70848b69 */

undefined2 __cdecl16near FUN_1000_b8be(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_BP;
  int iVar4;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -6) = *(undefined2 *)(unaff_BP + 4);
  FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10));
  for (iVar4 = 1; iVar4 < *(int *)(unaff_BP + 6); iVar4 = iVar4 + 1) {
    FUN_1000_f873(0x5f);
  }
  FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10));
  FUN_1000_f8c2(0x100,0,0xb0c,0);
  *(undefined1 *)(unaff_BP + -0xf) = 0;
  iVar4 = 0;
  while ((iVar2 = FUN_1000_f831(), iVar2 != 0 &&
         ((iVar2 != 0xd ||
          (((*(int *)(unaff_BP + 0xc) != 0 || (*(int *)(unaff_BP + 4) == *(int *)(unaff_BP + -6)))
           && ((*(int *)(unaff_BP + 0xc) != 1 || (*(char *)(unaff_BP + iVar4 + -0xf) != '\b'))))))))
        ) {
    if (iVar2 == 0x1b) {
      FUN_1000_f8c2(0x100,0,0x2b0c,0);
      return 0xffff;
    }
    if (iVar2 == 8) {
      if (*(int *)(unaff_BP + -6) == *(int *)(unaff_BP + 4)) {
        FUN_1000_7e47(5);
      }
      else {
        FUN_1000_f814(unaff_BP + 8,unaff_BP + 10);
        FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(int *)(unaff_BP + 10) + -1);
        FUN_1000_f873(0x5f);
        FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(int *)(unaff_BP + 10) + -1);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
        iVar4 = iVar4 + -1;
      }
    }
    else if ((((iVar2 == 0x20) && (*(int *)(unaff_BP + -6) == *(int *)(unaff_BP + 4))) ||
             (iVar2 == 0xd)) ||
            (*(int *)(unaff_BP + -6) + *(int *)(unaff_BP + 6) + -1 == *(int *)(unaff_BP + 4))) {
      FUN_1000_7e47(5);
    }
    else {
      *(undefined2 *)(unaff_BP + -2) = 0;
      if (*(int *)(unaff_BP + 0xc) == 0) {
        if ((((((*(byte *)(iVar2 + -0x7183) & 7) == 0) && (iVar2 != 0x20)) &&
             ((iVar2 != 0x2e && (iVar2 != 0x2c)))) &&
            (((iVar2 != 0x2d || (*(int *)(unaff_BP + -6) == *(int *)(unaff_BP + 4))) &&
             (iVar2 != 0x27)))) || (0x7f < iVar2)) {
          *(undefined2 *)(unaff_BP + -2) = 1;
        }
      }
      else if (*(int *)(unaff_BP + 0xc) == 1) {
        iVar5 = iVar4 + 1;
        puVar3 = (undefined1 *)(iVar4 + unaff_BP + -0xf);
        iVar4 = iVar5;
        switch(*puVar3) {
        case 0:
        case 3:
          if ((*(byte *)(iVar2 + -0x7183) & 4) == 0) {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          else if (iVar5 == 1) {
            *(undefined1 *)(unaff_BP + -0x11) = (char)iVar2;
            *(undefined1 *)(unaff_BP + -0xe) = 1;
          }
          else {
            *(undefined1 *)(unaff_BP + -0x10) = (char)iVar2;
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 4;
          }
          break;
        case 1:
          if ((((iVar2 < 0x31) || (0x39 < iVar2)) || (*(char *)(unaff_BP + -0x11) != '0')) &&
             (((iVar2 < 0x30 || (0x32 < iVar2)) || (*(char *)(unaff_BP + -0x11) != '1')))) {
            if (((*(byte *)(iVar2 + -0x7183) & 4) == 0) && (*(char *)(unaff_BP + -0x11) != '0')) {
              *(int *)(unaff_BP + -4) = *(char *)(unaff_BP + -0x11) + -0x30;
              *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 3;
              iVar2 = 0x2d;
            }
            else {
              *(undefined2 *)(unaff_BP + -2) = 1;
            }
          }
          else {
            if (*(char *)(unaff_BP + -0x11) == '1') {
              *(int *)(unaff_BP + -4) = iVar2 + -0x26;
            }
            else {
              *(int *)(unaff_BP + -4) = iVar2 + -0x30;
            }
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 2;
          }
          break;
        case 2:
        case 5:
          if ((*(byte *)(iVar2 + -0x7183) & 4) == 0) {
            *(char *)(unaff_BP + iVar5 + -0xf) = *(char *)(unaff_BP + iVar5 + -0x10) + '\x01';
            iVar2 = 0x2d;
          }
          else {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          break;
        case 4:
          if (((*(byte *)(iVar2 + -0x7183) & 4) == 0) && (*(char *)(unaff_BP + -0x10) != '0')) {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 6;
            iVar2 = 0x2d;
          }
          else if (((((*(byte *)(iVar2 + -0x7183) & 4) == 0) ||
                    ((*(char *)(unaff_BP + -0x10) < '0' || ('2' < *(char *)(unaff_BP + -0x10))))) ||
                   ((*(char *)(unaff_BP + -0x10) == '0' && (iVar2 == 0x30)))) &&
                  (((*(char *)(unaff_BP + -0x10) != '3' ||
                    (((((iVar1 = *(int *)(unaff_BP + -4), iVar1 == 4 || (iVar1 == 6)) ||
                       (iVar1 == 9)) || (iVar1 == 0xb)) && (iVar2 == 0x31)))) ||
                   (((iVar2 != 0x30 && (iVar2 != 0x31)) || (iVar1 == 2)))))) {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          else {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 5;
          }
          break;
        case 6:
          if ((iVar2 == 0x38) || (iVar2 == 0x39)) {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 7;
          }
          else {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          break;
        case 7:
          if ((*(byte *)(iVar2 + -0x7183) & 4) == 0) {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          else {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 8;
          }
          break;
        case 8:
          *(undefined2 *)(unaff_BP + -2) = 1;
        }
      }
      if (*(int *)(unaff_BP + -2) == 0) {
        puVar3 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
        *puVar3 = (char)iVar2;
        FUN_1000_f873(iVar2);
      }
      else {
        iVar4 = iVar4 + -1;
        FUN_1000_7e47(5);
      }
    }
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  FUN_1000_f8c2(0x100,0,0x2b0c,0);
  return 0;
}



/* 0x1bbea ev_b30158ac880ecc9b6f2af3404247a1033e95d906b3751b2cd8cd70f5c69af9f2 */

int __cdecl16near FUN_1000_bbea(undefined1 param_1,byte param_2,int param_3)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  while (local_3 < param_2) {
    *(undefined1 *)((uint)local_3 + param_3) = param_1;
    local_3 = local_3 + 1;
  }
  *(undefined1 *)((uint)local_3 + param_3) = 0;
  return param_3;
}



/* 0x1bc24 ev_e9193da6e78fcdd72ad2d235c757171c72427d1df1e116e993c514e42b4f269f */

void __cdecl16near FUN_1000_bc24(int param_1)

{
  undefined1 uVar1;
  undefined2 unaff_DS;
  undefined1 local_5;
  undefined1 local_4;
  
  local_4 = 0;
  local_5 = FUN_1000_f139(param_1);
  for (; local_5 = local_5 - 1, local_4 < local_5; local_4 = local_4 + 1) {
    uVar1 = *(undefined1 *)((uint)local_4 + param_1);
    *(undefined1 *)((uint)local_4 + param_1) = *(undefined1 *)((uint)local_5 + param_1);
    *(undefined1 *)((uint)local_5 + param_1) = uVar1;
  }
  return;
}



/* 0x1bc82 ev_afd126eb44a1a09bd0b400a578a64dfed937bf6e8835ac0c100bfd2dd711b2ba */

/* WARNING: Removing unreachable block (ram,0x0001bce8) */

int __cdecl16near FUN_1000_bc82(undefined2 param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  long lVar4;
  
  iVar3 = 0;
  do {
    iVar2 = iVar3;
    cVar1 = FUN_1000_f07b();
    iVar3 = iVar2 + 1;
    *(char *)(iVar2 + param_3) = cVar1 + '0';
    lVar4 = FUN_1000_f04d();
  } while (0 < lVar4);
  if ((param_2 < 1) && (param_2 != 0)) {
    *(undefined1 *)(iVar3 + param_3) = 0x2d;
    iVar3 = iVar2 + 2;
  }
  *(undefined1 *)(param_3 + iVar3) = 0;
  FUN_1000_bc24(param_3);
  return param_3;
}



/* 0x1bd1f ev_40ec57fa2dee3203035b5a8716882e8aa14a1d46842247c391ae61524df02ce3 */

void __cdecl16near FUN_1000_bd1f(void)

{
  int iVar1;
  
  while( true ) {
    iVar1 = FUN_1000_f84a();
    if (iVar1 < 1) break;
    FUN_1000_f831();
  }
  return;
}



/* 0x1bd33 ev_bbce2478399e59db76193635a324bbd1d312fe4aeaa191b72dcc0e4a1699c67a */

undefined4 __cdecl16near FUN_1000_bd33(uint param_1,int param_2)

{
  ulong uVar1;
  uint uVar2;
  bool bVar3;
  
  if ((param_2 < 1) && (param_2 != 0)) {
    uVar1 = (ulong)param_1;
    uVar2 = (uint)(uVar1 * 2);
    bVar3 = param_1 < uVar2;
    param_1 = param_1 - uVar2;
    param_2 = (-param_2 - (int)(uVar1 * 2 >> 0x10)) - (uint)bVar3;
  }
  return CONCAT22(param_2,param_1);
}



/* 0x1bd74 ev_7951040b7e3c6a244d0b825a998db4e96923ac339bace12cea15f78e4dbf83c5 */

void __cdecl16near FUN_1000_bd74(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0x90a6 * -0x1b0b + 0x3619;
  *(int *)0x90a6 = iVar1;
  FUN_1000_f04d(param_1,param_1 >> 0xf,iVar1,0);
  FUN_1000_f04d();
  return;
}



/* 0x1bdcb ev_10ef715d3eda739f45017b3252f436aef385a6da09b937a6076a170c2301f8af */

int __cdecl16near FUN_1000_bdcb(char param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_722b((int)param_1);
  return (int)*(char *)(iVar1 + -0x7a4c);
}



/* 0x1bde2 ev_55914a5b220b4b4816c91042bf8d8092acd441528075f622c2c1e1299c790a65 */

/* WARNING: Removing unreachable block (ram,0x0001bf89) */

void __cdecl16near
FUN_1000_bde2(undefined2 param_1,undefined2 param_2,undefined2 *param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  long lVar3;
  int local_e;
  int local_a;
  
  iVar1 = FUN_1000_f04d();
  FUN_1000_f04d();
  local_e = FUN_1000_f04d();
  FUN_1000_f04d();
  lVar3 = FUN_1000_f04d();
  uVar2 = FUN_1000_f04d();
  *param_3 = uVar2;
  local_e = iVar1 * 100 + local_e;
  if (lVar3 < 10) {
    local_a = (int)lVar3 + 3;
  }
  else {
    local_a = (int)lVar3 + -9;
    local_e = local_e + 1;
  }
  *param_5 = local_e;
  *param_4 = local_a;
  return;
}



/* 0x1bfc7 ev_720fdeeef953cb8cac1e3412f80a1972ad2fd2026656e3a5b52bdc32aaf39b04 */

undefined4 __cdecl16near FUN_1000_bfc7(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0x1a;
  uVar6 = 0x431f;
  if (param_2 < 3) {
    param_3 = param_3 + -1;
  }
  lVar3 = FUN_1000_f04d(0x431f,0x1a,0x3ab1,2,param_3 / 100,param_3 / 100 >> 0xf);
  lVar4 = FUN_1000_f04d();
  lVar5 = FUN_1000_f04d();
  lVar5 = lVar3 + lVar4 + lVar5;
  uVar1 = (uint)lVar5;
  uVar2 = uVar1 + param_1;
  return CONCAT22((int)((ulong)lVar5 >> 0x10) + ((int)param_1 >> 0xf) + (uint)CARRY2(uVar1,param_1)
                  + iVar7 + (uint)CARRY2(uVar2,uVar6),uVar2 + uVar6);
}



/* 0x1c08b ev_0315da6803586daf4f78f1e1f57279c0e1276e59c8f107dfcad5872cf5eb365c */

undefined1 * __cdecl16near FUN_1000_c08b(undefined2 param_1,undefined2 param_2,undefined1 *param_3)

{
  undefined2 unaff_DS;
  
  FUN_1000_bc82(param_1,param_2,param_3);
  if (param_3[1] == '\0') {
    param_3[2] = 0;
    param_3[1] = *param_3;
    *param_3 = 0x30;
  }
  return param_3;
}



/* 0x1c0c6 ev_72ba5ff8f534a64f40a7e592ad6f3c78ad8fa19cc33a630ebe2bc24a5036dd56 */

void FUN_1000_c0c6(undefined2 param_1,undefined2 param_2,int param_3)

{
  undefined2 unaff_DS;
  undefined1 local_8 [2];
  int local_6;
  int local_4;
  
  FUN_1000_bde2(param_1,param_2,&local_4,&local_6,local_8);
  FUN_1000_c08b(local_6,local_6 >> 0xf,param_3);
  *(undefined1 *)(param_3 + 2) = 0x2d;
  FUN_1000_c08b(local_4,local_4 >> 0xf,param_3 + 3);
  *(undefined1 *)(param_3 + 5) = 0x2d;
  FUN_1f8e_005b();
  return;
}



/* 0x1c121 ev_2f50c6b949312a2eb6454f8844d012f97545582aa620b4a7edf1c87e7a645740 */

undefined2 __cdecl16near FUN_1000_c121(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_c08b();
  return *(undefined2 *)(unaff_BP + 8);
}



/* 0x1c131 ev_15fdc8a5a8c3459a5293224691ef8bd04cae52c3475be59ed3960f68bf9d2941 */

void __cdecl16near FUN_1000_c131(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  for (iVar2 = 1; *(char *)(param_1 + iVar2) != '-'; iVar2 = iVar2 + 1) {
  }
  *(undefined1 *)(param_1 + iVar2) = 0;
  for (iVar3 = iVar2 + 1; *(char *)(param_1 + iVar3) != '-'; iVar3 = iVar3 + 1) {
  }
  *(undefined1 *)(param_1 + iVar3) = 0;
  iVar3 = FUN_1000_e469(param_1 + iVar3 + 1);
  uVar1 = FUN_1000_e469(param_1,iVar3 + 0x76c);
  uVar1 = FUN_1000_e469(param_1 + iVar2 + 1,uVar1);
  FUN_1000_bfc7(uVar1);
  return;
}



/* 0x1c19a ev_58eaabe31315d6584ec44a9bb2d2dd231991289e3a8562c19d4b3a3d9d727739 */

void __cdecl16near FUN_1000_c19a(void)

{
  FUN_1000_e7bd();
  FUN_1000_f814(0xa08a,0xa08c);
  return;
}



/* 0x1c1af ev_23900e3dc6a25b4ae3ef43e7c7eb4da830ad263aff694bc5849f90c44a3c7c58 */

void __cdecl16near FUN_1000_c1af(void)

{
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_f7da(*(undefined2 *)0xa08a,*(undefined2 *)0xa08c);
  return;
}



/* 0x1c1c4 ev_c2f84af53ed214f4c775bf5d9c5934d1a1bd5d4df1a4a18781cf18ba5320b270 */

undefined4 __cdecl16near FUN_1000_c1c4(void)

{
  code *pcVar1;
  undefined2 in_CX;
  undefined2 extraout_DX;
  
  pcVar1 = (code *)swi(0x1a);
  (*pcVar1)();
  return CONCAT22(in_CX,extraout_DX);
}



/* 0x1c1d3 ev_8e7ac5f30e81303e7f2184196d6ff61a058177814850166c648ae4a6b92c3105 */

void __cdecl16near FUN_1000_c1d3(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8889,*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  iVar3 = FUN_1000_75c1((int)*(char *)0x8b5);
  if ((iVar3 != 0) && (iVar2 == 0)) {
    iVar3 = FUN_1000_72dd(0x6e);
    if (iVar3 != 0) {
      puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
      *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
      *puVar1 = 0x6e;
      goto LAB_1000_c21d;
    }
  }
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar2;
LAB_1000_c21d:
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1c22d ev_20d00753d66f6034e8518469b98a4b1e7ee65652437357407ff707d249eb7fb1 */

void __cdecl16near FUN_1000_c22d(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar2 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar2;
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  if ((puVar1[-1] == 's') || ((puVar1[-1] == 'h' && ((puVar1[-2] == 's' || (puVar1[-2] == 'c'))))))
  {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x65;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x73;
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1c26e ev_a6993941b9d83bed684f83b17852bacfa2ea1e3541b5b0a299ff3865b232df8b */

void __cdecl16near FUN_1000_c26e(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar1;
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
  if (*(char *)*(undefined2 *)(unaff_BP + 4) != 'e') {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  }
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x85f4);
  return;
}



/* 0x1c29a ev_04b0d191642782478f787abb55536948b2731ea2b750b4ec2072a84a4c142826 */

void __cdecl16near FUN_1000_c29a(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar1;
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
  if (*(char *)*(undefined2 *)(unaff_BP + 4) != 'e') {
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  }
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x85f7);
  return;
}



/* 0x1c2c6 ev_78b7f20544c019bb9c4fe88310c60637bc89c8014c3bf192d37406f791e7379b */

void __cdecl16near FUN_1000_c2c6(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x85fb);
  return;
}



/* 0x1c2da ev_eccf411c59634d57677acdcefc51af001e61528de240c87c2b249bd8ef8b29c9 */

void __cdecl16near FUN_1000_c2da(void)

{
  undefined1 *puVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar2 = FUN_1000_72dd(0x2c);
  if (iVar2 != 0) {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x2c;
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  return;
}



/* 0x1c2fc ev_65a441183404f73d5b2f1199bf1c8aa0a539fc58457da5c0ab4cc0a04732d02d */

void __cdecl16near FUN_1000_c2fc(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_72ff(0x85fe);
  if (iVar1 == 0) {
    FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x8602);
  }
  else {
    FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),0x8600);
  }
  return;
}



/* 0x1c32b ev_b2c17634a910cf249c193dffba7009d9baab4135b719d2fb5e351f5187671d31 */

void __cdecl16near FUN_1000_c32b(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar3 = FUN_1000_bd74(2);
  if (iVar3 == 0) {
    uVar4 = 0x860d;
  }
  else {
    uVar4 = 0x8606;
  }
  FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),uVar4);
  iVar3 = FUN_1000_f139(*(undefined2 *)(unaff_BP + 4));
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + iVar3;
  uVar2 = FUN_1000_7251(0x8617);
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  iVar3 = FUN_1000_bd74(2);
  iVar5 = FUN_1000_72dd(0x5f);
  if (iVar5 == 0) {
    iVar3 = 0;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = 0x20;
  iVar5 = FUN_1000_bd74(2);
  if (iVar5 != 0) {
    uVar4 = *(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    FUN_1000_71ce(uVar4);
  }
  uVar2 = 0x5e;
  if (iVar3 != 0) {
    uVar2 = 0x5f;
  }
  puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
  *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
  *puVar1 = uVar2;
  if (iVar5 != 0) {
    uVar4 = *(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    FUN_1000_71ce(uVar4);
  }
  iVar5 = FUN_1000_bd74(2);
  if (iVar5 == 0) {
    *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  }
  else {
    puVar1 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
    *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
    *puVar1 = 0x20;
    uVar4 = 0x8627;
    if (iVar3 != 0) {
      uVar4 = 0x861a;
    }
    FUN_1000_e74e(*(undefined2 *)(unaff_BP + 4),uVar4);
  }
  return;
}



/* 0x1c3f6 ev_458afc58cfa01712ea74b68744278836fccdefcad81e427afef07d69743f4000 */

void __cdecl16near FUN_1000_c3f6(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x88a1,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_733f(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c411 ev_f76ef6aff5e5502f727506ffc665e28026d0b805263db676c6729422a9aeb7e5 */

void __cdecl16near FUN_1000_c411(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x88a1,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_733f(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c2c6(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c433 ev_0b9bf3e9e3480639415559bd0f7ef6cbec53351994cfb12df1504eeaa9dd1c7b */

void __cdecl16near FUN_1000_c433(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x88a3,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_733f(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c44e ev_668e9088511329e6c6d80a470d86867a3eca207e3fb1f7d8253aafd9eb869a9c */

void __cdecl16near FUN_1000_c44e(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_bd74(2,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_665a(*(undefined2 *)((iVar1 + 0x14) * 2 + -0x7787));
  FUN_1000_733f(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c478 ev_f077677c95557f67532c52b54efa033338d67ca65aa5c3105902fe422d4f62a1 */

void __cdecl16near FUN_1000_c478(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8879,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_733f(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c493 ev_9bf29ccbf7b68d605e10fbdc82927767db712b49f8bed68dab3d180fd632ca66 */

void __cdecl16near FUN_1000_c493(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x887d,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_733f(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c4ae ev_bc5722ca39f00e829deecf145329025d9d128bf3fc06efed13ea3467c7c174f7 */

void __cdecl16near FUN_1000_c4ae(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8879,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_733f(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c2c6(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c4d0 ev_05003b37f5fecf2162e0d6d64e59b0df38b8e1e39fa62357132294be2cd8d9d4 */

void __cdecl16near FUN_1000_c4d0(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  
  FUN_1000_e7bd();
  uVar2 = *(undefined2 *)(unaff_BP + 4);
  iVar1 = FUN_1000_bd74(4,uVar2);
  if (iVar1 == 0) {
    iVar1 = FUN_1000_bd74(2,uVar2);
    iVar1 = iVar1 + 9;
  }
  else {
    iVar1 = 0xb;
  }
  FUN_1000_665a(*(undefined2 *)(iVar1 * 2 + -0x7787));
  return;
}



/* 0x1c504 ev_1d11817be661cca505c70415b0dfa782df064de410e63513ebce7e692f545f27 */

void __cdecl16near FUN_1000_c504(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_c4d0(0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c527 ev_6be1bac07989d40ce8725e015c34f739af9ff2e3c410b32d154b31428531f112 */

void __cdecl16near FUN_1000_c527(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_c504(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c2c6(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c53c ev_316e9f51b0bed5bf3ba654dce7f8541a102017ee84a305231353004866ac7682 */

void __cdecl16near FUN_1000_c53c(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x888d,0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c565 ev_18aec8a23ad2ef977cca178238b55c5dc9a917eb574fe5572907238b9f700385 */

void __cdecl16near FUN_1000_c565(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x888b,0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c58e ev_b9b7e9c01293f75a33abd07abbf8e2826714512a21d540cdbdb780480887508f */

void __cdecl16near FUN_1000_c58e(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_c4d0(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c22d(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c5a3 ev_772f49ef9aaaddcfcac9ea08cf0859f78420a5fe893ed65c1de2db8cb9dd8ce3 */

void __cdecl16near FUN_1000_c5a3(void)

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar1 = FUN_1000_bd74(4,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_665a(*(undefined2 *)((iVar1 + 0x1b) * 2 + -0x7787));
  return;
}



/* 0x1c5c6 ev_60bbe5dbe12d72aecf55744f05cb10e44fb164c4922b2395a234343e58298e71 */

void __cdecl16near FUN_1000_c5c6(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_e7bd();
  FUN_1000_c5a3(0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c5e9 ev_d29a3345bd7224662c3514564d89ae015e37190b37490d0ff8749b9fe32efa25 */

void __cdecl16near FUN_1000_c5e9(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8899,0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c612 ev_2a534da84c9dc7271672142fd052b1047318e4bed663faadc719e30018bdc281 */

void __cdecl16near FUN_1000_c612(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8887,0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c63b ev_a98a77830b39e31c8b1431725bba557c050cf4ed42c97bccbad9cc9647615a54 */

void __cdecl16near FUN_1000_c63b(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8887,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c22d(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c656 ev_1c3e48ce849b88e2564a61a3b5902235ed5c296a2f237b560581fe98569518bc */

void __cdecl16near FUN_1000_c656(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x88a5,0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c67f ev_0ee37f33ec1628b1814715cd89d1853814442a23afc45ffec4be4a260fea2811 */

void __cdecl16near FUN_1000_c67f(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x889b,0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c6a8 ev_3c8679235b5f5049ccdefe6f2e54afe02ac2af2b17c1c533b1e77dbc6ef62233 */

void __cdecl16near FUN_1000_c6a8(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x889d,0x8b5);
  FUN_1000_c1d3(*(undefined2 *)(unaff_BP + 4));
  FUN_1000_e717(*(undefined2 *)(unaff_BP + 4),0x8b5);
  return;
}



/* 0x1c6d1 ev_3ab07fcddecb6106ff42a988cd24e68e78961ea735441f907a6ebb77800eab95 */

void __cdecl16near FUN_1000_c6d1(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8891,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c26e(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c6ec ev_1b718812997e492f8b8acdaf51e729d7872ab9bdeb2ffa5c88f3c0f649411e67 */

void __cdecl16near FUN_1000_c6ec(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8891,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c29a(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c707 ev_da4a4a48458a37f3252e42c2b03e1c776b8492e682c5fec1ae53867f34ee7d4a */

void __cdecl16near FUN_1000_c707(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8891,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c22d(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c722 ev_64dec1a8b061b470326408648487f5370d145548460b3d5b1665a6c56e30cdd7 */

void __cdecl16near FUN_1000_c722(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x88b7,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c26e(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c73d ev_710c4578f52a492589e75759c9f9b77c7ab44edea119b64c27ac6ebd6acdba51 */

void __cdecl16near FUN_1000_c73d(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x88b7,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c29a(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c758 ev_287a6a8e5ea2d70a7e2477b2d9f340dff15332ef83f091b8844981cc93a02dcf */

void __cdecl16near FUN_1000_c758(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x889f,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c26e(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c773 ev_62e0300d9400b5e5e56377a449f4f9f7b573d7e78933d9a9109d08e8aaf55c7c */

void __cdecl16near FUN_1000_c773(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_665a(*(undefined2 *)0x8897,*(undefined2 *)(unaff_BP + 4));
  FUN_1000_c26e(*(undefined2 *)(unaff_BP + 4));
  return;
}



/* 0x1c78e ev_41a83c6f7312a814f6fc407c59809f15a64fbb1363cc2c2d43209a7354daaf31 */

void __cdecl16near FUN_1000_c78e(void)

{
  int unaff_BP;
  int iVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_b1f3(0,1,7);
  FUN_1000_ae2b(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6),
                *(byte *)(unaff_BP + 4) + 10,*(byte *)(unaff_BP + 6) + 0x36,0,0xcd,0xb3,0xd5,0xb8,
                0xd4,0xbe);
  FUN_1000_b1f3(0,1,2);
  FUN_1000_c831(*(byte *)(unaff_BP + 4) + 1,*(byte *)(unaff_BP + 6) + 2);
  for (iVar1 = 0; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    FUN_1000_c98e(*(undefined1 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + 6),
                  (int)*(char *)(iVar1 + 0x7a53),0);
  }
  return;
}



/* 0x1c831 ev_4b499938e0e0e133234621ddff95ebe08479d6b033c47d269e31f436418306a4 */

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



/* 0x1c98e ev_ad12449ae7e1326d64614feb13addf868638c3e725f0ddca9d117ec24990f626 */

void __cdecl16near FUN_1000_c98e(void)

{
  char cVar1;
  int iVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)(unaff_BP + 8) < '!') {
    return;
  }
  if (*(char *)(unaff_BP + 10) == '\x01') {
    FUN_1000_b1f3(1,1,7);
  }
  else {
    FUN_1000_b1f3(0,1,2);
  }
  iVar2 = FUN_1000_722b((int)*(char *)(unaff_BP + 8));
  cVar1 = *(char *)(iVar2 * 2 + -0x7746);
  *(int *)(unaff_BP + -2) = (int)*(char *)(iVar2 * 2 + -0x7745);
  iVar2 = cVar1 * 2;
  FUN_1000_f7da((uint)*(byte *)(unaff_BP + 4) + iVar2 + 2,
                (uint)*(byte *)(unaff_BP + 6) + *(int *)(unaff_BP + -2) / 3 + iVar2 +
                *(int *)(unaff_BP + -2) + 3);
  uVar3 = FUN_1000_e793((int)*(char *)(unaff_BP + 8));
  FUN_1000_f873(uVar3);
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x1ca33 ev_09c257311565a98b6d9935fb32b6c5534d772cfc9b34dde55e4f7d03785ab80a */

void __cdecl16near FUN_1000_ca33(void)

{
  int iVar1;
  int unaff_BP;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -2) = 0;
  FUN_1000_7e47(7);
  FUN_1000_7d64(unaff_BP + -6,unaff_BP + -8);
  FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 7,*(byte *)(unaff_BP + 6) + 0xd);
  FUN_1000_f6a4(0x89db);
  while ((iVar1 = FUN_1000_f84a(), iVar1 == -1 && (*(int *)(unaff_BP + -6) != 0))) {
    *(undefined2 *)(unaff_BP + -4) = 0;
    for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
      for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
        if (iVar2 == *(int *)(unaff_BP + -2)) {
          if (*(char *)0x906a == '\0') {
            if ((*(uint *)0x8f42 & 8) == 0) {
              *(uint *)0x8f42 = *(uint *)0x8f42 | 8;
            }
            else {
              *(uint *)0x8f42 = *(uint *)0x8f42 & 0xf7;
            }
          }
          else {
            FUN_1000_b1f3(0,1,*(undefined1 *)((*(int *)(unaff_BP + -2) + iVar1) % 5 + -0x762a));
          }
        }
        FUN_1000_f7da((uint)*(byte *)(unaff_BP + 4) +
                      (uint)*(byte *)(*(int *)(unaff_BP + -4) + -0x76c0),
                      (uint)*(byte *)(unaff_BP + 6) +
                      (uint)*(byte *)(*(int *)(unaff_BP + -4) + -0x768e));
        FUN_1000_f873(*(undefined1 *)(*(int *)(unaff_BP + -4) + -0x765c));
        *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
      }
    }
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) % 10;
    FUN_1000_7d64(unaff_BP + -6,unaff_BP + -8);
  }
  FUN_1000_7d49();
  *(uint *)0x8f42 = *(uint *)0x8f42 & 0xf7;
  return;
}



/* 0x1cb56 ev_05f8ccf26d3f120899296667f0a5d844c3ab4fd13d6c66f3fed4a7f5f9cbe355 */

undefined2 __cdecl16near FUN_1000_cb56(void)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_7e47(5);
  uVar1 = FUN_1000_b21d(2,9,0x89e0,0,*(char *)0x90ad == '\0',0x8a01);
  if (uVar1 == 0xffff) {
    FUN_1000_e74e(0x17a0,0x1004);
    return 0xffff;
  }
  if (*(byte *)0x90ad == uVar1) {
    *(bool *)0x90ad = uVar1 == 0;
    *(undefined1 *)0x906e = 1;
    if (*(char *)0x90ad == '\0') {
      FUN_1000_7c0a();
    }
    else {
      FUN_1000_7b92();
    }
  }
  uVar2 = FUN_1000_7e47(5);
  return uVar2;
}



/* 0x1cbd7 ev_68dcbf8d962ea3015864f4ceb34aabef22ddea46533e9b75c2bb9c0f57f266f5 */

uint __cdecl16near FUN_1000_cbd7(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = 10;
  for (iVar3 = 0; iVar3 < 10; iVar3 = iVar3 + 1) {
    FUN_1000_e61c(*(undefined2 *)(iVar3 * 2 + 0x6d5),0x8a2f,iVar4,iVar4 + 9);
    iVar4 = iVar4 + 10;
  }
  FUN_1000_e74e(*(int *)((iVar3 + -1) * 2 + 0x6d5) + 3,0x8a39);
  uVar1 = (*(byte *)0x90b8 - 10) / 10;
  uVar2 = FUN_1000_b21d(10,9,0x6d5,0,uVar1,0xd38);
  if (uVar2 == 0xffff) {
    FUN_1000_e74e(0x17a0,0x1004);
    return 0xffff;
  }
  if (uVar2 != uVar1) {
    *(char *)0x90b8 = (char)uVar2 * '\n' + '\n';
    FUN_1000_54c1(0);
    uVar2 = FUN_1000_54c1(1);
    *(undefined1 *)0x906e = 1;
  }
  return uVar2;
}



/* 0x1cc89 ev_2f955fcf6180890c508a4f070e9eeafdc81608cb800d95ab214a13877c86bbc2 */

uint __cdecl16near FUN_1000_cc89(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  uVar1 = FUN_1000_b21d(7,8,0x7fb,0,*(undefined1 *)0x90b7,0xdd1);
  if (uVar1 == 0xffff) {
    FUN_1000_e74e(0x17a0,0x1004);
    return 0xffff;
  }
  uVar2 = (uint)*(byte *)0x90b7;
  if (*(byte *)0x90b7 != uVar1) {
    *(undefined1 *)0x90b7 = (char)uVar1;
    *(undefined1 *)0x906e = 1;
    uVar2 = uVar1;
  }
  return uVar2;
}



/* 0x1ccdd ev_61aae4557fe4fd75f1a175ac74d7fec186314915282641af8585b3da1ce21fd1 */

int __cdecl16near FUN_1000_ccdd(void)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar2 = *(byte *)0x90b6 / 5 - 1;
  iVar1 = FUN_1000_b21d(4,3,0x89ed,0,iVar2,0x8a3b);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    return -1;
  }
  if (iVar1 != iVar2) {
    iVar1 = (iVar1 + 1) * 5;
    *(undefined1 *)0x90b6 = (char)iVar1;
    *(undefined1 *)0x906e = 1;
  }
  return iVar1;
}



/* 0x1cd3c ev_c47f69d6cf150e4137c0d176607f2f19fd9aa6d1531bdc7d4460e6ab73eb2a9a */

undefined2 __cdecl16near FUN_1000_cd3c(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  FUN_1000_0128();
  iVar1 = FUN_1000_0f47();
  FUN_1000_e74e(*(undefined2 *)((*(int *)0x9d2e + 1) * 2 + 0x6d5),0x9072);
  if (*(int *)0x9d34 != 0) {
    iVar1 = iVar1 + 1;
  }
  iVar1 = FUN_1000_0d63(iVar1);
  if (iVar1 == -1) {
    FUN_1000_e74e(0x17a0,0x1004);
    FUN_1000_e913(*(undefined2 *)0x9070);
    return 0xffff;
  }
  uVar2 = FUN_1000_e913(*(undefined2 *)0x9070);
  *(undefined1 *)0x906e = 1;
  return uVar2;
}



/* 0x1cd9b ev_30cd9945ace17d60b009a5e25d751ff7a4ebeb4edb64f89035a0aa524c87b771 */

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



/* 0x1cf2e ev_f7ea4379b9cc8d0bc9fe21c055b1098cfd88590a51d0116b5d43cf4f3419e637 */

void __cdecl16near FUN_1000_cf2e(int param_1,int param_2)

{
  int iVar1;
  
  FUN_1000_b1f3(0,1,7);
  FUN_1000_ae2b(param_1,param_2,param_1 + 10,param_2 + 0x14,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  FUN_1000_b1f3(0,1,2);
  FUN_1000_ae2b(param_1 + 1,param_2 + 2,param_1 + 5,param_2 + 0xe,0,0xc4,0xb3,0xda,0xbf,0xc3,0xc5);
  FUN_1000_ae2b(param_1 + 3,param_2 + 2,param_1 + 7,param_2 + 0xe,0,0xc4,0xb3,0xc3,0xb4,0xc3,0xb4);
  FUN_1000_ae2b(param_1 + 1,param_2 + 6,param_1 + 7,param_2 + 10,0,0xc4,0xb3,0xc2,0xc2,0xc1,0xc5);
  FUN_1000_ae2b(param_1 + 5,param_2 + 2,param_1 + 9,param_2 + 0x12,0,0xc4,0xb3,0xc3,0xbf,0xc0,0xd9);
  FUN_1000_ae2b(param_1 + 7,param_2 + 10,param_1 + 9,param_2 + 0xe,0,0xc4,0xb3,0xc5,0xb4,0xc1,0xc1);
  FUN_1000_ae2b(param_1 + 3,param_2 + 6,param_1 + 5,param_2 + 10,0,0xc4,0xb3,0xc5,0xc5,0xc5,0xc5);
  FUN_1000_f7da(param_1 + 7,param_2 + 2);
  FUN_1000_f873(0xc3);
  FUN_1000_f7da(param_1 + 5,param_2 + 0xe);
  FUN_1000_f873(0xc5);
  for (iVar1 = 0; iVar1 < 0xc; iVar1 = iVar1 + 1) {
    FUN_1000_d14c(param_1,param_2,iVar1,0);
  }
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x1d14c ev_9b066b4aab7e22b0d71a0249f6e0d691690ef72521d0eb969f7523aa59917e04 */

void __cdecl16near FUN_1000_d14c(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 unaff_DS;
  
  if (param_4 == 1) {
    FUN_1000_b1f3(1,1,7);
  }
  else {
    FUN_1000_b1f3(0,1,2);
  }
  FUN_1000_f7da(*(char *)(param_3 * 2 + -0x7435) + param_1,
                *(char *)(param_3 * 2 + -0x7434) + param_2);
  FUN_1000_f873((int)*(char *)(param_3 + 0x7b14));
  FUN_1000_b1f3(0,1,7);
  return;
}



/* 0x1d1b8 ev_00855f1fec44ffc757d1c6cf802a57544391cb4ab342fe240e5fd1edf7c11359 */

void __cdecl16near FUN_1000_d1b8(int param_1)

{
  undefined2 unaff_DS;
  
  if (param_1 == 4) {
    FUN_1000_b1f3(0,2,7);
    if (*(char *)0x906a == '\0') {
      FUN_1000_ae2b(2,1,0x17,0x4e,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
    }
    else {
      FUN_1000_ae2b(2,1,0x17,0x4e,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
    }
  }
  else {
    FUN_1000_2692(0x1053,0x101e);
    FUN_1000_b1f3(0,2,7);
    if (*(char *)0xa08e == '\0') {
      FUN_1000_ae2b(0x11,4,0x14,0x4b,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
      FUN_1000_af51(0x8be3,0xffff,0x11,4,0x14,0x4b,0,0);
    }
    else {
      FUN_1000_d2c9();
    }
  }
  return;
}



/* 0x1d2c9 ev_8fe00a347efb807e6b4d3ee69c9d866b6c3b5de1373143bdc3b42db4931e36df */

void __cdecl16near FUN_1000_d2c9(void)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x906a == '\0') {
    FUN_1000_ae2b(0x11,0x1f,0x14,0x30,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  }
  else {
    FUN_1000_ae2b(0x11,0x1f,0x14,0x30,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
  }
  FUN_1000_f7da(0x12,0x21);
  FUN_1000_f6a4(0x8c6b);
  FUN_1000_f7da(0x13,0x21);
  FUN_1000_f6a4(0x8c7a);
  return;
}



/* 0x1d368 ev_9a7c056a0131b99e042e4f2bb2de486c45cff418014fa8f9aea0863745088848 */

int __cdecl16near FUN_1000_d368(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  undefined1 local_2e [30];
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  int local_8;
  int local_6;
  int local_4;
  
  local_8 = 0;
  if (*(char *)0x90b1 != '\0') {
    bVar1 = false;
    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
      if ((bVar1) || (iVar2 = FUN_1000_e677(iVar3 * 10 + param_1,*(undefined1 *)0x90b1), iVar2 != 0)
         ) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    if (bVar1) {
      *(undefined1 *)0x9d4e = 1;
      *(undefined1 *)0x9d51 = 1;
      FUN_1000_2692(0x8c89,0x101e);
      FUN_1000_cf2e(3,0x32);
      iVar3 = FUN_1000_e08c(*(undefined1 *)0x90b1);
      *(char *)0x9d4f = (char)((iVar3 + -1) % 3) + '\x01';
      if (*(char *)0x90b1 == '.') {
        *(undefined1 *)0x9d4f = 3;
      }
      FUN_1000_d14c(3,0x32,*(byte *)0x9d4f - 1,1);
      iVar3 = FUN_1000_e08c(*(undefined1 *)0x90b1,1);
      FUN_1000_d14c(3,0x32,iVar3 + -0x40);
      FUN_1000_f7da(0x11,8);
      FUN_1000_b1f3(1,7,1);
      FUN_1000_f6a4(0x1a50,0x1a95,(4 - (uint)*(byte *)0x9d4f) * 7 + 0x1a9b,
                    (int)*(char *)(*(byte *)0x9d4f + 0x7b13),*(undefined1 *)0x90b1);
      FUN_1000_b1f3(0,2,7);
      for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
        if (*(char *)0x906a == '\0') {
          FUN_1000_ae2b(3,10,0xe,0x18,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
        }
        else {
          FUN_1000_ae2b(3,10,0xe,0x18,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
        }
        for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
          FUN_1000_6298(local_2e + iVar2 * 10,9);
          FUN_1000_f7da(iVar2 * 3 + 5,0xd);
          FUN_1000_f6a4(0x8c99,local_2e + iVar2 * 10);
        }
        FUN_1000_bd1f();
        local_e = 0;
        local_10 = 0;
        local_c = 0;
        local_a = 0;
        for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
          local_8 = FUN_1000_4a70(iVar2 * 3 + 6,0xd,local_2e + iVar2 * 10,&local_a,&local_c,
                                  &local_10);
          if (local_8 == -1) {
            iVar3 = 3;
            iVar2 = 3;
            FUN_1000_e74e(0x17a0,0x1004);
          }
        }
        for (local_4 = 0; local_4 < 9; local_4 = local_4 + 1) {
          FUN_1000_f7da(local_4 + 4,0xd);
          for (local_6 = 0; local_6 < 10; local_6 = local_6 + 1) {
            FUN_1000_f873(0x20);
          }
        }
      }
      *(undefined1 *)0x90b1 = 0;
      *(undefined1 *)0x9d51 = 0;
      if ((param_2 != 1) && (local_8 == 0)) {
        FUN_1000_d1b8(1);
        FUN_1000_f7da(0x12,0x28);
        FUN_1000_f6a4(0x8c9c,*(undefined2 *)0x9d56);
        FUN_1000_f7da(0x13,0x2b);
        FUN_1000_f6a4(0x8ca3,*(undefined2 *)0x9d54);
      }
    }
  }
  if ((param_2 == 1) && (local_8 == 0)) {
    FUN_1000_d1b8(1);
  }
  return local_8;
}



/* 0x1d6a0 ev_454b9c2bab764c17c9b99e94bb83f8aa21906a30324914fbffb64c0f32314d7b */

int __cdecl16near FUN_1000_d6a0(int param_1)

{
  uint *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined2 unaff_DS;
  bool bVar10;
  undefined1 local_109;
  undefined1 local_108;
  undefined1 local_107;
  uint local_106;
  int local_104;
  uint local_102;
  int local_100;
  uint local_fe;
  uint local_fc;
  uint local_fa;
  int local_f8;
  uint local_f6;
  int local_f4;
  undefined1 local_f2 [240];
  
  local_fa = 1;
  local_100 = 0;
  local_102 = 0;
  iVar9 = 0;
  iVar8 = 0;
  do {
    if (*(int *)0x9d2c == 10) {
      uVar2 = FUN_1000_e1ad();
      *(undefined1 *)0x90b1 = uVar2;
    }
    if (local_fa == 1) {
      FUN_1000_54c1(1);
    }
    for (local_f4 = 0; local_f4 < param_1; local_f4 = local_f4 + 1) {
      local_f6 = 0;
      while( true ) {
        iVar3 = 6;
        if (param_1 == 1) {
          iVar3 = 3;
        }
        if (iVar3 <= (int)local_f6) break;
        FUN_1000_e15d(local_f2 + local_f4 * 0x3c + local_f6 * 10);
        local_f6 = local_f6 + 1;
      }
    }
    if ((*(int *)0x9d2c == 10) && (iVar3 = FUN_1000_d368(local_f2,local_fa), iVar3 == -1)) {
      FUN_1000_07c9(0x20,0);
      iVar8 = FUN_1000_e74e(0x17a0,0x1004);
      return iVar8;
    }
    for (local_f4 = 0; local_f4 < param_1; local_f4 = local_f4 + 1) {
      FUN_1000_b1f3(0,2,7);
      if (*(char *)0x906a == '\0') {
        iVar3 = 0x2f;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 0x15;
        }
        uVar6 = 0x16;
        if (param_1 == 1) {
          uVar6 = 0xe;
        }
        iVar4 = 0x21;
        if (param_1 != 1) {
          iVar4 = local_f4 * 0x11 + 7;
        }
        FUN_1000_ae2b(3,iVar4,uVar6,iVar3,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
      }
      else {
        iVar3 = 0x2f;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 0x15;
        }
        uVar6 = 0x16;
        if (param_1 == 1) {
          uVar6 = 0xe;
        }
        iVar4 = 0x21;
        if (param_1 != 1) {
          iVar4 = local_f4 * 0x11 + 7;
        }
        FUN_1000_ae2b(3,iVar4,uVar6,iVar3,1,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
      }
      local_f6 = 0;
      while( true ) {
        iVar3 = 6;
        if (param_1 == 1) {
          iVar3 = 3;
        }
        if (iVar3 <= (int)local_f6) break;
        iVar3 = 0x24;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 10;
        }
        FUN_1000_f7da(local_f6 * 3 + 5,iVar3);
        FUN_1000_f6a4(0x8ca8,local_f2 + local_f4 * 0x3c + local_f6 * 10);
        local_f6 = local_f6 + 1;
      }
    }
    FUN_1000_bd1f();
    local_104 = 0;
    local_106 = 0;
    local_fe = 0;
    local_fc = 0;
    for (local_f4 = 0; local_f4 < param_1; local_f4 = local_f4 + 1) {
      local_f6 = 0;
      while( true ) {
        iVar3 = 6;
        if (param_1 == 1) {
          iVar3 = 3;
        }
        if (iVar3 <= (int)local_f6) break;
        iVar3 = 0x24;
        if (param_1 != 1) {
          iVar3 = local_f4 * 0x11 + 10;
        }
        iVar3 = iVar3 + 9;
        iVar4 = FUN_1000_f139(local_f2 + local_f4 * 0x3c + local_f6 * 10,iVar3,
                              local_f2 + local_f4 * 0x3c + local_f6 * 10,&local_fc,&local_fe,
                              &local_106);
        iVar3 = FUN_1000_4a70(local_f6 * 3 + 6,iVar3 - iVar4);
        if (iVar3 == -1) {
          FUN_1000_07c9(0x20,0);
          FUN_1000_e74e(0x17a0,0x1004);
          return -1;
        }
        local_f6 = local_f6 + 1;
      }
    }
    if (*(int *)0x9d2c < 8) {
      iVar3 = *(int *)0x9d3a;
      *(int *)(iVar3 + 0x17) = (int)local_fc >> 0xf;
      *(uint *)(iVar3 + 0x15) = local_fc;
      iVar3 = *(int *)0x9d3a;
      *(int *)(iVar3 + 0x1b) = (int)local_fe >> 0xf;
      *(uint *)(iVar3 + 0x19) = local_fe;
      iVar3 = *(int *)0x9d3a;
      *(int *)(iVar3 + 0x13) = local_104;
      *(uint *)(iVar3 + 0x11) = local_106;
      iVar3 = 6;
      if (param_1 == 1) {
        iVar3 = 3;
      }
      iVar4 = *(int *)0x9d3a;
      *(int *)(iVar4 + 0x1f) = iVar3 * param_1 >> 0xf;
      *(int *)(iVar4 + 0x1d) = iVar3 * param_1;
    }
    puVar1 = (uint *)0x97b5;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + local_fc;
    *(int *)0x97b7 = *(int *)0x97b7 + ((int)local_fc >> 0xf) + (uint)CARRY2(uVar7,local_fc);
    puVar1 = (uint *)0x97b9;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + local_fe;
    *(int *)0x97bb = *(int *)0x97bb + ((int)local_fe >> 0xf) + (uint)CARRY2(uVar7,local_fe);
    puVar1 = (uint *)0x97b1;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + local_106;
    *(int *)0x97b3 = *(int *)0x97b3 + local_104 + (uint)CARRY2(uVar7,local_106);
    iVar3 = 6;
    if (param_1 == 1) {
      iVar3 = 3;
    }
    uVar5 = iVar3 * param_1;
    puVar1 = (uint *)0x97bd;
    uVar7 = *puVar1;
    *puVar1 = *puVar1 + uVar5;
    *(int *)0x97bf = *(int *)0x97bf + ((int)uVar5 >> 0xf) + (uint)CARRY2(uVar7,uVar5);
    iVar8 = iVar8 + local_fc;
    iVar9 = iVar9 + local_fe;
    bVar10 = CARRY2(local_102,local_106);
    local_102 = local_102 + local_106;
    local_100 = local_100 + local_104 + (uint)bVar10;
    if (*(int *)0x9d2c == 10) {
      FUN_1000_b1f3(0,2,7);
      for (local_f6 = 0; (int)local_f6 < 9; local_f6 = local_f6 + 1) {
        FUN_1000_f7da(local_f6 + 4,0x24);
        for (local_f4 = 0; local_f4 < 10; local_f4 = local_f4 + 1) {
          FUN_1000_f873(0x20);
        }
      }
      FUN_1000_f7da(0x12,0x2e);
      FUN_1000_f873(0x20);
      FUN_1000_f7da(0x13,0x2e);
      FUN_1000_f873(0x20);
      if (*(char *)0xa08e == '\0') {
        *(undefined1 *)0xa08e = 1;
        FUN_1000_b1f3(0,1,7);
        for (local_f4 = 0x11; local_f4 < 0x15; local_f4 = local_f4 + 1) {
          FUN_1000_f7da(local_f4,0);
          FUN_1000_f74a();
        }
        FUN_1000_b1f3(0,2,7);
        FUN_1000_d2c9();
      }
      FUN_1000_f7da(0x12,0x28);
      iVar3 = local_fc + local_fe + -2;
      uVar6 = FUN_1000_52dc(iVar3,iVar3 >> 0xf,0,0,local_106,local_104);
      *(undefined2 *)0x9d56 = uVar6;
      FUN_1000_f6a4(0x8cac,uVar6);
      FUN_1000_f7da(0x13,0x2b);
      uVar6 = FUN_1000_529a(local_fc,(int)local_fc >> 0xf,local_fe,(int)local_fe >> 0xf);
      *(undefined2 *)0x9d54 = uVar6;
      FUN_1000_f6a4(0x8cb3,uVar6);
      if (local_fa < *(byte *)0x90b6) {
        local_fa = local_fa + 1;
      }
      else {
        FUN_1000_f7da(9,0x22);
        FUN_1000_b1f3(1,1,7);
        FUN_1000_f6a4(0x1ae3);
        FUN_1000_b1f3(0,1,7);
        FUN_1000_2612(0x183,0);
        FUN_1000_4d14(0xfa,0,1);
        FUN_1000_bd1f();
        FUN_1000_2692(0x8cb8,0x101e);
        FUN_1000_ae2b(3,0x1b,9,0x35,0,0xcd,0xb3,0xd5,0xb8,0xd4,0xbe);
        FUN_1000_f7da(4,0x1d);
        iVar3 = iVar8 + iVar9 + local_fa * -2;
        uVar6 = FUN_1000_52dc(iVar3,iVar3 >> 0xf,0,0,local_102,local_100);
        FUN_1000_f6a4(0x8cce,uVar6);
        FUN_1000_f7da(5,0x1d);
        local_fa = 1;
        uVar6 = FUN_1000_529a(iVar8,iVar8 >> 0xf,iVar9,iVar9 >> 0xf);
        FUN_1000_f6a4(0x8cdc,uVar6);
        local_f8 = 0;
        for (local_f6 = 0x40; local_f6 <= *(byte *)0x90b0; local_f6 = local_f6 + 1) {
          iVar8 = local_f6 * 4;
          uVar7 = FUN_1000_52dc(*(undefined2 *)(iVar8 + -0x652c),*(undefined2 *)(iVar8 + -0x652a),
                                *(undefined2 *)(iVar8 + -0x6400),*(undefined2 *)(iVar8 + -0x63fe),
                                *(undefined2 *)(iVar8 + -0x6658),*(undefined2 *)(iVar8 + -0x6656));
          if (*(byte *)0x90b8 <= uVar7) {
            local_f8 = local_f8 + 1;
          }
        }
        FUN_1000_f7da(6,0x1d);
        FUN_1000_f6a4(0x8ceb,*(undefined1 *)0x90b8,local_f8);
        FUN_1000_def0(1,*(byte *)0x90b0 - 0x3f,0x7b14,&local_109);
        FUN_1000_f7da(7,0x1d);
        FUN_1000_f6a4(0x8d01,local_109,local_108,local_107);
        FUN_1000_def0(2,*(byte *)0x90b0 - 0x3f,0x7b14,&local_109);
        FUN_1000_f7da(8,0x1d);
        FUN_1000_f6a4(0x8d15,local_109,local_108,local_107);
        FUN_1000_07c9(0x20,0);
        iVar8 = FUN_1000_b21d(3,0x15,0x8bb2,10,0,0x102e);
        if (iVar8 == -1) {
          iVar8 = FUN_1000_e74e(0x17a0,0x1006);
          return iVar8;
        }
        if (iVar8 == 1) {
          iVar8 = FUN_1000_e74e(0x17a0,0x8d2f);
          return iVar8;
        }
        if (iVar8 == 2) {
          iVar8 = FUN_1000_e74e(0x17a0,0x1004);
          return iVar8;
        }
        FUN_1000_07c9(0x20,1);
        local_100 = 0;
        local_102 = 0;
        iVar9 = 0;
        iVar8 = 0;
      }
    }
    else {
      *(undefined1 *)0x9d38 = 1;
    }
    if (*(int *)0x9d2c != 10) {
      return *(int *)0x9d2c;
    }
  } while( true );
}



/* 0x1def0 ev_3ae864350b58e0800838b8de7e2a109479560027b3137ccb398f33f70fa42720 */

void __cdecl16near FUN_1000_def0(int param_1,int param_2,int param_3,undefined1 *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int local_9;
  int local_7;
  byte local_5 [3];
  
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    param_4[iVar3] = 0x20;
    bVar1 = 0;
    if (param_1 == 1) {
      bVar1 = 0xff;
    }
    local_5[iVar3] = bVar1;
  }
  iVar3 = 0;
  do {
    iVar2 = 3;
    if (param_1 != 0) {
      iVar2 = 1;
    }
    if (iVar2 <= iVar3) {
      if (((*(byte *)0x90b0 < 0x44) && (param_1 != 0)) ||
         ((*(char *)0x90b0 == 'D' && (param_1 == 2)))) {
        param_4[2] = 0x20;
      }
      if ((*(char *)0x90b0 == 'B') && (param_1 == 2)) {
        param_4[1] = 0x20;
      }
      return;
    }
    local_9 = 0;
    while( true ) {
      iVar2 = param_2;
      if (param_1 == 0) {
        iVar2 = FUN_1000_f139(iVar3 * 10 + param_3);
      }
      if (iVar2 <= local_9) break;
      iVar2 = FUN_1000_e08c((int)*(char *)(iVar3 * 10 + param_3 + local_9));
      bVar1 = *(byte *)(iVar2 + -0x6f45);
      local_7 = 0;
      while( true ) {
        if ((2 < local_7) || (param_4[local_7] == *(char *)(iVar3 * 10 + param_3 + local_9)))
        goto LAB_1000_e043;
        if (((param_1 == 1) && (bVar1 <= local_5[local_7])) ||
           ((param_1 != 1 && (local_5[local_7] < bVar1)))) break;
        local_7 = local_7 + 1;
      }
      if (local_7 < 2) {
        param_4[2] = param_4[1];
        local_5[2] = local_5[1];
      }
      if (local_7 == 0) {
        param_4[1] = *param_4;
        local_5[1] = local_5[0];
      }
      param_4[local_7] = *(undefined1 *)(iVar3 * 10 + param_3 + local_9);
      local_5[local_7] = bVar1;
LAB_1000_e043:
      local_9 = local_9 + 1;
    }
    iVar3 = iVar3 + 1;
  } while( true );
}



/* 0x1e08c ev_5fe2cc49ddbed4b114763efbbe48cedb5319a93510402d564de674ae15c04b84 */

int __cdecl16near FUN_1000_e08c(char param_1)

{
  undefined2 unaff_DS;
  
  if (param_1 == '.') {
    param_1 = '/';
  }
  return (int)*(char *)(param_1 + 0x7ada);
}



/* 0x1e0a7 ev_7d5e25b13fde8311b6d8be4c64f43cce14a67759e7299809885c92321baeb6ab */

bool __cdecl16near FUN_1000_e0a7(char param_1)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = FUN_1000_e08c((int)param_1);
  return uVar1 <= *(byte *)0x90b0;
}



/* 0x1e0c9 ev_df2625a17544252192a0fad62d2699ebcf7b7e66084e7023c6ee0696ebde5e18 */

int __cdecl16near FUN_1000_e0c9(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint local_1a;
  byte local_18 [11];
  char local_d [11];
  
  local_1a = 0;
  iVar6 = 0;
  iVar5 = 0;
  while( true ) {
    iVar3 = FUN_1000_f139(param_1);
    if (iVar3 <= iVar6) break;
    iVar4 = FUN_1000_e0a7((int)*(char *)(param_1 + iVar6));
    iVar3 = iVar5;
    if (iVar4 != 0) {
      cVar1 = *(char *)(param_1 + iVar6);
      local_d[iVar5] = cVar1;
      iVar3 = FUN_1000_e08c((int)cVar1);
      bVar2 = *(byte *)(iVar3 + -0x6f45);
      iVar3 = iVar5 + 1;
      local_18[iVar5] = bVar2;
      local_1a = local_1a + bVar2;
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar3;
  }
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    iVar6 = FUN_1000_bd74(local_1a);
    local_1a = (uint)local_18[0];
    iVar5 = 0;
    while ((int)local_1a < iVar6) {
      local_1a = local_1a + local_18[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = (int)local_d[iVar5];
  }
  return iVar5;
}



/* 0x1e15d ev_3b2120adcca52b03681caa461e7d0a4df273d84ce39a39c252215d7368f4656f */

int __cdecl16near FUN_1000_e15d(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar2 = FUN_1000_bd74(6);
  iVar2 = iVar2 + 4;
  for (iVar3 = 0; iVar3 < iVar2; iVar3 = iVar3 + 1) {
    uVar1 = FUN_1000_e0c9(0x2116);
    *(undefined1 *)(param_1 + iVar3) = uVar1;
  }
  iVar3 = FUN_1000_e0a7(0x2e);
  if (iVar3 != 0) {
    *(undefined1 *)(param_1 + iVar2 + -3) = 0x2e;
  }
  *(undefined1 *)(param_1 + iVar2) = 0;
  return param_1;
}



/* 0x1e1ad ev_0edc08b4a8b3830a85949bda1dc9fa526751c41d95a58f69c00d727ed079a5a0 */

int __cdecl16near FUN_1000_e1ad(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  if (*(byte *)0x90b0 < 0x4a) {
    iVar3 = 0;
    for (uVar2 = 0x40; uVar2 <= *(byte *)0x90b0; uVar2 = uVar2 + 1) {
      iVar1 = FUN_1000_544e(uVar2);
      if (iVar1 == 0) {
        iVar3 = iVar3 + 1;
      }
    }
    if (iVar3 < 3) {
      *(char *)0x90b0 = *(char *)0x90b0 + '\x01';
      return (int)*(char *)(*(byte *)0x90b0 + 0x7ad4);
    }
  }
  return 0x20;
}



/* 0x1e1f4 ev_77b3e9012e5fff7c966a407dcadfa38c4120aaa3f9c68ff69b16424721980d58 */

int __cdecl16near FUN_1000_e1f4(undefined1 *param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 unaff_DS;
  int local_6;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (param_3 <= iVar2) {
      return iVar2;
    }
    for (local_6 = param_2; local_6 != 0; local_6 = local_6 + -1) {
      iVar1 = FUN_1000_e3ce(param_4);
      if (iVar1 == -1) {
        return iVar2;
      }
      *param_1 = (char)iVar1;
      param_1 = param_1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}



/* 0x1e247 ev_7e9021bc355a53ec0bbf2ef21526d7d52876bb1a09b6c1f948daa8a966397d16 */

undefined2 __cdecl16near FUN_1000_e247(int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  int extraout_DX;
  undefined2 unaff_DS;
  bool bVar4;
  
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xf7;
  if ((*(byte *)(param_1 + 3) & 4) == 0) {
    if ((param_4 == 1) && (*param_1 != 0)) {
      uVar2 = param_1[1] - *param_1;
      bVar4 = param_2 < uVar2;
      param_2 = param_2 - uVar2;
      param_3 = (param_3 - ((int)uVar2 >> 0xf)) - (uint)bVar4;
    }
  }
  else {
    iVar1 = FUN_1000_e983(param_1,0xffff);
    if (iVar1 != 0) {
      return 0xffff;
    }
  }
  param_1[1] = 0;
  *param_1 = 0;
  FUN_1000_f42e((int)*(char *)((int)param_1 + 7),param_2,param_3,param_4);
  if ((extraout_DX < 1) && (extraout_DX != 0)) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 0x1e31a ev_3b3022fdd59878b19dd6aff1c45d9361cbf7d82a0d34fbf24ee08e379a919222 */

uint __cdecl16near FUN_1000_e31a(undefined2 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_1000_e3ce(param_1);
  if ((uVar1 != 0xffff) && (iVar2 = FUN_1000_e3ce(param_1), iVar2 != -1)) {
    return iVar2 << 8 | uVar1;
  }
  return 0xffff;
}



/* 0x1e352 ev_a1065c78c5436a9bb4109121074110a21ea1a7be612efe221beb6bd14572fa94 */

uint __cdecl16near FUN_1000_e352(uint param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_1000_e8c5(param_1,param_2);
  if (iVar1 < 0) {
    param_1 = 0xffff;
  }
  else {
    iVar1 = FUN_1000_e8c5(param_1 >> 8,param_2);
    if (iVar1 < 0) {
      param_1 = 0xffff;
    }
  }
  return param_1;
}



/* 0x1e38e ev_8a441e65b3da377bd147ab12af6b25794104a1bc4125381c7885ae9c46d21958 */

uint __cdecl16near FUN_1000_e38e(int param_1)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  do {
    uVar1 = FUN_1000_e3ce(param_1);
    if (uVar1 == 0xffff) {
      return 0xffff;
    }
    uVar1 = uVar1 & 0x7f;
  } while ((uVar1 == 0) || (uVar1 == 0xd));
  if (uVar1 == 0x1a) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 8;
    uVar1 = 0xffff;
  }
  return uVar1;
}



/* 0x1e3ce ev_7f1e37a6b213ea3abe262617a2bd14fd72ffd09e8f6ddedabef349a14df546e7 */

uint __cdecl16near FUN_1000_e3ce(uint *param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  if (param_1[1] <= *param_1) {
    if ((param_1[3] & 0x18) != 0) {
      return 0xffff;
    }
    *(byte *)(param_1 + 3) = (byte)param_1[3] & 0xfb;
    if (param_1[2] == 0) {
      FUN_1000_ea5e(param_1);
    }
    iVar4 = FUN_1000_f3e0((int)*(char *)((int)param_1 + 7),param_1[2],
                          *(undefined2 *)((int)param_1 + 9));
    if (iVar4 < 1) {
      bVar3 = 0x10;
      if (iVar4 == 0) {
        bVar3 = 8;
      }
      *(byte *)(param_1 + 3) = (byte)param_1[3] | bVar3;
      return 0xffff;
    }
    uVar1 = param_1[2];
    *param_1 = uVar1;
    param_1[1] = uVar1 + iVar4;
  }
  pbVar2 = (byte *)*param_1;
  *param_1 = *param_1 + 1;
  return (uint)*pbVar2;
}



/* 0x1e43d ev_1219170459523b82493834c281b3adb45f5b5972708c6a75f32aad2420297110 */

int __cdecl16near FUN_1000_e43d(int param_1,uint *param_2)

{
  undefined2 unaff_DS;
  
  if ((param_1 == -1) || (*param_2 <= param_2[2])) {
    param_1 = -1;
  }
  else {
    *param_2 = *param_2 - 1;
    *(undefined1 *)*param_2 = (char)param_1;
  }
  return param_1;
}



/* 0x1e469 ev_e56422d647f641d93ca96172adfa1150e5455c9ccd74a485191bb82fa99aba07 */

int __cdecl16near FUN_1000_e469(char *param_1)

{
  bool bVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
  }
  bVar1 = false;
  if (*param_1 == '-') {
    bVar1 = true;
    param_1 = param_1 + 1;
  }
  else if (*param_1 == '+') {
    param_1 = param_1 + 1;
  }
  iVar2 = 0;
  while ((*(byte *)(*param_1 + -0x7183) & 4) != 0) {
    iVar2 = (int)*param_1 + iVar2 * 10 + -0x30;
    param_1 = param_1 + 1;
  }
  if (bVar1) {
    iVar2 = -iVar2;
  }
  return iVar2;
}



/* 0x1e4d3 ev_acadac75e53ed01b500ad5e45e832c9199424df10e719d94dc6c107275cd8419 */

undefined4 __cdecl16near FUN_1000_e4d3(char *param_1)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  bool bVar5;
  uint local_6;
  int local_4;
  
  for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
  }
  bVar5 = false;
  if (*param_1 == '-') {
    bVar5 = true;
    param_1 = param_1 + 1;
  }
  else if (*param_1 == '+') {
    param_1 = param_1 + 1;
  }
  local_4 = 0;
  local_6 = 0;
  while ((*(byte *)(*param_1 + -0x7183) & 4) != 0) {
    uVar2 = (uint)*param_1;
    uVar1 = (ulong)local_6;
    uVar3 = (uint)(uVar1 * 10);
    uVar4 = uVar2 + uVar3;
    local_6 = uVar4 - 0x30;
    local_4 = ((int)uVar2 >> 0xf) + (int)(uVar1 * 10 >> 0x10) + local_4 * 10 +
              (uint)CARRY2(uVar2,uVar3) + -1 + (uint)(0x2f < uVar4);
    param_1 = param_1 + 1;
  }
  if (bVar5) {
    bVar5 = local_6 != 0;
    local_6 = -local_6;
    local_4 = -(uint)bVar5 - local_4;
  }
  return CONCAT22(local_4,local_6);
}



/* 0x1e56c ev_05e77a2644ac154148de1d6c7f4228a674d7cd73d395d867cb8a7f3f1c9c066f */

undefined1 __cdecl16near FUN_1000_e56c(void)

{
  code *pcVar1;
  undefined1 uVar2;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  return uVar2;
}



/* 0x1e5a1 ev_75aa6825a0b78af1767ec6c2e9e86078d44059b85dba5964f3b7701cef2554c6 */

uint __cdecl16near FUN_1000_e5a1(uint *param_1)

{
  code *pcVar1;
  int iVar2;
  int in_CX;
  uint uVar3;
  uint extraout_DX;
  uint extraout_DX_00;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  uVar3 = in_CX - 0x76c;
  param_1[5] = uVar3;
  param_1[4] = (uint)(byte)((char)(extraout_DX >> 8) - 1);
  param_1[3] = extraout_DX & 0xff;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  param_1[2] = uVar3 >> 8;
  param_1[1] = uVar3 & 0xff;
  *param_1 = extraout_DX_00 >> 8;
  param_1[9] = extraout_DX_00 & 0xff;
  iVar2 = 0;
  if ((1 < param_1[4]) && ((param_1[5] & 3) == 0)) {
    iVar2 = 1;
  }
  uVar3 = iVar2 + *(int *)(param_1[4] * 2 + -0x1a77) + param_1[3];
  param_1[7] = uVar3;
  uVar3 = uVar3 + param_1[5] + (param_1[5] - 1 >> 2) + 1;
  param_1[6] = uVar3 % 7;
  param_1[8] = 0;
  return uVar3 / 7;
}



/* 0x1e61c ev_662869aba8a7d37d7747ca6f17f3306cacc1a9306ab6b2bf28e2d7b27eecd210 */

undefined2 __cdecl16near FUN_1000_e61c(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x8f54 = param_1;
  uVar1 = FUN_1000_ece8(0xe647,param_2,&stack0x0006);
  *(undefined1 *)*(undefined2 *)0x8f54 = 0;
  return uVar1;
}



/* 0x1e647 ev_cfa661205d684917c249ec63f74ea2de65af28cd361a7b17b4cc113fd8abdc42 */

undefined1 __cdecl16near FUN_1000_e647(undefined1 param_1)

{
  undefined1 *puVar1;
  undefined2 unaff_DS;
  
  puVar1 = (undefined1 *)*(undefined2 *)0x8f54;
  *(int *)0x8f54 = *(int *)0x8f54 + 1;
  *puVar1 = param_1;
  return param_1;
}



/* 0x1e677 ev_e8fa5bf8b11ab4a11dc9d49d7a5a593506a81e66a23b269e5afe0d1b1534d4fe */

char * __cdecl16near FUN_1000_e677(char *param_1,char param_2)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  do {
    pcVar1 = param_1;
    if (*pcVar1 == '\0') {
      return (char *)0x0;
    }
    param_1 = pcVar1 + 1;
  } while (*pcVar1 != param_2);
  return pcVar1;
}



/* 0x1e696 ev_9057b9e0aaef71d4966231ee5e6df3351432dfe0c813b5fea76b6a85758069f4 */

undefined2 __cdecl16near FUN_1000_e696(undefined2 *param_1)

{
  return *param_1;
}



/* 0x1e6a2 ev_7540ae3d4f26f0d830e867d48e995fadd9b7311a129b5e664bdb9f3a1bdf1743 */

undefined1 __cdecl16near FUN_1000_e6a2(undefined1 *param_1)

{
  return *param_1;
}



/* 0x1e6b1 ev_7b233092ca8ec3159334509e3738f89fa6b197c2ed970c1d7383122769cb9507 */

void __cdecl16near FUN_1000_e6b1(undefined2 *param_1,undefined2 param_2)

{
  *param_1 = param_2;
  return;
}



/* 0x1e6c0 ev_979fa6aa74ee90aab4a0843536f6479bdf566e6dbbd856431279482a3b584af8 */

void __cdecl16near FUN_1000_e6c0(undefined1 *param_1,undefined1 param_2)

{
  *param_1 = param_2;
  return;
}



/* 0x1e6cf ev_06dd5c72d141eec7fe889a207275441159775e2f09bcf9ff7041377e6b7480e4 */

undefined1 __cdecl16near FUN_1000_e6cf(undefined2 param_1)

{
  undefined1 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



/* 0x1e6db ev_0a27d62e6e8bf5091427aee6137f04b7e8d054a56d4a3c4721d2b9950640ec16 */

undefined2 __cdecl16near FUN_1000_e6db(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



/* 0x1e6e4 ev_4b02ffbe70b373e03e6206b5f012745da89bef6c0bb3eccd1001cb4b4acb5174 */

undefined1 __cdecl16near FUN_1000_e6e4(undefined2 param_1,undefined1 param_2)

{
  out(param_1,param_2);
  return param_2;
}



/* 0x1e6f0 ev_5911541e7023425208bc8f33aef9d80a699c5931bb51211f63ec4e9badc71d10 */

undefined4 __cdecl16near FUN_1000_e6f0(undefined2 param_1,undefined2 param_2)

{
  out(param_1,param_2);
  return CONCAT22(param_1,param_2);
}



/* 0x1e6fc ev_a0d24ada70681d57817c78fe9b1e14fdc9e98c0e49b716e7ab782eba22806c1c */

void __cdecl16near FUN_1000_e6fc(undefined2 *param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *param_1 = 0x1000;
  param_1[1] = unaff_SS;
  param_1[2] = unaff_DS;
  param_1[3] = unaff_DS;
  return;
}



/* 0x1e717 ev_92abfbe1a4a0d1ce18f6876d451e67329d458a2c85e7950cdbfc527370f471a9 */

char * __cdecl16near FUN_1000_e717(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined2 unaff_DS;
  
  iVar3 = 0x7fff;
  pcVar4 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar2 = pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar2 != '\0');
  pcVar4 = pcVar4 + -1;
  iVar3 = 0x7fff;
  do {
    pcVar2 = param_2;
    param_2 = param_2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar4;
    pcVar4 = pcVar4 + 1;
    *pcVar2 = cVar1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0 && cVar1 != '\0');
  if (cVar1 != '\0') {
    *pcVar4 = '\0';
  }
  return param_1;
}



/* 0x1e74e ev_b005eb4dc7fa21fc81f4e1816f2ed590cd1edbe1ac1e6e12f814db532b3f27ea */

char * __cdecl16near FUN_1000_e74e(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  pcVar3 = param_1;
  do {
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar1 = cVar2;
  } while (cVar2 != '\0');
  return param_1;
}



/* 0x1e76b ev_9ab7237111411dadb57c58b82371b8d6761c7048a191c5543378cb391424cc7c */

char * __cdecl16near FUN_1000_e76b(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  pcVar3 = param_1;
  while( true ) {
    if (param_3 == 0) {
      return param_1;
    }
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    if (*pcVar1 == '\0') break;
    pcVar2 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar2 = *pcVar1;
    param_3 = param_3 + -1;
  }
  for (; param_3 != 0; param_3 = param_3 + -1) {
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar1 = '\0';
  }
  return param_1;
}



/* 0x1e793 ev_159781aac34430b889245a5e8067ed315a71ba2409967c6b88a17d19fc2e2689 */

char __cdecl16near FUN_1000_e793(char param_1)

{
  if (('`' < param_1) && (param_1 < '{')) {
    param_1 = param_1 + -0x20;
  }
  return param_1;
}



/* 0x1e7a7 ev_3fe084c8a1e91093056a652726cc8facb3025c60377543430f9b66c7373f4449 */

char __cdecl16near FUN_1000_e7a7(char param_1)

{
  if (('@' < param_1) && (param_1 < '[')) {
    param_1 = param_1 + ' ';
  }
  return param_1;
}



/* 0x1e7bd ev_ba1c31193f16aaa822786766079f540c35655dd3994a968a0335b7beb1dfb4b1 */

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl16near FUN_1000_e7bd(void)

{
  int in_AX;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_SS;
  code *in_stack_00000000;
  undefined2 auStack_6 [3];
  
  *(undefined2 *)((int)auStack_6 + in_AX + 4) = unaff_DI;
  *(undefined2 *)((int)auStack_6 + in_AX + 2) = unaff_SI;
  *(undefined2 *)((int)auStack_6 + in_AX) = 0xe7c7;
  (*in_stack_00000000)();
  return;
}



/* 0x1e7cd ev_e6f38b74aa11cb770435e423b591b822feff560485e022610ba3f33f479bc157 */

undefined2 __cdecl16near FUN_1000_e7cd(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = FUN_1000_ea3b();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_1000_e7f0(param_1,param_2,iVar1);
  }
  return uVar2;
}



/* 0x1e7f0 ev_3acd6eaf4d5bf1fff3c6a704cf3af0f413e71c2a6e2bef2cd6f6f4a277f4069a */

int __cdecl16near FUN_1000_e7f0(undefined2 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  undefined2 unaff_DS;
  
  FUN_1000_e913(param_3);
  pcVar2 = (char *)0x8d34;
  while( true ) {
    if (*pcVar2 == '\0') {
      *(undefined2 *)0x8f00 = 1;
      return 0;
    }
    iVar1 = FUN_1000_f105(pcVar2,param_2);
    if (iVar1 == 0) break;
    pcVar2 = pcVar2 + 5;
  }
  iVar1 = FUN_1000_efbb(param_1,*(undefined2 *)(pcVar2 + 3));
  if (iVar1 == -1) {
    return 0;
  }
  *(undefined1 *)(param_3 + 7) = (char)iVar1;
  *(undefined1 *)(param_3 + 6) = 1;
  return param_3;
}



/* 0x1e852 ev_a780240561a816ed1955c866cbc72282b9c6be5217a91a6eb59af323057c25bd */

int __cdecl16near FUN_1000_e852(char *param_1,int param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0;
  while( true ) {
    if ((uint)(param_2 * param_3) <= uVar2) {
      return param_3;
    }
    iVar1 = FUN_1000_e8c5((int)*param_1,param_4);
    if (iVar1 == -1) break;
    uVar2 = uVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}



/* 0x1e892 ev_707be4b24a5efd736e1b98eb799d9673a3977b7f9ce2c79b7562752b6b4830d9 */

undefined2 __cdecl16near FUN_1000_e892(int param_1,undefined2 param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  if ((param_1 == 10) && (iVar1 = FUN_1000_e8c5(0xd,param_2), iVar1 == -1)) {
    return 0xffff;
  }
  uVar2 = FUN_1000_e8c5(param_1,param_2);
  return uVar2;
}



/* 0x1e8c5 ev_c6801433e5e8ac2fba03a6ff213ff29a292e4b8a0b0aab5f734497dcb5657aa4 */

uint __cdecl16near FUN_1000_e8c5(byte param_1,uint *param_2)

{
  byte *pbVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  if (*param_2 < param_2[1]) {
    pbVar1 = (byte *)*param_2;
    *param_2 = *param_2 + 1;
    *pbVar1 = param_1;
    uVar2 = (uint)param_1;
  }
  else {
    uVar2 = FUN_1000_e983(param_2,param_1);
  }
  return uVar2;
}



/* 0x1e913 ev_3a38db09a64c2e42b70de0710faea1f9ebb1d02ed301b05e90c1c5e6555425cb */

uint __cdecl16near FUN_1000_e913(undefined2 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0;
  if (param_1 == (undefined2 *)0x0) {
    uVar2 = 0xffff;
  }
  else {
    if (*(char *)(param_1 + 3) != '\0') {
      if ((*(byte *)(param_1 + 3) & 4) != 0) {
        uVar2 = FUN_1000_e983(param_1,0xffff);
      }
      uVar1 = FUN_1000_f416((int)*(char *)((int)param_1 + 7));
      uVar2 = uVar2 | uVar1;
      if ((*(byte *)(param_1 + 3) & 2) != 0) {
        FUN_1000_ec0b(param_1[2]);
      }
      if ((*(byte *)(param_1 + 3) & 0x20) != 0) {
        FUN_1000_f44d(*(undefined2 *)((int)param_1 + 0xb));
        FUN_1000_ec0b(*(undefined2 *)((int)param_1 + 0xb));
      }
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
  }
  return uVar2;
}



/* 0x1e983 ev_10678eea9da8a6dc35df292dba60d52c53ce5dcbb4bfc3358ba87988bb14f41e */

uint __cdecl16near FUN_1000_e983(int *param_1,uint param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x8f0e = 0xe8f5;
  if ((*(byte *)(param_1 + 3) & 0x10) != 0) {
    return 0xffff;
  }
  if (((*(byte *)(param_1 + 3) & 4) == 0) ||
     (iVar4 = *param_1, iVar1 = param_1[2],
     iVar3 = FUN_1000_f3e7((int)*(char *)((int)param_1 + 7),param_1[2],iVar4 - iVar1),
     iVar3 == iVar4 - iVar1)) {
    if (param_2 == 0xffff) {
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfb;
      *param_1 = 0;
      param_1[1] = 0;
      return 0;
    }
    if (param_1[2] == 0) {
      FUN_1000_ea5e(param_1);
    }
    if (*(int *)((int)param_1 + 9) != 1) {
      iVar4 = param_1[2];
      *param_1 = iVar4;
      param_1[1] = iVar4 + *(int *)((int)param_1 + 9);
      *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 4;
      puVar2 = (undefined1 *)*param_1;
      *param_1 = *param_1 + 1;
      *puVar2 = (char)param_2;
      return param_2 & 0xff;
    }
    iVar4 = FUN_1000_f3e7((int)*(char *)((int)param_1 + 7),&param_2,1);
    if (iVar4 == 1) {
      return param_2;
    }
  }
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 0x10;
  *param_1 = 0;
  param_1[1] = 0;
  return 0xffff;
}



/* 0x1ea3b ev_f4ee47a0df4ca176190940cfd77ce67c374d11da1f414cadadf8e36a737b468a */

uint __cdecl16near FUN_1000_ea3b(void)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = 0x8d62;
  do {
    if (*(char *)(uVar1 + 6) == '\0') {
      return uVar1;
    }
    uVar1 = uVar1 + 0xd;
  } while (uVar1 < 0x8e66);
  return 0;
}



/* 0x1ea5e ev_668b0ee392c05dad42a252b63a6b564429621bc2e234542750822ae20a9e8ba9 */

void __cdecl16near FUN_1000_ea5e(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_f592((int)*(char *)(param_1 + 7));
  if ((iVar1 == 0) && (iVar1 = FUN_1000_eb10(0x400), iVar1 != 0)) {
    *(undefined2 *)(param_1 + 9) = 0x400;
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 2;
    *(int *)(param_1 + 4) = iVar1;
    return;
  }
  *(undefined2 *)(param_1 + 9) = 1;
  *(int *)(param_1 + 4) = param_1 + 8;
  return;
}



/* 0x1eb10 ev_dc99326dcc45a9ada461b7e6c92c69e7cb6fee5c9884ac801489230154d5ba8f */

uint * __cdecl16near FUN_1000_eb10(int param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined2 unaff_DS;
  int local_8;
  int local_6;
  uint *local_4;
  
  uVar1 = param_1 + 3U & 0xfffe;
  if (*(int *)0x8f58 == 0) {
    *(undefined2 *)0x8f56 = 0x8f56;
    *(uint *)0x8f56 = *(uint *)0x8f56 | 1;
    *(undefined2 *)0x8f58 = 0x8f56;
  }
  local_8 = 0;
  puVar3 = (uint *)*(undefined2 *)0x8f58;
  local_4 = puVar3;
  do {
    if ((puVar3 == (uint *)*(undefined2 *)0x8e66) && (local_8 = local_8 + 1, 1 < local_8)) {
      local_6 = 0x400;
      puVar2 = (uint *)FUN_1000_f5b2(0x400);
      if (puVar2 == (uint *)0xffff) {
        return (uint *)0x0;
      }
      if (puVar3 + 1 != puVar2) {
        *puVar3 = (uint)puVar2;
        *puVar3 = *puVar3 | 1;
        local_6 = 0x3fe;
        puVar3 = puVar2;
      }
      puVar2 = (uint *)((int)puVar3 + local_6);
      *puVar3 = (uint)puVar2;
      *puVar2 = 0x8f56;
      *puVar2 = *puVar2 | 1;
      *(undefined2 *)0x8e66 = puVar2;
      if ((uint *)(*local_4 & 0xfffe) == puVar3) {
        puVar3 = local_4;
      }
    }
    if ((*puVar3 & 1) == 0) {
      while (puVar2 = (uint *)(*puVar3 & 0xfffe), (*puVar2 & 1) == 0) {
        *puVar3 = *puVar2;
      }
      local_4 = puVar3;
      if (uVar1 <= (uint)((int)puVar2 - (int)puVar3)) {
        if (uVar1 < (uint)((int)puVar2 - (int)puVar3)) {
          *puVar3 = (int)puVar3 + uVar1;
          *(undefined2 *)0x8f5a = *(undefined2 *)((int)puVar3 + uVar1);
          *(undefined2 *)*puVar3 = puVar2;
        }
        *(uint *)0x8f58 = *puVar3;
        *puVar3 = *puVar3 | 1;
        return puVar3 + 1;
      }
    }
    puVar3 = (uint *)(*puVar3 & 0xfffe);
  } while( true );
}



/* 0x1ec0b ev_304366000eb747705dc0c5253d956eacfcee28ea45b928645586748c9add8790 */

undefined2 __cdecl16near FUN_1000_ec0b(int param_1)

{
  undefined2 uVar1;
  uint *puVar2;
  undefined2 unaff_DS;
  
  puVar2 = (uint *)(param_1 + -2);
  if ((*puVar2 & 1) == 0) {
    uVar1 = 0xffff;
  }
  else {
    *puVar2 = *puVar2 & 0xfffe;
    *(undefined2 *)0x8f58 = puVar2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 0x1ec2e ev_29ef50791932ef058a2aaeeeff63813ce0a4f6a3744f610c00e66a7db248c6bf */

undefined1 * __cdecl16near FUN_1000_ec2e(int *param_1,int param_2,undefined1 *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 unaff_DS;
  long lVar4;
  int local_4;
  
  if (param_4 == 4) {
    local_4 = param_1[1];
  }
  else if (param_2 < 1) {
    local_4 = *param_1 >> 0xf;
  }
  else {
    local_4 = 0;
  }
  bVar1 = false;
  if (((param_2 < 0) && (local_4 < 1)) && (local_4 != 0)) {
    bVar1 = true;
  }
  do {
    puVar3 = param_3;
    iVar2 = FUN_1000_f09f();
    param_3 = puVar3 + -1;
    *param_3 = *(undefined1 *)(iVar2 + -0x7196);
    lVar4 = FUN_1000_f0a7();
  } while (lVar4 != 0);
  if (bVar1) {
    param_3 = puVar3 + -2;
    *param_3 = 0x2d;
  }
  return param_3;
}



/* 0x1ece8 ev_132f0be684dab0b0a33295b933a79846669945ee557e867e0f0351ee08cb9212 */

int __cdecl16near FUN_1000_ece8(code *param_1,char *param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 unaff_DS;
  bool bVar5;
  char local_d1 [187];
  char *local_16;
  int local_14;
  char *local_12;
  int local_10;
  char *local_e;
  int local_c;
  uint local_a;
  int local_8;
  int *local_6;
  int local_4;
  
  local_8 = 0;
  local_6 = param_3;
  do {
    while( true ) {
      local_4 = (int)*param_2;
      if (local_4 == 0) {
        return local_8;
      }
      if (local_4 == 0x25) break;
      iVar2 = (*param_1)(local_4);
      if (iVar2 == -1) {
        return -1;
      }
      local_8 = local_8 + 1;
      param_2 = param_2 + 1;
    }
    local_d1[1] = 0;
    local_c = 0x20;
    local_e = (char *)0x2710;
    local_4 = (int)param_2[1];
    bVar5 = local_4 == 0x2d;
    pcVar3 = param_2 + 2;
    if (bVar5) {
      pcVar3 = param_2 + 3;
      local_4 = (int)param_2[2];
    }
    local_a = (uint)!bVar5;
    pcVar4 = pcVar3;
    if (local_4 == 0x30) {
      local_c = 0x30;
      pcVar4 = pcVar3 + 1;
      local_4 = (int)*pcVar3;
    }
    if (local_4 == 0x2a) {
      local_10 = *local_6;
      pcVar3 = pcVar4 + 1;
      local_4 = (int)*pcVar4;
      local_6 = local_6 + 1;
    }
    else {
      local_10 = 0;
      pcVar3 = pcVar4;
      while ((*(byte *)(local_4 + -0x7183) & 4) != 0) {
        local_10 = local_10 * 10 + local_4 + -0x30;
        local_4 = (int)*pcVar3;
        pcVar3 = pcVar3 + 1;
      }
    }
    if (local_4 == 0x2e) {
      pcVar4 = pcVar3 + 1;
      local_4 = (int)*pcVar3;
      if (local_4 == 0x2a) {
        local_e = (char *)*local_6;
        pcVar3 = pcVar3 + 2;
        local_4 = (int)*pcVar4;
        local_6 = local_6 + 1;
      }
      else {
        local_e = (char *)0x0;
        pcVar3 = pcVar4;
        while ((*(byte *)(local_4 + -0x7183) & 4) != 0) {
          local_e = (char *)((int)local_e * 10 + local_4 + -0x30);
          local_4 = (int)*pcVar3;
          pcVar3 = pcVar3 + 1;
        }
      }
    }
    local_12 = (char *)0x2;
    if (local_4 == 0x6c) {
      local_4 = (int)*pcVar3;
      local_12 = (char *)0x4;
      param_2 = pcVar3 + 1;
    }
    else {
      param_2 = pcVar3;
      if (local_4 == 0x68) {
        param_2 = pcVar3 + 1;
        local_4 = (int)*pcVar3;
      }
    }
    if (local_4 == 99) {
      local_4 = *local_6;
      local_6 = local_6 + 1;
LAB_1000_ee8e:
      local_16 = local_d1;
      local_d1[0] = (char)local_4;
LAB_1000_eebc:
      local_12 = local_d1 + (1 - (int)local_16);
    }
    else {
      if (local_4 == 100) {
        local_14 = -10;
LAB_1000_ee4d:
        local_16 = (char *)FUN_1000_ec2e(local_6,local_14,local_d1 + 1,local_12);
        local_6 = (int *)((int)local_6 + (int)local_12);
        goto LAB_1000_eebc;
      }
      if (local_4 == 0x6f) {
        local_14 = 8;
        goto LAB_1000_ee4d;
      }
      if (local_4 != 0x73) {
        if (local_4 == 0x75) {
          local_14 = 10;
        }
        else {
          if (local_4 != 0x78) goto LAB_1000_ee8e;
          local_14 = 0x10;
        }
        goto LAB_1000_ee4d;
      }
      local_16 = (char *)*local_6;
      local_6 = local_6 + 1;
      local_12 = (char *)FUN_1000_f139(local_16);
    }
    if ((int)local_e < (int)local_12) {
      local_12 = local_e;
    }
    if (local_a != 0) {
      if (((*local_16 == '-') || (*local_16 == '+')) && (local_c == 0x30)) {
        local_10 = local_10 + -1;
        pcVar1 = local_16;
        local_16 = local_16 + 1;
        iVar2 = (*param_1)((int)*pcVar1);
        if (iVar2 == -1) {
          return -1;
        }
      }
      while (iVar2 = local_10 + -1, bVar5 = (int)local_12 < local_10, local_10 = iVar2, bVar5) {
        iVar2 = (*param_1)(local_c);
        if (iVar2 == -1) {
          return -1;
        }
        local_8 = local_8 + 1;
      }
    }
    for (local_14 = 0; (*local_16 != '\0' && (local_14 < (int)local_e)); local_14 = local_14 + 1) {
      pcVar1 = local_16;
      local_16 = local_16 + 1;
      iVar2 = (*param_1)((int)*pcVar1);
      if (iVar2 == -1) {
        return -1;
      }
    }
    local_8 = local_8 + local_14;
    if (local_a == 0) {
      while (iVar2 = local_10 + -1, bVar5 = (int)local_12 < local_10, local_10 = iVar2, bVar5) {
        iVar2 = (*param_1)(0x20);
        if (iVar2 == -1) {
          return -1;
        }
        local_8 = local_8 + 1;
      }
    }
  } while( true );
}



/* 0x1efbb ev_cc6fbd2e62f134e8cb58ff2eccfcd678966427170d3c77fc8571e25e6f1c1151 */

int __cdecl16near FUN_1000_efbb(undefined2 param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  uVar3 = param_2 & 3 | 0x3d00;
  if ((param_2 & 0x200) != 0) {
    uVar3 = 0x3c00;
  }
  iVar2 = FUN_1000_f156(uVar3,param_1,0);
  if (iVar2 == -1) {
    if ((param_2 & 0x100) != 0) {
      iVar2 = FUN_1000_f156(0x3c,param_1,0);
    }
  }
  else if ((param_2 & 0x400) != 0) {
    FUN_1000_f416(iVar2);
    *(undefined2 *)0x8f00 = 0x13;
    return -1;
  }
  if (-1 < iVar2) {
    if ((param_2 & 0x800) != 0) {
      FUN_1000_f42e(iVar2,0,0,2);
    }
    uVar1 = FUN_1000_f592(iVar2);
    *(undefined1 *)(iVar2 + -0x70e0) = uVar1;
  }
  return iVar2;
}



/* 0x1f04d ev_d6050d71c32be0c4351737cd78451b788dff0f92067bdbcbfdfbb1b3ad542267 */

int __cdecl16near FUN_1000_f04d(void)

{
  int iVar1;
  int in_DX;
  int in_BX;
  bool bVar2;
  
  bVar2 = in_DX < 0;
  if (in_BX < 0) {
    bVar2 = !bVar2;
  }
  iVar1 = FUN_1000_f0a7();
  if (bVar2) {
    iVar1 = -iVar1;
  }
  return iVar1;
}



/* 0x1f07b ev_95e17a81bd0c40281cf1cc7cd104a00cce0e773deac97cf81496f6324def0abf */

undefined4 __cdecl16near FUN_1000_f07b(void)

{
  int in_CX;
  int in_DX;
  int in_BX;
  bool bVar1;
  
  if (in_BX < 0) {
    bVar1 = in_CX != 0;
    in_CX = -in_CX;
    in_BX = -(uint)bVar1 - in_BX;
  }
  FUN_1000_f0a7();
  if (in_DX < 0) {
    bVar1 = in_CX != 0;
    in_CX = -in_CX;
    in_BX = -(uint)bVar1 - in_BX;
  }
  return CONCAT22(in_BX,in_CX);
}



/* 0x1f09f ev_71e4f514449f060832b232a5a476ec06143628e357cf132ec7ab04e1210b666d */

undefined4 __cdecl16near FUN_1000_f09f(void)

{
  undefined2 in_CX;
  undefined2 in_BX;
  
  FUN_1000_f0a7();
  return CONCAT22(in_BX,in_CX);
}



/* 0x1f0a7 ev_39631a153c859ce8e5c4974d1d83dcedb0fcf6a57f8d7cf72d7c91258cf0b39c */

ulong __cdecl16near FUN_1000_f0a7(void)

{
  ulong uVar1;
  bool bVar2;
  uint in_AX;
  uint in_CX;
  int iVar3;
  uint in_DX;
  int in_BX;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (in_BX == 0) {
    if (in_CX <= in_DX) {
      return CONCAT22(in_DX / in_CX,
                      (int)(((ulong)in_DX % (ulong)in_CX << 0x10 | (ulong)in_AX) / (ulong)in_CX));
    }
    return CONCAT22(in_DX,in_AX) / (ulong)in_CX & 0xffff;
  }
  iVar4 = 0;
  iVar5 = 0;
  iVar3 = 0x20;
  do {
    uVar1 = (ulong)CONCAT12((int)in_AX < 0,in_DX) << 1;
    in_DX = (uint)uVar1 | (uint)((int)in_AX < 0);
    bVar2 = (uVar1 & 0x10000) != 0;
    uVar1 = (ulong)CONCAT12(bVar2,iVar5) << 1;
    uVar6 = (uint)uVar1 | (uint)bVar2;
    iVar5 = uVar6 - in_CX;
    for (iVar4 = ((iVar4 << 1 | (uint)((uVar1 & 0x10000) != 0)) - in_BX) - (uint)(uVar6 < in_CX);
        in_AX = in_AX * 2, iVar4 < 0;
        iVar4 = (iVar4 << 1 | (uint)((uVar1 & 0x10000) != 0)) + in_BX + (uint)CARRY2(uVar6,in_CX)) {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) goto LAB_1000_f0ff;
      uVar1 = (ulong)CONCAT12((int)in_AX < 0,in_DX) << 1;
      in_DX = (uint)uVar1 | (uint)((int)in_AX < 0);
      bVar2 = (uVar1 & 0x10000) != 0;
      uVar1 = (ulong)CONCAT12(bVar2,iVar5) << 1;
      uVar6 = (uint)uVar1 | (uint)bVar2;
      iVar5 = uVar6 + in_CX;
    }
    in_AX = in_AX + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
LAB_1000_f0ff:
  return CONCAT22(in_DX,in_AX);
}



/* 0x1f105 ev_c022696e21b3fbb362d48f7646e9f45ab212d531b76b9184acf083b6c9508340 */

undefined2 __cdecl16near FUN_1000_f105(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  iVar3 = 0x7fff;
  do {
    pbVar1 = param_1;
    param_1 = param_1 + 1;
    bVar2 = *pbVar1;
    pbVar1 = param_2;
    param_2 = param_2 + 1;
    if (bVar2 != *pbVar1) {
      if (*pbVar1 <= bVar2) {
        return 1;
      }
      return 0xffff;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0 && bVar2 != 0);
  return 0;
}



/* 0x1f139 ev_672cd776b9d1e07ebb1716a46a94fc4375a25ea5de0b28a9ed649d1155f64747 */

char * __cdecl16near FUN_1000_f139(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  iVar2 = 0x7fff;
  pcVar3 = param_1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar1 = pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (*pcVar1 != '\0');
  return pcVar3 + (-1 - (int)param_1);
}



/* 0x1f156 ev_afe1af63319418133a606a12c195211512bae8ac75f8794056b1c0506afcd406 */

uint __cdecl16near FUN_1000_f156(int param_1)

{
  code *pcVar1;
  byte bVar3;
  uint uVar2;
  undefined2 unaff_DS;
  bool bVar4;
  
  if ((char)((uint)param_1 >> 8) == '\0') {
    param_1 = param_1 << 8;
  }
  bVar3 = (byte)((uint)param_1 >> 8);
  if (9 < bVar3) {
    bVar4 = bVar3 < 0x47;
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    if (bVar4) {
      *(uint *)0x8f00 = uVar2;
      uVar2 = 0xffff;
    }
    return uVar2;
  }
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  return uVar2 & 0xff;
}



/* 0x1f19c ev_86c71ece42ee47c2ca5f4020035270b92cf8926e574c6f4b7352b851a54c9cda */

/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x0001f1a3) */

void entry(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined2 *puVar3;
  code *pcVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  char *pcVar10;
  undefined2 *puVar11;
  char *pcVar12;
  uint unaff_DS;
  bool bVar13;
  
  uVar8 = *(int *)0x2 + 0xe072;
  DAT_1000_f19a = unaff_DS;
  if (0x1000 < uVar8) {
    pcVar4 = (code *)swi(0x21);
    (*pcVar4)();
    uVar8 = 0;
  }
  puVar9 = (undefined1 *)(uVar8 << 4);
  if (DAT_1f8e_8f3e != 0) {
    puVar9 = (undefined1 *)(DAT_1f8e_8f3a * 0x10 + -0x5f6e);
  }
  DAT_1f8e_8f0a = puVar9;
  if (puVar9 == (undefined1 *)0x0) {
    DAT_1f8e_8f0a = (undefined1 *)0xffff;
  }
  DAT_1f8e_8f0c = unaff_DS;
  if (DAT_1f8e_8f3e != 0) {
    DAT_1f8e_8efe = (char *)((int)DAT_1f8e_8f0a + 1);
    bVar13 = CARRY2((uint)DAT_1f8e_8f0a,DAT_1f8e_8f3c * 0x10);
    DAT_1f8e_8f0a = (undefined1 *)((int)DAT_1f8e_8f0a + DAT_1f8e_8f3c * 0x10);
    if (bVar13) {
      DAT_1f8e_8f0a = (undefined1 *)0xffff;
    }
    bVar13 = ((int)DAT_1f8e_8f0a + 0xfU >> 4) + 0x1f8e < unaff_DS;
    pcVar4 = (code *)swi(0x21);
    (*pcVar4)();
    if (bVar13) {
      pcVar4 = (code *)swi(0x21);
      (*pcVar4)();
      if (bVar13) goto LAB_1000_f2e1;
    }
  }
  puVar11 = (undefined2 *)0x8f44;
  for (iVar6 = 0x8a7; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar3 = 0;
  }
  uVar8 = *(uint *)0x2c;
  pcVar12 = (char *)0x0;
  uVar7 = 0x7fff;
  do {
    if (*pcVar12 == '=') {
      uVar5 = 0;
      pcVar10 = pcVar12 + 1;
      *pcVar12 = '\0';
      goto LAB_1000_f28f;
    }
    bVar13 = false;
    if (*pcVar12 == '\0') break;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar1 = pcVar12;
      pcVar12 = pcVar12 + 1;
      bVar13 = *pcVar1 == '\0';
    } while (!bVar13);
  } while (bVar13);
  uVar7 = (uint)*(byte *)0x80;
  pcVar10 = (char *)0x81;
  uVar5 = 1;
  uVar8 = unaff_DS;
LAB_1000_f28f:
  *(undefined2 *)(puVar9 + -2) = uVar5;
  *(char **)(puVar9 + -4) = DAT_1f8e_8efe;
  for (; uVar7 != 0; uVar7 = uVar7 - 1) {
    pcVar1 = pcVar10;
    pcVar10 = pcVar10 + 1;
    if (*pcVar1 == '\0') break;
    pcVar2 = DAT_1f8e_8efe;
    DAT_1f8e_8efe = DAT_1f8e_8efe + 1;
    *pcVar2 = *pcVar1;
  }
  *DAT_1f8e_8efe = '\0';
  DAT_1f8e_8efe = (char *)((uint)(DAT_1f8e_8efe + 2) & 0xfffe);
  if (DAT_1f8e_8f3e == 0) {
    iVar6 = DAT_1f8e_8f3a;
    if (DAT_1f8e_8f3a == 0) {
      iVar6 = 0x800;
    }
    DAT_1f8e_8f08 = puVar9 + iVar6 * -0x10 + -4;
  }
  DAT_1f8e_8f02 = 0x1f8e;
  DAT_1f8e_8f04 = 0x1000;
  DAT_1f8e_8f06 = DAT_1f8e_8efe;
  *(undefined2 *)(puVar9 + -6) = 0xf2dd;
  FUN_1000_f2f3();
LAB_1000_f2e1:
  pcVar4 = (code *)swi(0x21);
  (*pcVar4)();
                    /* WARNING: Could not recover jumptable at 0x0001f2e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(ulong)DAT_1000_f198)();
  return;
}



/* 0x1f2df ev_ce357fa474d426b37e2357095a2ffab7916aa677efd9ab06e80e15530fa76976 */

void FUN_1000_f2df(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
                    /* WARNING: Could not recover jumptable at 0x0001f2e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(ulong)DAT_1000_f198)();
  return;
}



/* 0x1f2f3 ev_17f564d5781ec13d5b569f3a11c7215e8a6fc2a7ecebe4b822d44983a2727521 */

void __cdecl16near FUN_1000_f2f3(char *param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined2 *puVar6;
  undefined2 unaff_DS;
  char *pcVar5;
  
  uVar1 = FUN_1000_f592(0);
  *(undefined1 *)0x8f20 = uVar1;
  uVar1 = FUN_1000_f592(1);
  *(undefined1 *)0x8f21 = uVar1;
  uVar1 = FUN_1000_f592(2);
  *(undefined1 *)0x8f22 = uVar1;
  puVar2 = (undefined2 *)FUN_1000_f5b2((param_2 + 1) * 2);
  *(undefined2 *)0x8f5c = puVar2;
  *puVar2 = 0x8f10;
  *(int *)0x8f5e = param_2;
  puVar2 = (undefined2 *)(param_2 * 2 + *(int *)0x8f5c);
LAB_1000_f33c:
  do {
    for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
    }
    if (*param_1 == '\0') {
      *puVar2 = 0;
      FUN_1000_0000(*(undefined2 *)0x8f5e,*(undefined2 *)0x8f5c);
      FUN_1000_f3ba(0);
      return;
    }
    puVar6 = puVar2 + 1;
    *puVar2 = param_1;
    *(int *)0x8f5e = *(int *)0x8f5e + 1;
    iVar3 = FUN_1000_f5b2(2);
    if (iVar3 == -1) {
      FUN_1000_f3e7(2,0x8f11,0xe);
      FUN_1000_f2df(200);
    }
    do {
      pcVar5 = param_1;
      pcVar4 = pcVar5 + 1;
      param_1 = pcVar4;
      puVar2 = puVar6;
      if (*pcVar4 == '\0') goto LAB_1000_f33c;
    } while ((*pcVar4 != ' ') && (*pcVar4 != '\t'));
    param_1 = pcVar5 + 2;
    *pcVar4 = '\0';
  } while( true );
}



/* 0x1f3ba ev_14dc57c49dd526ca917b214bcc111fca2c47fecf22b4ef52483dd9305de182c8 */

void __cdecl16near FUN_1000_f3ba(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  (*(code *)*(undefined2 *)0x8f0e)();
  FUN_1000_f2df(param_1);
  return;
}



/* 0x1f3cc ev_72352dbbd2b5b2a94c81d5765e2bec150ce736b657a3b82c1fd02aa420ec3e4c */

void FUN_1000_f3cc(void)

{
  FUN_1000_f404();
  return;
}



/* 0x1f3d6 ev_82927df802f88460e6656b2afc960c897b8c8d1c01bc9aa065a26d0f6bda3d38 */

void FUN_1000_f3d6(void)

{
  FUN_1000_f404();
  return;
}



/* 0x1f3e0 ev_042e2b1b53199e50dd8522ee152a7d7d57fa2163cf7360137a5c2a2b6b870d13 */

/* WARNING: Removing unreachable block (ram,0x0001f3fc) */

undefined2 FUN_1000_f3e0(int param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  
  bVar3 = false;
  if (*(char *)(param_1 + -0x70e0) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0001f400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)*(undefined2 *)0x8f34)();
    return uVar2;
  }
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if (bVar3) {
    *(undefined2 *)0x8f00 = uVar2;
    uVar2 = 0xffff;
  }
  return uVar2;
}



/* 0x1f3e7 ev_c8fc51b299affea99c43a2362ae6dac111c8d69a087b6e517d6d40f8bdf29f06 */

/* WARNING: Removing unreachable block (ram,0x0001f400) */

undefined2 FUN_1000_f3e7(int param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  
  bVar3 = false;
  if (*(char *)(param_1 + -0x70e0) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0001f3fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)*(undefined2 *)0x8f36)();
    return uVar2;
  }
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if (bVar3) {
    *(undefined2 *)0x8f00 = uVar2;
    uVar2 = 0xffff;
  }
  return uVar2;
}



/* 0x1f404 ev_1823eebd798d66c94c37252c1f965647e67abc17d23c64ca97557d2f4ce7e345 */

undefined2 __cdecl16near FUN_1000_f404(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
    uVar2 = 0xffff;
  }
  return uVar2;
}



/* 0x1f416 ev_54171b9a98bd48754ca19bb5d8bcc2727bd8a99bc86c66cb1e9ef7b9b6f60402 */

undefined2 __cdecl16near FUN_1000_f416(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
    return 0xffff;
  }
  return 0;
}



/* 0x1f42e ev_7d3f4bdd012903c2b510504403a6d3a76c3c0137d7726245dfbbdf6d8078317f */

void __cdecl16near FUN_1000_f42e(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
  }
  return;
}



/* 0x1f44d ev_3977ca3d802b3955ea7a4fd9d8b74bd298f1e9de4a226127725d4c1b693fd720 */

undefined2 __cdecl16near FUN_1000_f44d(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
    return 0xffff;
  }
  return 0;
}



/* 0x1f465 ev_e7c98dff8b7252b521417dbacc256b1a99e7c63a3b1aa4d5c17acf297cb4873f */

undefined2 __cdecl16near FUN_1000_f465(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
    return 0xffff;
  }
  return 0;
}



/* 0x1f486 ev_83a51bfb81f102e1379902a2c1392baf24c916aa2b549ae05c7dd43f8253ac68 */

int __cdecl16near FUN_1000_f486(undefined2 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar2 = *(int *)0xa090;
  if (iVar2 == 0) {
    iVar1 = FUN_1000_f3cc(param_1,0x8f60,0x104);
    iVar2 = iVar1;
    if ((iVar1 != 0) && (*(char *)(iVar1 + -0x70a1) == '\n')) {
      iVar2 = iVar1 + -1;
      *(undefined1 *)(iVar1 + -0x70a2) = *(undefined1 *)0x8f38;
    }
    *(undefined2 *)0x9064 = 0x8f60;
    *(int *)0xa090 = iVar2;
  }
  if (param_3 < iVar2) {
    iVar2 = param_3;
  }
  if (iVar2 != 0) {
    FUN_1000_f54d(*(undefined2 *)0x9064,param_2,iVar2);
  }
  *(int *)0x9064 = *(int *)0x9064 + iVar2;
  *(int *)0xa090 = *(int *)0xa090 - iVar2;
  return iVar2;
}



/* 0x1f4eb ev_2f0312fc0c416c8e46632844f1bf3f1377dea23604e2d0b747fa21736909184d */

int __cdecl16near FUN_1000_f4eb(undefined2 param_1,char *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined2 unaff_DS;
  
  iVar2 = param_3;
  pcVar4 = param_2;
  while (iVar3 = iVar2 + -1, iVar2 != 0) {
    pcVar5 = pcVar4 + 1;
    pcVar1 = pcVar4;
    iVar2 = iVar3;
    pcVar4 = pcVar5;
    if (*pcVar1 == '\n') {
      FUN_1000_f3d6(param_1,param_2,(int)pcVar5 - (int)param_2);
      FUN_1000_f3d6(param_1,0x8f39,1);
      param_2 = pcVar5;
    }
  }
  if (pcVar4 != param_2) {
    FUN_1000_f3d6(param_1,param_2,(int)pcVar4 - (int)param_2);
  }
  return param_3;
}



/* 0x1f54d ev_93f6707ede3359a9361baed1414d5f14e76a80eac7bd929af2d2f86f3f598386 */

void __cdecl16near FUN_1000_f54d(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 unaff_DS;
  byte bVar7;
  
  bVar7 = 0;
  if (param_2 != param_1) {
    if (param_2 < param_1) {
      if ((param_3 & 1) != 0) {
        puVar4 = param_2;
        param_2 = (undefined2 *)((int)param_2 + 1);
        puVar2 = param_1;
        param_1 = (undefined2 *)((int)param_1 + 1);
        *(undefined1 *)puVar4 = *(undefined1 *)puVar2;
      }
    }
    else {
      bVar7 = 1;
      puVar6 = (undefined1 *)((int)param_2 + (param_3 - 1));
      puVar5 = (undefined1 *)((int)param_1 + (param_3 - 1));
      if ((param_3 & 1) != 0) {
        puVar3 = puVar6;
        puVar6 = (undefined1 *)((int)param_2 + (param_3 - 2));
        puVar1 = puVar5;
        puVar5 = (undefined1 *)((int)param_1 + (param_3 - 2));
        *puVar3 = *puVar1;
      }
      param_2 = (undefined2 *)(puVar6 + -1);
      param_1 = (undefined2 *)(puVar5 + -1);
    }
    param_3 = param_3 >> 1;
    if (param_3 != 0) {
      for (; param_3 != 0; param_3 = param_3 - 1) {
        puVar4 = param_2;
        param_2 = param_2 + (uint)bVar7 * -2 + 1;
        puVar2 = param_1;
        param_1 = param_1 + (uint)bVar7 * -2 + 1;
        *puVar4 = *puVar2;
      }
    }
  }
  return;
}



/* 0x1f592 ev_b0eebcf43fbbc0a7a525c0393307bfee6584a7bd726f36062c5e03701425deca */

undefined2 __cdecl16near FUN_1000_f592(void)

{
  code *pcVar1;
  byte extraout_DL;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (((!(bool)in_CF) && ((extraout_DL & 0x80) != 0)) && ((extraout_DL & 3) != 0)) {
    return 1;
  }
  return 0;
}



/* 0x1f5b2 ev_3c3f48f195114d090ac01974ca9270bfb9f07dfef21d54bd760583cde1b890a3 */

int __cdecl16near FUN_1000_f5b2(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0x8efe;
  iVar2 = FUN_1000_f5cf(param_1 + iVar1);
  if (iVar2 == 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}



/* 0x1f5cf ev_f6bb2198332d0acdadce17404a1974b9205b5456f9828fd683438b6efc39447e */

undefined2 __cdecl16near FUN_1000_f5cf(int param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint unaff_BP;
  int unaff_DS;
  bool bVar4;
  undefined2 in_stack_00000000;
  
  puVar2 = (undefined1 *)(param_1 + 1U & 0xfffe);
  if ((undefined1 *)*(uint *)0x8f06 <= puVar2) {
    if (*(int *)0x8f3e == 0) {
      if (((undefined1 *)*(uint *)0x8f08 <= puVar2) || (&stack0xfffe <= puVar2)) goto LAB_1000_f646;
    }
    else if (((undefined1 *)*(uint *)0x8f0a < puVar2) || (puVar2 <= (undefined1 *)*(uint *)0x8efe))
    {
      uVar3 = (param_1 + 1U >> 4) + 0x41 & 0xffc0;
      bVar4 = uVar3 + unaff_DS < *(uint *)0x8f0c;
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(uVar3,puVar2);
      if ((!bVar4) && (*(undefined2 *)0x8efe = in_stack_00000000, (unaff_BP & 0xe000) == 0)) {
        *(int *)0x8f0a = unaff_BP << 4;
        return 0;
      }
      goto LAB_1000_f646;
    }
    *(uint *)0x8efe = (uint)puVar2;
    return 0;
  }
LAB_1000_f646:
  *(undefined2 *)0x8f00 = 0xfffc;
  return 0xffff;
}



/* 0x1f653 ev_134e1a8129944dc760cfbff219f2a3197a1a586418d590ffff3abaa7b5404839 */

void __cdecl16near FUN_1000_f653(int param_1)

{
  undefined2 unaff_DS;
  
  *(int *)0x8f08 = (int)(&stack0xfffe + -param_1);
  return;
}



/* 0x1f660 ev_1b24aecbedc00b6abc09bc2455054e3863f51a5c6ec1952eb64f9900ed95c115 */

void __cdecl16near FUN_1000_f660(int param_1)

{
  FUN_1000_f873(param_1);
  if (param_1 == 10) {
    FUN_1000_f873(0xd);
  }
  return;
}



/* 0x1f67e ev_a55271bab56b0692ce5d8627ae8a7917db3989ca8ce4febc956271ccd49d3bc3 */

void __cdecl16near FUN_1000_f67e(char *param_1)

{
  undefined2 unaff_DS;
  
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    FUN_1000_f660((int)*param_1);
  }
  FUN_1000_f660(10);
  return;
}



/* 0x1f6a4 ev_6af6298f540e952b8801d8212e69728d3f9e4fe5ec44eece6c924b4bd655af10 */

void __cdecl16near FUN_1000_f6a4(undefined2 param_1)

{
  FUN_1000_ece8(0xf660,param_1,&stack0x0004);
  return;
}



/* 0x1f6bf ev_f03a3d0a4804afad64c05d6ba2be4df1bc4dd06769c4df50697d75ee598aeb4e */

int __cdecl16near FUN_1000_f6bf(int param_1,uint param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0x8f42;
  *(uint *)0x8f42 = param_1 << 4 | param_2;
  if (param_4 == 0) {
    *(uint *)0x8f42 = *(uint *)0x8f42 & 0x7f;
  }
  else {
    *(uint *)0x8f42 = *(uint *)0x8f42 | 0x80;
  }
  if (param_3 == 0) {
    *(uint *)0x8f42 = *(uint *)0x8f42 & 0xf7;
  }
  else {
    *(uint *)0x8f42 = *(uint *)0x8f42 | 8;
  }
  *(uint *)0x8f42 = *(uint *)0x8f42 & 0xff;
  return (int)(char)uVar1;
}



/* 0x1f717 ev_2b971bbc60a87f662a861120d035b7e4f6a24dfecdd509a7412bbcde4b530c2a */

undefined2 __cdecl16near FUN_1000_f717(void)

{
  undefined2 unaff_DS;
  
  return *(undefined2 *)0x8f42;
}



/* 0x1f721 ev_143da99c284fac22a9e8cb6e60f4a6fbb53d4513339548a93b3dbbdbb07462aa */

int __cdecl16near FUN_1000_f721(undefined2 param_1)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0x8f42;
  *(undefined2 *)0x8f42 = param_1;
  return (int)(char)uVar1;
}



/* 0x1f73b ev_7388a132f2ad2ed7816e0b2c1a4fe7fe751177596ac21b3d12f3716d61d1e253 */

undefined2 __cdecl16near FUN_1000_f73b(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x8f40 = param_1;
  return 0;
}



/* 0x1f74a ev_5aa3bdd9a72646bb14bed9079015a071e49132074f621271ccf9f1034b1bac32 */

undefined2 __cdecl16near FUN_1000_f74a(void)

{
  undefined2 unaff_DS;
  int local_6;
  undefined1 local_4 [2];
  
  FUN_1000_f814(local_4,&local_6);
  FUN_1000_f8c2(0x920,*(undefined2 *)0x8f42,0x50 - local_6,0);
  return 0;
}



/* 0x1f77c ev_c85b144ed4c6af09374ae6eb0cf1244dfa280d3342656ba01375cc7b8fd48150 */

undefined2 __cdecl16near FUN_1000_f77c(void)

{
  undefined2 unaff_DS;
  int local_6;
  int local_4;
  
  FUN_1000_f814(&local_4,&local_6);
  FUN_1000_f8c2(0x920,*(undefined2 *)0x8f42,(0x18 - local_4) * 0x50 + (0x50 - local_6),0);
  return 0;
}



/* 0x1f7c2 ev_f784a4e18f1fe3313a7c7ee62243ac1f3033b1ba641307a09208c56f21e52df2 */

undefined2 __cdecl16near FUN_1000_f7c2(int param_1)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = 7;
  if (param_1 != 0) {
    uVar1 = 0x70;
  }
  *(undefined2 *)0x8f42 = uVar1;
  return 0;
}



/* 0x1f7da ev_4ae13e9a8b1f9c045d26679e538c6ce53860d557e6db0d18795d63b0db294509 */

undefined2 __cdecl16near FUN_1000_f7da(int param_1,uint param_2)

{
  if (0x4f < (int)param_2) {
    param_2 = 0x4f;
  }
  if (0x18 < param_1) {
    param_1 = 0x18;
  }
  FUN_1000_f8c2(0x200,0,0,param_1 << 8 | param_2);
  return 0;
}



/* 0x1f814 ev_eec2e4408375ed7671347198865e9c400632626e760e4e20f64abeecf9ea6c4c */

void __cdecl16near FUN_1000_f814(undefined1 *param_1,undefined1 *param_2)

{
  code *pcVar1;
  undefined1 extraout_DL;
  undefined1 extraout_DH;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  *param_1 = extraout_DH;
  param_1[1] = 0;
  *param_2 = extraout_DL;
  param_2[1] = 0;
  return;
}



/* 0x1f831 ev_83daa3f6d8cc6f27a935647cc487dbd971e166c1b5d29bab89b7d91723d3412b */

uint __cdecl16near FUN_1000_f831(void)

{
  code *pcVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x16);
  (*pcVar1)();
  uVar2 = FUN_1000_f858();
  if ((*(char *)0x8f40 != '\0') && (uVar2 < 0x80)) {
    FUN_1000_f873();
  }
  return uVar2;
}



/* 0x1f84a ev_37b2236f49506c89bff53251e2bf1887d3ef5deef987bdabd05eecb74e589c2c */

undefined2 __cdecl16near FUN_1000_f84a(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_ZF;
  
  pcVar1 = (code *)swi(0x16);
  (*pcVar1)();
  if ((bool)in_ZF) {
    return 0xffff;
  }
  uVar2 = FUN_1000_f858();
  return uVar2;
}



/* 0x1f858 ev_da65846c754ca8751dfa9c49ab2eadfab79f8dbc206b597899eb48c49f9dc4e3 */

uint __cdecl16near FUN_1000_f858(void)

{
  uint in_AX;
  byte bVar1;
  
  bVar1 = (byte)(in_AX >> 8);
  if ((char)in_AX != '\0') {
    return in_AX & 0xff;
  }
  if (bVar1 != 0) {
    if (bVar1 == 3) {
      return 0;
    }
    return bVar1 | 0x80;
  }
  return 0xfffe;
}



/* 0x1f873 ev_cc9035fc0507f3357baf806bc9b2262b2718d31efef75c20d55cd3be02c6a7e4 */

uint __cdecl16near FUN_1000_f873(uint param_1)

{
  undefined2 unaff_DS;
  int local_6;
  undefined2 local_4;
  
  FUN_1000_f8c2(param_1 & 0xff | 0x900,*(undefined2 *)0x8f42,1,0);
  FUN_1000_f814(&local_4,&local_6);
  local_6 = local_6 + 1;
  if (local_6 < 0x50) {
    FUN_1000_f7da(local_4,local_6);
  }
  return param_1 & 0xff;
}



/* 0x1f8c2 ev_0bc5ced5851b61c8fdb0cd2fa581f53148f179817d33143421dc1b06dcea0a56 */

void __cdecl16near FUN_1000_f8c2(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}



/* 0x1f93b ev_a6acd0c2da438d205e33f9d677ff85f8eb9bd8a7f3a1c2e4bef764f3f99f7f87 */

void FUN_1f8e_005b(void)

{
  FUN_1000_c121();
  return;
}

