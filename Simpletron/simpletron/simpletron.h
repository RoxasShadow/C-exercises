#define MEMORY_SIZE 1000
#define SENTINEL    -99999

int getFileSize(FILE *file);
void dump(float memory[], float accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand);

int getFileSize(FILE *file) {
  fseek(file, 0L, SEEK_END);
  int size = ftell(file);
  rewind(file);
  return size;
}

void dump(float memory[], float accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand) {
  int i, j;
  printf("\tREGISTERS:\n");
  printf("\taccumulator\t\t%f\n", accumulator);
  printf("\tinstructionCounter\t\t%d\n", instructionCounter);
  printf("\tinstructionRegister\t\t%d\n", instructionRegister);
  printf("\toperationCode\t\t%d\n", operationCode);
  printf("\toperand\t\t%d\n\n", operand);
  
  printf("\tMEMORY:\n");
  for(i = 0; i < 10; ++i)
    printf("\t%d", i);
  printf("\n");
    
  for(i = 0; i < 10; ++i) {
    printf("%d\t", i);
    for(j = 0; j < 10; ++j)
      printf("%+.4d\t", (int)memory[i]);
    printf("\n");
  }
}
