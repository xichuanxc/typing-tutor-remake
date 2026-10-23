/* ev_eec2e4408375ed7671347198865e9c400632626e760e4e20f64abeecf9ea6c4c */

void __cdecl16near FUN_1000_f814(undefined1 *param_1,undefined1 *param_2)

{
  code *pcVar1;
  undefined1 extraout_DL;
  undefined1 extraout_DH;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  *param_1 = extraout_DH;
  param_1[1] = 0;
  *param_2 = extraout_DL;
  param_2[1] = 0;
  return;
}

