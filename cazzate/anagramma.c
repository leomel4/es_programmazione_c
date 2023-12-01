#include <stdio.h>
#include <string.h>


int cont=0;
char *vettoreGenerale[999999];


void swap( char *x, char *y){

    char temp = *x;
    *x = *y;
    *y = temp;
    
}

void generateAnagrams(char str[], int start, int end){
    if(start == end){
        printf("%s\n", str);
        cont++;
        vettoreGenerale[start]= "a";
        
    }else{
        for(int i = start; i <= end; i++){
            swap(&str[start], &str[i]);
            generateAnagrams(str, start + 1, end);
            swap(&str[start], &str[i]);
            
        }
    }
}

int main(){
    
    char word[999];

    printf("inserisci una parola: ");

    scanf("%s", word);

    printf("anagrammi di %s sono:\n", word);
    generateAnagrams(word, 0, strlen(word)-1);
    printf("%d\n",cont);
    printf("%n",vettoreGenerale);
    return 0;
}