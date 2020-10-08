#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <locale.h>

int  main() {
	//Ajout des caractères speciaux français
	setlocale(LC_ALL, "fr-FR");
	time_t t;
	srand((unsigned)time(&t));

	int nbVal;
	printf("Entrez le nombre de valeur que vous voulez entrer dans votre tableau :");
	scanf_s("%d", &nbVal);
}