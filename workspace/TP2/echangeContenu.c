#include <stdio.h>
#include <stdlib.h>

void echangeContenu(int *a, int *b){
    int aContenu = *a;

    *a = *b; 
    *b = aContenu; 

}

int main(void) {
    int a =10; 
    int b = 20; 
    printf("variables avant echange : a= %i b=%i \n", a, b );
    echangeContenu(&a, &b);
    printf("variables apres echange : a= %i b=%i \n", a, b );

    return EXIT_SUCCESS;
}