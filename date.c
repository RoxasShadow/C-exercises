#include <stdio.h>
#include <string.h>

#define DATE "21/07/55"
#define MILLENNIUM 1900

int main() {
  char s[] = DATE;
  char so[] = DATE;
  char date[3];
  char *months[] = { "gen", "feb", "mar", "apr", "mag", "giu", "lug", "ago", "set", "ott", "nov", "dic" };
  
  char *token = strtok(s, "/");
  int i;
  for(i = 0; i < 3; ++i) {
    date[i] = atoi(token);
    token = strtok(NULL, "/");
  }
  
  int day = date[0];
  char *month = months[--date[1]];
  int year = date[2] + MILLENNIUM; 
  
  printf("%s => %d %s %d\n", so, day, month, year);
    
  return 0;
}
