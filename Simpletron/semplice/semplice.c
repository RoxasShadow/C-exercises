#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "polish/polish.h"
#include "semplice.h"

int main(int argc, char *argv[]) {
  int memory[100];
  TableEntry symbolTable[100];
  int i = 0;
  
  int instructionCounter = 0;
  int location = 99;
  FILE *file;
  
  if((file = fopen(argv[1], "r")) == NULL) {
    printf("\t\t    *** Impossible to find or read the file ***\n");
    return -1;
  }
  else {
    int fileSize = getFileSize(file);
    
    char line[fileSize];
    TableEntry entry;
    char *tokenPtr;
    char opcode[4];
    int operation;
    
    while(!feof(file)) {
      fscanf(file, "%s", line);
      
      tokenPtr = strtok(line, " ");
      
      entry = { atoi(tokenPtr[0]), 'L', instructionCounter }; /* Line */
      symbolTable[instructionCounter] = entry;
      memory[instructionCounter] = entry.line;
      
      if(strcmp(tokenPtr[1], "rem"))
        continue;
      
      tokenPtr(NULL, " ");
      
      if(strcmp(tokenPtr[1], "input")) {
        entry = { (int)tokenPtr[2], 'V', location }; /* Variable */
        operation = 10; /* Input code */
        symbolTable[instructionCounter] = entry;
        memory[location] = entry.line;
      }
      
      int opcode = (operation * 100) + location;
      memory[instructionCounter++] = opcode;
      --location;
      
    }
    fclose(file);
  }
  
  return 0;
}
