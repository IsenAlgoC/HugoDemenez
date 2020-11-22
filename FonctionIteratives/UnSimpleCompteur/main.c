#include "Header.h"


int main() {
	int debut = 0;
	int fin = 5; 
	char* chaine = "toto";
	recursCompteur(debut, fin);
	printf("\n");
	recursCompteurIncrement(fin);
	printf("\n");
	printf("%d",recursStrLen(chaine));
}