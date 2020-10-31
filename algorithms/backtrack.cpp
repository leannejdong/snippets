// backtracking
#include <vector>
#include <iostream>

using namespace std;
using std::vector;

vector<vector<int> > backtrack(const int n, const int min)
{
    vector<vector<int> > result;
    if (n > 2 && min < (n+1)/2)
    {
        for (int i = min; i < (n+1)/2; i++)
        {
            vector<vector<int> > temp = backtrack(n-i, i+1);
            for(size_t j = 0; j < temp.size(); j++)
            {
                vector<int> aaa;
                aaa.push_back(i);
                for(size_t k = 0; k < temp[j].size(); k++)
                {
                    aaa.push_back(temp[j][k]);
                    result.push_back(aaa);
                }
            }

        }
    }
    vector<int> vec;
    vec.push_back(n);
    result.push_back(vec);
    return result;
}

int main()
{
    vector<vector<int> > vec = backtrack(10, 1);
    for(size_t i = 0; i < vec.size(); i++)
    {
        for(size_t j = 0; j < vec[i].size(); j++)
        cout << vec[i][j] << " ";
        cout << endl;
    }

    getchar();
}

