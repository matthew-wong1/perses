






int foo (int);

int a, b, c;
_Bool d;

void
bar (void)
{
  if (a += b)
    foo (0);
  if (a -= a)
    foo (1);
  if (b *= c)
    foo (2);
  else
    foo (3);
  if (b /= b)
    foo (4);
  else
    foo (5);
  while (c %= b)
    foo (6);
  while (c <<= c)
    foo (7);
  do foo (8); while (a >>= b);
  do foo (9); while (a &= a);
  for (;c ^= b;)
    foo (10);
  for (;c |= c;)
    foo (11);
  d = a += b;
  foo (12);
  d = a -= a;
  foo (13);
}
