







void bar (char *, double *);



struct S { char c[sizeof (double)]; };
void baz (struct S, struct S);
union U { struct S s; double d; };

__attribute__((noinline)) int
foo (double c1, double c2)
{
  double *a = &c1;
  char *b = (char *) &c1 + 2;

  b[-2]++;
  b[1]--;
  *a++;
  c2++;
  bar ((char *) &c2 + 1, &c2);
  c2 *= 3.0;
  bar (b, a);
  baz (((union U) { .d = c1 }).s, ((union U) { .d = c2 }).s);
  baz (*(struct S *)&c1, *(struct S *)&c2);
  return c1 + c2 + ((struct S *)&c1)->c[1];
}

