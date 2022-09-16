/*
    Scrivere un programma che, data in input una temperatura in Fahrenheit,
    ritorni a video il corretto valore in Celsius.
*/

#include <iostream>

int main() {
    float fahrenheit;   // Uso float perchè in genere le temperature richiedono poche cifre dopo la virgola
    std::cin >> fahrenheit;

    const float celsius = (fahrenheit - 32) / 1.8;
    std::cout << "Conversione in celsius = " << celsius << std::endl;
}
