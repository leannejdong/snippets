#include <iostream>

struct F1 {
  F1(int m) : member(m) {}

  void operator()(int i){
    cout << i + member << "\n";
  }
  void operator()() {
    cout << m << "\n";
  }
  int member;
};

int main(){
  F1 f1(4);

  f1(3);
  f1();

  // Can create references and pnters
  F1* ptr = &f1;
  F1& ref = f1;

  // And call through them
  (*ptr)();
  ref();
}
