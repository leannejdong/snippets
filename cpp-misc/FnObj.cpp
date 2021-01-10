#include <numeric>
#include <vector>
#include <iostream>

using std::vector;
using std::cerr;


static float productOf(const vector<float> &values)
{
    struct Multiply {
        float operator()(float a, float b) const
        {
            return a*b;
        }
    };

    return std::accumulate(values.begin(), values.end(), 1.0f, Multiply());
}


int main()
{
    vector<float> v = {1, 3.5, 7};
    float p = productOf(v);
    cerr << "p: " << p << "\n";
}

// manually created function object 
// along  with std::accumulate to get the product of all values in a vector
// here we need more information that just a and b
// https://godbolt.org/z/EqEPh1
