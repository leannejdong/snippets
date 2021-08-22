#include <future>
#include <iostream>
#include <thread>

int Operation(int count){
  using namespace std::chrono_literals;
  int sum{};
  for(int i{0}; i < count; ++i){
    sum += i;
    std::cerr << '.';// this gets invoked when we get to the shared state of the task, through .get()
    std::this_thread::sleep_for(300ms);//std::chrono::seconds(1)
  }
  return sum;
}

int main(){
  using namespace std::chrono_literals;
  std::future<int> result = std::async(std::launch::deferred, Operation,10);
  std::this_thread::sleep_for(1s);
  std::cout << "main() thread continues execution...\n";
  if(result.valid()){
    auto sum = result.get();// once we call get on future, the shared state got destroyed
    std::cerr << sum << "\n";
  }
  
}






