#define ALPHABET 26
#define ASCII_OFFSET 97

int getWildcards(char *mask) {
  int counter = 0;

  for (int i = 0; i < strlen(mask); i++) {
    if (mask[i] == '_') counter++;
  }

  return counter;
}

char* getChoices(char *mask, char *letters, int wildcards) {
  char *string = (char *) malloc(sizeof(char) * (strlen(letters) + 1));
  int len = 0;
  
  // @TODO: If you can think of other ways to check this, change this
  // implementation.
  int mask_counter[ALPHABET];
  int letters_counter[ALPHABET];

  // Initialize counters
  for (int i = 0; i < ALPHABET; i++) {
    mask_counter[i] = 0;
    letters_counter[i] = 0;
  }

  for (int i = 0; i < strlen(mask); i++) {
    if (mask[i] != '_') mask_counter[mask[i] - ASCII_OFFSET]++;
  }

  for (int i = 0; i < strlen(letters); i++) letters_counter[letters[i] - ASCII_OFFSET]++;

  // Perform XOR operation
  for (int i = 0; i < ALPHABET; i++) {
    int difference = letters_counter[i] - mask_counter[i];

    if (difference != 0) {
      for (int mult = 0; mult < difference; mult++) {
        string[len] = i + ASCII_OFFSET;
        len++;
      }
    } else {
      printf("Error");
    }
  }

  string[len] = '\0';
  return string;
}

char* replaceWildcards(char *mask, char *letters) {
  int index = 0, len = strlen(mask);
  char *string = (char *) malloc(sizeof(char) * (len + 1));

  for (int i = 0; i < len; i++) {
    if (mask[i] == '_') {
      string[i] = letters[index];
      index++;
    } else {
      string[i] = mask[i];
    }
  }

  string[len] = '\0';
  return string;
}

char* toLowerCase(char *string) {
  int len = strlen(string);
  char *lower = (char *) malloc(sizeof(char) * (len + 1));

  for (int i = 0; i < len; i++) {
    lower[i] = tolower(string[i]);
  }

  lower[len] = '\0';
  return lower;
}
