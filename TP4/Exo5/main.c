#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>



int main() {
	//Ajout des caract�res speciaux fran�ais
	setlocale(LC_ALL, "fr-FR");

	//Initialisation des variables
	char phrase[1024] ;
	int nbmots = 1;
	float caracteres = 0.00;

	
	printf("Entrez une phrase : ");

	//Debut de la s�quence de frappe
	gets_s(phrase, 1024);

	//Calcul du nombre de mot et du nombre de caract�res
	for (int i = 1; i < strlen(phrase); i++) {
		if (phrase[i] == ' ') {
			nbmots++;
		}
		else {
			caracteres++;
		}
	}

	//Affichage des differentes valeurs
	printf("\nIl y a %d mots dans votre phrase", nbmots);
	printf("\nIl y a en moyenne %.4f caract�res dans vos mots ", caracteres / nbmots);
}