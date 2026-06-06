#include <stdio.h>
#include <stdlib.h>

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize) {
  int *result_pair = (int *)malloc(numsSize * sizeof(*nums));
  int *f_nums = (int *)calloc(numsSize + 1, sizeof(*nums));
  if (result_pair == NULL || f_nums == NULL) {
    return NULL;
  }
  for (int i = 0; i < numsSize; ++i) {
    f_nums[nums[i]]++;
  }
  int count = 0;
  for (int i = 1; i <= numsSize; ++i) {
    if (f_nums[i] == 0) {
      result_pair[count] = i;
      count++;
    }
  }
  *returnSize = count;
  free(f_nums);
  f_nums = NULL;
  return result_pair;
}

int main() {
  int nums[8] = {4, 3, 2, 7, 8, 2, 3, 1};
  int returnSize = 0;
  int *result = findDisappearedNumbers(nums, 8, &returnSize);
  for (int i = 0; i < returnSize; ++i) {
    printf("%d\n", result[i]);
  }
  free(result);
  result = NULL;
  return EXIT_SUCCESS;
}