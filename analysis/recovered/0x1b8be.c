/* ev_05b7ce86c54beece8992e6ad087e37831d24745749bb4333d33e5f6c70848b69 */

undefined2 __cdecl16near FUN_1000_b8be(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_BP;
  int iVar4;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -6) = *(undefined2 *)(unaff_BP + 4);
  FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10));
  for (iVar4 = 1; iVar4 < *(int *)(unaff_BP + 6); iVar4 = iVar4 + 1) {
    FUN_1000_f873(0x5f);
  }
  FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(undefined2 *)(unaff_BP + 10));
  FUN_1000_f8c2(0x100,0,0xb0c,0);
  *(undefined1 *)(unaff_BP + -0xf) = 0;
  iVar4 = 0;
  while ((iVar2 = FUN_1000_f831(), iVar2 != 0 &&
         ((iVar2 != 0xd ||
          (((*(int *)(unaff_BP + 0xc) != 0 || (*(int *)(unaff_BP + 4) == *(int *)(unaff_BP + -6)))
           && ((*(int *)(unaff_BP + 0xc) != 1 || (*(char *)(unaff_BP + iVar4 + -0xf) != '\b'))))))))
        ) {
    if (iVar2 == 0x1b) {
      FUN_1000_f8c2(0x100,0,0x2b0c,0);
      return 0xffff;
    }
    if (iVar2 == 8) {
      if (*(int *)(unaff_BP + -6) == *(int *)(unaff_BP + 4)) {
        FUN_1000_7e47(5);
      }
      else {
        FUN_1000_f814(unaff_BP + 8,unaff_BP + 10);
        FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(int *)(unaff_BP + 10) + -1);
        FUN_1000_f873(0x5f);
        FUN_1000_f7da(*(undefined2 *)(unaff_BP + 8),*(int *)(unaff_BP + 10) + -1);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + -1;
        iVar4 = iVar4 + -1;
      }
    }
    else if ((((iVar2 == 0x20) && (*(int *)(unaff_BP + -6) == *(int *)(unaff_BP + 4))) ||
             (iVar2 == 0xd)) ||
            (*(int *)(unaff_BP + -6) + *(int *)(unaff_BP + 6) + -1 == *(int *)(unaff_BP + 4))) {
      FUN_1000_7e47(5);
    }
    else {
      *(undefined2 *)(unaff_BP + -2) = 0;
      if (*(int *)(unaff_BP + 0xc) == 0) {
        if ((((((*(byte *)(iVar2 + -0x7183) & 7) == 0) && (iVar2 != 0x20)) &&
             ((iVar2 != 0x2e && (iVar2 != 0x2c)))) &&
            (((iVar2 != 0x2d || (*(int *)(unaff_BP + -6) == *(int *)(unaff_BP + 4))) &&
             (iVar2 != 0x27)))) || (0x7f < iVar2)) {
          *(undefined2 *)(unaff_BP + -2) = 1;
        }
      }
      else if (*(int *)(unaff_BP + 0xc) == 1) {
        iVar5 = iVar4 + 1;
        puVar3 = (undefined1 *)(iVar4 + unaff_BP + -0xf);
        iVar4 = iVar5;
        switch(*puVar3) {
        case 0:
        case 3:
          if ((*(byte *)(iVar2 + -0x7183) & 4) == 0) {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          else if (iVar5 == 1) {
            *(undefined1 *)(unaff_BP + -0x11) = (char)iVar2;
            *(undefined1 *)(unaff_BP + -0xe) = 1;
          }
          else {
            *(undefined1 *)(unaff_BP + -0x10) = (char)iVar2;
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 4;
          }
          break;
        case 1:
          if ((((iVar2 < 0x31) || (0x39 < iVar2)) || (*(char *)(unaff_BP + -0x11) != '0')) &&
             (((iVar2 < 0x30 || (0x32 < iVar2)) || (*(char *)(unaff_BP + -0x11) != '1')))) {
            if (((*(byte *)(iVar2 + -0x7183) & 4) == 0) && (*(char *)(unaff_BP + -0x11) != '0')) {
              *(int *)(unaff_BP + -4) = *(char *)(unaff_BP + -0x11) + -0x30;
              *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 3;
              iVar2 = 0x2d;
            }
            else {
              *(undefined2 *)(unaff_BP + -2) = 1;
            }
          }
          else {
            if (*(char *)(unaff_BP + -0x11) == '1') {
              *(int *)(unaff_BP + -4) = iVar2 + -0x26;
            }
            else {
              *(int *)(unaff_BP + -4) = iVar2 + -0x30;
            }
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 2;
          }
          break;
        case 2:
        case 5:
          if ((*(byte *)(iVar2 + -0x7183) & 4) == 0) {
            *(char *)(unaff_BP + iVar5 + -0xf) = *(char *)(unaff_BP + iVar5 + -0x10) + '\x01';
            iVar2 = 0x2d;
          }
          else {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          break;
        case 4:
          if (((*(byte *)(iVar2 + -0x7183) & 4) == 0) && (*(char *)(unaff_BP + -0x10) != '0')) {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 6;
            iVar2 = 0x2d;
          }
          else if (((((*(byte *)(iVar2 + -0x7183) & 4) == 0) ||
                    ((*(char *)(unaff_BP + -0x10) < '0' || ('2' < *(char *)(unaff_BP + -0x10))))) ||
                   ((*(char *)(unaff_BP + -0x10) == '0' && (iVar2 == 0x30)))) &&
                  (((*(char *)(unaff_BP + -0x10) != '3' ||
                    (((((iVar1 = *(int *)(unaff_BP + -4), iVar1 == 4 || (iVar1 == 6)) ||
                       (iVar1 == 9)) || (iVar1 == 0xb)) && (iVar2 == 0x31)))) ||
                   (((iVar2 != 0x30 && (iVar2 != 0x31)) || (iVar1 == 2)))))) {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          else {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 5;
          }
          break;
        case 6:
          if ((iVar2 == 0x38) || (iVar2 == 0x39)) {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 7;
          }
          else {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          break;
        case 7:
          if ((*(byte *)(iVar2 + -0x7183) & 4) == 0) {
            *(undefined2 *)(unaff_BP + -2) = 1;
          }
          else {
            *(undefined1 *)(unaff_BP + iVar5 + -0xf) = 8;
          }
          break;
        case 8:
          *(undefined2 *)(unaff_BP + -2) = 1;
        }
      }
      if (*(int *)(unaff_BP + -2) == 0) {
        puVar3 = (undefined1 *)*(undefined2 *)(unaff_BP + 4);
        *(int *)(unaff_BP + 4) = *(int *)(unaff_BP + 4) + 1;
        *puVar3 = (char)iVar2;
        FUN_1000_f873(iVar2);
      }
      else {
        iVar4 = iVar4 + -1;
        FUN_1000_7e47(5);
      }
    }
  }
  *(undefined1 *)*(undefined2 *)(unaff_BP + 4) = 0;
  FUN_1000_f8c2(0x100,0,0x2b0c,0);
  return 0;
}

