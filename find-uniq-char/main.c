#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char *s) {
  int c = strlen(s);
  int *freq = (int *)calloc(256, sizeof(int));
  if (freq == NULL) {
    printf("FAIL\n");
    return -1;
  }
  for (int i = 0; i < c; ++i) {
    freq[(unsigned char)s[i]]++;
  }
  for (int i = 0; i < c; ++i) {
    if (freq[(unsigned char)s[i]] == 1) {
      free(freq);
      freq = NULL;
      return i;
    }
  }
  free(freq);
  freq = NULL;
  return -1;
}

int main() {
  printf("%d\n", firstUniqChar("leetcode"));     // 0
  printf("%d\n", firstUniqChar("loveleetcode")); // 2
  printf("%d\n", firstUniqChar("aabb"));         // -1
  return EXIT_SUCCESS;
}
