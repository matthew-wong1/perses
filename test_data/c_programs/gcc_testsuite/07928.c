

typedef int myint;

float __attribute__((vector_size(16))) b;
int __attribute__((vector_size(16))) d;
myint __attribute__((vector_size(16))) d2;
unsigned int __attribute__((vector_size(16))) e;

void foo()
{
 b + d;
 d += e;
 d2 += d;
}
