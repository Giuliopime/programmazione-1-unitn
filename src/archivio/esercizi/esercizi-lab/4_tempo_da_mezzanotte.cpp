#include <iostream>

using namespace std;

int main() {
    const int secondiMezzanotte = 24*60*60;
    int secondiDallaMezzanotte;
    cin >> secondiDallaMezzanotte;

    if (secondiDallaMezzanotte < 0 || secondiDallaMezzanotte >= secondiMezzanotte) {
        cout << "Secondi non validi" << endl;
        exit(1);
    }
     
    int ore = secondiDallaMezzanotte / 3600;
    int minuti = (secondiDallaMezzanotte / 60) - (ore * 60);
    int secondi = secondiDallaMezzanotte % 60;

    cout << "ore: " << ore << endl;
    cout << "minuti: " << minuti << endl;
    cout << "secondi: " << secondi << endl;
}