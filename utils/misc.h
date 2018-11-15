int getWildcards(char *mask) {
  int counter = 0;

  for (int i = 0; i < strlen(mask); i++) {
    if (mask[i] == '_') counter++;
  }

  return counter;
}