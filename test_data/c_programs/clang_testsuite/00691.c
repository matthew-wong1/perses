void bar();
void foo() { bar(); }
void Test(int *res, int *c, int *d, int *p, int n) {
  int i;
#pragma clang loop vectorize(assume_safety)
  for (i = 0; i < 1600; i++) {
    res[i] = (p[i] == 0) ? res[i] : res[i] + d[i];
  }
}
