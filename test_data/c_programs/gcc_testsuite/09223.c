



extern int A[], B[];

void
foo (int z)
{
  int j, i;
  for (j = 0; j < 32; j++)
    {
      int a = A[0];
      for (i = 0; i < 16; i++)
 a = A[i] ? a : z;
      B[j] = a;
    }
}
