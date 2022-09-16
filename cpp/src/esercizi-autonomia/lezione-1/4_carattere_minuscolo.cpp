#include <iostream>

int main() {
    char maiuscolo;
    std::cin >> maiuscolo;

    char minuscolo = maiuscolo + 32;
    std::cout << "Carattere  minuscolo relativo ad " << maiuscolo << " = " << minuscolo << std::endl;
}
