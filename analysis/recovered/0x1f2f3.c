/* ev_17f564d5781ec13d5b569f3a11c7215e8a6fc2a7ecebe4b822d44983a2727521 */

void __cdecl16near FUN_1000_f2f3(char *param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined2 *puVar6;
  undefined2 unaff_DS;
  char *pcVar5;
  
  uVar1 = FUN_1000_f592(0);
  *(undefined1 *)0x8f20 = uVar1;
  uVar1 = FUN_1000_f592(1);
  *(undefined1 *)0x8f21 = uVar1;
  uVar1 = FUN_1000_f592(2);
  *(undefined1 *)0x8f22 = uVar1;
  puVar2 = (undefined2 *)FUN_1000_f5b2((param_2 + 1) * 2);
  *(undefined2 *)0x8f5c = puVar2;
  *puVar2 = 0x8f10;
  *(int *)0x8f5e = param_2;
  puVar2 = (undefined2 *)(param_2 * 2 + *(int *)0x8f5c);
LAB_1000_f33c:
  do {
    for (; (*param_1 == ' ' || (*param_1 == '\t')); param_1 = param_1 + 1) {
    }
    if (*param_1 == '\0') {
      *puVar2 = 0;
      FUN_1000_0000(*(undefined2 *)0x8f5e,*(undefined2 *)0x8f5c);
      FUN_1000_f3ba(0);
      return;
    }
    puVar6 = puVar2 + 1;
    *puVar2 = param_1;
    *(int *)0x8f5e = *(int *)0x8f5e + 1;
    iVar3 = FUN_1000_f5b2(2);
    if (iVar3 == -1) {
      FUN_1000_f3e7(2,0x8f11,0xe);
      FUN_1000_f2df(200);
    }
    do {
      pcVar5 = param_1;
      pcVar4 = pcVar5 + 1;
      param_1 = pcVar4;
      puVar2 = puVar6;
      if (*pcVar4 == '\0') goto LAB_1000_f33c;
    } while ((*pcVar4 != ' ') && (*pcVar4 != '\t'));
    param_1 = pcVar5 + 2;
    *pcVar4 = '\0';
  } while( true );
}

