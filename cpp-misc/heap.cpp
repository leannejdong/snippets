#include <iostream>
#include <string>

using std::cerr;

class Entity {
    public:
    Entity()
    {
        cerr << " Created Entity " << "\n";

    }

    ~Entity()
    {
        cerr << "Destroyed Entity " << "\n";
    }

};

int main()
{
    {
        Entity* e = new Entity;
    }
}

// heap-based variable don't get destroyed when we go out of scope)
// Need to call delete https://godbolt.org/z/eehETE
