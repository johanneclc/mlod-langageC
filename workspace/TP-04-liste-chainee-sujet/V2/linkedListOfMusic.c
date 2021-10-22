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
    Music el = (Music)e; 
    printf("Nom : %s\n",el->titre);
    printf("Artiste : %s\n",el->artiste);
    printf("Album : %s \n",el->album);
    printf("Genre : %s \n",el->genre);
    printf("Disque numéro : %i \n",el->numeroDisque);
    printf("Musqiue numéro : %i \n",el->numeroMusique);
    printf("Année : %i \n",el->annee);
}

bool equalsElement(Element e1, Element e2){
    Music el1 = (Music)e1; 
    Music el2 = (Music)e2; 
    return (strcmp(el1->titre, el2->titre)==0 && 
            strcmp(el1->artiste, el2->artiste)==0 && 
            strcmp(el1->album , el2->album)==0 && 
            strcmp(el1->genre , el2->genre)==0 && 
            el1->numeroDisque == el2->numeroDisque && 
            el1->numeroMusique == el2->numeroMusique && 
            el1->annee == el2->annee ); 
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