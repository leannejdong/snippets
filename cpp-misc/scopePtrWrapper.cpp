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

class ScopedPtr {
    private:
    Entity* m_Ptr;

    public:
    ScopedPtr(Entity* Ptr)
        : m_Ptr(Ptr)
        {}

    ~ScopedPtr()
    {
        delete m_Ptr;
    }

};

int main()
{
    {
        ScopedPtr e = new Entity();
    }
}

// a scope pointer wrapper helps automatically delete 
// https://godbolt.org/z/3Gj3oP
