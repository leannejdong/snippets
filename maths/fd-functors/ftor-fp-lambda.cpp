#include <algorithm>
#include <iostream>
#include <vector>

// Functor

struct add_x
{
  int x;
  add_x(int y): x(y){}
  int operator()(int y)
  {
    return x+y;
  }
};

// Function pointer
int (func)(int x)
{
  return ++x;
}

void print(const std::vector<int>& vec)
{
  for(const auto&v : vec){
    std::cerr << v << ",";
  }
  std::cerr << "\n";
}

int main()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  // fill vec with 12345
  int (*f)(int) = func; // Function pointer
//  std::transform(vec.begin(), vec.end(), f);
  std::transform(vec.begin(), vec.end(), vec.begin(), add_x(1));
  print(vec);

  auto lambda = [&](int x){ return ++x;};
  std::transform(vec.begin(), vec.end(), vec.begin(), lambda);
  print(vec);
 int to_add = 5;
 std::transform(vec.begin(), vec.end(), vec.begin(), add_x(to_add));
 print(vec);

}
