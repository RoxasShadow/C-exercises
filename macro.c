#include <stdio.h>

#define PI  3.14159

#define CALC(r) \
  (4 / 3) * PI * (r) * (r) * (r)
  
#define SUMARRAY(ary, size) \
  for(i = 0; i < size; ++i) \
    sum += ary[i];

int main() {
  int i;
  int sum = 0;
  int ary[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int size = sizeof(ary) / sizeof(int);
  
  for(i = 1; i < 11; ++i)
    printf("Raggio %d: %f\n", i, CALC(i));
  printf("\n");
  
  printf("Values: ");
  for(i = 0; i < size; ++i)
    printf("%d ", ary[i]);
  printf("\n");
    
  SUMARRAY(ary, size);
  printf("Sum of the %d elements: %d\n", size, sum);
    
  return 0;
}
