#include <algorithm>
#include <iostream>
#include <list>

using std::list; 
using std::cerr;


bool isEven(int x)
{
    return x % 2 == 0;
}


int forEachEven(list<int> l, auto f)
{
    int count = 0;

    for (auto &x : l) {
        if (isEven(x)) {
            f(x);
            ++count;
        }
    }

    return count;
}


int main()
{
    list<int> l = {1, 2, 3, 4, 5};
    int count = forEachEven(l, [](int){});
    cerr << "count: " << count << "\n";
}


