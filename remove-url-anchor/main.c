#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_url_anchor(const char *url_in) {
  int index = -1;
  int len = strlen(url_in);
  for (int i = len; i > 0; --i) {
    if (url_in[i] == '#') {
      index = i;
      break;
    }
  }
  if (index != -1) {
    char *result = malloc((index + 1) * sizeof(char));
    if (result == NULL) {
      return NULL;
    }
    strncpy(result, url_in, index);
    result[index] = '\0';
    return result;
  }
  char *result = malloc((len + 1) * sizeof(char));
  if (result == NULL) {
    return NULL;
  }
  strncpy(result, url_in, len);
  result[len] = '\0';
  return result;
}

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {
  printf("%s\n", remove_url_anchor("www.codewars.com#about"));
  printf("%s\n", remove_url_anchor("www.codewars.com?page=1"));

  return EXIT_SUCCESS;
}