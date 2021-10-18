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
		int winnerAnnee; 
		char *winnerName;
		char *winnerDescription;
};

typedef struct winnersTuring winnersInfos; 

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

winnersInfos * readWinners(int nbreGagnants ){
	winnersInfos *winners = (winnersInfos *)calloc(nbreGagnants, sizeof(winnersInfos)); 

	for(int i = 0; i < nbreGagnants ; i++){
		winners[i].winnerAnnee = scanLineAsInt(); 
		//char *winnerName = scanLine(); 
		//char *winnerDescription = scanLine(); 
		winners[i].winnerName = scanLine(); 
		winners[i].winnerDescription = scanLine(); 
		//free(winnerName); 
		//free(winnerDescription); 
	}

	return winners;
}

void printWinners(winnersInfos *winners, int nbreGagnants){
	for(int i=0 ; i < nbreGagnants ; i++){
		printf("%s\n", winners[i].winnerName);
	}
}

void infosAnnee(int annee,winnersInfos *winners, int nbreGagnants){
	printf("L'annee %i, le(s) gagnant(s) ont été : ", annee);
	for(int i=0; i<nbreGagnants; i++){
		if(winners[i].winnerAnnee==annee){
			printf("%s\n",winners[i].winnerName);
		}
	}
	printf("\n Nature des travaux : ");
	for(int i=0; i<nbreGagnants; i++){
		if(winners[i].winnerAnnee==annee){
			printf("%s\n",winners[i].winnerDescription);
		} 
	}

}


int main(int argc , char* argv[]){

	int nbreGagnants = scanLineAsInt(); 

	winnersInfos *winners; 

	winners = readWinners(nbreGagnants); 
	printWinners(winners , nbreGagnants); 
	
	//if(argc==2){
	//		infosAnnee((int) *argv[1], winners , nbreGagnants); 
	//	else return 0 ; 
	//else{
	//	printWinners(winners , nbreGagnants); 
	//}

	free(winners); 

	return EXIT_SUCCESS;
}
