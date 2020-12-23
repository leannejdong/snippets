#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

int main() {

    std::vector<int> numbers = {1, 5, 3, 4, 2, 6};
    std::vector<int> intermediate;

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(intermediate),
    [](int n) {return n % 2 == 0; });

    std::transform(intermediate.begin(), intermediate.end(), intermediate.begin(),
    [](int x){ return x*2; });

    auto& result = intermediate;

    for (int n : result)
    {
        std::cout << n << ' ';
    }

    return 0;

}

