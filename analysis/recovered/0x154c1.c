/* ev_9bfb03a85045b7a4e6d20a38226702a687c9053c4ac39dff6bd0a137853964f0 */

void __cdecl16near FUN_1000_54c1(void)

{
  int iVar1;
  int unaff_BP;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  iVar4 = 0;
  if ((*(int *)(unaff_BP + 4) != 0) && (*(byte *)0x90af < 0x1d)) {
    return;
  }
  uVar2 = 0;
  if (*(int *)(unaff_BP + 4) != 0) {
    uVar2 = 0x1d;
  }
  for (; uVar2 <= *(byte *)0x90af; uVar2 = uVar2 + 1) {
    iVar1 = uVar2 * 4;
    iVar1 = FUN_1000_52dc(*(uint *)(iVar1 + -0x6dce) + *(uint *)(iVar1 + -0x652c),
                          *(int *)(iVar1 + -0x6dcc) + *(int *)(iVar1 + -0x652a) +
                          (uint)CARRY2(*(uint *)(iVar1 + -0x6dce),*(uint *)(iVar1 + -0x652c)),
                          *(uint *)(iVar1 + -0x6ca2) + *(uint *)(iVar1 + -0x6400),
                          *(int *)(iVar1 + -0x6ca0) + *(int *)(iVar1 + -0x63fe) +
                          (uint)CARRY2(*(uint *)(iVar1 + -0x6ca2),*(uint *)(iVar1 + -0x6400)),
                          *(uint *)(iVar1 + -0x6efa) + *(uint *)(iVar1 + -0x6658),
                          *(int *)(iVar1 + -0x6ef8) + *(int *)(iVar1 + -0x6656) +
                          (uint)CARRY2(*(uint *)(iVar1 + -0x6efa),*(uint *)(iVar1 + -0x6658)));
    iVar4 = iVar4 + iVar1;
  }
  if (*(int *)(unaff_BP + 4) != 0) {
    uVar2 = uVar2 - 0x1d;
  }
  iVar1 = 4;
  if (0x1c < *(byte *)0x90af) {
    iVar1 = 5;
  }
  uVar2 = (iVar4 / (int)uVar2 << 1) / iVar1;
  if (*(byte *)0x90b8 < uVar2) {
    uVar2 = (uint)*(byte *)0x90b8;
  }
  else {
    uVar3 = 10;
    if (*(int *)(unaff_BP + 4) != 0) {
      uVar3 = 5;
    }
    if ((int)uVar2 < (int)uVar3) {
      uVar2 = uVar3;
    }
  }
  *(undefined1 *)(*(int *)(unaff_BP + 4) + -0x6f4d) = (char)uVar2;
  return;
}

