unsigned int
f(unsigned int b, unsigned int c)
{
  unsigned int a = (b >> 16) * (c >> 16);
  if (!a)
    return 10;
  return a;
}
