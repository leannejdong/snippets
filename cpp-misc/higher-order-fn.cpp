#include <iostream>
#include <functional>


static void printHello()
{
    std::cout << "Hello\n";
}


static void callTwice(std::function<void()> f)
{
    f();
    f();
}


int main()
{
    callTwice(printHello);
}
