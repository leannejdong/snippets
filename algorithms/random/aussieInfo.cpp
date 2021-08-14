
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <atomic>
#include <sstream>
//#include <fstream>
#include <random>


using std::string;
using std::vector;
using std::cout;

constexpr size_t N = 10;
constexpr int MAX = 26;

struct Customer
{
    string firstname;
    string lastname;
    string phoneNum;
    string postCode;
    string idNumber;
};

struct Utility {
//    static size_t getUniqueId();
    static int randomNumber();
    static string getPhoneNumber(const string &input);
    static string getPostCode(const string &input);
    // static string printRandomString(int n);
    // static int randomAlphabet();
    static string getID();
};

// size_t Utility::getUniqueId() {
//     static std::atomic<std::uint32_t> uid { 0 };
//     return ++uid;
// }

int Utility::randomNumber() {
    auto gen = std::mt19937{std::random_device{}()};
    auto dist = std::uniform_int_distribution<int>{0, 9};
    return dist(gen);
}
string Utility::getPhoneNumber(const string &input) {
       // used as a seed for random engine
    std::random_device rd;// generate non-deterministic values
    std::mt19937 random_engine(rd()); // seed engine with number from random_device
    return (input + "-" + std::to_string(randomNumber()) + std::to_string(randomNumber())
    + std::to_string(randomNumber()) + std::to_string(randomNumber())
    + std::to_string(randomNumber()) + std::to_string(randomNumber())
    + std::to_string(randomNumber()) + std::to_string(randomNumber()));
}
string Utility::getPostCode(const string &input) {
    std::random_device rd;
    std::mt19937 random_engine(rd()); // rd() generate one non-deterministic values
    return (input + std::to_string(randomNumber()) + std::to_string(randomNumber())
    + std::to_string(randomNumber()));

}

// string Utility::printRandomString(int n)
// {
//     char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
//                           'h', 'i', 'j', 'k', 'l', 'm', 'n',
//                           'o', 'p', 'q', 'r', 's', 't', 'u',
//                           'v', 'w', 'x', 'y', 'z' };
//     string res = "";
//     for(int i{0}; i < n; ++i){
//         res = res + alphabet[randomAlphabet()];
//     }
//     return res;
    
// }

// int Utility::randomAlphabet()
// {
//     auto gen = std::mt19937{std::random_device{}()};
//     auto dist = std::uniform_int_distribution<int>{0, MAX - 1};
//     return dist(gen);
// }

string Utility::getID()
{
    std::random_device rd;
    std::mt19937 random_engine(rd()); // rd() generate one non-deterministic values
    return (std::to_string(randomNumber()) + std::to_string(randomNumber())
    + std::to_string(randomNumber()) + std::to_string(randomNumber()) + std::to_string(randomNumber()));

}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &container)
{
    
    for(const T&item : container){
        stream << "[";
        stream << item.firstname << " " << item.lastname << ": " << item.phoneNum << " " << item.postCode << " " << item.idNumber << " ";
        stream << "]";
        stream << "\n";

    }
    return stream;
}
int main()
{
    string areaCode;
    std::cin >> areaCode;
    string zip_start;
    std::cin >> zip_start;
    vector<Customer> customers = {
        { "Ben", "Goldys", Utility::getPhoneNumber(areaCode), Utility::getPostCode(zip_start), "bg" + Utility::getID()},
        { "Mike", "Tarr", Utility::getPhoneNumber(areaCode), Utility::getPostCode(zip_start), "mt" + Utility::getID()},
        { "Julie", "Simpson", Utility::getPhoneNumber("02"), Utility::getPostCode(zip_start), "js" + Utility::getID()},
        { "Mark", "Craddock", Utility::getPhoneNumber("02"), Utility::getPostCode(zip_start), "mc" + Utility::getID()},
        { "John", "van der Hoek", Utility::getPhoneNumber(areaCode), Utility::getPostCode(zip_start), "jv" + Utility::getID()}
    };


    auto less_last_name = 
      [](const auto &a, const auto &b){ return a.lastname < b.lastname; };

    auto less_postCode =
      [](const auto &a, const auto &b){ return a.postCode < b.postCode; };


   std::ranges::sort(customers, less_last_name);

    // for (const auto &c : customers) {
    //     cout << c.firstname << " " << c.lastname << "\n";
    // }

    cout << customers << "\n";

    std::ranges::sort(customers, less_postCode);
    // for (const auto &c : customers) {
    //     cout << c.firstname << " " << c.lastname << " " << c.phoneNum << " " << c.postCode << " " << c.idNumber <<"\n";
    // }
    cout << customers;

}

// https://godbolt.org/z/dx1bPfv4c  // generate random phone number

