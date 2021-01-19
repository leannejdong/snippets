#include <iostream>
#include <string>
#include <memory>

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
    std::shared_ptr<Entity> ptr1 = std::make_shared<Entity>();
    {
        std::shared_ptr<Entity> ptr2 = ptr1;
        cerr << "Leaving inner scope\n";
    }

    cerr << "Leaving outer scope\n";
}

// We have two shared pointers that are destroyed at different times
// that are pointing to the same object
// The two shared ptrs are local vars. That means they are destroyed 
// when they leave their scope. Since they are in different scopes, 
// they are destroyed at different times.
