#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct matrice{
		int nbreColonnes; 
		int nbreLignes;
		int *tab;
};

typedef struct matrice Matrix; 

struct tabMatrices{
		int nbreMatrices; 
		int *tab;
};

typedef struct tabMatrices MatrixArray; 

int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

MatrixArray * readMatrixArray(int nbreMatrices){
    MatrixArray *matrices = (MatrixArray *)malloc(sizeof(MatrixArray)); 
    matrices -> nbreMatrices = nbreMatrices;
    for(int i=0 ; i<nbreMatrices; i++){
        int nbreColonne, nbreLignes;
        scanf("%i %i", &nbreLignes, &nbreColonne);
        matrices->tab[i] = readMatrix(nbreLignes,nbreColonne); 
    }

}

int main(){

	int nbreMatrices = scanLineAsInt(); 

	MatrixArray *matrices; 

	matrices = readMatrixArray(nbreMatrices); 

	return EXIT_SUCCESS;
}