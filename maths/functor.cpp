#include <iostream>

struct Add {
    int amount;

    int operator()(int arg) const { return arg + amount; }
};


int main()
{
    auto f = Add{5};
    std::cout << f(3) << "\n";
}

/* a function object is needed if you need to carry additional state
like if you wanted a function that would add something to its parameter
but what it would add needed to be determined externally.

Function object is the output of overloading operator().
*/
