#include <stdio.h>


int main(){

    FILE *fp;
    char ch;
    fp = fopen("angelicaDiritti.txt","w");
    if (fp == NULL) {
        printf("Impossibile aprire il file di input.\n");
        return 1;
    }
    for (int i = 0; i < 9999999; i++) {
        fprintf(fp, "NEESSUN DIRITTO\n");
    }

    
    fclose(fp);

    printf("Il file è stato creato con successo.\n");

    return 0;
}