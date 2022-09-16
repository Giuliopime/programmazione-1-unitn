/*
    Scrivere un programma che, dato in input il raggio,
    calcoli l'area e la circonferenza di un cerchio.
*/

#include <iostream>

// Dichiaro una costante che contiene il valore di pi greco
const float PI = 3.14f;

int main() {
    double raggio;    // Dichiaro la variabile per prendere in input il raggio dell'utente
    std::cin >> raggio; // Prendo in input il valore e lo assegno alla variabile creata sopra

    const double area = PI*raggio*raggio; // Calcolo l'area
    std::cout << "Area = " << area << std::endl; // Stampo l'area calcolata

    const double circonferenza = 2*PI*raggio; // Calcolo la circonferenza
    std::cout << "Circonferenza = " << circonferenza << std::endl; // Stampo la circonferenza
}
