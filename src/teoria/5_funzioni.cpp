#include "cmath"

// Dichiarazione di una funzione
// tipo identificativo(parametri)
// Se il tipo è diverso da void la funzione deve ritornare un valore del dato tipo con l'istruzione return.
int random(int da, int a);

// Stessa funzione ma con parametri diversi
int random(int da, int a, int coefficienteRandomico);

// Dichiarazione e definizione in una sola linea
int calcoloComplesso(char base) {
    return 5643;
}

// Procedure
// Una funzione di tipo void è detta procedura
void nonRitornoNessunValore(int param) {
    int calcolo = log(param);
    int res = sqrt(calcolo);
}

// Parametri
// Stesso identificativo ma parametri diversi
int somma(int a, int b) { return a + b; }
int somma(int a, int b, int c) {return a + b + b; }

// Valori di default
int potenza(int x, int exp = 2) { return pow(x, exp); }

// Tipologia dei parametri
void perValore(int x) {}

void perRiferimento(int& x) {
    // Non crea la variabile x localmente all'interno della funzione ma usa direttamente l'indirizzo di quella originale ricevuta dalla chiamata della funzione
}

void perRiferimentoCostante(const int& x) {
    // x non può essere modificata
}

void perPuntatori(int* x) {
    // Ricevo un puntatore ad un indirizzo in memoria
}


// Funzioni ricorsive
int ricorsiva(int n) {
    int calcolo = ricorsiva(n); // richiama se stessa (in questo caso loop infinito)
    return calcolo;
}

int main() {
    // Libreria: Insieme di funzioni precompilate
    // Esempio chiamata di funzioni di libraria
    sqrt(100); // calcola la radice di 100
    log(25); // logaritmo naturale di 25

    // Chiamata di funzione
    int risultatoRandom = random(2, 10);

    // Tipologia di parametri
    // Per valore
    int x = 10;
    perValore(x);
    perRiferimento(x);
    perRiferimentoCostante(x);
    perPuntatori(&x);

    return 0;
}

// Definizione di una funzione
int random(int da, int a) {
    return 5; // Non molto random questo random ma non è lo scopo di questo file
}