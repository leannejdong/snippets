#include <vector>
#include <algorithm>

using std::ranges::count;

bool f(const auto &v)
{
    using std::ranges::count;
    return (count(v,10) == 2 || count(v,20) == 2);
}

int main()
{
    std::array<int,3> v = {10,10,20};
    return f(v);
}

// check a given array of integers and return true if the array contains 10 or 20 twice. 
// The length of the array will be 0, 1, or 2.
