#include <cmath>
#include <iostream>

using std::cout;
int main()
{
    float a, b, c;
    std::cin >> a >> b >> c;
    const float descrim = b*b - 4*a*c;

    if(descrim < 0){
        cout << "There is no real roots\n";
    } else if(descrim >0){
        const float r1 = ((-1)*b + sqrt(descrim))/(2*a);
        const float r2 = ((-1)*b - sqrt(descrim))/(2*a);
        cout << "The roots are r1 = " << r1 << " and r2 = " << r2 << "\n";
    } else {
        const float r = -b/(2*a);
        cout << "The roots are r = " << r << "\n";
    }
}
