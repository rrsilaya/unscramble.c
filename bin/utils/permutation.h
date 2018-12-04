void permutation(char *letters, char *mask) {
  int len = strlen(letters);

  int wildcards = getWildcards(mask);
  char *choices = getChoices(mask, letters, wildcards);

  char *nopts = (char *) malloc(sizeof(char) * (len + 2));
  char **option = (char **) malloc(sizeof(char*) * (len + 2));
  for (int i = 0; i < len + 2; i++) option[i] = (char *) malloc(sizeof(char) * (len + 2));

  int start, move, i, candidate, result;

  move = start = 0;
  nopts[start] = 1;

  FILE *stream;
  stream = fopen("../dictionary/words.txt", "r");

  char* line = (char *) malloc(sizeof(char) * MAX_WORD_SIZE);
  
  if (stream == NULL){
    printf("Dictionary not found");
    exit(EXIT_FAILURE);
  }

  char *word;
  word = (char *) malloc(sizeof(char) * MAX_WORD_SIZE);
  fgets(line, MAX_WORD_SIZE, stream);
  strcpy(word, line);
  word[strlen(word) - 1] = '\0';
  

  while (nopts[start] > 0) {
    if (nopts[move] > 0) {
      nopts[++move] = 0;

      if (move - 1 == wildcards) {
        char *solution = (char *) malloc(sizeof(char) * move);
        for (i = 1; i < move; i++) solution[i - 1] = choices[option[i][nopts[i]]];
        solution[move - 1] = '\0';

        result = strcmp(word, solution);
        // printf("%s %s %d\n", word, solution, result);
        
        if(result == 0) printf("%s\n", solution); // Valid word
        
        else if(result < 0){// Adjust dictionary
           while (fgets(line, MAX_WORD_SIZE, stream) != NULL && result < 0){
            free(word);
            word = NULL;  
            word = (char *) malloc(sizeof(char) * MAX_WORD_SIZE);
            strcpy(word, line);
            word[strlen(word) - 1] = '\0';
            result = strcmp(word, solution);
            // printf("%s %s %d\n", word, solution, result);
            if(result == 0) printf("%s\n", solution);
          }
        }//else Adjust permutation

        // Stops the system in doing permutation when the dictionary is exhausted
        if(feof(stream)){
          fclose(stream);
          break;
        };
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


