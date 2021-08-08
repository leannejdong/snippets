// practice variadic template
#include <iostream>

using std::cerr;
using std::string;

// This is the base case for our recursive function
template <typename T>
T adder(T v){
    cerr << __PRETTY_FUNCTION__ << "\n";
    return v;
}

/*
Variable number of input arguments in a template
"typename... Args" is a template parameter pack
"Args... args" is a function parameter pack
We can use recursive calls to unpack all the arguments!
*/

template< typename T, typename... Args>
T adder(T first, Args... args){
    cerr << __PRETTY_FUNCTION__ << "\n";
    return first + adder(args...);
}

template<typename T>
bool pair_comparer(T a, T b) {
  // In real-world code, we wouldn't compare floating point values like
  // this. It would make sense to specialize this function for floating
  // point types to use approximate comparison.
  return a == b;
}

template<typename T1, typename T2, typename... Args>
bool pair_comparer(T1 a, T2 b, Args... args) {
  return a == b && pair_comparer(args...);
}

template<typename T>
bool pair_comparer(T a) {
  return false;
}

int main(){
    // We can calculate a sum with a variable number of integers
    int int_sum = adder(1, 2, 3, 4, 5);
    cerr << "The integer sum is " <<int_sum << "\n";

    // We can calculate a sum with a variable number of floats
    float float_sum = adder(1.5, 2.5, 3.5, 4.5, 5.5);
    cerr << "The floating point sum is " << float_sum << "\n";

    // Declare some strings we want to combine
    string p1{"This"};
    string p2{"does"};
    string p3{"concatenation!"};

   // pair_comparer(1.5, 1.5, 2, 2, 6, 6); // change the 2nd 1.5 to 1 will fail you!
    pair_comparer(1.5, 1.5, 2, 2, 6, 6, 7, 7);

    // The string literal "4" becomes a const char * when it is used as a value
    // https://compiler-explorer.com/z/nThMradd5
    
}
