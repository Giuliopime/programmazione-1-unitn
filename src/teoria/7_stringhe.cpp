#include "iostream"
using namespace std;

int main() {
    // Una stringa è un array di char
    char stringa[] = "Ciao";

    // Contiene sempre il carattere nullo alla fine!
    char stringaConChar[]= {'C','i','a','o','\0'};

    // Lettura io
    char buffer[256];
    cin >> buffer;
    cout << buffer;

    // Alcune funzioni utili sono presenti nella libreria <cstring>
}