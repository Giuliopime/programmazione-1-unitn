#include "iostream"
#include <cstdlib>
using namespace std;

int roll();

int main() {
    srand(time(NULL));

    int toBeGuessed = 1;
    int ones = 0;
    for (int i=0; i<=5; i++) {
        int diceRes = roll();
        if (diceRes == toBeGuessed)
            ones++;
    }

    cout << "How many dices do you thing rolled a " << toBeGuessed << "?" << endl;
    int guess;
    cin >> guess;

    if (guess == ones)
        cout << "You guessed correct!" << endl;
    else
        cout << "You guessed wrong, the dice rolled a " << toBeGuessed << " " << ones << " times" << endl;
}

int roll() {
    return rand() % 6 + 1;
}