/* ev_86c71ece42ee47c2ca5f4020035270b92cf8926e574c6f4b7352b851a54c9cda */

/* WARNING (jumptable): Stack frame is not setup normally: Input value of stackpointer is not used
    */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x0001f1a3) */

void entry(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined2 *puVar3;
  code *pcVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  char *pcVar10;
  undefined2 *puVar11;
  char *pcVar12;
  uint unaff_DS;
  bool bVar13;
  
  uVar8 = *(int *)0x2 + 0xe072;
  DAT_1000_f19a = unaff_DS;
  if (0x1000 < uVar8) {
    pcVar4 = (code *)swi(0x21);
    (*pcVar4)();
    uVar8 = 0;
  }
  puVar9 = (undefined1 *)(uVar8 << 4);
  if (DAT_1f8e_8f3e != 0) {
    puVar9 = (undefined1 *)(DAT_1f8e_8f3a * 0x10 + -0x5f6e);
  }
  DAT_1f8e_8f0a = puVar9;
  if (puVar9 == (undefined1 *)0x0) {
    DAT_1f8e_8f0a = (undefined1 *)0xffff;
  }
  DAT_1f8e_8f0c = unaff_DS;
  if (DAT_1f8e_8f3e != 0) {
    DAT_1f8e_8efe = (char *)((int)DAT_1f8e_8f0a + 1);
    bVar13 = CARRY2((uint)DAT_1f8e_8f0a,DAT_1f8e_8f3c * 0x10);
    DAT_1f8e_8f0a = (undefined1 *)((int)DAT_1f8e_8f0a + DAT_1f8e_8f3c * 0x10);
    if (bVar13) {
      DAT_1f8e_8f0a = (undefined1 *)0xffff;
    }
    bVar13 = ((int)DAT_1f8e_8f0a + 0xfU >> 4) + 0x1f8e < unaff_DS;
    pcVar4 = (code *)swi(0x21);
    (*pcVar4)();
    if (bVar13) {
      pcVar4 = (code *)swi(0x21);
      (*pcVar4)();
      if (bVar13) goto LAB_1000_f2e1;
    }
  }
  puVar11 = (undefined2 *)0x8f44;
  for (iVar6 = 0x8a7; iVar6 != 0; iVar6 = iVar6 + -1) {
    puVar3 = puVar11;
    puVar11 = puVar11 + 1;
    *puVar3 = 0;
  }
  uVar8 = *(uint *)0x2c;
  pcVar12 = (char *)0x0;
  uVar7 = 0x7fff;
  do {
    if (*pcVar12 == '=') {
      uVar5 = 0;
      pcVar10 = pcVar12 + 1;
      *pcVar12 = '\0';
      goto LAB_1000_f28f;
    }
    bVar13 = false;
    if (*pcVar12 == '\0') break;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar1 = pcVar12;
      pcVar12 = pcVar12 + 1;
      bVar13 = *pcVar1 == '\0';
    } while (!bVar13);
  } while (bVar13);
  uVar7 = (uint)*(byte *)0x80;
  pcVar10 = (char *)0x81;
  uVar5 = 1;
  uVar8 = unaff_DS;
LAB_1000_f28f:
  *(undefined2 *)(puVar9 + -2) = uVar5;
  *(char **)(puVar9 + -4) = DAT_1f8e_8efe;
  for (; uVar7 != 0; uVar7 = uVar7 - 1) {
    pcVar1 = pcVar10;
    pcVar10 = pcVar10 + 1;
    if (*pcVar1 == '\0') break;
    pcVar2 = DAT_1f8e_8efe;
    DAT_1f8e_8efe = DAT_1f8e_8efe + 1;
    *pcVar2 = *pcVar1;
  }
  *DAT_1f8e_8efe = '\0';
  DAT_1f8e_8efe = (char *)((uint)(DAT_1f8e_8efe + 2) & 0xfffe);
  if (DAT_1f8e_8f3e == 0) {
    iVar6 = DAT_1f8e_8f3a;
    if (DAT_1f8e_8f3a == 0) {
      iVar6 = 0x800;
    }
    DAT_1f8e_8f08 = puVar9 + iVar6 * -0x10 + -4;
  }
  DAT_1f8e_8f02 = 0x1f8e;
  DAT_1f8e_8f04 = 0x1000;
  DAT_1f8e_8f06 = DAT_1f8e_8efe;
  *(undefined2 *)(puVar9 + -6) = 0xf2dd;
  FUN_1000_f2f3();
LAB_1000_f2e1:
  pcVar4 = (code *)swi(0x21);
  (*pcVar4)();
                    /* WARNING: Could not recover jumptable at 0x0001f2e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(ulong)DAT_1000_f198)();
  return;
}

