#include <iostream>

using std::cerr;


// Beginning of class definition for class A
struct A {
    // Beginning of constructor definition for class A
    A(int x)
    {
        cerr << "In constructor, x = " << x << "\n";
    }
    // End of constructor definition for class A
};
// End of class definition for class A

int main()
{
    A a{5};  // Create variable `a` and pass `5` to the constructor;
}
