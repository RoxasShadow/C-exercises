#include <stdio.h>

int main() {
  int i = 0;
  int end = 0;
  
  horizontal:
    printf("*");
    ++i;
    
    if(i < 5) {
      goto horizontal;
    }
    else {
      if(end == 0) {
        printf("\n");
        i = 0;
      }
      else {
        goto end;
      }
    }
      
  vertical:
    printf("*");
    printf(" ");
    printf(" ");
    printf(" ");
    printf("*");
    printf("\n");
    ++i;
    
    if(i < 3) {
      goto vertical;
    }
    else {
      i = 0;
      end = 1;
      goto horizontal;
    }
    
  end:
    printf("\n");
    
  return 0;
}
