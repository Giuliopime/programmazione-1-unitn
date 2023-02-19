#include "iostream"

using namespace std;

int main() {
   int decimale = 1232;

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
  
   // Deallocare dopo l'utilizzo
   cout << esadecimale << endl;

   delete[] esadecimale;

   return 0;
}
