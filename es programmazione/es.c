#include <stdio.h>
int main(void){
    char c;
    scanf("%c", &c);
    switch(c){
        case 'm':
            printf("Maschio");
        break;
        case 'M':
            printf("Maschio");
        break;
        case 'f':
            printf("Femmina");
        break;
        case 'F':
            printf("Femmina");
        break;
        default:
            printf("sesso non specificato");
        
    }
}