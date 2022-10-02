#include "iostream"
#include "cmath"

using namespace std;

int main() {
    double a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    cout.precision(10); // Imposta la precisione (parte decimale + intera) da stampare

    double delta = b*b - 4ac;
    double sol1 = (-b + sqrt(delta)) / 2a;

    cout << "Soluzione 1: " << sol1 << endl;
    if (delta != 0) {
        double sol2 = (-b - sqrt(delta)) / 2a;
        cout << "Soluzione 2: " << sol2 << endl;
    }
}