#include <memory>

using std::unique_ptr;
using std::make_unique;

int main()
{
    unique_ptr<int> p = make_unique<int>(5);
      // create an int and pass ownership to p

    int *q = p.release(); // p releases ownership and gives it to q;
    delete q; // have to use delete because q is going away and it still owns the int.
}
