#include "tab.h"


int initTab(int* tab, int size) {
	//On test si le tableau n'est pas NULL
	if (tab == NULL || size<0) {
		return -1;
	}
	//On va parcourir le tableau à l'aide de la boucle for : 
	for (int i = 0; i < size; i++) {
		//On va remplacer chaque terme du tableau par un entier 0 :
		*(tab +i) = 0;
	}
	return size;
}

int afficheTab(int* tab, int size, int nbElts) {
	//Si le tableau est NULL ou si size<0 ou si size<nbElts, on renvoie -1
	if (tab == NULL || size<0 || size<nbElts) {
		return -1;
	}
	//On affiche les nbElts premiers elements du pointeur tab
	for (int i = 0; i < nbElts; i++) {
		printf_s("%d", *(tab + i));
	}
	printf_s("\n");
	return 0;
}

int ajoutElementDansTableau(int* tab, int *size, int *nbElts, int element) {
	if (*nbElts == *size) {
		//On crée un pointeur tableau temporaire étant la réallocation du pointeur tab sur la taille nécéssaire pour ajouter une valeur
		int *tmp = (int*)realloc(tab, *size+TAILLEAJOUT);
		//Si l'agrandissement échoue, on renvoie -1
		if (tmp == NULL) {
			return -1;
		}
		//Sinon on remplace notre pointeur tableau par le nouveau tableau réalloué, on augmente le nombre d'éléments du tableau de 1 et on change la taille du tableau par la nouvelle taille
		else {
			tab = tmp;
			*nbElts = *nbElts + 1;
			*(tab + *nbElts-1) = element;
			*size = *size + TAILLEAJOUT;
		}
	}
	//Sinon cela signifie que la taille est suffisante pour acceuilir un nouvel élément, on ajoute simplement le nouvel élément dans le tableau et on augmente le nbElts par 1
	else {
		*nbElts= *nbElts+1;
		*(tab +*nbElts-1) = element;
	}
	//Si les opérations ont réussi, on renvoie le nombre d'éléments dans le tableau
	return *nbElts;
}