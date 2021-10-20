#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct matrice{
		int nbreColonnes; 
		int nbreLignes;
		int **val;
};

typedef struct matrice Matrix; 

struct tabMatrices{
		int nbreMatrices; 
		Matrix *matrice;
};

typedef struct tabMatrices MatrixArray; 

int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

Matrix *readMatrix(){
    Matrix *matrice = malloc(sizeof(Matrix)); 
    scanf("%i %i\n", &matrice -> nbreLignes, &matrice -> nbreColonnes);
    matrice->val = calloc(matrice->nbreLignes, sizeof(int*));
    for(int l=0; l<matrice->nbreLignes; l++){
        matrice->val[l] = calloc(matrice->nbreColonnes,sizeof(int)); 
        for(int c=0; c<matrice->nbreColonnes; c++)
            scanf("%i ",&matrice->val[l][c]) ;
    }
    return matrice; 
}

MatrixArray readMatrixArray(int nbreMatrices){
    MatrixArray *matrices = (MatrixArray *)calloc(nbreMatrices,sizeof(Matrix)); 
    matrices -> nbreMatrices = nbreMatrices;
    for(int i=0 ; i<nbreMatrices; i++){
        matrices[i].matrice = readMatrix(); 
    }
    return *matrices; 
}

void printMatrix(Matrix *matrice){
    printf("%i %i\n",matrice->nbreLignes,matrice->nbreColonnes);
    for(int l=0; l<matrice->nbreLignes;l++){
        for(int c=0; l<matrice->nbreColonnes;c++){
            if(c!=0)
                printf(" ");
            printf("%i ",matrice->val[l][c]);
        }
        printf("\n");
    }
}

void printMatrixArray(MatrixArray matrices, int nbreMatrices){
    printf("%i\n",nbreMatrices);
	for(int i=0 ; i < nbreMatrices ; i++){
		printMatrix((&matrices)[i].matrice); 
    }
}

int main(){

	int nbreMatrices = scanLineAsInt(); 

	MatrixArray matrices; 

	matrices = readMatrixArray(nbreMatrices); 
    printMatrixArray(matrices, nbreMatrices); 

	return EXIT_SUCCESS;
}