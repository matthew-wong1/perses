
unsigned int a[1000];
unsigned int b = 256;
unsigned int c = 1024;
unsigned int d = 17;
int
main ()
{
  int i;
  unsigned int n;
  for (i = 0; i < 1000; i++)
    {
     a[i]=100*i;
    }
  for (i = 0; i < 1000; i++)
    {
      if (i % 2)
 n = b;
      else if (i % 3)
 n = c;
      else
 n = d;
      a[i] %= n;
    }
  return 0;
}
