/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct winnersTuring{
		int winnersAnnee; 
		char winnersName;
		char winnersDescription;
};

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

void readWinners(){
	int nbreGagnants = scanLineAsInt();
	char *winnersName = malloc(nbreGagnants * sizeof(char));
	struct winnersTuring *winners = malloc(nbreGagnants * 3 * sizeof(char));
	winners->winnersName = malloc(nbreGagnants*sizeof(char));
	winners->winnersAnnee = malloc(nbreGagnants*sizeof(int));
	winners->winnersDescription = malloc(nbreGagnants*sizeof(char));

	for(int i=0; i<nbreGagnants;i++){
		//Annees
		char *winnerAnnee = scanLine();
		winners->winnersAnnee[i] = *winnerAnnee; 
		free(winnerAnnee);

		//Noms 
		char *winnerName = scanLine(); 
		winners->winnersName[i] = *winnerName; 
		printf("%s\n", winnerName);
		free(winnerName);

		//Descriptions
		scanLine();
	}
}

void infosAnnee(){
	printf("L'annee %i, le(s) gagnant(s) ont été : %s\n Nature des travaux : %s\n",);
}


int main(void){

	// Afficher le document texte 

	// char *line = scanLine();
	// while(strlen(line)!=0){
	// 	printf("%s\n",line);
	// 	free(line);
	// 	line = scanLine();
	// }	

	readWinners();

	return EXIT_SUCCESS;
}
