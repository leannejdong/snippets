auto operator "" _times(unsigned long long n) { //"" is a user-defined literal
   return [n](auto && f) { for(auto i = 0ULL; i != n; ++i) f(i); }; // 0ULL means the value 0 as type unsigned long long 
}
#include <iostream>
using namespace std;
int main() {
   10_times([](auto) { cout << "I love my instructor\n"; });
   5_times([](auto n) { cout << n * n << '\n'; });
}
// We are using user-defined literals to make a short way to repeat something a certain number of times
// g++ prog.cc -Wall -Wextra -O2 -march=native -I/opt/wandbox/boost-1.64.0/gcc-head/include -std=gnu++2a "-O2"
