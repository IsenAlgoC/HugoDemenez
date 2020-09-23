#include <stdio.h>
#include <stdlib.h>

int main() {

	int entiers = 100;
	int sommefor = 0;

	for (int compteurfor = 0; compteurfor <= entiers; compteurfor++) {
		
		sommefor = sommefor + compteurfor;
	}

	printf("La somme des 100 premiers entiers avec la boucle for est : %d \n", sommefor);

	int sommewhile = 0;
	int compteurwhile = 0;

	while (compteurwhile < entiers) {
		compteurwhile++;
		sommewhile = sommewhile + compteurwhile;
	}

	printf("La somme des 100 premiers entiers avec la boucle while est : %d \n", sommewhile);

	int sommedo = 0;
	int compteurdo = 0;

	do {
		compteurdo++;
		sommedo = sommedo + compteurdo;
	} 
	while (compteurdo < entiers);

	printf("La somme des 100 premiers entiers avec la boucle do...while est : %d \n", sommedo);

	int sommemax = 0;
	int compteurmax = 0;
	int exit = 0;
	while (exit==0) {
		compteurmax++;
		sommemax = sommemax + compteurmax;
		if (sommemax + compteurmax >= 65535) {
			65535 - sommemax <= compteurmax;
			exit = 1;
		}

	}

	printf("La valeur de l'entier max avant d'avoir une somme depassant la valeur d'un unsigned short est : %d \n", compteurmax);

	//Modification de programme pour pouvoir entrer l'entier souhaite
	unsigned short entier = 0;
	unsigned short sommeforunsigned = 0;
	printf("Entrez une valeur de n :");
	scanf_s("%hu", &entier);

	for (unsigned short compteurfor2 = 0; compteurfor2 <= entier; compteurfor2++) {

		sommeforunsigned = sommeforunsigned + compteurfor2;
	}

	printf("La somme des %hu premiers entiers avec la boucle for est : %d \n", entier, sommeforunsigned);

	//Modification de programme pour ne pas depasser en ayant entre l'entier souhaite

	unsigned short sommemax2 = 0;
	unsigned short compteurmax2 = 0;
	exit = 0;
	unsigned short entier2 = 0;

	printf("Entrez une valeur de n :");
	scanf_s("%hu", &entier2);

	while (exit == 0) {
		if (entier2 > 361) {
			printf("Entrez une valeur de n qui ne depasse pas le maximum autorise pour un unsigned short :");
			scanf_s("%hu", &entier2);
		}
		else {
			exit = 1;
		}
	}
	while ( compteurmax2 < entier2 ) {
		compteurmax2++;
		sommemax2 = sommemax2 + compteurmax2;
	}

	printf("La somme des %hu premiers entiers est : %d \n", entier2,sommemax2);


	system("pause");
	return (EXIT_SUCCESS);
}