#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<stdbool.h>
#include<math.h>

#define NBMAXNOTES 30

int main() {
	//Declaration des variables

		//FLOAT
	float note;
	float tableau[NBMAXNOTES+1];
	float moyenne = 0;
	float max = 0;
	float mini = 20;
	float somme = 0;
	float sommeecarttype = 0;
	float ecarttype;

	//INT
	int nbvalide = 0;
	int choix;
	int nbabsent = 0;
	int tailletableau = NBMAXNOTES;
	int stop = 0;

	//Debut de la saisie du tableau 
	while (stop == 0) {
		for (int num = 1; num <= NBMAXNOTES; num++) {

			printf("\nEntrez la note numero %d :", num);
			scanf_s("%f", &note);
			if (note > 20 || note < 0) {
				printf("Vous avez entre une valeur invalide : Eleve (A)bsent ? Ou voulez-vous arreter la saisie des notes (O)ui / (N)on? ");
				//Si on entre une des touches demandées alors on effectue l'action associée
				do { choix = _getch(); } while (choix != 'A' && choix != 'O' && choix != 'N'&& choix != 'a'&& choix != 'o'&& choix != 'n');
				switch (choix) {
				case 'A':
					printf("\n");
					//On remplace la mauvaise note par -1
					note = -1;
					break;
				case 'a':
					printf("\n");
					//On remplace la mauvaise note par -1
					note = -1;
					break;
				case 'O':
					printf("\n");
					stop = 1;
					tailletableau = num;
					num = NBMAXNOTES;
					break;
				case 'o':
					printf("\n");
					stop = 1;
					tailletableau = num;
					num = NBMAXNOTES;
					break;
				case'N':
					printf("\n");
					num = num - 1;
					break;
				case'n':
					printf("\n");
					num = num - 1;
					break;
				}

			}
			//Insertion de la note dans le tableau
			tableau[num] = note;
		}
		stop = 1;
	}
	//Parcours du tableau
	for (int i = 1; i < tailletableau; i++) {
		if (tableau[i] != -1) {
			//Calcul de moyenne
			somme = somme + tableau[i];
			nbvalide++;

			
			if (tableau[i] > max) {
				max = tableau[i];
			}
			if (tableau[i] < mini) {
				mini = tableau[i];
			}
		}
		else {
			nbabsent++;
		}
	}

	
	
	moyenne = somme / nbvalide;

	for (int i = 1; i < tailletableau; i++) {
		if (tableau[i] != -1) {
			sommeecarttype = sommeecarttype + pow(((double)tableau[i] - moyenne), 2);
		}

	}

	ecarttype = sqrt(sommeecarttype / (nbvalide - 1));

	printf("\nLa valeur maximale est %f", max);
	printf("\nLa valeur minimale est %f", mini);
	printf("\nLa valeur moyenne est %f", moyenne);
	printf("\nIl y a %d absents", nbabsent);
	printf("\nIl y a un ecart-type de : %f", ecarttype);
	printf("\nNoNote  Note");

	for (int i = 1; i < tailletableau; i++) {
		printf("\n%d       %f", i, tableau[i]);
	}

	
	return (EXIT_SUCCESS);

}
