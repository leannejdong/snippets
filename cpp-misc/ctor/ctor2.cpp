#include <iostream>

using std::cerr;


struct A {
    A() // Default constructor for A
    {
        cerr << "In A::A()\n";
    }

    A(int y) // Another onstructor for A
    {
        cerr << "In A::A(int): y=" << y << "\n";
    }
};


int main()
{
    cerr << "Constructing x\n";
    A x(5); // Construct an A called x, with y=5
    cerr << "Done constructing x\n";
    cerr << "Constructing x2\n";
    A x2;
    cerr << "Done constructing x2\n";
}
