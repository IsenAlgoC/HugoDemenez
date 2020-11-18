#include "tab.h"


int initTab(int* tab, int size) {
	//On test si le tableau n'est pas NULL
	if (tab == NULL || size<0) {
		return -1;
	}
	//On va parcourir le tableau � l'aide de la boucle for : 
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
		//On cr�e un pointeur tableau temporaire �tant la r�allocation du pointeur tab sur la taille n�c�ssaire pour ajouter une valeur
		int *tmp = (int*)realloc(tab, *size+TAILLEAJOUT);
		//Si l'agrandissement �choue, on renvoie -1
		if (tmp == NULL) {
			return -1;
		}
		//Sinon on remplace notre pointeur tableau par le nouveau tableau r�allou�, on augmente le nombre d'�l�ments du tableau de 1 et on change la taille du tableau par la nouvelle taille
		else {
			tab = tmp;
			*nbElts = *nbElts + 1;
			*(tab + *nbElts-1) = element;
			*size = *size + TAILLEAJOUT;
		}
	}
	//Sinon cela signifie que la taille est suffisante pour acceuilir un nouvel �l�ment, on ajoute simplement le nouvel �l�ment dans le tableau et on augmente le nbElts par 1
	else {
		*nbElts= *nbElts+1;
		*(tab +*nbElts-1) = element;
	}
	//Si les op�rations ont r�ussi, on renvoie le nombre d'�l�ments dans le tableau
	return *nbElts;
}