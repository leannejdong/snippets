#include <vector>
#include <iostream>

using std::cout;

class Graph {
 public:
 // take nodes and edges as input, then initialize them
  Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e)
      : v_(v), e_(e) {}

  std::vector<int> v_;
  std::vector<std::pair<int, int>> e_;
  void PrintGraph()
  {
     for (auto &nodes : v_)
     {
         cout << "nodes" << nodes << " make an edges with "<<"\n";
          for (auto &edges : e_)
          {
              if ((edges.first == nodes) || (edges.second == nodes))
              {
                cout << "Node: " << edges.first << " and " << edges.second << "\n";
              }
          }
    }
  }
};

int main() {
  std::vector<int> v = {0, 1, 2, 3};
  std::vector<std::pair<int, int>> e = {{1, 3}, {1, 3}, {3, 0}, {3, 0},
                                        {0, 2}, {2, 1}, {2, 3}};
  Graph g(v, e);
  g.PrintGraph();
}
