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

static vector<string> strTotoken(const string &graph_string)
{
    std::string str(graph_string);
    char split_char = '\n';

    std::istringstream split(str);
    std::vector<string> tokens;
    for (string each; std::getline(split, each, split_char);
     tokens.push_back(each));

    // for (auto &s : tokens)
    // {
    //     std::cout << s << "\t";
    // }
    return tokens;
}
static vector<pair<int, int>> makePair(vector<int> & vecA, vector<int> &vecB, vector<pair<int, int>>& V)
{
    for (size_t i = 0; i < vecB.size(); ++i)
    {
        V.push_back(std::make_pair(vecA[0], vecB[i]));
    }

    // for(auto &v : V)
    // {
    //     std::cerr <<  v.first << " " << v.second << "\n";
    // }

    return V;
}
static vector<pair<int,int>> parseGraph(const string &graph_string)
{
    vector<string> Tokens = strTotoken(graph_string);

    // 1) Read the input, turn them into integers
    //    1) Break the input into words
    // Here we use istringstream to parse an int in c++ to an int.
    istringstream input_stream(graph_string);
    vector<pair<int, int>> V;
    
     vector<int> vec0 = StrToVecInts(Tokens[0]);
     vector<int> vec1 = StrToVecInts(Tokens[1]);
     vector<int> vec2 = StrToVecInts(Tokens[2]);
     vector<int> vec3 = StrToVecInts(Tokens[3]);
     vector<int> vec4 = StrToVecInts(Tokens[4]);
     vector<int> vec5 = StrToVecInts(Tokens[5]);

  //  std::cerr << "start matching pairs" << "\n";
    makePair(vec0, vec1, V);
    // std::cerr << "start matching pairs" << "\n";
    // for (size_t i = 0; i < vec3.size(); ++i)
    // {
    //     V.push_back(std::make_pair(vec2[0], vec3[i]));
    // }
    makePair(vec2, vec3, V);
   // printVecPair(V);
   // std::cerr << "start matching pairs" << "\n";
    // for (size_t i = 0; i < vec5.size(); ++i)
    // {
    //     V.push_back(std::make_pair(vec4[0], vec5[i]));
    // }
    makePair(vec4, vec5, V);
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


int main()
{
   test1();
   test2();
}

