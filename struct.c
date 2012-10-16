#include <stdio.h>

struct person {
  char *name;
  int age;
};

typedef struct {
  char *name;
  char *color;
} Car;
  
int main() {

  struct person p;
  p.name = "Giovanni";
  p.age  = 16;
  printf("Name: %s\nAge: %d\n\n", p.name, p.age);
  
  Car c;
  c.name  = "Audi";
  c.color = "Silver";
  printf("Name: %s\nColor: %s\n\n", c.name, c.color);
  
  return 0;
}
