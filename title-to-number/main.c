#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char *columnTitle) {
  int result = 0;
  int len = strlen(columnTitle);
  for (int i = 0; i < len; ++i) {
    result += (columnTitle[i] - 64) * pow(26, len - 1 - i);
  }
  return result;
}

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {
  printf("%d\n", titleToNumber("A"));  // 1
  printf("%d\n", titleToNumber("AB")); // 28
  printf("%d\n", titleToNumber("ZY")); // 701
  return EXIT_SUCCESS;
}