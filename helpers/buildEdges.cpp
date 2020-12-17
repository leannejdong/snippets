#include <cassert>
#include <string>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::pair;


static vector<pair<int,int>> buildEdges(int node, const vector<int> &connected_nodes)
{
    vector<pair<int, int>> V;
    for (auto &v : connected_nodes)
    {
        V.push_back(std::make_pair(node, v));

    }
    return V;
   // assert(false); // not implemented
}


static void test1()
{
    int node = 1;
    vector<int> connected_nodes = {2,3};
    vector<pair<int,int>> result = buildEdges(node, connected_nodes);

    vector<pair<int,int>> expected_result = {
       {1,2},
       {1,3},
    };

    assert(result == expected_result);
}


int main()
{
   test1();
}
