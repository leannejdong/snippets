#include <iostream>

using std::cerr;

namespace {
struct A {
    int x = 0;

    void f1()
    {
        ++this->x;
    }
};
}


static void f2(A *p)
{
    ++p->x;
}


static void example1()
{
    A a;
    a.f1();
}


static void example2()
{
    A a;
    f2(&a);
}


int main()
{
}

// eg1&2 doing the same jobs
