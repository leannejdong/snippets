#include <functional>
#include <future>
#include <iostream>

using std::cerr;


struct A {
  A() { cerr << "In A()\n"; }
  ~A() { cerr << "In ~A()\n"; }

  static void g()
  {
      cerr << "In A::g()\n";
  }
};

void doTask(std::function<void()> middle)
{
    cerr << "Start task\n";
    middle();
    cerr << "End task\n";
}


int main()
{
    A a;
    doTask(a.g);
}

/*
In this example, doTask takes a function a parameter middle which is a callback to be executed in the middle of the task.
a.g is used as that callback
*/
//https://compiler-explorer.com/z/v3ex5GYT4
