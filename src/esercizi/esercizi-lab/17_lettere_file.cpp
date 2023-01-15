#include <iostream>
#include <fstream>

using namespace std;

int ottieni_indice(char lettera);
void stampa_occorrenze(int array [], int size);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: conta <input_file>" << endl;
        exit(0);
    }

    // Conterrà il numero di occorrenze
    int alfabeto[26] = {0};
    char carattere;
    fstream input;

    input.open(argv[1], ios::in);
    if (input.fail()) {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
    }

    while(input.get(carattere)) {
        int indice = ottieni_indice(carattere);
        if (indice != -1)
            alfabeto[indice] += 1;
    }

    stampa_occorrenze(alfabeto, sizeof(alfabeto)/sizeof(alfabeto[0]));

    input.close();

    return 0;
}

void stampa_occorrenze(int array [], int size) {
    for(int i =0; i< size; i++) {
        cout << char(i+'a') << ": " << array[i] << endl;
    }
}

int ottieni_indice(char lettera) {
    int indice = -1;
    if ( lettera >= 'a' && lettera <= 'z')
        indice = lettera - 'a';
    else if ( lettera >= 'A' && lettera <= 'Z')
        indice = lettera - 'A';
    return indice;
}
