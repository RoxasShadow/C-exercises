#include <stdio.h>

#define DEBUG( ... )  \
  printf( __FILE__ ": " __VA_ARGS__ )

int main() {
  int i, size;
  
  printf("Number of values: ");
  scanf("%d", &size);
  
  int ary[size];
  
  for(i = 0; i < size; ++i) {
    printf("Value: ");
    scanf("%d", &ary[i]);
  }
  
  printf("Values: ");
  for(i = 0; i < size; ++i) {
    printf("%d ", ary[i]);
  }
  printf("\n");
  
  DEBUG("ary[size] = %d\n", sizeof(ary) / sizeof(int));
  
  return 0;
}
