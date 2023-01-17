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
 * Esempio ricevendo l'array come parametro
 * IMPORTANTE: la dimensione dell'array dev'essere stata calcolata prima di essere passata alla funzione (ovviamente)
 */
char* decimaleABinarioConParametro(int decimale, char* binario) {
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


int decimaleAOttale(int decimale) {
   int ottale = 0;
   int contatore = 1;

   while (decimale > 0) {
      ottale += (decimale % 8) * contatore;
      decimale /= 8;
      contatore *= 10;
   }

   return ottale;
}

int ottaleADecimale(int ottale) {
   int decimale = 0;
   int base = 1;

   while (ottale > 0) {
      int resto = ottale % 10;
      decimale += resto * base;

      ottale /= 10;
      base *= 8;
   }

   return decimale;
}


char* decimaleAEsadecimale(int decimale) {
   int temp = decimale;
   int esadecimale_array_dim = 0;
   while (temp > 0) {
      esadecimale_array_dim++;
      temp /= 16;
   }

   char* esadecimale = new char[esadecimale_array_dim + 1];
   int resto, dim_decimale = 0;

   while (decimale > 0) {
      resto = decimale % 16;

      if (resto < 10)
         esadecimale[dim_decimale] = resto + '0';
      else
         esadecimale[dim_decimale] = resto + ('A' - 10);

      decimale /= 16;
      dim_decimale++;
   }

   for(int i=0; i<(dim_decimale/2); i++) {
      char temp = esadecimale[i];
      esadecimale[i] = esadecimale[dim_decimale - i - 1];
      esadecimale[dim_decimale - i - 1] = temp;
   }

   esadecimale[esadecimale_array_dim + 1] = '\0';
   
   return esadecimale;
}


int esadecimaleADecimale(char* esadecimale, int dimensioneEsadecimale) {
   int decimale = 0;
   int base = 1;

   for (int i = dimensioneEsadecimale - 1; i >= 0; i--) {
      if (esadecimale[i] >= '0' && esadecimale[i] <= '9') 
         decimale += (int(esadecimale[i]) - '0') * base;
      else
         decimale += (int(esadecimale[i]) - ('A' - 10)) * base;
      base *= 16;
   }

   return decimale;
}

char decimaleAAsci(int decimale) {
   return (char) decimale;
}

int asciADecimale(char asci) {
   return int(asci);
}

int* asciStringaADecimale(char asci[], int dimensioneStringa) {
   int* decimale = new int[dimensioneStringa];

   for (int i=0; i<dimensioneStringa; i++) {
      decimale[i] = asciADecimale(asci[i]);
   }

   return decimale;
}
