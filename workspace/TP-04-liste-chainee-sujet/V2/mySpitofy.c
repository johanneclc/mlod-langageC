#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Remonte le prmier élément de la liste à sa place dans l'ordre chronologique des années 
void trierPremierElement(Liste l){
    if(!estVide(l) && !estVide(l->suiv)){
        while(!estVide(l->suiv)){
            if(((Music)l->val)->annee > ((Music)l->suiv->val)->annee){
                Music temp = (Music)l->val; 
                l->val = l->suiv->val ;
                l->suiv->val = temp; 
            }
            l = l->suiv;
        }
    }
}

void trier_r(Liste l){
    if(!estVide(l) && !estVide(l->suiv)){
        trier_r(l->suiv); 
        trierPremierElement(l); 
    }
}

Music readMusic(char *line){
    Music music = malloc(sizeof(Music)); 
    char * temp = strdup(line); 
    music->titre = strsep(&temp,",");
    music->artiste = strsep(&temp,",");
    music->album = strsep(&temp,",");
    music->genre = strsep(&temp,",");
    music->numeroDisque = atoi(strsep(&temp,","));
    music->numeroMusique = atoi(strsep(&temp,","));
    music->annee = atoi(strsep(&temp,","));
    free(temp); 

    return music; 
}

Liste readMusics(FILE *f){
    Liste listeMusic = NULL; 
    char line[1500] ; 
    fgets(line,sizeof(line),f); 
    while(fgets(line,sizeof(line),f)){
        Music music = readMusic(line); 
        listeMusic = ajoutFin_r(music,listeMusic);
    }
    return listeMusic; 
}

void main(){ 

    char fileName[] = "music.csv";
    FILE* f;
    f = fopen(fileName,"r");

    Liste musiques = NULL; 

    musiques = readMusics(f);
    afficheListe_r(musiques); 

    // trier_r(musiques); 
    // afficheListe_r(musiques); 

    detruire_r(musiques); 
    fclose(f); 

    return EXIT_SUCCESS; 
}