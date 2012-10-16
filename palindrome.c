#include <stdio.h>
#define SIZE 5

int strEquals(char string1[], char string2[], int length);
int testPalindrome(const char string[], char palindrome[], int start, int end);

int main() {
  char string[] = "radar";
  char palindrome[SIZE];
  
  printf("%d", testPalindrome(string, palindrome, 0, SIZE-1));
  
  return 0;
}

int testPalindrome(const char string[], char palindrome[], int start, int end) {
  palindrome[start] = string[end];
  if(end > 0)
    testPalindrome(string, palindrome, start+1, end-1);
  else
    return strEquals(string,  palindrome, SIZE);
}

int strEquals(char string1[], char string2[], int length) {
  int i;
  for(i = 0; i < length; ++i)
    if(string1[i] != string2[i])
      return 0;
  return 1;
}
