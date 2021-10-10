#include <iostream>
#include <thread>
#include <mutex>

using std::mutex;
std::mutex mutex1, mutex2;
void ThreadA()
{
    std::lock_guard<mutex> locker1(mutex1);
    std::lock_guard<mutex> locker2(mutex2);
    std::cout <<  "Thread A\n" ;

}

void ThreadB()
{
    std::lock_guard<mutex> locker1(mutex1);
    std::lock_guard<mutex> locker2(mutex2);

    std::cout <<  "Thread B\n" ;

}

void ExecuteThreads()
{
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);

    t1.join();
    t2.join();

    std::cout << "Finished\n";
}

int main()
{
    ExecuteThreads();
    return 0;
}

//https://compiler-explorer.com/z/14jbvq48E


