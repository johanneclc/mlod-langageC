#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h> //uint8_t , uint32_t 

int sommeDesDiviseurs(int i){
    int sommeDiviseurs =0; 
    for(int d=1;d<i;d++){
            if(i%d==0){
                sommeDiviseurs+=d;
            }
        }
    return sommeDiviseurs; 
}


int parfaits(int N){
    for(int i=1; i<=N;i++){
        if(sommeDesDiviseurs(i)==i)
            printf("nombre parfait : %i" , i); 
    }
    return EXIT_SUCCESS;
}

int main(void) {
    int n = 8; 

    parfaits(n); 

    return EXIT_SUCCESS; 
}