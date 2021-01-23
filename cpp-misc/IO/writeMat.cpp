#include<iostream>
#include<vector>
#include<random>
#include <iomanip>
#include<fstream>

using std::vector;
using std::cerr;

int main()
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 10.0);
    vector<vector<double>> Matrix(5, vector<double>(7, 0));
    std::ofstream file("matrix.txt");
    for (auto &row : Matrix){
        for (auto &col : row){
            col = dis(gen);
            file << std::setw(4) << col;
        }
        file << '\n';
    }

}
// https://godbolt.org/z/PdT946

