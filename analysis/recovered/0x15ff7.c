/* ev_5d1befa20f20aef81a3316f32009f21f015a9c772dc56e5fd67d61840562972f */

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

