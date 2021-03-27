#include <iostream>

class Functor {
    int my_i;
    int &my_jRef;

public:
    Functor(int i, int &j) : my_i{i}, my_jRef{j} {}

    int operator()(int k0, int &l0) {
        my_jRef = 2 * my_jRef;
        k0 = 2*k0;
        l0 = 2*l0;
        return my_i + my_jRef + k0 + l0;
    }

    //void do_it(const vector<int>)
};  // A class that has an overloaded function call operator is defined as functor

int main()
{
    int i = 1; int k = 10; 
    Functor func(i, k);
    std::cout << func(i, k) << "\n";
}
