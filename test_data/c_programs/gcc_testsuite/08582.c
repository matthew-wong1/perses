
void foo (int j)
{
  int i1 = (int)(double)1.0 + 2147483647;
  int i2 = (int)(double)1 + 2147483647;
  int i3 = 1 + 2147483647;
  int i4 = +1 + 2147483647;
  int i5 = (int)((double)1.0 + 2147483647);
  int i6 = (double)1.0 + 2147483647;
  int i7 = 0 ? (int)(double)1.0 + 2147483647 : 1;
  int i8 = 1 ? 1 : (int)(double)1.0 + 2147483647;
  int i9 = j ? (int)(double)1.0 + 2147483647 : 1;
  unsigned int i10 = 0 ? (int)(double)1.0 + 2147483647 : 9U;
  unsigned int i11 = 1 ? 9U : (int)(double)1.0 + 2147483647;
  unsigned int i12 = j ? (int)(double)1.0 + 2147483647 : 9U;
  int i13 = 1 || (int)(double)1.0 + 2147483647 < 0;
  int i14 = 0 && (int)(double)1.0 + 2147483647 < 0;
  int i15 = 0 || (int)(double)1.0 + 2147483647 < 0;
  int i16 = 1 && (int)(double)1.0 + 2147483647 < 0;
  int i17 = j || (int)(double)1.0 + 2147483647 < 0;
  int i18 = j && (int)(double)1.0 + 2147483647 < 0;
}
