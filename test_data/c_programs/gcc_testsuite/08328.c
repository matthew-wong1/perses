


void ASMAtomicWritePtrVoid(const void *pv);
void rtThreadDestroy(void)
{
  void * const pvTypeChecked = ((void *)0);
  ASMAtomicWritePtrVoid((void *)(pvTypeChecked));
}
