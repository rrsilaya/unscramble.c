#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/avl.h"
#include "utils/permutation.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Wrong input\n");

    return 1;
  } else {
    // permutation(argv[1]);
    WORD *root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 2);
    insertNode(&root, 1);
    insertNode(&root, 6);
    insertNode(&root, 3);

    viewTree(root, 1);
    return 0;
  }
}
