#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { 
  return (*(int *)a - *(int *)b);
}

int arrayPairSum(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(*nums), compare);
  int result = 0;
  for (int i = 0; i < numsSize; i += 2) {
    result += nums[i];
  }
  return result;
}

int main(int argc, [[maybe_unused]] char *argv[argc + 1]) {
  int arr1[4] = {1, 4, 3, 2};
  int arr2[6] = {6, 2, 6, 5, 1, 2};
  printf("%d\n", arrayPairSum(arr1, 4));
  printf("%d\n", arrayPairSum(arr2, 6));
  return EXIT_SUCCESS;
}