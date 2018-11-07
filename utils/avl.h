typedef struct word {
  int value;

  struct word *left;
  struct word *right;
} WORD;

WORD* createWord(int value) {
  WORD* new = (WORD*) malloc(sizeof(WORD));

  new -> value = value;
  new -> left = NULL;
  new -> right = NULL;

  return new;
}

void insertNode(WORD** root, int value) {
  WORD *base = *root;

  if (base == NULL) {
    *root = createWord(value);
  } else {
    if (base -> right != NULL && base -> value < value) {
      insertNode(&(base -> right), value);
    } else if (base -> left != NULL && base -> value > value) {
      insertNode(&(base -> left), value);
    } else {
      // Probably the leaf nodes are NULL
      WORD *node = createWord(value);

      if (base -> value < value) base -> right = node;
      else base -> left = node;
    }
  }
}

void viewTree(WORD* root, int tabs) {
  if (root != NULL) {
    viewTree(root -> right, tabs + 1);

    for (int i = 0; i < tabs; i++) printf("\t");
    printf("%2i\n", root -> value);

    viewTree(root -> left, tabs + 1);
  }
}
