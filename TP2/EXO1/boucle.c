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



	system("pause");
	return (EXIT_SUCCESS);
}