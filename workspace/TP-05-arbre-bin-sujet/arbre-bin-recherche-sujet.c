#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL; 
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a= malloc(sizeof(ArbreBinaire));
	a->val = e; 
	initialiser(&a->filsDroit);
	initialiser(&a->filsGauche);
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if(estVide(a))
		return creer(e); 
	ArbreBinaire noeud_parcouru = a;
	while(!estVide(noeud_parcouru)){
		if(noeud_parcouru->val == e)
			return a; 
		if(noeud_parcouru->val < e)
			noeud_parcouru = noeud_parcouru->filsGauche; 

	}
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if(estVide(a) )
		return creer(e); 
	if(a->val == e)
		return a; 
	if(a->val < e){
		a->filsDroit = insere_r(a->filsDroit,e); 
	}
	if(a->val > e){
		a->filsGauche = insere_r(a->filsGauche,e); 
	}
	return a; 
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(estVide(a))
		return 0; 
	else{
		return 1+nombreDeNoeud(a->filsGauche)+nombreDeNoeud(a->filsDroit); 
	}
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if(estVide(a))
		return -1; 
	else {
		if(a->val == e)
			return 0;
		if(a->val < e)
			return (profondeur(a->filsDroit,e)==-1 ? -1 : 1+profondeur(a->filsDroit,e));
		if(a->val > e)
			return (profondeur(a->filsGauche,e)==-1 ? -1 : 1+profondeur(a->filsGauche,e));
	}
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a))
		return 0; 
	else{
		int gauche = hauteur(a->filsGauche);
		int droite = hauteur(a->filsDroit);
		return 1+ (gauche>droite ? gauche : droite); 
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element e){
	if(estVide(a) || a->val==e)
		return NULL; 
	else{
		ArbreBinaire noeud_prec = a;
		ArbreBinaire noeud_parc = (a->val <e ? a->filsDroit : a->filsGauche);
		while(!estVide(noeud_parc) && noeud_parc->val != e ){
			noeud_prec = noeud_parc; 
			noeud_parc = (noeud_parc->val <e ? noeud_parc->filsDroit : noeud_parc->filsGauche);
		}
		return noeud_prec; 
	}
}


void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("%i \n", a->val); 
		printf("(");
		afficheRGD_r(a->filsGauche);
		printf(")");
		printf("(");
		afficheRGD_r(a->filsDroit);
		printf(")");
	}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("(");
		afficheGRD_r(a->filsGauche);
		printf(")");
		printf("%i", a->val); 
		printf("(");
		afficheGRD_r(a->filsDroit);
		printf(")");
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("%i \n", a->val); 
		printf("(");
		afficheRGD_r(a->filsDroit);
		printf(")");
		printf("(");
		afficheRGD_r(a->filsGauche);
		printf(")");
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	if(estVide(a))
		return NULL; 
	if(estVide(a->filsGauche))
		return a; 
	else
		return min(a->filsGauche); 
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	if(estVide(a))
		return NULL; 
	if(estVide(a->filsDroit))
		return a; 
	else
		return max(a->filsDroit); 
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){
	if(a->val == elem)
		return a; 
	if(estVide(a))
		return NULL; 
	else
		return (a->val < elem ? recherche_r(a->filsDroit,elem) : recherche_r(a->filsGauche,elem)) ;
}


// suppime x de a
// a->val = min(a->filsDroit); 
ArbreBinaire supprimer_r(ArbreBinaire a,Element e){
	if(estVide(a))
		return a; 
	if(a->val < e) {
		a->filsDroit = supprimer_r(a->filsDroit,e);
		return a; 
	}
	if(a->val > e) {
		a->filsGauche = supprimer_r(a->filsGauche,e);
		return a; 
	}
	if(a->val == e){
		a->val = min(a->filsDroit)->val;
		detruire_r(min(a->filsDroit)); 
		return a; 
	}
}

void detruire_r(ArbreBinaire a){
	if(!estVide(a)){
		if(!estVide(a->filsDroit))
			detruire_r(a->filsDroit); 
		if(!estVide(a->filsGauche))
			detruire_r(a->filsGauche); 
		free(a);
	}
}

