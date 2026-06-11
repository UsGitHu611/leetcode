#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char **buildArray(int *target, int targetSize, int n, int *returnSize) {
  int maxOps = 2 * target[targetSize - 1];
  char **result = (char **)malloc(maxOps * sizeof(char *));
  if (result == NULL) {
    return NULL;
  }
  for (int i = 0; i < maxOps; ++i) {
    result[i] = (char *)malloc(5 * sizeof(char));
  }
  int targetIdx = 0;
  int currentNum = 1;
  int opsCount = 0;
  while (targetIdx < targetSize) {
    if (currentNum == target[targetIdx]) {
      result[opsCount] = "Push";
      opsCount++;
      targetIdx++;
    } else {
      result[opsCount] = "Push";
      result[opsCount + 1] = "Pop";
      opsCount += 2;
    }
    currentNum++;
  }
  *returnSize = opsCount;
  return result;
}

int main() {
  int target[2] = {1, 3};
  int returnSize = 0;
  char **result = buildArray(target, 2, 3, &returnSize);
  for (int i = 0; i < returnSize; ++i) {
    printf("%s\n", result[i]);
  }
  free(result);
  result = NULL;
  return EXIT_SUCCESS;
}
