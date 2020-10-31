//subset Sum
// You are given N numbers. Check if there is a subset of them,
// with the sum equal to target value S. 
// N <= 20
// You cannot take an element more than once,
// iterating over all subsets of some set of numbers can be 
// done with recursion. But let's focus on iterative version,

// for i in 30..0
//   if (x & (1 << i)) != 0
//     print(1)
//   else
//     print(0)

#include <cstdio>
#include <iostream>
#include <vector>

void bitmask(int n)
{
    int S = 30;  std::vector<int> a{1, 3, 4, 5, 5, 8, 3, 2, 1, 2};
    for(int mask = 0; mask < (1 << n); mask++)
    {
        long long sum_of_this_subset = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i)) // test if bit 'i' is turned on in subset 'mask'? 
            {
                sum_of_this_subset += a[i];
            }
        }
        if (sum_of_this_subset == S)
        {
            puts("YES");
            std::cout  << sum_of_this_subset << " \n";
        }
    }
    puts("No");
}

int main()
{
    bitmask(10);
}

// This bitmap example was saying that the subset of some set of numbers from 1 to 30 
// can be represented as binary number of length 30...and so this is more efficient than std::vector

