#include <random>
#include <iostream>


    double GetNormDistrDouble(std::mt19937 &gen)
    {
        double val = 1;
        std::normal_distribution<> nd;
        val = nd(gen);
        do { val = nd(gen);}
        while(val < 1.0 || val > 10.0);

        return val;
    }


int main()
{
    int seed = 10;
    std::mt19937 gen(seed);

    std::cerr << "result: " << GetNormDistrDouble(gen) << "\n";
    std::cerr << "result: " << GetNormDistrDouble(gen) << "\n";
    std::cerr << "result: " << GetNormDistrDouble(gen) << "\n";

    GetNormDistrDouble(gen);
}
