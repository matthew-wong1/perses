



void
fn2 (short *s, long *l)
{
}

unsigned *
fn1 (void)
{
  int (*fpi) (int);
  int (*fpd) (double) = fpi;
  fpi = fpd;
  char *di;
  float *dp = &di;
  di = dp;
  fn2 (dp, di);
  return dp;
}
