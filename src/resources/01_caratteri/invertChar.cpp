
/**
 * Trasforma un carattere nel suo opposto nell'alfabeto.
 * 
 * a --> z, b --> y, x --> c
 * @param carattere Il carattere da trasformare
*/
char invert_char(char carattere) {
    if (carattere >= 'a' && carattere <= 'z')
        return char('a' - carattere + 'z');
    if (carattere >= 'A' && carattere <= 'Z')
        return char('A' - carattere + 'Z');
    if (carattere >= '0' && carattere <= '9') {
        return char('0' - carattere + '9');
    }

    return carattere;
}