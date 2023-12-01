#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


int main(){
    int numero;
    printf("inserisci il numero con cui vuoi creare il quadrato: \n");
    scanf("%d", &numero);

    int lunghezza = numero*2-1;
    char quadrato[lunghezza][lunghezza];

    for(int i = 0; i< lunghezza; i++){
        for(int j = i; j < lunghezza -i; j ++){
            quadrato[i][j] = '0' + numero -i;
            quadrato[lunghezza -i -1][j] = '0'+ numero -i;
            quadrato[j][i] = '0' + numero -i;
            quadrato[j][lunghezza -i -1] = '0' + numero - i;
        } 
    }
    for(int f = 0; f < lunghezza; f++){
        for(int t = 0; t < lunghezza; t++){
            printf("%c ", quadrato[f][t]);
        }
        printf("\n");
    }
    return 0;
}