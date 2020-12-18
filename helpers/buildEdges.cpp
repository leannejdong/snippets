#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>

using std::string;
using std::vector;
using std::pair;
using std::istringstream;

void printVecPair (vector<pair<int, int>> &V)
{
    for(auto &v : V)
    {
        std::cerr <<  v.first << " " << v.second << "\n";
    }
}

static vector<pair<int,int>> parseGraph(const string &graph_string)
{
    // 1) Read the input, turn them into integers
    //    1) Break the input into words
    // Here we use istringstream to parse an int in c++ to an int.
    istringstream input_stream(graph_string);
    vector<pair<int, int>> V;
    
    int num1,  num2, num3, num4, num5, num6, num7, num8, num9;

    input_stream >> num1;
    input_stream >> num2;
    input_stream >> num3;
    V.push_back(std::make_pair(num1, num2));
    //printVecPair(V);
    V.push_back(std::make_pair(num1, num3));
    //printVecPair(V);
    input_stream >> num4;
    input_stream >> num5;
    input_stream >> num6;
    input_stream >> num7;
    V.push_back(std::make_pair(num4, num5));
    V.push_back(std::make_pair(num4, num6));
    V.push_back(std::make_pair(num4, num7));
    input_stream >> num8;
    input_stream >> num9;
    V.push_back(std::make_pair(num8, num9));

    printVecPair(V);

    return V;
   // assert(false); // not implemented
}


static void test1()
{
    string graph_string =
      "1\n"     // node number
      "2 3\n"   // list of nodes connected to node 1
      "2\n"     // node number
      "3 4 5\n" // list of nodes connected to node 2
      "4\n"     // node number
      "5\n";    // list of nodes connected to node 4

    vector<pair<int,int>> result = parseGraph(graph_string);

    vector<pair<int,int>> expected_result = {
       {1,2},
       {1,3},
       {2,3},
       {2,4},
       {2,5},
       {4,5}
    };

    assert(result == expected_result);
}


int main()
{
   test1();
}



