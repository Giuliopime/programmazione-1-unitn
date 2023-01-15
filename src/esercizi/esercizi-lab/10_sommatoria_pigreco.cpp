#include "iostream"

using namespace std;

int main() {
    int n;
    cout << "Inserisci il limite della sommatoria" << endl;
    cin >> n;

    double somma = 0;
    for(int i=1; i<=n; i++) {
        somma += 1.0 / (i * i);
    }

    cout << "Somma = " << somma << endl;

    const double pi = 3.141592;
    cout << "Somma pigreco =" << pi * pi / 6 << endl;

    return 0;
}