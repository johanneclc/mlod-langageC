#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum {jan = 1, fev, mars, avr, mai, juin,
    juil, aout, sept, oct, nov, dec} Mois;

struct DateSimple {
    int jour;
    Mois mois; 
    int annee;
};

typedef struct DateSimple Date;

void initialiseDate(Date *d){
    printf("Jour (compris entre 1 et 31) :"); 
    scanf( "%i",&d->jour ); 
    printf("Mois (jan=1, fev=2,...) : "); 
    scanf( "%i",(int *) &d->mois ); 
    printf("Année :"); 
    scanf( "%i",&d->annee ); 
    
}

void afficheDate(Date *date){
    printf("%i %i %i", (*date).jour,(*date).mois,(*date).annee );
}

Date creerDateParCopie(){
    Date date; 

    initialiseDate(&date); 

    return date; 
}

void *newDate(){
    struct DateSimple *adresse = NULL ; 
    adresse = malloc(sizeof(struct DateSimple));

    if(adresse){
        printf("Jour (compris entre 1 et 31) :"); 
        scanf( "%i",&adresse->jour ); 
        printf("Mois (jan=1, fev=2,...) : "); 
        scanf( "%i",(int *) &adresse->mois ); 
        printf("Année :"); 
        scanf( "%i",&adresse->annee );

        return adresse;
    }
    else 
        return 0; 
}

unsigned int nbreJours(Mois mois, unsigned int annee){
    if(mois == 2 && annee%4 != 0)
        return 28 ; 
    if(mois == 2 && annee%4 == 0)
        return 29 ; 
    else if(mois % 2 == 0)
        return 30; 
    else
        return 31; 
}

bool dateValide(Date uneDate){
    return (uneDate.jour>0 && uneDate.jour < nbreJours(uneDate.mois, uneDate.annee));
}


int main(void) {

    //version avec modification par pointeur 
    Date d; 
    initialiseDate(&d); 
    afficheDate(&d);

    // version copie de la mémoire 
    Date date;
    date = creerDateParCopie(); //Création de 3 cases mémoire supplémentaires donc moins optimal
    afficheDate(&date);

    // version allocation manuelle d'un espace mémoire 
    Date *date2;
    date2 = newDate();
    afficheDate(date2);
    free(date2);

    return EXIT_SUCCESS;
}