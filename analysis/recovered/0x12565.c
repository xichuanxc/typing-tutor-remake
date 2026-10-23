/* ev_8f9965c3b0812f6b1bf77c45949a5162694e4d207f3ffb9451ec12175af5f00a */

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

