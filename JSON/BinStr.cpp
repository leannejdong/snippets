#include <iostream>
#include <string>
#include <bitset>


using std::cerr;
using std::string;

int main()
{
    cerr << std::bitset<8>(123) << "\n";
    string str = std::bitset<8>(123).to_string();
    cerr << str << "\n";

}
