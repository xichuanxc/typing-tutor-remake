/* ev_6ce47b8a72106bcc08f3f2b258be13d92a90070a9f06557a150eacd082226aa9 */

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

