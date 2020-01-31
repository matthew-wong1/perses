



void *memset (void *, int, long unsigned int);
void *memcpy (void *, const void *, long unsigned int);

char *alloc (int);

char *
test (int type, int size, char *data, int len)
{
  char *block = alloc (size);
  char *bp = block;

  *bp++ = type;
  switch (type)
    {
    case 0:
    case 1:
      memset (bp, type == 0 ? 0x00 : 0xff, size);
      memcpy (bp, data, len);
    }

  return block;
}
