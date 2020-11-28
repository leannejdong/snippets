#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::cout;
using std::rotate;


void print(vector<int>& vec)
{
    for (auto v : vec)
    {
        cout << v << "\t";
    }
    cout << "\n";
}

int main()
{
    vector<int> vec0{ 1, 2, 3, 4, 5, 6, 7};
    print(vec0);
    int rotR = 3;

    std::rotate(vec0.begin(), vec0.begin()+rotR, vec0.end());

    print(vec0);


}
