

extern void bar(int);
void foo(void)
{
#pragma omp sections
 bar (0);

#pragma omp sections
 {
    }

#pragma omp sections
 {
      bar (1);
    }

#pragma omp sections
 {
#pragma omp section
 bar(2);
      bar(3);
      bar(4);
#pragma omp section
 bar(5);
      bar(6);
      bar(7);
    }
}
