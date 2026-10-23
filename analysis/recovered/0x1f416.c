/* ev_54171b9a98bd48754ca19bb5d8bcc2727bd8a99bc86c66cb1e9ef7b9b6f60402 */

undefined2 __cdecl16near FUN_1000_f416(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x8f00 = uVar2;
    return 0xffff;
  }
  return 0;
}

