double u[1782225];

void foo(int N, int *res)
{
  int i;
  double a, b;
  double sum = 0.0;

  for (i = 0; i < N; i++)
    sum += u[i];

  for (i = 0; i < N; i++)
    {
      a = u[i];
      u[i] = i * i;
      b = u[i];
      sum += a + b;
    }

  *res = sum + N;
}
