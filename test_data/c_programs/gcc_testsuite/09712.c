


void
foo (int *a, int i)
{
  int j, k = 1, l = 30, m = 4;
#pragma omp parallel for num_threads (3 * i) schedule (dynamic, i * 4)
 for (j = 0; j <= l; j++)
    a[j] = 1;
#pragma omp parallel for num_threads (3 * i) schedule (dynamic, i * 4)
 for (j = k; j <= l; j += (m - 1))
    a[j] = 2;
#pragma omp parallel for num_threads (3 * i) schedule (dynamic, 4)
 for (j = 0; j <= l; j++)
    a[j] = 3;
#pragma omp parallel for num_threads (3 * i) schedule (dynamic, 4)
 for (j = k; j <= l; j += (m - 1))
    a[j] = 4;
}

void
bar (int *a, int i)
{
  int j, k = 1, l = 30, m = 4;
#pragma omp parallel for num_threads (3 * i) schedule (guided, i * 4)
 for (j = 0; j <= l; j++)
    a[j] = 1;
#pragma omp parallel for num_threads (3 * i) schedule (guided, i * 4)
 for (j = k; j <= l; j += (m - 1))
    a[j] = 2;
#pragma omp parallel for num_threads (3 * i) schedule (guided, 4)
 for (j = 0; j <= l; j++)
    a[j] = 3;
#pragma omp parallel for num_threads (3 * i) schedule (guided, 4)
 for (j = k; j <= l; j += (m - 1))
    a[j] = 4;
}
