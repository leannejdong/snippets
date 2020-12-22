#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using std::cerr;
using std::vector;
using std::pair;
using std::set;

template <typename T>
void printVec(T V)
{
    for (auto &v : V)
    {
        std::cerr << v << "\n";
    }
    std::cerr << "End of Print " << "\n";

}

static vector<int> findNeighbors(int node_id, const vector<pair<int,int>> &edges)
{
    vector<int> neighbors;
    for (auto u : edges)
    {
        if ((node_id  == u.first))
        {
            neighbors.push_back(u.second);
        } else if (node_id  == u.second) {
            neighbors.push_back(u.first);
        } else {
            cerr << "not a neighbor" << "\n";
        }
    }

    printVec(neighbors);
    return neighbors;
}



static void test1()
{
   vector<pair<int,int>> edges = {
       {1,2},
       {1,3},
       {1,4},
       {2,3},
       {2,5},
       {3,6},
   };

   int node_id = 3;
   vector<int> neighbors = findNeighbors(node_id, edges);
   set<int> neighbor_set(neighbors.begin(), neighbors.end());//order irrevalent when comparing two sets
   set<int> expected_neighbors = {1,2,6};
   assert(neighbor_set == expected_neighbors);
}

int main()
{
    test1();
}
