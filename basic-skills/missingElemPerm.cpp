#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
#include <cassert>

using std::vector;
namespace ranges = std::ranges;

int soln(vector<int> &v)
{
    std::ranges::sort(v);

    int size = (int)v.size();

    for(int i = 0; i < size; i++)
    {
        if(v[i] != (i+1))
        {
            return i + 1;
        }
    }
    return size + 1;
}

int main()
{
    vector<int> v { 2, 3, 1, 5};
    assert(soln(v) == 4);
    std::cout << soln(v);

}

