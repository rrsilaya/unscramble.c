void permutation(char *letters) {
  int len = strlen(letters);

  char *nopts = (char *) malloc(sizeof(char) * (len + 2));
  char **option = (char **) malloc(sizeof(char*) * (len + 2));
  for (int i = 0; i < len + 2; i++) option[i] = (char *) malloc(sizeof(char) * (len + 2));

  int start, move, i, candidate;

  move = start = 0;
  nopts[start] = 1;

  while (nopts[start] > 0) {
    if (nopts[move] > 0) {
      nopts[++move] = 0;

      // Print a solution
      if (move > len) {
        // @TODO: Modify this code to add the answer to an AVL tree.
        for (i = 1; i < move; i++) printf("%c", option[i][nopts[i]]);
        printf("\n");
      }

      // Find Candidates
      for (candidate = len - 1; candidate >= 0; candidate--) {
        for (i = move - 1; i > 0; i--) {
          if (option[i][nopts[i]] == letters[candidate]) break;
        }

        if (i <= 0) {
          // @TODO: Modify this to properly check for duplicates. Note that the input
          // characters can be "aaddaa". Modify this code to use only the provided characters.
          option[move][++nopts[move]] = letters[candidate];
        }
      }
    }  else {
      nopts[--move]--; // backtrack
    }
  }

  // @TODO: After generating the AVL tree of possible answers, import the dictionary of
  // words and check for existing words. DO NOT traverse the tree repeatedly for each solution
  // found. Since the solution we generated from this fxn is already sorted, we can say that
  // if the word in the dictionary comes after the current word, the word does not exist in the 
  // dictionary and we backtrack.
}
