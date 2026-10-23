/* ev_7c78fbf88c39b8311910faff335033b6cb526108c5dc890137b72eb44baccd47 */

undefined2 __cdecl16near FUN_1000_8ad2(void)

{
  int iVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar3;
  
  FUN_1000_e7bd();
  if (*(char *)*(undefined2 *)(unaff_BP + 4) != '\0') {
    uVar2 = *(undefined2 *)(unaff_BP + 10);
    *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
    FUN_1000_f7da(uVar2,3);
    FUN_1000_f6a4(*(undefined2 *)(unaff_BP + 4));
  }
  if (*(int *)(unaff_BP + 6) == 0) {
    iVar1 = (*(int *)(unaff_BP + 6) + 4) * 0x4f;
    bVar3 = false;
    if (*(int *)(iVar1 + -0x6b5f) == 0) {
      bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
    }
    if (bVar3) {
      bVar3 = false;
      if (*(int *)(iVar1 + -0x6b5b) == 0) {
        bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
      }
      if (bVar3) goto LAB_1000_8b27;
    }
    bVar3 = true;
  }
  else {
LAB_1000_8b27:
    bVar3 = false;
  }
  if (!bVar3) {
    iVar1 = *(int *)(unaff_BP + 6) * 0x4f;
    bVar3 = false;
    if (*(int *)(iVar1 + -0x6b5f) == 0) {
      bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
    }
    if (bVar3) {
      bVar3 = false;
      if (*(int *)(iVar1 + -0x6b5b) == 0) {
        bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
      }
      if (bVar3) {
        iVar1 = (*(int *)(unaff_BP + 6) + 1) * 0x4f;
        bVar3 = false;
        if (*(int *)(iVar1 + -0x6b5f) == 0) {
          bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
        }
        if (bVar3) {
          bVar3 = false;
          if (*(int *)(iVar1 + -0x6b5b) == 0) {
            bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
          }
          if (bVar3) {
            uVar2 = *(undefined2 *)(unaff_BP + 10);
            *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
            FUN_1000_f7da(uVar2,6);
            FUN_1000_f6a4(0x7e87);
            goto LAB_1000_8c3e;
          }
        }
      }
    }
  }
  while (*(int *)(unaff_BP + 6) < *(int *)(unaff_BP + 8)) {
    iVar1 = *(int *)(unaff_BP + 6) * 0x4f;
    bVar3 = false;
    if (*(int *)(iVar1 + -0x6b5f) == 0) {
      bVar3 = *(int *)(iVar1 + -0x6b61) == 0;
    }
    if (bVar3) {
      bVar3 = false;
      if (*(int *)(iVar1 + -0x6b5b) == 0) {
        bVar3 = *(int *)(iVar1 + -0x6b5d) == 0;
      }
      if (!bVar3) goto LAB_1000_8bb0;
    }
    else {
LAB_1000_8bb0:
      uVar2 = *(undefined2 *)(unaff_BP + 10);
      *(int *)(unaff_BP + 10) = *(int *)(unaff_BP + 10) + 1;
      FUN_1000_f7da(uVar2,5);
      iVar1 = *(int *)(unaff_BP + 6) * 0x4f;
      uVar2 = FUN_1000_c0c6(*(undefined2 *)(iVar1 + -0x6b69),*(undefined2 *)(iVar1 + -0x6b67),
                            unaff_BP + -9,
                            *(undefined1 *)
                             ((*(byte *)0x90b8 - 10) / 10 + *(int *)(unaff_BP + 6) * 0x4f + -0x6b31)
                           );
      FUN_1000_f6a4(0x7e74,*(int *)(unaff_BP + 6) * 0x4f + -0x6b76,uVar2);
      FUN_1000_8857(*(undefined2 *)(unaff_BP + 6));
    }
    *(int *)(unaff_BP + 6) = *(int *)(unaff_BP + 6) + 1;
  }
LAB_1000_8c3e:
  return *(undefined2 *)(unaff_BP + 10);
}

