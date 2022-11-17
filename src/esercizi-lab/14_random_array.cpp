#include <iostream>
#include <cstdlib>
using namespace std;

int* generate_numbers(int n) {
    srand(time(NULL));

    int* array = new int[n];

    for (int i=0; i<n; i++) {
        array[i] = rand() % 100;
    }

    return array;
}

int main() {
    int n;
    cout << "Inserisci la lunghezza dell'array" << endl;
    cin >> n;

    int* pointerArray = generate_numbers(n);
    
    for (int i=0; i<n; i++)
        cout << pointerArray[i] << endl;

    delete[] pointerArray;
}