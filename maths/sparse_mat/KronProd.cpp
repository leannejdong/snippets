#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using Matrix = std::vector<std::vector<double>>;

Matrix KroneckersProduct(Matrix v1, Matrix v2){
    Matrix v(v1.size() * v2.size(), std::vector<double>(v1[0].size() * v2[0].size()));
    for (std::size_t z1(0); z1 < v1.size(); ++z1) {
        for (std::size_t z2(0); z2 < v2.size(); ++z2) {
            for (std::size_t z3(0); z3 < v1[0].size(); ++z3) {
                for (std::size_t z4(0); z4 < v2[0].size(); ++z4) {
                    v[z1*v2.size() + z2][z3*v2[0].size() + z4] = v1[z1][z3] * v2[z2][z4];
                }
            }
        }
    }
    return v;
}

int main() {
    Matrix v1{{1, 2},{3, 4},{1, 0}};
    Matrix v2{{0, 5, 2}, {6, 7, 3}};

    Matrix v(KroneckersProduct(v1, v2));

    for (const auto& row : v) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << '\n';
    }
    return 0;
}



