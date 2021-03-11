#include <algorithm>
#include <iostream>
#include <list>

using std::list; 
using std::cerr;

int forEach(list<int> l, auto f)
{
    int count = 0;

    for (auto &x : l) {
        f(x);
        ++count;
    }

    return count;
}


int main()
{
    list<int> l = {1, 2, 3, 4, 5};
    int count = forEach(l, [](int){});
    cerr << "count: " << count << "\n";
}

// when do I need a lambda with empty capture&empty body?
// It would be a case where a function was required for something but 
// we didn't actually need that function to do anything
// In the above example, we had a function which goes through each item in a list
// and call some function f with that. 
