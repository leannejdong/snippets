#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

void add_1(std::atomic<int>& i) { // function to be run in thread
    i += 1;
}

int main() {
    std::atomic<int> var = 1;

    cout << var << endl; // prints 1
    
    thread t1(add_1, std::ref(var)); // create thread with arguments
    thread t2(add_1, std::ref(var)); // create another thread
    t1.join(); t2.join(); // wait for both threads to finish
    
    cout << var << endl; // prints 3
}
//https://compiler-explorer.com/z/bvETsbT77
