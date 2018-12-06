void permutation(char *letters, char *mask) {
  int len = strlen(letters);

  int wildcards = getWildcards(mask);
  char *choices = getChoices(mask, letters, wildcards);

  char *nopts = (char *) malloc(sizeof(char) * (len + 2));
  char **option = (char **) malloc(sizeof(char*) * (len + 2));
  for (int i = 0; i < len + 2; i++) option[i] = (char *) malloc(sizeof(char) * (len + 2));

  int start, move, i, candidate, comparison;

  FILE *dictStream = fopen("./dictionary/words.txt", "r");
  char word[MAX_WORD_SIZE];
  char substring[MAX_WORD_SIZE];

  if (dictStream == NULL) {
    exit(EXIT_FAILURE);
  }

  fscanf(dictStream, "%s\n", &word);

  move = start = 0;
  nopts[start] = 1;

  int foo = 1;

  while (nopts[start] > 0) {
    if (nopts[move] > 0) {
      nopts[++move] = 0;

      // Print a solution
      char *generated = (char *) malloc(sizeof(char) * move);
      for (i = 1; i < move; i++) generated[i - 1] = choices[option[i][nopts[i]]];
      generated[move - 1] = '\0';

      char *solution = replaceWildcards(mask, generated);

      // Dictionary Cross Check
      if (strlen(solution)) {
        comparison = strcmp(word, solution);

        while (comparison < 0 && fscanf(dictStream, "%s\n", &word) == 1) {
          // Keep on adjusting dict until it catches up
          comparison = strcmp(word, solution);
        }

        if (move - 1 == wildcards && !comparison) {
          // Match found from dict
          printf("%s\n", solution);
        }
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

      // Prune
      if (strlen(solution) && comparison > 0) {
        // Dict is ahead, meaning no more words with same prefix
        strcpy(substring, word);
        substring[strlen(solution)] = '\0';

        if (strcmp(substring, solution) > 0) {
          nopts[--move]--;
        }
      }

      free(solution);
      free(generated);
    } else {
      nopts[--move]--; // backtrack
    }
  }

  fclose(dictStream);
}


