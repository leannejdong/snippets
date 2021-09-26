#include <iostream>

static auto makeLambda(int x)
{
    auto lamb = [&x]()
    {
        std::cout << "I'm back from hiking, feel good, not bloated~ My value = " << x << "\n";
    };

    // here x has gone out scope before we invoke lamb
    // we'll hv a ref to an object whose life time has ended--> UB

    return lamb;
}


int main()
{
    int x = 38;
    auto lamb = makeLambda(x);
    lamb();
}
// How to fix this?
// make x as a ref in line3 https://compiler-explorer.com/z/d9xzT4Te3
// capture by value https://compiler-explorer.com/z/PY1dca8K3

