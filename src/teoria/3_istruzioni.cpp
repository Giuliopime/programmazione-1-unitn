void istruzioni() {
    // Espressione condizionale
    double prezzo, valore, peso;
    peso = 20;
    // prezzo = valore * peso * 0.9;
    prezzo = valore * peso * (peso > 10) ? 0.9 : 1;

    peso = 8;
    // prezzo = valore * peso * 2020;
    prezzo = valore * peso * (peso > 10) ? 0.9 : 1;


    // Istruzione condizionale
    // If
    bool espressione;
    int secondaEspressione;
    if (espressione) {
        // Esegui questo codice
    } else if (secondaEspressione == 3) {
        // Esegui questo codice
    } else {
        // Se nessuna espressione è stata soddisfatta esegui questo
    }

    // Switch
    int risultato;
    switch (secondaEspressione) {
        case 1: risultato = 45 break; // break serve altrimenti viene eseguito anche il case successivo
        case 2: risultato = 12 break;
        default: risultato = 0;
    }

    // Istruzioni iterative
    // While
    int contatore = 0;
    while(contatore < 10) {
        // Fai qualcosa
        contatore++;
    }

    // Do while
    // Prima esegue e poi controlla l'espressione
    do {
        // Esegue anche se contatore = 0 alla prima iterazione
    } while (contatore < 0);

    // For
    for (int countdown=10; countdown>0; countdown++) {
        // Fai qualcosa
        countdown--;
    }

    // NON SI PUÒ USARE ALL'ESAME
    // Istruzioni di salto (da evitare)
    while(true) {
        break; // Termina tutto il ciclo
        continue; // Termina l'iterazione in esecuzione e passa alla successiva
        return; // Termina l'intera funzione e quindi anche il ciclo
    }


}