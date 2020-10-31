#include <iostream>
#include <cmath>

template <typename Function, typename Var, typename Float>
static auto fin_diff(const Function &f, Var &var, Float h)
{
    Var old_value = var;
    var = old_value - h;
    auto result1 = f();
    var = old_value + h;
    auto result2 = f();
    var = old_value;
    return (result2 - result1)/(2*h);
}

int main()
{
    using std::cout;
    auto sin_plus_cos = [](auto x, auto y) { return sin(x)+cos(y); };
    double x = 1;
    double y = 0.5;
    auto f = [&]{ return sin_plus_cos(x,y); };
    cout << fin_diff(f, x, 0.001) << '\n';
    cout << fin_diff(f, y, 0.001) << '\n';
}
