#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <stack>
#include <ranges>
#include <range/v3/all.hpp>
#include <algorithm>
#include <numeric>
#include <iterator>

using std::string;
using std::vector;
using std::pair;
using std::istringstream;
using std::stack;
using std::make_pair;
using std::ranges::sort;

//namespace rn = std::ranges;
namespace vi = ranges::views;
namespace actions = ranges::actions;
//namespace to = ranges::_to_::to;

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
    //printVec(vecInts);
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


static void test1()
{
    string graph_string =
      "1\n"     // node number
      "2 3\n"   // list of nodes connected to node 1
      "2\n"     // node number
      "3 4 5\n" // list of nodes connected to node 2
      "4\n"     // node number
      "5\n";    // list of nodes connected to node 4

    vector<pair<int,int>> e = parseGraph(graph_string);

    vector<pair<int,int>> expected_e = {
       {1,2},
       {1,3},
       {2,3},
       {2,4},
       {2,5},
       {4,5}
    };

    assert(e == expected_e);
}

static void test2()
{
    string graph_string =
      "1\n"     // node number
      "2 3 4\n"   // list of nodes connected to node 1
      "2\n"     // node number
      "3 4 5\n" // list of nodes connected to node 2
      "4\n"     // node number
      "5\n";    // list of nodes connected to node 4

    vector<pair<int,int>> e = parseGraph(graph_string);

    vector<pair<int,int>> expected_e = {
       {1,2},
       {1,3},
       {1,4},
       {2,3},
       {2,4},
       {2,5},
       {4,5}
    };

    assert(e == expected_e);
}


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
     //const auto v0 = vi::concat(e|vi::keys, e|vi::values);
     const auto v = vi::concat(e|vi::keys, e|vi::values)
     |ranges::to<std::vector<int>>()|actions::sort|actions::unique;
    //  sort(v0);
    //  auto last = std::unique(begin(v0), end(v0));

    //  const auto v = rn::subrange(begin(v0),last);
     printVec(v);

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
    vector<int> expected_v = {1, 2, 3, 4, 5, 6, 7};
    //printVec(v);

    assert(v == expected_v);
}


int main()
{
    test1();
    test2();
    test3();
}

//-fconcepts -std=c++2a 
