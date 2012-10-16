#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opcodes.h"
#include "simpletron.h"

int main(int argc, char *argv[]) {
  float *memory;
  int i = 0;
  
  if(argc != 2) {    
    printf("\t\t*** Welcome to Simpletron! ***\n");
    printf("\t\t*** Please enter your program one instruction ***\n");
    printf("\t\t*** (or data word) at a time. I will type the ***\n");
    printf("\t\t*** location number and a question mark (?).  ***\n");
    printf("\t\t*** You then type the word for that location. ***\n");
    printf("\t\t*** Type the sentinel %d to stop entering ***\n", SENTINEL);
    printf("\t\t*** your program. ***\n\n");
  
    if( (memory = malloc(MEMORY_SIZE * sizeof(char))) == NULL) {
      fprintf(stderr, "Impossible to allocate the memory.\n");
      return -1;
    }
    
    int sentinel;
    while(1) {
      printf("%.2d ? ", i);
      scanf("%d", &sentinel);
      
      if(sentinel == SENTINEL)
        break;
      
      if( sentinel == +0000 || (sentinel < 4301 && sentinel > 999) ) {
        memory[i++] = sentinel;
      }
      else {
        printf("\t\t\t\t*** Invalid opcode ***\n");
        printf("\t\t    *** Simpletron execution abnormally terminated ***\n");
        return -1;
      }
    }
  }
  else {
    FILE *file;
    
    if((file = fopen(argv[1], "r")) == NULL) {
      printf("\t\t    *** Impossible to find or read the file ***\n");
      return -1;
    }
    else {
      int fileSize = getFileSize(file);
      
      if( (memory = malloc(fileSize * sizeof(char))) == NULL) {
        fprintf(stderr, "Impossible to allocate the memory.\n");
        return -1;
      }
      
      char line[fileSize];
      float fLine;
      
      while(!feof(file)) {
        fscanf(file, "%s", line);
        
        fLine = atof(line);
        
        if(fLine == SENTINEL)
          break;
        
        if(!( fLine == +0000 || (fLine < 4301 && fLine > 999) )) {
          printf("\t\t\t\t*** Invalid opcode in in line #%d ***\n", i);
          printf("\t\t    *** Simpletron execution abnormally terminated ***\n");
          return -1;
        }
        
        if(i + 1 > fileSize) {
          fprintf(stderr, "Size of memory reached.\n");
          return -1;
        }
        
        memory[i++] = fLine;
      }
      fclose(file);
    }
  }
  
  float accumulator       = +0000;  /* Registro accumulatore */
  int instructionRegister =  00;    /* Load */
  int instructionCounter  = +0000;  /* Indirizzo dell'istruzione da eseguire */
  int operationCode       =  00;    /* Operazione da eseguire (prime due cifre) */
  int operand             =  00;    /* Locazione di memorie in cui opererà l'istruzione (ultime due cifre) */
  
  while(operationCode != HALT) {
    instructionRegister = memory[instructionCounter];
    operationCode       = instructionRegister / 100;
    operand             = instructionRegister % 100;
    
    switch(operationCode) {
      case READ:
        printf("Input: ");
        scanf("%f", &memory[operand]);
        break;
      case WRITE:
        printf("Output: %f\n", memory[operand]);
        break;
      case NEWLINE:
        printf("\n");
        break;
      case TAB:
        printf("\t");
        break;
      case LOAD:
        accumulator = memory[operand];
        break;
      case STORE:
        memory[operand] = accumulator;
        break;
      case ADD:
        accumulator += memory[operand];
        break;
      case SUBTRACT:
        accumulator -= memory[operand];
        break;
      case DIVIDE:
        if(memory[operand] == 0) {
          printf("\t\t*** Attempt to divide by zero ***\n");
          printf("\t\t*** Simpletron execution abnormally terminated ***\n");
          dump(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
          operationCode = HALT;
          break;
        }
        accumulator /= memory[operand];
        break;
      case MULTIPLY:
        accumulator *= memory[operand];
        break;
      case MODULE:
        /*accumulator %= memory[operand];*/
        break;
      case POWER:
        accumulator *= accumulator;
        break;
      case BRANCH:
        instructionCounter = operand;
        --instructionCounter;
        break;
      case BRANCHNEG:
        if(accumulator < 0) {
          instructionCounter = operand;
          --instructionCounter;
        }
        break;
      case BRANCHZERO:
        if(accumulator == 0) {
          instructionCounter = operand;
          --instructionCounter;
        }
        break;
      case HALT:
        printf("\t\t*** Simpletron execution terminated ***\n");
        break;
      default:
        printf("\t\t*** Instruction '%+.4d` is not a valid opcode.  ***\n", operationCode);
        printf("\t\t*** Simpletron execution abnormally terminated ***\n");
        dump(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
        operationCode = HALT;
    }
    ++instructionCounter;
  }
  
  free(memory);
  return 0;
}
