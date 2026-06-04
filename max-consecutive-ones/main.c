#include <stdio.h>
#include <stdlib.h>

int findMaxConsecutiveOnes(int *nums, int numsSize) {
  int result = 0;
  int c = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == 0) {
      result = c > result ? c : result;
      c = 0;
    } else {
      c++;
    }
  }
  result = result < c ? c : result;
  return result;
}

int main() {
  int nums1[6] = {1, 1, 0, 1, 1, 1}; // 3
  int nums2[6] = {1, 0, 1, 1, 0, 1}; // 2
  printf("%d\n", findMaxConsecutiveOnes(nums1, 6));
  printf("%d\n", findMaxConsecutiveOnes(nums2, 6));
  return EXIT_SUCCESS;
}