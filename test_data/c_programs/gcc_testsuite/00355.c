int
f(int a, int b, int c)
{
  a -= (short)b * (c >> 16);
  if (!a)
    return 10;
  return a;
}
