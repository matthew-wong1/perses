






void link_error (void);

int
foo (int a, int b, int c, int d)
{
  int x, y;

  b = a;
  if (a == b)
    x = c;
  else
    {
      link_error ();
      x = d;
    }

  if (x == c)
    return a;
  else
    {
      link_error ();
      return b;
    }
}

int
main()
{
  foo (1, 2, 3, 4);
}
