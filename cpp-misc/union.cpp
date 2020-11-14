#include <iostream>   
#include <variant>                                                                                                                                                                                     

union MyUnion
{
    char c; // one byte
    int x; // four bytes
    double d; // eight bytes
};

/* Although the union declares multiple data members,
 * it can only hold a value of one member at any given time. 
 * This is because all the data members share the same memory
 * location. And we can only access the member that was the last 
 * written to.*/

 int main()
 {
     MyUnion o;
     o.c = 'A';
     std::cout << o.c << '\n';
     // accessing o.x and o.d is UB at this point

     o.x = 123;
     std::cout << o.c << '\n';
     // accessing o.c and o.d is UB at this point

     o.d = 456.789;
     std::cout << o.c;
     // accessing o.c or o.x is UB at this point

 }

 

