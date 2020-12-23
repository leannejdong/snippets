#include <iostream>
#include <vector>
#include <range/v3/all.hpp>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <memory>

struct Foo
{
    Foo(int a, int b) : a{a}, b{b} {}
    int a;
    int b;
};
int main() {
    namespace rn = ranges;
    namespace vi = ranges::views;

    std::vector<int> numbers = {1, 5, 3, 4, 2, 6};

    auto v1 = vi::ints | vi::take(10)
        | vi::transform([](int n) {return std::make_unique<Foo>(n*2, n*5); })
        | rn::to_vector;
    auto v2 = vi::ints | vi::take(14)
        | vi::transform([](int n) {return std::make_unique<Foo>(n*6, n*9); })
        | rn::to_vector;
    
    auto odd = [](int n) {return n % 2 == 0;};
    auto processing = vi::indirect | vi::transform(std::mem_fn(&Foo::b)) | vi::take_last(6) | vi::filter(odd);
    auto range1 = v1 | processing;
    auto range2 = v2 | processing;
//    // std::cout << rn::accumulate(v | vi::indirect, 0) << "\n";

//     auto& result = v;

    for ( auto [n1, n2] : vi::zip(range1, range2) )
    {
        std::cout << n1 << " : " << n2 << ' ';
    }
    return 0;

}

