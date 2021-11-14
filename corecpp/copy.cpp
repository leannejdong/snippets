// Copying and Copy ctor 
#include <iostream>
#include <cstring>
using std::cerr;


class String
{
    char* m_Buffer;
    unsigned int m_Size;

    public:
    String(const char* string)
    {
        m_Size = std::strlen(string);
        cerr << "Calling new\n";
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size + 1);// strcpy includes the null termination character
        m_Buffer[m_Size] = 0;
    }
    String(const String& other): /*m_Buffer(other.m_Buffer),*/ m_Size(other.m_Size){
        cerr << "Calling new\n";
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }
    ~String()
    {
        cerr << "Calling delete\n";
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    String string = "levynoise";
    String second = string;
    second[0] = 'L'; second[4] = 'N';
    std::cout << string << "\n";

    std::cout << second << "\n";
}
