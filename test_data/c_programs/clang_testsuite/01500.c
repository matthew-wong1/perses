void
foo (void)
{
 struct b;
 struct b* x = 0;
 struct b* y = &*x;
}
void foo2 (void)
{
 typedef int (*arrayptr)[];
 arrayptr x = 0;
 arrayptr y = &*x;
}
void foo3 (void)
{
 void* x = 0;
 void* y = &*x;
}
extern const void cv1;
const void *foo4 (void)
{
  return &cv1;
}
extern void cv2;
void *foo5 (void)
{
  return &cv2;
}
typedef const void CVT;
extern CVT cv3;
const void *foo6 (void)
{
  return &cv3;
}
