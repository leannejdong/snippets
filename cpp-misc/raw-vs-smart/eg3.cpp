//never have two unique_ptrs pointing to the same thing
#include <memory>
#include <vector>
#include <iostream>

using std::unique_ptr;
using std::make_unique;
using std::vector;
using std::cout;

vector<unique_ptr<int>> global_ints;


int* f()
{
    unique_ptr<int> p = make_unique<int>(5);
      // an int is allocated an ownership goes into p

    int *q = p.get();
      // we get a non-owning raw pointer to the same int.

    global_ints.push_back(std::move(p));
      // we transfer ownership from p into global_ints;
    return q;
      // we return the non-owning pointer to the int
}

int main()
{
    int *q = f();
      // we get a non-owning pointer to the int that was created in f()

    cout << *q << "\n";
}

//notice that I did int *q = p.get() before transferring ownership
//Once we do global_ints.push_back(std::move(p));, p gives up ownership and becomes null


