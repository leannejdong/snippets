#include <array>
#include <iostream>
#include <algorithm>

using std::array;
using std::cout;


int main()
{
    array<int, 7> arr {2, 12, 3, 2, 5, 7, 9};
    int size = arr.size();
    cout << size << "\n";
    int odd = std::count_if(arr.begin(), arr.end(), [](int i){return i % 2 != 0;});
    cout << " Odd are: " << odd << "\n";

}
