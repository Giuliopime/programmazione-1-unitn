void shiftASinistra(char* array, int dimensione, int shift) {
  // Array rotato
  // Usare new se la dimensione non si sa a priori dell'esecuzione del programma
  // char* shiftato = new char[dimensione];
  char shiftato[dimensione];

  // In caso shift sia più lungo della dim
  shift = shift % dimensione;

  // Indice dell'array rotato
  int indiceShiftato = 0;

  // Prendo dallo shift in poi
  for (int i = shift; i < dimensione; i++) {
    shiftato[indiceShiftato] = array[i];
    indiceShiftato++;
  }

  // Prendo da 0 allo shift
  for (int i = 0; i < shift; i++) {
    shiftato[indiceShiftato] = array[i];
    indiceShiftato++;
  }

  // Copio il risultato
  for (int i = 0; i < dimensione; i++) {
    array[i] = shiftato[i];
  }

  // delete[] shiftato;
}

void shiftADestra(char* array, int dimensione, int shift) {
  // Array rotato
  // Usare new se la dimensione non si sa a priori dell'esecuzione del programma
  // char* shiftato = new char[dimensione];
  char shiftato[dimensione];

  // In caso shift sia più lungo della dim
  shift = shift % dimensione;

  // Indice dell'array rotato
  int indiceArray = 0;

  // Prendo da 0 allo shift
  for (int i = shift; i < dimensione; i++) {
    shiftato[i] = array[indiceArray];
    indiceArray++;
  }

  // Prendo dallo shift in poi
  for (int i = 0; i < shift; i++) {
    shiftato[i] = array[indiceArray];
    indiceArray++;
  }

  // Copio il risultato
  for (int i = 0; i < dimensione; i++) {
    array[i] = shiftato[i];
  }

  // delete[] shiftato;
}

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
