#include <iostream>
using std::cerr;
using std::cin;
class Number
{
    int n;
    public:
        void read()
        {
          cerr << "Enter a number: " << "\n";
          cin >> n;
        }
        int operator<(Number X)
        {
          if(n < X.n)
            return 1;
          else
            return 0;
        
        }
        int operator>(Number X)
        {
          if(n > X.n)
            return 1;
          else
            return 0;
        }
        int operator == (Number X)
        {
          if(n == X.n)
            return 1;
          else
            return 0;
        }
};

int main()
{
  Number n1, n2;
  n1.read();
  n2.read();
  if(n1 < n2)
    cerr << "n1 is less than n2 " << "\n";
  else
    if(n1 > n2)
      cerr << "n1 is greater than n2 " << "\n";
    else
      if(n1 == n2)
        cerr << "Equal" << "\n";
  return 0;
}
