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
		Matrix **tab;
};

typedef struct tabMatrices MatrixArray; 

int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

Matrix *readMatrix(){
    int nbreColonnes, nbreLignes;
    scanf("%i %i\n", &nbreLignes, &nbreColonnes);
    Matrix *matrice = (Matrix *)malloc(nbreLignes*nbreColonnes*sizeof(int)); 
    matrice -> nbreColonnes = nbreColonnes; 
    matrice -> nbreLignes = nbreLignes;
    for(int l=0; l<nbreLignes; l++){
        for(int c=0; c<nbreColonnes; c++){
            int n; 
            (l== nbreColonnes-1 ? scanf("%i\n",&n) : scanf("%i ",&n)) ;
            matrice->tab[l][c] = n; 
        }
    }
    return matrice; 
}

MatrixArray *readMatrixArray(int nbreMatrices){
    MatrixArray *matrices = (MatrixArray *)calloc(nbreMatrices,sizeof(Matrix)); 
    matrices -> nbreMatrices = nbreMatrices;
    for(int i=0 ; i<nbreMatrices; i++){
        matrices[i].tab[i] = readMatrix(); 
    }
    return matrices; 
}

void printMatrix(Matrix matrice){
    for(int l=0; l<matrice.nbreLignes;l++){
        for(int c=0; l<matrice.nbreColonnes;c++)
            (c==matrice.nbreColonnes-1 ? printf("%i\n",matrice->tab[l][c]) : printf("%i ",matrice->tab[l][c]));
    }
}

void printMatrixArray(MatrixArray *matrices, int nbreMatrices){
    printf("%i\n",nbreMatrices);
	for(int i=0 ; i < nbreMatrices ; i++){
        printf("%i %i\n",*(matrices->tab)[i].nbreLignes,matrices->tab[i].nbreColonnes);
		printMatrix(matrices.tab[i]); 
    }
}

int main(){

	int nbreMatrices = scanLineAsInt(); 

	MatrixArray *matrices; 

	matrices = readMatrixArray(nbreMatrices); 
    printMatrixArray(matrices, nbreMatrices); 

	return EXIT_SUCCESS;
}