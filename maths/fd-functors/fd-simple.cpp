//Finite difference with function pointers
#include <iostream>
#include <cmath>
#include <cstdio>

double fin_diff(double f(double), double x, double h);
double sin_plus_cos(double x);



double fin_diff(double f(double), double x, double h)
{
    return (f(x+h) - f(x))/h;
}

double sin_plus_cos(double x)
{
    return sin(x) + cos(x);
}

int main()
{
    using namespace std;
    cout << fin_diff(sin_plus_cos, 1., 0.001) << '\n';
    cout << fin_diff(sin_plus_cos, 0., 0.001) << '\n';

}

