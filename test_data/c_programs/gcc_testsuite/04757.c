



int r;
void
foo (int a)
{
  r = a > 0 || !a >= 2;
  r = !a || a == 10;
  r = !a && !a < 4;
  r = !a > 0 && a < 6;
  r = a + (!a < 12);
  r = a == 7 || !a < 12;
  r = (a == 7 * a > 0) || !a < 2;
  r = (1 > !a) || (!42 > a);
  r = (!5 > a);
  r = (!0 > a);
  r = (!-5 > a);
  r = (!(5 + 3) > a);
  r = (!(5 - a) > a);
}
