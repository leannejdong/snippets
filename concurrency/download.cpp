#include <iostream>
#include <list>
#include <thread>

const int SIZE = 5000000;
std::list<int> g_Data(SIZE);
void Download(){
  std::cout << "[Downloader]Started download" << "\n";
  for(int i{0}; i <SIZE; ++i){  
    g_Data.push_back(i);
  }
  std::cout << "[Downloader]Finished download" << "\n";
}

int main()
{
    std::cout << "[main]User started an operation" << "\n";
    std::thread thDownloader(Download);
    std::cout << "[main]User started another operation" << "\n";
    // Wait for the thread to finish; we stay here until it is done
    thDownloader.join();
    return 0;

}

