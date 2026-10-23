/* ev_042e2b1b53199e50dd8522ee152a7d7d57fa2163cf7360137a5c2a2b6b870d13 */

/* WARNING: Removing unreachable block (ram,0x0001f3fc) */

undefined2 FUN_1000_f3e0(int param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  
  bVar3 = false;
  if (*(char *)(param_1 + -0x70e0) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0001f400. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)*(undefined2 *)0x8f34)();
    return uVar2;
  }
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if (bVar3) {
    *(undefined2 *)0x8f00 = uVar2;
    uVar2 = 0xffff;
  }
  return uVar2;
}

