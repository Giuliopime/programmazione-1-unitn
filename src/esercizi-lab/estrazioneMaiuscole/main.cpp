#include "iostream"
#include "estrai.h"

using namespace std;

int main() {
    char stringa[256];
    char *risultato;

    cout << "Inserisci una stringa: " << endl;
    cin >> stringa;

    risultato = estraiStringa(stringa);
    cout << "Il risultato e': " << risultato << endl;
}