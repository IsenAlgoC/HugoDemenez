#include "Header.h"

TABLEAU newArray() {
	TABLEAU tmp;
	//On initialise la size d'une structure tableau tmp à la valeur TAILLEINITIALE
	tmp.size = TAILLEINITIALE;
	
	//Si l'allocation est null on retourne un pointeur elt null
	if ((int*)malloc(TAILLEINITIALE * sizeof(int)) == NULL) {
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
	if ((int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int)) == NULL) {
		return -1;
	}
	//On crée un pointeur tmp qui est une réallocation du pointeur elt dans tab
	else {
		
		int tmp = (int*)realloc(tab->elt, (tab->size + incrementValue) * sizeof(int));
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
	//Si on se position à l'intérieur du tableau alors on met à element la position pos-1 dans le tableau
	if (0<pos && pos< tab->size) {
		tab->elt[pos-1] = element;
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
			printf_s("%d ", *(tab->elt + i));
		}
		printf_s("\n");
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (tab == NULL || startPos>endPos || startPos<0 || endPos>tab->size) {
		return -1;
	}

	else {
		for (int i = startPos; i < endPos; i++) {
			tab->elt[i] = NULL;
		}
		//On va décaler les termes à partir de endPos jusque startPos
		for (int i = endPos; i < tab->size; i++) {
			tab->elt[startPos + (i-endPos) -1 ] = tab->elt[i];
		}
		//On alloue une nouvelle taille plus petite
		int tmp = (int*)realloc(tab->elt, (tab->size - (endPos - startPos)) * sizeof(int));
		tab->elt = tmp; 
		//On réduit size du tableau
		tab->size = tab->size - (endPos - startPos + 1);
	}
	return tab->size;
}
