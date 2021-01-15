#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using std::vector;
using std::array;
using Value = int;

struct SparseMatrixEntry {
   int row;
   int col;
   Value value;
   SparseMatrixEntry(const int x, const int y, const Value c)
        : row(x), col(y), value(c) {}
};

std::ostream &operator<<(std::ostream &os, const std::vector<SparseMatrixEntry> &sparsemat)
{
    bool last = true;
    for (const SparseMatrixEntry & item : sparsemat) {
        if (last) {
            last = false;
        } else {
            os << ",";
        }
        os  << "[" << item.row << " " << item.col << " " << item.value << "]";       
    }
    return os;
}


std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<Value>> & container/*(M, std::vector<Value> (N))*/)
{
    for (const std::vector<Value> &row : container)
    {
        for (const Value &col : row)
        {
            os << col << " ";
        }
        os << "\n";
    }
    return os;
}

int main()
{
    vector<vector<int>> a {{{0, 3, 0, 0, 0}, {22, 0, 0, 0, 17},
    {7, 5, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 14, 0, 8}}};
    // for (const auto &row : a)
    // {
    //     for (const auto &col : row)
    //     {
    //         std::cerr << col << " ";
    //     }
    //     std::cerr << "\n";
    // }
    std::cout << a;
    

    vector<SparseMatrixEntry> v;
    v.emplace_back(SparseMatrixEntry(0, 1, a[0][1]));
    v.emplace_back(SparseMatrixEntry(1, 0, a[1][0]));
    v.emplace_back(SparseMatrixEntry(1, 4, a[1][4]));
    v.emplace_back(SparseMatrixEntry(2, 0, a[2][0]));
    v.emplace_back(SparseMatrixEntry(2, 1, a[2][1]));
    v.emplace_back(SparseMatrixEntry(2, 3, a[2][3]));
    v.emplace_back(SparseMatrixEntry(4, 3, a[4][3]));
    v.emplace_back(SparseMatrixEntry(4, 4, a[4][4]));

    std::cout << v;


}
// https://godbolt.org/z/j8qahM
