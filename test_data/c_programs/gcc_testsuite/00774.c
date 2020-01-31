


extern void abort (void);

int
foosi (int x)
{
  return x > 100 ? x - 2 : x - 1;
}

int
barsi (int x)
{
  return x > 100 ? x + 4 : x + 3;
}

long
foodi (long x)
{
  return x > 100 ? x - 2 : x - 1;
}

long
bardi (long x)
{
  return x > 100 ? x + 4 : x + 3;
}




int
main (void)
{
  if (foosi (105) != 103)
    abort ();

  if (foosi (95) != 94)
    abort ();

  if (barsi (105) != 109)
    abort ();

  if (barsi (95) != 98)
    abort ();

  if (foodi (105) != 103)
    abort ();

  if (foodi (95) != 94)
    abort ();

  if (bardi (105) != 109)
    abort ();

  if (bardi (95) != 98)
    abort ();

  return 0;
}
