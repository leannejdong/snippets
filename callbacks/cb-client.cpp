#include <iostream>
#include <future>
#include <string>
#include <functional>

using Callback = std::function<int(int)>;
class Caller{
    public:
    // Clients can connect callback with this
    void connectCallback(Callback cb){
        m_cb = cb;
    }
    // Test the callback to make sure it works
    void test(){
        m_cb(5);
        std::cout << "Caller::test() calling callback...\n";
    }

    private:
    Callback m_cb;
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
   //caller.connectCallback([&callee](int i) {return callee.callbackFunction(i);});
   // call std::async with lambda as callback
   std::future<int> result = std::async([&callee](int i) {return callee.callbackFunction(i);}, 5);
   std::cout << result.get() << "\n";
    // Test the callback
   // caller.test();
    return 0;
}

//https://compiler-explorer.com/z/8qdEsTahG
