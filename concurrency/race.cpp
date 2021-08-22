#include <iostream>
#include <list>
#include <thread>

const int SIZE = 5000;
std::list<int> g_Data(SIZE);
void Download(){
  for(int i{0}; i <SIZE; ++i){
      g_Data.push_back(i);
  }
}
void Download2(){
  for(int i{0}; i <SIZE; ++i){
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

