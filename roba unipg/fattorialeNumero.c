#include <stdio.h>

int main(){
    
    int numero;
    long fattoriale=1;
    
    printf("inserisci un numero: ");
    scanf("%d", &numero);

    for(int i = 1; i <= numero ; i++){
        fattoriale = fattoriale * i;

    }

    printf("%d", fattoriale);

    
    return 0;
}