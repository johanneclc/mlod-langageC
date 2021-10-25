#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void detruireElement(Element e){
    free(e);
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

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste liste = malloc(sizeof(Liste)) ; 
	liste->val = v; 
	liste->suiv = NULL; 
	return liste;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Cellule *cellule =creer(v);
	cellule->suiv = l; 
	l = cellule;
	return l; 
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(estVide(l))
		printf("La liste est vide !");
	else {
		Liste cellule_parcourue = l; 
		while(cellule_parcourue != NULL){
			afficheElement(cellule_parcourue->val);
			cellule_parcourue = cellule_parcourue->suiv;
		}
		printf("\n");
	}
}

// version recursive
void afficheListe_r(Liste l) {
	if(estVide(l))
		printf("\n");
	else{
		afficheElement(l->val); 
		afficheListe_r(l->suiv);
	}
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste cellule_parcourue = l; 
	while(!estVide(cellule_parcourue)){
		Element element_a_detruire = cellule_parcourue->val; 
		Liste pointeur_a_detruire = cellule_parcourue; 
		cellule_parcourue = cellule_parcourue->suiv;
		detruireElement(element_a_detruire);
		free(pointeur_a_detruire);
	}
}

// version récursive
void detruire_r(Liste l) {
	if(!estVide(l)){
		detruire_r(l->suiv);
		detruireElement(l->val);  
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Cellule *cellule_parcourue = l; 
	if(estVide(l))
		return creer(v); 
	while(cellule_parcourue->suiv != NULL){
		cellule_parcourue = cellule_parcourue->suiv;
	}
	cellule_parcourue->suiv = creer(v); 
	return l; 
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l))
		return creer(v); 
	else
		l->suiv = ajoutFin_r(v, l->suiv); 
	return l; 
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Cellule *cellule_parcourue = l; 
	while(cellule_parcourue->suiv != NULL){
		if(equalsElement(cellule_parcourue->val, v))
			return cellule_parcourue; 
		cellule_parcourue = cellule_parcourue->suiv;
	}
	return NULL; 
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(estVide(l))
		return NULL; 
	else{
		if(equalsElement(v, l->val))
			return l; 
		cherche_r(v, l->suiv); 
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	if(!estVide(l)){
		Cellule *cellule_parcourue = l; 
		if(equalsElement(l->val,v)){
			// detruireElement(l->val); 
			// free(l);
			return cellule_parcourue->suiv; 
		}
		while(!equalsElement(v, cellule_parcourue->suiv->val)){
				cellule_parcourue = cellule_parcourue->suiv; 
		}
		cellule_parcourue->suiv = cellule_parcourue->suiv->suiv;
		// detruireElement(cellule_parcourue->suiv->val); 
		// free(cellule_parcourue->suiv->suiv);
		return l; 
	}
	else 
		return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(estVide(l))
		return l; 
	else if(equalsElement(l->val,v)){
		return l->suiv; 
		//detruire
	}
	l->suiv = retirePremier_r(v, l->suiv); 
	return l; 
}


void afficheEnvers_r(Liste l) {
	if(estVide(l))
		printf("\n");
	else{
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}

