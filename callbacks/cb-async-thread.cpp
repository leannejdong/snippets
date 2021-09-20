#include <iostream>
#include <future>
#include <string>
#include <functional>

struct TimeResponse{};

using Callback = std::function<int(int)>;
class Caller{
    public:
    // Clients can connect callback with this
    void connectCallback(Callback cb){
        m_cb = cb;
    }

    static void testThread(Caller *caller_ptr)
    {
        caller_ptr->m_cb(5);
    }

    // Test the callback to make sure it works
    void startTest(){
        thread = std::thread(testThread, this);
    }

    void endTest()
    {
        thread.join();
    }

    private:
    Callback m_cb;
    std::thread thread;
};

class Callee{
    public:
    Callee(int i): m_i(i){}

    // The callback function that Caller will call
    int callbackFunction(int i){
        std::cout << " Callee::callbackFunction() inside callback\n";
        return m_i * i;
    }

    private:
    // To prove "this" is indeed valid within callbackFunction()
    int m_i;
};

int main(){
    Caller caller;
    Callee callee(5);
    // Connect the callback with lambda
   caller.connectCallback([&callee](int i) {return callee.callbackFunction(i);});
    // Test the callback
    caller.startTest();
    caller.endTest();
    return 0;
}
//https://compiler-explorer.com/z/dfGTE6rfM
