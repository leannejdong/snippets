#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::istringstream;
using std::cerr;


int main()
{
    string input_string =
        "MATRICES FOR INPUT TO TEST ROUTINES\n"
        "number of rows and columns:\n"
        "11\n"
        "Circuit matrix:\n"
        "0 1 0 0 0 0 1 1 0 0 0\n";
    
    istringstream stream(input_string);
    std::string dummy;
    std::getline(stream, dummy);
    cerr << "line 1: " << dummy << "\n";
    std::getline(stream, dummy);
    cerr << "line 2: " << dummy << "\n";
    int r;
    stream >> r;
    cerr << "r: " << r << "\n";
    std::getline(stream, dummy);
    cerr << "line 3: " << dummy << "\n";
}

// https://godbolt.org/z/sjx3Eq

