
#include <iostream>

struct F1 {
  F1(int m) : member(m) {}

  void operator()(int i){
    cout << i + member << "\n";
//  }
//  void operator()() {
//    cout << m << "\n";
//  }
  int member;
};

int main(){
  int m = 4;
  F1 f1(4);

  auto lambda = [m](int i){std::cout << i + m << "\n";
  f1(3);
  lambda(3);
}
