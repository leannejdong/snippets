#include <cmath>
#include <iostream>

int main()
{
    auto jumps = [](int x = 10, int y = 85, int d = 30) 
     { if ((y-x)%d==0) return (y-x)/d; else return (int)floor((y-x)/d + 1); };

    std::cout << "jumps are : " << jumps();
}
