



struct A
{
    int i;
    int x[];
};

int foo(struct A a)
{
    return (a,a).x[0];
}
