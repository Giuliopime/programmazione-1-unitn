#include "iostream"
using namespace std;

void revert(int number);

int main() {
    int number;
    cout << "Insert a number to revert" << endl;
    cin >> number;

    revert(number);

    return 0;
}

void revert(int number) {
    while (number > 0) {
        int digit = (number % 10);
        number /= 10;
        cout << digit;
    }
}