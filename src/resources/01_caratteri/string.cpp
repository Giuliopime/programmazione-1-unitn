int lunghezzaStringa(char* stringa) {
  int lunghezza = 0;
  while (stringa[lunghezza] != '\0') {
    lunghezza++;
  }

  return lunghezza;
}
