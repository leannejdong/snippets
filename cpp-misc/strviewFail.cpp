#include <string_view>
#include <string>
#include <iostream>

using std::cerr;


int main()
{
    {
        std::string a = "hello";
        std::string b = " there";
        cerr << (a+b) << "\n";
    }
    // {
    //     std::string_view a = "hello";
    //     std::string_view b = " there";
    //     cerr << (a+b) << "\n";
    // }
}

//when string_view fails https://godbolt.org/z/aTc3vd


