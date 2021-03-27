#include <iostream>
#include <vector>
#include <cassert>
using std::vector;

class evenp
{
    public:
    bool operator() (int n) {
        return (n % 2 ==0);
    }
};

void do_it(const vector<int> &vec, evenp is_even) {
    for (auto &v : vec) {
        if(is_even(v)) {
            std::cerr << v << " is even\n";
        }
    }
}

int main()
{
    vector<int> numbers{1, 4, 7, 11, 12, 23, 26};
    evenp is_even;  // create an instance of the functor
    if (is_even(6)){
        std::cerr << "6 is even\n";
    } // call its function call operator with argument 6
    do_it(numbers, is_even);   
}
