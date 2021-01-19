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
    {
        // ScopedPtr e = new Entity();
        // std::cerr << "now try unique_ptr " << "\n";
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();

    }
}
