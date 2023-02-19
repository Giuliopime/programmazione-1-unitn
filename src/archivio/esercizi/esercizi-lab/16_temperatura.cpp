#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Questa funzione ordina un array. Implementa l'algoritmo
// bubblesort
void sort_array(float array [], int length)
{
    for(int i=0; i<length-1; i++) {
        for (int j=0; j<length-1; j++) {
            if (array[j] < array[j+1]) {
                float tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

int main(int argc, char * argv []) {

    if (argc != 4) {
        cout << "Usage: temp <file> <dim> <n>" << endl;
        exit(0);
    }

    fstream input;
    int DIM = atoi(argv[2]);

    // Definisco un array dinamico in cui andremo a salvare
    // le temperature del file
    float * temperature = new float[DIM];

    int temp_contatore = 0;

    input.open(argv[1], ios::in);
    if (input.fail()) {
        cout << "Il file selezionato non esiste" << endl;
        exit(0);
    }

    char tmp[256];
    while(input >> tmp) {
        temperature[temp_contatore] = atof(tmp);
        temp_contatore++;
    }

    sort_array(temperature, DIM);

    for(int i=0; i<atoi(argv[3]); i++) {
        cout << i+1 << ": " << temperature[i] << endl;
    }

    delete[] temperature;
    input.close();

    return 0;
}
