#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>

const int SIZE = 5000;
std::list<int> g_Data(SIZE);
void Download(){
  for(int i{0}; i <SIZE; ++i){
      g_Mutex.lock();
      g_Data.push_back(i);
      if(i==500)
        return; // the 1st thread might have locked the mutex, so at this point it simply return without unlocking
      g_Mutex_unlock();// this will never happen as the 1st thread been locked already terminated.
  }
}
void Download2(){
  for(int i{0}; i <SIZE; ++i){
      g_Mutex.lock();
      g_Data.push_back(i);
      g_Mutex.unlock();
  }
}

int main()
{
    std::thread thDownloader(Download);
     std::thread thDownloader2(Download2);

    thDownloader.join();
    thDownloader2.join();
    std::cout << g_Data.size() << "\n";

    return 0;

}

// the two threads race with each other.
// We need a way to ensure that while the data is being accessed by one thread, it shall not be accessed by the other thread. To this end, we have c++11 mutex
// a mutex is a lock, a synchronization primitive enforeces limits on access to a resource when there are many threads of execution.
