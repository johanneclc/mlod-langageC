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
    scanf( "%i",&jour ); 
    printf("Mois (jan=1, fev=2,...) : "); 
    scanf( "%i",&mois ); 
    printf("Année :"); 
    scanf( "%i",&annee ); 
    
    (*d).jour = jour; 
    //(*d).mois = mois; 
    d->mois = mois;
    (*d).annee = annee; 
    
}

void afficheDate(Date *date){
    printf("%i %i %i", (*date).jour,(*date).mois,(*date).annee );
}

Date creerDateParCopie(){
    Date date; 

    initialiseDate(&date); 

    return date; 
}

int newDate(){
    int adresseJour = (int *) malloc(sizeof(int));
    int adresseMois = (int *) malloc(sizeof(int));
    int adresseAnnee=  (int *) malloc(sizeof(int));

    *adresseJour =  (int *) malloc(sizeof(int));
    *adresseMois =  (int *) malloc(sizeof(int));
    *adresseAnnee =  (int *) malloc(sizeof(int));
}

int main(void) {

    Date d; 

    initialiseDate(&d); //Pourquoi a t-on ajouté un &?
    afficheDate(&d);

    Date date;
    date = creerDateParCopie();
    afficheDate(&date);

    Date *date2;
    date = newDate();
    afficheDate(date2);
    //...
    free(date2);




    return EXIT_SUCCESS;
}