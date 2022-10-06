#include "iostream"

using namespace std;

int fib(int n) {
    int r1 = n-1;
    if (r1 > 1)
        r1 = fib(r1);

    int r2 = n-2;
    if (r2 > 1)
        r2 = fib(r2);

    return r1 + r2;
}

int main() {
    int n;
    cout << "Inserisci un numero da applicare a fibonacci" << endl;
    cin >> n;

    for (int i=2; i<n; i++) {
        cout << fib(i) << endl;
    }

    // Metodo 2
    cout << "Metodo 2" << endl;
    int a = 0, b = 1;
    // TODO: Fix

    for (int i=2; i<n; i++) {
        b = b + a;
        a = b - a;
        cout << a + b << endl;
    }

    return 0;
}

