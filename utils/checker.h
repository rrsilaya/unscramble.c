void searchFile(char* string){
  FILE *stream;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  stream = fopen("./dictionary/words.txt", "r");
  if (stream == NULL){
    printf("words.txt not in the directory");
      exit(EXIT_FAILURE);
  }
  else{
    while ((read = getline(&line, &len, stream)) != -1) {
      if(strcmp(line, string) == 0){
        printf("%s found inside dictionary %s\n", string, line);
        break;
      }else if(strcmp(line, string) > 0){
        printf("%s-> NOT FOUND\n", string);
        break;
      }
    }
    free(line);
    fclose(stream);
  }
}

void searchDict(WORD* root) {
  if (root != NULL) {
    searchDict(root -> left);
    searchFile(strcat(root->string, "\n"));
    searchDict(root -> right);
  }
}

