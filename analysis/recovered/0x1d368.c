/* ev_9a7c056a0131b99e042e4f2bb2de486c45cff418014fa8f9aea0863745088848 */

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

