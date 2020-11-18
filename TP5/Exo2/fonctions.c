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
	if ((int*)realloc(tab->elt, (tab->size + incrementValue) ) == NULL) {
		return -1;
	}
	//On crée un pointeur tmp qui est une réallocation du pointeur elt dans tab
	else {
		int tmp = (int*)realloc(tab->elt, (tab->size + incrementValue));
		tab->elt = tmp;
		tab->size = tab->size + incrementValue;
		return tab->size;
	}
}

int setElement(TABLEAU* tab, int pos, int element) {
	//On retourne 0 si on a une erreur
	if (pos < 0) {
		return 0;
	}
	//Si on se position à l'intérieur du tableau alors on met à element la position pos dans le tableau
	if (0<pos && pos< tab->size) {
		tab->elt[pos] = element;
	}
	//Sinon on a donc (pos > tab->size) et il faut agrandir le tableau pour ajouter la valeur
	else {
		incrementArraySize(tab, pos - (tab->size));
		tab->elt[pos-1] = element;
	}
	return pos;
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	//Si on a une erreur, on retourne -1
	if (startPos > tab->size || endPos > tab->size || startPos < 0 || endPos < 0) {
		return -1;
	}
	//Autrement on affiche les valeurs à partir de startPos jusqu'à endPos
	else {
		for (int i = startPos; i < endPos; i++) {
			printf_s("%d", *(tab->elt + i));
		}
		printf_s("\n");
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {

	return EXIT_SUCCESS;
}
