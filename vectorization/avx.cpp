#include <immintrin.h>
#include <iostream>

using std::cout;

int main()
{
  //create two 256-bit argument (8 floats)
  //"ps": packed single precision (aka floats)
  __m256 evens = _mm256_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
  __m256 odds = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

  // Compute the difference between two vectors
  // Format: _mm<bit_width>_<name>_<data_type>
  __m256 result = _mm256_sub_ps(evens, odds);

  // Cast the result pointer to floats
  // float *f = (float *)&result;
  float *f = reinterpret_cast<float*>(&result);

  // Print the result
  std::cout << "Result: ";
  for(int i{0}; i < 8; ++i){
    std::cout << f[i] << "\n";
  }
  return 0;
}
//g++ -mavx -o avx avx.cpp
//objdump -d avx >out1.asm
