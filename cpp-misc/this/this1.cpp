#include <iostream>

using std::cerr;


struct A {
    void f()
    {
        cerr << "Inside f(): this = " << this << "\n";
    }
};


int main()
{
    A a;
    cerr << "Before calling a.f(): &a = " << &a << "\n";
    a.f();
}
