#include <vector>
#include <iostream>


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
    std::vector<int> v = {1,2,3};
    std::cout << v;
}
