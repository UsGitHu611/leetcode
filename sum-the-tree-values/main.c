#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int value;
  struct node *left;
  struct node *right;
};

int sumTheTreeValues(const struct node *root) {
  if (root == NULL) {
    return 0;
  }
  return root->value + sumTheTreeValues(root->left) +
         sumTheTreeValues(root->right);
}

int main(void) {
  printf("%d\n",
         sumTheTreeValues(&(struct node){
             .value = 10,
             .left = &(struct node){.value = 1, .left = NULL, .right = NULL},
             .right = &(struct node){.value = 2, .left = NULL, .right = NULL},
         })); // 13
  return EXIT_SUCCESS;
}