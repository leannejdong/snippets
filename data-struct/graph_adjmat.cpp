#include <iostream>
#include <map>
#include <vector>

class Graph{
  public:
    Graph(std::vector<std::vector<int>> &adjacency): adjacency_(adjacency){}
    std::vector<std::vector<int>> adjacency_;
};

int main(){
    std::vector<std::vector<int>> adjacency{
     {0, 1, 1, 0, 0},
     {1, 0, 0, 1, 1},
     {1, 1, 0, 1, 0},
     {0, 1, 1, 0, 1},
     {0, 1, 0, 1, 0}
    };
      
    Graph g(adjacency);// graph calls the ctor and pass the adjacency matrix
}
// https://compiler-explorer.com/z/osTb4T6YE
