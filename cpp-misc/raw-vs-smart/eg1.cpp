
//using a unique_ptr would be appropriate to express that the ownership 
//is being transferred back to the caller
#include <memory>

using std::unique_ptr;
using std::make_unique;

unique_ptr<int> f()
{
    return make_unique<int>(5); // an int is allocated, and ownership
                                // passes back to the caller.
}

int main()
{
    unique_ptr<int> p = f(); // the main function receives ownership of
                             // the int.
}
