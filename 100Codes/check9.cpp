#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string num[] = {"Greater than 9", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine"};

    // Write Your Code Here
    // if(n > 5){
    //     cout << num[0];
    // }else{
    //     cout << num[n];
    // }
    cout << ((n>9)?num[0]:num[n]);

    return 0;
}
