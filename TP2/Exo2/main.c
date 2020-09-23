#include <stdio.h>
#include <stdlib.h>


int main() {

	float longueur = 0;
	float largeur = 0;
	float hauteur = 0;
	int retour = 1; 
	while (retour == 1) {
		printf("Entrez la longueur du bagage comprise entre 1 et 150 :");
		scanf_s("%f", &longueur);
		while (longueur > 150 || longueur < 1) {
			printf("Entrez la longueur du bagage valide:");
			scanf_s("%f", &longueur);
		}

		printf("Entrez la largeur du bagage comprise entre 1 et 150 :");
		scanf_s("%f", &largeur);
		while (largeur > 150 || largeur < 1) {
			printf("Entrez la largeur du bagage valide :");
			scanf_s("%f", &largeur);
		}

		printf("Entrez la hauteur du bagage comprise entre 1 et 150 :");
		scanf_s("%f", &hauteur);
		while (hauteur > 150 || hauteur < 1) {
			printf("Entrez la hauteur du bagage valide :");
			scanf_s("%f", &hauteur);
		}

		float temp;

		if (longueur < largeur) {
			temp = largeur;
			largeur = longueur;
			longueur = temp;
		}

		float temp2;
		if (longueur < hauteur) {
			temp2 = longueur;
			longueur = hauteur;
			hauteur = temp2;
		}

		float temp3;
		if (largeur < hauteur) {
			temp3 = largeur;
			largeur = hauteur;
			hauteur = temp3;
		}

		if (longueur < 55 && largeur < 35 && hauteur < 25) {
			printf("Super vous pouvez embarquer");
			retour = 1;

		}
		else {
			printf("Vos dimensions ne sont pas acceptees");
			retour = 1;
		}
	}
	
	
}
