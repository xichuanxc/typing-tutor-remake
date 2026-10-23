/* ev_5a346b4461f7adee0cd3f4f25e0be6dccfef68a3dd4d99ce6fd76eef800b44a5 */

void __cdecl16near FUN_1000_84d1(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  if (*(char *)0xa052 == '\0') {
    *(char *)0xa050 = *(char *)0xa050 + -1;
    if (0xb < *(byte *)(unaff_BP + 6)) {
      *(undefined1 *)0xa051 = *(undefined1 *)0xa050;
    }
    if ((uint)*(byte *)0xa051 - (uint)*(byte *)0xa050 == 0x16) {
      *(undefined1 *)0xa052 = *(undefined1 *)0xa050;
    }
    if (*(char *)0xa055 == '\0') {
      *(char *)0xa053 = *(char *)0xa053 + -1;
      if (*(byte *)(unaff_BP + 4) < 9) {
        *(undefined1 *)0xa054 = *(undefined1 *)0xa053;
      }
      if ((uint)*(byte *)0xa054 - (uint)*(byte *)0xa053 == 0x16) {
        *(undefined1 *)0xa055 = *(undefined1 *)0xa053;
      }
    }
  }
  return;
}

