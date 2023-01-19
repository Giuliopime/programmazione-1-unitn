#include "iostream"
#include "fstream"

using namespace std;

int main(int argc, char* argv[]) {
   if (argc != 3) {
      cout << "Usage: ./a.out <input> <output>" << endl;
      exit(1);
   }

   fstream input, output;

   input.open(argv[1], ios::in);

   if (input.fail()) {
      cout << "Errore nel file di input" << endl;
      exit(1);
   }

   output.open(argv[2], ios::out);

   int MAX_DIM_RIGA = 255;

   int dimensionePiuGrande = 0;
   char rigaPiuLunga[MAX_DIM_RIGA];

   char buffer[MAX_DIM_RIGA];

   while (input.getline(buffer, MAX_DIM_RIGA)) {
      int dimensione = 0;
      while(buffer[dimensione] != '\0') {
         dimensione++;
      }

      if (dimensione > dimensionePiuGrande) {
         dimensionePiuGrande = dimensione;
         for (int i=0; i<dimensione; i++) {
            rigaPiuLunga[i] = buffer[i];
         }
      }

      output << dimensione << endl;
   }

   output << "Riga piu lunga (" << dimensionePiuGrande << "):" << endl;
   output << rigaPiuLunga;
   
   return 0;
}
