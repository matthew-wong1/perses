



char acDummy[0xf0] __attribute__ ((__BELOW100__));
unsigned short B100A __attribute__ ((__BELOW100__));
unsigned short *pA = &B100A;
unsigned short B100B __attribute__ ((__BELOW100__));
unsigned short *pB = &B100B;

char *
Do (void)
{
  if (!(B100A & 0x8000))
    {
      if (!(B100B & 0x8000))
 return "Fail";
      else
 return "Success";
    }
  else
    return "Fail";
}

int
main (void)
{
  *pA = 0x1234;
  *pB = 0xedcb;
  return Do ()[0] == 'F';
}
