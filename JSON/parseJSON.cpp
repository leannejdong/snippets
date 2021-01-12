#include <iostream>
//#include "https://raw.githubusercontent.com/nlohmann/json/v3.9.1/single_include/nlohmann/json.hpp"
#include <nlohmann/json.hpp>

using std::cerr;

int main()
{
    using nlohmann::json;

    const char *text = "[1,2,3]";
    auto j = json::parse(text);
    cerr << "j[0] = " << j[0] << "\n";
    cerr << "j[1] = " << j[1] << "\n";
}
//https://godbolt.org/z/bcq1Y1
