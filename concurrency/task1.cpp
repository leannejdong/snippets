// high level concurrency

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
