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
        for (i = 1; i < move; i++) printf("%c", option[i][nopts[i]]);
        printf("\n");
      }

      // Find Candidates
      for (candidate = len - 1; candidate >= 0; candidate--) {
        for (i = move - 1; i > 0; i--) {
          if (option[i][nopts[i]] == letters[candidate]) break;
        }

        if (i <= 0) {
          option[move][++nopts[move]] = letters[candidate];
        }
      }
    }  else {
      nopts[--move]--; // backtrack
    }
  }
}