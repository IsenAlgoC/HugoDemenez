#include "Header.h"


int main() {
	int ValeurA;
	int ValeurB;
	printf("Entrez une valeur A :");
	scanf_s("%d", &ValeurA);
	printf("\nEntrez une valeur B :");
	scanf_s("%d", &ValeurB);

	ordonne(ValeurA, ValeurB);
	printf("Les valeurs ordonnées sont : %d %d", ValeurA, ValeurB);
}