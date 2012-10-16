#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define OPERATORS { '*', '/', '%', '+', '-', '^' }

int  isOperator(char c);
int  precedence(char operator1, char operator2);
void convertToPostfix(char infix[], char postfix[]);
char *fillArray(char ary[], int length);
int  calculate(int op1, int op2, char operator);
int  evaluatePostfixExpression(char *expr);

/* Return true if the argument is an operator */
int isOperator(char c) {
  char op[] = OPERATORS;
  int i;
  
  for(i = 0; i < 5; ++i)
    if(c == op[i])
      return 1;
  
  return 0;
}

/* Return -1, 0 or 1 if the priority of operator1 is minor, equals or major of operator2 */
int precedence(char operator1, char operator2) {
  char op[] = OPERATORS;
  int o1 = -1;
  int o2 = -1;
  int i;
  
  for(i = 0; i < 5; ++i) {
    if(operator1 == op[i])
      o1 = i;
    if(operator2 == op[i])
      o2 = i;
  }
  
  if(o1 == -1 || o2 == -1)
    return -1;
  else if(o1 < o2)
    return 1;
  else if(o1 == o2)
    return 0;
  else
    return -1;
}

/* Convert infix notation to polish notation */
void convertToPostfix(char infix[], char postfix[]) {
  StackNodePtr stackPtr = NULL;
  int j = 0;
  int i = 0;
  
  push(&stackPtr, '(');
  strcat(infix, ")");
  
  while(!isEmpty(stackPtr)) {
  
    if(isdigit(infix[i])) {
      postfix[j++] = infix[i];
    }
      
    else if(infix[i] == '(') {
      push(&stackPtr, '(');
    }
      
    else if(isOperator(infix[i])) {
      char op = stackTop(&stackPtr);
      int prec;
      while( (prec = precedence(op, infix[i])) >= 0) {
        if(isOperator(op)) {
          postfix[j++] = op;
        }
        pop(&stackPtr);
        op = stackTop(&stackPtr);
      }
      push(&stackPtr, infix[i]);
    }
    
    else if(infix[i] == ')') {
      char op;
      while( (op = stackTop(&stackPtr)) != '(') {
        if(isOperator(op)) {
          postfix[j++] = op;
        }
        pop(&stackPtr);
      }
      pop(&stackPtr);
    }
    
    ++i;
    
  }
  
  infix[i-1] = 0;
  
}

/* Compact an array and separe with a space each element */
char *fillArray(char ary[], int length) {
  int i, j;
  char *filled = malloc(length * sizeof(char));
  
  for(i = 0, j = 0; i < length; ++i) {
    if(ary[i] != 0) {
      filled[j++] = ary[i];
      filled[j++] = ' ';
    }
  }
  
  return filled;
}

/* math.h's pow() won't work here... */
int _pow(int op1, int op2) {
  int i, p;
  for(i = 0, p = 1; i < op2; ++i)
    p *= op1;
  return p;
}

/* Calculate the value of the expression op1 operator op2 */
int calculate(int op1, int op2, char operator) {
  switch(operator) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    case '^':
      return _pow(op1, op2);
    case '%':
      return op1 % op2;
    default:
      return -1;
  }
}

/* Evaluate the expression in polish notation */
int evaluatePostfixExpression(char *expr) {
  StackNodePtr stackPtr = NULL;
  int i;
  
  for(i = 0; expr[i] != '\0'; ++i) {
    if(isdigit(expr[i])) {
      push(&stackPtr, atoi(&expr[i]));
    }
    else if(isOperator(expr[i])) {
      int x = (int)pop(&stackPtr);
      int y = (int)pop(&stackPtr);
      int res = (expr[i] == '/' || expr[i] == '-') ? calculate(y, x, expr[i]) : calculate(x, y, expr[i]);
      push(&stackPtr, (char)res);
    }
  }
  
  return (int)pop(&stackPtr);
}

int main(int argc, char *argv[]) {
  //char infix[] = "(6 + 2) * 5 - 8 / 4";
  char infix[] = "2 ^ 4";
  int length = strlen(infix);
  
  char *postfix = malloc(length * sizeof(char));
  convertToPostfix(infix, postfix);
  
  char *filledPostfix = fillArray(postfix, length);
  int result = evaluatePostfixExpression(filledPostfix);
  
  printf("Infix: %s\nPostfix: %s\nResult: %d\n", infix, filledPostfix, result);
  
  free(filledPostfix);
  free(postfix);
  
  return 0;
}
