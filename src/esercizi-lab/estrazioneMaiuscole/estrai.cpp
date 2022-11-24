#include "estrai.h"

void estrai_lettera(char* stringa, int idx, char* risultato, int idx_r) {
    if (stringa[idx] ==  '\0')
        risultato[idx_r] = '\0';
    else {
        if (stringa[idx] >= 'A' && stringa[idx] <= 'Z') {
            risultato[idx_r] = stringa[idx];
            idx_r++;
        }
        estrai_lettera(stringa, idx+1, risultato, idx_r);
    }
}

char* estrai_stringa(char *stringa) {
    char *risultato = new char[256];
    estrai_lettera(stringa, 0, risultato, 0);
    return risultato;
}