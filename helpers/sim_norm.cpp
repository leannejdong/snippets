#include <random>
#include <iostream>


std::random_device rd{};
std::mt19937 gen{rd()};
std::normal_distribution<> nd;

float GetNormDistrFloat()
{
    float val = -1;
    do { val = nd(gen); } 
    while(val < 0.0f || val > 1.0f);

    return val;
}


int main()
{
    std::cerr << "result: " << GetNormDistrFloat() << "\n";
    std::cerr << "result: " << GetNormDistrFloat() << "\n";
    std::cerr << "result: " << GetNormDistrFloat() << "\n";

    GetNormDistrFloat();
}
