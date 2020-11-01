#include <vector>
#include <iostream>
using std::vector;

class solution {
    public:

    void print(vector<int> & vec)
    {
        for(auto &v : vec)
        {
            std::cerr << v << " \n";
        }
    }
    int count(vector<int> &S, int m, int n ) 
    { 
        vector<int> dp(m+1);
        // If n is 0 then there is 1 solution  
        // (do not include any coin) 
        if (n == 0) 
            return 1; 
        
        // If n is less than 0 then no  
        // solution exists 
        if (n < 0) 
            return 0; 
    
        // If there are no coins and n  
        // is greater than 0, then no 
        // solution exist 
        if (m <=0 && n >= 1) 
            return 0; 
    
        // count is sum of solutions (i)  
        // including S[m-1] (ii) excluding S[m-1] 
       // std::cerr << "dp.size()=" << dp.size() <<"\n";
        return dp[m] = count( S, m - 1, n ) + count( S, m, n-S[m-1]); 
    } 

};

  
// Driver program to test above function 
int main() 
{ 
    solution ways;
    vector<int> arr {1, 2, 3}; 
    int m = arr.size()/arr.front(); 
 //   std::cout << m << " \n";
    std::cout << ways.count(arr, m, 4); 
    return 0; 
} 
