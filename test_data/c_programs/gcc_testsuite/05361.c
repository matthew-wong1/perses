


double
foo (const char *u, const char *v, long n)
{
  long i, n1 = 0, n2 = 0;

  for (i = 0; i < n; i++)
    {
      n2 += (u[i] && !v[i]);
      n1 += (!u[i] && v[i]);
    }
  return (2.0 * n2 * n1);
}
