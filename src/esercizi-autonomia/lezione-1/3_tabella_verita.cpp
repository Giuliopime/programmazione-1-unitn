#include <iostream>

using namespace std;

int main() {
    bool a = 0;
    bool b = 0;

    cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << endl;

    a = 1;
    b = 0;
    cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << endl;

    a = 0;
    b = 1;
    cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << endl;

    a = 1;
    b = 1;
    cout << "a = " << a << ", b = " << b << ", a && b = " << (a && b) << ", a || b = " << (a || b) << endl;
}
