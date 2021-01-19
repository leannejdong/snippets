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
        Entity e;
    }
}

//the stack-based variable gets destroy soon we go out of scope)
