/* ev_5458d4929461f75e4075ead84969ebdb0eb4a38b82ca04ca24cc041850bde5db */

void __cdecl16near FUN_1000_8857(void)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar8;
  
  FUN_1000_e7bd();
  iVar2 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar2 + -0x6b5f) == 0) {
    bVar8 = *(int *)(iVar2 + -0x6b61) == 0;
  }
  if (bVar8) {
    bVar8 = false;
    if (*(int *)(iVar2 + -0x6b5b) == 0) {
      bVar8 = *(int *)(iVar2 + -0x6b5d) == 0;
    }
    if (bVar8) {
      FUN_1000_f6a4(0x7e58,0x20);
      goto LAB_1000_88b4;
    }
  }
  uVar3 = FUN_1000_529a(*(undefined2 *)(iVar2 + -0x6b61),*(undefined2 *)(iVar2 + -0x6b5f),
                        *(undefined2 *)(iVar2 + -0x6b5d),*(undefined2 *)(iVar2 + -0x6b5b));
  FUN_1000_f6a4(0x7e52,uVar3);
LAB_1000_88b4:
  iVar2 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar2 + -0x6b63) == 0) {
    bVar8 = *(int *)(iVar2 + -0x6b65) == 0;
  }
  if (bVar8) {
    iVar2 = 0;
  }
  else {
    uVar4 = *(uint *)(iVar2 + -0x6b61) + *(uint *)(iVar2 + -0x6b5d);
    iVar5 = *(int *)(unaff_BP + 4) * 0x4f;
    lVar1 = (ulong)*(uint *)(iVar5 + -0x6b59) * 2;
    uVar6 = (uint)lVar1;
    iVar2 = FUN_1000_52dc(uVar4 - uVar6,
                          ((*(int *)(iVar2 + -0x6b5f) + *(int *)(iVar2 + -0x6b5b) +
                           (uint)CARRY2(*(uint *)(iVar2 + -0x6b61),*(uint *)(iVar2 + -0x6b5d))) -
                          ((int)((ulong)lVar1 >> 0x10) + *(int *)(iVar5 + -0x6b57) * 2)) -
                          (uint)(uVar4 < uVar6),0,0,*(undefined2 *)(iVar2 + -0x6b65),
                          *(undefined2 *)(iVar2 + -0x6b63));
  }
  iVar5 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar5 + -0x6b53) == 0) {
    bVar8 = *(int *)(iVar5 + -0x6b55) == 0;
  }
  if (bVar8) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_1000_52dc(*(undefined2 *)(iVar5 + -0x6b51),*(undefined2 *)(iVar5 + -0x6b4f),
                          *(undefined2 *)(iVar5 + -0x6b4d),*(undefined2 *)(iVar5 + -0x6b4b),
                          *(undefined2 *)(iVar5 + -0x6b55),*(undefined2 *)(iVar5 + -0x6b53));
  }
  iVar7 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar7 + -0x6b47) == 0) {
    bVar8 = *(int *)(iVar7 + -0x6b49) == 0;
  }
  if (bVar8) {
    *(undefined2 *)(unaff_BP + -2) = 0;
  }
  else {
    uVar3 = FUN_1000_52dc(*(undefined2 *)(iVar7 + -0x6b45),*(undefined2 *)(iVar7 + -0x6b43),
                          *(undefined2 *)(iVar7 + -0x6b41),*(undefined2 *)(iVar7 + -0x6b3f),
                          *(undefined2 *)(iVar7 + -0x6b49),*(undefined2 *)(iVar7 + -0x6b47));
    *(undefined2 *)(unaff_BP + -2) = uVar3;
  }
  iVar7 = *(int *)(unaff_BP + 4) * 0x4f;
  bVar8 = false;
  if (*(int *)(iVar7 + -0x6b3b) == 0) {
    bVar8 = *(int *)(iVar7 + -0x6b3d) == 0;
  }
  if (bVar8) {
    *(undefined2 *)(unaff_BP + -4) = 0;
  }
  else {
    uVar3 = FUN_1000_52dc(*(undefined2 *)(iVar7 + -0x6b39),*(undefined2 *)(iVar7 + -0x6b37),
                          *(undefined2 *)(iVar7 + -0x6b35),*(undefined2 *)(iVar7 + -0x6b33),
                          *(undefined2 *)(iVar7 + -0x6b3d),*(undefined2 *)(iVar7 + -0x6b3b));
    *(undefined2 *)(unaff_BP + -4) = uVar3;
  }
  if (iVar2 != 0) {
    FUN_1000_f6a4(0x7e5c,iVar2);
    if ((((iVar5 == 0) || (iVar2 < iVar5)) &&
        ((*(int *)(unaff_BP + -2) == 0 || (iVar2 < *(int *)(unaff_BP + -2))))) &&
       ((*(int *)(unaff_BP + -4) == 0 || (iVar2 < *(int *)(unaff_BP + -4))))) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    *(undefined2 *)(unaff_BP + -6) = uVar3;
    if (*(int *)(unaff_BP + -6) == 0) {
      if ((((iVar5 == 0) || (iVar5 < iVar2)) &&
          ((*(int *)(unaff_BP + -2) == 0 || (*(int *)(unaff_BP + -2) < iVar2)))) &&
         ((*(int *)(unaff_BP + -4) == 0 && (*(int *)(unaff_BP + -4) < iVar2)))) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      *(undefined2 *)(unaff_BP + -6) = uVar3;
    }
    if (iVar5 == 0) {
      FUN_1000_f6a4(0x7e64,0x20);
    }
    else {
      if (*(int *)(unaff_BP + -6) != 0) {
        iVar5 = iVar2;
      }
      FUN_1000_f6a4(0x7e60,iVar5);
      *(undefined2 *)(unaff_BP + -6) = 0;
    }
    if (*(int *)(unaff_BP + -2) == 0) {
      FUN_1000_f6a4(0x7e6c,0x20);
    }
    else {
      iVar5 = *(int *)(unaff_BP + -2);
      if (*(int *)(unaff_BP + -6) != 0) {
        iVar5 = iVar2;
      }
      FUN_1000_f6a4(0x7e68,iVar5);
      *(undefined2 *)(unaff_BP + -6) = 0;
    }
    if (*(int *)(unaff_BP + -4) != 0) {
      iVar5 = *(int *)(unaff_BP + -4);
      if (*(int *)(unaff_BP + -6) != 0) {
        iVar5 = iVar2;
      }
      FUN_1000_f6a4(0x7e70,iVar5);
    }
  }
  return;
}

