#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main (){

   char conversione[1];

   int numero;
    
    char binario[1000];

    char* ottale = NULL; 
    int size = 0;

    char* esadecimale = NULL;
    int sizeESA =0;
        
    char base[3];

    float resto;
    
    char b[]= "1";
    char o[]= "2";
    char e[]= "3";

    printf("-->[1] scegli se vuoi vonvertire da decimale alle altre basi\n     \n-->[2] dalle basi al decimale corrispondente\n");
    scanf("%s", &conversione);
    
    if(strcmp(conversione, "2")==0){

        printf("inserisci la base con cui vuoi fare la conversione:\n-->[1] BIN\n-->[2] OTT\n-->[3] ESA\n");
        scanf("%s", &base);

        if(strcmp(base, b) == 0){
            char numeroBinario[65];
            int lunghezza, i;
            long long decimale = 0;

            // Chiedi all'utente di inserire un numero binario
            printf("Inserisci un numero binario:\n");
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
            printf("Il numero binario in decimale è:\n%lld\n", decimale);
        }else if(strcmp(base, o) == 0){
            
            int numOtt;
            int numeroDecimale = 0;
            int posizione = 0;

            printf("inserisci il numero in ottale:\n");
            scanf("%d", &numOtt);

            while(numOtt !=0 ){
                int cifra = numOtt % 10;
                numeroDecimale += cifra * pow(8, posizione);
                numOtt /= 10;
                posizione++;
            }

            printf("il numero in decimale corrispondente è:\n%d", numeroDecimale);



        }else if(strcmp(base, e) == 0){
            char numero_esadecimale[100];
            long numero_decimale; 

            // Richiesta all'utente di inserire un numero esadecimale
            printf("Inserisci un numero esadecimale:\n");
            scanf("%s", numero_esadecimale);

            // Converte il numero esadecimale in un numero decimale utilizzando strtol
            numero_decimale = strtol(numero_esadecimale, NULL, 16);

            // Stampa il numero decimale risultante
            printf("Il numero decimale corrispondente è:\n%ld\n", numero_decimale);
        }
    }else{
        strcpy(binario, "");

        printf("inserisci un numero decimale:\n");

        scanf("%d", &numero);

        printf("scrivi se vuoi il risultato in:\n-->[1] BIN\n-->[2] OTT\n-->[3] ESA\n");

        scanf("%s", &base);

        if(strcmp(base, b) == 0){
            while(numero!=0){
                if(numero %2 == 0){
                    numero = numero /2;
                    char zero[]="0";
                    int lunghezzaStringa, i;
                    
                    lunghezzaStringa = strlen(binario);

                    for(i = 0; zero[i] != '\0'; i++) {
                        binario[lunghezzaStringa + i] = zero[i];
                    }

            
                    binario[lunghezzaStringa + i] = '\0';
                }else{
                    numero = numero / 2;
                    char uno[]="1";
                    int lunghezzaStringa, i;
        
                    lunghezzaStringa = strlen(binario);

                    for(i = 0; uno[i] != '\0'; i++) {
                        binario[lunghezzaStringa + i] = uno[i];
                    }

            
                    binario[lunghezzaStringa + i] = '\0';
                }
            }
            int lunghezza = strlen(binario);
            int e, j;

            for(e = 0, j = lunghezza - 1; e < j; e++, j--) {
                char temp = binario[e];
                binario[e] = binario[j];
                binario[j] = temp;
            }
            printf("il numero binario corrispondente é:\n%s\n", binario);
        }else  if(strcmp(base, o) == 0){
            while(numero!=0){
                ottale = (char*)realloc(ottale, (size + 1) * sizeof(char));

                int risultato = numero%8;            
                numero = numero/8;

                ottale[size] = '0' + risultato;
                
                size++;
                
            }
                int lunghezza = strlen(ottale);
                int e, j;

                for(e = 0, j = lunghezza - 1; e < j; e++, j--) {
                    char temp = ottale[e];
                    ottale[e] = ottale[j];
                    ottale[j] = temp;
                }
            printf("il numero ottale corrispondente è:\n%s\n", ottale);
            free(ottale);

        }else  if(strcmp(base, e) == 0){
            while(numero!=0){
                esadecimale = (char*)realloc(esadecimale, (size + 1) * sizeof(char));

                int risultato = numero%16;            
                numero = numero/16;

                if (risultato >= 10 && risultato <= 15) {
                    esadecimale[sizeESA] = 'A' + (risultato - 10);
                } else {
                    esadecimale[sizeESA] = '0' + risultato;
                }

                sizeESA++;

                int lunghezza = strlen(esadecimale);
                int e, j;

                for(e = 0, j = lunghezza - 1; e < j; e++, j--) {
                    char temp = esadecimale[e];
                    esadecimale[e] = esadecimale[j];
                    esadecimale[j] = temp;
                }

            }
            printf("il numero esadecimale corrispondente è:%s\n", esadecimale);
            free(esadecimale);
        }
        return 0;
    }
}