#include <iostream>
#include <bitset>
#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;
using std::bitset;

int main()
{
    unordered_map<bitset<2>, string> m;
    m[0] = "light rain";
    m[1] = "medium rain";
    m[2] = "heavy rain";
    std::cout << m[0] << "\n";
}
