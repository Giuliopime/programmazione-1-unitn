#include <iostream>

int main() {
    bool a = 0;
    bool b = 0;

    std::cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << std::endl;

    a = 1;
    b = 0;
    std::cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << std::endl;

    a = 0;
    b = 1;
    std::cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << std::endl;

    a = 1;
    b = 1;
    std::cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << std::endl;
}
