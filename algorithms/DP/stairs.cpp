#include <unordered_map>
#include <iostream>

using std::unordered_map;

struct Solution {
    unordered_map<int,int> cache;
    int climbStairs(int n) {
         if(cache.find(n)!=cache.end()) return cache[n];
         int result = 0;
         if (n == 0) result = 0;
         else if (n == 1) result= 1; 
         else if (n == 2) result = 2; 
         else result = climbStairs(n-1) + climbStairs(n-2); 
         
         cache[n]=result; // stored imtermediate result
         return result;
    }
};

int main()
{
    Solution soln1;
    std::cout << soln1.climbStairs(8) << " \n";
}
