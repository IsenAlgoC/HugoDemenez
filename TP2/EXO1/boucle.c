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
	int good = 0;
	while (good==0) {
		compteurmax++;
		sommemax = sommemax + compteurmax;
		if (sommemax + compteurmax >= 65535) {
			65535 - sommemax <= compteurmax;
			good = 1;
		}

	}

	printf("La valeur de l'entier max avant d'avoir une somme depassant la valeur d'un unsigned short est : %d \n", compteurmax);


	system("pause");
	return (EXIT_SUCCESS);
}