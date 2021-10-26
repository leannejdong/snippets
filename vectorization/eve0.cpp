//https://godbolt.org/z/8P1h6srjK
#include <eve/algo/equal.hpp>
#include <eve/function/sub.hpp>

#include <cstdint>
#include <string_view>

namespace ascii
{
  struct
  {
    EVE_FORCEINLINE auto operator()(eve::wide<std::uint8_t> c) const
    {
      constexpr std::uint8_t alphabet_length = 'z' - 'a';
      constexpr std::uint8_t a_A_offset      = 'a' - 'A';

      return eve::sub[(c - 'a') <= alphabet_length](c, a_A_offset);
    }

  } inline constexpr to_upper;

  bool iequals(std::string_view a, std::string_view b)
  {
    if ( a.size() != b.size() ) return false;

    // converting them to uint8_t; because our to upper algorithm relies on unsigned integers.
    auto *f1 = reinterpret_cast<std::uint8_t const *>(a.begin());
    auto *l1 = reinterpret_cast<std::uint8_t const *>(a.end());
    auto *f2 = reinterpret_cast<std::uint8_t const *>(b.begin());

    return eve::algo::equal(eve::algo::as_range(f1, l1), f2,
        [](eve::wide<std::uint8_t> a, eve::wide<std::uint8_t> b)
        {
          return to_upper(a) == to_upper(b);
        });
  }
}

/*
There are inrtinsics one should use:, like _mm_castps_si128.
Or bit_cat- like just memcpy from one register to another
C++ simd libraries give you:
a) portability: the popularity of SIMD everywhere tells me about how many people just wrote the intrinsics once but then didn't have the resources to port them. SIMDe is just not the best solution for a different architecture.
b) they can help you write loops. The amount of code I saw that doesn't align/unroll even though it should is completely unreasonable
c) they make writing code complexity under some threshold. This is, let's say, inclusive_scan over 2 parallel arrays, that does uses aligned accesses for the first array and unaligned for the second one: https://github.com/jfalcou/eve/blob/384a7712fd904043436c6a31504bad85f7d0e3cf/examp[…]sing_existing/inclusive_scan_zip__using_zip_with_algorithms.cpp

*/
