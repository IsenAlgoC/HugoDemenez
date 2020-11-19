#include "Header.h"


int main() {
	//On déclare un tableau de structure tableau
	TABLEAU MonTableau;
	//On initialise le tableau avec la fonction newArray(), taille de départ : 10, valeurs : 0 
	MonTableau = newArray();
	//On affiche les élements de 0 à 5 du tableau
	displayElements(&MonTableau, 0, 5);
	//On met l'element 5 à la valeur 10
	setElement(&MonTableau, 5, 10);
	//On augmente la taille du tableau de 3 
	incrementArraySize(&MonTableau, 3);
	//On met l'element 14 à la valeur 7, on va augmenter la taille de 1 puisque la taille jusqu'ici est de 13
	setElement(&MonTableau, 14, 7);
	//On affiche tous les élements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);
	//On met l'element 6 à la valeur 3
	setElement(&MonTableau, 6, 3);
	//On met l'element 7 à la valeur 5
	setElement(&MonTableau, 7, 5);
	//On affiche tous les élements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);
	//On supprime les élements de 2 à 6 inclus
	deleteElements(&MonTableau, 2, 6);
	//On affiche les élements du tableau
	displayElements(&MonTableau, 0, MonTableau.size);
	
	
	return EXIT_SUCCESS;
}