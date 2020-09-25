#include<stdio.h>
#include<stdlib.h>


main() {


	int AB = 0, BC = 0, CA = 0;
	printf("\nEntrez la valeur du côté AB ");
	scanf_s("%d", &AB);
	printf("\nEntrez la valeur du côté BC ");
	scanf_s("%d", &BC);
	printf("\nEntrez la valeur du côté CA ");
	scanf_s("%d", &CA);


	// Version longue : imbrication des 'if'
	int existe = 0; // par défaut , le triangle n'existe pas
	if ((AB >= 0) && (BC >= 0) && (CA >= 0)) {
		if (AB + BC > CA) {
			if (AB + CA > BC) {
				if (BC + CA > AB) {
					existe = 1; // toutes les conditions sont vérifiées
				}
			}
		}
	}

	if (existe)
		printf("Ce triangle existe. \n");
	else { printf("Ce triangle n'existe pas. \n"); }

	// Version courte : Un seul 'if' regroupant les conditions
	// avec des opérateurs logiques

	if ((AB >= 0) && (BC >= 0) && (CA >= 0) && (AB + BC > CA)
		&& (AB + CA > BC) && (BC + CA > AB))
		printf("Ce triangle existe. \n");
	else
		printf("Ce triangle n'existe pas. \n");

}