


float x[2*256+1];

void foo(void)
{
  int i;
  for (i=0; i<256; ++i)
   {
    x[2*i] = x[2*i] * x[2*i];
    x[2*i+1] = x[2*i+1] * x[2*i+1];
   }
}
