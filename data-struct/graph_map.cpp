#include <iostream>
#include <map>
//#include <vector>
#include <set>

class Graph{
  public:
    Graph(std::map<int, std::set<int>> &v): v_(v){}
    std::map<int, std::set<int>> v_;
};

int main(){
    std::map<int, std::set<int>> v{
        {0, {1, 2}}, 
        {1, {0, 2, 3, 4}},
        {2, {0, 1, 3}},
        {3, {1, 2, 4}}
    };
      
    Graph g(v);
}
// can be done equivalently with vector instead of set

