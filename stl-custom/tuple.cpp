#include <iostream>

using std::cout;


template <typename F>
struct Tuple {
    F f;
    Tuple(F f) // Tuple class stores a function obj
    : f(f)
    {
    }
};


template <typename... Args>
static auto makeTuple(Args... args)
{
    return Tuple([args...](auto g){ g(args...); });
}

template <typename F, typename F2>
static void apply(const F &f, const Tuple<F2> &t)
{
    t.f(f);
}


template <typename T>
static void print(const T &arg)
{
    cout << arg << "\n";
}

int main()
{
    Tuple t = makeTuple(1, 6.2, "cake");
    apply([](auto... args){ ((cout << args << "\n"),...); }, t);
}
