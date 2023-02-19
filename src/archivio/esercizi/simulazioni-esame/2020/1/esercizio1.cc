#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// La funzione non va modificata, pena l'annullamento dell'esercizio
void sort_array(int * array, int len_array) {
    for (int i=0; i<len_array; i++) {
        for (int j=0; j<len_array; j++) {
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    const char* OUTPUT_FILE_NAME = "output.txt";

    if (argc !=  4) {
        cout << "Usage: ./a.out <file> <dim> <n>";
        exit(1);
    }

    int initLength = atoi(argv[2]);
    int desiredLength = atoi(argv[3]);

    if (desiredLength > initLength) {
        cout << "La dimensione desiderata deve essere minore della dimensione corrente" << endl;
        exit(1);
    }

    fstream input, output;

    input.open(argv[1], ios::in);
    if (input.fail()) {
        cout << "Il file non esiste" << endl;
        exit(1);
    }

    output.open(OUTPUT_FILE_NAME, ios::out);
    if (output.fail()) {
        cout << "Non posso creare file" << endl;
        exit(1);
    }

    int* votes = new int[initLength];

    for(int i=0; i<initLength; i++) {
        if (input.eof()) {
            cout << "Quantita' di voti errata" << endl;
            exit(1);
        }
        input >> votes[i];
    }
    input.close();

    sort_array(votes, initLength);

    for (int i=0; i<desiredLength; i++) {
        output << votes[i] << endl;
    }

    output.close();

    cout << "Elaborazione voti completata" << endl;
}