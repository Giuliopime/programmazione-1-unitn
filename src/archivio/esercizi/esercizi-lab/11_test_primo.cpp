#include "iostream"

using namespace std;

int main() {
    int n;
    cout << "Inserisci un numero" << endl;
    cin >> n;

    bool primo=true;
    for(int i=2; i<n && primo; i++) {
        if (n % i == 0)
            primo = false;
    }

    if (primo)
        cout << "Il numero è primo" << endl;
    else
        cout << "Il numero non è primo" << endl;

    return 0;
}