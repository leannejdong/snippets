#include <iostream>
#include <vector>
using namespace std;

constexpr int n = 10;

void print(vector<long long> &v)
{
    for (auto &s : v)
    {
        cout << s << "\n";
    }
} 
// DP approach
long long fib(int n, vector<long long> &dp)
{
    if(n == 1 || n == 2)
        return 1;
    if(dp[n] != 0) // Checking if Nth term is already computed or not
        return dp[n];
    return dp[n] = fib(n-1, dp)+fib(n-2, dp); // Storing the computed values
}
// iterative approach
void fib_iter(vector<long long> &F)
{
    F.resize(n);
    // F.push_back(0);
    // F.push_back(1);
    F[0]=0, F[1]=1;
    //print(F);

    //for (auto &f : F)
     for (int i = 2; i<n; ++i)
     {
         F[i]=F[i-1]+F[i-2];
     }
    print(F);
}
int main()
{
    vector<long long> dp(101); // Creating the array for storing computed values
    //cout << fib(n, dp);
    vector<long long > F1;
    //print(F1);
    fib_iter(F1);

}
