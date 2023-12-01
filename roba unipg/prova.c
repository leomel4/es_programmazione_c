#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    /*
    char numeroBinario[65];
    int lunghezza, i;
    long long decimale = 0;

    // Chiedi all'utente di inserire un numero binario
    printf("Inserisci un numero binario: ");
    scanf("%s", numeroBinario);

    // Calcola la lunghezza del numero binario
    lunghezza = strlen(numeroBinario);

    // Verifica se il numero è negativo
    int isNegativo = 0;
    if (numeroBinario[0] == '1') {
        isNegativo = 1;
        // Inverti i bit per ottenere il complemento a 1
        for (i = 0; i < lunghezza; i++) {
            numeroBinario[i] = (numeroBinario[i] == '1') ? '0' : '1';
        }
        // Aggiungi 1 per ottenere il complemento a 2
        for (i = lunghezza - 1; i >= 0; i--) {
            if (numeroBinario[i] == '0') {
                numeroBinario[i] = '1';
                break;
            } else {
                numeroBinario[i] = '0';
            }
        }
    }

    // Converte il numero binario in decimale
    for (i = lunghezza - 1; i >= 0; i--) {
        if (numeroBinario[i] == '1') {
            decimale += pow(2, lunghezza - 1 - i);
        }
    }

    // Se il numero è negativo, rendi il risultato negativo
    if (isNegativo) {
        decimale = -decimale;
    }

    // Stampa il risultato
    printf("Il numero binario in decimale è: %lld\n", decimale);
    */

    /*char a;

    printf("inserisci un numero: ");
    scanf("%s", &a);
    int lunghezza = strlen(a);
    printf("%d", lunghezza);
    return 0;*/


    /*int a = 1231242;

    // Determina la lunghezza della stringa risultante
    int lunghezza = snprintf(NULL, 0, "%d", a);

    // Alloca dinamicamente il vettore di caratteri
    char *numOtt = (char *)malloc((lunghezza + 1) * sizeof(char)); // +1 per il terminatore di stringa '\0'

    // Controlla se l'allocazione di memoria è riuscita
    if (numOtt == NULL) {
        printf("Errore: impossibile allocare memoria\n");
        return 1;
    }

    // Converti l'intero in una stringa di caratteri
    snprintf(numOtt, lunghezza + 1, "%d", a);

    // Stampa il vettore di caratteri
    printf("numOtt: %s\n", numOtt[1]);

    // Libera la memoria allocata dinamicamente
    free(numOtt);

    return 0;*/

/*
    char comando[] = "ls -l"; // Esempio di comando Bash da eseguire
    char buffer[128]; // Buffer per leggere l'output del comando

    // Apre un processo in modalità di lettura del comando Bash
    FILE *file = popen(comando, "r");
    if (file == NULL) {
        fprintf(stderr, "Errore durante l'apertura del processo.\n");
        return 1;
    }

    // Legge l'output del comando linea per linea e stampa ciascuna linea
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Chiude il processo
    pclose(file);*/

  /*  char numero_esadecimale[20]; // Dichiarazione di un array di caratteri per memorizzare il numero esadecimale
    long numero_decimale; // Variabile per memorizzare il numero decimale convertito

    // Richiesta all'utente di inserire un numero esadecimale
    printf("Inserisci un numero esadecimale: ");
    scanf("%s", numero_esadecimale);

    // Converte il numero esadecimale in un numero decimale utilizzando strtol
    numero_decimale = strtol(numero_esadecimale, NULL, 16);

    // Stampa il numero decimale risultante
    printf("Il numero decimale corrispondente a %s è %ld\n", numero_esadecimale, numero_decimale);*/

    

    /*float numero;
    int parteIntera;
    float parteDecimale;

    // Chiedi all'utente di inserire un numero con la virgola
    printf("Inserisci un numero con la virgola: ");
    scanf("%f", &numero);

    // Converte il numero in parte intera e parte decimale
    parteIntera = (int)numero;
    parteDecimale = numero - parteIntera;

    // Stampa la parte intera e la parte decimale
    printf("Parte intera: %d\n", parteIntera);
    printf("Parte decimale: %f\n", parteDecimale);*/



   char s[] = "acd";
    char d[] = "fgr";
    char j[100]; // Vettore di caratteri per memorizzare il risultato

    // Copia il primo vettore nel risultato
    strcpy(j, s);

    // Concatena il secondo vettore al risultato
    strcat(j, d);

    // Stampa il risultato
    printf("Il risultato è: %s\n", j);



    return 0;

}
