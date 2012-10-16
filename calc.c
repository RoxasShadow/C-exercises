#include <stdio.h>

double sum(double a, double b);
double sub(double a, double b);

int main() {
  double (*f[2])(double, double) = { sum, sub };
  
  int choice, a, b;
  printf("Sum => 1\nSubtraction => 2\nYour choice: ");
  scanf("%d", &choice);
  choice -= 1;
  
  printf("a: ");
  scanf("%d", &a);
  printf("b: ");
  scanf("%d", &b);
  
  printf("%.2f\n", (*f[choice])(a, b));
  
  return 0;
}

double sum(double a, double b) {
  return a + b;
}

double sub(double a, double b) {
  return a - b;
}
