#include <stdio.h>

// Alignment requirements
// 32 bit machine           64 bit machine

// char       1 byte           1 bytes
// short int  2 bytes          2 bytes
// int        4 bytes          4 bytes
// long       4 bytes          8 bytes
// double     8 bytes          8 bytes
// long long  8 bytes          8 bytes
// long double  16 bytes       16 bytes

// structure A
struct structa
{
    char    c;
    short int  s;
};

//The alignment requirements for A can be satisfied by adding one byte of padding between A::c and A::s 

/// structure B
struct structb
{
    short int  s;
    char    c;
    int     i;
};
//The alignment requirements for B can be satisfied by adding one byte of padding between B::c and B::i 

// structure C
struct structc
{
    char    c;
    double   d;
    int 	 s;
};
// The alighment requirements for C require adding 7 bytes padding between C::c and C::d
/* Put in another way, alignment requirement for C::d is 8
 C::c has a size of 1 byte
 So we need 7 more bytes after C::c so that C::d ends up on a 8-byte bdry*/

// structure D
struct structd
{
    double   d;
    int 	 s;
    char    c;
};

int main()
{
    printf("sizeof(structa_t) = %lu\n", sizeof(structa));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd));

    return 0;
}

