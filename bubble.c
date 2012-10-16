#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SWAP(ary, i, j) \
  hold = ary[i];  \
  ary[i] = ary[j];  \
  ary[j] = hold;

void bubble(int ary[], int size, int ascendent);

int main(int argc, char *argv[]) {
  int ary[10];
  int size  = sizeof(ary) / sizeof(int);
  int i;
  
  srand(time(NULL));
  for(i = 0; i < size; ++i)
    ary[i] = rand() % 1000;
  
  if(argc != 2 || strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-d") != 0) {
    printf("Usage: %s [ -a | -d ]\n", argv[0]);
    return -1;
  }

  bubble(ary, size, !strcmp(argv[1], "-a"));
  
  for(i = 0; i < size; ++i)
    printf("%d ", ary[i]);
  printf("\n");
  
  return 0;
}

void bubble(int ary[], int size, int ascendent) {
  int i, j, hold;
  
  for(i = 0; i < size; ++i) {
    for(j = 0; j < size; ++j) {
      if(ascendent == 1) {
        if(ary[j] > ary[i]) {
          SWAP(ary, i, j);
        }
      }
      else {
        if(ary[j] < ary[i]) {
          SWAP(ary, i, j);
        }
      }
    }
  }
}
