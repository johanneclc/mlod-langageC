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

// Problème de fuite mémoire (free(): invalid next size (fast) Aborted) 
// Je pense que ca vient de la fonction detruireElement 
// Probleme d'affichage pour le Titre de la musique (impossible de comprendre pourquoi)
Music readMusic(char *line){
    Music music = malloc(sizeof(struct Music)); 
    char * temp = strdup(line); 
    music->titre = (char *)strsep(&temp,",");
    music->artiste = (char *)strsep(&temp,",");
    music->album = (char *)strsep(&temp,",");
    music->genre = (char *)strsep(&temp,",");
    music->numeroDisque = atoi(strsep(&temp,","));
    music->numeroMusique = atoi(strsep(&temp,","));
    music->annee = atoi(strsep(&temp,","));
    //free(temp); 

    return music; 
}

Liste readMusics(FILE *f){
    Liste listeMusic = NULL; 
    char line[1500] ; 
    fgets(line,sizeof(line),f); 
    while(fgets(line,sizeof(line),f)){
        Music music = readMusic(line); 
        afficheElement(music);
        listeMusic = ajoutFin_r(music,listeMusic);
    }
    return listeMusic; 
}

int main(){ 

    char fileName[] = "music.csv";
    FILE* f;
    f = fopen(fileName,"r");

    Liste musiques = NULL; 

    musiques = readMusics(f);
    //afficheListe_r(musiques); 

    //trier_r(musiques); 
    //afficheListe_r(musiques); 

    detruire_r(musiques); 
    fclose(f); 

    return EXIT_SUCCESS; 
}