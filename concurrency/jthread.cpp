// Leanne

/* In C++11 std::thread. A thread cannot be interupted.
In C++20 this is no longer the case with jthread
*/

#include <iostream>
#include <thread>
#include <chrono>
// /* 
// What happens when we spawn a thread, and we don't join it.
// If it is join-able, std::terminate gets called (usually calls abort)
// */


int main()
{
    std::jthread t0([](){ std::cout << "Print from the new thread!\n";});
    //If we call join, we wait for the thread to finish
//    t0.join();
    //If we call detach, the thread no longer join-able(terminate isn't called)
    //However, if main exist, our string may not print
//    t0.detach();

}
//https://godbolt.org/z/xWjdTK38T
