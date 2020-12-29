#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <stack>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <array>

using namespace std::ranges;
using std::string;
using std::vector;
using std::pair;
using std::istringstream;
using std::stack;
using std::make_pair;
using std::ranges::sort;
using std::array;
constexpr int N = 100;

void printVecPair (vector<pair<int, int>> &V)
{
    for(auto &v : V)
    {
        std::cerr <<  v.first << " " << v.second << "\n";
    }
    std::cerr << "End of Print " << "\n";

}


template <typename T>
void printVec(T V)
{
    for (auto &v : V)
    {
        std::cerr << v << "\n";
    }
    std::cerr << "End of Print " << "\n";

}

static vector<int> StrToVecInts(const string &graph_string)
{
    vector<int> vecInts;
    istringstream input_stream(graph_string);
    int number;
    while(input_stream >> number) {
        vecInts.push_back(number);
    }
    return vecInts;
}

static vector<pair<int,int>> parseGraph(const string &graph_string)
{
    std::istringstream split(graph_string);
    string each;
    vector<pair<int, int>> V;

    while (std::getline(split, each)) {
        vector<int> vec1 = StrToVecInts(each);
        std::getline(split, each);
        vector<int> vec2 = StrToVecInts(each);

        for (int x : vec2) {
            V.push_back(make_pair(vec1[0], x));
        }
    }

    return V;
}

struct Graph {
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
            neighbors.push_back(u.first);
         } 
    }
    return neighbors;
}
void printCycles(int v, int u, vector<int> &par)
{
    std::cerr << "Found cycle" << "\n";
    while(u != v)
    {
        std::cerr << u << " -> " << " ";
        u = par[u];
    }
    std::cerr << v << "\n";
}
bool dfs_cycle(int u, vector<int> &color, vector<int> &par)
{
     vector<int> neighbors;
    neighbors = findNeighbors(u, e_);
    color[u] = 1;
    for (auto v : neighbors)
    {
        if (color[v] == 0)
        {
            par[v] = u;
            dfs_cycle(v, color, par);
        } else if (color[v] == 1 && v != par[u]) {
            printCycles(v, u, par);
            break;
        }
    }
    color[u] = 2;
    return false;
}

};
static void test3()
{
    string graph_string =
      "1\n"     // node number
      "2 3 4\n"   // list of nodes connected to node 1
      "2\n"     // node number
      "3 4 5\n" // list of nodes connected to node 2
      "4\n"     // node number
      "5\n"
      "5\n"     // node number
      "6 7\n"
      ;
    

    vector<pair<int,int>> e = parseGraph(graph_string);
    vector<int> v;
#if 1   // via std::transform, copy a vec-pair to vec
    std::transform(begin(e), end(e), std::back_inserter(v),
    [&v](const std::pair<int, int> &pair)
    {v.push_back(pair.first);
     return pair.second ;});
#else   
    for (auto p : e) { // loop over all pairs and add both node_ids to a single vec
        v.push_back(p.first);
        v.push_back(p.second);
    }
#endif
     sort(v);
     auto last = std::unique(begin(v), end(v));
     v.erase(last, v.end());
  //   printVec(v);

    vector<pair<int,int>> expected_e = {
       {1,2},
       {1,3},
       {1,4},
       {2,3},
       {2,4},
       {2,5},
       {4,5},
       {5,6},
       {5,7}
    };
    vector<int> expected_v = { 1, 2, 3, 4, 5, 6, 7 };
    printVecPair(e);
    assert(e == expected_e);

    Graph g(v, e);
    vector<int> color(N);
    vector<int> par(N);

    g.dfs_cycle(1, color, par);
}


int main()
{
    test3();
}

