/* ev_c9fc2ce3fe49f925a28f0513c6d1064b538924774dd3d80e720c4342df01e1a8 */

undefined1 __cdecl16near FUN_1000_3a2e(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_1000_e7bd();
  *(undefined1 *)(unaff_BP + -1) = 0;
  while (cVar1 = *(char *)(unaff_BP + 6), *(char *)(unaff_BP + 6) = *(char *)(unaff_BP + 6) + -1,
        cVar1 != '\0') {
    cVar1 = FUN_1000_f139(*(undefined2 *)
                           ((uint)*(byte *)(unaff_BP + 4) * 0x1f + (uint)*(byte *)(unaff_BP + 6) * 2
                           + 0x134f));
    *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + cVar1 + '\x02';
  }
  return *(undefined1 *)(unaff_BP + -1);
}

