#include <iostream>

using namespace std;

int main() {
    int dividendo;
    int divisore;

    cin >> dividendo;
    cin >> divisore;

    int quoziente = dividendo / divisore;
    double resto = dividendo % divisore;

    cout << "Quoziente = " << quoziente << endl;
    cout << "Resto = " << resto << endl;
}
