#incluse <iostream>

int main() {
    double raggio;
    std::cin >> raggio;

    double volume = 4 / 3 * raggio * 3.14;
    std::cout << "Volume = " << volume << std::endl;
}
