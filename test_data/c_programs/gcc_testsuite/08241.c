
__attribute__ ((noinline))
int factorial(int x)
{
   if (x == 1)
     return 1;
   else
     return x*factorial(--x);
}
int gbl;
int
main()
{
   gbl = factorial(100);
   return 0;
}
