extern int kallsyms_token_index[] __attribute__((weak));
extern int kallsyms_token_table[] __attribute__((weak));
void kallsyms_expand_symbol(int *result)
{
  int len = *result;
  int *tptr;
  while(len) {
    tptr = &kallsyms_token_table[ kallsyms_token_index[*result] ];
    len--;
    while (*tptr) tptr++;
    *tptr = 1;
  }
 *result = 0;
}
