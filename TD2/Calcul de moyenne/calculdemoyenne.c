#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

main() {
	//Initialisation des variables
	float moyenne=0;
	float note=0;
	float i=0;
	float somme = 0;

	//Debut de la boucle tant que
	while (note != -1) {
		printf("\nPour arreter le programme entrez -1 \nEntrez vos notes :");
		scanf_s("%f", &note);
		if (note != -1) {
			somme = somme + note;
			i++;
		}
		
	// Fin de la boucle tant que 
	}

	moyenne = somme / i;
	printf("\nVotre moyenne est de :%f", moyenne);
	// Fin du programme
}
