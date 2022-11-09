#include "fstream"
#include "iostream"
using namespace std;

int main(int argc, char * argv[]) {
    // Argomenti da linea di comando
    /**
     * l’intero argc, in cui viene automaticamente copiato il numero delle parole della riga di comando (“./a.out” o analogo inclusa)
     * l’array di puntatori a caratteri (stringhe) argv in cui vengono automaticamente copiate le parole della linea di comando
     */

    fstream input, output, append;
    input.open("ingresso.txt", ios::in); // Lettura
    output.open("uscita.txt",ios::out); //scrittura
    append.open("uscita2.txt",ios::out|ios::app); // append (puntatore si posiziona alla fine di uno stream)

    char testo[256];
    input >> testo;

    char modifica[] = "Hello world!";
    output << modifica;

    input.close();
    output.close();
    append.close();

    // Passagio nomi file da riga di comando
    if (argc != 2) {
        cerr << "Usage: ./a.out <source>\n";
        exit(0);
    }

    fstream inputFile;
    inputFile.open(argv[1], ios::in);

    if (inputFile.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        exit(0);
    }

    return 0;
}
