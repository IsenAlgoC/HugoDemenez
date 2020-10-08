#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


int main() {
	int valeur;
	printf("Entrez une valeur :");
	scanf_s("%d", &valeur);
	printf("%d", somme(valeur));
}
