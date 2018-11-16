#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utils/misc.h"
#include "utils/avl.h"
#include "utils/permutation.h"
#include "utils/checker.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Wrong input: ./unscramble.exe <characters> <template>\n");

    return 1;
  } else {
    WORD *solutions = NULL;
    WORD *dictionary = NULL;

    permutation(toLowerCase(argv[1]), toLowerCase(argv[2]), &solutions);
    loadFile(&dictionary);
    searchDict(solutions, dictionary);
    return 0;
  }
}
