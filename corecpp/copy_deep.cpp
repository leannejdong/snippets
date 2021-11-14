// Copying and Copy ctor, deep copy
#include <iostream>
#include <cstring>
#include <memory>
using std::cerr;


class String
{
    std::unique_ptr<char[]> m_Buffer;
    unsigned int m_Size;

    public:
    String(const char* string)
    {
        m_Size = std::strlen(string);
        cerr << "Calling new\n";
        m_Buffer.reset(new char[m_Size + 1]);
        memcpy(m_Buffer.get(), string, m_Size + 1);// strcpy includes the null termination character
        // m_Buffer[m_Size] = 0;
    }
    String(const String& other): /*m_Buffer(other.m_Buffer),*/ m_Size(other.m_Size){
        cerr << "Calling new\n";
        m_Buffer.reset(new char[m_Size + 1]);
        memcpy(m_Buffer.get(), other.m_Buffer.get(), m_Size + 1);
    }
    ~String()
    {
        cerr << "Calling delete\n";
        //delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer.get();
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

// https://compiler-explorer.com/z/v79PnKzYs
