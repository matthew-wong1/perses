






extern char *strcpy (char *, const char *);
extern int strcmp (const char*, const char*);
extern void abort (void);

char buf[128];

void __attribute__((noinline))
bar (int a, const char *p)
{
  if (strcmp (p, "0123456789abcdefghijklmnopqrstuvwxyz") != 0)
    abort ();
}

void __attribute__((noinline))
foo (int a)
{
  if (a)
    bar (0, buf);
  strcpy (buf, "0123456789abcdefghijklmnopqrstuvwxyz");
  bar (0, buf);
}

int
main (void)
{
  foo (0);
  return 0;
}
