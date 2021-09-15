#include <thread>
#include <future>
#include <chrono>
#include <iostream>
// Function object
struct DataFetcher
{
    std::string operator()(std::string recvData)
    {
        // make sure the function takes 5 secs to cviomplete
        std::this_thread::sleep_for(std::chrono::seconds(5));
        // fetch data file
        return "File_" + recvData;
    }

};

int main()
{
    std::future<std::string> fileResult = std::async(std::launch::async,DataFetcher(), "Data");
    std::cout << fileResult.get() << "\n";
}
// calling std::async with functor with callback

