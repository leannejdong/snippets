#include <iostream>

struct struct1
{
    char a; // 1 byte
    short b; // 2 bytes
    int c; // 4 bytes
};

struct struct2
{
    char a; //1 byte
    char b; //1 byte
    int c; //4 byte because char b is in address two, int c is in address4. 
    //So the differece between b&c is 2 bytes
    //there are two padding bytes between b and c
    //ab--ccccdd--
    short d; //2bytes
};

int main()
{
    std::cout << sizeof(struct1) << std::endl;
    std::cout << sizeof(struct2) << std::endl;
}

// the unexpected result due to padding.

