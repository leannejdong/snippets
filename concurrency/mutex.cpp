/*
 * Accessing std::cout object from two different threads at the same time
 * allows one thread to write a little to it, then another thread jumps in and write a little to it, and we end up with some strange text in the console window.To prevent this, we need to synchronize the access to a shared std::cout object somehow. While one thread is writing to it, we need to ensure that the thread does not write to it. We do so by locking and un-locking mutex-es. A mutex is a way to synchronize the access to a shared std::cout object. While one thread is writing to it, we need to ensure that the thread does not write to it.
 * The following is an example where two threads execute the same function and guard access to std::cout object by locking and unlocking mutexes. We use std::lock_guard to eliminate the chance of forgetting to unlock.*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex m; // will guard std::cout

void myfunc(const std::string& param)
{
  for (int i = 0; i < 10; i++)
  {
    std::lock_guard<std::mutex> lg(m);
    std::cout << "Executing function from a "<< param << "\n";
  }// lock_guard goes out of scope here and unlocks the mutex
}


int main()
{
  std::thread t1{ myfunc, "Thread 1" };
  std::thread t2{ myfunc, "Thread 1" };

  t1.join();
  t2.join();
}
