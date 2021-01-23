/*
 *@leanne.dong@concordia.ca
 * Performance benchmark 
 * - naive matrix multiplication vs sparse matrix multiplication
 * - print via fmt vs ostream
*/

#include <cassert>
#include <iostream>
#include <vector>
//#include <fmt/format.h>
#include <thread>

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

      //  float ms = duration.count() * 1000.0f;
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

Matrix MatMultiplyP(const Matrix &m1, const Matrix &m2) {
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
          for (std::size_t inner = 0; inner < m1[0].size(); ++inner) {
              //result += m1[row*m1[0].size()+inner]*m2[inner*result[0].size()+col]
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

// inline void nested_print(const std::vector<double> & vector) {
//   fmt::print("[{}]", fmt::join(vector.begin(), vector.end(), ", "));
// }

// template <typename T>
// inline void nested_print(const T & tensor)
// {
//   fmt::print("[");
//   for (auto &curr_tensor : tensor) {
//     nested_print(curr_tensor);
//     fmt::print("\n");
//   }
//   fmt::print("\n]");
// }

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
  Matrix m;
  Timer t;
  std::thread t1([&](){std::cerr << "thread function\n";                                                                                                                                                          
      m = MatMultiply(m1, m2);                                                                                                                                                                                     
      });
  t1.join();
  std::cout << m;
  return 0;
}

/*
 * One might use a lambda, but it doesn't have to be.
 * Here is another way https://godbolt.org/z/34T5EM
 * the return value of the thread function is ignored
 * but we can work around that by calling another function inside the thread function
 * https://godbolt.org/z/q9qrhK
 * so let's say the function that we want to be executed in a thread is g
 * we create another function f, which calls g, and passes the result back through the pointer
 * A lambda is an alternate way to create such a function: https://godbolt.org/z/95E6z1
 * and lambdas allow captures, which makes this a little more direct: https://godbolt.org/z/qKqjnT
 */
