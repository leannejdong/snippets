#include <thread>
#include <mutex>
#include <iostream>
using namespace std;

void add_1(int& i/*, mutex& m*/) { // function to be run in thread
   // m.lock();
    i += 1;
  /// m.unlock();
}

int main() {
    int var = 1;
   // mutex m;
    //int m;
    cout << var << endl; // prints 1
    
    thread t1(add_1, std::ref(var)/*, std::ref(m)*/); // create thread with arguments
    thread t2(add_1, std::ref(var)/*, std::ref(m)*/); // create another thread
    t1.join(); t2.join(); // wait for both threads to finish
    
    cout << var << endl; // prints 3
}
//-std=c++20 -pthread -Wall -W -fsanitize=thread
//https://compiler-explorer.com/z/7qYccTxns
