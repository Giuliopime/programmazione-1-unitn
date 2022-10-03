#include "iostream"
using namespace std;

void puntatori() {
    /*
     * TERMINOLOGIA
     * Una variabile è composta da:
     * l-value: l'indirizzo in memoria della variabile
     * r-value: il valore della variabile
     */


    // REFERENCE
    int x=1;
    int &y = x; // y è una reference ad x
    // int &y = x; Mettere & affianco al tipo o al nome della variabile è la stessa cosa

    // y ora è semplicemente un alias (sinonimo) di x
    // Se cambio il valore di y è come se stessi cambiando quelli di x
    y = 2;
    cout << x << endl; // x sarà uguale a 2 ora

    // L'inizializzazione di una reference è obbligatoria
    // int &ref; Risulterà in un errore

    // I tipi delle due variabili devono coincidere
    // double &ref = x; Risulta errore, in quanto i tipi sono diversi: double != int

    // Per ottenere l'indirizzo di una variabile nella memoria (l-value) posso usare &
    cout << &x << endl; // Printerà l'indirizzo in memoria della variabile x


    // PUNTATORE
    // Lo spazio allocato per un puntatore è quello che serve per contenere un indirizzo di una variabile:
    // 32 bit o 64 bit a seconda dell'archittettura del processore
    int *puntatore;
    puntatore = &x; // Salvo nel mio puntatore l'indirizzo di x

    // Posso modificare il r-value di x direttamente dal puntatore
    *puntatore = 3;
    cout << x << endl; // x = 3

    // È possibile avere dei puntatori che puntano ad una variabile ma di qualsiasi tipo
    void *puntatoreGenerico;
    char a = 'a';
    double pi = 3.14;

    puntatoreGenerico = &a;
    *(char*)puntatoreGenerico = 'b'; // Per assegnare il valore devo specificare il ciclo con una sorta di casting
    puntatoreGenerico = &pi;
    *(double*)puntatoreGenerico = 3.1415;

    // Posso anche definire un puntatore costante, e quindi invariabile
    const int *puntatoreCostante = &x;
    // *puntatoreCostante = &y; darebbe errore

    // È possibile anche creare un puntatore a un puntatore
    int **pp = &puntatore;

    // Posso modificare un puntatore anche 'manualmente'
    // In modo automatico 1 viene convertito nella dimensione (sizeof()) del puntatore
    // 4 byte in un sistema a 32 bit, 8 byte per uno a 64
    // Quindi sposto il puntatore di una cella di memoria
    puntatore = puntatore + 1;
    // Oppure
    puntatore++; // Vado nella cella di memoria successiva
    puntatore--; // Vado nella cella di memoria precedente
    // Valgono tutti gli altri modi per modificare il valore di un intero
    // *=
    // /=
    // espressioni matematiche (+5, *34, -12)
}