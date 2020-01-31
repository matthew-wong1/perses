



typedef struct {
  double min;
  double max;
} interval;
inline interval add(interval x, interval y) __attribute__((always_inline));
inline interval add(interval x, interval y)
{
  interval r;
  r.min = x.min + y.min;
  r.max = x.max + y.max;
  return r;
}
interval foo (interval a, interval b, interval c)
{
  return add (a, add (b, c));
}
