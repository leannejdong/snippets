#include <iostream>
#include <vector>
#include <range/v3/all.hpp>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <memory>

struct Foo
{
    Foo(int a, int b) : a(a), b(b) {}
    int a;
    int b;
};
int main() {
    namespace rn = ranges;
    namespace vi = ranges::views;

    std::vector<int> numbers = {1, 5, 3, 4, 2, 6};

    auto v = vi::ints | vi::take(10)
        | vi::transform([](int n) {return std::make_unique<Foo>(n*6, n*9); })
        | rn::to_vector;
    
    auto odd = [](int n) {return n % 2 == 0;};
    auto range = v | vi::indirect | vi::transform(std::mem_fn(&Foo::b)) | vi::take_last(6) | vi::filter(odd);

   // std::cout << rn::accumulate(v | vi::indirect, 0) << "\n";

    auto& result = v;

    for ( auto [i, n] : range | vi::enumerate )
    {
        std::cout << i << " : " << n << ' ';
    }
    return 0;

}

