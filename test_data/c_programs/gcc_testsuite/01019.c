



char acDummy[0xf0] __attribute__ ((__BELOW100__));
unsigned char B100A __attribute__ ((__BELOW100__)) = 0xcb;
unsigned char *pA = &B100A;
unsigned char B100B __attribute__ ((__BELOW100__)) = 0x34;
unsigned char *pB = &B100B;

char *
Do (void)
{
  if (B100A & 0x80)
    {
      if (B100B & 0x80)
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
  return Do ()[0] == 'F';
}
