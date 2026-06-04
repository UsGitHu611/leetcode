#include <stdio.h>
#include <stdlib.h>

int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize) {
  int *result = (int *)malloc(numsSize * sizeof(*nums));
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; ++i) {
    int c = 0;
    for (int j = 0; j < numsSize; ++j) {
      if (nums[i] > nums[j] && i != j) {
        c++;
      }
    }
    result[i] = c;
  }
  return result;
}

int main() {
  int nums[5] = {8, 1, 2, 2, 3};
  int returnSize = 0;
  int *result = smallerNumbersThanCurrent(nums, 5, &returnSize);
  for (int i = 0; i < 5; ++i) {
    printf("%d\n", result[i]);
  }
  free(result);
  result = NULL;
  return EXIT_SUCCESS;
}