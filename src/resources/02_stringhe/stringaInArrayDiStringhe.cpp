#include <cstring>

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