/* ev_3588cc6d19a2510c9a84b993f8337141a4dfd47f330480d7f8aab71b5e45b50c */

byte __cdecl16near FUN_1000_6802(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = *(byte *)*(undefined2 *)0x9d94;
  if (*(uint *)0x9d96 < 5) {
    *(int *)0x9d94 = *(int *)0x9d94 + 1;
    if (*(uint *)0x9d96 < 4) {
      local_3 = local_3 << (4U - (char)*(undefined2 *)0x9d96 & 0x1f) |
                *(byte *)*(undefined2 *)0x9d94 >> ((char)*(undefined2 *)0x9d96 + 4U & 0x1f);
    }
    *(int *)0x9d96 = *(int *)0x9d96 + 3;
  }
  else {
    *(int *)0x9d96 = *(int *)0x9d96 + -4;
    uVar1 = *(undefined2 *)0x9d96;
    *(int *)0x9d96 = *(int *)0x9d96 + -1;
    local_3 = (byte)((uint)(int)(char)local_3 >> ((byte)uVar1 & 0x1f));
  }
  return local_3 & 0x1f;
}

