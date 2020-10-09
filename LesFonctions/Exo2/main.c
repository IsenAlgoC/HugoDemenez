#include "Header.h"


int main() {
	int valeur;
	bool start = true;
	while (start) {
		printf("\nQuel factorielle voulez-vous calculer ? :");
		scanf_s("%d", &valeur);
		printf("Le factorielle de %d est %d", valeur, factorielle(valeur));
	}
}