



extern void abort (void);

struct S
{
  char c;
  unsigned short f[2][2];
  int i;
  unsigned short f3, f4;
};


int __attribute__ ((noinline))
foo (struct S *p)
{
  struct S l;

  l = *p;
  l.i++;
  l.f[1][0] += 3;
  *p = l;
}

int
main (int argc, char **argv)
{
  struct S a = {0, { {5, 7}, {9, 11} }, 4, 0, 0};
  foo (&a);
  if (a.i != 5 || a.f[1][0] != 12)
    abort ();
  return 0;
}
