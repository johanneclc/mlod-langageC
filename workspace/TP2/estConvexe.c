#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool estConvexe(bool tab[], int length){
    bool trueVu = false; 
    for(int i=0; i<length; i++){
        if(tab[i]){
            if(trueVu && !tab[i-1] && !(i==length-1 && tab[0]))
                return false;
            else
                trueVu = true; 
        }
    }
    return true; 
}

int main(void) {
    bool tab[4] = {false, true, false , true};
    bool convexe = estConvexe(tab,4); 
    

    if(convexe)
        printf("Le tableau est convexe");
    else
        printf("Le tableau n'est pas convexe");

    return EXIT_SUCCESS;
}