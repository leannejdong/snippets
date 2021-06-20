#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // // Complete the code.
    // int a, b, n;
    // vector<string> str{"one", "two","three","four","five","six","seven","eight","nine","even","odd"};
    // cin >> a >> b;
    // for(n = a; n <= b; ++n){
    //     if((n>=1)&&(n <= 9)){          
    //         cout << str[n-1] << "\n";
    //     }else if((n > 9)&&(n%2==0)){         
    //         cout << str[9 + (n%2)]<< "\n";       
    //     }else if((n > 9)&&(n%2!=0)){
    //         cout << str[9 + (n%2)] << "\n";
    //     }
    // } 
    int a, b, n;
    vector<string> str{"one", "two","three","four","five","six","seven","eight","nine","even","odd"};
    cout << "Enter lower, upper bounds " << "\n";
    cin >> a >> b;
    for(n = a; n <= b; ++n){
        if(n<=9){          
            cout << str[n-1] << "\n";
        }else{         
            cout << str[9 + (n%2)]<< "\n";       
        }
    } 
    return 0;
}

