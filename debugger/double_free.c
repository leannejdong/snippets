#include <malloc.h>

int use_and_free(int *p)
{
  int result = *p;
  free(p);
}

int main()
{
  const int num_pointers = 2;
  int *p[num_pointers];

  for(int j = 0; j < num_pointers; j++){
    p[j] = malloc(sizeof(int));
    *p[j] = j;
  }
  int sum = 0;

  for(int j = 0; j < num_pointers; j++){
    sum += use_and_free(p[j]);
  }
  free(p[0]);

  return sum;
}
//gcc -g double_free.c -fsanitize=address && ./a.out
