#include <cassert>
#include <iostream>
#include <vector>
#include <fmt/format.h>

// without span

using Tensor = std::vector<std::vector<std::vector<std::vector<double>>>>;
using Matrix = std::vector<std::vector<double>>;
Tensor KroneckersOuterProduct(Matrix m1, Matrix m2) {
  Tensor result;
  auto n1 = m1.size();
  auto n2 = m1[0].size();
  auto n3 = m2.size();
  auto n4 = m2[0].size();
  result.resize(n1);
  for (auto& v2 : result) {
    v2.resize(n2);
    for (auto& v3 : v2) {
      v3.resize(n3);
      for (auto& v4 : v3) {
        v4.resize(n4);
      }
    }
  }
  for (std::size_t z1(0); z1 < m1.size(); ++z1) {
    for (std::size_t z2(0); z2 < m1[0].size(); ++z2) {
      for (std::size_t z3(0); z3 < m2.size(); ++z3) {
        for (std::size_t z4(0); z4 < m2[0].size(); ++z4) {
          result[z1][z2][z3][z4] = m1[z1][z2] * m2[z3][z4];
        }
      }
    }
  }
  return result;
}


inline void nested_print(const std::vector<double> & vector) {
  fmt::print("[{}]", fmt::join(vector.begin(), vector.end(), ", "));
}

template <typename T>
inline void nested_print(const T & tensor)
{
  fmt::print("[");
  for (auto &curr_tensor : tensor) {
    nested_print(curr_tensor);
    fmt::print("]\n");
  }
  fmt::print("");
}

int main() {
  Matrix m1{{1, 2, 3}, {4, 5, 6}};
  Matrix m2{{7, 8}, {9, 10}, {11, 12}};

  Tensor m(KroneckersOuterProduct(m1, m2));

  std::cout << "want to print the outer product as block matrix "
            << "\n";

  nested_print(m);

  return 0;
}

