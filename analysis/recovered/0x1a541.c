/* ev_d30319a8dc9c3fb924ddf06e1462e3c5dffade92b4f57a1fde7a557e91b6ffeb */

void __cdecl16near FUN_1000_a541(int param_1)

{
  char *pcVar1;
  int *piVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined2 unaff_DS;
  
  for (iVar9 = 0; iVar9 < 0x5a; iVar9 = iVar9 + 1) {
    iVar5 = param_1 + iVar9;
    if ((((*(char *)(iVar5 + 0x21c) == '\x02') &&
         ((uint)*(byte *)(iVar5 + 0x10e) == *(int *)0xa056 % 3)) ||
        ((*(char *)(iVar5 + 0x21c) == '\x03' && (*(int *)0xa056 % 2 != 0)))) ||
       ((*(char *)(iVar5 + 0x21c) == '\x01' &&
        ((uint)*(byte *)(iVar5 + 0x10e) == *(int *)0xa056 % *(int *)0xa05c)))) {
      uVar10 = (uint)*(byte *)(iVar5 + 0x1c2);
      for (uVar11 = 0; uVar11 < *(byte *)(param_1 + uVar10 + 0x4ce); uVar11 = uVar11 + 1) {
        FUN_1000_922d(*(undefined1 *)(param_1 + iVar9),*(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar11
                      ,0x20);
        if (uVar11 < *(byte *)(param_1 + uVar10 + 0x4f6)) {
          FUN_1000_b1f3(1,1,2);
        }
        else if (1 < *(byte *)(param_1 + iVar9 + 0x21c)) {
          FUN_1000_b1f3(0,1,6);
        }
        if (*(char *)(param_1 + iVar9 + 0x21c) == '\x03') {
          FUN_1000_922d(*(undefined1 *)(param_1 + iVar9),
                        *(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar11 + -1,
                        (int)*(char *)(uVar10 * 0xf + param_1 + uVar11 + 0x276));
        }
        else {
          FUN_1000_922d(*(byte *)(param_1 + iVar9) + 1,*(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar11
                        ,(int)*(char *)(uVar10 * 0xf + param_1 + uVar11 + 0x276));
        }
        FUN_1000_b1f3(0,1,7);
      }
      if (((char *)(param_1 + iVar9))[0x21c] == '\x03') {
        piVar2 = (int *)(iVar9 * 2 + param_1 + 0x5a);
        *piVar2 = *piVar2 + -1;
      }
      else {
        pcVar1 = (char *)(param_1 + iVar9);
        *pcVar1 = *pcVar1 + '\x01';
      }
      pbVar8 = (byte *)(param_1 + iVar9);
      if ((pbVar8[0x168] != 0) && (pbVar8[0x168] <= *pbVar8)) {
        FUN_1000_a22a(1,iVar9,*(undefined1 *)(param_1 + uVar10 + 0x4ce),param_1);
      }
      if (((*(char *)(param_1 + iVar9 + 0x21c) == '\x03') &&
          (*(char *)(param_1 + iVar9 + 0x168) == '\0')) &&
         ((int)(*(int *)(iVar9 * 2 + param_1 + 0x5a) + (uint)*(byte *)(param_1 + uVar10 + 0x4ce)) <
          0)) {
        *(undefined1 *)(param_1 + uVar10 + 0x4f6) = 0;
        *(undefined1 *)(param_1 + uVar10 + 0x4ce) = 0;
        *(undefined1 *)(param_1 + iVar9 + 0x168) = 0;
        *(undefined1 *)(param_1 + iVar9 + 0x21c) = 0;
        if (uVar10 == *(uint *)0xa070) {
          *(undefined2 *)0xa06e = 0;
        }
        *(int *)0xa05e = *(int *)0xa05e + -1;
        FUN_1000_7d49();
        *(undefined2 *)0xa074 = 0;
      }
    }
    uVar10 = (uint)*(byte *)((uint)*(byte *)(param_1 + iVar9 + 0x1c2) + param_1 + 0x4ce);
    iVar5 = param_1 + iVar9;
    if (*(char *)(iVar5 + 0x168) != '\0') {
      iVar7 = *(int *)0xa074;
      if (*(char *)(iVar5 + 0x21c) != '\x03') {
        iVar7 = *(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar10 / 2;
      }
      uVar3 = *(undefined1 *)(iVar5 + 0x168);
      *(char *)(iVar5 + 0x168) = *(char *)(iVar5 + 0x168) + -1;
      FUN_1000_4e79(uVar3,iVar7,0x20);
      FUN_1000_b1f3(0,1,4);
      FUN_1000_4e79(*(undefined1 *)(param_1 + iVar9 + 0x168),iVar7,0x18);
      FUN_1000_b1f3(0,1,7);
      if (((byte *)(param_1 + iVar9))[0x168] <= *(byte *)(param_1 + iVar9)) {
        FUN_1000_a22a(1,iVar9,uVar10,param_1);
      }
    }
    if ((((byte *)(param_1 + iVar9))[0x21c] != 0) && (0x15 < *(byte *)(param_1 + iVar9))) {
      FUN_1000_a22a(0,iVar9,uVar10,param_1);
    }
  }
  iVar9 = FUN_1000_bd74(*(undefined2 *)0xa05a);
  if ((((iVar9 == 0) || ((*(int *)0xa05e < 5 && (iVar9 = FUN_1000_bd74(2), iVar9 != 0)))) &&
      (*(int *)0xa064 < 0x28)) &&
     ((*(int *)0xa058 == 0 && (*(int *)(*(int *)0xa07e * 2 + -0x5f98) != 0)))) {
    iVar9 = FUN_1000_91df((int)*(char *)(*(int *)0xa064 * 0xf + param_1 + 0x276));
    if (*(char *)(iVar9 + param_1 + 0x21c) != '\0') {
      for (iVar9 = 0; iVar9 < 10; iVar9 = iVar9 + 1) {
        iVar5 = FUN_1000_bd74(*(int *)0xa062 + 1);
        cVar4 = *(char *)(iVar5 + 0x7a94);
        iVar5 = FUN_1000_91df((int)cVar4);
        if ((*(char *)(iVar5 + param_1 + 0x21c) == '\0') &&
           (iVar5 = FUN_1000_e677(0x84a2,(int)cVar4), iVar5 == 0)) {
          *(char *)(*(int *)0xa064 * 0xf + param_1 + 0x276) = cVar4;
          *(undefined1 *)(param_1 + *(int *)0xa064 + 0x4ce) = 1;
          break;
        }
      }
    }
    iVar9 = FUN_1000_91df((int)*(char *)(*(int *)0xa064 * 0xf + param_1 + 0x276));
    if (*(char *)(iVar9 + param_1 + 0x21c) == '\0') {
      *(undefined1 *)(param_1 + iVar9 + 0x1c2) = (char)*(undefined2 *)0xa064;
      *(undefined1 *)(param_1 + iVar9 + 0x21c) = 1;
      *(undefined1 *)(param_1 + iVar9) = 2;
      if (*(char *)(param_1 + *(int *)0xa064 + 0x4ce) == '\x01') {
        iVar5 = FUN_1000_bd74(5);
        if (((iVar5 == 0) && (*(int *)0xa074 == 0)) && (1 < *(int *)0xa086)) {
          *(undefined1 *)(param_1 + iVar9 + 0x21c) = 2;
          *(undefined2 *)0xa074 = 1;
          FUN_1000_7e47(0);
        }
      }
      else if (((*(int *)0xa074 == 0) && (2 < *(int *)0xa086)) &&
              (iVar5 = FUN_1000_bd74(5), iVar5 == 0)) {
        *(undefined2 *)0xa074 = 1;
        *(undefined1 *)(param_1 + iVar9 + 0x21c) = 3;
        cVar4 = FUN_1000_bd74(0x12);
        *(char *)(param_1 + iVar9) = cVar4 + '\x03';
        *(undefined2 *)(iVar9 * 2 + param_1 + 0x5a) = 0x4e;
        FUN_1000_7e47(1);
      }
      if (*(char *)(param_1 + iVar9 + 0x21c) != '\x03') {
        iVar7 = 0x50 - (uint)*(byte *)(param_1 + *(int *)0xa064 + 0x4ce);
        iVar5 = FUN_1000_bd74(2);
        if (iVar5 == 0) {
          iVar5 = FUN_1000_bd74(*(undefined2 *)0xa06c);
          uVar10 = (uint)*(byte *)(iVar5 + param_1 + 0x614);
          *(uint *)(iVar9 * 2 + param_1 + 0x5a) = uVar10;
          if (iVar7 < (int)uVar10) {
            *(int *)(iVar9 * 2 + param_1 + 0x5a) = iVar7;
          }
        }
        else {
          uVar6 = FUN_1000_bd74(iVar7);
          *(undefined2 *)(iVar9 * 2 + param_1 + 0x5a) = uVar6;
        }
      }
      if (1 < *(byte *)(param_1 + iVar9 + 0x21c)) {
        FUN_1000_b1f3(0,1,6);
      }
      for (uVar10 = 0; uVar10 < *(byte *)(param_1 + *(int *)0xa064 + 0x4ce); uVar10 = uVar10 + 1) {
        FUN_1000_922d(*(undefined1 *)(param_1 + iVar9),*(int *)(iVar9 * 2 + param_1 + 0x5a) + uVar10
                      ,(int)*(char *)(*(int *)0xa064 * 0xf + param_1 + uVar10 + 0x276));
      }
      FUN_1000_b1f3(0,1,7);
      if (*(char *)(param_1 + iVar9 + 0x21c) == '\x02') {
        *(undefined1 *)(param_1 + iVar9 + 0x10e) = (char)(*(int *)0xa056 % 3);
      }
      else {
        *(undefined1 *)(param_1 + iVar9 + 0x10e) = (char)(*(int *)0xa056 % *(int *)0xa05c);
      }
      *(int *)0xa058 = *(int *)0xa05c + 1;
      *(int *)0xa05e = *(int *)0xa05e + 1;
      *(int *)0xa064 = *(int *)0xa064 + 1;
    }
  }
  if (*(int *)0xa058 != 0) {
    *(int *)0xa058 = *(int *)0xa058 + -1;
  }
  *(int *)0xa056 = *(int *)0xa056 + 1;
  return;
}

