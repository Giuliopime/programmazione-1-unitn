#include "iostream"
#include<algorithm>
using namespace std;

int main() {
    srand(time(NULL));

    int atk1 = rand() % 6 + 1;
    int atk2 = rand() % 6 + 1;
    int def1 = rand() % 6 + 1;
    int def2 = rand() % 6 + 1;

    int maxAtk = max(atk1, atk2);
    int minAtk = maxAtk == atk1 ? atk2 : atk1;

    int maxDef = max(def1, def2);
    int minDef = maxDef == def1 ? def2 : def1;

    int wonAtk = 0;
    int wonDef = 0;

    if (maxAtk > maxDef)
        wonAtk++;
    else
        wonDef++;

    if (minAtk > minDef)
        wonAtk++;
    else
        wonDef++;

    cout << "Attacker won " << wonAtk << " roll/s while defender won " << wonDef << " time/s" << endl;
}