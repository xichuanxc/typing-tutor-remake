/* ev_04b76eb83d7781e2457aa689f06ba1ce95e0edb2b36e7c8200c5860e14767fcc */

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

