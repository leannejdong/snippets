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
    // 1) Read the input, turn them into integers
    //    1) Break the input into words
    // Here we use istringstream to parse an int in c++ to an int.

    std::istringstream split(graph_string);
    string each;
    vector<pair<int, int>> V;

    while (std::getline(split, each)) {
        vector<int> vec1 = StrToVecInts(each);
        std::getline(split, each);
        vector<int> vec2 = StrToVecInts(each);

        for (int x : vec2) {
            V.push_back(std::make_pair(vec1[0], x));
        }
    }

    return V;
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

   // assert(result == expected_result);
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

    vector<pair<int,int>> result = parseGraph(graph_string);

    vector<pair<int,int>> expected_result = {
       {1,2},
       {1,3},
       {1,4},
       {2,3},
       {2,4},
       {2,5},
       {4,5}
    };

    assert(result == expected_result);
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

    vector<pair<int,int>> result = parseGraph(graph_string);

    vector<pair<int,int>> expected_result = {
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

    assert(result == expected_result);
}


int main()
{
    test1();
    test2();
    test3();
}

