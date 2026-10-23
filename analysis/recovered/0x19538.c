/* ev_e22cba081ca86e6459b18940b5b4a3b8d3914bdbf9f41bd72047da0167bcb073 */

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

