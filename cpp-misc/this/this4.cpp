#include <iostream>

using std::cerr;

namespace {
struct A {
    int x = 0;
    int y = 0;

    void f1();
};
}


void A::f1()
{
    int x = 5;
    ++x; // increments the local variable
    cerr << "After incremtting local variable:\n";
    cerr << "  local x = " << x << "\n";
    cerr << "  member x = " << this->x << "\n";
    ++this->x; // increments the member
    cerr << "After incrementing member\n";
    cerr << "  local x = " << x << "\n";
    cerr << "  member x = " << this->x << "\n";
    ++y; // increments the member
}


int main()
{
    A a;
    a.f1();
}

/*
If we say this->x that is just the same as saying x
unless there is a local variable that is also called x
in which case x refers to the local variable instead
*/
