/* How do I know my codes can be vectorized or not?
 *
 * Recall, "assembling" in that context means converting assembly language to machine code.
 * "disassembling" means converting machine code into assembly language
 * Start with disassembling on godbolt function by function
 * If a function looks like std:: transform or std::transform_reduce, it should be autovectorised
 */

#include <cstdint>

#include <eve/algo/as_range.hpp>
#include <eve/algo/transform.hpp>

#include <algorithm>

constexpr std::uint32_t bits_per_block = 20;

void clean(std::uint32_t * const blocks, unsigned int number_of_blocks, unsigned int offset) {
    if (offset == 0) { return; }

    std::uint32_t mask = ~((std::uint32_t)(0)) >> 20 - offset;

    eve::algo::as_range r(blocks, blocks + number_of_blocks);

    std::transform(r.begin(), r.end(), r.begin(), [&](auto cur) {
      return cur & mask;
    });

}
//https://godbolt.org/z/r83ojYTfx
