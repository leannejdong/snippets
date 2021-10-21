#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 4
int main (){
        omp_set_num_threads(NUM_THREADS);
        int x;//shared variable
        #pragma omp parallel for
        for (int i=0;i<10000; i++)
                x+= 10; //data race
        printf("\n value of x: %d", x);
}
