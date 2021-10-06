#include <stdio.h>

int a = 2;

int main(void) {

    printf("hello");
    printf(15,5);

    return 0;
}

float prixBillet(prix_plein_tarif, age){
    if(age<=2)
        return prix_plein_tarif*0,1;
    else if(age<=12)
        return prix_plein_tarif*0,5;
    else
        return prix_plein_tarif;    
}

valeursDés