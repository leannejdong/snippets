#include <iostream>

using std::cerr;

namespace {
struct A {
    int x = 0;

    void f1();
};
}


static void show(A *p)
{
    cerr << "p = " << p << "\n";
}

void A::f1()
{
    show(this);
}


static void f2(A *p)
{
    show(p);
}


int main()
{
    A a;
    a.f1();
    f2(&a);
}

// eg1&2 doing the same jobs
