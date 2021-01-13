#include <iostream>
#include <string>
//#include "https://raw.githubusercontent.com/nlohmann/json/v3.9.1/single_include/nlohmann/json.hpp"
#include <json.hpp>

using std::cerr;
using std::string;

int main()
{
    using nlohmann::json;

    const char *text = "[1,2,3]";
    auto j = json::parse(text);
    cerr << "j[0] = " << j[0] << "\n";
    cerr << "j[1] = " << j[1] << "\n";

    string s1 = R"("Good morning")";
    auto j1 = json::parse(s1);
    cerr << "j1 = " << j1 << "\n";

    std::string_view sw("\"apple pie.\"");
    auto j2 = json::parse(sw);
    cerr << "j2 = " << j2 << "\n";

    std::string_view swr = R"("orange cake")";
    auto j3 = json::parse(swr);
    cerr << "j3 = " << j3 << "\n";
}
