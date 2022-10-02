#include "iostream"
using namespace std;

int main() {
    // Con variabile temporanea
    int a, b;

    cin >> a;
    cin >> b;

    int temp = a;
    a = b;
    b = temp;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    // Senza variabile temporanea
    int c, d;
    cin >> c;
    cin >> d;

    c += d;
    d = c - d;
    c -= d;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
}
