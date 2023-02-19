#include <iostream>

using namespace std;

int main() {
    const int secondiMezzanotte = 24*60*60;
    int ore, minuti, secondi;
    cin >> ore;
    cin >> minuti;
    cin >> secondi;

    if (ore < 0 || ore >= 24) {
        cout << "Ore non valide" << endl;
        exit(1);
    }
    if (minuti < 0 || minuti >= 60) {
        cout << "Minuti non validi" << endl;
        exit(1);
    }
    if (secondi < 0 || secondi >= 60) {
        cout << "Secondi non validi" << endl;
        exit(1);
    }

    int secondiDallaMezzanotte = secondiMezzanotte - (ore*60*60 + minuti*60 + secondi);
    cout << "Secondi dalla mezzanotte: " << secondiDallaMezzanotte << endl;
}