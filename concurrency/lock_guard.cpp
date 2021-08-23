#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>

const int SIZE = 5000;
std::list<int> g_Data(SIZE);
std::mutex g_Mutex;
void Download(){
  for(int i{0}; i <SIZE; ++i){
      std::lock_guard<std::mutex> mtx(g_Mutex);
      g_Data.push_back(i);
      if(i==500)
        return; 
  }
}
void Download2(){
  for(int i{0}; i <SIZE; ++i){
      std::lock_guard<std::mutex> mtx(g_Mutex);
      g_Data.push_back(i);
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

