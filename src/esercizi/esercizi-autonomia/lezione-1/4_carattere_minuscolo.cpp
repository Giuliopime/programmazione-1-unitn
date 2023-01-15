#include <iostream>

using namespace std;

int main() {
    char maiuscolo;
    cin >> maiuscolo;

    char minuscolo = maiuscolo + 32;
    cout << "Carattere  minuscolo relativo ad " << maiuscolo << " = " << minuscolo << endl;
}
