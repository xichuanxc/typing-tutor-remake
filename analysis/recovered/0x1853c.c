/* ev_26125d5a74230a9ecf31e5d54fdc7137064784c3ad6252834184cf2e89d17dc7 */

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

