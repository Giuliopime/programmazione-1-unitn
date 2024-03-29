#include "calcolatore_rpn.h"
#include "entry.h"
#include "stack.h"

static void Cancella() { // Stampa 10 new line per simulare clean del terminale
  for (int i = 0; i < 10; i++)
    cout << '\n';
}

int calcolatore() {
  entry e, op1, op2;
  retval res;

  init();
  do {
    print();
    res = read_entry(e);
    if (res == FAIL) {
      Cancella();
      cout << "!!! Tipo di dato errato !!!\n";
    }
    // SWITCH OFF
    else if (offp(e)) {
      // Non fare nulla
    }
    // NUMBER
    else if (!operatorp(e)) {
      res = push(e);
      Cancella();
      if (res == FAIL) {
        cout << "!!! Troppi dati nello stack !!!\n";
      }
    }
    // OPERATOR
    else if (length() < 2) {
      Cancella();
      cout << "!!! Troppo pochi operandi !!!\n";
    } else {
      top(op1);
      pop();
      top(op2);
      pop();
      push(calcola(op1, op2, e));
      Cancella();
    }
  } while (!offp(e));
  deinit();
  return 0;
}
