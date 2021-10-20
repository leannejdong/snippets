#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
#include <iomanip>

int main()
{
  std::vector<int> v(10000, 1);
  auto print = [](const auto&n) {std::cout << " " << n;};
  auto t1 = std::chrono::high_resolution_clock::now();
  std::atomic<int> sum{0};
  std::for_each(std::execution::par_unseq, v.begin(), v.end(), [&](auto&& item){sum +=item;});
  const auto t2 = std::chrono::high_resolution_clock::now();
  const std::chrono::duration<double, std::milli> ms = t2 - t1;
  std::cout << std::fixed << std::setprecision(1) << " result took: " << ms.count() << " ms\n";
  std::cout << std::fixed << std::setprecision(1) << " sum: " << sum << "\n";
}

//https://compiler-explorer.com/z/EsW6j9Er1
