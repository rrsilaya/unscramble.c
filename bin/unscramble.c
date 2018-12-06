#define MAX_WORD_SIZE 60

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

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
    clock_t startTime = clock(), currentTime;

    permutation(argv[1], argv[2]);

    currentTime = clock() - startTime;
    printf("[TIME] Finished in %ims\n", currentTime * 1000 / CLOCKS_PER_SEC);

    return 0;
  }
}