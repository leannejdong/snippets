#include <iostream>

using std::cerr;


struct A {
    A(int y) // Constructor for A
    {
        cerr << "In A::A(int): y=" << y << "\n";
    }
};


int main()
{
    cerr << "Constructing x\n";
    A x(5); // Construct an A called x, with y=5
    cerr << "Done constructing x\n";
}
