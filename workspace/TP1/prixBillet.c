#include <stdio.h>
#include <stdlib.h>

float prixBillet(prix_plein_tarif, age){
    if(age<=2)
        return prix_plein_tarif*0.1;
    if(age<=12)
        return prix_plein_tarif*0.5;
    return prix_plein_tarif;    
}

int main(void) {
    float prix_plein_tarif = 15;
    unsigned int age = 5; 

    float prix = prixBillet(prix_plein_tarif,age);

    printf("prix= %f",prix);

    return EXIT_SUCCESS; 
}

