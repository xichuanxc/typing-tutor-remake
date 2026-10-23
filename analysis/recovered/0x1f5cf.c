/* ev_f6bb2198332d0acdadce17404a1974b9205b5456f9828fd683438b6efc39447e */

undefined2 __cdecl16near FUN_1000_f5cf(int param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint unaff_BP;
  int unaff_DS;
  bool bVar4;
  undefined2 in_stack_00000000;
  
  puVar2 = (undefined1 *)(param_1 + 1U & 0xfffe);
  if ((undefined1 *)*(uint *)0x8f06 <= puVar2) {
    if (*(int *)0x8f3e == 0) {
      if (((undefined1 *)*(uint *)0x8f08 <= puVar2) || (&stack0xfffe <= puVar2)) goto LAB_1000_f646;
    }
    else if (((undefined1 *)*(uint *)0x8f0a < puVar2) || (puVar2 <= (undefined1 *)*(uint *)0x8efe))
    {
      uVar3 = (param_1 + 1U >> 4) + 0x41 & 0xffc0;
      bVar4 = uVar3 + unaff_DS < *(uint *)0x8f0c;
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(uVar3,puVar2);
      if ((!bVar4) && (*(undefined2 *)0x8efe = in_stack_00000000, (unaff_BP & 0xe000) == 0)) {
        *(int *)0x8f0a = unaff_BP << 4;
        return 0;
      }
      goto LAB_1000_f646;
    }
    *(uint *)0x8efe = (uint)puVar2;
    return 0;
  }
LAB_1000_f646:
  *(undefined2 *)0x8f00 = 0xfffc;
  return 0xffff;
}

