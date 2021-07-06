#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <array>
using std::cin;
using std::vector;
using std::make_pair;
constexpr int MAX = 1e4 + 5;
using PII = std::pair<long long, int>;
std::array<bool, MAX> marked;
vector<PII> adj[MAX];

auto prim_MST(int x)
{
    std::priority_queue<PII, vector<PII>, std::greater<PII>> Q;
    int y;
    long long minCost = 0;
    PII p;
    Q.push(std::make_pair(0, x));
    while(!Q.empty()){
        // select the edge with min. weight
        p = Q.top();
        Q.pop(); //rm the 1st edge from the priority queue
        x = p.second;
        // check for cycle
        if(marked[x] == true){
            continue;
        }
        minCost += p.first;
        marked[x] = true;
        for(size_t i{0}; i < adj[x].size(); ++i){
            y = adj[x][i].second;
            if(marked[y] == false){
                Q.push(adj[x][i]);
            }
        }
    }
    return minCost;
}

int main()
{
  int nodes, edges, x, y;
  long long weight, minCost;
  cin >> nodes >> edges;
  for(int i = 0; i < edges; ++i)
  {
    cin >> x >> y >> weight;
    adj[x].push_back(make_pair(weight, y));
    adj[y].push_back(make_pair(weight, x));
  }
  // selecting 1 as the starting node
  minCost = prim_MST(1);
  std::cerr << minCost << "\n";
  return 0;
}
