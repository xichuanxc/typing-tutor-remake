/* ev_b68a9b46e3702cd449ff49654c8acdd5f681147fb94f9522aaa9c31690ff0018 */

void __cdecl16near FUN_1000_a22a(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 unaff_DS;
  
  FUN_1000_b1f3(0,4,6);
  bVar3 = *(byte *)(param_4 + param_2);
  *(byte *)(param_4 + *(int *)0xa066 + 0x6af) = bVar3;
  uVar4 = (uint)bVar3;
  iVar8 = *(int *)(param_2 * 2 + param_4 + 0x5a);
  *(int *)(*(int *)0xa066 * 2 + param_4 + 0x6c1) = iVar8;
  iVar5 = param_3 + iVar8;
  FUN_1000_922d(uVar4 - 1,iVar8 + -1,0x5c);
  FUN_1000_922d(uVar4,iVar8 + -1,0xc4);
  FUN_1000_922d(uVar4,iVar8 + -2,0xc4);
  FUN_1000_922d(uVar4 + 1,iVar8 + -1,0x2f);
  for (; iVar8 < iVar5; iVar8 = iVar8 + 1) {
    FUN_1000_922d(uVar4 - 1,iVar8,0xb3);
    if (param_1 == 0) {
      FUN_1000_b1f3(0,1,7);
      FUN_1000_4e79(uVar4,iVar8,0x20);
      FUN_1000_4e79(uVar4 + 1,iVar8,0x20);
      FUN_1000_4e79(uVar4 + 2,iVar8,0x20);
      FUN_1000_b1f3(0,4,6);
    }
    else {
      FUN_1000_922d(uVar4,iVar8,0xc5);
      FUN_1000_922d(uVar4 + 1,iVar8,0xb3);
    }
  }
  FUN_1000_922d(uVar4 - 1,iVar8,0x2f);
  FUN_1000_922d(uVar4,iVar8,0xc4);
  FUN_1000_922d(uVar4,iVar8 + 1,0xc4);
  FUN_1000_922d(uVar4 + 1,iVar8,0x5c);
  uVar4 = (uint)*(byte *)(param_4 + param_2 + 0x1c2);
  if (param_1 == 0) {
    iVar8 = *(int *)0xa07e * 4;
    puVar1 = (uint *)(iVar8 + -0x6266);
    uVar7 = *puVar1;
    *puVar1 = *puVar1 - 10;
    *(int *)(iVar8 + -0x6264) = *(int *)(iVar8 + -0x6264) - (uint)(uVar7 < 10);
    if ((*(int *)(iVar8 + -0x6264) < 1) && (*(int *)(iVar8 + -0x6264) != 0)) {
      *(undefined2 *)(iVar8 + -0x6264) = 0;
      *(undefined2 *)(iVar8 + -0x6266) = 0;
    }
    if (uVar4 == *(uint *)0xa070) {
      *(undefined2 *)0xa06e = 0;
    }
  }
  else if (param_3 < 2) {
    if (*(char *)(param_4 + param_2 + 0x21c) == '\x01') {
      uVar7 = 10;
    }
    else {
      uVar7 = 0x32;
    }
    iVar8 = *(int *)0xa07e;
    puVar1 = (uint *)(iVar8 * 4 + -0x6266);
    uVar6 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    piVar2 = (int *)(iVar8 * 4 + -0x6264);
    *piVar2 = *piVar2 + (uint)CARRY2(uVar6,uVar7);
  }
  else {
    iVar8 = (param_3 + 1) * param_3;
    uVar7 = iVar8 * 5;
    if (*(char *)(param_4 + param_2 + 0x21c) == '\x01') {
      iVar8 = *(int *)0xa07e;
      puVar1 = (uint *)(iVar8 * 4 + -0x6266);
      uVar6 = *puVar1;
      *puVar1 = *puVar1 + uVar7;
      piVar2 = (int *)(iVar8 * 4 + -0x6264);
      *piVar2 = *piVar2 + ((int)uVar7 >> 0xf) + (uint)CARRY2(uVar6,uVar7);
    }
    else {
      uVar6 = iVar8 * 10;
      iVar8 = *(int *)0xa07e;
      puVar1 = (uint *)(iVar8 * 4 + -0x6266);
      uVar7 = *puVar1;
      *puVar1 = *puVar1 + uVar6;
      piVar2 = (int *)(iVar8 * 4 + -0x6264);
      *piVar2 = *piVar2 + ((int)uVar6 >> 0xf) + (uint)CARRY2(uVar7,uVar6);
    }
  }
  if (1 < *(byte *)(param_4 + param_2 + 0x21c)) {
    *(undefined2 *)0xa074 = 0;
    FUN_1000_7d49();
  }
  *(undefined1 *)(param_4 + param_2 + 0x21c) = 0;
  *(undefined1 *)(param_4 + param_2 + 0x168) = 0;
  iVar8 = param_4 + uVar4;
  *(undefined1 *)(iVar8 + 0x4ce) = 0;
  *(undefined1 *)(iVar8 + 0x4f6) = 0;
  iVar8 = *(int *)0xa066;
  *(int *)0xa066 = *(int *)0xa066 + 1;
  *(undefined1 *)(iVar8 + param_4 + 0x6e5) = (char)param_3;
  if (param_1 == 0) {
    FUN_1000_7e47(2);
    iVar10 = 0;
    for (iVar8 = *(int *)(param_2 * 2 + param_4 + 0x5a); iVar8 < iVar5; iVar8 = iVar8 + 1) {
      iVar9 = *(int *)0xa07e * 0x50 + param_4 + iVar8;
      if (*(char *)(iVar9 + 0x574) != '\0') {
        iVar10 = iVar10 + 1;
        *(undefined1 *)(iVar9 + 0x574) = 0;
      }
    }
    piVar2 = (int *)(*(int *)0xa07e * 2 + -0x5f98);
    *piVar2 = *piVar2 - iVar10;
  }
  else {
    FUN_1000_7e47(3);
  }
  FUN_1000_f7da(0,0x26);
  FUN_1000_b1f3(1,5,6);
  FUN_1000_f6a4(0x849c,*(undefined2 *)(*(int *)0xa07e * 4 + -0x6266),
                *(undefined2 *)(*(int *)0xa07e * 4 + -0x6264));
  FUN_1000_b1f3(0,1,7);
  *(int *)0xa05e = *(int *)0xa05e + -1;
  return;
}

