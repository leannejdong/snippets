#include <cstdint>

#include <eve/algo/as_range.hpp>
#include <eve/algo/mismatch.hpp>

#include <algorithm>

constexpr std::uint32_t bits_per_block = 20;

struct clean_u32
{
  std::uint32_t mask;
  clean_u32(std::uint32_t bits_per_block, std::uint32_t offset):
    mask{ ~((std::uint32_t)(0)) >> 20 - offset}
  {
  } 

  auto operator()(eve::like<std::uint32_t> auto u32) const
  {
    return u32 & mask;
  }
};

int compare_simd(std::uint32_t const* left, std::uint32_t const* right, 
                           unsigned int size)
{
  clean_u32 clean(20, 5);

  auto [left_res, right_res] = eve::algo::mismatch(
    eve::algo::as_range(left, left + size), right, [&](auto l, auto r) {
      return clean(l) == clean(r);
  });

  if (left_res == (left + size)) return 0;

  return *left_res - *right_res;
}

int compare_scalar(std::uint32_t const* left, std::uint32_t const* right, 
                           unsigned int size)
{
  clean_u32 clean(20, 5);

  auto [left_res, right_res] = std::mismatch(left, left + size, right, 
  [&](auto l, auto r) {
      return clean(l) == clean(r);
  });

  if (left_res == (left + size)) return 0;

  return *left_res - *right_res;
}
//https://godbolt.org/z/TrYrn479n
