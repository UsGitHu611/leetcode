#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char *s) {
  int i = strlen(s);
  while (i > 0 && s[i - 1] == ' ') {
    i--;
  }
  int end = i;
  while (i > 0 && s[i - 1] != ' ') {
    i--;
  }
  return end - i;
}

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {
  printf("%d\n", lengthOfLastWord("Hello World"));                 // 5
  printf("%d\n", lengthOfLastWord("   fly me   to   the moon  ")); // 4
  printf("%d\n", lengthOfLastWord("luffy is still joyboy"));       // 6
  return EXIT_SUCCESS;
}