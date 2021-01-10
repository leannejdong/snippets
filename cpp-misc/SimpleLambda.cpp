#include <numeric>
#include <vector>
#include <iostream>

using std::vector;
using std::cerr;


static float productOf(const vector<float> &values)
{
    return std::accumulate(values.begin(), values.end(), 1.0f, [](float a, float b){ return a*b; });
}


int main()
{
    vector<float> v = {1, 3.5, 7};
    float p = productOf(v);
    cerr << "p: " << p << "\n";
}

// std::accumulate to get the product of all values in a vector using lambda
