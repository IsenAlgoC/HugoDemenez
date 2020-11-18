#include "tab.h"

int main() {
	//On cr�e un tableau myTab1 avec 10 valeurs
	int myTab1[10];

	//On initialise le tableau myTab1 avec des 0
	initTab(myTab1, 10);

	//On affiche les 5 premiers �l�ments du tableau myTab1
	afficheTab(myTab1, 10, 5);

	//On cr�e un pointeur MyTab2 NULL
	int* MyTab2 = NULL;

	//On alloue la m�moire n�c�ssaire � la cr�ation du tableau
	MyTab2 = (int*)malloc(TAB2SIZE * sizeof(int));

	//On test si la m�moire est suffisante 
	if (MyTab2 != NULL) { initTab(MyTab2, TAB2SIZE); }
	else { printf("m�moire insuffisante"); return(-1); }

	//On initialise le tableau MyTab2 avec des valeurs 0
	initTab(MyTab2, TAB2SIZE);

	//On remplace les 20 premi�res valeurs par des valeurs allant de 1 � 20
	for (int i = 0; i < 20; i++) {
		*(MyTab2 + i) = i + 1;
	}

	//On affiche les 20 premi�res valeurs du tableau MyTab2
	afficheTab(MyTab2, TAB2SIZE, 20);

	//On cr�e des variables qui peuvent �tre modifi�es pour cr�er le MyTab2
	int TABSIZE = 100;
	int NBELEMENT = 20;

	//On ajoute la valeur 21 � la suite de MyTab2
	ajoutElementDansTableau(MyTab2,&TABSIZE,&NBELEMENT, 21);

	//On affiche les 21 premi�res valeurs du tableau MyTab2
	afficheTab(MyTab2, TAB2SIZE, 21);

	//On d�truit le tableau
	free(MyTab2);

	return EXIT_SUCCESS;
}