#include "iostream"

bool judgeCircle(char* moves);

int main() {
  char moves[] = {'U', 'R', 'D', 'L'};

  bool centrato = judgeCircle(moves);

  std::cout << (centrato ? "true" : "false") << std::endl;

  return 0;
}

int lunghezzaStringa(char* stringa) {
  int lunghezza = 0;
  while (stringa[lunghezza] != '\0') {
    lunghezza++;
  }

  return lunghezza;
}

void aux(char* moves, int& contatore, int numeroMosse, int& srcx, int& srcy) {
  if (contatore < numeroMosse) {
    if (moves[contatore] == 'R') {
      srcx++ ;
    } else if (moves[contatore] == 'L') {
      srcx-- ;
    } else if (moves[contatore] == 'U') {
      srcy++;
    } else {
      srcy--;
    }
    contatore++;
    aux(moves, contatore, numeroMosse, srcx, srcy);
  }
}

bool judgeCircle(char* moves) {
  int srcx = 0;
  int srcy = 0;
  int contatore = 0;

  aux(moves, contatore, lunghezzaStringa(moves), srcx, srcy);

  if (srcx == 0 && srcy == 0) {
    return true;
  } else {
    return false;
  }
}
