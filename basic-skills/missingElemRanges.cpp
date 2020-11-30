#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <ranges>

using std::vector;
namespace ranges = std::ranges;

int soln(vector<int> &v)
{
    ranges::sort(v);
    //auto r = ranges::views::iota(1);
    auto r = std::views::iota(1);
    return *ranges::mismatch(v, r).in2;
}

int main()
{
    {
        vector<int> v { 2, 3, 4, 5};
        assert(soln(v) == 1);
        std::cout << soln(v) << "\n";
    }
    {
        vector<int> v { 2, 3, 1, 5};
        assert(soln(v) == 4);
    }
    {
        vector<int> v { 2, 3, 1, 4, 5};
        assert(soln(v) == 6);
    }
}

// std::iota fills container with a sequence, std::ranges::views::iota 
// represent a sequence without storing it

// The ranges version of iota can represent an infinite range, 
// where we give a begin but no end

// the use of stl or ranges does not change time complexity
// we are just calling a function that does a loop instead of doing the loop yourself

