#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define SEGFAULT  \
  int i = (int)strcat("You", "failed");

void fail(int fail) {
  fprintf(stderr, "Fail (#%d)\n", fail);
  exit(23);
}

int main() {
  signal(SIGSEGV, fail);
  
  SEGFAULT
  
  return 0;
}
