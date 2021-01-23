#include <iostream>


struct PrintFunctor {
    void operator()(int x) const {
        std::cout << x << std::endl;
    }
};

int main()
{
    PrintFunctor f;
    f(5);

    // simple way via lambda
    auto f1 = [](int x){ std::cout << x << std::endl; };
    f1(5);
}

// operator() is what allows us to use () on an object
// so that it looks like a function call
// https://godbolt.org/z/rWbMdq
// We create a variable called f which is an instance of the PrintFunctor class
// When then use `operator()` on f, as if f was a function, even though it isn't.
// If we remove the operator() from the PrintFunctor class, 
// then we can no longer do that: https://godbolt.org/z/xM1aco

// PrintFunctor is the functor
// A functor is a class
// It is a class where the instances of the class can use operator() as if the instance was a function.
// Having operator() defined in the PrintFunctor class is what makes it be a functor.

// Usually a class is designed to be used as a function object.
// we don't usually take some existing class and turn it into a function object.
// This is usually in the context of using algorithms, like the algorithms in the standard library.
// If you want to use std::find_if, it needs a function object to define what it is you are finding.
// Actually it doesn't necessarily need to be a function object, it could also be an actual function.
// But using function objects is more common, because they are more flexible.
// And using lambdas is the most common way since C++11,
// since lambdas create function objects.
// Since function objects tend to be small classes, creating a function object by defining a class is a lot of extra code for just little bit of work.
// Creating a function object by using a lambda takes less code.
// This is just like the PrintFunctor code: https://godbolt.org/z/ax3fYd
// except using a lambda to create the function object instead of defining a class.
