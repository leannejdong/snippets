#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex m;

void worker(int index){
    for(int i{0}; i < 10; ++i){
        std::lock_guard<std::mutex> g(m);
        std::cout << "Worker " << index << " begins" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "Worker " << index << " ends" << "\n";
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

int main(){
    std::thread worker1(worker, 1);
    std::thread worker2(worker, 2);
    worker1.join();
    worker2.join();
    std::cout << "Done\n";

}

// -std=c++20 -pthread -Wall -W -fsanitize=thread
