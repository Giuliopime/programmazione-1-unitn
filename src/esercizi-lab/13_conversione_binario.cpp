#include "iostream"
#include "math.h"
using namespace std;

int main() {
    int binario;
    cin >> binario;

    int decimale = 0;
    int count = 0;

    while (binario > 0) {
        int unita = binario % 10;
        if (unita == 1)
           decimale += pow(2, count);

        count++;
        binario /= 10;
    }

    cout << "risultato: " << decimale << endl;

    return 0;
}
