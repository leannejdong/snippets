#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
#include <optional>

static std::optional<std::pair<int,int>>
findTwoSum(const std::vector<int>& list, int sum)
{
    for(auto & a : list){
        for(auto &b : list){
            if((a + b == sum)){
                return {{a,b}};
            }
        }
    }

    return std::nullopt;
}


int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::optional<std::pair<int, int>> maybe_indices = findTwoSum(list, 10);

    if (maybe_indices) {
        const auto &indices = *maybe_indices;
        std::cout << indices.first << '\n' << indices.second;
    }
    else {
        std::cout << "not found\n";
    }
}
