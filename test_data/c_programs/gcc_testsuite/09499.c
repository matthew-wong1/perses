



_Noreturn void exit (int);

_Noreturn int f1 (void);

_Noreturn void f2 (void);

static void _Noreturn f3 (void) { exit (0); }





_Noreturn int
f4 (void)
{
  return 1;

}

_Noreturn void
f5 (void)
{
  return;

}

_Noreturn void
f6 (void)
{
}

_Noreturn void
f7 (int a)
{
  if (a)
    exit (0);
}



void f2 (void);

void f8 (void);
_Noreturn void f8 (void);


_Noreturn _Noreturn void _Noreturn f9 (void);



void (*fp) (void) = f5;



int noreturn;
