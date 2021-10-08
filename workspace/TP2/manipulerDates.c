#include <stdint.h>
#include <stdlib.h>

typedef enum {jan = 1, fev, mars, avr, mai, juin,
    juil, aout, sept, oct, nov, dec} Mois;

struct DateSimple {
    int jour;
    Mois mois; 
    int annee;
};

typedef struct DateSimple Date;

void initialiseDate(Date *d){
    int jour, annee; 
    Mois mois; 
    printf("Jour (compris entre 1 et 31) :"); 
    scanf( "%i",jour ); 
    printf("Mois (jan, fev, mars, avr, mai, juin,juil, aout, sept, oct, nov, dec) : "); 
    scanf( "%c",mois ); 
    printf("Année :"); 
    scanf( "%i",annee ); 
    
    (*d).jour = jour; 
    (*d).mois = mois; 
    (*d).annee = annee; 
    
}

void afficheDate(Date *date){
    printf("%i %c %i", (*date).jour,(*date).mois,(*date).annee );
}

Date creerDateParCopie(){
    Date date; 

    initialiseDate(&date); 

    return date; 
}

int main(void) {

    Date d; 

    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);

    Date date;
    date = creerDateParCopie();
    afficheDate(&date);



    return EXIT_SUCCESS;
}