/* ev_304366000eb747705dc0c5253d956eacfcee28ea45b928645586748c9add8790 */

undefined2 __cdecl16near FUN_1000_ec0b(int param_1)

{
  undefined2 uVar1;
  uint *puVar2;
  undefined2 unaff_DS;
  
  puVar2 = (uint *)(param_1 + -2);
  if ((*puVar2 & 1) == 0) {
    uVar1 = 0xffff;
  }
  else {
    *puVar2 = *puVar2 & 0xfffe;
    *(undefined2 *)0x8f58 = puVar2;
    uVar1 = 0;
  }
  return uVar1;
}

