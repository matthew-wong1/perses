







long a[100];

void com (long);
void bar (long);

long foo (long x, long y, long z)
{


  if (z)
    {
      a[1] = a[0] + a[2] + a[3] + a[4] + a[5] + a[6];
      a[2] = a[1] + a[3] + a[5] + a[5] + a[6] + a[7];
      a[3] = a[2] + a[5] + a[7] + a[6] + a[7] + a[8];
      a[4] = a[3] + a[7] + a[11] + a[7] + a[8] + a[9];
      a[5] = a[5] + a[11] + a[13] + a[8] + a[9] + a[10];
      a[6] = a[7] + a[13] + a[17] + a[9] + a[10] + a[11];
      a[7] = a[11] + a[17] + a[19] + a[10] + a[11] + a[12];
      com (x+y);
    }
  else
    {
      bar (x+y);
    }

  return 0;
}
