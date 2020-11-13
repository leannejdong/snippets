#include <iostream>
#include <vector>

using std::vector;

bool hasPairWithSum(const vector<int> &A, int sum)
{
  int N = A.size();
  for (int i=0; i!=N; ++i) {
    for (int j=i+1; j!=N; ++j) {
      if (A[i]+A[j] == sum) return true;
    }
  }
  return false;
}

int main()
{
    // array declaration
    vector<int> arr { 3, 5, 9, 2, 8, 10, 11, 23, 4, 1 };
     
    // value to search
    int sum = 21;
     
    // Function call
    printf("%d", hasPairWithSum(arr, sum));
 
    return 0;
}

/* For each pair of numbers, we need to see if any of them has the desired sum.
 * So, to go through each pair of numbers, one needs to go through each number,
 * and for each of those, one goes through all the other numbers.
 * The order of the two in the pair doesn't matter.
 * So one simply need to check A[2] + A[3], but one doesn't need to check A[3] + A[2]
 * So one can check all A[i]+A[j], where i < j.
 * So we go through each i, and then go through each j, where j is greater than i
 * So we start with j = i+1 and go up to N.*/
