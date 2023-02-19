#include "iostream"
using namespace std;

int main() {
    int n;
    cout << "Inserisci il limite " << endl;
    cin >> n;

    for(int i=1; i<=n; i++) {
        bool primo=true;
        for(int y=2; y<i && primo; y++) {
            if (i % y == 0)
                primo = false;
        }

        if (primo)
            cout << "Il numero " << i << " è primo" << endl;
        else
            cout << "Il numero "<< i << " non è primo" << endl;
    }
}