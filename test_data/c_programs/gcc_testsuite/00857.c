


char acDummy[0xf0] __attribute__ ((__BELOW100__));
unsigned short B100 __attribute__ ((__BELOW100__));
unsigned short *p = &B100;

void
Do (void)
{
  B100 |= 0x0100;
}

int
main (void)
{
  *p = 0x1234;
  Do ();
  return (*p == 0x1334) ? 0 : 1;
}
