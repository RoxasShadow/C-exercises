#include <stdio.h>

#define SIZE 11

int main() {
  size_t c   = sizeof(char);
  size_t uc  = sizeof(unsigned char);
  
  size_t si  = sizeof(short int);
  size_t usi = sizeof(unsigned short int);
  
  size_t i   = sizeof(int);
  size_t ui  = sizeof(unsigned int);
  size_t li  = sizeof(long int);
  size_t uli = sizeof(unsigned long int);
  
  size_t f   = sizeof(float);
  size_t d   = sizeof(double);
  size_t ld  = sizeof(long double);
  
  char *types[] = { "char", "unsigned char", "short int", "unsigned short int", "int", "unsigned int", "long int", "unsigned long int", "float", "double", "long double" };
  size_t datasizes[] = { c, uc, si, usi, i, ui, li, uli, f, d, ld };
  
  FILE *file;
  
  if((file = fopen("datasize.dat", "wb")) == NULL) {
    printf("Impossible to create 'datasize.dat'.\n");
  }
  else {
    fwrite(datasizes, SIZE * sizeof(size_t), 1, file);
    fclose(file);
  }
 
  if((file = fopen("datasize.dat", "r")) == NULL) {
    printf("Impossible to read 'datasize.dat'.");
  }
  else {
    fread(datasizes, sizeof(size_t), 1, file);
    printf("%-20s %-23s\n", "Data type", "Size");
    int j;
    for(j = 0; j < SIZE; ++j)
      printf("%-20s %-23i\n", types[j], datasizes[j]);
    fclose(file);
  }
  
  return 0;
}
