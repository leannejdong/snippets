// Move semantic
#include <iostream>
#include <cstring>
#include <memory>
using std::cerr;
class String
{
    public:
    //std::shared_ptr<char []> m_Data{new char[m_Size]};
    String() = default;
    String(const char* string){
        cerr << "Created!\n";
        m_Size = std::strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    String(const String& other){
        cerr << "Copied!\n";
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    String(String&& other) noexcept
    {   cerr << "Moved!\n";
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        //memcpy(m_Data, other.m_Data, m_Size);
        other.m_Size = 0;
        other.m_Data = nullptr;
// this is a shallow copy
    }
    String& operator=(String&& other) noexcept
    {   cerr << "Moved!\n";
        if(this != &other){
          delete[] m_Data;// delete our current data as we moving another object into ourselves. Then we can reassign all our variables.
          m_Size = other.m_Size;
          m_Data = other.m_Data;
          //memcpy(m_Data, other.m_Data, m_Size);
          other.m_Size = 0;
          other.m_Data = nullptr;
          // this is a shallow copy
        }
    }



    ~String()
    {
        cerr << "deleted!\n";
        delete[] m_Data;
    }

    void Print()
    {
        for(uint32_t i{0}; i < m_Size; ++i){
            cerr << m_Data[i] << "";
        }
        cerr << "\n";
    }

    private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity
{
    public:
    Entity(const String& name) : m_Name(name){}
    Entity(const String&& name) : m_Name(std::move(name)){}

    void PrintName()
    {
        m_Name.Print();
    }
    private:
    String m_Name;
};

int main()
{
    Entity entity(String("Leanne"));
    entity.PrintName();
    
    String apple = "Apple";
    String dest;

    apple.Print();
    dest.Print();

    dest = std::move(apple);
    apple.Print();
    dest.Print();

//    String string = "Hello";
//    String dest(std::move(string));
//
}
