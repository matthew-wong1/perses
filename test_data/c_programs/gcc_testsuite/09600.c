


extern void bar(int);

void foo (int n)
{
  int i;

#pragma omp for schedule(dynamic)
 for (i = 0; i < n; ++i)
    bar(i);
}
