#include <iostream>                                                                                                                                                                                        
#include <variant>

// define a variant that can hold 3 types. 
// When we initialize or assign a value to a variant, 
// an appropriate type is chosen. Eg,
// if we initialize a variant with a character value
// the variant will currently hold a char data member.
// Accessing other members at this point will throw an exception

using MyUnion = std::variant<char,int,double>;


 int main()
 {
     MyUnion o;
     o = 'A';
     std::cout << std::get<char>(o) << '\n';

     o = 123;
     std::cout << std::get<int>(o) << '\n';

     o = 456.789;
     std::cout << std::get<double>(o) << '\n';
 }

 

