// Here we create structured bindings of reference type via auto&syntax
// This means the variable are now references to array elements and making
// changes to variable also changes the array elements
#include <iostream>                                                                                                                                                                                                
#include <array> //use a type with a size known at compile time,
                 //like a std::array, or a std::tuple, or a struct  

using std::array;
int main()                                                                                                                                                                                                         
{                                                                                                                                                                                                                  
  array<int, 3> arr { 1, 2, 3 };                                                                                                                                                                                
  auto& [myvar1, myvar2, myvar3] = arr;                                                                                                                                                                            
  myvar1 = 10;                                                                                                                                                                                                     
  myvar2 = 20;                                                                                                                                                                                                     
  myvar3 = 30;                                                                                                                                                                                                     
  for (auto el : arr)                                                                                                                                                                                              
  {                                                                                                                                                                                                                
    std::cout << el << ' ';                                                                                                                                                                                        
  }                                                                                                                                                                                                                
} 
