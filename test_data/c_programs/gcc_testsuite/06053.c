


struct a
{
  union
  {
    int a;
    int b;
  };
  union
  {
    int c;
    int d;
  };
  int e;
};

int f(struct a *c)
{
  int d;
  c->e = 2;
  d = c->a;
  c->c = 1;
  return c->a + d;
}
