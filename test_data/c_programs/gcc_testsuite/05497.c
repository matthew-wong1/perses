


extern void abort (void);
extern void exit (int);

int foo (int n)
{
  return n == 0 ? 1 : n * (n - foo (n - 1));
}

int bar (int n)
{
  return n == 0 ? 1 : n * (- bar (n - 1));
}

int baz (int n, int m)
{
  return n == 0 ? 100 : (baz (n - 1, m) - m);
}

int main (void)
{
  if (foo (6) != 726)
    abort ();

  if (bar (7) != -5040)
    abort ();

  if (baz (10, 5) != 50)
    abort ();

  exit (0);
}
