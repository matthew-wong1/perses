

volatile int g[32];
long long gll;
double gd;
void
test (int n)
{
  union { long long l; double d; } u = { 0x12345678 };
  gll = u.l;
  int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30;
  x1 = g[1], x2 = g[2], x3 = g[3], x4 = g[4], x5 = g[5], x6 = g[6], x7 = g[7], x8 = g[8], x9 = g[9], x10 = g[10], x11 = g[11], x12 = g[12], x13 = g[13], x14 = g[14], x15 = g[15], x16 = g[16], x17 = g[17], x18 = g[18], x19 = g[19], x20 = g[20], x21 = g[21], x22 = g[22], x23 = g[23], x24 = g[24], x25 = g[25], x26 = g[26], x27 = g[27], x28 = g[28], x29 = g[29], x30 = g[30];
  g[1] = x1, g[2] = x2, g[3] = x3, g[4] = x4, g[5] = x5, g[6] = x6, g[7] = x7, g[8] = x8, g[9] = x9, g[10] = x10, g[11] = x11, g[12] = x12, g[13] = x13, g[14] = x14, g[15] = x15, g[16] = x16, g[17] = x17, g[18] = x18, g[19] = x19, g[20] = x20, g[21] = x21, g[22] = x22, g[23] = x23, g[24] = x24, g[25] = x25, g[26] = x26, g[27] = x27, g[28] = x28, g[29] = x29, g[30] = x30;
  g[1] = x1, g[2] = x2, g[3] = x3, g[4] = x4, g[5] = x5, g[6] = x6, g[7] = x7, g[8] = x8, g[9] = x9, g[10] = x10, g[11] = x11, g[12] = x12, g[13] = x13, g[14] = x14, g[15] = x15, g[16] = x16, g[17] = x17, g[18] = x18, g[19] = x19, g[20] = x20, g[21] = x21, g[22] = x22, g[23] = x23, g[24] = x24, g[25] = x25, g[26] = x26, g[27] = x27, g[28] = x28, g[29] = x29, g[30] = x30;
  g[1] = x1, g[2] = x2, g[3] = x3, g[4] = x4, g[5] = x5, g[6] = x6, g[7] = x7, g[8] = x8, g[9] = x9, g[10] = x10, g[11] = x11, g[12] = x12, g[13] = x13, g[14] = x14, g[15] = x15, g[16] = x16, g[17] = x17, g[18] = x18, g[19] = x19, g[20] = x20, g[21] = x21, g[22] = x22, g[23] = x23, g[24] = x24, g[25] = x25, g[26] = x26, g[27] = x27, g[28] = x28, g[29] = x29, g[30] = x30;
  gd = u.d;
}
