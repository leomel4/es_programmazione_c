#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


int main(){
    
    char conversione [1]; 
    printf("[1]  conversione decimale con virgola a binario con virgola\n[2]  conversione binario con virgola a decimale con virgola\n");
    scanf("%s", &conversione);

    if(strcmp(conversione, "1")==0){
        float numero;
        printf("inserisci un numero con la virgola: ");
        scanf("%f", &numero);

        int parteIntera = (int)numero;
        float parteDecimale = numero -parteIntera;
        
        char binarioItero [1000];
        char binarioDecimale [1000];
        char bina [1000];
        char punto [] = ".";

        strcpy(binarioItero, "");
        strcpy(binarioDecimale, "");

        //int binarioDecimale;

        while(parteIntera!=0){
                    if(parteIntera %2 == 0){
                        parteIntera = parteIntera /2;
                        char zero[]="0";
                        int lunghezzaStringa, i;
                        
                        lunghezzaStringa = strlen(binarioItero);

                        for(i = 0; zero[i] != '\0'; i++) {
                            binarioItero[lunghezzaStringa + i] = zero[i];
                        }


                        binarioItero[lunghezzaStringa + i] = '\0';
                    }else{
                        parteIntera = parteIntera / 2;
                        char uno[]="1";
                        int lunghezzaStringa, i;
            
                        lunghezzaStringa = strlen(binarioItero);

                        for(i = 0; uno[i] != '\0'; i++) {
                            binarioItero[lunghezzaStringa + i] = uno[i];
                        }

                        binarioItero[lunghezzaStringa + i] = '\0';
                    }
        }
        int lunghezza = strlen(binarioItero);
        int e, j;
        
        for(e = 0, j = lunghezza - 1; e < j; e++, j--) {
            char temp = binarioItero[e];
            binarioItero[e] = binarioItero[j];
            binarioItero[j] = temp;
        }
        int contatore;
        while(contatore != 8){
            float n = parteDecimale * 2;
            int bin = (int)n;
            if(bin == 0){
                char zero[]="0";
                int lunghezzaStringa, i;
                        
                lunghezzaStringa = strlen(binarioDecimale);

                for(i = 0; zero[i] != '\0'; i++) {
                    binarioDecimale[lunghezzaStringa + i] = zero[i];
                }
                binarioDecimale[lunghezzaStringa + i] = '\0';
            }else{
                char uno[]="1";
                int lunghezzaStringa, i;
                        
                lunghezzaStringa = strlen(binarioDecimale);

                for(i = 0; uno[i] != '\0'; i++) {
                    binarioDecimale[lunghezzaStringa + i] = uno[i];
                }
                binarioDecimale[lunghezzaStringa + i] = '\0';
            }
            
            parteDecimale = n - (int)n;
            contatore++;

        }
        //copia 
        strcpy(bina, binarioItero);
        //concatena
        strcat(bina, punto);
        strcat(bina, binarioDecimale);
        
        printf("%s\n", bina);
    }else{
        char numeroBinarioVirgola[100];
        
        char numeroBinarioDecimale[100];
        char numeroBinarioIntero[100];
        strcpy(numeroBinarioDecimale, "");
        strcpy(numeroBinarioIntero, "");

        printf("inserisci un numero binario con la virgola: ");
        scanf("%s", &numeroBinarioVirgola);
    
        bool trovato = false;
        
        for(int i = 0, e= 0; i < strlen(numeroBinarioVirgola); i++){
            //non usare "" perché una stringa, io devo controllare con un carattere ''
            if(numeroBinarioVirgola[i] != '.' && trovato != true){
                numeroBinarioIntero[i]= numeroBinarioVirgola[i];
                numeroBinarioIntero[i+1]= '\0';
                
            }else{
                numeroBinarioDecimale[e]= numeroBinarioVirgola[i];
                numeroBinarioDecimale[e+1] = '\0';
                trovato = true;
                e++;
            }
        }
        int intero;
        int i, lunghezzaIntero;
        lunghezzaIntero = strlen(numeroBinarioIntero);
        for (i = lunghezzaIntero - 1; i >= 0; i--) {
                if (numeroBinarioIntero[i] == '1') {
                    intero += pow(2, lunghezzaIntero - 1 - i);
                    
                }
            }
        
        float decimale;
        int x, lunghezzaDecimale;
        lunghezzaDecimale = strlen(numeroBinarioDecimale);
        for(x=1; x<lunghezzaDecimale; x++){
            if(numeroBinarioDecimale[x]== '0'){
                decimale += 0/pow(2,x);
            }else if(numeroBinarioDecimale[x]== '1'){
                decimale += 1/pow(2,x);
            }
           

        }
        float riss = intero+decimale;
        printf("%f\n", riss);
    }

    


    
    return 0;

}



