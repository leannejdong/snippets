#include <iostream>

using std::cout;

struct C1 {
    static void fkn1(C1* obj){
        cout << 1 << "\n";
    }

    static void fkn2(C1* obj){
        cout << 2 << "\n";
    }

};


int main(){
    // static member funcntion works as free functions. Just declared within a class
    // and have the class name as part of their name
    C1::fkn1(nullptr);

    // specify signature when setting up a function pointer type
    using Fkn = void(*)(C1*);

    // Use name (including class name) with signature to extract address
    Fkn fkn = &C1::fkn1;

    // and finally call
    C1 c1;
    fkn(&c1);
}




