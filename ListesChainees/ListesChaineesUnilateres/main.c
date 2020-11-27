#include "listes.h"



int main() {
	//On cr�e une nouvelle liste vide appel�e MaListe
	LinkedList *MaListe = NewLinkedList();
	//On cr�e un nouvel element appel� MonPremierElement avec la valeur 5
	SingleLinkedListElem* MonPremierElement = NewLinkedListElement(5);
	//On ajoute MonPremierElement � MaListe
	insertElemAtLinkedListHead(MaListe, MonPremierElement);
	
	//On ajoute 15 elements avec des valeurs al�atoires comprise entre 0 et 1000
	InitRandLinkedList(MaListe, 15);
	//On affiche les elements de la liste
	DisplayList(MaListe);

	return EXIT_SUCCESS;
}