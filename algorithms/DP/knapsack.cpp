#include <iostream>
#include <vector>
#include <array>

using std::vector;
using std::array;
using std::cout;
using std::cin;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int knapSack(int W, vector<int> &w, vector<int> &v, int n)
{
    int i, wt;
    vector<vector<int> > K(n + 1, vector<int> (W+1));
    for (i = 0; i <= n; i++)
    {
        for (wt = 0; wt <= W; wt++)
        {
            if (i == 0 || wt == 0)
            K[i][wt] = 0;
            else if (w[i - 1] <= wt)
            {
                K[i][wt] = max(v[i-1] + K[i-1][wt - w[i-1]], K[i - 1][wt]);
            }
            else
            {
                K[i][wt] = K[i - 1][wt];
            }
        }
        
    }
    return K[n][W];
}

int main() {
   cout << "Enter the number of items in a Knapsack:";
   int n, W;
   cin >> n;
   //int v[n], w[n];

   vector<int> v(n); vector<int> w(n);
   for (int i = 0; i < n; i++) {
      cout << "Enter value and weight for item " << i << ":";
      cin >> v[i];
      cin >> w[i];
   }
   cout << "Enter the capacity of knapsack";
   cin >> W;
   cout << knapSack(W, w, v, n);
   return 0;
}

/* 0/1 Knapsack problem
Given a rucksack of capacity W, and N item with their weights and 
values, put these items in the rucksack, so that you get the maximum
total value in the rucksack and don't exceed its weight limit
dp[what you know] = what you don't know
- items with their weights and values     - the maximum value
- the weight of the rucksack

Here, we solve the 0-1 knapsack prpblem using DP.
In 0-1 knapsack problem, a set of items are given,
each with a weight and a value. We need to determine 
the number of each item to include in a collection so that the 
total weight is less than or equal to the given limit and the
total value is large as possible
*/


