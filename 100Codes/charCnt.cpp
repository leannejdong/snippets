#include <string>
#include <iostream>
#include <algorithm>

using std::cerr;
using std::string;
using std::ranges::count_if;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str = "Hi there, have you done it? I got me a Bug I need to tell";
    //cerr << "Upper case characters: " << std::count_if(str.begin(), str.end(), ::isupper) << "\n";
    cerr << "Upper case characters: " << count_if(str, ::isupper) << "\n";
    return 0;
}
// https://godbolt.org/z/8vP84sGjd
// https://stackoverflow.com/questions/28782013/how-make-separate-functions-to-count-no-of-uppercase-lowercase-spaces-and-spe
// count the number of upper cases in a sentence
