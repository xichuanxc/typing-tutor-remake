/* ev_3626d12191b440f311ab96ddd71ddde56b703eefdc86bd9ba584beabca2da55f */

/* WARNING: Removing unreachable block (ram,0x000133ae) */

void __cdecl16near FUN_1000_32ed(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar5;
  long lVar6;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -3) = 0;
  *(undefined1 *)(unaff_BP + -2) = 0;
  *(undefined1 *)(unaff_BP + -1) = 0;
  uVar2 = 0x843;
  if (-1 < *(int *)(unaff_BP + 6)) {
    uVar2 = *(undefined2 *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134c);
  }
  FUN_1000_366e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),uVar2);
LAB_1000_3327:
  do {
    if (*(char *)(unaff_BP + -3) != '\0') {
      FUN_1000_b1f3(0,1,7);
      return;
    }
    *(bool *)0x17a5 = *(char *)0x17a0 == '\0';
    FUN_1000_37f2(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
    uVar2 = FUN_1000_3a2e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
    FUN_1000_f7da(3,uVar2);
    if ((*(char *)0x16a == '\0') || (*(char *)0x17a5 == '\0')) {
      if (*(char *)0x17a0 == '\0') {
        uVar5 = FUN_1000_4cb5();
        *(undefined2 *)(unaff_BP + -7) = (int)((ulong)uVar5 >> 0x10);
        *(undefined2 *)(unaff_BP + -9) = (int)uVar5;
        do {
          iVar3 = FUN_1000_f84a();
          if (((0 < iVar3) ||
              (lVar6 = FUN_1000_4cb5(),
              CONCAT22(*(int *)(unaff_BP + -7) + (uint)(0xfe0b < *(uint *)(unaff_BP + -9)),
                       *(uint *)(unaff_BP + -9) + 500) <= lVar6)) ||
             (0x83 < *(int *)(unaff_BP + -7))) break;
        } while ((*(int *)(unaff_BP + -7) != 0x83) || (*(uint *)(unaff_BP + -9) < 0xc278));
        iVar3 = FUN_1000_f84a();
        if (iVar3 < 1) {
          FUN_1000_370e();
        }
      }
    }
    else {
      *(undefined1 *)0x16a = 0;
      FUN_1000_370e();
    }
    iVar3 = FUN_1000_35c3();
    *(undefined1 *)(unaff_BP + -2) = *(undefined1 *)(unaff_BP + -1);
    if ((iVar3 == 0x1b) && (iVar4 = FUN_1000_38f1(*(undefined2 *)(unaff_BP + 4),0x71), iVar4 != -1))
    {
      iVar3 = 0x71;
    }
    if (((iVar3 < 0x80) && ((*(byte *)(iVar3 + -0x7183) & 3) != 0)) &&
       (iVar4 = FUN_1000_38f1(*(undefined2 *)(unaff_BP + 4),iVar3), iVar4 != -1)) {
      *(undefined1 *)(unaff_BP + -1) = (char)iVar4;
      *(undefined1 *)(unaff_BP + -2) = (char)iVar4;
      iVar3 = 10;
      *(uint *)(unaff_BP + -5) = (uint)*(byte *)0x17a5;
      *(undefined1 *)0x17a5 = 0;
      FUN_1000_394a(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
      *(undefined1 *)0x17a5 = (char)*(undefined2 *)(unaff_BP + -5);
    }
    if ((iVar3 != 10) && (iVar3 != 0xd)) {
      if (iVar3 == 0x1b) {
        *(undefined1 *)(unaff_BP + -3) = 1;
        goto LAB_1000_3327;
      }
      if (iVar3 != 0x20) {
        if (iVar3 == 0xcb) {
          uVar1 = FUN_1000_35f5(0xcb,*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
          *(undefined1 *)(unaff_BP + -1) = uVar1;
          goto LAB_1000_3327;
        }
        if (iVar3 != 0xcd) {
          FUN_1000_7e47(5);
          goto LAB_1000_3327;
        }
      }
      uVar1 = FUN_1000_35f5(0xcd,*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
      *(undefined1 *)(unaff_BP + -1) = uVar1;
      goto LAB_1000_3327;
    }
    if (*(int *)((uint)*(byte *)(unaff_BP + -1) * 2 + *(int *)(unaff_BP + 4) * 0x1f + 0x135d) < 0) {
      FUN_1000_c19a();
      iVar3 = *(int *)(unaff_BP + 4) * 0x1f;
      (*(code *)*(undefined2 *)
                 (*(int *)((uint)*(byte *)(unaff_BP + -1) * 2 + iVar3 + 0x135d) * -2 + 0x1759))
                (*(undefined2 *)(iVar3 + 0x134c));
      *(bool *)0x17a5 = *(char *)0x17a0 == '\0';
      *(undefined1 *)(unaff_BP + -1) = *(undefined1 *)(unaff_BP + -2);
      uVar2 = 0x843;
      if (-1 < *(int *)(unaff_BP + 6)) {
        uVar2 = *(undefined2 *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134c);
      }
      FUN_1000_366e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),uVar2);
      FUN_1000_c1af();
    }
    else {
      FUN_1000_32ed(*(undefined2 *)
                     ((uint)*(byte *)(unaff_BP + -1) * 2 + *(int *)(unaff_BP + 4) * 0x1f + 0x135d),
                    *(undefined2 *)(unaff_BP + 4));
      *(bool *)0x17a5 = *(char *)0x17a0 == '\0';
      uVar2 = 0x843;
      if (-1 < *(int *)(unaff_BP + 6)) {
        uVar2 = *(undefined2 *)(*(int *)(unaff_BP + 6) * 0x1f + 0x134c);
      }
      FUN_1000_366e(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1),uVar2);
      FUN_1000_37f2(*(undefined2 *)(unaff_BP + 4),*(undefined1 *)(unaff_BP + -1));
    }
  } while( true );
}

