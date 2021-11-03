#include <memory_resource>
#include <iostream>

int main()
{
    char buffer[20]{0};
    std::fill_n(std::begin(buffer), std::size(buffer)-1, 'E');
    std::cout << buffer << "\n";
    std::pmr::monotonic_buffer_resource memory(std::data(buffer), std::size(buffer));
    std::pmr::vector<char> vect{&memory};
    //vect.reserve(20);

    for(char c = 'a'; c <= 'e'; ++c){
        vect.emplace_back(c);
        std::cout << "After adding " << c << ": " << buffer << "\n";
        std::cout << "  capacity: " << vect.capacity() << "\n";
    }
}

/*
reserve changes the capacity of the vector (edited) 
if the vector has a large enough capacity then it doesn't have to reallocate (edited) 
without using reserve, the capacity starts at 0
when you try to add the first character, it increases the capacity to 1
when you try to add the 2nd character, it increases the capacity to 2 by allocating a new 2-byte buffer and copying what it had before adding the new character
it is allocating small buffers within the larger buffer
*/

