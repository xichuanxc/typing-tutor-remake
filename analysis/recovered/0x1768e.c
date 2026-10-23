/* ev_40be234a7e197e04dc49fb8374e1cc07b812a688b58a1ddae5b4321c952df132 */

void __cdecl16near FUN_1000_768e(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_BP;
  int iVar6;
  int iVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  for (iVar6 = 0; iVar6 < 5; iVar6 = iVar6 + 1) {
    iVar3 = *(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23;
    iVar4 = *(int *)(unaff_BP + 6) * 4;
    iVar7 = *(int *)(iVar4 + -0x6264);
    iVar5 = *(int *)(iVar3 + -0x67a1);
    if ((iVar5 < iVar7) ||
       ((iVar7 == iVar5 && (*(uint *)(iVar3 + -0x67a3) < *(uint *)(iVar4 + -0x6266))))) break;
  }
  if (iVar6 != 5) {
    for (iVar7 = 3; iVar6 <= iVar7; iVar7 = iVar7 + -1) {
      FUN_1000_e74e(*(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23 + -0x67bd,
                    *(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23 + -0x67bd);
      iVar5 = *(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23;
      uVar1 = *(undefined2 *)(iVar5 + -0x67a3);
      iVar3 = *(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23;
      *(undefined2 *)(iVar3 + -0x67a1) = *(undefined2 *)(iVar5 + -0x67a1);
      *(undefined2 *)(iVar3 + -0x67a3) = uVar1;
      *(undefined1 *)(*(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23 + -0x679f) =
           *(undefined1 *)(*(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23 + -0x679f);
      iVar5 = *(int *)(unaff_BP + 4) * 0xaf + iVar7 * 0x23;
      uVar1 = *(undefined2 *)(iVar5 + -0x679e);
      iVar3 = *(int *)(unaff_BP + 4) * 0xaf + (iVar7 + 1) * 0x23;
      *(undefined2 *)(iVar3 + -0x679c) = *(undefined2 *)(iVar5 + -0x679c);
      *(undefined2 *)(iVar3 + -0x679e) = uVar1;
    }
    if (*(int *)(unaff_BP + 6) == 0) {
      FUN_1000_e74e(*(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23 + -0x67bd,0x9072);
    }
    else {
      FUN_1000_e74e(*(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23 + -0x67bd,*(undefined2 *)0x6d5);
    }
    iVar7 = *(int *)(unaff_BP + 6) * 4;
    uVar1 = *(undefined2 *)(iVar7 + -0x6266);
    iVar6 = *(int *)(unaff_BP + 4) * 0xaf + iVar6 * 0x23;
    *(undefined2 *)(iVar6 + -0x67a1) = *(undefined2 *)(iVar7 + -0x6264);
    *(undefined2 *)(iVar6 + -0x67a3) = uVar1;
    cVar2 = '\b';
    if (7 < *(byte *)0x90af) {
      cVar2 = *(char *)0x90af + '\x01';
    }
    *(char *)(iVar6 + -0x679f) = cVar2;
    uVar1 = *(undefined2 *)0x99a4;
    *(undefined2 *)(iVar6 + -0x679c) = *(undefined2 *)0x99a6;
    *(undefined2 *)(iVar6 + -0x679e) = uVar1;
    *(undefined1 *)0x906e = 1;
    return;
  }
  return;
}

