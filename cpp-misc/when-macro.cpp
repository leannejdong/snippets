// We need macros when turning
// members on and off a class
#include <iostream>

#define HAS_ADDRESS 0

using std::string;


struct A {
    string name;
#if HAS_ADDRESS
    string address;
#endif
};


int main()
{
}
