int x[10];
int x[] = {1,2,3};
int testx[(sizeof(x) == sizeof(int) * 10) ? 1 : -1];
int (*a)(int (*x)[10], int (*y)[]);
int (*a)(int (*x)[], int (*y)[5]);
void b() {
  int x[10], y[5];
  a(&x, &y);
  a(&y, &y);
  a(&x, &x);
}
