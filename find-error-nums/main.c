#include <stdio.h>
#include <stdlib.h>

int *findErrorNums(int *nums, int numsSize, int *returnSize) {
  int *result = (int *)malloc(2 * sizeof(int));
  int *counts = (int *)calloc(numsSize + 1, sizeof(int));
  *returnSize = 2;
  for (int i = 0; i < numsSize; i++) {
    counts[nums[i]]++;
  }
  for (int i = 1; i <= numsSize; i++) {
    if (counts[i] == 2) {
      result[0] = i;
    } else if (counts[i] == 0) {
      result[1] = i;
    }
  }
  free(counts);
  counts = NULL;
  return result;
}

int main() {
  int array1[4] = {1, 2, 2, 4};
  int returnSize = 0;
  int *result = findErrorNums(array1, 4, &returnSize); // [2,3]
  printf("[");
  for (int i = 0; i < 2; ++i) {
    if (i < 1) {
      printf("%d, ", result[i]);
    } else {
      printf("%d", result[i]);
    }
  }
  printf("]\n");

  free(result);
  result = NULL;
  return EXIT_SUCCESS;
}