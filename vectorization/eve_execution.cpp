#include <cstdint>

#include <eve/algo/as_range.hpp>
#include <eve/algo/transform.hpp>

#include <algorithm>
#include <execution>
constexpr std::uint32_t bits_per_block = 20;

void clean(std::uint32_t * const blocks, 
  unsigned int number_of_blocks, unsigned int offset) {
    if (offset == 0) { return; }

    std::uint32_t mask = ~((std::uint32_t)(0)) >> 20 - offset;

    eve::algo::as_range r(blocks, blocks + number_of_blocks);

    std::transform(r.begin(), r.end(), r.begin(), [&](auto cur) {
      return cur & mask;
    });

}

// A plain std::transform seems to give the same result.
void clean2(std::uint32_t * const blocks, 
  unsigned int number_of_blocks, unsigned int offset) {
    if (offset == 0) { return; }

    std::uint32_t mask = ~((std::uint32_t)(0)) >> 20 - offset;
    // The std::execution::unseq is the C++20 version of std::execution::par_unseq
    // and execute algorithm in parallel with vectorization
    // https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t
    // http://www.mycpu.org/stdpar-c++/
    std::transform(/*std::execution::unseq,*/ blocks, blocks + number_of_blocks, blocks, [&](auto cur){
        return cur & mask;
    });

}
// https://godbolt.org/z/n58nsjd8b
