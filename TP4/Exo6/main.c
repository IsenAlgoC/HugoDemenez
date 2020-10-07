#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

int main() {
	//Ajout des caractères speciaux français
	setlocale(LC_ALL, "fr-FR");

	//Initialisation des variables
	int valeur=21;
	int tableau[100];
	int compteur = 0;
	int positions[100];
	int* Pointeur;

	//Ajout du temps
	time_t t;
	srand((unsigned)time(&t));

	
	for (int i = 0; i < 100; i++) {
		tableau[i]= rand() % 20;
	}

	Pointeur = &tableau[0];

	printf("\nVeuillez entrer la valeur recherchée entre 0 et 20 :");
	scanf_s("%d", &valeur);

	printf("La valeur %d a été trouvée en : ", valeur);
	for (int i = 0; i < 100; i++) {
		if (*Pointeur == valeur) {
			printf(" %d ", i);
		}
		Pointeur++;
	}




	
}