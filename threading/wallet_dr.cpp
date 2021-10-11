#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

//using std::mutex;
class Wallet
{
    int mMoney;
    std::mutex mutex;
    public:
        Wallet() :mMoney(0){}
        int getMoney() { return mMoney; }
        void addMoney(int money)
        {
            std::lock_guard<std::mutex> lk(mutex);
            //mutex.lock();
            for(int i{0}; i < money; ++i)
            {
                mMoney++;
            }
            //mutex.unlock();
        }

};

int testMultithreadedWallet()
{
    Wallet wObj;
    std::vector<std::thread> threads;
    for(int i{0}; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &wObj, 1000));
    }
    for(size_t i{0}; i < threads.size(); i++)
    {
        threads[i].join();
    }
    return wObj.getMoney();
}

int main()
{
    int val{0};
    for(int k{0}; k < 1000; ++k)
    {
        if((val = testMultithreadedWallet()) != 5000)
        {
            std::cout << "Error at count = " << k << " Money in Wallet = " << val << "\n";
        }
    }
    return 0;
}
// No error msg printed, hence program compiled successfully

// https://thispointer.com//c11-multithreading-part-5-using-mutex-to-fix-race-conditions/
