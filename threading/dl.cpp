#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;
void ThreadA()
{
    // Creates deadlock
    mutex2.lock();
    std::cout <<  "Thread A\n" ;
    mutex1.lock();
    mutex2.unlock();
    mutex1.unlock();
}

void ThreadB()
{
    // Creates deadlock
    mutex1.lock();
    std::cout <<  "Thread B\n" ;
    mutex2.lock();
    mutex1.unlock();
    mutex2.unlock();
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


