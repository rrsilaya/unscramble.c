void loadFile(WORD **root){
  FILE *stream;
  stream = fopen("./dictionary/words.txt", "r");

  char* line = (char *) malloc(sizeof(char) * MAX_WORD_SIZE);
  
  if (stream == NULL){
    printf("words.txt not in the directory");
    exit(EXIT_FAILURE);
  }else{
      while (fgets(line, MAX_WORD_SIZE, stream) != NULL){
        char *solution = (char *) malloc(sizeof(char) * MAX_WORD_SIZE);
        strcpy(solution, line);
        solution[strlen(solution) - 1] = '\0';
        insertValue(root, solution);
      }
      fclose(stream);
  }
}

void searchTree(WORD* root, char* string) {
  if (root != NULL) {
    if(strcmp(root->string, string) < 0){
      searchTree(root -> right, string);
    }else if(strcmp(root->string, string) > 0){
      searchTree(root -> left, string);
    }else if(strcmp(root->string, string) == 0){
      printf("%s\n", string);
    }
  }
}

void searchDict(WORD* root, WORD* sol) {
  if (root != NULL) {
    searchDict(root -> left, sol);
    searchTree(sol, root -> string);
    searchDict(root -> right, sol);
  }
}


