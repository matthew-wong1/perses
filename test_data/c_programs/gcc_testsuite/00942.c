



unsigned char *pA = (unsigned char *) 0x7f14;

unsigned char *pB = (unsigned char *) 0x7f10;

char *
Do (void)
{
  if (!((*((volatile unsigned char*)0x7f14)) & 0x01))
    {
      if (!((*((volatile unsigned char*)0x7f10)) & 0x01))
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
  *pA = 0x34;
  *pB = 0xcb;
  return Do ()[0] == 'F';
}
