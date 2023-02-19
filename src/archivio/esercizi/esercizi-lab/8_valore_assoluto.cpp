#include "iostream"
using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    int r = a - b;
    int rAssoluto = r * ((r>0) - (r<0));
    // Oppure
    // int rAssoluto = sqrt(r);
    // int rAssoluto = abs(r);

    cout << "a - b = " << rAssoluto << endl;
}