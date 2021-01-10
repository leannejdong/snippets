#include <numeric>
#include <vector>
#include <iostream>

using std::vector;
using std::cerr;


static float productOf(const vector<float> &values)
{
    float x = 1;

    return std::accumulate(values.begin(), values.end(), 1.0f,
       [x](float a, float b){ return a*b + x; });
}


int main()
{
    vector<float> v = {1, 3.5, 7};
    float p = productOf(v);
    cerr << "p: " << p << "\n";
}

//using std::accumulate to get the product of all values in a vector 
// along with lambda
// This is a situation where we have a complex function object, 
// https://godbolt.org/z/ov38va
