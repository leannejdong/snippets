#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using std::string;
using std::vector;
using std::cout;

// void printWords(const string &str)
// {
//     string word;

//     std::istringstream is_stream(str);

//     while (is_stream >> word)
//     {
//         std::cout << word << "\n";
//     }

//     while (getline(is_stream, word))
//     {

//     }
// }

static vector<string>
organize(const string &table_string, const string &order_string)
{
    string fruitindexP, fruitindexQ;
    string fruitname;
    vector<string> fruitnames;

    std::map<string, string> fruit;

    std::istringstream fruit_table(table_string);
    std::istringstream fruit_order(order_string);


   while (fruit_table >> fruitindexP >> fruitname)
   {
       fruit[fruitname] = fruitindexP;
   }

   while (fruit_order >> fruitindexQ)
   {
       for (auto& [fruitname,fruitindexP] : fruit) {
            if (fruit[fruitname] == fruitindexQ)
            {
                cout << fruit[fruitname] << "\n";
                fruitnames.push_back(fruitname);
            }
       }
   }
   
   for (size_t i = 0; i < fruitnames.size(); i++)
   {
       cout << fruitnames[i] << "\n";
   }

   return fruitnames;

    //return fruitnames;
}


static void test1()
{
    string table_string =
      "1 apple\n"
      "2 orange\n"
      "3 pear\n";

    string order_string = "3 1 2";

    vector<string> result = organize(table_string, order_string);
    vector<string> expected_result = {"pear","apple","orange"};
    assert(result == expected_result);

   // printWords(table_string);
}


static void test2()
{
    string table_string =
      "1 apple\n"
      "2 orange\n"
      "3 pear\n";

    string order_string = "3 2 1";

    vector<string> result = organize(table_string, order_string);
    vector<string> expected_result = {"pear","orange","apple"};
    assert(result == expected_result);
}


int main()
{
    test1();
    test2();
}

// The table_string shows numbers and corresponding names
// The order_string has a list of numbers
// The goal is to create the function organize(), which returns a vector of the names given in table_string according to the order given in order_string.



