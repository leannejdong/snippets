#include <vector>
#include <utility>
#include <iostream>


template <typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<std::pair<T, T>> &container)
{
    for (const auto &item : container) {
        stream << "[" << item.first << " " << item.second << "]" << " ";
    }

    return stream;
}


int main()
{
    std::vector<std::pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
    std::cout << v << "\n";
}
