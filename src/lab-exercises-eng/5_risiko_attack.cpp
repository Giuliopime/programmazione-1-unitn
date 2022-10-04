#include "iostream"
using namespace std;

int main() {
    srand(time(NULL));

    int attacker = rand() % 6 + 1;
    int defender = rand() % 6 + 1;

    if (attacker > defender)
        cout << "The attacker won " << attacker << " to " << defender << endl;
    else if (defender > attacker || defender == attacker)
        cout << "The defender won " << defender << " to " << attacker << endl;

    return 0;
}