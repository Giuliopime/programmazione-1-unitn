#include <iostream>
#include <cstring>
#include "coda.h"

using namespace std;


int main() {

    init();

    cout << "inserisci: " << endl;
    cout << "- 'r1' per rimuovere un cliente dallo sportello S1" << endl;
    cout << "- 'r2' per rimuovere un cliente dallo sportello S2" << endl;
    cout << "- 's1' per stampare a video il primo cliente della sotto-coda allo sportello S1" << endl;
    cout << "- 's2' per stampare a video il primo cliente della sotto-coda allo sportello S2" << endl;
    cout << "- 'p' per stampare a video entrambe le sotto-code" << endl;
    cout << "- 'c' per aggiungere un nuovo cliente alla sotto-coda più corta" << endl;
    cout << "- 'e' per terminare il programma" << endl;

    bool esci = false;
    char input[3];
    int contatore = 1;

    while (!esci) {

        cout << "Il tuo comando: ";
        cin >> input;


        /** Rimozione da S1 */
        if (strcmp(input, "r1") == 0) {
            int primoS1;
            if (firstS1(primoS1)) {
                dequeueS1();
                cout << "abbiamo rimosso il cliente con il numero " << primoS1 << endl;
            } else {
                cout << "La sotto-coda allo sportello S1 è vuota" <<  endl;
            }
        }


            /** Rimozione da S2 */
        else if (strcmp(input, "r2") == 0) {
            int primoS2;
            if (firstS2(primoS2)) {
                dequeueS2();
                cout << "abbiamo rimosso il cliente con il numero " << primoS2 << endl;
            } else {
                cout << "La sotto-coda allo sportello S2 è vuota" <<  endl;
            }
        }


            /** Primo elemento di S1 */
        else if (strcmp(input, "s1") == 0) {
            int primoS1;
            if (firstS1(primoS1)) {
                cout << "Il primo elemento in S1 è il cliente con il numero " << primoS1 << endl;
            } else {
                cout << "La sotto-coda allo sportello S1 è vuota" <<  endl;
            }
        }


            /** Primo elemento di S2 */
        else if (strcmp(input, "s2") == 0) {
            int primoS2;
            if (firstS2(primoS2)) {
                cout << "Il primo elemento in S2 è il cliente con il numero " << primoS2 << endl;
            } else {
                cout << "La sotto-coda allo sportello S2 è vuota" <<  endl;
            }
        }


            /** Stampa a video */
        else if (strcmp(input, "p") == 0) {
            print();
        }


            /** Inserimento di un cliente */
        else if (strcmp(input, "c") == 0) {
            bool result = enqueue(contatore);
            if (result) {
                cout << "Abbiamo inserito il cliente numero " << contatore << endl;
                contatore++;
            } else {
                cout << "C'è stato un errore nell'inserimento del cliente numero " << contatore << endl;
            }
        }


            /** Uscita del programma */
        else if (strcmp(input, "e") == 0) {
            cout << "Uscita del programma" << endl;
            esci = true;
        }


            /** Opzione non valida */
        else {
            cout << "Opzione non valida" << endl;
        }
    }

    deinit();

    return 0;
}
