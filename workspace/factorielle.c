#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long TypeEntier;

TypeEntier factorielle(TypeEntier n){
    TypeEntier res = 1;
    for(TypeEntier i=1;i<=n;i++){
        res*=i;
    }
    return res;
}

TypeEntier factorielles(){
    for(TypeEntier i=1;i<=15;i++)
        printf("factorielle de %i : %lli \n",i, factorielle(i));
}

int main(void) {
    TypeEntier n= 8; 
    TypeEntier resultatFactorielle = factorielle(n); 

    printf("%lli", resultatFactorielle);

    factorielles(); 

    return EXIT_SUCCESS;
}