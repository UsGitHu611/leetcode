#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getConcatenation(int *nums, int numsSize, int *ret_size) {
  int *result = malloc(numsSize * 2 * sizeof(int));
  if (result == NULL) {
    return NULL;
  }
  memcpy(result, nums, numsSize * sizeof(int));
  memcpy(result + numsSize, nums, numsSize * sizeof(int));
  *ret_size = numsSize * 2;
  return result;
}

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {
  int arr1[3] = {1, 2, 1};
  int size_arr = 0;
  int *res = getConcatenation(arr1, 3, &size_arr);
  if (res == NULL) {
    fprintf(stderr, "Ошибка выделения памяти\n");
    return EXIT_FAILURE;
  }
  printf("size arr = %d\n", size_arr);

  printf("[");
  for (int i = 0; i < 6; ++i) {
    if (i < 5) {
      printf("%d, ", res[i]);
    } else {
      printf("%d", res[i]);
    }
  }
  printf("]\n");

  free(res);
  res = NULL;

  return EXIT_SUCCESS;
}