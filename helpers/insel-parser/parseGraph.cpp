#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <iostream>

using std::string;
using std::vector;
using std::pair;


static vector<pair<int,int>> parseGraph(const string &graph_string)
{
    std::istringstream input_stream(graph_string);
    string line;
    vector<pair<int, int>> V;
    if (!input_stream) {
        assert(false);
    }

    while (getline(input_stream, line))
    {
        std::istringstream line_stream(line);

        int x, y, z;
        if(isdigit(line_stream.peek())) {
            line_stream >> x;

            line_stream >> y;
            if (!line_stream) {
                // failed to read y
                std::cerr << "The first number is " << x << "\n";
            } else {
                // succesfully read y
                line_stream >> z;
            }
        }
    }

    return V;

}


static void test1()
{
    string graph_string =
      "1\n"     // blk number
      "2 3\n"   // list of blks connected to node 1
      "2\n"     // node number
      "3 4 5\n" // list of blks connected to node 2
      "4\n"     // node number
      "5\n";    // list of blks connected to node 4

    vector<pair<int,int>> result = parseGraph(graph_string);

    vector<pair<int,int>> expected_result = {
       {1,2},
       {1,3},
       {2,3},
       {2,4},
       {2,5},
       {4,5}
    };

    //assert(result == expected_result);
}


int main()
{
   test1();
}
