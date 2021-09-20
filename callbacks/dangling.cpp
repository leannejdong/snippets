#include <functional>
#include <future>
#include <iostream>

using std::cerr;


struct A {
  A() { cerr << "In A()\n"; }
  ~A() { cerr << "In ~A()\n"; }
  void g()
  {
      cerr << "In A::g()\n";
  }
};


std::future<void> f(A a)
{
    return std::async([&a](){ a.g(); });
}



int main()
{
    std::future<void> future_f = f(A());
}

//Note that A::g is called after the A is destroyed, which is UB.


