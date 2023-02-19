#include "iostream"
#include "fstream"

using namespace std;

// Funzioni dal file `operazione_rotazione.cpp` in resources/03_array

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
  cout << "opk" << endl;
  while (input >> parola) {
    cout << "opk" << endl;
    int dimensioneParola = lunghezzaStringa(parola);
    cout << dimensioneParola << endl;
    shiftASinistraAlt(parola, dimensioneParola, shift);
    cout << parola << endl;
    output << parola << " ";
  }

  input.close();
  output.close();

  return 0;
}
