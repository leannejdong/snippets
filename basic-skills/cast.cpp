#include <iostream>
using std::cerr;
int main()
{
    int age = 44;
    double height = 6.02;

    cerr << "Age" << age << "\n";
    cerr << "Height: " << height << "\n";

    age = static_cast<int>(44.90);
    cerr << "Age: " << age << "\n";

    signed int dogs = -1;
    cerr << "Dogs:" << dogs << "\n";
    dogs = 15;
    cerr << "Dogs:" << dogs << "\n";

    unsigned int cats = static_cast<unsigned int>(-1);
    cerr << "Cats:" << cats << "\n";
    dogs = 15;
    cerr << "Cats:" << cats << "\n";

    cerr << sizeof (dogs) << "\n";
    cerr << sizeof (cats) << "\n";
    cerr << sizeof (height) << "\n";
}
//-std=c++20  -Wconversion -Wsign-conversion
