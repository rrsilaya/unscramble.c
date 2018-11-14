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

int max(int a, int b){
  return(a>b?a:b);
}

int cmpStr(char *a, char *b) {
  return strcmp(a, b) > 0;
}

void updateHeight(WORD *root){
  if(root!=NULL)
    root->height = max(root->left==NULL?-1:root->left->height,root->right==NULL?-1:root->right->height)+1;
}

int checkBalance(WORD *root){

  //These integers takes the height of the subtrees
  int leftSubTree; 
  int rightSubTree;

  if(root->left == NULL) leftSubTree = -1;
  else leftSubTree = root->left->height;

  if(root->right == NULL) rightSubTree = -1;
  else rightSubTree = root->right->height;

  // If the difference is positive or negative one, then the root is balanced
  // Else if the difference is positive two, then the tree is imbalanced at left subtree, else if negative two, then imbalanced at right subtree
  return leftSubTree - rightSubTree;

}

//leftRotate() does a single left rotation given a root
void leftRotate(WORD **rootptr){

  WORD *temp = (*rootptr)->right; //Left rotation takes note of the right pointer of the root

  if(rootptr!=NULL && *rootptr!=NULL && (*rootptr)->right!=NULL){

    //Checks if the rootptr has a parent
    if((*rootptr)->parent != NULL){
      if((*rootptr)->parent->left == (*rootptr)){ //This assign root->parent->left/right to temp
        (*rootptr)->parent->left = temp;
        (*rootptr) = temp->parent;
      }
      else(*rootptr)->parent->right = temp;
    }

    //Pointing necessary pointers to its corresponding nodes
    temp->parent = (*rootptr)->parent; 
    if(temp->left!=NULL) temp->left->parent = (*rootptr); 
    (*rootptr)->right = temp->left; 
    temp->left = (*rootptr);
    (*rootptr)->parent = temp;
    (*rootptr) = temp;
    
    //Updates height of temp->left and temp
    updateHeight(temp->left);
    updateHeight(temp);
  }
}

//rightRotate() does a single left rotation given a root
void rightRotate(WORD **rootptr){

  WORD *temp = (*rootptr)->left;//Right rotation takes note of the left pointer of the root

  if(rootptr!=NULL && *rootptr!=NULL && (*rootptr)->left!=NULL){
  
    
    //Checks if the rootptr has a parent
    if((*rootptr)->parent != NULL) {
      if((*rootptr)->parent->right == (*rootptr)){ //This assign root->parent->left/right to temp
        (*rootptr)->parent->right = temp;
        (*rootptr) = temp->parent;
      }
      else(*rootptr)->parent->left = temp;
    }


    //Pointing necessary pointers to its corresponding nodes
    temp->parent = (*rootptr)->parent; 
    if(temp->right!=NULL){
      (*rootptr)->left = temp->right;
      temp->right->parent = (*rootptr);
    }else (*rootptr)->left = NULL;
    (*rootptr)->left = temp->right;
    temp->right = (*rootptr);
    (*rootptr)->parent = temp;
    (*rootptr) = temp; //New root would be the temp
    

    //Updates height of temp->left and temp
    updateHeight(temp->right);
    updateHeight(temp);


  }
}

void insertFixUp(WORD **rootptr, WORD *temp){

  int balance_factor; //Notes the balance factor of a node

  do{
    balance_factor = checkBalance(temp); //Balance factor of a node
    //Note that positive number would mean leaning left, whilst negative would mean leaning right


    //Left leaning 
    if(balance_factor == 2){ 
      //Gets balance factor of the left subtree
      balance_factor = checkBalance(temp->left); 

      //If balance_factor is negative, it would mean leaning to the Right so Left-Right leaning
      if(balance_factor < 0){ 
        leftRotate(&(temp->left));
        rightRotate(&(temp));
      }
      //Else positive, it would mean leaning to the Left so Left-Left leaning 
      else{
        rightRotate(&temp);
      }
    }

    //Right leaning
    else if (balance_factor == -2){ 
      //Gets balance factor of the right subtree
      balance_factor = checkBalance(temp->right);

      //If balance_factor is negative, it would mean leaning to the left so Right-Left leaning
      if(balance_factor > 0){
        rightRotate(&(temp->right)); 
        leftRotate(&(temp));
      }

      //Else positive, it would mean leaning to the right so Right-Right leaning
      else{ 
        leftRotate(&temp);
      }
    }


    updateHeight(temp);

    if(temp->parent==NULL)
      *rootptr = temp;

    temp = temp->parent;

  } while(temp!=NULL);
}

void insertNode(WORD** root, WORD* temp) {
  WORD *base = *root;
  
  if(*root==NULL) *root = temp;
  else{
    temp->parent = *root;

    if(!cmpStr(base -> string, temp -> string))
      insertNode(&((*root)->right),temp);
    else
      insertNode(&((*root)->left),temp);
  }
}

void insertValue(WORD **rootptr, char* string){
  WORD *temp;
  temp = createWord(string);
  insertNode(rootptr, temp);
  insertFixUp(rootptr, temp);
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
    free(*root);
    *root = NULL;
  }
}
