//an example where ownership goes somewhee else
#include <memory>
#include <vector>

using std::unique_ptr;
using std::make_unique;
using std::vector;

vector<unique_ptr<int>> global_ints;

void f()
{
    global_ints.push_back(make_unique<int>(5));
    // an int is allocated and ownership is put into the global_ints vector.
}

int main()
{
    f();
}
