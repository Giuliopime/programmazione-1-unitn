// STREAM INPUT OUTPUT
#include <iostream> // Includo la libreria di input output, serve per l'istruzione cout
// 'using namespace std;' è considerato "bad practice" --> https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

int main() {
    char carattere = 'a';
    /*
        Per usare cout devo usare il namespace std:: oppure includere nel file il codice 'using namespace std;'
        
    */
    std::cout << carattere; // Stampo in output il valore della variabile c

    // Ricevo in input un carattere
    char inputCarattere;    // Creo la variabile che conterrà l'input
    std::cin >> inputCarattere;    // Richiedo l'input all'utente
    std::cout << inputCarattere;    // Stampo l'input ricevuto

    return 0; // La funzione si aspetta un valore di ritorno intero (int)
}