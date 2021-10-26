#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int plusPetit(Liste l){
    if(estVide(l->suiv))
        return ((Music) l->val)->annee; 
    if(plusPetit(l->suiv) > ((Music) l->val)->annee)
        return ((Music) l->val)->annee ; 
    else    
        return plusPetit(l->suiv);        
}

Music readMusic(char *line){
    Music music = malloc(sizeof(Music)); 
    music->titre = strdup(strsep(&line,","));
    music->artiste = strdup(strsep(&line,","));
    music->album = strdup(strsep(&line,","));
    music->genre = strdup(strsep(&line,","));
    music->numeroDisque = atoi(strsep(&line,","));
    music->numeroMusique = atoi(strsep(&line,","));
    music->annee = atoi(strsep(&line,","));

    return music; 
}

Liste readMusics(FILE *f){
    Liste listeMusic = NULL; 
    char line[1000] ; 
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

    printf("La plus petite annee : %i \n", plusPetit(musiques)); 

    detruire_r(musiques); 
    fclose(f); 

    return EXIT_SUCCESS; 
}