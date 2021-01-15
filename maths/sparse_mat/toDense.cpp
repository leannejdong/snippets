/// sparse to dense
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using std::vector;
using std::array;
using Value = int;
constexpr int M = 5;
constexpr int N = 5;

struct SparseMatrixEntry {
   int row;
   int col;
   Value value;
   SparseMatrixEntry(const int x, const int y, const Value c)
        : row(x), col(y), value(c) {}
};

std::ostream &operator<<(std::ostream &os, const std::vector<SparseMatrixEntry> &sparsemat)
{
    //bool last = true;
    for (const SparseMatrixEntry & item : sparsemat) {
        // if (last) {
        //     last = false;
        // } else {
        //     os << ",";
        // }
        os  << "[" << item.row << " " << item.col << " " << item.value << "]" << "\n";       
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
    vector<SparseMatrixEntry> v;
    v.emplace_back(SparseMatrixEntry(0, 1, 3));
    v.emplace_back(SparseMatrixEntry(1, 0, 22));
    v.emplace_back(SparseMatrixEntry(1, 4, 17));
    v.emplace_back(SparseMatrixEntry(2, 0, 7));
    v.emplace_back(SparseMatrixEntry(2, 1, 5));
    v.emplace_back(SparseMatrixEntry(2, 3, 1));
    v.emplace_back(SparseMatrixEntry(4, 2, 14));
    v.emplace_back(SparseMatrixEntry(4, 4, 8));

    // for (const auto & s : v)
    // {
    //     std::cout << s.value << "\t";
    // }

   // std::cerr << v.size();

   std::cout << v;
   std::cout << "\n";


  std::vector<std::vector<int>> a(M, std::vector <int> (N, 0));
   a[0][1] = v[0].value;
   a[1][0] = v[1].value;
   a[1][4] = v[2].value;
   a[2][0] = v[3].value;
   a[2][1] = v[4].value;
   a[2][3] = v[5].value;
   a[4][2] = v[6].value;
   a[4][4] = v[7].value;

   std::cout << a;
}

// https://godbolt.org/z/fdzqeG
