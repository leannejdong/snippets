#include <iostream>

using std::cerr;


struct A {
    A() // Default constructor for A
    {
        cerr << "In A::A()\n";
    }

    A(int y) // Another onstructor for A
    { // used when you don't have explicit constructor arguments
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
    cerr << "Constructing x3\n";
    A x3{};
    cerr << "Done constructing x3\n";
}

/* For class types it doesn't make much difference
The default constructor gets called either way
For primitive types like int, it does make a difference.
A primitive type will be uninitialized if you don't use {} */
