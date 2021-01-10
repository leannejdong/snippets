#include <iostream>

using std::cerr;

struct A {
     int x = 0;
};

int main()
{
    A a;
    A *ap = &a;
    a.x = 5;
    cerr << "Before incrementing a.x:\n";
    cerr << "  a.x: " << a.x << "\n";
    cerr << "  ap->x: " << ap->x << "\n";
    cerr << "  (*ap).x: " << (*ap).x << "\n";
    ++a.x;
    cerr << "After incrementing a.x:\n";
    cerr << "  a.x: " << a.x << "\n";
    cerr << "  ap->x: " << ap->x << "\n";
    cerr << "  (*ap).x: " << (*ap).x << "\n";
    ++ap->x;
    cerr << "After incrementing ap->x:\n";
    cerr << "  a.x: " << a.x << "\n";
    cerr << "  ap->x: " << ap->x << "\n";
    cerr << "  (*ap).x: " << (*ap).x << "\n";
}

// a->b is same as (*a).b
// a->b means the b member of what a points to
//https://godbolt.org/z/q5zYxM
