#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>


int main() {
    // Dichiarazione della stringa di input
    char input[100];
    // Richiesta all'utente di inserire una stringa di testo
    printf("Inserisci una stringa di testo: ");
    fgets(input, sizeof(input), stdin);
    // Rimuovi il carattere newline dalla stringa di input
    size_t lunghezza_input = strlen(input);
    if (input[lunghezza_input - 1] == '\n') {
        input[lunghezza_input - 1] = '\0';
    }
    // Allocazione dinamica di un vettore per contenere la stringa
    char *vettore = (char *)malloc((lunghezza_input + 1) * sizeof(char));

    // Copia la stringa di input nel vettore dinamico
    strcpy(vettore, input);
    
    for(int i=0; i<strlen(vettore); i++){
        char carattere = tolower(vettore[i]);
         if (isalpha(carattere)) {
            // Stampa il numero corrispondente della lettera
            printf("%d", carattere - 'a' + 1);

            // Aggiungi uno spazio dopo ogni numero, tranne l'ultimo
            if (i < lunghezza_input - 1) {
                printf(" ");
            }
        }
        
    }
    
    free(vettore);

    return 0;
}
