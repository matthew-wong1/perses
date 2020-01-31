

int adler32(int adler, char *buf, int n)
{
  int sum = 0;
  do {
     adler += buf[0];
     sum += adler;
     adler += buf[1];
     sum += adler;
     adler += buf[2];
     sum += adler;
     adler += buf[3];
     sum += adler;
  } while (--n);
  return adler | (sum << 16);
}
