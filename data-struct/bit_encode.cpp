#include <iostream>
#include <bitset>
#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;
using std::bitset;

int main()
{
    unordered_map<string, bitset<2>> m;
    m["light rain"] = 0;
    m["medium rain"] = 1;
    m["heavy rain"] = 2;
    std::cout << m["light rain"] << "\n";
    std::cout << m["medium rain"] << "\n";
    std::cout << m["heavy rain"] << "\n";

}
