#include <thread>
#include <future>
#include <chrono>
#include <iostream>

int main()
{
    std::future<std::string> resultFromDB = std::async([](std::string recvdData){
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return "DB_" + recvdData;
    }, "Data");
    std::cout << resultFromDB.get() << "\n";
}
//calling std::async with lambda function as callback
