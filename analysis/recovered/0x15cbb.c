/* ev_47059c26d2c5e62f684758c8503355cafca7056fb3cbe3a98568afe29753a234 */

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

