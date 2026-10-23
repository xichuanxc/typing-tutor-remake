/* ev_91e10e5646bb5a847f96c8bfd06103d3a5351b8498cfbb6a284d76e936c04ce1 */

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

