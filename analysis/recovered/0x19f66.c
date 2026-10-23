/* ev_92323194178dd45c98488c3fd14981f80dd09f6c37a01ddc5e68884ac93b4959 */

undefined2 __cdecl16near FUN_1000_9f66(int param_1)

{
  char *pcVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  undefined2 unaff_DS;
  
  while( true ) {
    do {
      iVar4 = FUN_1000_f84a();
      if (iVar4 < 1) {
        return 0;
      }
      cVar3 = FUN_1000_f831();
    } while (((cVar3 == '\r') || (cVar3 == ' ')) && (*(int *)0xa06e == 0));
    if ((cVar3 == '\x1b') || (*(int *)(*(int *)0xa07e * 2 + -0x5f98) == 0)) break;
    if (*(int *)0xa06e == 0) {
      iVar4 = FUN_1000_e677(0x8498,(int)cVar3);
      if (((iVar4 == 0) && (' ' < cVar3)) &&
         ((cVar3 < '~' &&
          ((iVar4 = FUN_1000_91df((int)cVar3), *(char *)(iVar4 + param_1 + 0x21c) != '\0' &&
           (*(char *)(param_1 + iVar4 + 0x168) == '\0')))))) {
        uVar6 = (uint)*(byte *)(param_1 + iVar4 + 0x1c2);
        *(uint *)0xa070 = uVar6;
        *(undefined1 *)(uVar6 + param_1 + 0x4f6) = 1;
        *(int *)0xa076 = *(int *)0xa076 + 1;
        FUN_1000_b1f3(1,1,2);
        FUN_1000_4e79(*(undefined1 *)(param_1 + iVar4),*(undefined2 *)(iVar4 * 2 + param_1 + 0x5a),
                      (int)cVar3);
        if (*(byte *)(param_1 + *(int *)0xa070 + 0x4ce) < 2) {
          FUN_1000_b1f3(0,1,4);
          uVar2 = *(undefined2 *)(iVar4 * 2 + param_1 + 0x5a);
          *(undefined1 *)(param_1 + iVar4 + 0x168) = 0x15;
          FUN_1000_4e79(0x15,uVar2,0x18);
        }
        else {
          *(int *)0xa072 = iVar4;
          *(undefined2 *)0xa06e = 1;
        }
        FUN_1000_b1f3(0,1,7);
      }
      else {
        FUN_1000_9ecc();
      }
    }
    else if (*(char *)(*(int *)0xa070 * 0xf + param_1 + *(int *)0xa06e + 0x276) == cVar3) {
      FUN_1000_b1f3(1,1,2);
      FUN_1000_922d(*(undefined1 *)(param_1 + *(int *)0xa072),
                    *(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) + *(int *)0xa06e,(int)cVar3);
      *(int *)0xa06e = *(int *)0xa06e + 1;
      *(int *)0xa076 = *(int *)0xa076 + 1;
      iVar4 = *(int *)0xa070;
      pcVar1 = (char *)(param_1 + iVar4 + 0x4f6);
      *pcVar1 = *pcVar1 + '\x01';
      if ((uint)*(byte *)(param_1 + iVar4 + 0x4ce) == *(uint *)0xa06e) {
        FUN_1000_b1f3(0,1,4);
        pbVar5 = (byte *)(param_1 + *(int *)0xa072);
        if (pbVar5[0x21c] == 3) {
          iVar4 = (*(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) - (0x17 - *pbVar5 >> 1)) +
                  *(int *)0xa06e / 2;
          *(int *)0xa074 = iVar4;
        }
        else {
          iVar4 = *(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) + *(int *)0xa06e / 2;
        }
        pbVar5[0x168] = 0x15;
        FUN_1000_4e79(0x15,iVar4,0x18);
        *(undefined2 *)0xa06e = 0;
      }
      FUN_1000_b1f3(0,1,7);
    }
    else {
      for (uVar6 = 0; uVar6 < *(byte *)(param_1 + *(int *)0xa070 + 0x4f6); uVar6 = uVar6 + 1) {
        FUN_1000_922d(*(undefined1 *)(param_1 + *(int *)0xa072),
                      *(int *)(*(int *)0xa072 * 2 + param_1 + 0x5a) + uVar6,
                      (int)*(char *)(*(int *)0xa070 * 0xf + param_1 + uVar6 + 0x276));
      }
      *(undefined2 *)0xa06e = 0;
      *(undefined1 *)(param_1 + *(int *)0xa070 + 0x4f6) = 0;
      FUN_1000_9ecc();
    }
  }
  return 0xffff;
}

