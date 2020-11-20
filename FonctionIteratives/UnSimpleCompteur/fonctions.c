#include "Header.h"


void recursCompteur(int debut, int fin) {
	if (debut > fin) {
		return;
	}
	printf("%d", debut);
	recursCompteur(debut + 1, fin);
	return;
}

void recursCompteurDecrement(int compteur) {
	if (compteur < 0) {
		return;
	}
	printf("%d", compteur);
	recursCompteurDecrement(compteur - 1);
}

void recursCompteurIncrement(int compteur) {
	if (compteur <0) {
		return;
	}
	recursCompteurIncrement(compteur - 1);
	printf("%d", compteur);
	return;
	
}

int recursStrLen(char* chaine) {

	if (*(chaine ) == 0) {
		return 0;
	}
	return (1 + recursStrLen(++chaine));
}