#include "iostream"
using namespace std;

bool isLowercase(char c);
char makeUppercase(char l);

int main() {
    char c;
    cout << "Insert a character" << endl;
    cin >> c;

    bool isLower = isLowercase(c);
    if (isLower)
        c = makeUppercase(c);

    cout << "It was " << (isLower ? "lowercase" : "already uppercase") << endl;

    if (isLower)
        cout << "Result transformation: " << c << endl;

    return 0;
}

char makeUppercase(char l) {
    return l + ('A' - 'a');
}

bool isLowercase(char c) {
return c >= 'a' && c <= 'z';
}