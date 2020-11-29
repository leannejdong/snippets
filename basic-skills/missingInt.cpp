#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

using std::vector;
namespace ranges = std::ranges;


int solution(vector<int>& Vec)
{
    //Sort and remove duplicates: Method 1
    std::ranges::sort(Vec);
   // std::sort(Vec.begin(), Vec.end());
    Vec.erase(std::unique(Vec.begin(), Vec.end()), Vec.end());

    //Sort and remove duplicates: Method 2
    // std::set<int> s(Vec.begin(), Vec.end());
    // Vec.assign(s.begin(), s.end());


    //Remove all ints < 1
    Vec.erase(std::remove_if(Vec.begin(), Vec.end(), [](int x){ return x<1; }),Vec.end());

    size_t i=0;

    for(; i < Vec.size(); ++i)
    {
        if(Vec.at(i) != int(i+1))
            break;
    }

    return int(i+1);
}

int main()
{
    {
        vector<int> vec {-1, 2, 3, 4, 7};
        assert(solution(vec) == 1);
        std::cerr << solution(vec) << "\n";
    }
    {
        vector<int> vec {1, 2, 3, 4, 7};
        assert(solution(vec) == 5);
        std::cerr << solution(vec) << "\n";

    }    
    {
        vector<int> vec {1, 2, 3, 4};
        assert(solution(vec) == 5);
        std::cerr << solution(vec) << "\n";
    }
    {
        vector<int> vec {0};
        assert(solution(vec) == 1);
        std::cerr << solution(vec) << "\n";
    }
}

/*
The while loop implicitly capture the case all ints <1 due to the .Erase().
The logic can be simpler because that assumption can be made.
Each stage of the algorithm is basically making it easier to work with the Vec.
At the top of the function, we don't know much about the numbers, so it makes them hard to work with.
So we progressively change things to make it easier to work with.
Any duplicates are irrelevant, so we'd like to remove them.
We can do that using std::uniqe, but it requires the vector to be sorted.
So we sort the vector first. Now we can use std::unique on it.
At that point, we now have a vector that we know has no duplicates and is sorted
It would be fairly easy to find the missing element if there was no negative ones, since we could just step through each position and see if the position matches the element value. But the negative elements get in the way of being able to do that. So we remove them. Now we have a vector which we know has no duplicates, all elements are positive, and is sorted. So we can simply walk through through the elements until the value doesn't match the position or we reach the end.
*/
