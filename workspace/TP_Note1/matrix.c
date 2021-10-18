#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct matrice{
		int nbreColonnes; 
		int nbreLignes;
		int *tab[][];
};

typedef struct matrice Matrix; 

struct tabMatrices{
		int nbreMatrices; 
		int *tab[];
};

typedef struct matrice MatrixArray; 

int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

MatrixArray readMatrixArray(int nbreMatrices){

}

int main(int argc , char* argv[]){

	int nbreMatrices = scanLineAsInt(); 

	MatrixArray *matrices; 

	matrices = readMatrixArray(nbreMatrices); 

	return EXIT_SUCCESS;
}