#include <vector>
#include <iostream>

using std::vector;
using Value = int;


// Time:  O(m * n * l), A is m x n matrix, B is n x l matrix
// Space: O(m * l)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int m = A.size(), n = A[0].size(), l = B[0].size();
        vector<vector<int>> res(m, vector<int>(l));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < n; ++k) {
                if (A[i][k]) {
                    for (int j = 0; j < l; ++j) {
                        res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};

std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<Value>> & container)
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
    Solution soln;
    vector<vector<Value>> A {{{0, 3, 0, 0, 0}, {22, 0, 0, 0, 17},
    {7, 5, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 14, 0, 8}}};

    vector<vector<Value>> B {{{0, 3, 0, 0, 0}, {0, 0, 0, 0, 17},
    {7, 5, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 14, 0, 8}}};

    vector<vector<Value>> C = soln.multiply(A, B);
    std::cout << C;

    vector<vector<Value>> I1 {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

    vector<vector<Value>> I2 {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

    vector<vector<Value>> I3 = soln.multiply(I1, I2);
    std::cout << I3;
}

// https://quick-bench.com/q/JdUj1RyehgJ99GL4YV_6p2LXUH8
