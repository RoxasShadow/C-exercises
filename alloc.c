#include <stdio.h>
#include <stdlib.h>

#define PRINT_ARRAY print(ary, size);

void print(int ary[], int size);

int main() {
  int i, size, *ary;
  
  printf("Array size: ");
  scanf("%d", &size);
  
  ary = malloc(size * sizeof(int));
  
  for(i = 0; i < size; ++i) {
    printf("#%d value: ", i);
    scanf("%d", &ary[i]);
  }
  
  PRINT_ARRAY
  
  size /= 2;
  ary = realloc(ary, size * sizeof(int));
  printf("Array size is now %i\n", size);
  
  PRINT_ARRAY
  
  free(ary);
    
  return 0;
}

void print(int ary[], int size) {
  int i;
  printf("Values: ");
  for(i = 0; i < size; ++i)
    printf("%d ", ary[i]);
  printf("\n");
}
