#include <iostream>
#include <vector>
#include <range/v3/all.hpp>
#include <unordered_map>
#include <algorithm>
#include <iterator>

int main() {
    namespace rn = ranges;
    namespace vi = ranges::views;

    std::vector<int> numbers = {1, 5, 3, 4, 2, 6};
 //   std::vector<int> intermediate;

    // std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(intermediate),
    // [](int n) {return n % 2 == 0; });

    // std::transform(intermediate.begin(), intermediate.end(), intermediate.begin(),
    // std::bind(std::multiplies<int>{}, 2, std::placeholders::_1));

    auto result = numbers | vi::filter([](int n) {return n % 2 == 0; }) 
                          | vi::transform([](int n) {return n * 2; });

    for (int n : result)
    {
        std::cout << n << ' ';
    }

    return 0;

}

