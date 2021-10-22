#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void detruireElement(Element e){

}

void afficheElement(Element e){
    printf("%s",(char *)e); 
}

bool equalsElement(Element e1, Element e2){
    return strcmp(e1, e2) == 0; 
}

void main(){
    Liste l = NULL; 

    l = ajoutTete("Bonjour!",l); 
    l = ajoutFin_r("Enchanté!",l);


    afficheListe_r(l); 

    detruire_r(l); 

    return EXIT_SUCCESS; 
}