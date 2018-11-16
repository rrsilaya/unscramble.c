void permutation(char *letters, char *mask, WORD **root) {
  int len = strlen(letters);

  int wildcards = getWildcards(mask);
  char *choices = getChoices(mask, letters, wildcards);

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
      if (move - 1 == wildcards) {
        char *solution = (char *) malloc(sizeof(char) * move);

        for (i = 1; i < move; i++) solution[i - 1] = choices[option[i][nopts[i]]];
        solution[move - 1] = '\0';
        insertValue(root, replaceWildcards(mask, solution));
      }

      // Find Candidates
      for (candidate = strlen(choices) - 1; candidate >= 0; candidate--) {
        for (i = move - 1; i > 0; i--) {
          if (option[i][nopts[i]] == candidate) break;
        }

        if (i <= 0) {
          option[move][++nopts[move]] = candidate;
        }
      }
    }  else {
      nopts[--move]--; // backtrack
    }
  }
}
