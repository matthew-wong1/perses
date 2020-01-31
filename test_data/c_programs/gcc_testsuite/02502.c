extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
char *
strrchr (const char *s, int c)
{
  long unsigned int i;






  i = 0;
  while (s[i] != 0)
    i++;

  do
    if (s[i] == c)
      return (char *) s + i;
  while (i-- != 0);

  return 0;
}

__attribute__ ((__noinline__))
char *
rindex (const char *s, int c)
{
  return strrchr (s, c);
}
