/* ev_09c257311565a98b6d9935fb32b6c5534d772cfc9b34dde55e4f7d03785ab80a */

void __cdecl16near FUN_1000_ca33(void)

{
  int iVar1;
  int unaff_BP;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined2 *)(unaff_BP + -2) = 0;
  FUN_1000_7e47(7);
  FUN_1000_7d64(unaff_BP + -6,unaff_BP + -8);
  FUN_1000_f7da(*(byte *)(unaff_BP + 4) + 7,*(byte *)(unaff_BP + 6) + 0xd);
  FUN_1000_f6a4(0x89db);
  while ((iVar1 = FUN_1000_f84a(), iVar1 == -1 && (*(int *)(unaff_BP + -6) != 0))) {
    *(undefined2 *)(unaff_BP + -4) = 0;
    for (iVar1 = 0; iVar1 < 5; iVar1 = iVar1 + 1) {
      for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
        if (iVar2 == *(int *)(unaff_BP + -2)) {
          if (*(char *)0x906a == '\0') {
            if ((*(uint *)0x8f42 & 8) == 0) {
              *(uint *)0x8f42 = *(uint *)0x8f42 | 8;
            }
            else {
              *(uint *)0x8f42 = *(uint *)0x8f42 & 0xf7;
            }
          }
          else {
            FUN_1000_b1f3(0,1,*(undefined1 *)((*(int *)(unaff_BP + -2) + iVar1) % 5 + -0x762a));
          }
        }
        FUN_1000_f7da((uint)*(byte *)(unaff_BP + 4) +
                      (uint)*(byte *)(*(int *)(unaff_BP + -4) + -0x76c0),
                      (uint)*(byte *)(unaff_BP + 6) +
                      (uint)*(byte *)(*(int *)(unaff_BP + -4) + -0x768e));
        FUN_1000_f873(*(undefined1 *)(*(int *)(unaff_BP + -4) + -0x765c));
        *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
      }
    }
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
    *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) % 10;
    FUN_1000_7d64(unaff_BP + -6,unaff_BP + -8);
  }
  FUN_1000_7d49();
  *(uint *)0x8f42 = *(uint *)0x8f42 & 0xf7;
  return;
}

