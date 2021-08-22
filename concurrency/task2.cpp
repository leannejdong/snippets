// high level concurrency, launch policy
// std::launch::deferred - the task is executed synchronously
// std::launch::async -  the task is executed asynchronously
// Call to std::async w/o a launch policy might not always create a new thread
// 1) depends on the compiler implementation
// 2) To force std::async to execute the task asynchronously,use the async launch policy explicitly
// If new thread cannot be created with async launch policy, std::system_error exception is thrown
// arguments are passed by value by default. To pass by ref,
// use the reference wrapper, std::ref (std::cref for const ref)
// To get a value from a task, simply return it from the corresponding function
// Store the value to std::future

#include <iostream>
#include <thread>

void Downloader(){
  using namespace std::chrono_literals;
  for(int i{0}; i < 10; ++i){
    std::cout << '.';
    std::this_thread::sleep_for(100ms); // std::chrono::second(1)
  }
}
int main(){
  // To execute Downloader() as a task, we use std::async

  std::future<void> result = Downloader();
  std::cout << "main() threading continues execution...\n";
  result.get();
}
