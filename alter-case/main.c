#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_alternating_case(const char *s, int *returnSize) {
  int len = 0;
  while (s[len++] != '\0')
    ;
  len--;
  char *result = (char *)malloc((len + 1) * sizeof(char));
  if (result == NULL) {
    *returnSize = 0;
    return NULL;
  }
  for (int i = 0; i < len; ++i) {
    if (s[i] >= 65 && s[i] <= 90) {
      result[i] = s[i] + 32;
    } else if (s[i] >= 97 && s[i] <= 122) {
      result[i] = s[i] - 32;
    } else {
      result[i] = s[i];
    }
  }
  result[len] = '\0';
  *returnSize = len;
  return result;
}

int main() {
  int returnSize = 0;
  char *result = to_alternating_case("HeLLo WoRLD", &returnSize); // hEllO wOrld
  for (int i = 0; i < returnSize; ++i) {
    printf("%c\n", result[i]);
  }
  free(result);
  result = NULL;
  return EXIT_SUCCESS;
}