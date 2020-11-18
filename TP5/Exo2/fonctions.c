#include "Header.h"

TABLEAU newArray() {
	TABLEAU tmp;
	//On initialise la size d'une structure tableau tmp à la valeur TAILLEINITIALE
	tmp.size = TAILLEINITIALE;
	
	//Si l'allocation est null on retourne un pointeur elt null
	if ((int*)malloc(TAILLEINITIALE) == NULL) {
		return tmp;
	}

	//Sinon on alloue la taille nécéssaire pour le pointeur elt de la structure tableau tmp et on initialise les valeurs de elt à 0 et eltsCount à 0
	else {
		tmp.elt = (int*)malloc(TAILLEINITIALE*sizeof(int));
		for (int i = 0; i < TAILLEINITIALE; i++) {
			tmp.elt[i] = 0;
		}
		tmp.eltsCount = 0;
	}
	//On retourne la structure tableau tmp
	return tmp;
}


int incrementArraySize(TABLEAU* tab, int incrementValue) {
	//On regarde si la reallocation est possible : 
	if ((int*)realloc(tab->elt, tab->size + incrementValue) == NULL) {
		return -1;
	}
	//On crée un pointeur tmp qui est une réallocation du pointeur elt dans tab
	else {
		int* tmp = (int*)realloc(tab->elt, tab->size + incrementValue);
		tab->elt = tmp;
		tab->size = tab->size + incrementValue;
		return tab->size;
	}
}

int setElement(TABLEAU* tab, int pos, int element) {
	if (pos < tab->size) {
		return 0;
	}
	//Alors on a donc (pos > tab->size) et il faut agrandir le tableau pour ajouter la valeur
	else {
		incrementArraySize(tab, pos - (tab->size));
		*(tab->elt + pos) = element;
	}
	return pos;
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	if (startPos > tab->size || endPos > tab->size || startPos < 0 || endPos < 0) {
		return -1;
	}
	for (int i = startPos; i < endPos; i++) {
		printf("%d", *(tab->elt + i));
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {

	return EXIT_SUCCESS;
}
