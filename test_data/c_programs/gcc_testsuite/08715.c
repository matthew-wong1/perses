


struct S
{
  float red;
  int green;
  void *blue;
};

extern int gi;
static int foo ();

int
bar (void)
{
  foo ();
  return 0;
}

static int
foo (struct S s)
{
  gi = s.green;
  return 0;
}
