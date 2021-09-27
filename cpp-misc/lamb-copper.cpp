/* Example 6
* Declare a lambda expression
* myLamb has an lvalue category since it has a name
* received using a template or std::function
*/

#include <iostream>
#include <functional>
#include <map>

// auto myLamb = [](double data){ return int(data); };
// do_stuffA(myLamb);
// do_stuffB(myLamb);

// template<typename T>
// void do_stuffA(T arg1);

// void do_stuffB(std::function<int(double)> arg2);


/* Example 7
* std::map<Key, Value, Compare>
* our struct will override the default Compare operation
*/


struct MyCompare{
    bool operator()(const std::string &a, const std::string &b) const{
        return a.size() < b.size();
    }
};

auto myLamb = [](const std::string &a, const std::string &b){
    return a.size() < b.size();
};

int main()
{
    std::map<std::string, int, MyCompare>
    myMapA = { {"orange", 45}, {"apple", 95}, {"kiwi", 40}, {"grapefruit", 22}};

    std::map<std::string, int, decltype(myLamb)> // since we need to specify a data type for 3rd par of std::map
    myMapB = { {"orange", 45}, {"apple", 95}, {"kiwi", 40}, {"grapefruit", 22}};
}

//https://compiler-explorer.com/z/z5PzPcGs6
