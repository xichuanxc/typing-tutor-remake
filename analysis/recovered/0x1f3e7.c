/* ev_c8fc51b299affea99c43a2362ae6dac111c8d69a087b6e517d6d40f8bdf29f06 */

/* WARNING: Removing unreachable block (ram,0x0001f400) */

undefined2 FUN_1000_f3e7(int param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  
  bVar3 = false;
  if (*(char *)(param_1 + -0x70e0) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0001f3fc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)*(undefined2 *)0x8f36)();
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

