struct stackNode {
  char data;
  struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char data); /*  Append a char to the stack          */
char pop(StackNodePtr *topPtr);             /*  Get and remove a char by the stack  */
char stackTop(StackNodePtr *topPtr);        /*  Get a char by the stack             */
int  isEmpty(StackNodePtr topPtr);          /*  Return true if the stack is empty   */
void printStack(StackNodePtr currentPtr);   /*  Print the stack to stdout           */

void push(StackNodePtr *topPtr, char data) {
  StackNodePtr newPtr = malloc(sizeof(StackNode));
  if(newPtr != NULL) {
    newPtr->data = data;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
  }
  else {
    fprintf(stderr, "No memory available to insert '%c'.\n", data);
  }
}

char pop(StackNodePtr *topPtr) {
  StackNodePtr tempPtr = *topPtr;
  char popdata = (*topPtr)->data;
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);
  return popdata;
}

char stackTop(StackNodePtr *topPtr) {
  return (*topPtr)->data;
}

int isEmpty(StackNodePtr topPtr) {
  return topPtr == NULL;
}

void printStack(StackNodePtr currentPtr) {
  if(currentPtr == NULL) {
    fprintf(stderr, "The stack is empty.\n\n");
  }
  else {
    printf("The stack is:\n");
    while(currentPtr != NULL) {
      printf("%c ---> ", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }
    printf("NULL\n");
  }
}
