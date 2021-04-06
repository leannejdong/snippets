#include <functional>
#include <iostream>
#include <string>

using std::cerr;
using std::string;


int main()
{
    std::hash<string> hash_function;
    string key = "test";
    size_t hash_code = hash_function(key);
    cerr << "key: " << key << "\n";
    cerr << "hash code: " << hash_code << "\n";
}
// https://godbolt.org/z/KPsnqr85M
