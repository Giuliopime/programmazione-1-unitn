void shiftADestraAlt(char* array, int dimensione, int shift) {
  int len = dimensione - 1;
  int i, j;
  for(j = 0; j < shift; j++) {
    for (i = 0; i < len; i++) {
      char tmp = array[i];
      array[i] = array[len];
      array[len] = tmp;
    }
  }
}

void shiftASinistraAlt(char* array, int dimensione, int shift) {
  int len = dimensione - 1;
  int i, j;
  for(j = 0; j < shift; j++) {
    for (i = len; i>=0; i--) {
      char tmp = array[i];
      array[i] = array[len];
      array[len] = tmp;
    }
  }
}

void printArray(char* array, int dimensione) {
  for (int i = 0; i < dimensione; i++) {
    std::cout << array[i] << " ";
  }
}
