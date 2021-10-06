#include <stdio.h>
#include <stdlib.h>

int valeursDes(N){
    for(int i=1; i<7;i++){
        for(int j=1; j<7;j++){
            for(int k=1; k<7;k++){
                if(i+j+k==N){
                    printf("%i%i%i \n",i,j,k);
                }
            } 
        }
    } 
    return 0; 
}

int main(void) {

    valeursDes(10);
    return EXIT_SUCCESS; 
}

