#include <functional>
#include <fmt/format.h>
#include <cassert>
#include <memory>

class Iteration {
public:
    virtual double solve(double) { return {}; }
    virtual double solve(double, double) { return {}; }

    int numberOfIterations() const { return mNumberOfIterations; }
    virtual ~Iteration() = default;// the wrong type of object will be destroyed// without a virtual dtor

protected:
    explicit Iteration(double epsilon) : mEpsilon(epsilon), mNumberOfIterations(0) {}

    void resetNumberOfIterations() { mNumberOfIterations = 0; }
    int incrementNumberOfIterations() { return mNumberOfIterations++; }
    double epsilon() const { return mEpsilon; }

private:
    const double mEpsilon;
    int mNumberOfIterations;
};


class Newton : public Iteration {
public:
    Newton(double epsilon, const std::function<double (double)> f, const std::function<double (double)> fPrime) : Iteration(epsilon), mf(f), mfPrime(fPrime) {}
    ~Newton() override = default;
 
    double solve(double x) override {
        resetNumberOfIterations();

        fmt::print("Newton -> [x0 = {:}]\n", x);
        fmt::print("{:<5}|{:<20}|{:<20}|{:<20}\n", "K", "x", "f(x)", "f'(x)");
        fmt::print("------------------------------------------------------------------ \n");

        double fx = mf(x);
        double fxPrime = mfPrime(x);
        fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), x, fx, fxPrime);

        while(fabs(fx) >= epsilon()) {
            x = calculateX(x, fx, fxPrime);

            fx = mf(x);
            fxPrime = mfPrime(x);

            fmt::print("{:<5}|{:<20.15f}|{:<20.15f}|{:<20.15f}\n", incrementNumberOfIterations(), x, fx, fxPrime);
        }

        fmt::print("\n");

        return x;
    }

private:
    static double calculateX(double x, double fx, double fxPrime) {
        assert(fabs(fxPrime) >= std::numeric_limits<double>::min());

        return x - fx/fxPrime;
    }

    const std::function<double (double)> mf;
    const std::function<double (double)> mfPrime;
};


int main()
{
    auto f = [](double x){
        return x*x*x-x*x-x-1;
    };

    auto fPrime = [](double x) {
        return 3*x*x-2*x-1;
    };

    const double epsilon = 1e-10;

    std::unique_ptr<Iteration> newton = std::make_unique<Newton>(epsilon, f, fPrime);
    const double newtonResults = newton->solve(1.5);

    fmt::print("{:<20}|{:<15}|{:<20}|{:<10.15f}\n", "Newton Method", "[x^0=1.5]", newton->numberOfIterations(), newtonResults);

    return 0;
}

/*
The comment code will induce a stack-buffer-overflow
Having a const reference member in a class is a red flag. It isn't necessarily wrong, but it is dangerous. (edited) 
It's very easy to end up a with a dangling reference this way:
const std::function<double (double)> &mf;

If we look at where mf is initialized, we see
Newton(double epsilon, const std::function<double (double)> &f, const std::function<double (double)> &fPrime) : Iteration(epsilon), mf(f), mfPrime(fPrime) {}

We have mf(f), so mf is being initialized with f which is another const reference
Then we look at where f is initialized:
std::unique_ptr<Newton> newton = std::make_unique<Newton>(epsilon, f, fPrime);

so f is being initialized with a lambda
The f parameter to the Newton constructor is a const reference to a std::function and we are initializing it with a lambda
because they are different types, this means that a temporary std::function is created
So the f parameter to the Newton constructor is being initialized with a temporary
Which means the mf member of the Newton  class ends up referring to a temporary
temporaries are destroyed and the end of the full expression, which in this case is the end of the statement here
std::unique_ptr<Newton> newton = std::make_unique<Newton>(epsilon, f, fPrime);
That means that after line 80, the mf member of the Newton class is now a dangling reference
That means that by the time we execute line 37
double fx = mf(x);
mf is dangling (it is referring to an object that has been destroyed)
Using a dangling reference is undefined behavior, so the program is invalid.
*/
