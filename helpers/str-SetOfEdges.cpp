#include <string>
#include <sstream>
#include <set>
#include <cassert>
#include <vector>
#include <iostream>

using std::string;
using std::set;
using std::pair;
using std::vector;
using std::getline;
using std::istringstream;


// graph_string contains lines showing edges in a graph.
// Each line has two integers indicating two node IDs.
// This function should return the graph as a set of edges, where each
// each is pair of node IDs.
static set<pair<int,int>> parseGraph(const string &graph_string)
{
    std::istringstream input_stream(graph_string);
    vector<int> nodes;
    int node_P, node_Q;
    set<pair<int, int>> S;
    if (!input_stream) {
        assert(false);
    }
    std::cout << "Before first while loop\n";

    std::cout << "Before second while loop\n";
    //std::cout << "Calling getline: " << bool(getline(input_stream, str_line)) << "\n";
    //while(getline(input_stream, str_line))
    while(input_stream >> node_P >> node_Q)
    {
        std::cout << "Inside second while loop\n";

        S.insert(std::make_pair(node_P,node_Q));

        for (auto &s : S)
        {
            std::cout << s.first << " " << s.second << "\n";
        }

    }
    std::cout << "After second while loop\n";
    for (auto &s : S)
    {
        std::cout << s.first << " " << s.second << "\n";
    }
    return S;
   // assert(false); // not implemented
}

static void test1()
{
    string graph_string =
      "0 1\n"
      "1 2\n"
      "1 4\n";

    set<pair<int,int>> result = parseGraph(graph_string);
    set<pair<int,int>> expected_result = {{0,1},{1,2},{1,4}};
    assert(result == expected_result);
}

int main()
{

    test1();

}
