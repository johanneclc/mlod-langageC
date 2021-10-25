#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Music readMusic(char *line){
    Music music = malloc(sizeof(Music)); 
    music->titre = strdup(strsep(line,","));
    music->artiste = strdup(strsep(line,","));
    music->album = strdup(strsep(line,","));
    music->genre = strdup(strsep(line,","));
    music->numeroDisque = (int) strdup(strsep(line,","));
    music->numeroMusique = (int) strdup(strsep(line,","));
    music->annee = (int) strdup(strsep(line,","));

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
    char *line = "Bonjour, Johanne, Salut ";

    printf("Bonjour");
    printf(strsep(&line,","));
    printf(strsep(&line,","));
 

    // char fileName[] = "music.csv";
    // FILE* f;
    // f = fopen(fileName,"r");

    // Liste musiques = NULL; 

    // musiques = readMusics(f);
    // afficheListe_r(musiques); 

    // detruire_r(musiques); 
    // fclose(f); 

    return EXIT_SUCCESS; 
}