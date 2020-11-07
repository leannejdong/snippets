#include <iostream>

using std::cout;


int main()
{
    const unsigned short redMask   = 0b1111100000000000; // 0xF800;
    const unsigned short greenMask = 0b0000011111100000; // 0x07E0;
    const unsigned short blueMask  = 0b0000000000011111; // 0x001F;
    unsigned short lightGray =       0b0111101111101111; // 0x7BEF;
    unsigned short redComponent   = (lightGray & redMasak) >> 11;
    unsigned short greenComponent = (lightGray & greenMask) >> 5;
    unsigned short blueComponent =  (lightGray & blueMask);

    cout << "redComponent:   " << redComponent << "\n";   // 15 = 0b01111;
    cout << "greenComponent: " << greenComponent << "\n"; // 31 = 0b011111;
    cout << "blueComponent:  " << blueComponent << "\n";  // 15 = 0b01111;
}
