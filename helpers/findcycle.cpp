#include <algorithm>
#include <memory>
#include <vector>
#include <stack>
#include <cassert>
#include <iostream>

using std::unique_ptr;
using std::vector;
using std::pair;
using std::stack;
using std::make_pair;
using std::cerr;


template <typename T>
void printVec(T V)
{
    for (auto &v : V)
    {
        std::cerr << v << "\n";
    }
    std::cerr << "End of Print " << "\n";

}
class Graph {
 public:
  Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e)
      : v_(v), e_(e) {}
  void PrintGraph();
  std::vector<int> v_;
  std::vector<std::pair<int, int>> e_;

static vector<int> findNeighbors(int node_id, const vector<pair<int,int>> &edges)
{
    vector<int> neighbors;
    for (auto u : edges)
    {
        if ((node_id  == u.first))
        {
            neighbors.push_back(u.second);
        } else if (node_id  == u.second) {
            neighbors.push_back(u.first);}
        // } else {
        //     cerr << "not a neighbor" << "\n";
        // }
    }

    return neighbors;
}

bool hascycle_iter (int start, vector<bool>& visited)
{
    stack <pair<int, int> > S;
    S.push(make_pair(start, -1));
    visited[start] = true;

    while (!S.empty())
    {
        int v = S.top().first;
        int f = S.top().second;
        S.pop();
        vector<int> neighbors;
        neighbors = findNeighbors(start, e_);
        for (auto w : neighbors)
        {
           // printVec(neighbors);

            if (!visited[w])
            {
                S.push(make_pair(w, v));
                visited[w] = true;
            } else if (w != f) return true;

            // for (auto node : visited) {
            //     std::cout << node << "\n";
            // }
        }
    }
    return false;
 
}

bool hascycle()
{
    vector<bool> visited(v_.size(), false);
    for (size_t i = 0; i < v_.size(); ++i)
    {
        if(!visited[i] && hascycle_iter(i, visited)) return true;
    }
    return false;
}



};

int main() {
   std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7};
   std::vector<std::pair<int, int>> e = {{1, 2}, {1, 3}, {1, 4}, {2, 3},
                                         {2, 4}, {2, 5}, {4, 5}, {5, 6}, {5, 7}};
   Graph g(v, e);
   bool res;
   res = g.hascycle();
   std::cout << res << "\n";
   if(res) std::cerr << " has cycle " << "\n";
   else std::cerr << " no cycle " << "\n";
}
