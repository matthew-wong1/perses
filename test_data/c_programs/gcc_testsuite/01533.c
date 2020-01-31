




extern void abort ();


float a[16] = {-0.1f, -3.2f, -6.3f, -9.4f,
       -12.5f, -15.6f, -18.7f, -21.8f,
       24.9f, 27.1f, 30.2f, 33.3f,
       36.4f, 39.5f, 42.6f, 45.7f};
float b[16] = {-1.2f, 3.4f, -5.6f, 7.8f,
       -9.0f, 1.0f, -2.0f, 3.0f,
       -4.0f, -5.0f, 6.0f, 7.0f,
       -8.0f, -9.0f, 10.0f, 11.0f};
float r[16];

int
main (void)
{
  int i;

  for (i = 0; i < 16; i++)
    r[i] = __builtin_copysignf (a[i], b[i]);


  for (i = 0; i < 16; i++)
    if (r[i] != __builtin_copysignf (a[i], b[i]))
      abort ();

  return 0;
}
