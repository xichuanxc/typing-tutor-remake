/* ev_cdecc1ed7ad8a2bad5375ed0459f1498823ddc2be01e714f3ec0fd3c596683cf */

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

