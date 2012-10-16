#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define PHRASES 5

int main() {
  char *article[] = { "the", "a", "one", "some", "any" };
  char *noun[] = { "boy", "girl", "dog", "town", "car" };
  char *verb[] = { "drove", "jumped", "ran", "walked", "skip" };
  char *proposition[] = { "to", "from", "over", "under", "on" };
  char **arrays[] = { article, noun, verb, proposition };
  
  srand(time(NULL));

  char sentence[255] = "";
  int i, j, n;
  for(i = 0; i < PHRASES; ++i) {
    for(j = 0; j < 4; ++j) {
      n = rand() % PHRASES;
      strcat(sentence, arrays[j][n]);
      strcat(sentence, " ");
    }
    strcat(sentence, "\n");
  }
  
  sentence[strlen(sentence)-2] = '.';
  sentence[0] = toupper(sentence[0]);
  
  printf("   %s", sentence);
  
  return 0;
}
