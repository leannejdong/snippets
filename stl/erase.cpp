#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using std::vector;

template <typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &container)
{
    stream << "[ ";

    for (const T &item : container) {
        stream << item << " ";
    }

    stream << "]";
    return stream;
}

int main()
{
    //popilating a vector
    vector<int> v;
    for(int i{0}; i < 5; ++i)
    {
        v.push_back(i);
    }

    int i{0};
    std::generate_n(std::back_inserter(v), 5, [&](){ return i++; });

    //totalling 
    int total{0};
    for(int index{0}; index < 5; index++)
    {
        total += v[index];
    }

    std::cout << v << "\n";

    total = 0;
    for(int elem : v)
    {
        total += elem;
    }

    std::cout << v << "\n";

    total = std::accumulate(begin(v), end(v), 0);

    // counting the number of 2s
    int count1{0};
    for(unsigned int i{0}; i < v.size(); ++i)
    {
        if(v[i] == 3)
        {
            count1++;
        }
    }

    std::cout << v << "\n";

    int count2{0};
    for(auto it = begin(v); it != end(v); it++)
    {
        if(*it == 3)
        {
            count2++;
        }
    }

    std::cout << v << "\n";

    int count3 = std::count(begin(v), end(v), 3);

    // removing 3's
    auto v2 = v;
    for(unsigned int index{0}; index < v2.size(); ++index)
    {
        if(v2[index] == 3)
        {
            v2.erase(v2.begin() + index);
        }
    }
    std::cout << v2 << "\n";

//UB: on line94, v.erase(it) is called. This invalidates the iterator,
// and it is no longer valid to use it, but ++it is called on line 91
    // auto v3 = v;
    // for(auto it = begin(v3); it != end(v3); ++it)
    // {
    //     if(*it == 3)
    //     {
    //         v3.erase(it);
    //     }

    // }
    //     std::cout << v << "\n";

    auto v4 = v;
    auto endv4 = std::remove_if(begin(v4), end(v4),
    [](int elem){return (elem == 3);});
    std::cout << v4 << "\n";
    //simpler approach
    //auto endv4 = v4.erase(std::remove(begin(v4), end(v4),3), v4.end());
    //use lambda if we need some other way to identify the element that needs
    //to be removed other than equality


    //https://godbolt.org/z/e1sba6P4s
    // It also say in doc https://en.cppreference.com/w/cpp/container/vector/erase that "invalidates iterators and reference at or after the point of the erase, including the end() iterator. More info at https://stackoverflow.com/questions/6438086/iterator-invalidation-rules-for-c-containers?noredirect=1&lq=1





}
