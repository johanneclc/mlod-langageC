#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Music{
    char *titre;
    char *artiste;
    char *album;
    char *genre;
    int numeroDisque;
    int numeroMusique;
    int annee
} ; 

typedef struct Music *Music; 

void detruireElement(Element e){
    free(e);
}

void afficheElement(Element e){
    printf("Nom : %s\n",e->titre);
    printf("Artiste : %s\n",e->artiste);
    printf("Album : %s \n",e->album);
    printf("Genre : %s \n",e->genre);
    printf("Disque numéro : %i \n",e->numeroDisque);
    printf("Musqiue numéro : %i \n",e->numeroMusique);
    printf("Année : %i \n",e->annee);
}

bool equalsElement(Element e1, Element e2){
    return (strcmp(e1->titre, e2->titre)==0 && 
            strcmp(e1->artiste, e2->artiste)==0 && 
            strcmp(e1->album , e2->album)==0 && 
            strcmp(e1->genre , e2->genre)==0 && 
            e1->numeroDisque == e2->numeroDisque && 
            e1->numeroMusique == e2->numeroMusique && 
            e1->annee == e2->annee ); 
}

void main(){

    Liste musiques = NULL; 

    Music m = malloc(sizeof(struct Music));
    m->titre = "Them Bones";
    m->artiste = "Alice In Chains"; 
    m->album = "Dirt";
    m->genre = "Alternative";
    m->numeroDisque = 1;
    m->numeroMusique = 1;
    m->annee = 1992; 

    musiques = ajoutFin_r(m, musiques);
    afficheListe_r(m);

    return EXIT_SUCCESS; 
}