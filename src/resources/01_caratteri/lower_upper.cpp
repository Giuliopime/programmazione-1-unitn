/**
 * Converte un carattere da uppercase a lowercase in caso sia compreso tra 'A' e 'Z'
 *
 * @param carattere Il carattere da trasformare
*/
char to_lower(char carattere) {
  if (carattere >= 'A' && carattere <= 'Z')
    return (char) (carattere - 'A') + 'a';
  
  return carattere;
}

/**
 * Converte un carattere da lowercase a uppercase in caso sia compreso tra 'a' e 'z'
 *
 * @param carattere Il carattere da trasformare
*/
char to_upper(char carattere) {
  if (carattere >= 'a' && carattere <= 'z')
    return (char) (carattere - 'a') + 'A';
  
  return carattere;
}

/**
 * Converte un carattere da lowercase a uppercase o viceversa a seconda del carattere fornito
 *
 * @param carattere Il carattere da trasformare
*/
char switch_char_case(char carattere) {
  if (carattere >= 'A' && carattere <= 'Z')
    return (char) (carattere - 'A') + 'a';
  else if (carattere >= 'a' && carattere <= 'z')
    return (char) (carattere - 'a') + 'A';
  
  return carattere;
}