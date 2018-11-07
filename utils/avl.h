typedef struct word {
  char *string;

  struct word *left;
  struct word *right;
} WORD;

WORD* createWord(char *string) {
  WORD* node = (WORD*) malloc(sizeof(WORD));

  node -> left = NULL;
  node -> right = NULL;

  node -> string = (char *) malloc(sizeof(char) * strlen(string));
  strcpy(node -> string, string);

  return node;
}

int cmpStr(char *a, char *b) {
  return strcmp(a, b) > 0;
}

void insertNode(WORD** root, char* string) {
  WORD *base = *root;

  if (base == NULL) {
    *root = createWord(string);
  } else {
    if (base -> right != NULL && !cmpStr(base -> string, string)) {
      insertNode(&(base -> right), string);
    } else if (base -> left != NULL && cmpStr(base -> string, string)) {
      insertNode(&(base -> left), string);
    } else {
      // Probably the leaf nodes are NULL
      WORD *node = createWord(string);

      if (!cmpStr(base -> string, string)) base -> right = node;
      else base -> left = node;
    }
  }
}

void viewTree(WORD* root, int tabs) {
  if (root != NULL) {
    viewTree(root -> right, tabs + 1);
    for (int i = 0; i < tabs; i++) printf("\t");
    printf("%10s\n", root -> string);
    viewTree(root -> left, tabs + 1);
  }
}


void deleteTree(WORD ** root){

  if((*root) != NULL){
    deleteTree(&((*root)->left));
    deleteTree(&((*root)->right));
    printf("Deleting %s\n",(*root)->string); //Displaying what is about to be deleted
    free(*root);
    *root = NULL;
  }
}
