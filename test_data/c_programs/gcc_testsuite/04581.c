




int
main (void)
{
  const double inf = __builtin_inf ();
  const double nan = __builtin_nan ("");
  volatile double d;

  __int128 i;
  d = (-(__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1) - 1);
  (i) = (d) - 5.0; (i) = (d) - 1.5; (i) = (d) - 1.0; (i) = (d) - 0.75; (i) = (d) - 0.5; (i) = (d) - 0.0000001; (i) = (d) - 0.0; (i) = (d); (i) = (d) + 0.0; (i) = (d) + 0.0000001; (i) = (d) + 0.5; (i) = (d) + 0.75; (i) = (d) + 1.0; (i) = (d) + 1.5; (i) = (d) + 5.0;;
  d = 0.0;
  (i) = (d) - 5.0; (i) = (d) - 1.5; (i) = (d) - 1.0; (i) = (d) - 0.75; (i) = (d) - 0.5; (i) = (d) - 0.0000001; (i) = (d) - 0.0; (i) = (d); (i) = (d) + 0.0; (i) = (d) + 0.0000001; (i) = (d) + 0.5; (i) = (d) + 0.75; (i) = (d) + 1.0; (i) = (d) + 1.5; (i) = (d) + 5.0;;
  d = (__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1);
  (i) = (d) - 5.0; (i) = (d) - 1.5; (i) = (d) - 1.0; (i) = (d) - 0.75; (i) = (d) - 0.5; (i) = (d) - 0.0000001; (i) = (d) - 0.0; (i) = (d); (i) = (d) + 0.0; (i) = (d) + 0.0000001; (i) = (d) + 0.5; (i) = (d) + 0.75; (i) = (d) + 1.0; (i) = (d) + 1.5; (i) = (d) + 5.0;;
  (i) = nan; (i) = -nan; (i) = inf; (i) = -inf;;

  unsigned __int128 u;
  d = ((2 * (unsigned __int128) (__int128) (((unsigned __int128) 1 << ((16 * 8) - 1)) - 1)) + 1);
  (u) = (d) - 5.0; (u) = (d) - 1.5; (u) = (d) - 1.0; (u) = (d) - 0.75; (u) = (d) - 0.5; (u) = (d) - 0.0000001; (u) = (d) - 0.0; (u) = (d); (u) = (d) + 0.0; (u) = (d) + 0.0000001; (u) = (d) + 0.5; (u) = (d) + 0.75; (u) = (d) + 1.0; (u) = (d) + 1.5; (u) = (d) + 5.0;;
  d = 0.0;
  (u) = (d) - 5.0; (u) = (d) - 1.5; (u) = (d) - 1.0; (u) = (d) - 0.75; (u) = (d) - 0.5; (u) = (d) - 0.0000001; (u) = (d) - 0.0; (u) = (d); (u) = (d) + 0.0; (u) = (d) + 0.0000001; (u) = (d) + 0.5; (u) = (d) + 0.75; (u) = (d) + 1.0; (u) = (d) + 1.5; (u) = (d) + 5.0;;
  (u) = nan; (u) = -nan; (u) = inf; (u) = -inf;;

  return 0;
}
