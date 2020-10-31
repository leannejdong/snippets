//Finite difference with function pointers
#include <iostream>
#include <cmath>
#include <cstdio>
#include <type_traits>

template <typename Morphism>
constexpr double fin_diff(Morphism &&morphism, double x, double h) noexcept(noexcept(morphism(x)))
{
    static_assert(std::is_invocable_r_v<double, std::decay_t<Morphism>, double>);
    return (morphism(x+h) - morphism(x))/h;
}

int main()
{
    using namespace std;
    
    constexpr auto sin_plus_cos{[](double x) noexcept -> double { 
        return sin(x)+cos(x);
    }};

    cout << fin_diff(sin_plus_cos, 1., 0.001) << '\n';
    cout << fin_diff(sin_plus_cos, 0., 0.001) << '\n';

}

