typedef unsigned cond_t;
volatile cond_t test;
volatile int i0;
volatile __fp16 h0 = 0.0, h1 = 1.0, h2;
volatile float f0, f1, f2;
volatile double d0;
void foo(void) {
  test = (h0);
  h0 = (test);
  test = (!h1);
  h1 = -h1;
  h1 = +h1;
  h1++;
  ++h1;
  --h1;
  h1--;
  h1 = h0 * h2;
  h1 = h0 * (__fp16) -2.0f;
  h1 = h0 * f2;
  h1 = f0 * h2;
  h1 = h0 * i0;
  h1 = (h0 / h2);
  h1 = (h0 / (__fp16) -2.0f);
  h1 = (h0 / f2);
  h1 = (f0 / h2);
  h1 = (h0 / i0);
  h1 = (h2 + h0);
  h1 = ((__fp16)-2.0 + h0);
  h1 = (h2 + f0);
  h1 = (f2 + h0);
  h1 = (h0 + i0);
  h1 = (h2 - h0);
  h1 = ((__fp16)-2.0f - h0);
  h1 = (h2 - f0);
  h1 = (f2 - h0);
  h1 = (h0 - i0);
  test = (h2 < h0);
  test = (h2 < (__fp16)42.0);
  test = (h2 < f0);
  test = (f2 < h0);
  test = (i0 < h0);
  test = (h0 < i0);
  test = (h0 > h2);
  test = ((__fp16)42.0 > h2);
  test = (h0 > f2);
  test = (f0 > h2);
  test = (i0 > h0);
  test = (h0 > i0);
  test = (h2 <= h0);
  test = (h2 <= (__fp16)42.0);
  test = (h2 <= f0);
  test = (f2 <= h0);
  test = (i0 <= h0);
  test = (h0 <= i0);
  test = (h0 >= h2);
  test = (h0 >= (__fp16)-2.0);
  test = (h0 >= f2);
  test = (f0 >= h2);
  test = (i0 >= h0);
  test = (h0 >= i0);
  test = (h1 == h2);
  test = (h1 == (__fp16)1.0);
  test = (h1 == f1);
  test = (f1 == h1);
  test = (i0 == h0);
  test = (h0 == i0);
  test = (h1 != h2);
  test = (h1 != (__fp16)1.0);
  test = (h1 != f1);
  test = (f1 != h1);
  test = (i0 != h0);
  test = (h0 != i0);
  h1 = (h1 ? h2 : h0);
  h0 = h1;
  h0 = (__fp16)-2.0f;
  h0 = f0;
  h0 = i0;
  i0 = h0;
  h0 += h1;
  h0 += (__fp16)1.0f;
  h0 += f2;
  i0 += h0;
  h0 += i0;
  h0 -= h1;
  h0 -= (__fp16)1.0;
  h0 -= f2;
  i0 -= h0;
  h0 -= i0;
  h0 *= h1;
  h0 *= (__fp16)1.0;
  h0 *= f2;
  i0 *= h0;
  h0 *= i0;
  h0 /= h1;
  h0 /= (__fp16)1.0;
  h0 /= f2;
  i0 /= h0;
  h0 /= i0;
  h0 = d0;
  h0 = (float)d0;
  d0 = h0;
  d0 = (float)h0;
}
