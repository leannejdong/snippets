#include <stdlib.h>
#include <stdio.h>

void bar(){
    int* p = NULL;
    p = malloc(sizeof(int));
    *p = 42;
    free(p);
}

void foo(){
    bar();
}

int main()
{
    foo();
    return 0;
}
