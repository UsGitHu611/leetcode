#include <stdio.h>
#include <stdlib.h>

int *shuffle(int *nums, int numsSize, int n, int *returnSize) {
  int *result = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < n; ++i) {
    result[2 * i] = nums[i];
    result[2 * i + 1] = nums[i + n];
  }
  *returnSize = numsSize;
  return result;
}

int main() {
  int array[6] = {2, 5, 1, 3, 4, 7};
  int returnSize = 0;
  int *result = shuffle(array, 6, 3, &returnSize);

  printf("returnSize = %d\n", returnSize);
  for (int i = 0; i < 6; ++i) {
    printf("%d\n", result[i]);
  }

  free(result);
  result = NULL;
  return EXIT_SUCCESS;
}
