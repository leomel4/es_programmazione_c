#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// uso questa libreira per ripulire la stringa inserita dall'utente
#include <ctype.h>
#include <stdbool.h>

char* cifrarioCesare (char *s){
    system("clear");
    printf(" ██████╗███████╗███████╗ █████╗ ██████╗ ███████╗\n");
    printf("██╔════╝██╔════╝██╔════╝██╔══██╗██╔══██╗██╔════╝\n");
    printf("██║     █████╗  ███████╗███████║██████╔╝█████╗  \n");
    printf("██║     ██╔══╝  ╚════██║██╔══██║██╔══██╗██╔══╝  \n");
    printf("╚██████╗███████╗███████║██║  ██║██║  ██║███████╗\n");
    printf(" ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝\n");

    int chiave;
    char cyphertext [strlen(s)];
    printf("scrivi la chiave per il cifrario: ");
    scanf("%d", &chiave);
    for(int i=0 ; i<strlen(s); i++){
            cyphertext[i] = ((s[i] - 'a' + chiave) % 26) + 'a';
            cyphertext[i+1] = '\0';
    }
    for(int e = 0; e< strlen(cyphertext); e++){
        s[e] = cyphertext[e];
    }
    return s;
}
char* cifrarioSostituzione(char *s){

    char alfabeto[26];

    while (1) {
        system("clear");
        printf("███████╗ ██████╗ ███████╗████████╗██╗████████╗██╗   ██╗███████╗██╗ ██████╗ ███╗   ██╗███████╗\n");
        printf("██╔════╝██╔═══██╗██╔════╝╚══██╔══╝██║╚══██╔══╝██║   ██║╚══███╔╝██║██╔═══██╗████╗  ██║██╔════╝\n");
        printf("███████╗██║   ██║███████╗   ██║   ██║   ██║   ██║   ██║  ███╔╝ ██║██║   ██║██╔██╗ ██║█████╗  \n");
        printf("╚════██║██║   ██║╚════██║   ██║   ██║   ██║   ██║   ██║ ███╔╝  ██║██║   ██║██║╚██╗██║██╔══╝  \n");
        printf("███████║╚██████╔╝███████║   ██║   ██║   ██║   ╚██████╔╝███████╗██║╚██████╔╝██║ ╚████║███████╗\n");
        printf("╚══════╝ ╚═════╝ ╚══════╝   ╚═╝   ╚═╝   ╚═╝    ╚═════╝ ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝\n");
        printf("Inserisci l'alfabeto a 26 lettere DIVERSE per cifrare la tua stringa:\n");
        scanf("%s", alfabeto);

        // Controllo la lunghezza della stringa
        if (strlen(alfabeto) != 26) {
            system("clear");
            printf("La stringa deve essere lunga 26.\n");
            continue; // Richiede all'utente di reinserire la stringa
        }
        // Controllo duplicati
        int duplicato = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                if (alfabeto[i] == alfabeto[j]) {
                    duplicato = 1;
                    break;
                }
            }
            if (duplicato) {
                system("clear");
                printf("La stringa contiene duplicati. Riprova.\n");
                break;
            }
        }
        if (duplicato) {
            continue; // Richiede all'utente di reinserire la stringa
        }
        // Controllo se la stringa contiene solo lettere
        int soloLettere = 1;
        for (int i = 0; i < 26; i++) {
            if (!isalpha(alfabeto[i])) {
                soloLettere = 0;
                break;
            }
        }
        if (!soloLettere) {
            system("clear");
            printf("La stringa deve contenere solo lettere. Riprova.\n");
            continue; // Richiede all'utente di reinserire la stringa
        }
        break; // Esce dal ciclo se la stringa è valida
    }
    for(int i= 0; i<strlen(s); i++){
        int indice = s[i]-97;
        s[i] = alfabeto[indice];
    }
    return s;
}
char* cifrarioStaccionata(char *s){
    system("clear");
    char strCipher[strlen(s)];
    
    printf("███████╗████████╗ █████╗  ██████╗ ██████╗██╗ ██████╗ ███╗   ██╗ █████╗ ████████╗ █████╗ \n");
    printf("██╔════╝╚══██╔══╝██╔══██╗██╔════╝██╔════╝██║██╔═══██╗████╗  ██║██╔══██╗╚══██╔══╝██╔══██╗\n");
    printf("███████╗   ██║   ███████║██║     ██║     ██║██║   ██║██╔██╗ ██║███████║   ██║   ███████║\n");
    printf("╚════██║   ██║   ██╔══██║██║     ██║     ██║██║   ██║██║╚██╗██║██╔══██║   ██║   ██╔══██║\n");
    printf("███████║   ██║   ██║  ██║╚██████╗╚██████╗██║╚██████╔╝██║ ╚████║██║  ██║   ██║   ██║  ██║\n");
    printf("╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝ ╚═════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝\n");
                                                                                        
    for (int i = 0; i < strlen(s); i++) {
        s[i] = toupper(s[i]);
    }
    char matrix[3][strlen(s)];
    for (int i = 0; i < 3; i++) {
        for (int e = 0; e < strlen(s); e++) {
            matrix[i][e] = '.';
        }
    }
    int r = 0, inc = 1;
    for (int c = 0; c < strlen(s); c++) {
        matrix[r][c] = s[c];
        
        if (r >= 3 - 1) {
            inc = -1;
        }
        if (r <= 0) {
            inc = 1;
        }
        r = r + inc;
    }
    int k=0;
    for (int i = 0; i < 3; i++) {
            for (int e = 0; e < strlen(s); e++) {
                if(matrix[i][e]!='.'){
                    strCipher[k]=matrix[i][e];
                    k++;
                }
                printf("%c ", matrix[i][e]);
            }
            printf("\n");
        }
    
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(strCipher[i]);
    }
    return s;
}
char* scegliCifrario(char *string){
    int tipoCifrario;
    printf("SCEGLI IL TIPO DI CIFRARIO\n[1] cifrario di cesare\n[2] cifrario a sostituzione (alfabeto mescolato)\n[3] cifrario a staccionata\n\n[99] exit\n\n");
    scanf("%d", &tipoCifrario);
    if(tipoCifrario ==1){
        cifrarioCesare(string);
    }else if(tipoCifrario ==2){
        cifrarioSostituzione(string);
    }else if(tipoCifrario ==3){
        cifrarioStaccionata(string);
    }else if(tipoCifrario == 99){
        char ex[] = "exit";
        for(int i=0; i<strlen(string); i++){
            if(i< strlen(ex)){
                string[i]=ex[i];
            }else{
                string[i]= '\0';
            }
        }
    }
    return string;
}
void ripulisciStringa(char *str){
    int i, e=0; 
    for(i= 0; str[i]!= '\0';i++){
         //se il carattere è una lettera maiuscola la converte con la rispettiva minuscola
        if (isupper(str[i])) {
            str[e] = tolower(str[i]);
            e++;
            // Se il carattere non è un numero e non è un carattere speciale, lo conserva nella stringa
        }else if (islower(str[i])) {
            str[e] = str[i];
            e++;
        }
    }
    str[e] = '\0';
}
int main(){
    system("clear");
    char stringa[56];
    printf("         ██████╗██╗██████╗ ██╗  ██╗███████╗██████╗    ██╗  ██╗        \n");
    printf("        ██╔════╝██║██╔══██╗██║  ██║██╔════╝██╔══██╗   ╚██╗██╔╝        \n");
    printf("        ██║     ██║██████╔╝███████║█████╗  ██████╔╝    ╚███╔╝         \n");
    printf("        ██║     ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗    ██╔██╗         \n");
    printf("███████╗╚██████╗██║██║     ██║  ██║███████╗██║  ██║██╗██╔╝ ██╗███████╗\n");
    printf("╚══════╝ ╚═════╝╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝╚══════╝\n");
    printf("                                                          version: 2.0\n\n");
    printf("scrivi la stringa che devi cifrare: ");
    fgets(stringa, sizeof(stringa), stdin);
    printf("\n");

    if (stringa[strlen(stringa) - 1] == '\n') {
        stringa[strlen(stringa) - 1] = '\0';
    }

    ripulisciStringa(stringa);
    scegliCifrario(stringa);

    if(strcmp(stringa, "exit")==0){
        return 0;
    }else{
        printf("stringa cifrata --> %s", stringa);
        return 0;
    }
}