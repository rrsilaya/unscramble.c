#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/avl.h"
#include "utils/permutation.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Wrong input: ./unscramble.exe <characters> <template>\n");

    return 1;
  } else {
    // permutation(argv[1]);
    WORD *root = NULL;

    insertNode(&root, "earned");
    insertNode(&root, "beast");
    insertNode(&root, "arrival");
    insertNode(&root, "fun");
    insertNode(&root, "card");
    insertNode(&root, "reader");

    viewTree(root, 0);
    deleteTree(&root);
    return 0;
  }
}
