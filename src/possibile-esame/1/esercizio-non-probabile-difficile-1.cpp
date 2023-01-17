#include "iostream"
#include <cstdlib>
#include <fstream>
#include <ios>

using namespace std;

int binarioADecimale(int binario);

char decimaleAAsci(int decimale);

char invert_char(char carattere);

char* decimaleABinario(int decimale);

int main(int count, char* argv[]) {
   if (count != 2) {
      cout << "Usage: ./a.out <input>" << endl;
      exit(1);
   }

   fstream stream;

   stream.open(argv[1], ios::in|ios::out);

   if (stream.fail()) {
      cout << "File fornito invalido" << endl;
      exit(1);
   }

   // Salvo tutte le parole / numeri / lgbtq+ per poi poter sovrascrivere il File
   

   const int LUNGHEZZA_MAX = 10;
   int numeroParole = 0;
   char parola[LUNGHEZZA_MAX];

   while (stream >> parola) {
      numeroParole++;
   }

   stream.clear();
   stream.seekg(0);

   char** listaDiParole = new char*[numeroParole];
   for (int i=0; i<numeroParole; i++) {
      listaDiParole[i] = new char[LUNGHEZZA_MAX];
   }

   int contatore = 0;
   while (stream >> parola) {
      // Converto la parola da binario a asci
      int decimale = binarioADecimale(atoi(parola));
      char asci = decimaleAAsci(decimale);
      asci = invert_char(asci);
      char* binarioModificato = decimaleABinario((int) asci); // Deallocate
     

      for (int i=0; binarioModificato[i] != '\0'; i++) {
         listaDiParole[contatore][i] = binarioModificato[i];
      }

      delete[] binarioModificato;
      contatore++;
   }

   // Sovrascrivi il File
   for (int i=0; i<contatore; i++) {
      stream << listaDiParole[i];
      delete[] listaDiParole[i];
   }

   delete[] listaDiParole;


   return 0;
}

int binarioADecimale(int binario) {
   int decimale = 0;
   int resto;
   int prodotto = 1;
   
   while (binario > 0) {
      resto = binario % 10;
      decimale += (resto * prodotto);
      
      binario = binario / 10;
      prodotto *= 2;
   }

   return decimale;  
}

char decimaleAAsci(int decimale) {
   return (char) decimale;
}

/**
 * IMPORTANTE: Alloca dinamicamente un array per darlo come valore di ritorno della funzione.
 * Questo si potrebbe evitare ricevendo l'array come parametro oppure evitando di usare il codice come funzione.
 */
char* decimaleABinario(int decimale) {
   char* binario = new char[(sizeof(decimale) * 8) + 1];

   int contatore = 0;
   while (decimale > 0) {
      binario[contatore] = '0' + (decimale % 2);
      decimale /= 2;
      contatore++;
   }
   
   for(int i=0; i<(contatore/2); i++) {
      char temp = binario[i];
      binario[i] = binario[contatore - i - 1];
      binario[contatore - i - 1] = temp;
   }

   binario[sizeof(decimale) * 8] = '\0';

   return binario;
}


/**
 * Trasforma un carattere nel suo opposto nell'alfabeto.
 * 
 * a --> z, b --> y, x --> c
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
