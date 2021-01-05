#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::istringstream;
using std::cerr;

static void my_getline(std::istream &stream, string &s)
{
    s.clear();

    for (;;) {
        int c = stream.get();

        if (c == EOF) {
            break;
        }

        if (c == '\n') {
            break;
        }

        s.push_back(c);
    }
}

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
    // getline reads all character up to the \n and puts them into a string
    // then skips the \n
    my_getline(stream, dummy);
    cerr << "line 1: " << dummy << "\n";
    my_getline(stream, dummy);
    cerr << "line 2: " << dummy << "\n";
    int r;
    stream >> r;// this doesn't read the whole line, it leave out the \n
    cerr << "r: " << r << "\n";
    my_getline(stream, dummy);
    cerr << "line 3: " << dummy << "\n";
    my_getline(stream, dummy);
    cerr << "line 4: " << dummy << "\n";
}

//https://godbolt.org/z/PGdzTa

