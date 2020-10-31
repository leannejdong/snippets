#include <vector>
#include <iostream>

using namespace std;

class solution {
  public:
    int change(int amount, vector<int>& coins){
      vector <int> dp (amount +1);
      dp[0] = 1;
      int n = coins.size();
      for (int i = 0; i < n; i++)
      {
        for (int j = coins[i]; j <= amount; j++)
        {
          dp[j] += dp[j - coins[i]];
        }
      }
      return dp[amount];
    }
};

int main()
{
  solution ways;
  vector<int> v = { 1, 1, 5};
  cout << (ways.change(5, v)) << " \n";
}
