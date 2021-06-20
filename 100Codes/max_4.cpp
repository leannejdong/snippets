#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
    return max(a, max(b, max(c, d)));  
}
int max4(int a, int b, int c, int d)
{
    return std::max({a, b, c, d});
}
int main() {
    int a, b, c, d;
    cout << "Enter a, b, c d: " << "\n";
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d\n", ans);
   // cout << "Enter a, b, c d: " << "\n";
   // scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans1 = max_of_four(a, b, c, d);
    printf("%d\n", ans1);
    
    return 0;
}
