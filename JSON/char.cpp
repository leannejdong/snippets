#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using std::cerr;
using std::string;

int main()
{
    using nlohmann::json;

    const char *text = "[1,2,3]";
    auto j = json::parse(text);
    cerr << "j[0] = " << j[0] << "\n";
    cerr << "j[1] = " << j[1] << "\n";

    char s1[] = {'"','G','o','o','d',' ','M','o','r','n','i','n','g','"'};
    auto j1 = json::parse(s1);
    cerr << "j1 = " << j1 << "\n";
}
