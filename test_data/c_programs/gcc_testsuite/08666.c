



struct S
{
  int a, b, c;
};

void *blah(int, void *);

static void __attribute__ ((noinline)) foo (int x, int z, struct S *p);

static void __attribute__ ((noinline))
bar (int x, int z, struct S *p)
{
  foo (z, x, p);
}

static void __attribute__ ((noinline))
foo (int x, int z, struct S *p)
{
  int i, c = p->c;
  int b = p->b - z;
  void *v = (void *) p;

  if (z)
    {
      z--;
      bar (z, x, p);
    }
  for (i = 0; i< c; i++)
    v = blah(b + x + i, v);
}

void
entry (int c)
{
  struct S s;
  int i;

  for (i = 0; i<c; i++)
    {
      s.a = c;
      s.b = 64;
      s.c = 32;
      foo (4, i, &s);
    }
}
