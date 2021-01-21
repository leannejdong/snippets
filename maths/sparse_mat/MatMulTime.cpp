/*
 *@leanne.dong@concordia.ca
 * Performance benchmark 
 * - naive matrix multiplication vs sparse matrix multiplication
 * - print via fmt vs ostream
*/

#include <cassert>
#include <iostream>
#include <vector>
#include <fmt/format.h>

#include <chrono>
#include <cassert>

using std::cerr;
struct Timer
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        float s = duration.count();
      //  std::cerr << "Timer took in ms " << ms << "ms" << "\n";
        std::cerr << "Timer took in s " << s << "s" << "\n";

    }
};
using Matrix = std::vector<std::vector<double>>;
Matrix MatMultiply(const Matrix &m1, const Matrix &m2) {
// Matrix result(m1.size() * m2.size(), std::vector<double>(m1[0].size() *
//   m2[0].size()));
  Matrix result;
  auto n1 = m1.size();
  auto n2 = m2[0].size();
  result.resize(n1);
  for (auto& v2 : result) {
    v2.resize(n2);
  }
  for (std::size_t row(0); row < result.size(); ++row) {
      for (std::size_t col(0); col < result[0].size(); ++col) {
          for (std::size_t inner = 0; inner < m2.size(); ++inner) {
              result[row][col] += m1[row][inner] * m2[inner][col];
          }
      }
  }

  return result;
}

Matrix SparseMul(const Matrix &m1, const Matrix &m2) {
    Matrix result;
    auto n1 = m1.size();
    auto n2 = m1[0].size();
    auto n3 = m2[0].size();
    result.resize(n1);
    for (auto& v2 : result) {
        v2.resize(n3);
    }
    for (std::size_t row(0); row < n1; ++row) {
        for (std::size_t col(0); col < n2; ++col) {
            if (m1[row][col] == 0) {
                continue;
            }
            for (std::size_t inner = 0; inner < n3; ++inner) {
                result[row][inner] += m1[row][col] * m2[col][inner];
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
    fmt::print("\n");
  }
  fmt::print("\n]");
}

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<double>> & container/*(M, std::vector<Value> (N))*/)
{
    for (const std::vector<double> &row : container)
    {
        for (const double &col : row)
        {
            os << col << " ";
        }
        os << "\n";
    }
    return os;
}

int main() {
  Matrix m1{{1, 2, 3}, {4, 5, 6}};
  Matrix m2{{7, 8}, {9, 10}, {11, 12}};
  std::cerr << "Measure time taken for naive Matrix multiplication: " << "\n";
  Timer t;
  Matrix m(MatMultiply(m1, m2));
  std::cerr << "Measure time taken for printing naive Matrix multiplication (fmt): " << "\n";
  Timer tt;
  nested_print(m);
  std::cerr << "Measure time taken for sparse Matrix multiplication: " << "\n";
  Timer t1;
  Matrix sm(SparseMul(m1, m2));
  std::cerr << "Measure time taken for printing sparse Matrix multiplication (fmt): " << "\n";
  Timer tt1;
  nested_print(sm);
  std::cerr << "Measure time taken for printing sparse Matrix multiplication (ostream): " << "\n";
  Timer tt2;
  std::cout << sm;

  return 0;
}

// https://quick-bench.com/q/P_eYUNSwF1h7IicwQJdsFcBZ5DI

