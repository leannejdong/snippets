
#include <iostream>
#include <vector>
using std::cout;
using std::vector;
int main()
{
  // Normal arrays packed with even and odd floating point numbers
  vector<float> evens{2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0};
  vector<float> odds{1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0};

  // Output vector
  vector<float> result;
  // Do the subtraction
  for(int i{0}; i < 8; ++i)
  {
    result[i] = evens[i] - odds[i];
  }

  // Print the result
  std::cout << "Result: ";
  for(int i{0}; i < 8; ++i){
    std::cout << result[i] << "\n";
  }
  return 0;
}
