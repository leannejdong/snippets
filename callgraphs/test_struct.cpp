#include <vector>

struct A { 
  A(int);
  void f(); // not defined, prevents inlining it!
};

int main() {
  std::vector<A> v;
  v.push_back(42);
  v[0].f();
}
