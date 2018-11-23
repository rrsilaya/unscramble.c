typedef struct word {
  char *string;
  int height;

  struct word *parent;
  struct word *left;
  struct word *right;
} WORD;

WORD* createWord(char *string) {
  WORD* node = (WORD*) malloc(sizeof(WORD));

  node -> left = NULL;
  node -> right = NULL;
  node -> parent = NULL;

  node -> string = (char *) malloc(sizeof(char) * strlen(string));
  strcpy(node -> string, string);

  return node;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int cmpStr(char *a, char *b) {
  return strcmp(a, b) > 0;
}

void updateHeight(WORD *root) {
  if (root != NULL)
    root -> height = max(
      root -> left == NULL
        ? -1
        : root -> left -> height,
      root -> right == NULL
        ? -1
        : root -> right -> height
    ) + 1;
}

int checkBalance(WORD *root) {
  // These integers takes the height of the subtrees
  int leftSubTree; 
  int rightSubTree;

  if (root -> left == NULL) leftSubTree = -1;
  else leftSubTree = root -> left -> height;

  if (root -> right == NULL) rightSubTree = -1;
  else rightSubTree = root -> right -> height;

  // If the difference is positive or negative one, then the root is balanced
  // Else if the difference is positive two, then the tree is imbalanced at left
  // subtree, else if negative two, then imbalanced at right subtree
  return leftSubTree - rightSubTree;
}

void leftRotate(WORD **root) {
  WORD *base = *root;
  WORD *temp = base -> right; // Left rotation takes note of the right pointer of the root

  if (root != NULL && base != NULL && base -> right != NULL) {
    // Checks if the root has a parent
    if (base -> parent != NULL) {
      if (base -> parent -> left == base) {
        // Assigns root->parent->left/right to temp
        base -> parent -> left = temp;
        *root = temp -> parent;
      } else {
        base -> parent -> right = temp;
      }
    }

    // Pointing necessary pointers to its corresponding nodes
    temp -> parent = base -> parent;

    if (temp -> left != NULL) temp -> left -> parent = base;

    base -> right = temp -> left; 
    temp -> left = base;
    base -> parent = temp;
    
    *root = temp;
    
    // Updates height of temp->left and temp
    updateHeight(temp -> left);
    updateHeight(temp);
  }
}

void rightRotate(WORD **root) {
  WORD *base = *root;
  WORD *temp = (*root) -> left; // Right rotation takes note of the left pointer of the root

  if (root != NULL && base != NULL && base -> left != NULL) {
    // Checks if the root has a parent
    if (base -> parent != NULL) {
      if (base -> parent -> right == base) {
        // Assigns root->parent->left/right to temp
        base -> parent -> right = temp;
        *root = temp -> parent;
      } else {
        base -> parent -> left = temp;
      }
    }

    // Pointing necessary pointers to its corresponding nodes
    temp -> parent = base -> parent;

    if (temp -> right != NULL) {
      base -> left = temp -> right;
      temp -> right -> parent = base;
    } else {
      base -> left = NULL;
    }

    base -> left = temp -> right;
    temp -> right = base;
    base -> parent = temp;
    *root = temp; // New root would be the temp
    
    updateHeight(temp -> right);
    updateHeight(temp);
  }
}

void insertFixUp(WORD **root, WORD *temp) {
  int balanceFactor;

  do{
    // Positive number would mean leaning left,
    // whilst negative would mean leaning right
    balanceFactor = checkBalance(temp);

    if (balanceFactor > 0) {
      // Left Leaning
      balanceFactor = checkBalance(temp -> left); 

      if (balanceFactor < 0) {
        leftRotate(&(temp -> left));
        rightRotate(&temp);
      } else {
        rightRotate(&temp);
      }
    } else if (balanceFactor < 0) {
      // Right Leaning
      balanceFactor = checkBalance(temp -> right);

      if (balanceFactor > 0) {
        rightRotate(&(temp -> right)); 
        leftRotate(&temp);
      } else {
        leftRotate(&temp);
      }
    }

    updateHeight(temp);

    if (temp -> parent == NULL) *root = temp;
    temp = temp -> parent;
  } while (temp != NULL);
}

void insertNode(WORD** root, WORD* temp) {
  WORD *base = *root;
  
  if (base == NULL) *root = temp;
  else {
    temp -> parent = base;

    if (strcmp(base -> string, temp -> string) < 0) {
      insertNode(&(base -> right), temp);
    } else if (strcmp(base -> string, temp -> string) > 0) {
      insertNode(&(base -> left), temp);
    }
  }
}

void insertValue(WORD **root, char* string) {
  WORD *temp = createWord(string);

  insertNode(root, temp);
  insertFixUp(root, temp);
}

void viewTree(WORD* root, int tabs) {
  if (root != NULL) {
    viewTree(root -> right, tabs + 1);
    for (int i = 0; i < tabs; i++) printf("\t");
    printf("%10s\n", root -> string);
    viewTree(root -> left, tabs + 1);
  }
}


void deleteTree(WORD **root) {
  WORD *base = *root;

  if (base != NULL) {
    deleteTree(&(base -> left));
    deleteTree(&(base -> right));
    free(base);

    *root = NULL;
  }
}
