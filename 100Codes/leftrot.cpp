//Left rotation
#include <iostream>
#include <vector>
//#include <algorithm>
#include <span>
using std::vector;
using std::cerr;
using std::span;

template <typename T>
vector<T> rotLeft(vector<T> &a, T d){
    vector<T> rot_array;
    //for(auto it = a.begin()+d; it != a.end(); ++it)
    for(auto x : span(a.begin()+d, a.end()))
    {
        rot_array.push_back(x);
    }
    //for(auto it = a.begin(); it != a.begin()+d; ++it)
    for(auto x : span(a.begin(), a.begin()+d))
    {
        rot_array.push_back(x);
    }
    return rot_array;
}


int main()
{
    vector<int> arr{12, 22, 34, 47, 55, 67, 82, 98};
    vector<int> result_arr = rotLeft(arr, 3);
    for(auto a : result_arr)
    {
        cerr << a << " ";
    }
    cerr << "\n";
    
}

//https://www.modernescpp.com/index.php/c-20-std-span
// use std::span, since we not modifying the vector
