


int a, b, c;
void bar (int);

void
foo (void)
{
  if (a)
    if (b)
      {
 if (c)
   bar (0);
      }
    else
      bar (1);

  if (a > 0)
    if (a > 1)
      if (a > 2)
 if (a > 3)
   if (a > 4)
     if (a > 5)
       if (a > 6)
  while (1)
    bar (0);
  else
    bar (1);

  if (a)
    if (b)
      switch (c);
    else
      bar (1);

  switch (a)
  {
  default:
    if (b)
      if (c)
 for (;;)
          bar (0);
    else
      bar (1);
  }

  if (a)
  if (a)
    {
      bar (2);
    }
  else
    bar (3);

  if (a)
    do if (b) bar (4); while (1);
  else bar (5);

  do
    {
      if (a)
        if (b)
         if (c) for (;;) bar (6);
     else bar (7);
    } while (0);
}
