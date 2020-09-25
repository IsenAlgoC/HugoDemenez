#include<stdio.h>
#include <stdlib.h>



main() {
	//Initialisation des variables
	float montant;
	float taux;
	float epargne=0;
	int i = 0;

	//
	printf("\nEntrez le montant de la somme que vous souhaitez placer :");
	scanf_s("%f", &montant);
	printf("\nEntrez le taux d'interet :");
	scanf_s("%f", &taux);

	epargne = montant;

	//Debut de la boucle tant que 

	while (epargne <2*montant) {
		epargne = epargne + epargne*taux/100;
		i++;
		printf("\nEn %d an votre epargne sera de %f\n", i, epargne);
	}

	//Fin de la boucle tant que

	printf("Au bout de %d ans votre capital aura double",i);

	//Fin du programme
}