#include <vector>
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>

using std::vector;
using std::string;


static vector<int> readInts(const string &input_string)
{
    std::istringstream input_stream(input_string);
    string line;
    int number;
    vector<int> ans;
    if (!input_stream) {
        assert(false);
    }

    while (input_stream >> number)
    {
        ans.push_back(number);

    }
    for (auto &s : ans)
    {
        std::cout << s << "\n";
    }


    return ans;
    


  //  assert(false); // Not implemented
}


static void test1()
{
    string input_string = "7 9 8 5";
    vector<int> result = readInts(input_string);
    vector<int> expected_result = {7,9,8,5};
    assert(result == expected_result);
}


int main()
{
    test1();
}
