#include "iostream"
using namespace std;

struct data {
    int giorno, mese, anno;
};

struct persona {
    char nome[25], cognome[25];
    char comune_nascita[25];
    data data_nascita;
    enum { F, M } sesso;
};

struct conArrayDin {
    int* arrayDin;
};

int main() {
    persona giulio = {
            "Giulio",
            "Pimenoff Verdolin",
            "Minerbe",
            data { 29, 9, 2003 },
            persona::M
    };

    cout << giulio.nome;

    // Per puntatore
    persona* puntatoreGiulio = &giulio;
    puntatoreGiulio->data_nascita = data { 29, 9, 2003};

    cout << puntatoreGiulio->nome;

    // Posso copiare le struct
    persona cloneDiGiulio = giulio;

    // Array dinamici
    conArrayDin cad, cad2;

    cad.arrayDin = new int[giulio.data_nascita.giorno];
    // Viene copiato il puntatore dell'array dinamico
    // Quindi cad.arrayDin e cad2.arrayDin sono lo stesso array
    cad2 = cad;

    // Array di persone
    int numeroPersone = 23;
    // Molto più efficiente lavorare con puntatori
    persona* persone[23];

    for(int i=0; i<numeroPersone; i++) {
        cout << persone[i]->nome;
    }

    return 0;
}

void ricevoStruct(persona p) {}