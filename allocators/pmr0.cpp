#include <memory_resource>
#include <iostream>

int main()
{
    char buffer[20]{0};
    std::fill_n(std::begin(buffer), std::size(buffer)-1, 'E');
    std::cout << buffer << "\n";
    std::pmr::monotonic_buffer_resource memory(std::data(buffer), std::size(buffer));
    std::pmr::vector<char> vect{&memory};
    //chars.reserve(20);

    for(char c = 'a'; c <= 'e'; ++c){
        vect.emplace_back(c);
    }
    std::cout << buffer;
    // the vector grows, as it grows it copies memory to different locations, since the different locations
    // are in the buffer. We will just see this being multiply over over again.

}

//EEEEEEEEEEEEEEEEEEE
//aababcdabcdeEEEEEEE

