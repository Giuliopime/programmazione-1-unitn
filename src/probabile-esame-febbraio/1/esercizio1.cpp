#include "iostream"
#include "fstream"

using namespace std;

void shiftASinistra(char* array, int dimensione, int shift) {
  // Array rotato
  // Usare new se la dimensione non si sa a priori dell'esecuzione del programma
  char* shiftato = new char[dimensione];
  // char shiftato[dimensione];

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

  delete[] shiftato;
}

int lunghezzaStringa(char* stringa) {
  int lunghezza = 0;
  while (stringa[lunghezza] != '\0') {
    lunghezza++;
  }

  return lunghezza;
}


int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Usage: ./a.out <input> <output>" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  if (input.fail()) {
    cout << "Non sono riuscito a gestire il file di input" << endl;
    input.close();
    exit(1);
  }

  output.open(argv[2], ios::out);
  if (output.fail()) {
    cout << "Non sono riuscito a gestire il file di output" << endl;
    input.close();
    output.close();
    exit(1);
  }

  const int shift = 3;
  const int MAX_LUNGHEZZA_PAROLA = 100;

  char parola[MAX_LUNGHEZZA_PAROLA];
  while (input >> parola) {
    int dimensioneParola = lunghezzaStringa(parola);
    shiftASinistra(parola, dimensioneParola, shift);
    output << parola << " ";
  }

  input.close();
  output.close();

  return 0;
}
