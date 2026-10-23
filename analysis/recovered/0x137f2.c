/* ev_8c036371284441f908edfdb28adc14b761cc20728728626bef153dc6aada93e7 */

void __cdecl16near FUN_1000_37f2(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  if (*(char *)0x17a5 != '\0') {
    FUN_1000_b1f3(0,5,6);
    FUN_1000_f7da(4,0);
    FUN_1000_f74a();
  }
  if ((*(int *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2 + 0x135d) <
       0) && (*(char *)0x17a5 != '\0')) {
    FUN_1000_f6a4(*(undefined2 *)
                   (*(int *)((uint)*(byte *)(unaff_BP + 4) * 0x1f +
                             (uint)*(byte *)(unaff_BP + 6) * 2 + 0x135d) * -2 + 0x14f5));
  }
  else {
    FUN_1000_f7da(4,0);
    *(undefined1 *)(unaff_BP + 4) =
         (char)*(undefined2 *)
                ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2 + 0x135d);
    while (*(byte *)(unaff_BP + -1) < *(byte *)((uint)*(byte *)(unaff_BP + 4) * 0x1f + 0x134e)) {
      if (*(char *)0x17a5 != '\0') {
        FUN_1000_f6a4(0x1a48,*(undefined2 *)
                              ((uint)*(byte *)(unaff_BP + 4) * 0x1f +
                               (uint)*(byte *)(unaff_BP + -1) * 2 + 0x134f));
      }
      *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
    }
  }
  FUN_1000_b1f3(0,1,7);
  return;
}

