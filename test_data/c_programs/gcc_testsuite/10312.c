



char a[40];
extern void bar (char *);

void
foo (void)
{
  char b[10];
  __builtin_memmove (&a[0], &a[20], 20);
  __builtin_memmove (&b[1], &a[25], 9);
  bar (b);
}
