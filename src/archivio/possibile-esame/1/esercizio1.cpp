#include "iostream"
#include "fstream"
#include <cstddef>
#include <ios>

using namespace std;

long long int converti(char source[], int dim_source);

int main(int argc, char* argv[]) {
   
   if (argc != 3) {
      cout << "Usage: ./a.out <input> <output>" << endl;
      exit(1);
   }

   fstream input, output;

   input.open(argv[1], ios::in);
   if (input.fail()) {
      cout << "Errore nel file di input" << endl;
      input.close();
      exit(1);
   }

   output.open(argv[2], ios::out);

   int MAX_LUNGHEZZA = 10;
   int TRONCA = 5;
   char numero[MAX_LUNGHEZZA];
   while(input >> numero) {
      int dim = 0;
      numero[5] = '\0';

      while (numero[dim] != '\0') {
         dim++;
      }

      long long int convertito = converti(numero, dim);
      output << convertito;
   }

   input.close();
   output.close();

   return 0;
}

long long int converti(char source[], int dim_source) {
   long long int decimale = 0;
   int base = 1;

   for (int i=dim_source-1; i>=0; i--) {
      decimale += (source[i] - '0') * base;
      base *= 4;
   }

   return decimale;
}
