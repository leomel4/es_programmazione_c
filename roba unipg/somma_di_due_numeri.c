#include <stdio.h>

int main(){
    int firstN, secondN, sumN;

    printf("enter two integers:");
    
    
    scanf("%d %d", &firstN, &secondN);

    sumN = firstN + secondN;

    printf("%d + %d = %d", firstN ,secondN ,sumN);

    return 0;
}