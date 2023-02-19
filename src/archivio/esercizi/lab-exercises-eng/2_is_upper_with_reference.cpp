#include "iostream"
using namespace std;

bool isLowercase(char c);
void makeUppercase(char &l);

int main() {
    char c;
    cout << "Insert a character" << endl;
    cin >> c;

    bool isLower = isLowercase(c);
    if (isLower)
        makeUppercase(c);

    cout << "It was " << (isLower ? "lowercase" : "already uppercase") << endl;

    if (isLower)
        cout << "Result transformation: " << c << endl;

    return 0;
}

bool isLowercase(char c) {
    return c >= 'a' && c <= 'z';
}

void makeUppercase(char &l) {
    l = l + ('A' - 'a');
}