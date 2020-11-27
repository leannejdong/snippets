#include <limits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <bitset>
#include <string>

using std::cout;
using std::string;
using std::bitset;
constexpr auto limits = std::numeric_limits<int>::digits;

int findlongestgap(int x)
{
    int longest_gap = 0;
    string binary = bitset<limits>(x).to_string();
    auto it = binary.begin();
    /*const*/ auto it_end = binary.end();
    while(it != it_end)
    {
        std::cout << "before find\n";
        auto current_true = std::find(it, it_end, '1');
        if(current_true == it_end) {
            std::cout << "hit end\n";
            break;
        }
        std::cout << "after find\n";

        auto next_true = std::find(current_true+1, it_end, '1');
        if(next_true == it_end) break;

        const auto d = std::distance(current_true, next_true) - 1;
        longest_gap = std::max(longest_gap, static_cast<int>(d));

        it = next_true;
    }
    return longest_gap;
}



int main()
{
    std::cout << "longest gap for 9: " << findlongestgap(9) << "\n";
}
