




extern void abort (void);
extern void exit (int);

struct { int a; int x[]; } d1 = { 0, 0 };
int d2 = 0;

int
main ()
{
  d2 = 1;
  if (sizeof (d1) != sizeof (int))
    abort ();
  if (d1.x[0] != 0)
    abort ();
  exit (0);
}
