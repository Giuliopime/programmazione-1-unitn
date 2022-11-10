#include "iostream"
using namespace std;

int main() {
    int size;
    cin >> size;

    // Array dinamico, dichiarato con new
    int* arrayDinamico = new int[size];

    // Se il programma non ha più memoria a disposizione, l'opeatore new abortisce il programma
    // Possiamo evitare cioò facendo restituire NULL dall'operatore new in caso la memoria sia esaurita
    int* arrayONull = new (nothrow) int[size];

    if (arrayONull != NULL) {
        // Array valido
    }

    // Deallocazione per liberare area in memoria
    delete[] arrayONull;

    // Array dinamici multidimensionali
    // è sostanzialmente un array di puntatori
    int** multiDimArray = new int* [size];
    int sizeRighe = 5;
    for(int i=0; i<size; i++) {
        multiDimArray[i] = new int[sizeRighe];
    }

    return 0;
}

int* restituisciArray() {
    int size;
    cin >> size;

    int* array = new int[size];

    return array;
}