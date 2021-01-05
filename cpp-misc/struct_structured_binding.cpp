#include <iostream>
#include <string>

auto foo()
{
    struct Result {
        int s1 = 10;
        float s2 = 20.33;
        std::string str = "Hi";
    };
    
    return Result{};


}

int main()
{
    auto [x, y, z] = foo();
    x = 20; y = 20.5; z = "hello";
    std::cout << x << " , " << y << " , " << z << std::endl;
}
//https://gcc.godbolt.org/z/6rMxPh
