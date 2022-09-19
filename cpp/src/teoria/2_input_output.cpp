// STREAM INPUT OUTPUT
#include <iostream> // Includo la libreria di input output, serve per l'istruzione cout
// 'using namespace std;' è considerato "bad practice" --> https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

int main() {
    char carattere = 'a';
    /*
        Per usare cout devo usare il namespace std:: oppure includere nel file il codice 'using namespace std;'

    */
    std::cout << carattere << std::endl; // Stampo in output il valore della variabile c

    // Stampo piu' messaggi in output
    std::cout << "Il carattere e' ";
    std::cout << carattere;
    std::cout << std::endl;

    // Oppure con un unica riga di codice
    std::cout << "Il carattere e' " << carattere << std::endl;

    // Ricevo in input un carattere
    char inputCarattere;    // Creo la variabile che conterrà l'input
    std::cin >> inputCarattere;    // Richiedo l'input all'utente
    std::cout << inputCarattere << std::endl;    // Stampo l'input ricevuto

    // Ricevo piu' input con un unica riga di codice
    char x;
    double y;
    int z;
    std::cin >> x >> y >> z; // Gestisce in automatico il tipo delle variabili

    return 0; // La funzione si aspetta un valore di ritorno intero (int)
}
