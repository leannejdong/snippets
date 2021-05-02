// The code is creating a new string with each character added twice
#include <iostream>
#include <string>

using std::cerr;
using std::string;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    string str = "Hello World";
    string result = "";
  //  size_t i = 0;
   // while (i < str.length()){
    //     char c = str.at(i);
    //     result = result + c + c;
    //     i++;
    // }
    // cerr << result;

    for(size_t i = 0; i < str.length(); ++i)
    {
        char c = str.at(i);
       // result += c + c;
        result = result + c + c;
    }
    cerr << result;
    return 0;
}
//adding two characters together doesn't give you a string
//https://godbolt.org/z/EYEs9G7fT
