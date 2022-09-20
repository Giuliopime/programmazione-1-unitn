// Una variabile si dichiara come `tipo nome = valore;`
int anno = 2022;
// Può essere resa costante (immodificabile)
const annoNascita = 2003;
// Può essere resa utilizzabile in un altro file del nostro progetto
extern const double piGreco = 3.14;

// Posso assegnare un valore a più variabili
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
--x: // Sottrae di uno, la lettura avviene dopo la sottrazione

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

/*
   short e long sottointendono sempre int
   short equivale a short int
   long equivale a long int
   etc...
*/

// Posso vedere la dimensione di un numero con
int main() {
   sizeof(i)
}

// Posso specificare che sono numeri senza segno con la keyword unsigned
unsigned int senzaSegno;

// Operazioni bit a bit per interi senza segno
int x;
int y;
int n;

x | y; // Or
x & y; // And
x^y; // Xor
~x; // Not
x>>n; // Shift a destra di n posizioni
x<<n; // Shift a sinistra di n posizioni


// Numeri con la virgola
float g = 5.52f; // Numero con la virgola con precisione 7 cifre dopo la virgola, meno del double
double z = 3.2; // Precisione di 15 cifre dopo la virgola
long double ld;

// Booleani: vero o falso
bool veroFalse = true;
// Enum
enum ciao;
// Caratteri
char c = 'a'; // Singolo carattere