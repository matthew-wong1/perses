


struct Foo {
  int *p, *q;
};

int *foo (int ***x) __attribute__((pure));

int bar (int b)
{
  int i;
  struct Foo f;
  int *p, **q;
  p = &i;
  f.p = &i;
  f.q = f.p;
  if (b)
    q = &f.p;
  else
    q = &f.q;
  return *foo (&q);
}
