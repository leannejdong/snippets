#include <iostream>
#include <string>
#include <string_view>
/*Copying data can be an expensive operation in terms of CPU usage. 
 * Passing substrings as function parameters would require making a copy of substrings.
 * This is a costly operation. The string_view class help with it */
int main()
{
  std::string s = "Hello World";
  std::string_view sw(s);
//  std::cout << sw;
  // now we create a substring of the first 5 characters
  std::string_view sw5(s.c_str(), 5);
  std::cout << sw5;
  // std::cout << sw.substr(0, 5);                                                                                                                                                                                      

}
