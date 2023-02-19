#include <iostream>
#include <cstddef>

using namespace std;

void get_elements(char source[], int size_source, char *&dest1, int &size_dest1, char *&dest2, int &size_dest2);

void print(const char a[], const int s, const char *prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int &s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n'));) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}

int main() {
  const int maxdim = 10;

  char *d1;
  int d1_s = 0;

  char *d2;
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);
  print(s, s_s, "Source = ");

  get_elements(s, s_s, d1, d1_s, d2, d2_s);

  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

  delete[] d1;
  delete[] d2;
}

/**
 * Converte un carattere da lowercase a uppercase in caso sia compreso tra 'a' e 'z'
 *
 * @param carattere Il carattere da trasformare
*/
char to_upper(char carattere) {
  if (carattere >= 'a' && carattere <= 'z')
    return (char) (carattere - 'a') + 'A';

  return carattere;
}

/**
 * Trasforma un carattere nel suo opposto nell'alfabeto.
 * Sia lettere che numeri.
 * 
 * a --> z, b --> y, x --> c, 0 --> 9, 8 --> 1
 * @param carattere Il carattere da trasformare
*/
char invert_char(char carattere) {
  if (carattere >= 'a' && carattere <= 'z')
    return char('a' - carattere + 'z');
  if (carattere >= 'A' && carattere <= 'Z')
    return char('A' - carattere + 'Z');
  if (carattere >= '0' && carattere <= '9') {
    return char('0' - carattere + '9');
  }

  return carattere;
}

void get_elements_aux(char source[], int size_source, char *&dest1, int &size_dest1, char *&dest2, int &size_dest2, int index) {
  if (index >= size_source) {
    // Ho finito di analizzare la source quindi inizializzo gli array
    dest1 = new char[size_dest1];
    dest2 = new char[size_dest2];
  } else {
    char daAnalizzare = source[index];

    if (daAnalizzare >= 'a' && daAnalizzare <= 'z') {
      char nuovoValore = to_upper(invert_char(daAnalizzare));
      int indiceInCuiInserire = size_dest1++;
    
      get_elements_aux(source, size_source, dest1, size_dest1, dest2, size_dest2, index + 1);

      dest1[indiceInCuiInserire] = nuovoValore;
    } else if (daAnalizzare >= '0' && daAnalizzare <= '9') {
      char nuovoValore = invert_char(daAnalizzare);
      int indiceInCuiInserire = size_dest2++;

      get_elements_aux(source, size_source, dest1, size_dest1, dest2, size_dest2, index + 1);

      dest2[indiceInCuiInserire] = nuovoValore;
    } else {
      get_elements_aux(source, size_source, dest1, size_dest1, dest2, size_dest2, index + 1);
    }
  }
}

void get_elements(char source[], int size_source, char *&dest1, int &size_dest1, char *&dest2, int &size_dest2) {
  get_elements_aux(source, size_source, dest1, size_dest1, dest2, size_dest2, 0);
}
