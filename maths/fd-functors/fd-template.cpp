#include <iostream>
#include <cmath>


template <typename Morphism>
static double fin_diff(const Morphism &morphism, double x, double h)
{
    return (morphism(x+h) - morphism(x))/h;
}


int main()
{
    using std::cout;
    
    auto sin_plus_cos = [](auto x) { return sin(x)+cos(x); };

    cout << fin_diff(sin_plus_cos, 1., 0.001) << '\n';
    cout << fin_diff(sin_plus_cos, 0., 0.001) << '\n';
}
