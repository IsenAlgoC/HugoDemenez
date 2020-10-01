#include<stdio.h>
#include<stdlib.h>

int main() {
	//Déclaration des variables
	float tableau[100] = { 0 };
	int ask = 1;
	int position = 0;
	float valeur=0;

	//Debut de la boucle pour entrer les valeurs dans le tableau
	while (valeur >= 0) {
		printf("\nEntrez une valeur positive a stocker :");
		scanf_s("%f", &valeur);
		if (valeur >= 0) {
			tableau[position] = valeur;
			position++;
		}
	}

	//Affichage du tableau
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%.2f ", tableau[i]);
	}

	//Demande pour inserer une valeur 
	printf("\nOu voulez vous inserer une valeur ? ");
	scanf_s("%d", &position);
	printf("\nQuelle est cette valeur ? :");
	scanf_s("%f", &valeur);

	//Insertion de la valeur dans le tableau
	tableau[position] = valeur;

	//Affichage du tableau
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%.2f ", tableau[i]);
	}

	//Demande de suppression de valeur
	printf("\nQuelle valeur voulez vous supprimer ? ");
	scanf_s("%d", &position);
	
	//Suppression de la valeur
	tableau[position] = 0.0; 

	//Affichage du tableau
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%.2f ", tableau[i]);
	}

	float somme = 0;
	//Calcul de la somme des valeurs du tableau
	for (int i = 0; i < 100; i++) {
		somme = somme + tableau[i];
	}
	float moyenne = somme / 100;

	printf("\n La note moyenne est %f", moyenne);
}