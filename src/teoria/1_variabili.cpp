int main() {
    // Una variabile si dichiara come `tipo nome = valore;`
    int anno = 2022;
    // Può essere resa costante (immodificabile)
    const int annoNascita = 2003;
    // Può essere resa utilizzabile in un altro file del nostro progetto
    extern const double piGreco;

    // Posso assegnare un valore a più variabili
    int x, y, a, b;
    x = y = a = b = 5;

    /*
       Operatori:
       + piu
       - meno
       * per
       / diviso
       % modulo
    */

    // Operatori misti: assegnazione & aritmentica:
    x += y; // x = x+y;
    x -= y; // x = x-y;
    x *= y; // x = x*y;
    x /= y; // x = x/y;
    x %= y; // x = x%y;

    // Operatori di incremento e decremento unitario
    // Vanno evitati nelle sotto espressioni, esempio: x = j++ * i++;
    x++; // Incrimenta di uno, la lettura avviene prima dell'incremento
    x--; // Sottrae di uno, la lettura avviene prima della sottrazione
    ++x; // Incrimenta di uno, la lettura avviene dopo l'incremento
    --x; // Sottrae di uno, la lettura avviene dopo la sottrazione

    // Operatori relazionali
    x == y; // uguale
    x != y; // diverso
    x <= y; // minore uguale
    x >= y; // maggiore uguale
    x < y; // minore
    x > y; // maggiore

    // Tipi

    // Numeri interi
    short s; // Tipicamente non più di 16 bit
    int i = 34; // Tipicamente almeno 16 bit
    long l; // Tipicamente almeno 32 bit
    long long ciao; // Tipicamente almeno 64 bit

    sizeof(double); // Controlla la dimensione in byte di un espressione
    sizeof(i);

    /*
       short e long sottointendono sempre int
       short equivale a short int
       long equivale a long int
       etc...
    */

    // Posso specificare che sono numeri senza segno con la keyword unsigned
    unsigned int senzaSegno;

    // Operazioni bit a bit per interi senza segno
    int n;

    x | y; // Or
    x & y; // And
    x ^ y; // Xor
    ~x; // Not
    x >> n; // Shift a destra di n posizioni
    x << n; // Shift a sinistra di n posizioni


    // Numeri con la virgola
    float g = 5.52f; // Numero con la virgola con precisione 7 cifre dopo la virgola, meno del double
    double z = 3.2; // Precisione di 15 cifre dopo la virgola
    long double ld;

    // Posso usare conversioni implicite ed escplicite
    int prezzo = 10;
    float peso = 3.4;
    // Implicita
    int costo = prezzo * peso;
    // Esplicita
    costo = (int) prezzo * peso;
    // Sempre esplicita (funzionale)
    costo = int(prezzo * peso);


    // Booleani: vero o falso
    bool booleano = true;

    // Operatori booleani
    // !x -> Not (ha la priorità nelle espressioni)
    // && -> And
    // !! -> Or

    return 1;
}

// Enum
enum Giorno {
    LUN, MAR, MER, GIO, VEN, SAT, SUN
};
Giorno giorno = LUN;

enum Colore {
    ROSSO=0, VERDE=2, BLU=3
};
Colore sfondo = ROSSO;

// Caratteri
char c = 'c'; // Singolo carattere
// I caratteri possono essere confrontati come i numeri
// In quanto un char fa riferimento al valore sulla tabella dei caratteri (ad esempio ASCII)
char e = c + 2;
bool isLowercase = ((c >= 'a') && (c <= 'z'));
char maiuscolo = c - ('a' - 'A'); // Diventa 'C'