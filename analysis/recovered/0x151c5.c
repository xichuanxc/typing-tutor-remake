/* ev_8405b34b17c687a89714d52763ac039d6dc447a74f5bb446c2d07e0bc28b73ab */

void __cdecl16near FUN_1000_51c5(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 local_25a [150];
  undefined2 local_12e [150];
  
  iVar6 = 2;
  if (*(int *)0x9d2c == 4) {
    iVar6 = 6;
  }
  for (; *(int *)0x9d2c <= iVar6; iVar6 = iVar6 + -1) {
    puVar4 = (undefined2 *)((iVar6 + 1) * 0x4f + -0x6b76);
    puVar7 = (undefined2 *)(iVar6 * 0x4f + -0x6b76);
    for (iVar5 = 0x27; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar2 = puVar4;
      puVar4 = puVar4 + 1;
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar2 = *puVar1;
    }
    *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
  }
  puVar4 = (undefined2 *)(*(int *)0x9d2c * 0x4f + -0x6b76);
  puVar7 = (undefined2 *)*(undefined2 *)0x9d3a;
  for (iVar6 = 0x27; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = puVar7;
    puVar7 = puVar7 + 1;
    *puVar2 = *puVar1;
  }
  *(undefined1 *)puVar4 = *(undefined1 *)puVar7;
  for (iVar6 = 0; iVar6 < 0x4b; iVar6 = iVar6 + 1) {
    uVar3 = *(undefined2 *)(iVar6 * 2 + *(int *)0x9d3c + 300);
    local_12e[iVar6 * 2 + 1] = 0;
    local_12e[iVar6 * 2] = uVar3;
    uVar3 = *(undefined2 *)(iVar6 * 2 + *(int *)0x9d3c + 0x1c2);
    local_25a[iVar6 * 2 + 1] = 0;
    local_25a[iVar6 * 2] = uVar3;
  }
  FUN_1000_8f6e(local_12e,local_25a,*(undefined2 *)0x9d3c);
  return;
}

