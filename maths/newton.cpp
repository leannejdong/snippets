#include <iostream>
#include <cfloat>
#include <cmath>

//typedef double(*func)(double);
using func = double(*)(double);
using std::endl;

class Nonlinear
{
    public: // put all to public because
    // we use our alias
    func Function;
    Nonlinear (func F) { Function = F; }
    // derivative
    double fprime (double);

/* A virtual function allows derived classes to 
   replace the implementation provided by the base class.
   The virtual fn serve as a template for child class, 
   we use it polymprhically */
   virtual double iteration() = 0; // initialize to 0

};

double Nonlinear::fprime(double x)
{
    // step size
    double del = FLT_EPSILON;
    // keep the step size small, multiple and assign the step size to the absolute value of x
    if(std::abs(x) > 1)
    {
        del *= abs(x);
    }
    // centre difference quotient
    return (Function(x + del) - Function(x - del)) / (2*del);

}

class Newton : public Nonlinear
{
    private:
    double x0;  int maxIter;  double eps;

    public:
    Newton(func F, double X, int I, double E): Nonlinear(F), x0(X), maxIter(I), eps(E){}
    virtual double iteration();
};

double Newton::iteration()
{
    double denominator, y, x = x0;
    int iteration = 0;

    while(iteration < maxIter)
    {
        denominator = fprime(x);
        if(abs(denominator) < DBL_EPSILON){
            std::cout << "Denominator is 0\n";
        }
        y = x - Function(x) / denominator;
        if(std::abs(y) > FLT_MAX){
            std::cout << "Overflow\n";
        }
        if(std::abs(x - y) < eps*std::fabs(x)){
            break;
        }
        std::cout << "y = " << y << "\t" << "x = " << x << endl;
        iteration++;
        // assign y to x
        x = y;
    }
    if (iteration >= maxIter)
    {
        x = 0;
        std::cout << "Max number of iteration are reched " << endl;
    }
    return y;
}

/*const*/ double function_1( double x)
{
    return -(x)*(x)*(x) - 4*(x) + 10;
}

/*const*/ double function_2( double x)
{
    return pow(x,3) - 2*(x) + 2;
}
// make ur funct void, put more guards. better abstraction

int main()
{
    std::cout << "Calculation of root using iterative method by newton" << endl;
    Newton poly1(function_1, 1, 10, 1e-6);
    Newton poly2(function_2, -1, 10, 1e-6);

    std::cout << "The approximated root for this function is: " << poly1.iteration() << endl << endl;
    std::cout << "The approximated root for this function is: " << poly2.iteration() << endl << endl;
    return 0;
}
// https://compiler-explorer.com/z/x3sb65fbY
