#include <algorithm>
#include <cassert>
#include <iostream>
#include <ranges>
#include <span>
#include <type_traits>
#include <vector>

#include "fmt/format.h"

using Tensor = std::vector<std::vector<std::vector<std::vector<double>>>>;
using Matrix = std::vector<std::vector<double>>;
Tensor KroneckersOuterProduct(Matrix m1, Matrix m2) {
  // Matrix m(m1.size() * m2.size(), std::vector<double>(m1[0].size() *
  // m2[0].size()));
  Tensor result;
  int n1 = 3;
  int n2 = 2;
  int n3 = 2;
  int n4 = 3;
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

template <typename T>
concept Arithmetic = std::floating_point<T> || std::integral<T>;

template <Arithmetic T>
inline void nested_print(std::span<T> vector) {
  fmt::print("[{}]", fmt::join(vector.begin(), vector.end(), ", "));
}

template <typename T>
inline void nested_print(std::span<T> tensor) requires(!Arithmetic<T>) {
  fmt::print("[");
  for (std::span curr_tensor : tensor) {
    nested_print(curr_tensor);
    fmt::print("\n");
  }
  fmt::print("\n]");
}

int main() {
  Matrix m1{{1, 2}, {3, 4}, {1, 0}};
  Matrix m2{{0, 5, 2}, {6, 7, 3}};

  Tensor m(KroneckersOuterProduct(m1, m2));

  std::cout << "want to print the outer product as block matrix "
            << "\n";

  nested_print(std::span(m));

  return 0;
}

// concepts and span is due to Basit

