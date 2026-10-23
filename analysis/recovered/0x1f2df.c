/* ev_ce357fa474d426b37e2357095a2ffab7916aa677efd9ab06e80e15530fa76976 */

void FUN_1000_f2df(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
                    /* WARNING: Could not recover jumptable at 0x0001f2e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(ulong)DAT_1000_f198)();
  return;
}

