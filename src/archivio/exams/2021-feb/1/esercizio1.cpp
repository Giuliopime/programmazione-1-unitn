#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_PAROLE = 1000;
const int MAX_LUNGHEZZA_PAROLA = 100;
const char CARATTERE_CENSURA = 'X';


/**
 * Converte un carattere da uppercase a lowercase in caso sia compreso tra 'A' e 'Z'
 *
 * @param carattere Il carattere da trasformare
*/
char to_lower(char& carattere) {
  if (carattere >= 'A' && carattere <= 'Z')
    return (char) (carattere - 'A') + 'a';
  
  return carattere;
}

/**
 * Controlla se una stringa è presente in un array di stringhe.
 * Per stringa si intende a sua volta un array di caratteri.
 * 
 * Questo medoto ha bisogno di conoscere la lunghezza massima delle parole nell'array.
 * 
 * @param stringa La stringa da cercare
 * @param array L'array di stringhe
 * @param lunghezzaArray La lunghezza dell'array precedente
 * @return true se la stringa é nell'array, false al contrario
*/
bool stringaInArrayDiStringhe(char* stringa, char array[][MAX_LUNGHEZZA_PAROLA], int lunghezzaArray) {
  // Itero l'array di stringhe
  for (int i=0; i<lunghezzaArray; i++) {

    // Controllo se la stringa fornita come parametro é della stessa lunghezza della stringa che ho preso dall'array
    if (strlen(stringa) == strlen(array[i])) {

      // In tal caso controllo carattere per carattere le due stringhe
      for (int y=0; y<strlen(stringa); y++) {

        // Se vedo che i caratteri sono uguali e si tratta dell'ultimo carattere della stringa allora posso dire di avere un match
        if (to_lower(stringa[y]) == to_lower(array[i][y]) && y == (strlen(stringa) - 1))
          return true;

        // Altrimenti controllo se i caratteri sono diversi, in tal caso smetto di analizzare la stringa e proseguo con la successiva dell'array
        else if(to_lower(stringa[y]) != to_lower(array[i][y]))
          break;
      }
    }
  }

  // Se dopo aver confrontato la stringa fornita con tutte quelle nell'array non ho trovato nessun match
  // allora posso dire che non é contenuta nell'array
  return false;
}


int main(int argc, char * argv []) {
  /**
   * Controllo argomenti per l'esecuzione
  */
  if (argc != 4) {
    cout << "Usage: esercizio1.cpp <messaggio.txt> <vocabolario.txt> <output_file>" << endl;
    exit(1);
  }

  /**
   *  Setup dei file di input ed output 
  */
  fstream messaggio, fileVocabolario, output;

  messaggio.open(argv[1], ios::in);
  if (messaggio.fail()) {
    cout << "Non sono riuscito ad aprire il file " << argv[1] << endl;
    messaggio.close();
    exit(1);
  }

  fileVocabolario.open(argv[2], ios::in);
  if (fileVocabolario.fail()) {
    cout << "Non sono riuscito ad aprire il file " << argv[2] << endl;
    fileVocabolario.close();
    messaggio.close();
    exit(1);
  }

  output.open(argv[3], ios::out);

  /**
   * Creazione del vocabolario come array di stringhe
  */
  char vocabolario[MAX_PAROLE][MAX_LUNGHEZZA_PAROLA];
  int index = 0;
  while (fileVocabolario >> vocabolario[index]) {
    index++;
  }


  /**
   * Censuro le parole
  */
  char parola[MAX_LUNGHEZZA_PAROLA];
  while (messaggio >> parola) {
    if (stringaInArrayDiStringhe(parola, vocabolario, index))
      for (int i=0; i<strlen(parola); i++)
        output << CARATTERE_CENSURA;
    else
      output << parola;

    output << ' ';
  }

  output << endl;
  
  /**
   * Chiudo gli fstream
  */
  messaggio.close();
  fileVocabolario.close();
  output.close();

  return 0;
}