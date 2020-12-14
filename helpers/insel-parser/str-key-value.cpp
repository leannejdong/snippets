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
       fruit[fruitindexP] = fruitname;
   }

   while (fruit_order >> fruitindexQ)
   {
       fruitnames.push_back(fruit[fruitindexQ]);
   }
   
   for (size_t i = 0; i < fruitnames.size(); i++)
   {
       cout << fruitnames[i] << "\n";
   }

   return fruitnames;

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

/* The table_string shows numbers and corresponding names
 * The order_string has a list of numbers
 * The goal is to create the function organize(), which returns a vector of the names given in table_string according to the order given in order_string.
 */

/* 
 *Since the order string contained the numbers, 
 *it is more natural to want to look for the names that go with the numbers. 
 *So treating the numbers as the key makes it easier to work with the map.
 */

 /* Line29, 34. We are looking for a value for a particular key. 
  * This is not a build-in feature of map. So we cannot do it->first. 
  * Instead, we do fruit[fruitindexQ]
  */


