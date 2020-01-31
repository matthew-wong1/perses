





typedef double adouble __attribute__((aligned(sizeof (double))));







void __attribute__((sseregparm))
test_noneg_add_noneg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = ((a[i] * b[i]) + c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_noneg_add_noneg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = ((a[i] * b[i]) + c[i]) * a[i] - c[i];
}

void __attribute__((sseregparm))
test_noneg_add_neg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -((a[i] * b[i]) + c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_noneg_add_neg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -((a[i] * b[i]) + c[i]) * a[i] - c[i];
}

void __attribute__((sseregparm))
test_noneg_sub_noneg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = ((a[i] * b[i]) - c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_noneg_sub_noneg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = ((a[i] * b[i]) - c[i]) * a[i] - c[i];
}

void __attribute__((sseregparm))
test_noneg_sub_neg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -((a[i] * b[i]) - c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_noneg_sub_neg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -((a[i] * b[i]) - c[i]) * a[i] - c[i];
}

void __attribute__((sseregparm))
test_neg_add_noneg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = (-(a[i] * b[i]) + c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_neg_add_noneg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = (-(a[i] * b[i]) + c[i]) * a[i] - c[i];
}

void __attribute__((sseregparm))
test_neg_add_neg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -(-(a[i] * b[i]) + c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_neg_add_neg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -(-(a[i] * b[i]) + c[i]) * a[i] - c[i];
}

void __attribute__((sseregparm))
test_neg_sub_noneg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = (-(a[i] * b[i]) - c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_neg_sub_noneg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = (-(a[i] * b[i]) - c[i]) * a[i] - c[i];
}

void __attribute__((sseregparm))
test_neg_sub_neg_add (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -(-(a[i] * b[i]) - c[i]) * a[i] + c[i];
}

void __attribute__((sseregparm))
test_neg_sub_neg_sub (adouble *a, adouble *b, adouble *c, adouble *d, int n)
{
  int i;
  for (i = 0; i < n; i++)
    d[i] = -(-(a[i] * b[i]) - c[i]) * a[i] - c[i];
}

