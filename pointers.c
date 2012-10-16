#include <stdio.h>

int main() {

  int n = 5;
  int *nPtr = &n;
  
  printf("%d\n", n);
  printf("%p\n", &n);
  
  printf("%p\n", &nPtr);
  printf("%d\n", *nPtr);
  
  printf("\t-------------------\n");
  
  int arr[5] = { 1, 2, 3, 4, 5 };
  printf("%d\n", sizeof(arr));
  printf("%d\n", sizeof(int));
  printf("%d\n", sizeof(arr) / sizeof(int));
  
  printf("%d, %d", 1==1, 1==2);
  return 0;
}
