


typedef struct
{
  unsigned char b0:1;
  unsigned char b1:1;
  unsigned char b2:1;
  unsigned char b3:1;
  unsigned char b4:1;
  unsigned char b5:1;
  unsigned char b6:1;
  unsigned char b7:1;
} BitField;

char acDummy[0xf0] __attribute__ ((__BELOW100__));
BitField B100 __attribute__ ((__BELOW100__)) =
{
0, 0, 1, 0, 1, 1, 0, 0};
unsigned char *p = (unsigned char *) &B100;

void
Do (void)
{
  B100.b7 = 1;
}

int
main (void)
{
  Do ();
  return (*p == 0xb4) ? 0 : 1;
}
