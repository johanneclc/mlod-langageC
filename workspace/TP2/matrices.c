#include <stdint.h>
#include <stdlib.h>

void mult_matrice(int64_t matriceResultat[5][5], int64_t matrice1[5][5],int64_t matrice2[5][5],int tailleMatrice){
    for(int i = 0; i<=tailleMatrice; i++){
        for(int j = 0; j<=tailleMatrice; j++){
            matriceResultat[i][j]=0; 
            for(int k = 0; k<=tailleMatrice; k++)
                matriceResultat[i][j] += matrice1[i][k]*matrice2[k][j];
        }
    }
}

affiche_matrice(int64_t matriceResultat[5][5],int tailleMatrice){
    for(int i = 0; i<=tailleMatrice; i++){
        for(int j = 0; j<=tailleMatrice; j++){
            printf("  %5i  ", matriceResultat[i][j]);
        }
        printf("\n"); 
    }
}


int main(void) {
    //matrices en ligne * colonne
    int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[5][5];

    mult_matrice(matriceResultat,matrice1,matrice2,5);
    affiche_matrice(matriceResultat,5);

    return EXIT_SUCCESS;
}