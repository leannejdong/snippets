#include <iostream>

using std::cout;

void fkn1(){
    cout << 0 << "\n";
}

void fkn1(int x){
    cout << x << "\n";
}

void fkn2(int x){
    cout << 2*x << "\n";
}

int main(){
    // specify both function name, signature and make the call
    // or, deduce function address from signature and name, call address
    // This is overload resolution in standard language.
    fkn1(1);
    // Now let use Fn pnters
    // Specify signature, part of the type system.
    using Fkn = void(*)(int);

    // make function pointer
    Fkn fkn = nullptr;
    // Calculate address from name together with signature
    // Overload resolution is performed. Assign to pointer.
    fkn = &fkn1;

    // Do the call. Address and argument values
    // needed at the call site. No resolution done
    fkn(2);
}

// Function signature: The type of function includes a number of parameters and their types
// Function pointer: Object with the address of a function. Its type is given by the function signature.
// Function address: Can be taken from a function defn and later be used to call the function with arguments.
// Function arguments: Values to pass into a function at call time
// Overload set: A set of functions sharing the same name, but with different signatures.


