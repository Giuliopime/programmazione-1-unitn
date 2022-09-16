#include <iostream>

int main() {
    int dividendo;
    int divisore;

    std::cin >> dividendo;
    std::cin >> divisore;

    int quoziente = dividendo / divisore;
    double resto = dividendo % divisore;

    std::cout << "Quoziente = " << quoziente << std::endl;
    std::cout << "Resto = " << resto << std::endl;
}
